#include "common.h"

#define MIPS_JUMP_TARGET(insn) (((insn)&0x003FFFFF) << 1)

typedef struct {
    u32 headerSize;
    s32 entryPointOffset;
    s32 textSize;
    s32 rodataSize;
    s32 dataSize;
    s32 bssSize;
    s32 relocCount;
    s32 nameTag;
    s32* relaContents;
} ModuleCommInfo; // size = 0x24

typedef enum MipsRelocation_e {
    MIPS_RELOC_HI16 = 0,
    MIPS_RELOC_LO16 = 1,
    MIPS_RELOC_26 = 2,
    MIPS_UNK_RELOC_3 = 3,
    MIPS_UNK_RELOC_4 = 4,
    MIPS_RELOC_32 = 5,
    MIPS_UNK_RELOC_6 = 6,
} MipsRelocation;

typedef enum MipsInstructionSection_e {
    INSTRUCTION_SECTION_TEXT,
    INSTRUCTION_SECTION_DATA,
    INSTRUCTION_SECTION_RODATA,
} MipsInstructionSection;

typedef enum SymbolSection_e {
    SYM_SECTION_TEXT,
    SYM_SECTION_RODATA,
    SYM_SECTION_DATA,
    SYM_SECTION_BSS,
} SymbolSection;

UnkStruct_8002D1A4* func_80001724(s32, s32);                          
s32 func_80003494(s32); 
UnkStruct_8002D1A4* func_8000355C(s32);                             
void func_80001A68(s32, s32);
UnkStruct_8002D1A4* func_800019B8(s32, s32);                            
s16 uvGetFilesCount(s32);                               
s32 uvGetFileData(s32, s32);                          
void uvDoModuleRelocs(u8*, ModuleCommInfo*);

s32* sModuleNameTags;
s32* gModuleHeaderSize;
s16 gModuleCount;

void func_80003310(void) {
    s32 i;
    s32 fileId;
    u8* fileData;
    u32 size;
    ModuleCommInfo info;

    gModuleCount = uvGetFilesCount('UVMO');
    sModuleNameTags = _uvMemAllocAlign8(gModuleCount * 4);
    gModuleHeaderSize = _uvMemAllocAlign8(gModuleCount * 4);
    for (i = 0; i < gModuleCount; i++) {
        fileData = uvGetFileData('UVMO', i);
        if (fileData != NULL) {
            fileId = uvFileReadHeader(fileData);
            uvFileSearchTag(fileId, &size, (void** ) &fileData, 'COMM', 0);
            _uvMediaCopy(&info, (void* ) fileData, size);
            uvFileFree(fileId);
            sModuleNameTags[i] = info.nameTag;
            gModuleHeaderSize[i] = info.headerSize;
        } else {
            sModuleNameTags[i] = 0;
            gModuleHeaderSize[i] = 0;
        }
    }
}

s32 func_80003494(s32 moduleName) {
    s32 i;
    s32* var_a1;

    for (i = 0; i < gModuleCount; i++) {
        if (moduleName == sModuleNameTags[i]) {
            return i;
        }
    }

    return -1;
}

UnkStruct_8002D1A4* func_800034E0(s32 tag) {
    s32 ret;

    ret = func_80003494(tag);
    if (ret == -1) {
        return 0;
    }
    return func_80001724('UVMO', ret);
}


s32 func_80003520(s32 tag) {
    s32 temp_v0;

    temp_v0 = func_80003494(tag);
    if (temp_v0 == -1) {
        return 0;
    }
    return func_8000355C(temp_v0);
}

UnkStruct_8002D1A4* func_8000355C(s32 arg0) {
    return func_800019B8('UVMO', arg0);
}

void* uvLoadModuleCode(u8* file) {
    s32 fileId;
    u32 tag;
    u32 blockSize;
    void* fileBlock;
    u8* ovlStartPtr;
    s32 overlaySize;
    s32 headeredStartPtr;
    ModuleCommInfo info;
    void (*entryPointFunction)(void*);
    ModuleCommInfo* infoPtr = &info;

    fileId = uvFileReadHeader(file);
    while ((tag = uvFileReadBlock(fileId, &blockSize, &fileBlock, 1)) != 0) {
        switch (tag) {
            case 'COMM':
                _uvMediaCopy(&info, fileBlock, sizeof(info));
                _uvMemFree(fileBlock);
                break;
            case 'CODE':
                headeredStartPtr = _uvMemAllocAlign16(infoPtr->headerSize + blockSize + infoPtr->bssSize);
                ovlStartPtr = headeredStartPtr + infoPtr->headerSize;
                _uvMediaCopy(ovlStartPtr, fileBlock, blockSize);
                _uvMemFree(fileBlock);
                break;
            case 'RELA':
                infoPtr->relaContents = fileBlock;
                break;
            default:
                _uvMemFree(fileBlock);
                break;
        }
    }
    uvFileFree(fileId);
    overlaySize = infoPtr->textSize + infoPtr->rodataSize + infoPtr->dataSize;
    uvMemSet(ovlStartPtr + overlaySize, 0, infoPtr->bssSize); // zero bss
    uvDoModuleRelocs(ovlStartPtr, &info);
    osWritebackDCache(ovlStartPtr, overlaySize + infoPtr->bssSize);
    osInvalDCache(ovlStartPtr, overlaySize + infoPtr->bssSize);
    osInvalICache(ovlStartPtr, overlaySize + infoPtr->bssSize);
    entryPointFunction =  ovlStartPtr + infoPtr->entryPointOffset;
    _uvMemFree(infoPtr->relaContents);
    entryPointFunction(headeredStartPtr);
    return headeredStartPtr;
}

void func_80003760(s32 tag) {
    func_80001A68('UVMO', func_80003494(tag));
}

#define CURRENT_MIPS_OP (instructionBase + addend)
void uvDoModuleRelocs(u8 *ovlStartPtr, ModuleCommInfo *info) {
    s32 symBase;
    s32 addend;
    s32 mipsLo16;
    u32 haveHi16;
    s32 i;    
    u32 symbolSection;
    u8 *instructionBase;
    s32 *lui;
    union {
        u32 lui;
        u32 targetInstructionSection;
    } u;
    u32 relocType;
    u32 pairedHiLoImm;
    

    haveHi16 = FALSE;
    for (i = 0; i < info->relocCount; i++) {
        symbolSection = (u32)info->relaContents[i] >> 0x1C;
        u.targetInstructionSection = (u32) (info->relaContents[i] & 0x0C000000) >> 0x1A; // 0
        relocType = (u32) (info->relaContents[i] & 0x03C00000) >> 0x16; // 0
        addend = MIPS_JUMP_TARGET(info->relaContents[i]); // 20
        switch (symbolSection) {
            case SYM_SECTION_TEXT:       
                symBase = ovlStartPtr;
                break;
            case SYM_SECTION_RODATA:
                symBase = (u32)ovlStartPtr + info->textSize;
                break;
            case SYM_SECTION_DATA:
                symBase = (u32)ovlStartPtr + info->textSize + info->rodataSize;
                break;
            case SYM_SECTION_BSS:
                symBase = (u32)ovlStartPtr + info->textSize + info->rodataSize + info->dataSize;
                break;
        }

        switch (u.targetInstructionSection) {
            case INSTRUCTION_SECTION_TEXT:        
                instructionBase = ovlStartPtr;
                break;
            case INSTRUCTION_SECTION_DATA: 
                instructionBase = ovlStartPtr + info->textSize + info->rodataSize;
                break;
            case INSTRUCTION_SECTION_RODATA: 
                instructionBase = ovlStartPtr + info->textSize;
                break;
        }

        
        switch (relocType) {
            case MIPS_RELOC_HI16:       
                haveHi16 = TRUE;
                lui = (s32*)CURRENT_MIPS_OP;
                break;
            case MIPS_RELOC_LO16:
                u.lui = *lui;
                mipsLo16 = (*(s32*)(CURRENT_MIPS_OP) & 0xFFFF); // lo16 = (s + a) & 0xFFFF
                pairedHiLoImm = ((u.lui & 0xFFFF) << 0x10) + mipsLo16 + symBase;
                
                if (pairedHiLoImm & 0x8000) {
                    pairedHiLoImm += 0x10000;
                }
                if (mipsLo16 & 0x8000) {
                    pairedHiLoImm -= 0x10000;
                }

                u.lui = (u.lui & 0xFFFF0000) | ((pairedHiLoImm >> 0x10) & 0xFFFF);

                if (haveHi16 == TRUE) {
                    *lui = u.lui;
                }
                haveHi16 = FALSE;
                *((s16*)(CURRENT_MIPS_OP) + 1) = (pairedHiLoImm & 0xFFFF);
                break;
            case MIPS_UNK_RELOC_3:
            case MIPS_UNK_RELOC_4:
                break;
            case MIPS_RELOC_26:
                *(s32*)(CURRENT_MIPS_OP) += (u32) (symBase & 0x0FFFFFFF) >> 2;
                break;
            case MIPS_RELOC_32:
            case MIPS_UNK_RELOC_6:
                *(s32*)(CURRENT_MIPS_OP) += symBase;
                break;
            default:
                break;
        }
    }
}

s32 func_80003A14(u32 arg0, s32* arg1) {
    s32 i;
    s32 var_s4;
    u32 temp_v0;
    u32 var_s1;

    var_s1 = 0;
    var_s4 = -1;
    for (i = 0; i < uvGetFilesCount('UVMO'); i++) {
        temp_v0 = func_80001724('UVMO', i);
        if ((temp_v0 < arg0) && (var_s1 < temp_v0)) {
            var_s4 = i;
            var_s1 = temp_v0;
        }
    }
    if (arg1 != NULL) {
        *arg1 = var_s4;
    }
    if (var_s4 == -1) {
        return 0;
    }
    return sModuleNameTags[var_s4];
}

