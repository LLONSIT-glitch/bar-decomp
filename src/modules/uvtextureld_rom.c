// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"

typedef struct UnkTexture_Exports_s {
    /* 0x00 */ char pad0[0x20];
    /* 0x20 */ void* (*unk20)(void);
    /* 0x24 */ void* (*unk24)(void);                      /* inferred */
    /* 0x28 */ char pad28[4];
} UnkTexture_Exports;                               /* size = 0x2C */


typedef struct UnkStruct_uvtextureld_rom_00400A40_s {
    /* 0x00 */ void* unk0;                          /* inferred */
    /* 0x04 */ void* unk4;                          /* inferred */
    /* 0x08 */ void* unk8;                          /* inferred */
    /* 0x0C */ void* unkC;                          /* inferred */
    /* 0x10 */ char pad10[4];
    /* 0x14 */ s32 unk14;                           /* inferred */
    /* 0x18 */ u16 unk18;                           /* inferred */
    /* 0x1A */ char pad1A[6];                       /* maybe part of unk18[4]? */
    /* 0x20 */ u8 unk20;                            /* inferred */
    /* 0x21 */ char pad21[3];                       /* maybe part of unk20[4]? */
} UnkStruct_uvtextureld_rom_00400A40;               /* size = 0x24 */


extern UvGfxMgr_Exports* D_uvtextureld_rom_00400B60;
extern UnkTexture_Exports* D_uvtextureld_rom_00400B64;
extern UvTSeq_Exports* D_uvtextureld_rom_00400B68;
extern UvtSeqLd_Rom_Exports* D_uvtextureld_rom_00400B6C;
extern u16 D_uvtextureld_rom_00400B70;
extern u16 D_uvtextureld_rom_00400B72;


void func_uvtextureld_rom_00400A40(UnkStruct_uvtextureld_rom_00400A40 *arg0);

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvtextureld_rom/__entrypoint_func_uvtextureld_rom_400000.s")

void func_uvtextureld_rom_004000C4(void) {
    uvUnloadModule('GMGR');
    uvUnloadModule('TEXT');
    uvUnloadModule('TSEQ');
    uvUnloadModule('UVTS');
}

s32 func_uvtextureld_rom_0040010C(u8* data) {
    s32 fileId;
    void* parsedUvTexture;
    u32 size;
    void* blockData;
    s32 ptr;
    u32 tag;

    parsedUvTexture = NULL;
    fileId = uvFileReadHeader(data);
    tag = uvFileReadBlock(fileId, &size, &blockData, FILE_NOT_COMPRESSED);
    while (tag != 0) {
        switch (tag) {
            case 'COMM':
                ptr = blockData;
                parsedUvTexture = func_uvtextureld_rom_004002E8(ptr);
                _uvMemFree(ptr);
                break;
            default:
                break;
        }
        tag = uvFileReadBlock(fileId, &size, &blockData, FILE_NOT_COMPRESSED);
    }
    uvFileFree(fileId);
    return parsedUvTexture;
}

void* func_uvtextureld_rom_004001C8(u8* arg0) {
    void* var_s0;
    u16 sp3A;
    u16 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;

    uvConsumeBytes(&sp38, &arg0, 2U);
    if (sp38 >= 0x1001) {
        sp38 = 0x1000;
    }
    uvConsumeBytes(&sp3A, &arg0, 2U);
    uvConsumeBytes(&sp34, &arg0, 4U);
    uvConsumeBytes(&sp30, &arg0, 4U);
    uvConsumeBytes(&sp34, &arg0, 4U);
    uvConsumeBytes(&sp30, &arg0, 4U);
    uvConsumeBytes(&sp2C, &arg0, 4U);
    uvConsumeBytes(&sp28, &arg0, 4U);
    if (D_uvtextureld_rom_00400B70 < D_uvtextureld_rom_00400B72) {
        D_uvtextureld_rom_00400B70++;
        var_s0 = _uvMemAlloc((u32) sp38, 8U);
        _uvMediaCopy(var_s0, arg0, (u32) sp38);
    } else {
        var_s0 = D_uvtextureld_rom_00400B64->unk20();
    }
    return var_s0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvtextureld_rom/func_uvtextureld_rom_004002E8.s")


void func_uvtextureld_rom_00400A40(UnkStruct_uvtextureld_rom_00400A40* parsedUvTexture) {
    s32 pad;
    s32* sp20;

    sp20 = parsedUvTexture->unkC;
    if ((parsedUvTexture->unk18 != 0xFFF) && (parsedUvTexture->unk18 != (parsedUvTexture->unk14 & 0xFFF))) {
        uvUnloadFile('UVTX', parsedUvTexture->unk18);
    }
    if (parsedUvTexture->unk20 != 0xFF) {
        D_uvtextureld_rom_00400B68->func_uvtseq_rom_00400620(parsedUvTexture->unk20);
    }
    if (parsedUvTexture->unk4 != NULL) {
        _uvMemFree(parsedUvTexture->unk4);
    }
    if (parsedUvTexture->unk8 != NULL) {
        _uvMemFree(parsedUvTexture->unk8);
    }
    if (parsedUvTexture->unk0 != NULL) {
        _uvMemFree(parsedUvTexture->unk0);
    }
    if ((sp20 != NULL) && (D_uvtextureld_rom_00400B64->unk24() != sp20)) {
        _uvMemFree(sp20);
        D_uvtextureld_rom_00400B70 -= 1;
    }
    _uvMemFree(parsedUvTexture);
}


