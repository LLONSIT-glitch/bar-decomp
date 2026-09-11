// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"

typedef struct UnkTexture_Exports_s {
    /* 0x00 */ char pad0[0x20];
    /* 0x20 */ void* (*unk20)(void);
    /* 0x24 */ void* (*unk24)(void);                      /* inferred */
    /* 0x28 */ char pad28[4];
} UnkTexture_Exports;                               /* size = 0x2C */

typedef struct UvTextureLd_Exports_s {
    /* 0x0 */ void (*unk0)(void);                       /* inferred */
    /* 0x4 */ s32 (*unk4)(u8 *);                    /* inferred */
    /* 0x8 */ void (*unk8)(UnkStruct_uvtextureld_rom_00400A40 *); /* inferred */
} UvTextureLd_Exports;                              /* size = 0xC */


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

void* func_uvtextureld_rom_004002E8(u8* arg0);
void __entrypoint_func_uvtextureld_rom_400000(UvTextureLd_Exports *exports);
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

void* func_uvtextureld_rom_004002E8(u8* arg0) {
    u32 temp_t0;
    Gfx* sp178;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 pad;
    s32 var_a3;
    s32 var_a2;
    u16 pad_sp162;
    u16 sp160;
    u16 sp15E;
    u16 pad_sp15C;
    UnkUVTX_1C* sp158;
    UnkUVTX_1C* sp154;
    f32 sp150;
    f32 sp14C;
    s32 i;
    u8* sp144 = arg0;
    f32 sp140;
    f32 sp13C;
    s32 sp138;
    u16 sp136;
    u8 sp135;
    s32 j;
    s32 k;
    s32 pad2;
    ParsedUVTX* temp_v0;
    s32 pad3[4];
    u16 sp54[6][16];
    s32 sp50;
    ParsedUVTX* var_v1;

    uvConsumeBytes(&sp15E, &arg0, 2);
    if (sp15E > 0x1000) {
        sp15E = 0x1000;
    }
    uvConsumeBytes(&sp160, &arg0, 2);
    uvConsumeBytes(&sp150, &arg0, 4);
    uvConsumeBytes(&sp14C, &arg0, 4);
    if ((sp150 != 0.0f) || (sp14C != 0.0f)) {
        sp158 = _uvMemAllocAlign8(0x1C);
        sp158->unk0 = 1.0f;
        sp158->unk4 = 1.0f;
        sp158->unk8 = sp150;
        sp158->unkC = sp14C;
        sp158->unk18 = 0;
        sp158->unk19 = 0;
        sp158->unk1A = 1;
        sp158->unk10 = 0.0f;
        sp158->unk14 = 0.0f;
    } else {
        sp158 = NULL;
    }
    uvConsumeBytes(&sp150, &arg0, 4);
    uvConsumeBytes(&sp14C, &arg0, 4);
    uvConsumeBytes(&sp140, &arg0, 4);
    uvConsumeBytes(&sp13C, &arg0, 4);
    if ((sp150 != 0.0f) || (sp14C != 0.0f) || (sp140 != 0.0f) || (sp13C != 0.0f)) {
        sp154 = _uvMemAllocAlign8(0x1C);
        sp154->unk0 = 1.0f;
        sp154->unk4 = 1.0f;
        sp154->unk8 = sp150;
        sp154->unkC = sp14C;
        sp154->unk10 = sp140;
        sp154->unk14 = sp13C;
        sp154->unk18 = 0;
        sp154->unk19 = 0;
        sp154->unk1A = 1;
    } else {
        sp154 = NULL;
    }
    arg0 += sp15E;
    sp178 = _uvMemAlloc(sp160 * 8, 8);
    uvConsumeBytes(sp178, &arg0, sp160 * 8);
    temp_v0 = _uvMemAllocAlign8(0x28);
    uvConsumeBytes(&temp_v0->width, &arg0, 2);
    uvConsumeBytes(&temp_v0->height, &arg0, 2);
    uvConsumeBytes(&temp_v0->unk24, &arg0, 1);
    uvConsumeBytes(&temp_v0->unk25, &arg0, 1);
    uvConsumeBytes(&temp_v0->unk26, &arg0, 1);
    uvConsumeBytes(&temp_v0->unk14, &arg0, 4);
    uvConsumeBytes(&temp_v0->pad18, &arg0, 2);
    uvConsumeBytes(&sp136, &arg0, 2);
    temp_v0->unk27 =  sp136;
    uvConsumeBytes(&temp_v0->unk21, &arg0, 1);
    uvConsumeBytes(&sp135, &arg0, 1);
    uvConsumeBytes(&sp135, &arg0, 1);
    uvConsumeBytes(&sp135, &arg0, 1);
    uvConsumeBytes(&sp135, &arg0, 1);
    uvConsumeBytes(&sp138, &arg0, 4);
    uvConsumeBytes(&temp_v0->unk23, &arg0, 1);
    uvConsumeBytes(&temp_v0->unk22, &arg0, 1);
    temp_v0->unk20 = 0xFF;
    if (temp_v0->unk14 & 0x80000) {
        sp50 = FALSE;
        temp_v0->unk20 = D_uvtextureld_rom_00400B68->func_uvtseq_rom_004005BC();
        if (temp_v0->unk20 != 0xFF) {
            temp_v0_6 = uvGetFilesCount('UVTS');
            for (i = 0; i < temp_v0_6; i++) {
                if (D_uvtextureld_rom_00400B6C->func_uvtseqld_rom_0040029C(i) == (temp_v0->unk14 & 0xFFF)) {
                    sp50 = TRUE;
                    uvLoadFile('UVTS', i);
                    D_uvtextureld_rom_00400B68->func_uvtseq_rom_00400378((s32) temp_v0->unk20, i);
                    temp_v0_7 = D_uvtextureld_rom_00400B68->func_uvtseq_rom_0040096C((s32) temp_v0->unk20);
                    for (j = 1; j < temp_v0_7; j++) {
                        uvLoadFile('UVTX', D_uvtextureld_rom_00400B68->func_uvtseq_rom_0040098C(temp_v0->unk20, j));
                    }
                    break;
                }
            }
        }
        if (!sp50) {
            temp_v0->unk14 &= ~0x80000;
            if (temp_v0->unk20 != 0xFF) {
                D_uvtextureld_rom_00400B68->func_uvtseq_rom_00400620(temp_v0->unk20);
            }
            temp_v0->unk20 = 0xFF;
        }
    }
    if (temp_v0->unk21 == 0) {
        for (i = 0; i < temp_v0->unk22; i++)  {
            uvConsumeBytes(&sp54[i], &arg0, 0x20);
        }
    }
    temp_v0->unk1A = sp15E;
    temp_t0 = func_uvtextureld_rom_004001C8(sp144);
    temp_v0->unk0 = sp178;
    temp_v0->data.pointer = temp_t0;
    temp_v0->unk4 = sp158;
    temp_v0->size.as_s32 = sp154;
    var_a2 = 0;
    for (i = 0; i < sp160; i++) {
        Gfx* gfxCmd = &sp178[i];
        u32* v0;
        u8 cmd = gfxCmd->setimg.cmd;
        if (cmd != 0xFD) {
            continue;
        }
        if (var_a2 == 0) {
            gfxCmd->setimg.dram |= (u32)OS_PHYSICAL_TO_K0(temp_t0);
        } else {
            if (temp_v0->pad18 == (temp_v0->unk14 & 0xFFF)) {
                var_v1 = temp_v0;
            } else {
                var_v1 = uvLoadFile('UVTX', temp_v0->pad18);
            }
            v0 = &gfxCmd->setimg.dram;
            if (var_v1 == NULL) {
            }  else {
                *v0 |= (u32)OS_PHYSICAL_TO_K0(var_v1->data.pointer);
            }
        }
        var_a2++;
    }
    if (temp_v0->unk21 == 0) {
        temp_v0->unk10 = _uvMemAlloc(temp_v0->unk22 * 0x80, 0x10);
        for (j = 0; j < temp_v0->unk22; j++) {
            for (i = 0; i < 0x10; i++) {
                temp_v0->unk10[(j * 0x40) + 0x0 + i] =
                    temp_v0->unk10[(j * 0x40) + 0x10 + i] =
                        temp_v0->unk10[(j * 0x40) + 0x20 + i] = 
                            temp_v0->unk10[(j * 0x40) + 0x30 + i] = sp54[j][i];
            }
        }
    } else {
        temp_v0->unk10 = NULL;
    }
    return temp_v0;
}

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


