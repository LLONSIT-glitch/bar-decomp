// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "uvasset_types.h"

typedef struct UVPXData_s {
    /* 0x00 */ s32 unk0;  /* inferred */
    /* 0x04 */ s32 unk4;  /* inferred */
    /* 0x08 */ s32 unk8;  /* inferred */
    /* 0x0C */ s32 unkC;  /* inferred */
    /* 0x10 */ f32 unk10; /* inferred */
    /* 0x14 */ s32 unk14; /* inferred */
    /* 0x18 */ s32 unk18; /* inferred */
    /* 0x1C */ f32 unk1C; /* inferred */
    /* 0x20 */ f32 unk20; /* inferred */
    /* 0x24 */ f32 unk24; /* inferred */
    /* 0x28 */ s32 unk28; /* inferred */
    /* 0x2C */ f32 unk2C; /* inferred */
    /* 0x30 */ f32 unk30; /* inferred */
    /* 0x34 */ f32 unk34; /* inferred */
    /* 0x38 */ s32 unk38; /* inferred */
    /* 0x3C */ s32 unk3C; /* inferred */
    /* 0x40 */ f32 unk40; /* inferred */
    /* 0x44 */ f32 unk44; /* inferred */
    /* 0x48 */ f32 unk48; /* inferred */
    /* 0x4C */ f32 unk4C; /* inferred */
    /* 0x50 */ f32 unk50; /* inferred */
    /* 0x54 */ f32 unk54; /* inferred */
    /* 0x58 */ f32 unk58; /* inferred */
    /* 0x5C */ f32 unk5C; /* inferred */
    /* 0x60 */ f32 unk60; /* inferred */
    /* 0x64 */ f32 unk64; /* inferred */
    /* 0x68 */ f32 unk68; /* inferred */
} UVPXData;               /* size = 0x6C */

typedef struct PHDR_s {
    /* 0x00 */ s32 unk0;  /* inferred */
    /* 0x04 */ f32 unk4;  /* inferred */
    /* 0x08 */ s32 unk8;  /* inferred */
    /* 0x0C */ f32 unkC;  /* inferred */
    /* 0x10 */ s32 unk10; /* inferred */
    /* 0x14 */ s32 unk14; /* inferred */
} PHDR;                   /* size = 0x18 */

void func_uvpfxld_rom_00400094(void);
void *func_uvpfxld_rom_004000DC(u8 *arg0);
void func_uvpfxld_rom_004002DC(UVPXData *arg0);
void func_uvpfxld_rom_00400994(PHDR *arg0);
void func_uvpfxld_rom_00400B98(void *arg0);
void func_uvpfxld_rom_00400BD4(s32 *arg0);
void func_uvpfxld_rom_00400CBC(s32 *arg0);
void func_uvpfxld_rom_00400CD0(UnkStruct_uvpfx_rom_00404FA0_unk0 *arg0);
void __entrypoint_func_uvpfxld_rom_400000(UvPfxLd_Exports *exports);

// .data

// ! unused
s32 D_uvpfxld_rom_00400EA0 = 0;
s32 D_uvpfxld_rom_00400EA4 = 0;
f32 D_uvpfxld_rom_00400EA8[] = { 0.6f, 0.8f, 0.9f, 0.95f };
s32 D_uvpfxld_rom_00400EB8 = 0;
s32 D_uvpfxld_rom_00400EBC = 256;
s32 D_uvpfxld_rom_00400EC0 = 0;
s32 D_uvpfxld_rom_00400EC4 = 0;
s32 D_uvpfxld_rom_00400EC8 = 0;
s32 D_uvpfxld_rom_00400ECC[] = { 0x000C0000, __entrypoint_func_uvpfxld_rom_400000, 0, 0};

// .bss
UnkStruct_uvpfx_rom_00404FA0 *D_uvpfxld_rom_00400EE0;
UnkStruct_uvpfx_rom_00404FA0_unk0 *D_uvpfxld_rom_00400EE4;
UnkStruct_uvpfx_rom_00404FA0_unk4 *D_uvpfxld_rom_00400EE8[256];
static UvFMtx_Rom_Exports *sUvFMtxExports;
static UvTSeq_Exports *sUvTseqExports;
static UvFVec_Rom_Exports *sUvFvecExports;
static UvPfx_Exports *sUvPfxExports;

void __entrypoint_func_uvpfxld_rom_400000(UvPfxLd_Exports *exports) {
    uvUpdateFileAllocPtr(exports);
    exports->func_uvpfxld_rom_004000DC = func_uvpfxld_rom_004000DC;
    exports->func_uvpfxld_rom_00400094 = func_uvpfxld_rom_00400094;
    exports->func_uvpfxld_rom_00400CD0 = func_uvpfxld_rom_00400CD0;
#ifdef __sgi
#line 78
#endif
    sUvTseqExports = uvLoadModule('TSEQ');
    sUvFMtxExports = uvLoadModule('FMTX');
    sUvFvecExports = uvLoadModule('FVEC');
    sUvPfxExports = uvLoadModule('UPFX');
}

void func_uvpfxld_rom_00400094(void) {
    uvUnloadModule('TSEQ');
    uvUnloadModule('FMTX');
    uvUnloadModule('FVEC');
    uvUnloadModule('UPFX');
}

void *func_uvpfxld_rom_004000DC(u8 *arg0) {
    void *var_s0;
    s32 temp_v0;
    s32 i;
    u32 sp58;
    void *sp54;
    u32 var_v0;

    D_uvpfxld_rom_00400EB8 = *sUvPfxExports->D_uvpfx_rom_00404FA8;
    D_uvpfxld_rom_00400EBC = *sUvPfxExports->D_uvpfx_rom_00404FA4;
    D_uvpfxld_rom_00400EE0 = *sUvPfxExports->D_uvpfx_rom_00404FA0;
    temp_v0 = uvFileReadHeader(arg0);
    while (var_v0 = uvFileReadBlock(temp_v0, &sp58, &sp54, 1)) {
        switch (var_v0) {
            case 'COMM':
                var_s0 = sp54;
                func_uvpfxld_rom_004002DC(var_s0);
                _uvMemFree(var_s0);
                break;
            case 'TEXT':
                var_s0 = sp54;
                func_uvpfxld_rom_00400BD4(var_s0);
                _uvMemFree(var_s0);
                break;
            case 'PIID':
                var_s0 = sp54;
                func_uvpfxld_rom_00400CBC(var_s0);
                _uvMemFree(var_s0);
                break;
            case 'PHDR':
                var_s0 = sp54;
                func_uvpfxld_rom_00400994(var_s0);
                _uvMemFree(var_s0);
                break;
            case 'PDAT':
                var_s0 = sp54;
                func_uvpfxld_rom_00400B98(var_s0);
                _uvMemFree(var_s0);
                break;
        }
    }

    for (i = 0; i < D_uvpfxld_rom_00400EE4->unk0; i++) {
        if (D_uvpfxld_rom_00400EB8 < D_uvpfxld_rom_00400EBC) {
            D_uvpfxld_rom_00400EB8++;
        }
    }
    *sUvPfxExports->D_uvpfx_rom_00404FA8 = D_uvpfxld_rom_00400EB8;
    uvFileFree(temp_v0);
    return D_uvpfxld_rom_00400EE4;
}

void func_uvpfxld_rom_004002DC(UVPXData *arg0) {
    UnkStruct_uvpfx_rom_00404FA0_unk4 *temp_v0_2;
    s16 *temp_a0;
    s16 *temp_v0;
    s32 i;
    s32 temp;

    D_uvpfxld_rom_00400EC8 = arg0->unk14;
    D_uvpfxld_rom_00400EE4 = _uvMemAllocAlign8(sizeof(UnkStruct_uvpfx_rom_00404FA0_unk0));
    D_uvpfxld_rom_00400EE4->unk0 = arg0->unk8;

    for (i = 0; i < D_uvpfxld_rom_00400EE4->unk0; i++) {
        if ((D_uvpfxld_rom_00400EB8 + i) < D_uvpfxld_rom_00400EBC) {
            // unk0?
            D_uvpfxld_rom_00400EE8[i] = _uvMemAllocAlign8(sizeof(UnkStruct_uvpfx_rom_00404FA0_unk4));
            D_uvpfxld_rom_00400EE0[D_uvpfxld_rom_00400EB8 + i].unk4 = D_uvpfxld_rom_00400EE8[i];
            D_uvpfxld_rom_00400EE0[D_uvpfxld_rom_00400EB8 + i].unk0 =
                (UnkStruct_uvpfx_rom_00404FA0_unk0 *) D_uvpfxld_rom_00400EE4;
            continue;
        }
        _uvMemFree(D_uvpfxld_rom_00400EE4);
        return;
    }
    D_uvpfxld_rom_00400EE4->unk1E = 3;
    D_uvpfxld_rom_00400EE4->unk34 = 1.0f;
    D_uvpfxld_rom_00400EE4->unk24 = arg0->unk18;
    D_uvpfxld_rom_00400EE4->unk6 = arg0->unk4;
    if (D_uvpfxld_rom_00400EE4->unk24 == 0) {
        arg0->unk30 = 1.0f;
    }
    D_uvpfxld_rom_00400EE4->unkC = 0x1F560000;
    D_uvpfxld_rom_00400EE4->unk8 = 0xA00000;
    if (arg0->unk0 == 0) {
        D_uvpfxld_rom_00400EE4->unk4 = 2;
        D_uvpfxld_rom_00400EE4->unk2C = _uvMemAllocAlign8(0x10U);
        D_uvpfxld_rom_00400EE4->unk28 = NULL;
    } else {
        D_uvpfxld_rom_00400EE4->unk4 = 1;
        D_uvpfxld_rom_00400EE4->unk2C = NULL;
        D_uvpfxld_rom_00400EE4->unk30 = 0;
        D_uvpfxld_rom_00400EE4->unk28 = _uvMemAllocAlign8(0x1CU);
        D_uvpfxld_rom_00400EE4->unk10 = arg0->unk38;
        D_uvpfxld_rom_00400EE4->unk28->unk0 = arg0->unk3C;
        D_uvpfxld_rom_00400EE4->unk28->unk18 = arg0->unk34;
        D_uvpfxld_rom_00400EE4->unk28->unk8 = 4;
        D_uvpfxld_rom_00400EE4->unk28->unk4 =
            _uvMemAllocAlign8(D_uvpfxld_rom_00400EE4->unk28->unk0 * 4);
        _uvMediaCopy(D_uvpfxld_rom_00400EE4->unk28->unk4, D_uvpfxld_rom_00400EA8,
                     sizeof(f32) * ARRAY_COUNT(D_uvpfxld_rom_00400EA8));
        sUvPfxExports->func_uvpfx_rom_004004D0(
            D_uvpfxld_rom_00400EB8, 0x4027, arg0->unk2C, 0x4029, arg0->unk30, 0x4026, arg0->unk50,
            arg0->unk54, arg0->unk58, arg0->unk5C, 0x1019, 300.0f, 0x1003, arg0->unk1C, arg0->unk20,
            arg0->unk24, 0);
    }
    sUvPfxExports->func_uvpfx_rom_004004D0(
        D_uvpfxld_rom_00400EB8, 0x1022, 20.0f, 0x1023, arg0->unk28, 0x1005, arg0->unk40, arg0->unk44,
        arg0->unk48, arg0->unk4C, 0x1008, 0xFFF, 0x1013, 0xFF, 0);
    for (i = 0; i < D_uvpfxld_rom_00400EE4->unk0; i++) {
        if ((D_uvpfxld_rom_00400EB8 + i) < D_uvpfxld_rom_00400EBC) {
            D_uvpfxld_rom_00400EE8[i]->unk28 = 0xFF;
            if (D_uvpfxld_rom_00400EC8 == 2) {
                D_uvpfxld_rom_00400EE8[i]->unk2A = 2;
            } else {
                D_uvpfxld_rom_00400EE8[i]->unk2A = 1;
            }
            D_uvpfxld_rom_00400EE8[i]->unk2C = 0xFFF;
            D_uvpfxld_rom_00400EE8[i]->unk4 = 0.0f;
            if (arg0->unkC == 1) {
                D_uvpfxld_rom_00400EE8[i]->unk10 = 1000000.0f;
            } else {
                D_uvpfxld_rom_00400EE8[i]->unk10 = arg0->unk10;
            }
            D_uvpfxld_rom_00400EE8[i]->unkC = -2000000.0f;
            D_uvpfxld_rom_00400EE8[i]->unk24 = 0;
            D_uvpfxld_rom_00400EE8[i]->unk6E = 0;
            D_uvpfxld_rom_00400EE8[i]->unkE4 = 0;
            sUvFMtxExports->uvMat4SetIdentity(&D_uvpfxld_rom_00400EE8[i]->unk80);
            sUvFvecExports->uvVec3FSet(&D_uvpfxld_rom_00400EE8[i]->unkC0, 0.0f, 0.0f, 0.0f);
            sUvFvecExports->uvVec3FSet(&D_uvpfxld_rom_00400EE8[i]->unkCC, 0.0f, 0.0f, 0.0f);
            sUvPfxExports->func_uvpfx_rom_004004D0(D_uvpfxld_rom_00400EB8 + i, 0x1007, 1.0f,
                                                            0x1020, 0, 0x1019, 300.0f, 0x1003,
                                                            arg0->unk1C, arg0->unk20, arg0->unk24, 0);
            if (arg0->unk0 == 1) {
                D_uvpfxld_rom_00400EE8[i]->unk22 = -1;
                D_uvpfxld_rom_00400EE8[i]->unk14 = 0 /*.0f*/;
                D_uvpfxld_rom_00400EE8[i]->unk18 = 0.5f;
                sUvPfxExports->func_uvpfx_rom_004004D0(
                    D_uvpfxld_rom_00400EB8 + i, 0x4033, arg0->unk60, arg0->unk64, arg0->unk68, 0);
                D_uvpfxld_rom_00400EE0[D_uvpfxld_rom_00400EB8 + i].unk8 =
                    _uvMemAllocAlign8(D_uvpfxld_rom_00400EE4->unk28->unk0 * 0xC);
            }
        }
    }
}

void func_uvpfxld_rom_00400994(PHDR *arg0) {
    UnkStruct_uvpfx_rom_00404FA0_unk4 *temp_v0;
    s32 i;

    D_uvpfxld_rom_00400EC0 = arg0->unk14;
    D_uvpfxld_rom_00400EC4 = arg0->unk10;
    D_uvpfxld_rom_00400EE4->unk30 = _uvMemAllocAlign8(arg0->unk14 * 2);
    D_uvpfxld_rom_00400EE4->unk10 = (s16) arg0->unk0;
    D_uvpfxld_rom_00400EE4->unk2C->unk0 = (s16) arg0->unk10;
    D_uvpfxld_rom_00400EE4->unk2C->unk8 = (s16) arg0->unk8;
    D_uvpfxld_rom_00400EE4->unk2C->unkC = arg0->unk4;
    D_uvpfxld_rom_00400EE4->unk2C->unk4 = 1.0f / arg0->unkC;
    for (i = 0; i < D_uvpfxld_rom_00400EE4->unk0; i++) {
        if ((D_uvpfxld_rom_00400EB8 + i) < D_uvpfxld_rom_00400EBC) {
            temp_v0 = D_uvpfxld_rom_00400EE8[i];
            if (temp_v0->unk10 == 0.0f) {
                temp_v0->unk10 = arg0->unk4;
            }
            if (arg0->unk10 == 9) {
                D_uvpfxld_rom_00400EE0[D_uvpfxld_rom_00400EB8 + i].unk8 =
                    _uvMemAllocAlign8(D_uvpfxld_rom_00400EE4->unk10 * 0xC);
            } else {
                D_uvpfxld_rom_00400EE0[D_uvpfxld_rom_00400EB8 + i].unk8 = NULL;
            }
        }
    }
}

void func_uvpfxld_rom_00400B98(void *arg0) {
    _uvMediaCopy(D_uvpfxld_rom_00400EE4->unk30, arg0, D_uvpfxld_rom_00400EC0 * 2);
}

void func_uvpfxld_rom_00400BD4(s32 *arg0) {
    s32 temp_s1;
    s32 i;

    temp_s1 = *arg0;
    for (i = 0; i < D_uvpfxld_rom_00400EE4->unk0; i++) {
        if (D_uvpfxld_rom_00400EC8 == 0) {
            sUvPfxExports->func_uvpfx_rom_004004D0(D_uvpfxld_rom_00400EB8 + i, 0x1008, temp_s1,
                                                            0);
        } else {
            sUvPfxExports->func_uvpfx_rom_004004D0(D_uvpfxld_rom_00400EB8 + i, 0x1013, temp_s1,
                                                            0);
        }
    }
}

void func_uvpfxld_rom_00400CBC(s32 *arg0) {
    D_uvpfxld_rom_00400EE4->unk2 = *arg0;
}

void func_uvpfxld_rom_00400CD0(UnkStruct_uvpfx_rom_00404FA0_unk0 *arg0) {
    s32 i;
    s32 j;

    D_uvpfxld_rom_00400EB8 = *sUvPfxExports->D_uvpfx_rom_00404FA8;
    D_uvpfxld_rom_00400EE0 = *sUvPfxExports->D_uvpfx_rom_00404FA0;

    for (i = 0; i < D_uvpfxld_rom_00400EB8; i++) {
        if (arg0 == D_uvpfxld_rom_00400EE0[i].unk0) {
            if (D_uvpfxld_rom_00400EE0[i].unk8 != NULL) {
                _uvMemFree(D_uvpfxld_rom_00400EE0[i].unk8);
            }
            _uvMemFree(D_uvpfxld_rom_00400EE0[i].unk4);
            if (D_uvpfxld_rom_00400EB8 >= 2) {
                D_uvpfxld_rom_00400EB8--;
                for (j = i; j < D_uvpfxld_rom_00400EB8; j++) {
                    D_uvpfxld_rom_00400EE0[j].unk0 = D_uvpfxld_rom_00400EE0[j + 1].unk0;
                    D_uvpfxld_rom_00400EE0[j].unk4 = D_uvpfxld_rom_00400EE0[j + 1].unk4;
                    D_uvpfxld_rom_00400EE0[j].unk8 = D_uvpfxld_rom_00400EE0[j + 1].unk8;
                }
                i--;
            } else {
                D_uvpfxld_rom_00400EB8 = 0;
            }
        }
    }

    *sUvPfxExports->D_uvpfx_rom_00404FA8 = D_uvpfxld_rom_00400EB8;
    if (arg0->unk2C != NULL) {
        _uvMemFree(arg0->unk2C);
    }
    if (arg0->unk28 != NULL) {
        void *a1 = arg0->unk28->unk4;
        if (a1 != NULL) {
            _uvMemFree(a1);
        }
        _uvMemFree(arg0->unk28);
    }
    if (arg0->unk30 != NULL) {
        _uvMemFree(arg0->unk30);
    }
    _uvMemFree(arg0);
}
