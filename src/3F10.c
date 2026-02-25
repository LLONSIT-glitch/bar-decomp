#include "common.h"

#define MIPS_JUMP_TARGET(insn) (((insn)&0x003FFFFF) << 1)

typedef struct {
    u32 headerSize;
    s32 entryPointOffset;
    s32 textSize;
    s32 rodataSize;
    s32 dataSize;
    s32 bssSize;
    s32 unk18; // Reloc count?
    s32 nameTag;
    s32* relaContents;
} ModuleCommInfo; // size = 0x24

typedef enum MipsReloc_e {
    R_MIPS_HI16 = 0,
    R_MIPS_LO16 = 1,
    R_MIPS_26 = 2,
} MipsReloc;

typedef enum RelocSection_e {
    SECTION_0,
    SECTION_RODATA,
    SECTION_TEXT
} RelocSection;

UnkStruct_8002D1A4* func_80001724(s32, s32);                          
s32 func_80003494(s32); 
UnkStruct_8002D1A4* func_8000355C(s32);                             
void func_80001A68(s32, s32);
UnkStruct_8002D1A4* func_800019B8(s32, s32);                            
s16 func_80001654(s32);                               
s32 func_800016A4(s32, s32);                          
void uvDoModuleReloc(u8*, ModuleCommInfo*);

extern s32* D_8002DA70;
extern s32* D_8002DA74;
extern s16 D_8002DA78;


void func_80003310(void) {
    s32 i;
    s32 v0_2;
    s32 temp_v0;
    u32 sp70;
    ModuleCommInfo info;

    D_8002DA78 = func_80001654('UVMO');
    D_8002DA70 = _uvMemAllocAlign8(D_8002DA78 * 4);
    D_8002DA74 = _uvMemAllocAlign8(D_8002DA78 * 4);
    for (i = 0; i < D_8002DA78; i++) {
        temp_v0 = func_800016A4('UVMO', i);
        if (temp_v0 != 0) {
            v0_2 = uvFileReadHeader(temp_v0);
            func_800025C8(v0_2, &sp70, (void** ) &temp_v0, 'COMM', 0);
            _uvMediaCopy(&info, (void* ) temp_v0, sp70);
            uvFileFree(v0_2);
            D_8002DA70[i] = info.nameTag;
            D_8002DA74[i] = info.headerSize;
        } else {
            D_8002DA70[i] = 0;
            D_8002DA74[i] = 0;
        }
    }
}

s32 func_80003494(s32 arg0) {
    s32 i;
    s32* var_a1;

    for (i = 0; i < D_8002DA78; i++) {
        if (arg0 == D_8002DA70[i]) {
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


s32 func_80003520(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_80003494(arg0);
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
    void (*fcn)(void*);
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
    uvMemSet(ovlStartPtr + overlaySize, 0, infoPtr->bssSize);
    uvDoModuleReloc(ovlStartPtr, &info);
    osWritebackDCache(ovlStartPtr, overlaySize + infoPtr->bssSize);
    osInvalDCache(ovlStartPtr, overlaySize + infoPtr->bssSize);
    osInvalICache(ovlStartPtr, overlaySize + infoPtr->bssSize);
    fcn = ovlStartPtr + infoPtr->entryPointOffset;
    _uvMemFree(infoPtr->relaContents);
    (fcn)(headeredStartPtr);
    return headeredStartPtr;
}

void func_80003760(s32 tag) {
    func_80001A68('UVMO', func_80003494(tag));
}


void uvDoModuleReloc(u8 *ovlStartPtr, ModuleCommInfo *info) {
    s32 ovlPtr1; // t0
    s32 addend;
    s32 mipsLo16;
    u32 haveHi16;
    s32 i;    
    u32 cmd;
    u8 *symbol; // t1
    s32 *var_t5;
    u32 temp;
    u32 relocType;
    u32 var_v1;
    

    haveHi16 = 0;
    for (i = 0; i < info->unk18; i++) {
        cmd = (u32)info->relaContents[i] >> 0x1C;
        temp = (u32) (info->relaContents[i] & 0x0C000000) >> 0x1A; // 0
        relocType = (u32) (info->relaContents[i] & 0x03C00000) >> 0x16; // 0
        addend = MIPS_JUMP_TARGET(info->relaContents[i]); // 20
        switch (cmd) {
            case 0:       
                ovlPtr1 = ovlStartPtr;
                break;
            case 1:
                ovlPtr1 = (u32)ovlStartPtr + info->textSize;
                break;
            case 2:
                ovlPtr1 = (u32)ovlStartPtr + info->textSize + info->rodataSize;
                break;
            case 3:
                ovlPtr1 = (u32)ovlStartPtr + info->textSize + info->rodataSize + info->dataSize;
                break;
        }
        switch (temp) {
            case SECTION_0:        
                symbol = ovlStartPtr;
                break;
            case SECTION_RODATA: 
                symbol = ovlStartPtr + info->textSize + info->rodataSize;
                break;
            case SECTION_TEXT: 
                symbol = ovlStartPtr + info->textSize;
                break;
        }

        
        switch (relocType) {
            case R_MIPS_HI16:       
                haveHi16 = 1;
                var_t5 = symbol + addend;
                break;
            case R_MIPS_LO16:
                temp = *var_t5;
                mipsLo16 = (*(s32*)(symbol + addend) & 0xFFFF); // lo16 = (s + a) & 0xFFFF
                var_v1 = ((temp & 0xFFFF) << 0x10) + mipsLo16 + ovlPtr1;
                
                if (var_v1 & 0x8000) {
                    var_v1 += 0x10000;
                }
                if (mipsLo16 & 0x8000) {
                    var_v1 -= 0x10000;
                }

                temp = (temp & 0xFFFF0000) | ((var_v1 >> 0x10) & 0xFFFF);

                if (haveHi16 == 1) {
                    *var_t5 = temp;
                }
                haveHi16 = 0;
                *((s16*)(symbol + addend) + 1) = (var_v1 & 0xFFFF);
                break;
            case 3:
            case 4:
                break;
            case R_MIPS_26:
                *(s32*)(symbol + addend) += (u32) (ovlPtr1 & 0x0FFFFFFF) >> 2;
                break;
            case 5:
            case 6:
                *(s32*)(symbol + addend) += ovlPtr1;
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
    for (i = 0; i < func_80001654('UVMO'); i++) {
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
    return D_8002DA70[var_s4];
}

