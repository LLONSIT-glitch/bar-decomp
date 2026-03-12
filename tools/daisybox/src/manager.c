#include "config.h"
#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <linux/swab.h>
#include <cjson/cJSON.h>
#include "manager_types.h"
#include "bfd.h"
#include "symtab.h"
#include "load_map_symbols.h"

#define MODULE_FILES_CODE_BYTES_START 0x50
#define WORD_PAD_SIZE sizeof(int)
#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a > b) ? b : a)

typedef struct ModuleCommInfo_s {
    uint32_t headerSize;
    int32_t entryPointOffset;
    int32_t textSize;
    int32_t rodataSize;
    int32_t dataSize;
    int32_t bssSize;
    int32_t relocCount; // Reloc count?
    int32_t nameTag;
    int32_t relaContents;
} ModuleCommInfo; // size = 0x24

typedef struct ModuleFileHeader_s {
    int32_t formTag;
    int32_t fileSize;
    int32_t moduTag;
    int32_t padTag;
    int32_t padSize;
    int32_t padContents; // Structure padding
    int32_t commTag;
    int32_t commSize;
    ModuleCommInfo commInfo;
} ModuleFileHeader; // size 0x48

typedef struct ModuleFileMdbgInfo_s {
    int32_t mdbgTag;
    int32_t mdbgSize;
    char mdbgInfo[0x20]; // Module debug info
} ModuleFileMdbgInfo;

typedef struct CodeInfo_s {
    int32_t codeTag;
    int32_t codeSize;
} CodeInfo;

typedef struct RelaInfo_s {
    int32_t relaTag;
    int32_t relaSize;
} RelaInfo;

// Encoded reloc types
typedef enum MipsRelocation_e {
    MIPS_RELOC_HI16 = 0,
    MIPS_RELOC_LO16 = 1,
    MIPS_RELOC_26 = 2,
    MIPS_UNK_RELOC_3 = 3,
    MIPS_UNK_RELOC_4 = 4,
    MIPS_RELOC_32 = 5,
    MIPS_UNK_RELOC_6 = 6,
} MipsRelocation;

extern BarModuleFilesInfo BarModuleFiles[BAR_MODULE_FILES_COUNT];

static int RelocCount = 0;
static int *RelocEncodedWordsPtr = NULL;

static int encodeInstructionSection(asection *sec) {
    if (strcmp(sec->name, ".text") == 0) {
        return 0;
    } else if (strcmp(sec->name, ".data") == 0) {
        return 1;
    } else if (strcmp(sec->name, ".rodata") == 0) {
        return 2;
    } else if (strcmp(sec->name, ".bss") == 0) {
        return 3;
    }

    return -1;
}

static int encodeSymbolSection(asection *sec) {
    if (strcmp(sec->name, ".text") == 0) {
        return 0;
    } else if (strcmp(sec->name, ".rodata") == 0) {
        return 1;
    } else if (strcmp(sec->name, ".data") == 0) {
        return 2;
    } else if (strcmp(sec->name, ".bss") == 0) {
        return 3;
    }

    return -1;
}

static uint32_t encodeReloc(uint32_t symbolSection, uint32_t targetSection, uint32_t relocType,
                            int32_t addend) {
    uint32_t word = 0;

    word |= (symbolSection & 0xF) << 28;
    word |= (targetSection & 0x3) << 26;
    word |= (relocType & 0xF) << 22;
    word |= ((addend >> 1) & 0x3FFFFF);

    return word;
}

static int convertRelocType(int relocType) {
    switch (relocType) {
        case R_MIPS_26:
            return MIPS_RELOC_26;
        case R_MIPS_HI16:
            return MIPS_RELOC_HI16;
        case R_MIPS_LO16:
            return MIPS_RELOC_LO16;
        case R_MIPS_32:
            return MIPS_RELOC_32;
        default:
            printf("!!! Unknown reloc type: %x\n", relocType);
            return -1;
    }
}

static int stringToTag(char *tagStr) {
    int ptr;

    if (strlen(tagStr) < 4) {
        printf("Invalid size for tag string!\n");
        return -1;
    }

    memcpy(&ptr, tagStr, 4);
    return ptr;
}

void growRelocs(int newReloc) {
    int newCount = RelocCount + 1;

    int *tmp = realloc(RelocEncodedWordsPtr, newCount * sizeof(*RelocEncodedWordsPtr));
    if (tmp == NULL) {
        perror("realloc failed");
        abort();
    }

    RelocEncodedWordsPtr = tmp;
    RelocEncodedWordsPtr[RelocCount] = newReloc;
    RelocCount = newCount;
}

static void setCommEntryPointOffset(bfd *abfd, ModuleCommInfo *info) {
    int storage_needed = bfd_get_symtab_upper_bound(abfd);

    if (storage_needed <= 0) {
        printf("No symbols for this file!\n");
        exit(EXIT_FAILURE);
    }

    asymbol **symtable = (asymbol **) malloc(storage_needed);

    int count = bfd_canonicalize_symtab(abfd, symtable);
    symvalue minFunctionSymValue = 0;
    asymbol *entry = NULL;

    // Find the entrypoint function
    for (int i = 0; i < count; i++) {
        asymbol *sym = symtable[i];

        if (sym->name == NULL) {
            printf("! No symbol name!\n");
            continue;
        }

        if (strcmp(sym->section->name, ".text") != 0) {
            continue;
        }

        if (!(sym->flags & BSF_FUNCTION)) {
            continue;
        }

        if (strncmp(sym->name, "__entrypoint_func", 17) == 0) {
            entry = sym;
            break;
        }

        minFunctionSymValue = MIN(minFunctionSymValue, sym->value);

        printf("Symbol name: %s\n", sym->name);
    }

    assert(entry != NULL);

    long int entrySymbolFunctionOffset = entry->value - minFunctionSymValue;

    info->entryPointOffset = entrySymbolFunctionOffset;
    free(symtable);
}

static int computeRela(bfd *abfd) {
    int relaSize = 0;

    int storage_needed = bfd_get_symtab_upper_bound(abfd);

    if (storage_needed <= 0) {
        printf("No symbols for this file!\n");
        exit(EXIT_FAILURE);
    }
    asymbol **symtable = (asymbol **) malloc(storage_needed);

    int count = bfd_canonicalize_symtab(abfd, symtable);

    for (asection *sec = abfd->sections; sec != NULL; sec = sec->next) {

        long relocationSize = bfd_get_reloc_upper_bound(abfd, sec);
        if (relocationSize <= 0) {
            continue;
        }

        arelent **relocs = (arelent **) malloc(relocationSize);

        long relcount = bfd_canonicalize_reloc(abfd, sec, relocs, symtable);

        if (relcount < 0) {
            perror("bfd_canonicalize_reloc");
        }

        for (int i = 0; i < relcount; i++) {
            arelent *rel = relocs[i];
            asymbol *sym = *rel->sym_ptr_ptr;

            if (sym->section == bfd_und_section_ptr) {
                continue;
            }

            int type = convertRelocType(rel->howto->type);
            if (type < 0) {
                continue;
            }


            uint32_t word =
                encodeReloc(encodeSymbolSection(sym->section), encodeInstructionSection(sec), type, rel->address);
            //printf("Encoded word: %x\n", word);
            growRelocs(__swab32(word));
            relaSize += 4;
        }

        free(relocs);
    }
    return relaSize;
}

static void setCommSectionsSizes(bfd *abfd, ModuleCommInfo *info) {
    for (asection *sec = abfd->sections; sec; sec = sec->next) {

        const char *name = bfd_section_name(sec);
        bfd_size_type size = bfd_section_size(sec);

        // Set sections size
        if (strcmp(name, ".text") == 0) {
            info->textSize = size;
        } else if (strcmp(name, ".data") == 0) {
            info->dataSize = size;
        } else if (strcmp(name, ".rodata") == 0) {
            info->rodataSize = size;
        } else if (strcmp(name, ".bss") == 0) {
            info->bssSize = size;
        }
    }
}

static void resolveUndefHiLoRelocs(bfd *abfd, asection *text) {
    int storage_needed = bfd_get_symtab_upper_bound(abfd);

    if (storage_needed <= 0) {
        printf("No symbols for this file!\n");
        exit(EXIT_FAILURE);
    }
    asymbol **symtable = (asymbol **) malloc(storage_needed);

    int count = bfd_canonicalize_symtab(abfd, symtable);

    for (asection *sec = abfd->sections; sec != NULL; sec = sec->next) {

        long relocationSize = bfd_get_reloc_upper_bound(abfd, sec);
        if (relocationSize <= 0) {
            continue;
        }

        arelent **relocs = (arelent **) malloc(relocationSize);

        long relcount = bfd_canonicalize_reloc(abfd, sec, relocs, symtable);

        if (relcount < 0) {
            printf("Info: No relocs in this section!\n");
        }

        for (int i = 0; i < relcount; i++) {
            arelent *rel = relocs[i];
            asymbol *sym = *rel->sym_ptr_ptr;

            int type = convertRelocType(rel->howto->type);
            if (type < 0) {
                continue;
            }

            if (sym->section != bfd_und_section_ptr) {
                continue;
            }

            if (type == R_MIPS_26 && sym->section == bfd_und_section_ptr) {
                continue;
            }

            uint32_t symAddr = Symtab_ResolveSymbol(sym->name);
            if (symAddr == (uint32_t) -1) {
                printf("Couldn't resolve sym: %s\n", sym->name);
                continue;
            }

            asymbol sym_from_fake_symtab = { 0 };
            sym_from_fake_symtab.flags = BSF_GLOBAL;
            sym_from_fake_symtab.name = sym->name;
            sym_from_fake_symtab.section = bfd_abs_section_ptr;
            sym_from_fake_symtab.value = symAddr;
            asymbol *fake = &sym_from_fake_symtab;
            arelent patchedRel = *rel;
            patchedRel.sym_ptr_ptr = &fake;

            assert(text->contents != NULL);
            char *error;
            bfd_reloc_status_type status =
                bfd_perform_relocation(abfd, &patchedRel, text->contents, text, NULL, &error);
            if (status != bfd_reloc_ok) {
                printf("Reloc failed for %s (status=%d)\n", sym->name, status);
            }
        }

        free(relocs);
    }
}

static void resolveModuleRelocs(bfd *abfd, asection *text) {
    int storage_needed = bfd_get_symtab_upper_bound(abfd);

    assert(storage_needed > 0);

    asymbol **symtable = (asymbol **) malloc(storage_needed);

    int count = bfd_canonicalize_symtab(abfd, symtable);

    for (asection *sec = abfd->sections; sec != NULL; sec = sec->next) {

        long relocationSize = bfd_get_reloc_upper_bound(abfd, sec);
        if (relocationSize <= 0) {
            continue;
        }

        arelent **relocs = (arelent **) malloc(relocationSize);

        long relcount = bfd_canonicalize_reloc(abfd, sec, relocs, symtable);

        if (relcount < 0) {
            printf("Info: No relocs in this section!\n");
        }

        for (int i = 0; i < relcount; i++) {
            arelent *rel = relocs[i];
            asymbol *sym = *rel->sym_ptr_ptr;

            int type = convertRelocType(rel->howto->type);
            if (type < 0) {
                continue;
            }

            if (sym->section == bfd_und_section_ptr) {
                continue;
            }

            asymbol newSym = { 0 };
            newSym.flags = BSF_GLOBAL;
            newSym.name = sym->name;
            newSym.section = bfd_abs_section_ptr;
            newSym.value = sym->value;
            asymbol *fake = &newSym;
            arelent patchedRel = *rel;
            patchedRel.sym_ptr_ptr = &fake;

            assert(text->contents != NULL);
            char *error;
            bfd_reloc_status_type status =
                bfd_perform_relocation(abfd, &patchedRel, text->contents, text, NULL, &error);
            if (status != bfd_reloc_ok) {
                printf("Reloc failed for %s (status=%d)\n", sym->name, status);
            }
        }

        free(relocs);
    }
}

void writeCommHeader(bfd *abfd, FILE *inputFile, FILE *outputFile, char *moduleName) {
    assert(moduleName != NULL);
    bool foundModuleName = false;
    ModuleHardcodedInfo info = { 0 };
    ModuleFileHeader header = { 0 };
    CodeInfo codeInfo = { 0 };

    for (int i = 0; i < BAR_MODULE_FILES_COUNT; i++) {
        if (strcmp(moduleName, BarModuleFiles[i].moduleName) == 0) {
            foundModuleName = true;
            info = BarModuleFiles[i].info;
            break;
        }
    }

    assert(foundModuleName);

    // Initial comm heeader info
    header.formTag = 'FORM';
    header.moduTag = 'MODU';
    header.padTag = 'PAD ';
    header.commInfo.nameTag = __swab32(stringToTag(moduleName));
    header.padSize = sizeof(int);
    header.padContents = 0; // Just padding
    header.commTag = 'COMM';
    header.commSize = 0x28;
    header.commInfo.headerSize = info.headeredSize;
    header.commInfo.relaContents = info.relocVal;

    int storage_needed = bfd_get_symtab_upper_bound(abfd);
    if (storage_needed <= 0) {
        printf("ERROR: No symbols for this file!\n");
        exit(EXIT_FAILURE);
    }

    setCommEntryPointOffset(abfd, &header.commInfo);
    setCommSectionsSizes(abfd, &header.commInfo);

    int32_t commPad = 0;
    int sectionsSize = header.commInfo.textSize + header.commInfo.dataSize + header.commInfo.rodataSize;
    int firstSize = sizeof(ModuleFileHeader) - 0x8;
    int mdbgInfoSize = sizeof(ModuleFileMdbgInfo) + WORD_PAD_SIZE;
    int relaInfoSize = sizeof(RelaInfo);
    int relaSize =
        computeRela(abfd) + WORD_PAD_SIZE; // We need to add four extra bytes for padding reasons..
    header.commInfo.relocCount = RelocCount;
    // TODO: Organize this mess
    header.fileSize =
        firstSize + sizeof(CodeInfo) + relaInfoSize + sectionsSize + mdbgInfoSize + relaSize;

    int *ptr = (int *) &header;
    for (size_t i = 0; i < sizeof(ModuleFileHeader); i += 4) {
        *ptr++ = __swab32(*ptr);
    }

    codeInfo.codeTag = __swab32('CODE');
    codeInfo.codeSize = __swab32(sectionsSize);

    fwrite(&header, sizeof(ModuleFileHeader), 1, outputFile);
    fwrite(&commPad, sizeof(int32_t), 1, outputFile);
    fwrite(&codeInfo, sizeof(CodeInfo), 1, outputFile);
}

void writeCodeBlock(bfd *abfd, FILE* inputFile, FILE *outFile) {
    asection *text = bfd_get_section_by_name(abfd, ".text");
    asection *rodata = bfd_get_section_by_name(abfd, ".rodata");
    asection *data = bfd_get_section_by_name(abfd, ".data");

    size_t text_size = bfd_section_size(text);
    size_t data_size = bfd_section_size(data);
    size_t rodata_size = bfd_section_size(rodata);

    text->contents = malloc(text_size);
    data->contents = malloc(data_size);
    rodata->contents = malloc(rodata_size);

    if (text->contents == NULL || rodata->contents == NULL || data->contents == NULL) {
        perror("Can't alloc memory for sections");
        exit(EXIT_FAILURE);
    }

    fseek(inputFile, text->filepos, SEEK_SET);
    fread(text->contents, text_size, 1, inputFile);
    fseek(inputFile, rodata->filepos, SEEK_SET);
    fread(rodata->contents, rodata_size, 1, inputFile);
    fseek(inputFile, data->filepos, SEEK_SET);
    fread(data->contents, data_size, 1, inputFile);

    // Before writting the text section we must resolve those undefined LO16/HI16 refs
    resolveUndefHiLoRelocs(abfd, text);
    resolveModuleRelocs(abfd, text);

    fseek(outFile, MODULE_FILES_CODE_BYTES_START, SEEK_SET);

    fwrite(text->contents, text_size, 1, outFile);
    fwrite(rodata->contents, rodata_size, 1, outFile);
    fwrite(data->contents, data_size, 1, outFile);

    free(text->contents);
    free(rodata->contents);
    free(data->contents);
}

void writeMdbg(char* inputFileName, FILE* outFile) {
    ModuleFileMdbgInfo info = {0};

    size_t len = strlen(inputFileName);
    if (len >= sizeof(info.mdbgInfo)) {
        len = sizeof(info.mdbgInfo) - 1;
    }
    
    info.mdbgTag = __swab32('MDBG');
    info.mdbgSize = __swab32(32);
    memcpy(info.mdbgInfo, inputFileName, len);
    fwrite(&info, sizeof(info), 1, outFile);
}

void writeRela(FILE* outFile) {
    int relaSize = RelocCount * sizeof(int) + WORD_PAD_SIZE;
    RelaInfo info;

    info.relaTag = __swab32('RELA');
    info.relaSize = __swab32(relaSize);

    fwrite(&info, sizeof(info), 1, outFile);
    fwrite(RelocEncodedWordsPtr, relaSize, 1, outFile);
}

int main(int argc, char *argv[]) {
    char maxFileName[200];
    if (argc < 4) {
        printf("module_manager {input} {moduleName} {mapFile.json} -> {input}.uvmo.bin\n");
        exit(EXIT_FAILURE);
    }

    bfd_init();

    char *inputFileName = argv[1];

    FILE *inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        perror("Can't open input file");
        exit(EXIT_FAILURE);
    }

    bfd *abfd = bfd_openr(inputFileName, NULL);

    if (abfd == NULL) {
        printf("Can't open bfd!\n");
        exit(EXIT_FAILURE);
    }

    bfd_boolean b = bfd_check_format(abfd, bfd_object);

    if (!b) {
        printf("Only ELF Rel object files supported\n");
        exit(EXIT_FAILURE);
    }

    snprintf(maxFileName, 200, "%s.generated.uvmo", inputFileName);
    FILE *outFile = fopen(maxFileName, "w+");

    if (outFile == NULL) {
        perror("Can't open output file!\n");
        exit(EXIT_FAILURE);
    }

    printf("Converting: %s\n", argv[1]);
    printf("Loading symbols from map file\n");
    MapSymbols_Init(argv[3]);
    MapSymbols_Load();

    printf("Writing comm header\n");
    writeCommHeader(abfd, inputFile, outFile, argv[2]);
    printf("- Done\n");
    printf("Writing CODE block\n");
    writeCodeBlock(abfd, inputFile, outFile);
    printf("- Done\n");
    printf("Writing MDBG\n");
    writeMdbg(inputFileName, outFile);
    printf("- Done\n");
    printf("Writing RELA\n");
    writeRela(outFile);
    printf("- Done\n");

    fclose(inputFile);
    fclose(outFile);
    bfd_close(abfd);
    MapSymbols_Destroy();
    return 0;
}
