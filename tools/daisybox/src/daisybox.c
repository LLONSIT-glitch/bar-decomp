#include "global.h"
#include "manager_types.h"
#include "symtab.h"
#include "reloc_sorts.h"
#include "load_reloc_sorts.h"
#include "load_map_symbols.h"
#include "module_types.h"
#include "utils.h"

#define MODULE_FILES_CODE_BYTES_START 0x50
#define WORD_PAD_SIZE sizeof(int)
#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a > b) ? b : a)

struct Info {
    arelent *rel;
    int order;
};

extern BarModuleFilesInfo BarModuleFiles[BAR_MODULE_FILES_COUNT];

static int RelocCount = 0;
static int *RelocEncodedWordsPtr = NULL;

static void growRelocs(int newReloc, bool incrementCount) {
    int newCount = RelocCount + 1;

    int *tmp = realloc(RelocEncodedWordsPtr, newCount * sizeof(*RelocEncodedWordsPtr));
    if (tmp == NULL) {
        perror("realloc failed");
        abort();
    }

    RelocEncodedWordsPtr = tmp;
    RelocEncodedWordsPtr[RelocCount] = newReloc;
    if (incrementCount) {

        RelocCount = newCount;
    }
}

static int cmp_info(const void *a, const void *b) {
    const struct Info *ia = a;
    const struct Info *ib = b;
    return ia->order - ib->order;
}

static void sortTextRelocs(arelent **relocs, int relCount) {

    struct Info info[relCount];

    for (int i = 0; i < relCount; i++) {
        info[i].rel = relocs[i];
        info[i].order = RelocSort_GetRelocOrder(relocs[i]->address);
    }

    qsort(info, relCount, sizeof(struct Info), cmp_info);

    for (int i = 0; i < relCount; i++) {
        // printf("Order: %d\n", info[i].order);
        relocs[i] = info[i].rel;
    }
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

        if (strcmp(sec->name, ".text") == 0) {
            int localDefSymCount = 0;
            for (int i = 0; i < relcount; i++) {
                arelent *rel = relocs[i];
                asymbol *sym = *rel->sym_ptr_ptr;

                if (sym->section != bfd_und_section_ptr) {
                    localDefSymCount++;
                }
            }

            arelent **localRelocs = malloc(localDefSymCount * sizeof(arelent *));
            if (localRelocs == NULL) {
                perror("Can't allocate local relocs array");
                abort();
            }

            // Now copy local def sym relocs to the new array
            int j = 0;
            for (int i = 0; i < relcount; i++) {
                arelent *rel = relocs[i];
                asymbol *sym = *rel->sym_ptr_ptr;
                if (sym->section != bfd_und_section_ptr) {
                    printf("Symbol with name %s is a local def sym\n", sym->name);
                    localRelocs[j++] = rel; // Use a separate counter
                }
            }
            sortTextRelocs(localRelocs, localDefSymCount);

            for (int i = 0; i < localDefSymCount; i++) {
                arelent *rel = localRelocs[i];
                asymbol *sym = *rel->sym_ptr_ptr;

                int type = Utils_ConvertRelocType(rel->howto->type);
                if (type < 0) {
                    continue;
                }

                printf("REL Sym name: %s\n", sym->name);

                uint32_t word =
                    Utils_EncodeReloc(Utils_EncodeSymbolSection(sym->section),
                                      Utils_EncodeInstructionSection(sec), type, rel->address);
                // printf("Encoded word: %x\n", word);
                growRelocs(__swab32(word), true);
                relaSize += 4;
            }
            continue;
        }

        for (int i = 0; i < relcount; i++) {
            arelent *rel = relocs[i];
            asymbol *sym = *rel->sym_ptr_ptr;

            if (sym->section == bfd_und_section_ptr) {
                continue;
            }
            int type = Utils_ConvertRelocType(rel->howto->type);
            if (type < 0) {
                continue;
            }

            if (strcmp(sec->name, ".text") == 0) {
                printf("REL Sym name: %s\n", sym->name);
            }

            uint32_t word = Utils_EncodeReloc(Utils_EncodeSymbolSection(sym->section),
                                              Utils_EncodeInstructionSection(sec), type, rel->address);
            printf("Encoded word: %x\n", word);
            growRelocs(__swab32(word), true);
            relaSize += 4;
        }

        free(relocs);
    }

    growRelocs(0, false); // Pad the rela section with four extra bytes for alignment reasons
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

            int type = Utils_ConvertRelocType(rel->howto->type);
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
    // Get symbol table
    int storage_needed = bfd_get_symtab_upper_bound(abfd);
    assert(storage_needed > 0);

    asymbol **symtable = malloc(storage_needed);
    int symcount = bfd_canonicalize_symtab(abfd, symtable);
    if (symcount <= 0) {
        fprintf(stderr, "No symbols found!\n");
        free(symtable);
        return;
    }

    // Iterate sections
    for (asection *sec = abfd->sections; sec != NULL; sec = sec->next) {
        long relocSize = bfd_get_reloc_upper_bound(abfd, sec);
        if (relocSize <= 0)
            continue;

        arelent **relocs = malloc(relocSize);
        long relcount = bfd_canonicalize_reloc(abfd, sec, relocs, symtable);
        if (relcount < 0) {
            fprintf(stderr, "No relocations in section %s\n", sec->name);
            free(relocs);
            continue;
        }

        for (int i = 0; i < relcount; i++) {
            arelent *rel = relocs[i];
            asymbol *sym = *rel->sym_ptr_ptr;

            int type = Utils_ConvertRelocType(rel->howto->type);
            if (type < 0)
                continue;

            // Skip undefined symbols if unresolved
            if (sym->section == bfd_und_section_ptr && Symtab_ResolveSymbol(sym->name) == -1) {
                fprintf(stderr, "ERROR: Undefined reference: %s\n", sym->name);
                abort();
            }

            if (rel->howto->type == R_MIPS_32) {
                continue;
            }

            char *error = NULL;
            bfd_reloc_status_type status =
                bfd_perform_relocation(abfd, rel, text->contents, sec, NULL, &error);

            if (status != bfd_reloc_ok) {
                fprintf(stderr, "Reloc failed for %s (status=%d, error=%s)\n", sym->name, status,
                        error ? error : "<none>");
            }
        }

        free(relocs);
    }

    free(symtable);
}

static void resolveMips32Relocs(bfd *abfd, asection *data, asection *rodata) {
    int storage_needed = bfd_get_symtab_upper_bound(abfd);
    assert(storage_needed > 0);

    asymbol **symtable = malloc(storage_needed);

    for (asection *sec = abfd->sections; sec != NULL; sec = sec->next) {
        long relocSize = bfd_get_reloc_upper_bound(abfd, sec);
        if (relocSize <= 0) {
            continue;
        }

        arelent **relocs = malloc(relocSize);
        long relcount = bfd_canonicalize_reloc(abfd, sec, relocs, symtable);

        if (relcount < 0) {
            printf("Info: No relocs in section: %s\n", sec->name);
            free(relocs);
            continue;
        }

        for (int i = 0; i < relcount; i++) {
            arelent *rel = relocs[i];

            if (rel->howto->type != R_MIPS_32) {
                continue;
            }

            asymbol *sym = *rel->sym_ptr_ptr;

            asection *target_sec = NULL;

            /* Determine which section buffer to patch */
            if (sec == data) {
                target_sec = data;
            } else if (sec == rodata) {
                target_sec = rodata;
            } else {
                continue;
            }

            uint8_t *location = target_sec->contents + rel->address;

            /* Read existing addend */
            uint32_t addend = bfd_get_32(abfd, location);

            /* Compute symbol value */
            uint32_t symbol_value = sym->value;

            if (sym->section != NULL && sym->section != bfd_abs_section_ptr) {
                symbol_value += sym->section->vma;
            }

            uint32_t result = symbol_value + addend;

            bfd_put_32(abfd, result, location);

            printf("R_MIPS_32: %-20s  section=%s  offset=0x%x -> %08X\n", sym->name, sec->name,
                   (unsigned int) rel->address, result);
        }

        free(relocs);
    }

    free(symtable);
}

static void writeCommHeader(bfd *abfd, FILE *outputFile, char *moduleName) {
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
    header.commInfo.nameTag = __swab32(Utils_StringToTag(moduleName));
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

static asection *readSection(bfd *abfd, FILE *inputFile, char *sectionName) {
    asection *section = bfd_get_section_by_name(abfd, sectionName);

    if (section == NULL) {
        return NULL;
    }

    section->contents = malloc(section->size);
    if (section->contents == NULL) {
        printf("Can't allocate memory for section: %s", sectionName);
        perror("");
        return NULL;
    }

    fseek(inputFile, section->filepos, SEEK_SET);
    fread(section->contents, section->size, 1, inputFile);
    return section;
}

static void writeCodeBlock(bfd *abfd, FILE *inputFile, FILE *outFile) {
    asection *text = readSection(abfd, inputFile, ".text");
    asection *rodata = readSection(abfd, inputFile, ".rodata");
    asection *data = readSection(abfd, inputFile, ".data");

    // Code starts at 0x50
    fseek(outFile, MODULE_FILES_CODE_BYTES_START, SEEK_SET);

    if (text != NULL) {
        // Before writting the text section we must resolve those undefined LO16/HI16 refs
        resolveUndefHiLoRelocs(abfd, text); // Resolve kernel symbols
        resolveModuleRelocs(abfd, text);
        fwrite(text->contents, text->size, 1, outFile);
        free(text->contents);
    }

    if (data != NULL || rodata != NULL) {
        resolveMips32Relocs(abfd, data, rodata);
    }

    // Write the sections into the module file
    if (rodata != NULL) {
        fwrite(rodata->contents, rodata->size, 1, outFile);
        free(rodata->contents);
    }

    if (data != NULL) {
        fwrite(data->contents, data->size, 1, outFile);
        free(data->contents);
    }
}

static void writeMdbg(char *inputFileName, FILE *outFile) {
    ModuleFileMdbgInfo info = { 0 };

    size_t len = strlen(inputFileName);
    if (len >= sizeof(info.mdbgInfo)) {
        len = sizeof(info.mdbgInfo) - 1;
    }

    info.mdbgTag = __swab32('MDBG');
    info.mdbgSize = __swab32(sizeof(info.mdbgInfo));
    memcpy(info.mdbgInfo, inputFileName, len);
    fwrite(&info, sizeof(info), 1, outFile);
}

static void writeRela(FILE *outFile) {
    int relaSize = RelocCount * sizeof(int) + WORD_PAD_SIZE;
    RelaInfo info;

    info.relaTag = __swab32('RELA');
    info.relaSize = __swab32(relaSize);

    fwrite(&info, sizeof(info), 1, outFile);
    fwrite(RelocEncodedWordsPtr, relaSize, 1, outFile);
}

int main(int argc, char *argv[]) {
    char maxFileName[200];
    if (argc < 5) {
        printf("module_manager {input} {moduleName} {mapFile.json} {relocSorts} -> {input}.uvmo.bin\n");
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
        printf("Only ELF Rel object files are supported\n");
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
    LoadRelocSorts(argv[4]);

    printf("Writing comm header\n");
    writeCommHeader(abfd, outFile, argv[2]);
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
    LoadRelocSorts_Destroy();
    // char* inputFileHash = Utils_GenHash(inputFile);

    /*
    if (Utils_CompareFileHash(inputFile, outFile)) {
        printf("Hash check: OK");
    } else {
        printf("Hash check: Maybe check  ")
    }
    */

    return 0;
}
