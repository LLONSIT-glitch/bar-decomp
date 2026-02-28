/*
 * @file module_tool.c
 * Simple tool to read module files
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <linux/swab.h>

#define MODULE_FILES_CODE_START 0x50

typedef struct ModuleCommInfo_s {
    uint32_t headerSize;
    int32_t entryPointOffset;
    int32_t textSize;
    int32_t rodataSize;
    int32_t dataSize;
    int32_t bssSize;
    int32_t unk18; // Reloc count?
    int32_t nameTag;
    int32_t relaContents;
} ModuleCommInfo; // size = 0x24

typedef struct ModuleFileHeader_s {
    int32_t formTag;
    int32_t fileSize;
    int32_t moduTag;
    int32_t padTag;
    int32_t padSize;
    int32_t padContents;
    int32_t commTag;
    int32_t commSize;
    ModuleCommInfo commInfo;
} ModuleFileHeader; // size 0x44

typedef struct ModuleFileMdbgInfo_s {
    int32_t mdbgTag;
    int32_t mdbgSize;
    char mdbgInfo[0x20]; // Module debug info
} ModuleFileMdbgInfo;

typedef struct RelaInfo_s {
    int32_t relaTag;
    int32_t relaSize;
} RelaInfo;

static char CurrentTagName[5];

size_t getFileSize(FILE *fp) {
    fseek(fp, 0, SEEK_END);
    size_t fSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    return fSize;
}

void byteSwapModuleFileHeader(ModuleFileHeader **header) {
    int *ptr = (int *) *header;

    for (int32_t i = 0; i < sizeof(ModuleFileHeader); i += sizeof(int32_t), ptr++) {
        *ptr = __swab32(*ptr);
    }
}

static char *tagToString(int *tag) {
    char newStr[4];
    char *tagPtr;
    int i;

    *tag = __swab32(*tag);
    tagPtr = (char *) (tag);
    for (i = 0; i < 4; i++) {
        CurrentTagName[i] = *tagPtr++;
    }
    CurrentTagName[i + 1] = '\0';
    return CurrentTagName;
}

void printModuleHeader(ModuleFileHeader *header) {
    printf("-- Module file header -- \n");
    printf("   Form tag: %s\n", tagToString(&header->formTag));
    printf("   File size: %d\n", header->fileSize + 8);
    printf("   Module tag: %s\n", tagToString(&header->moduTag));
    printf("   Pad tag: %s\n", tagToString(&header->padTag));
    printf("   Pad size: %d\n", header->padSize);
    printf("   Comm tag: %s\n", tagToString(&header->commTag));
    printf("   Comm size: %d\n", header->commSize);
}

void printCommInfo(ModuleCommInfo *info) {
    printf("\n-- Module Comm info -- \n");
    printf("   Comm header size: %x\n", info->headerSize);
    printf("   Module entry point offset: %x\n", info->entryPointOffset);
    printf("   Module text size: %x\n", info->textSize);
    printf("   Module rodata size %x\n", info->rodataSize);
    printf("   Module data size: %x\n", info->dataSize);
    printf("   Module bss size: %x\n", info->bssSize);
    printf("   unk18 (relocCount?): %x\n", info->unk18);
    printf("   nameTag: %s\n", tagToString(&info->nameTag));
    printf("   relaContents not overwritten: %x\n", info->relaContents);
}

void printMdbg(ModuleFileMdbgInfo *info) {

    info->mdbgTag = __swab32(info->mdbgTag);
    info->mdbgSize = __swab32(info->mdbgSize);

    printf("\n-- Module Mdbg info -- \n");
    printf("     MDBG tag: %s\n", tagToString(&info->mdbgTag));
    printf("     MDBG size: %x\n", info->mdbgSize);
    printf("     MDBG contents: %s\n", info->mdbgInfo);
}

void printRela(RelaInfo *info) {
    info->relaSize = __swab32(info->relaSize);
    info->relaTag = __swab32(info->relaTag);

    printf("\n-- Rela info -- \n");
    printf("     Rela tag: %s\n", tagToString(&info->relaTag));
    printf("     Rela size: %x\n", info->relaSize);
}

void printExtraInfo(ModuleCommInfo *info) {
    printf("\n-- Extra info -- \n");
    printf("     Text starts at: %x\n", MODULE_FILES_CODE_START);
    printf("     Rodata starts at: %x\n", info->textSize + MODULE_FILES_CODE_START);
    printf("     Data starts at: %x\n",
           info->textSize + MODULE_FILES_CODE_START + info->dataSize);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("module_tool <input file>\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "rb");

    if (fp == NULL) {
        perror("Can't not open input file");
        exit(EXIT_FAILURE);
    }

    size_t fileSize = getFileSize(fp);
    uint8_t *buf = malloc(fileSize);

    if (buf == NULL) {
        perror("Can't allocate memory!\n");
        exit(EXIT_FAILURE);
    }

    fread(buf, fileSize, 1, fp);
    ModuleFileHeader *fileHeader = (ModuleFileHeader *) buf;

    byteSwapModuleFileHeader(&fileHeader);

    // Validate file
    if (fileHeader->formTag != 'FORM' || fileHeader->moduTag != 'MODU' || fileHeader->padTag != 'PAD '
        || fileHeader->commTag != 'COMM') {
        printf("Invalid module file\n");
        free(buf);
        exit(EXIT_FAILURE);
    }

    printModuleHeader(fileHeader);
    printCommInfo(&fileHeader->commInfo);

    int mdbgEntry = MODULE_FILES_CODE_START + fileHeader->commInfo.textSize
                    + fileHeader->commInfo.dataSize + fileHeader->commInfo.rodataSize;
    ModuleFileMdbgInfo *mdbgInfo = (ModuleFileMdbgInfo *) &buf[mdbgEntry];
    printMdbg(mdbgInfo);

    RelaInfo *relaInfo = (RelaInfo *) &buf[mdbgEntry + sizeof(ModuleFileMdbgInfo)];
    printRela(relaInfo);

    printExtraInfo(&fileHeader->commInfo);

    free(buf);
    return 0;
}