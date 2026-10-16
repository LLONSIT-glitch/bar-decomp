// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "uvasset_types.h"
// uvchan_rom exports
typedef struct UnkStruct_uvterra_rom_0040F760_s {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ void (*unk4)(s32, s32, f32 *, s32); /* inferred */
    /* 0x08 */ char pad8[0x24];                    /* maybe part of unk4[0xA]? */
    /* 0x2C */ s32 (*unk2C)(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4); /* inferred */
} UnkStruct_uvterra_rom_0040F760;                                              /* size = 0x30 */

typedef struct UnkStruct_uvterra_rom_0040F768_s {
    /* 0x00 */ char pad0[0x18];
    /* 0x18 */ s32 (*unk18)(Vtx *, u16, u16, u16, void *, f32); /* inferred */
} UnkStruct_uvterra_rom_0040F768;                               /* size = 0x1C */

/*
 * D_uvterra_rom_0040F760 = uvLoadModule('CHAN');
 * D_uvterra_rom_0040F770 = uvLoadModule(0x534F5254);
 * D_uvterra_rom_0040F74C = uvLoadModule(0x494D5458);
 * D_uvterra_rom_0040F744 = uvLoadModule('FMTX');
 * D_uvterra_rom_0040F748 = uvLoadModule('FVEC');
 * D_uvterra_rom_0040F750 = uvLoadModule(0x53544154);
 * D_uvterra_rom_0040F754 = uvLoadModule(0x474D4752);
 * D_uvterra_rom_0040F75C = uvLoadModule('MATH');
 * D_uvterra_rom_0040F758 = uvLoadModule('MODL');
 * D_uvterra_rom_0040F764 = uvLoadModule('CBCK');
 * D_uvterra_rom_0040F768 = uvLoadModule('ISCT');
 * D_uvterra_rom_0040F76C = uvLoadModule('QERY');
 */

u16 func_uvterra_rom_0040B0C4(s16 arg0, s16 arg1, u8 arg2);
void func_uvterra_rom_0040B26C(s16 *arg0, s16 *arg1, u16 *arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
                               f32 arg7, f32 arg8, f32 arg9, u8 arg10, f32 arg11, f32 arg12);
void *func_uvterra_rom_0040C0F8(s32);
void func_uvterra_rom_0040C218(s32);
s32 func_uvterra_rom_0040B8C0(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 *arg4, f32 *arg5, f32 *arg6,
                              s16 *arg7, s16 *arg8, u8 arg9);
s16 func_uvterra_rom_0040BD38(f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32,
                              uvUnkTileStruct *); /* extern */

extern UvCback_Exports *D_uvterra_rom_0040F764;
extern s32 *D_uvterra_rom_0040F77C;
extern UvMath_Exports *D_uvterra_rom_0040F75C;
extern UvQuery_Exports *D_uvterra_rom_0040F76C;
extern f32 D_uvterra_rom_0040D6A8;
extern s32 D_uvterra_rom_0040F740;
extern s32 D_uvterra_rom_0040FBEC;
extern UvIntersect_Exports *D_uvterra_rom_0040F768;
extern UvFVec_Rom_Exports *D_uvterra_rom_0040F748;
extern s32 *D_uvterra_rom_0040F784;
extern f32 D_uvterra_rom_0040D6AC;
extern f32 D_uvterra_rom_0040D6B0;
extern f32 *D_uvterra_rom_0040F780;
extern Vec3F *D_uvterra_rom_0040F788;
extern UvFMtx_Rom_Exports *D_uvterra_rom_0040F744;
extern UvModel_Exports *D_uvterra_rom_0040F758;
extern s32 *D_uvterra_rom_0040F78C;
extern u16 D_uvterra_rom_0040D718[64][64];

#define UV_COMPUTE_LINE_MACRO(cond, arg2, arg0)                                                        \
    if ((cond)) {                                                                                      \
        *(arg2) = 0;                                                                                   \
    }                                                                                                  \
    *(arg0) = -1;

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/__entrypoint_func_uvterra_rom_400000.s")

void func_uvterra_rom_004005A4(void) {
    uvUnloadModule('IMTX');
    uvUnloadModule('FMTX');
    uvUnloadModule('FVEC');
    uvUnloadModule('STAT');
    uvUnloadModule('GMGR');
    uvUnloadModule('MATH');
    uvUnloadModule('MODL');
    uvUnloadModule('CHAN');
    uvUnloadModule('CBCK');
    uvUnloadModule('ISCT');
    uvUnloadModule('SORT');
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_00400640.s")

void func_uvterra_rom_004006E0(s32 arg0, s32 arg1) {
    if ((arg1 == 0xFFFF) || (arg1 == -1)) {
        D_uvterra_rom_0040F77C[arg0] = 0xFFFF;
    } else if (uvGetLoadedFile('UVTR', arg1) == NULL) {
        D_uvterra_rom_0040F77C[arg0] = 0xFFFF;
    } else {
        D_uvterra_rom_0040F77C[arg0] = arg1;
    }
}

s32 func_uvterra_rom_00400774(s32 arg0) {
    return D_uvterra_rom_0040F77C[arg0];
}

// _uvTerraDraw
#ifdef NEEDS_RODATA
void func_uvterra_rom_0040078C(s32 arg0) {
    s32 var_v0;
    s32 sp1A8;
    s32 sp1A4;
    s32 var_v1;
    s32 sp19C;
    s32 var_t2;
    s32 var_t3;
    s32 var_t4;
    s32 var_t5;
    f32 temp_fs2;
    f32 temp_fs3;
    f32 x;
    f32 y;
    f32 z;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fa0;
    f32 temp_fv1;
    f32 temp_fv0;
    Vec3F sp158;
    Vec3F sp14C;
    f32 temp_fs2_2;
    f32 temp_fs3_2;
    f32 temp_fs4;
    f32 temp_fs5;
    f32 temp_fa1;
    f32 var_ft4;
    f32 var_fv0;
    u16 temp_s0;
    u16 temp_v0_6;
    u16 var_s6;
    u16 temp_v0;
    s32 temp_t0;
    f32 sp110[5];
    f32 spFC[5];
    f32 spE8[5];
    u8 spE0[5];
    u16 spDE;
    ParsedUVTR_inner *temp_fp;
    UnkStruct_uvterra_rom_0040FBE8 *temp_s0_2;
    UnkStruct_uvterra_rom_0040078C *temp_v0_2;
    s16 spCE;
    s16 spCC;
    ParsedUVTR *spC8;
    s32 i;
    f32 temp_ft0;
    UnkStruct_uvterra_rom_0040F774 *spBC;

    spBC = &D_uvterra_rom_0040F774[arg0];
    D_uvterra_rom_0040F740 = 0;
    if (D_uvterra_rom_0040F77C[arg0] == 0xFFFF) {
        return;
    }

    spC8 = uvGetLoadedFile('UVTR', D_uvterra_rom_0040F77C[arg0]);
    if (spC8 == NULL) {
        return;
    }

    func_uvterra_rom_0040C218(arg0);
    temp_v0_2 = func_uvterra_rom_0040C0F8(arg0);
    temp_fs2 = spC8->unk1C;
    temp_fs3 = spC8->unk20;
    var_t2 = (s32) ((temp_v0_2->unk0 - spC8->unk0.unk0) / temp_fs2);
    var_t3 = (s32) ((temp_v0_2->unkC - spC8->unk0.unk0) / temp_fs2);
    var_t4 = (s32) ((temp_v0_2->unk4 - spC8->unk0.unk4) / temp_fs3);
    var_t5 = (s32) ((temp_v0_2->unk10 - spC8->unk0.unk4) / temp_fs3);

    if (var_t2 < 0) {
        var_t2 = 0;
    }

    if ((spC8->unk18 - 1) < var_t3) {
        var_t3 = spC8->unk18 - 1;
    }
    if (var_t4 < 0) {
        var_t4 = 0;
    }

    if ((spC8->unk19 - 1) < var_t5) {
        var_t5 = spC8->unk19 - 1;
    }

    for (i = 0; i < spBC->unk48; i++) {
        temp_fv1 = spBC->unk0[i].x;
        temp_fa1 = spBC->unk0[i].y;
        if (i < (spBC->unk48 - 1)) {
            var_fv0 = spBC->unk0[i + 1].x;
            var_ft4 = spBC->unk0[i + 1].y;
        } else {
            var_fv0 = spBC->unk0[0].x;
            var_ft4 = spBC->unk0[0].y;
        }

        temp_fa0 = var_fv0 - temp_fv1;
        temp_ft0 = var_ft4 - temp_fa1;

        if (temp_fa0 == 0.0f) {
            sp110[i] = 2140143600.0f;
            spE8[i] = 0.0f;
            spFC[i] = temp_fv1;
            if (temp_ft0 > 0.0f) {
                spE0[i] = 1;
            } else {
                spE0[i] = 0;
            }
        } else {
            temp_fv0 = (var_ft4 - temp_fa1) / temp_fa0;
            if (temp_fa0 > 0.0f) {
                spE0[i] = 1;
            } else {
                spE0[i] = 0;
            }
            sp110[i] = temp_fv0;
            spE8[i] = 1.0f / temp_fv0;
            spFC[i] = temp_fa1 - (temp_fv0 * temp_fv1);
        }
    }

    D_uvterra_rom_0040F760->unk4(arg0, 7, &sp158, 0);
    D_uvterra_rom_0040F760->unk4(arg0, 8, &sp14C, 0);

    for (sp1A8 = var_t2; sp1A8 <= var_t3; sp1A8++) {
        for (sp1A4 = var_t4; sp1A4 <= var_t5; sp1A4++) {
            if ((D_uvterra_rom_0040FBEC != 0) && (sp14C.x > 0.0f) ^ (D_uvterra_rom_0040FBEC == 2)) {
                var_v1 = (var_t3 - sp1A8) + var_t2;
            } else {
                var_v1 = sp1A8;
            }
            if ((D_uvterra_rom_0040FBEC != 0) && (sp14C.y > 0.0f) ^ (D_uvterra_rom_0040FBEC == 2)) {
                var_v0 = (var_t5 - sp1A4) + var_t4;
            } else {
                var_v0 = sp1A4;
            }
            sp19C = (spC8->unk18 * var_v0) + var_v1;
            temp_fp = spC8->unk28 + sp19C;
            if (temp_fp == NULL) {
                continue;
            }

            if (temp_fp->unk40 == NULL) {
                continue;
            }

            x = (temp_fp->unk30 + temp_fp->unk40->unk18);
            y = (temp_fp->unk34 + temp_fp->unk40->unk1C);
            z = (temp_fp->unk38 + temp_fp->unk40->unk20);
            if (!D_uvterra_rom_0040F760->unk2C(arg0, x - sp158.x, y - sp158.y, z - sp158.z,
                                               temp_fp->unk40->unk24)) {
                continue;
            }

            temp_fs0 = 15.0f / temp_fs2;
            temp_fs1 = 15.0f / temp_fs3;
            temp_fs2_2 = temp_fp->unk30 - (0.5f * temp_fs2);
            temp_fs3_2 = temp_fp->unk30 + (0.5f * temp_fs2);
            temp_fs4 = temp_fp->unk34 + (0.5f * temp_fs3);
            temp_fs5 = temp_fp->unk34 - (0.5f * temp_fs3);

            var_s6 = 0;
            spDE = 0xFFFF;
            for (i = 0; i < spBC->unk48; i++) {
                func_uvterra_rom_0040B26C(&spCE, &spCC, &spDE, temp_fs2_2, temp_fs3_2, temp_fs4,
                                          temp_fs5, spFC[i], sp110[i], spE8[i], (s32) spE0[i], temp_fs0,
                                          temp_fs1);
                if (spCE >= 0) {
                    temp_s0 = func_uvterra_rom_0040B0C4(spCE, spCC, 0);
                    temp_v0_6 = func_uvterra_rom_0040B0C4(spCE, spCC, 1);
                    var_s6 |= temp_s0 & temp_v0_6;
                    if (spE0[i] != 0) {
                        spDE &= temp_v0_6;
                    } else {
                        spDE &= temp_s0;
                    }
                }

                if (spDE == 0) {
                    break;
                }
            }

            temp_v0 = spDE & ~var_s6;
            if (spDE) {
                temp_s0_2 = &D_uvterra_rom_0040FBE8[D_uvterra_rom_0040F740];
                temp_s0_2->unk0 = temp_fp;
                temp_s0_2->unk6 = spDE;
                temp_s0_2->unk4 = temp_v0;
                temp_s0_2->unkC = sp19C;

                temp_s0_2->unk8 = D_uvterra_rom_0040F75C->uvSqrtf(
                    SQ(sp158.z - temp_fp->unk38)
                    + (SQ(sp158.x - temp_fp->unk30) + SQ(sp158.y - temp_fp->unk34)));
                D_uvterra_rom_0040F740++;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_0040078C.s")
#endif

// uvTerraGetPlane
void func_uvterra_rom_00400E70(s32 arg0, u32 arg1, f32 arg2, f32 arg3, f32 *arg4, Vec3F *arg5) {
    f32 temp_ft5;
    uvUnkTileStruct *sp60;
    ParsedUVTR *temp_v0;
    Unk80225FBC_0x28_UnkC *sp58;
    Vtx *sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    s16 sp46;
    s16 sp44;
    Unk80225FBC_0x28 *v1;
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_fv0;

    if (arg1 == -1) {
        return;
    }

    temp_v0 = uvGetLoadedFile('UVTR', arg0);
    if (temp_v0 == NULL) {
        return;
    }

    sp60 = &temp_v0->unk28[(arg1 >> 0x16) & 0x3FF];
    v1 = &sp60->unk40->unk8[(arg1 >> 0xC) & 0x3FF];
    sp58 = &v1->unk18[arg1 & 0xFFF];
    sp54 = sp60->unk40->vtxTable;

    func_uvterra_rom_0040B8C0(temp_v0, arg2, arg3, 0.0f, &sp50, &sp4C, &sp48, &sp46, &sp44, 0U);
    sp50 *= sp60->unk40->unk2C;
    sp4C *= sp60->unk40->unk2C;
    sp48 *= sp60->unk40->unk30;
    temp_fv0 = (sp60->unk40->unk2C / sp60->unk40->unk30);
    if (D_uvterra_rom_0040F768->func_uvintersect_rom_00400804(sp54, sp58->unk0, sp58->unk2, sp58->unk4,
                                                              arg5, temp_fv0)
        == 0) {
        arg5->x = 0.0f;
        arg5->y = 0.0f;
        arg5->z = 1.0f;
    }

    temp_ft5 = sp54[sp58->unk0].v.ob[0];
    temp_fa0 = sp54[sp58->unk0].v.ob[1];
    temp_fa1 = sp54[sp58->unk0].v.ob[2];
    if (arg5->z != 0.0f) {
        *arg4 = (((arg5->x * (temp_ft5 - sp50)) + (arg5->y * (temp_fa0 - sp4C))) / (arg5->z * temp_fv0))
                + temp_fa1;
        *arg4 /= sp60->unk40->unk30;
        *arg4 += sp60->unk0.m[3][2];
    }
}

void func_uvterra_rom_004010B4(s32 arg0, u32 arg1, Vec3F *arg2) {
    ParsedUVCT *temp_v0_2;
    ParsedUVTR *temp_v0;
    Unk80225FBC_0x28 *t;
    uvUnkTileStruct *t2;
    Unk80225FBC_0x28_UnkC *temp_v1;

    if (arg1 == -1U) {
        return;
    }

    temp_v0 = uvGetLoadedFile(0x55565452, arg0);
    if (temp_v0 == NULL) {
        return;
    }

    t2 = &temp_v0->unk28[(arg1 >> 0x16) & 0x3FF];
    temp_v0_2 = t2->unk40;
    t = &temp_v0_2->unk8[(arg1 >> 0xC) & 0x3FF];
    temp_v1 = &t->unk18[arg1 & 0xFFF];

    if (D_uvterra_rom_0040F768->func_uvintersect_rom_00400804(temp_v0_2->vtxTable, temp_v1->unk0,
                                                              temp_v1->unk2, temp_v1->unk4, arg2,
                                                              temp_v0_2->unk2C / temp_v0_2->unk30)
        == 0) {
        arg2->x = 0.0f;
        arg2->y = 0.0f;
        arg2->z = 0.0f;
    }
}

s32 func_uvterra_rom_004011A4(s32 arg0, u32 arg1) {
    ParsedUVCT *temp_a1;
    ParsedUVTR *temp_v0;
    s32 temp_t6;
    uvUnkTileStruct *temp_a0;
    Unk80225FBC_0x28 *t;

    if (arg1 == -1U) {
        return 0xFFF;
    }
    temp_v0 = uvGetLoadedFile(0x55565452, arg0);
    if (temp_v0 == NULL) {
        return 0xFFF;
    }
    temp_t6 = (arg1 >> 0x16) & 0x3FF;
    if (temp_t6 >= (temp_v0->unk18 * temp_v0->unk19)) {
        return 0xFFF;
    }
    temp_a0 = &temp_v0->unk28[temp_t6];
    if (temp_a0 == NULL) {
        return 0xFFF;
    }
    temp_a1 = temp_a0->unk40;
    if (temp_a1 == NULL) {
        return 0xFFF;
    }
    t = &temp_a1->unk8[(arg1 >> 0xC) & 0x3FF];
    return t->texture;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_00401284.s")

void *func_uvterra_rom_00401E28(s32 arg0) {
    void *temp_v0;

    temp_v0 = uvGetLoadedFile('UVTR', arg0);
    if (temp_v0 == NULL) {
        return NULL;
    }
    return temp_v0;
}

u32 func_uvterra_rom_00401E64(s32 arg0, f32 arg1, f32 arg2, s32 **arg3) {
    f32 spC4;
    f32 spC0;
    f32 spBC;
    ParsedUVCT *temp_s4;
    ParsedUVTR *temp_v0;
    Unk80225FBC_0x28 *temp_s1;
    Unk80225FBC_0x28_UnkC *temp_v1;
    Vtx *temp_a0;
    u16 spA6;
    Vtx *temp_a1;
    u16 sp9E;
    Vtx *temp_a2;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 temp_fv1;
    uvUnkTileStruct *v0;
    u16 j;
    u16 i;
    u32 var_s2;

    var_s2 = 0;
    temp_v0 = uvGetLoadedFile('UVTR', arg0);
    if (func_uvterra_rom_0040B8C0(temp_v0, arg1, arg2, 0.0f, &spC4, &spC0, &spBC, &sp9E, (s16 *) &spA6,
                                  0)
        == 0) {
        *arg3 = NULL;
        return 0U;
    }
    v0 = &temp_v0->unk28[sp9E];
    temp_s4 = v0->unk40;
    if (temp_s4 == NULL) {
        *arg3 = NULL;
        return 0U;
    }
    spC4 *= temp_s4->unk2C;
    spC0 *= temp_s4->unk2C;
    spBC *= temp_s4->unk30;
    for (i = 0; i < temp_s4->unkC; i++) {
        temp_s1 = &temp_s4->unk8[i];
        if (!(temp_s1->unk1E & spA6)) {
            continue;
        }

        for (j = 0; j < temp_s1->unk1C; j++) {
            temp_v1 = &temp_s1->unk18[j];
            if (!(temp_v1->unk6 & spA6)) {
                continue;
            }
            temp_a0 = (Vtx *) temp_s4->vtxTable + temp_v1->unk0;
            temp_ft5 = temp_a0->v.ob[0];
            temp_a1 = (Vtx *) temp_s4->vtxTable + temp_v1->unk2;
            temp_fs0 = temp_a1->v.ob[0];
            temp_a2 = (Vtx *) temp_s4->vtxTable + temp_v1->unk4;
            temp_fs1 = temp_a2->v.ob[0];

            if (((temp_ft5 < spC4)) && (temp_fs0 < spC4) && (temp_fs1 < spC4)) {
                continue;
            }

            if (((spC4 < temp_ft5) && (spC4 < temp_fs0) && (spC4 < temp_fs1))) {
                continue;
            }

            temp_fv0 = temp_a0->v.ob[1];
            temp_fv1 = temp_a1->v.ob[1];
            temp_ft4 = temp_a2->v.ob[1];

            if (((temp_fv0 < spC0)) && (temp_fv1 < spC0) && (temp_ft4 < spC0)) {
                continue;
            }

            if (((spC0 < temp_fv0) && (spC0 < temp_fv1) && (spC0 < temp_ft4))) {
                continue;
            }

            if (D_uvterra_rom_0040F768->func_uvintersect_rom_00400E60(
                    spC4, spC0, temp_ft5, temp_fv0, temp_fs0, temp_fv1, temp_fs1, temp_ft4, 1.0f)
                == 0) {
                continue;
            }
            D_uvterra_rom_0040F784[var_s2++] = (sp9E << 12 << 10) + ((i & 0x3FF) << 0xC) + (j & 0xFFF);
            if (var_s2 >= D_uvterra_rom_0040F76C->func_uvquery_rom_00400224()) {
                break;
            }
        }
    }
    *arg3 = D_uvterra_rom_0040F784;
    return var_s2;
}

#ifdef NEEDS_RODATA

s32 func_uvterra_rom_00402244(s32 terraId, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
                              s32 **arg7, f32 **arg8) {
    ParsedUVTR *uvtr;
    uvUnkTileStruct *temp_s1;
    ParsedUVCT *uvct;
    Unk80225FBC_0x28 *temp_s1_2;
    Unk80225FBC_0x28_UnkC *temp_v0_2;
    Vtx *vtx1;
    Vtx *vtx2;
    Vtx *vtx3;
    Vec3F sp1C4;
    f32 sp1C0;
    f32 sp1BC;
    f32 sp1B8;
    f32 sp1B4;
    f32 sp1B0;
    f32 sp1AC;
    u16 sp1AA;
    u16 sp1A8;
    u16 sp1A6;
    u16 sp1A4;
    u16 var_s0;
    u8 var_s3;
    f32 var_fa0;
    f32 var_fa1;
    f32 var_ft4;
    s32 sp190;
    s32 sp18C;
    f32 var_ft5;
    s32 temp_s5;
    s32 var_v0;
    s32 var_v1;
    f32 sp178;
    f32 sp174;
    f32 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp164;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp14C;
    f32 sp148;
    f32 sp144;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 temp1;
    f32 temp2;
    f32 temp3;
    f32 temp_fs0;
    f32 temp_fs2;
    f32 temp_fs3;
    f32 sp11C;
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    f32 temp_fv0;
    f32 temp_fv1;
    u8 sp103;
    u8 sp102;
    u8 temp_s0;
    u8 temp_t3;

    var_s3 = 0;
    if ((arg1 == arg4) && (arg2 == arg5) && (arg3 == arg6)) {
        *arg7 = NULL;
        *arg8 = NULL;
        return 0;
    }
    uvtr = uvGetLoadedFile('UVTR', terraId);
    if (uvtr == NULL) {
        return 0;
    }

    sp178 = uvtr->unk1C;
    sp174 = uvtr->unk20;
    sp14C = arg1;
    sp148 = arg2;
    sp144 = arg4;
    sp140 = arg5;
    temp_fs2 = arg4 - arg1;
    temp_fs3 = arg5 - arg2;
    temp_fs0 = arg6 - arg3;
    D_uvterra_rom_0040F768->func_uvintersect_rom_00401A2C(&arg1, &arg2, &arg4, &arg5, uvtr->unk0.unk0,
                                                          uvtr->unk0.unkC, uvtr->unk0.unk4,
                                                          uvtr->unk0.unk10);
    if (arg1 == uvtr->unk0.unkC) {
        arg1 -= 0.0001f * sp178;
    }
    if (arg4 == uvtr->unk0.unkC) {
        arg4 -= 0.0001f * sp178;
    }
    if (arg2 == uvtr->unk0.unk10) {
        arg2 -= 0.0001f * sp174;
    }
    if (arg5 == uvtr->unk0.unk10) {
        arg5 -= 0.0001f * sp174;
    }

    if ((sp14C != arg1) && (temp_fs2 != 0.0f)) {
        arg3 += temp_fs0 * ((arg1 - sp14C) / temp_fs2);
    } else if ((sp148 != arg2) && (temp_fs3 != 0.0f)) {
        arg3 += temp_fs0 * ((arg2 - sp148) / temp_fs3);
    }
    if ((sp144 != arg4) && (temp_fs2 != 0.0f)) {
        arg6 += temp_fs0 * ((arg4 - sp144) / temp_fs2);
    } else if ((sp140 != arg5) && (temp_fs3 != 0.0f)) {
        arg6 += temp_fs0 * ((arg5 - sp140) / temp_fs3);
    }
    temp1 = arg4 - arg1;
    temp2 = arg5 - arg2;
    temp3 = arg6 - arg3;
    if ((temp1 == 0.0f) && (temp2 == 0.0f) && (temp3 == 0.0f)) {
        *arg7 = NULL;
        *arg8 = NULL;
        return 0;
    }
    temp_s0 =
        func_uvterra_rom_0040B8C0(uvtr, arg1, arg2, arg3, &sp1C0, &sp1BC, &sp1B8, &sp1AA, &sp1A6, 0);
    temp_t3 =
        func_uvterra_rom_0040B8C0(uvtr, arg4, arg5, arg6, &sp1B4, &sp1B0, &sp1AC, &sp1A8, &sp1A4, 0);
    if ((temp_s0 == 0) && (temp_t3 == 0)) {
        *arg7 = NULL;
        *arg8 = NULL;
        return 0;
    }
    sp103 = FALSE;
    sp102 = FALSE;
    if (sp1AA == sp1A8) {
        sp103 = TRUE;
        if (sp1A6 == sp1A4) {
            sp102 = TRUE;
        }
    }
    if (sp103) {
        var_v1 = var_v0 = (s32) ((arg1 - uvtr->unk0.unk0) / sp178);
        sp190 = sp18C = (s32) ((arg2 - uvtr->unk0.unk4) / sp174);
    } else {
        if (arg4 < arg1) {
            var_ft4 = arg4;
            var_ft5 = arg1;
        } else {
            var_ft4 = arg1;
            var_ft5 = arg4;
        }
        if (arg5 < arg2) {
            var_fa0 = arg5;
            var_fa1 = arg2;
        } else {
            var_fa1 = arg5;
            var_fa0 = arg2;
        }

        var_v1 = (s32) ((var_ft4 - uvtr->unk0.unk0) / sp178);
        var_v0 = (s32) ((var_ft5 - uvtr->unk0.unk0) / sp178);
        sp190 = (s32) ((var_fa0 - uvtr->unk0.unk4) / sp174);
        sp18C = (s32) ((var_fa1 - uvtr->unk0.unk4) / sp174);
        if (var_v1 < 0) {
            var_v1 = 0;
        }

        if (var_v0 >= uvtr->unk18) {
            var_v0 = uvtr->unk18 - 1;
        }
        if (sp190 < 0) {
            sp190 = 0;
        }

        if (sp18C >= uvtr->unk19) {
            sp18C = uvtr->unk19 - 1;
        }
    }

    if (arg3 < arg6) {
        sp11C = arg3;
    } else {
        sp11C = arg6;
    }

    for (i = var_v1; i <= var_v0; i++) {
        for (j = sp190; j <= sp18C; j++) {
            temp_s5 = (uvtr->unk18 * j) + i;
            temp_s1 = &uvtr->unk28[temp_s5];
            if (temp_s1 == NULL) {
                continue;
            }
            if (temp_s1->unk48 < sp11C) {
                continue;
            }
            uvct = temp_s1->unk40;
            if (uvct != NULL) {
                sp15C = arg1;
                sp154 = arg2;
                sp158 = arg4;
                sp150 = arg5;
                sp13C = arg3 - temp_s1->unk0.m[3][2];
                sp138 = arg6 - temp_s1->unk0.m[3][2];

                sp16C = temp_s1->unk0.m[3][0] - (0.5f * sp178);
                sp168 = temp_s1->unk0.m[3][0] + (0.5f * sp178);
                sp160 = temp_s1->unk0.m[3][1] + (0.5f * sp174);
                sp164 = temp_s1->unk0.m[3][1] - (0.5f * sp174);
                if (D_uvterra_rom_0040F768->func_uvintersect_rom_0040191C(arg1, arg2, arg4, arg5, sp16C,
                                                                          sp168, sp164, sp160)
                    == 0) {
                    continue;
                }
                if (!sp103) {
                    D_uvterra_rom_0040F768->func_uvintersect_rom_00401CB0(
                        &sp15C, &sp154, &sp13C, &sp158, &sp150, &sp138, sp16C, sp168, sp164, sp160);
                    if ((sp15C == sp158) && (sp154 == sp150) && (sp13C == sp138)) {
                        continue;
                    }
                    var_s0 = 0;
                    if (sp15C == sp168) {
                        var_s0 |= 1;
                    }
                    if (sp154 == sp160) {
                        var_s0 |= 2;
                    }
                    func_uvterra_rom_0040B8C0(uvtr, sp15C, sp154, sp13C, &sp1C0, &sp1BC, &sp1B8, &sp1AA,
                                              &sp1A6, var_s0);
                    var_s0 = 0;
                    if (sp158 == sp168) {
                        var_s0 |= 1;
                    }
                    if (sp150 == sp160) {
                        var_s0 |= 2;
                    }
                    func_uvterra_rom_0040B8C0(uvtr, sp158, sp150, sp138, &sp1B4, &sp1B0, &sp1AC, &sp1A8,
                                              &sp1A4, var_s0);
                    if (sp1A6 != sp1A4) {
                        sp1A4 =
                            func_uvterra_rom_0040BD38(sp15C, sp154, sp158, sp150, sp1C0, sp1BC, sp1B4,
                                                      sp1B0, sp16C, sp168, sp160, sp164, temp_s1);
                    }
                }

                if (!sp102) {
                    sp1A4 = func_uvterra_rom_0040BD38(sp15C, sp154, sp158, sp150, sp1C0, sp1BC, sp1B4,
                                                      sp1B0, sp16C, sp168, sp160, sp164, temp_s1);
                }
                if (sp1A4 == 0) {
                    continue;
                }

                sp1C0 *= uvct->unk2C;
                sp1B4 *= uvct->unk2C;
                sp1BC *= uvct->unk2C;
                sp1B0 *= uvct->unk2C;
                sp1B8 *= uvct->unk30;
                sp1AC *= uvct->unk30;
                for (k = 0; k < uvct->unkC; k++) {
                    temp_s1_2 = &uvct->unk8[k];
                    if (!(temp_s1_2->unk1E & sp1A4)) {
                        continue;
                    }

                    if (temp_s1_2->unk34 + temp_s1->unk0.m[3][2] < sp11C) {
                        continue;
                    }

                    for (l = 0; l < temp_s1_2->unk1C; l++) {
                        temp_v0_2 = &temp_s1_2->unk18[l];
                        if (!(temp_v0_2->unk6 & sp1A4)) {
                            continue;
                        }

                        vtx1 = &uvct->vtxTable[temp_v0_2->unk0];
                        vtx2 = &uvct->vtxTable[temp_v0_2->unk2];
                        vtx3 = &uvct->vtxTable[temp_v0_2->unk4];

                        if (MIN(MIN(vtx1->v.ob[0], vtx2->v.ob[0]), vtx3->v.ob[0]) > MAX(sp1C0, sp1B4)) {
                            continue;
                        }
                        if (MAX(MAX(vtx1->v.ob[0], vtx2->v.ob[0]), vtx3->v.ob[0]) < MIN(sp1C0, sp1B4)) {
                            continue;
                        }
                        if (MIN(MIN(vtx1->v.ob[1], vtx2->v.ob[1]), vtx3->v.ob[1]) > MAX(sp1BC, sp1B0)) {
                            continue;
                        }
                        if (MAX(MAX(vtx1->v.ob[1], vtx2->v.ob[1]), vtx3->v.ob[1]) < MIN(sp1BC, sp1B0)) {
                            continue;
                        }
                        if (MIN(MIN(vtx1->v.ob[2], vtx2->v.ob[2]), vtx3->v.ob[2]) > MAX(sp1B8, sp1AC)) {
                            continue;
                        }
                        if (MAX(MAX(vtx1->v.ob[2], vtx2->v.ob[2]), vtx3->v.ob[2]) < MIN(sp1B8, sp1AC)) {
                            continue;
                        }

                        if (D_uvterra_rom_0040F768->func_uvintersect_rom_00401318(
                                sp1C0, sp1BC, sp1B8, sp1B4, sp1B0, sp1AC, vtx1->v.ob[0], vtx1->v.ob[1],
                                vtx1->v.ob[2], vtx2->v.ob[0], vtx2->v.ob[1], vtx2->v.ob[2],
                                vtx3->v.ob[0], vtx3->v.ob[1], vtx3->v.ob[2], 1.0f, 1.0f, &sp170, &sp1C4)
                            == 0) {
                            continue;
                        }
                        if (var_s0 != 0) {
                            if (temp_fs2 != 0.0f) {
                                sp170 = (((sp158 - sp15C) / temp_fs2) * sp170)
                                        + ((sp15C - sp14C) / temp_fs2);
                            } else if (temp_fs3 != 0.0f) {
                                sp170 = (((sp150 - sp154) / temp_fs3) * sp170)
                                        + ((sp154 - sp148) / temp_fs3);
                            }
                        }

                        if (sp170 < 0.0f) {
                            sp170 = 0.0f;
                        } else if (sp170 > 1.0f) {
                            sp170 = 1.0f;
                        }
                        if (var_s3 >= D_uvterra_rom_0040F76C->func_uvquery_rom_00400224()) {
                            break;
                        }
                        D_uvterra_rom_0040F784[var_s3] =
                            ((temp_s5 & 0x3FF) << 22) + ((k & 0x3FF) << 12) + (l & 0xFFF);
                        D_uvterra_rom_0040F780[var_s3] = sp170;
                        D_uvterra_rom_0040F748->uvVec3FCopy(&D_uvterra_rom_0040F788[var_s3], &sp1C4);
                        var_s3++;
                    }
                }
            }
        }
    }
    *arg7 = D_uvterra_rom_0040F784;
    *arg8 = D_uvterra_rom_0040F780;
    return var_s3;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_00402244.s")
#endif

void func_uvterra_rom_00403270(s32 arg0, u32 arg1, s8 *arg2, s8 *arg3, s8 *arg4) {
    ParsedUVCT *temp_a0;
    ParsedUVTR *uvtr;
    Unk80225FBC_0x28 *a1;
    Unk80225FBC_0x28_UnkC *temp_v0_2;
    Vtx *vtx;
    uvUnkTileStruct *temp_v1;

    if (arg1 == -1U) {
        return;
    }

    uvtr = uvGetLoadedFile('UVTR', arg0);
    if (uvtr == NULL) {
        return;
    }

    temp_v1 = &uvtr->unk28[(arg1 >> 0x16) & 0x3FF];
    if (temp_v1 == NULL) {
        return;
    }

    temp_a0 = temp_v1->unk40;
    if (temp_a0 == NULL) {
        return;
    }

    a1 = &temp_a0->unk8[(arg1 >> 0xC) & 0x3FF];
    temp_v0_2 = &a1->unk18[arg1 & 0xFFF];
    vtx = temp_a0->vtxTable;
    *arg2 = (vtx[temp_v0_2->unk0].v.cn[0] + vtx[temp_v0_2->unk2].v.cn[0] + vtx[temp_v0_2->unk4].v.cn[0])
            / 3;
    *arg3 = (vtx[temp_v0_2->unk0].v.cn[1] + vtx[temp_v0_2->unk2].v.cn[1] + vtx[temp_v0_2->unk4].v.cn[1])
            / 3;
    *arg4 = (vtx[temp_v0_2->unk0].v.cn[2] + vtx[temp_v0_2->unk2].v.cn[2] + vtx[temp_v0_2->unk4].v.cn[2])
            / 3;
}

void func_uvterra_rom_00403464(s32 arg0, u32 arg1, Vec3F *arg2, Vec3F *arg3, Vec3F *arg4) {
    ParsedUVCT *temp_a1;
    ParsedUVTR *temp_v0;
    Unk80225FBC_0x28_UnkC *temp_v1;
    uvUnkTileStruct *a2;
    Unk80225FBC_0x28 *a3;
    Vtx *temp_a0;
    Unk80225FBC_0x28_UnkC *tmp;

    if (arg1 == -1U) {
        return;
    }

    temp_v0 = uvGetLoadedFile('UVTR', arg0);
    if (temp_v0 == NULL) {
        return;
    }

    a2 = &temp_v0->unk28[(arg1 >> 0x16) & 0x3FF];
    temp_a1 = a2->unk40;
    a3 = &temp_a1->unk8[(arg1 >> 0xC) & 0x3FF];
    temp_v1 = &a3->unk18[arg1 & 0xFFF];
    temp_a0 = temp_a1->vtxTable;
    arg2->x = temp_a0[temp_v1->unk0].v.ob[0];
    arg2->y = temp_a0[temp_v1->unk0].v.ob[1];
    tmp = temp_v1;
    arg2->z = temp_a0[tmp->unk0].v.ob[2];
    arg3->x = temp_a0[tmp->unk2].v.ob[0];
    arg3->y = temp_a0[tmp->unk2].v.ob[1];
    arg3->z = temp_a0[tmp->unk2].v.ob[2];
    arg4->x = temp_a0[tmp->unk4].v.ob[0];
    arg4->y = temp_a0[tmp->unk4].v.ob[1];
    arg4->z = temp_a0[tmp->unk4].v.ob[2];
}

s32 func_uvterra_rom_00403630(s32 arg0, f32 arg1, f32 arg2, f32 *arg3, f32 *arg4) {
    ParsedUVTR *temp_v0;
    s32 temp_a2;
    s32 temp_lo;
    s32 temp_lo_2;

    *arg3 = arg1;
    *arg4 = arg2;
    temp_v0 = uvGetLoadedFile('UVTR', arg0);
    if (temp_v0 == NULL) {
        return 0;
    }
    temp_lo = (s32) (arg1 - temp_v0->unk0.unk0) / (s32) temp_v0->unk1C;
    temp_lo_2 = (s32) (arg2 - temp_v0->unk0.unk4) / (s32) temp_v0->unk20;
    if ((temp_lo >= (s32) temp_v0->unk18) || (temp_lo < 0) || (temp_lo_2 >= (s32) temp_v0->unk19)
        || (temp_lo_2 < 0)) {
        *arg3 = arg1;
        *arg4 = arg2;
        return 0;
    }
    temp_a2 = (temp_v0->unk18 * temp_lo_2) + temp_lo;
    *arg3 = temp_v0->unk28[temp_a2].unk0.m[3][0];
    *arg4 = temp_v0->unk28[temp_a2].unk0.m[3][1];
    return 1;
}

s32 func_uvterra_rom_004037B8(s32 arg0, u32 arg1, f32 *arg2, f32 *arg3) {
    ParsedUVTR *uvtr;

    *arg2 = 0.0f;
    *arg3 = 0.0f;
    uvtr = uvGetLoadedFile('UVTR', arg0);
    if (uvtr == NULL) {
        return FALSE;
    }
    *arg2 = uvtr->unk28[(arg1 >> 0x16) & 0x3FF].unk0.m[3][0];
    *arg3 = uvtr->unk28[(arg1 >> 0x16) & 0x3FF].unk0.m[3][1];
    return TRUE;
}

#ifdef NEEDS_RODATA
// uvSobjGetSeg
s32 func_uvterra_rom_0040385C(s32 terraId, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
                              f32 arg7, s32 **arg8, f32 **arg9, Vec3F **arg10, s32 **arg11) {
    ParsedUVTR *uvtr;
    uvUnkTileStruct *temp_s1;
    ParsedUVCT *uvct;
    Unk80225FBC_0x28 *temp_s1_2;
    Unk80225FBC_0x28_UnkC *temp_v0_2;
    struct UnkSobjDraw *sobj;
    Vtx *vtx1;
    Vtx *vtx2;
    Vtx *vtx3;
    f32 temp_fs0;
    Vec3F sp1D4;
    f32 sp1D0;
    f32 sp1CC;
    f32 sp1C8;
    f32 sp1C4;
    f32 sp1C0;
    f32 sp1BC;
    u16 sp1BA;
    u16 sp1B8;
    u16 sp1B6;
    u16 sp1B4;
    u16 var_s0;
    f32 var_fa0;
    f32 var_fa1;
    s32 sp1A4;
    s32 sp1A0;
    f32 var_ft4;
    f32 var_ft5;
    f32 temp_fv0;
    s32 var_v0;
    f32 sp18C;
    f32 sp188;
    f32 sp184;
    f32 sp180;
    f32 sp17C;
    f32 sp178;
    f32 sp174;
    f32 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp164;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp14C;
    s32 var_v1;
    f32 temp1;
    f32 temp2;
    f32 temp3;
    f32 temp_fs2;
    f32 temp_fs3;
    f32 sp130;
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    f32 temp_fv1;
    s32 sp118;
    s32 temp_t0;
    ParsedUVMD *temp_v0_4;
    u8 sp10F;
    u8 sp10E;
    u8 temp_s0;
    u8 temp_t3;
    f32 ft4;
    f32 ft5;
    f32 fs2;
    f32 fv1;

    PRINTF("sobjgetseg\n");

    *D_uvterra_rom_0040F790 = 0;
    if ((arg2 == arg5) && (arg3 == arg6) && (arg4 == arg7)) {
        if (arg1 & 2) {
            if (arg7 != 0.0f) {
                arg7 *= 1.0001f;
            } else {
                arg7 += 0.0001f;
            }
        } else {
            return 0;
        }
    }
    uvtr = uvGetLoadedFile('UVTR', terraId);

    sp18C = uvtr->unk1C;
    sp188 = uvtr->unk20;
    sp160 = arg2;
    sp15C = arg3;
    sp158 = arg5;
    sp154 = arg6;
    temp_fs2 = arg5 - arg2;
    temp_fs3 = arg6 - arg3;
    temp_fs0 = arg7 - arg4;
    D_uvterra_rom_0040F768->func_uvintersect_rom_00401A2C(&arg2, &arg3, &arg5, &arg6, uvtr->unk0.unk0,
                                                          uvtr->unk0.unkC, uvtr->unk0.unk4,
                                                          uvtr->unk0.unk10);
    if (arg2 == uvtr->unk0.unkC) {
        arg2 -= 0.0001f * sp18C;
    }
    if (arg5 == uvtr->unk0.unkC) {
        arg5 -= 0.0001f * sp18C;
    }
    if (arg3 == uvtr->unk0.unk10) {
        arg3 -= 0.0001f * sp188;
    }
    if (arg6 == uvtr->unk0.unk10) {
        arg6 -= 0.0001f * sp188;
    }

    if ((sp160 != arg2) && (temp_fs2 != 0.0f)) {
        arg4 += temp_fs0 * ((arg2 - sp160) / temp_fs2);
    } else if ((sp15C != arg3) && (temp_fs3 != 0.0f)) {
        arg4 += temp_fs0 * ((arg3 - sp15C) / temp_fs3);
    }
    if ((sp158 != arg5) && (temp_fs2 != 0.0f)) {
        arg7 += temp_fs0 * ((arg5 - sp158) / temp_fs2);
    } else if ((sp154 != arg6) && (temp_fs3 != 0.0f)) {
        arg7 += temp_fs0 * ((arg6 - sp154) / temp_fs3);
    }
    temp1 = arg5 - arg2;
    temp2 = arg6 - arg3;
    temp3 = arg7 - arg4;
    if ((temp1 == 0.0f) && (temp2 == 0.0f) && (temp3 == 0.0f)) {
        if (arg1 & 2) {
            i = func_uvterra_rom_0040888C(terraId, arg2, arg3, arg4);
            if (i == -1) {
                return 0;
            }
            *D_uvterra_rom_0040F784 = i;
            *D_uvterra_rom_0040F780 = 0.0f;
            *D_uvterra_rom_0040F794 |= 2;
            *D_uvterra_rom_0040F794 &= ~4;
            D_uvterra_rom_0040F788->x = 0.0f;
            D_uvterra_rom_0040F788->y = 0.0f;
            D_uvterra_rom_0040F788->z = 1.0f;
            *arg8 = D_uvterra_rom_0040F784;
            *arg9 = D_uvterra_rom_0040F780;
            *arg10 = D_uvterra_rom_0040F788;
            *arg11 = D_uvterra_rom_0040F794;
            return 1;
        }
        return 0;
    }
    temp_s0 =
        func_uvterra_rom_0040B8C0(uvtr, arg2, arg3, arg4, &sp1D0, &sp1CC, &sp1C8, &sp1BA, &sp1B6, 0);
    temp_t3 =
        func_uvterra_rom_0040B8C0(uvtr, arg5, arg6, arg7, &sp1C4, &sp1C0, &sp1BC, &sp1B8, &sp1B4, 0);
    if ((temp_s0 == 0) && (temp_t3 == 0)) {
        return 0;
    }
    if (sp1BA == sp1B8) {
        sp10F = TRUE;
        if (sp1B6 == sp1B4) {
            sp10E = TRUE;
        } else {
            sp10E = FALSE;
        }
    } else {
        sp10F = FALSE;
        sp10E = FALSE;
    }
    if (sp10F) {
        var_v1 = var_v0 = (s32) ((arg2 - uvtr->unk0.unk0) / sp18C);
        sp1A4 = sp1A0 = (s32) ((arg3 - uvtr->unk0.unk4) / sp188);
    } else {
        if (arg5 < arg2) {
            var_ft4 = arg5;
            var_ft5 = arg2;
        } else {
            var_ft4 = arg2;
            var_ft5 = arg5;
        }
        if (arg6 < arg3) {
            var_fa0 = arg6;
            var_fa1 = arg3;
        } else {
            var_fa1 = arg6;
            var_fa0 = arg3;
        }

        var_v1 = (s32) ((var_ft4 - uvtr->unk0.unk0) / sp18C);
        var_v0 = (s32) ((var_ft5 - uvtr->unk0.unk0) / sp18C);
        sp1A4 = (s32) ((var_fa0 - uvtr->unk0.unk4) / sp188);
        sp1A0 = (s32) ((var_fa1 - uvtr->unk0.unk4) / sp188);
        if (var_v1 < 0) {
            var_v1 = 0;
        }

        if (var_v0 >= uvtr->unk18) {
            var_v0 = uvtr->unk18 - 1;
        }
        if (sp1A4 < 0) {
            sp1A4 = 0;
        }

        if (sp1A0 >= uvtr->unk19) {
            sp1A0 = uvtr->unk19 - 1;
        }
    }

    if (arg4 < arg7) {
        sp130 = arg4;
    } else {
        sp130 = arg7;
    }

    for (i = var_v1; i <= var_v0; i++) {
        for (j = sp1A4; j <= sp1A0; j++) {
            sp118 = (uvtr->unk18 * j) + i;
            temp_s1 = &uvtr->unk28[sp118];
            if (temp_s1 == NULL) {
                continue;
            }
            if (temp_s1->unk48 < sp130) {
                continue;
            }
            uvct = temp_s1->unk40;
            if (uvct == NULL) {
                continue;
            }
            sp170 = arg2;
            sp168 = arg3;
            sp16C = arg5;
            sp164 = arg6;
            sp150 = arg4 - temp_s1->unk0.m[3][2];
            sp14C = arg7 - temp_s1->unk0.m[3][2];

            sp180 = temp_s1->unk0.m[3][0] - (0.5f * sp18C);
            sp17C = temp_s1->unk0.m[3][0] + (0.5f * sp18C);
            sp174 = temp_s1->unk0.m[3][1] + (0.5f * sp188);
            sp178 = temp_s1->unk0.m[3][1] - (0.5f * sp188);
            if (D_uvterra_rom_0040F768->func_uvintersect_rom_0040191C(arg2, arg3, arg5, arg6, sp180,
                                                                      sp17C, sp178, sp174)
                == 0) {
                continue;
            }
            if (!sp10F) {
                D_uvterra_rom_0040F768->func_uvintersect_rom_00401CB0(
                    &sp170, &sp168, &sp150, &sp16C, &sp164, &sp14C, sp180, sp17C, sp178, sp174);
                if ((sp170 == sp16C) && (sp168 == sp164) && (sp150 == sp14C)) {
                    continue;
                }
                var_s0 = 0;
                if (sp170 == sp17C) {
                    var_s0 |= 1;
                }
                if (sp168 == sp174) {
                    var_s0 |= 2;
                }
                func_uvterra_rom_0040B8C0(uvtr, sp170, sp168, sp150, &sp1D0, &sp1CC, &sp1C8, &sp1BA,
                                          &sp1B6, var_s0);
                var_s0 = 0;
                if (sp16C == sp17C) {
                    var_s0 |= 1;
                }
                if (sp164 == sp174) {
                    var_s0 |= 2;
                }
                func_uvterra_rom_0040B8C0(uvtr, sp16C, sp164, sp14C, &sp1C4, &sp1C0, &sp1BC, &sp1B8,
                                          &sp1B4, var_s0);
                if (sp1B6 != sp1B4) {
                    sp1B4 = func_uvterra_rom_0040BD38(sp170, sp168, sp16C, sp164, sp1D0, sp1CC, sp1C4,
                                                      sp1C0, sp180, sp17C, sp174, sp178, temp_s1);
                }
            }

            if (!sp10E) {
                sp1B4 = func_uvterra_rom_0040BD38(sp170, sp168, sp16C, sp164, sp1D0, sp1CC, sp1C4,
                                                  sp1C0, sp180, sp17C, sp174, sp178, temp_s1);
            }
            if (sp1B4 == 0) {
                continue;
            }

            sp1D0 *= uvct->unk2C;
            sp1C4 *= uvct->unk2C;
            sp1CC *= uvct->unk2C;
            sp1C0 *= uvct->unk2C;
            sp1C8 *= uvct->unk30;
            sp1BC *= uvct->unk30;

            if (arg1 & 2) {
                for (temp_t0 = 0; temp_t0 < temp_s1->unk40->unk14; temp_t0++) {
                    sobj = &temp_s1->unk40->unk10[temp_t0];
                    if (!(sp1B4 & sobj->unk18)) {
                        continue;
                    }
                    if ((sobj->unk3C + temp_s1->unk0.m[3][2]) < sp130) {
                        continue;
                    }

                    ft4 = sobj->unk8;
                    ft5 = sobj->unkC;
                    fs2 = sobj->unk10;
                    fv1 = sobj->unk14;

                    if (fv1 + ft4 < MIN(sp1D0, sp1C4)) {
                        continue;
                    }
                    if (fv1 - ft4 > MAX(sp1D0, sp1C4)) {
                        continue;
                    }
                    if (fv1 + ft5 < MIN(sp1CC, sp1C0)) {
                        continue;
                    }
                    if (fv1 - ft5 > MAX(sp1CC, sp1C0)) {
                        continue;
                    }
                    if (fv1 + fs2 < MIN(sp1C8, sp1BC)) {
                        continue;
                    }
                    if (fv1 - fs2 > MAX(sp1C8, sp1BC)) {
                        continue;
                    }

                    if (D_uvterra_rom_0040F768->func_uvintersect_rom_00400144(
                            sp1D0, sp1CC, sp1C8, sp1C4, sp1C0, sp1BC, ft4, ft5, fs2, fv1, &sp184)
                        != 0) {
                        temp_v0_4 = uvGetLoadedFile('UVMD', sobj->modelId);
                        if (temp_v0_4 == NULL) {
                            continue;
                        }
                        *D_uvterra_rom_0040F78C = (temp_s1->unk44 << 0xC) | temp_t0;
                        if (!(temp_v0_4->unk5 & 6)) {
                            if (*D_uvterra_rom_0040F790
                                >= D_uvterra_rom_0040F76C->func_uvquery_rom_00400224()) {
                                break;
                            }
                            D_uvterra_rom_0040F784[*D_uvterra_rom_0040F790] = *D_uvterra_rom_0040F78C;
                            D_uvterra_rom_0040F780[*D_uvterra_rom_0040F790] = sp184;
                            D_uvterra_rom_0040F768->func_uvintersect_rom_00400700(
                                arg2, arg3, arg4, arg5, arg6, arg7, sp184,
                                temp_s1->unk0.m[3][0] + sobj->unk8, temp_s1->unk0.m[3][1] + sobj->unkC,
                                temp_s1->unk0.m[3][2] + sobj->unk10,
                                &D_uvterra_rom_0040F788[*D_uvterra_rom_0040F790]);
                            *D_uvterra_rom_0040F790 += 1;
                        } else {
                            func_uvterra_rom_0040A79C(sp1D0, sp1CC, sp1C8, sp1C4, sp1C0, sp1BC, sobj);
                        }
                    }
                }
            }
            for (temp_t0 = 0; temp_t0 < *D_uvterra_rom_0040F790; temp_t0++) {
                D_uvterra_rom_0040F794[temp_t0] |= 2;
                D_uvterra_rom_0040F794[temp_t0] &= ~4;
            }
            if (arg1 & 4) {
                for (k = 0; k < uvct->unkC; k++) {
                    temp_s1_2 = &uvct->unk8[k];
                    if (!(temp_s1_2->unk1E & sp1B4)) {
                        continue;
                    }

                    if (temp_s1_2->unk34 + temp_s1->unk0.m[3][2] < sp130) {
                        continue;
                    }

                    for (l = 0; l < temp_s1_2->unk1C; l++) {
                        temp_v0_2 = &temp_s1_2->unk18[l];
                        if (!(temp_v0_2->unk6 & sp1B4)) {
                            continue;
                        }

                        vtx1 = &uvct->vtxTable[temp_v0_2->unk0];
                        vtx2 = &uvct->vtxTable[temp_v0_2->unk2];
                        vtx3 = &uvct->vtxTable[temp_v0_2->unk4];

                        if (MIN(MIN(vtx1->v.ob[0], vtx2->v.ob[0]), vtx3->v.ob[0]) > MAX(sp1D0, sp1C4)) {
                            continue;
                        }
                        if (MAX(MAX(vtx1->v.ob[0], vtx2->v.ob[0]), vtx3->v.ob[0]) < MIN(sp1D0, sp1C4)) {
                            continue;
                        }
                        if (MIN(MIN(vtx1->v.ob[1], vtx2->v.ob[1]), vtx3->v.ob[1]) > MAX(sp1CC, sp1C0)) {
                            continue;
                        }
                        if (MAX(MAX(vtx1->v.ob[1], vtx2->v.ob[1]), vtx3->v.ob[1]) < MIN(sp1CC, sp1C0)) {
                            continue;
                        }
                        if (MIN(MIN(vtx1->v.ob[2], vtx2->v.ob[2]), vtx3->v.ob[2]) > MAX(sp1C8, sp1BC)) {
                            continue;
                        }
                        if (MAX(MAX(vtx1->v.ob[2], vtx2->v.ob[2]), vtx3->v.ob[2]) < MIN(sp1C8, sp1BC)) {
                            continue;
                        }

                        if (D_uvterra_rom_0040F768->func_uvintersect_rom_00401318(
                                sp1D0, sp1CC, sp1C8, sp1C4, sp1C0, sp1BC, vtx1->v.ob[0], vtx1->v.ob[1],
                                vtx1->v.ob[2], vtx2->v.ob[0], vtx2->v.ob[1], vtx2->v.ob[2],
                                vtx3->v.ob[0], vtx3->v.ob[1], vtx3->v.ob[2], 1.0f, 1.0f, &sp184, &sp1D4)
                            == 0) {
                            continue;
                        }
                        if (var_s0 != 0) {
                            if (temp_fs2 != 0.0f) {
                                sp184 = (((sp16C - sp170) / temp_fs2) * sp184)
                                        + ((sp170 - sp160) / temp_fs2);
                            } else if (temp_fs3 != 0.0f) {
                                sp184 = (((sp164 - sp168) / temp_fs3) * sp184)
                                        + ((sp168 - sp15C) / temp_fs3);
                            }
                        }

                        if (sp184 < 0.0f) {
                            sp184 = 0.0f;
                        } else if (sp184 > 1.0f) {
                            sp184 = 1.0f;
                        }
                        if (*D_uvterra_rom_0040F790
                            >= D_uvterra_rom_0040F76C->func_uvquery_rom_00400224()) {
                            break;
                        }
                        temp_t0 = *D_uvterra_rom_0040F790;
                        D_uvterra_rom_0040F784[temp_t0] =
                            ((sp118 & 0x3FF) << 22) + ((k & 0x3FF) << 12) + (l & 0xFFF);
                        D_uvterra_rom_0040F780[temp_t0] = sp184;
                        D_uvterra_rom_0040F794[temp_t0] |= 4;
                        D_uvterra_rom_0040F794[temp_t0] &= ~2;
                        D_uvterra_rom_0040F748->uvVec3FCopy(&D_uvterra_rom_0040F788[temp_t0], &sp1D4);
                        (*D_uvterra_rom_0040F790)++;
                    }
                }
            }
        }
    }
    if (*D_uvterra_rom_0040F790 != 0) {
        *arg8 = D_uvterra_rom_0040F784;
        *arg9 = D_uvterra_rom_0040F780;
        *arg11 = D_uvterra_rom_0040F794;
        *arg10 = D_uvterra_rom_0040F788;
    }

    return *D_uvterra_rom_0040F790;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_0040385C.s")
#endif

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_00404E14.s")

s32 func_uvterra_rom_004060A4(s32 arg0, u32 arg1) {
    ParsedUVCT* temp_a1;
    ParsedUVTR* temp_v0;
    uvUnkTileStruct* temp_v1;
    Unk80225FBC_0x28* var_v1;
    s32 ret;

    if (arg1 == -1U) {
        return 0xFFF;
    }
    temp_v0 = uvGetLoadedFile('UVTR', arg0);
    if (temp_v0 == NULL) {
        return 0xFFF;
    }
    temp_v1 = &temp_v0->unk28[(arg1 >> 0x16) & 0x3FF];
    if (temp_v1 == NULL) {
        return 0xFFF;
    }
    temp_a1 = temp_v1->unk40;
    if (temp_a1 == NULL) {
        return 0xFFF;
    }
    var_v1 = &temp_a1->unk8[(arg1 >> 0xC) & 0x3FF];
    ret = var_v1->texture & 0xFFF;
    return ret;
}

s32 func_uvterra_rom_00406160(s32 terraId, s32 texture, s32 **arg2) {
    ParsedUVTR *uvtr;
    s32 temp_lo;
    s32 k;
    s32 i;
    s32 j;
    s32 var_t4;
    s32 *temp_s2;
    s32 temp_t0;
    u16 temp_t5;
    ParsedUVCT *uvct;
    Unk80225FBC_0x28 *temp_a0_2;
    s32 var_a3;
    uvUnkTileStruct *temp_ra;
    
    temp_s2 = D_uvterra_rom_0040F784;
    var_a3 = 0;
    uvtr = uvGetLoadedFile('UVTR', terraId);
    if (uvtr == NULL) {
        *arg2 = NULL;
        return 0;
    }
    temp_lo = uvtr->unk18 * uvtr->unk19;
    for (i = 0; i < temp_lo; i++) {
        temp_ra = &uvtr->unk28[i];
        if (temp_ra == NULL) {
            continue;
        }
        uvct = temp_ra->unk40;
        if (uvct == NULL) {
            continue;
        }

        j = 0;
        temp_t5 = uvct->unkC;
        if (temp_t5 > 0) {
            do {
                temp_a0_2 = &temp_ra->unk40->unk8[j];
                temp_t0 = temp_a0_2->unk1C;
                if (temp_t0 == 0) {
                    continue;
                }
                var_t4 = (temp_a0_2->texture & 0xFFF);
                if (var_t4 != texture) {
                    continue;
                }
                var_t4 = ((u16)i << 22);
                for (k = 0; k < temp_t0; k++) {
                    temp_s2[var_a3++] = (u32)var_t4 + ((j & 0x3FF) << 0xC) + (k & 0xFFF);
                }
            } while (++j != temp_t5);
        }
    }
    *arg2 = temp_s2;
    return var_a3;
}


#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_00406324.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_00406648.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_00406C60.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_004071A4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_004072BC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_004072C8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_004072D4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_004072E0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_004072EC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_004074EC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_00407680.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_004076A8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_00407A80.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_00407A94.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_00407B0C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_00407E5C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_00407ED4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_00408300.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_00408534.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_00408614.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_004087D8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_0040880C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_0040888C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_00408AD8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_00409394.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_0040A08C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_0040A43C.s")

s32 func_uvterra_rom_0040A79C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5,
                              UnkSobjDraw *sobj) {
    s16 modelLodCount;
    ParsedUVMD_1 *temp_fp;
    f32 temp_fs1;
    f32 temp_fs0;
    ParsedUVMD *uvmd;
    s16 temp_s1;
    s16 j;
    Mtx4F spC0;
    s16 count;
    s16 i;
    s32 var_s0;
    uvModelLOD *modelLod;

    uvmd = uvGetLoadedFile('UVMD', (s32) sobj->modelId);
    temp_fp = uvmd->unk0;
    modelLodCount = temp_fp->unk8;
    D_uvterra_rom_0040F758->uvModelMtxStackReset();
    count = 0;
    for (i = 0; i < modelLodCount; i++) {
        modelLod = &temp_fp->unk0[i];
        if ((sobj->unk1C & (1 << i)) || (((modelLod->unk7 & 1)))) {
            var_s0 = FALSE;
        } else {
            var_s0 = TRUE;
        }

        if ((!var_s0) && (modelLod->unk7 & 2)) {
            continue;
        }

        D_uvterra_rom_0040F744->uvMat4CopyL2F(&spC0, sobj->unk4[i]);
        if (i == 0) {
            temp_fs0 = 1.0f / sobj->unk30;
            temp_fs1 = 1.0f / sobj->unk34;
            D_uvterra_rom_0040F744->uvMat4Scale(&spC0, temp_fs0, temp_fs0, temp_fs1);
            spC0.m[3][0] *= temp_fs0;
            spC0.m[3][1] *= temp_fs0;
            spC0.m[3][2] *= temp_fs1;
        }
        D_uvterra_rom_0040F758->uvModelMtxStackPush(&spC0);
        count++;
        if (var_s0 != 0) {
            *D_uvterra_rom_0040F78C = (*D_uvterra_rom_0040F78C & 0xFFFFFF) | (i << 0x18);
            D_uvterra_rom_0040F758->_uvSegInMboxs(arg0, arg1, arg2, arg3, arg4, arg5,
                                                  D_uvterra_rom_0040F758->uvModelMtxStackTop(),
                                                  &temp_fp->unk0[i], uvmd);
        }
        if (i == (modelLodCount - 1)) {
            break;
        }
        temp_s1 = temp_fp->unk0[i].unk6 - temp_fp->unk0[i + 1].unk6;
        // clang-format off
        for (j = 0; j <= temp_s1; j++) { \
            D_uvterra_rom_0040F758->uvModelMtxStackPop();  \
            count--; \
        }
        // clang-format on
    }

    for (i = 0; i < count; i++) {
        D_uvterra_rom_0040F758->uvModelMtxStackPop();
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_0040AB14.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_0040ABB4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_0040ABE0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_0040AC14.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_0040AC8C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_0040AC9C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_0040AE4C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_0040AFD8.s")

u16 func_uvterra_rom_0040B0C4(s16 arg0, s16 arg1, u8 arg2) {
    s16 temp_v0;

    if (arg2) {
        temp_v0 = arg1 - arg0;
        if ((temp_v0 == 1) || (temp_v0 == 0) || ((temp_v0 == -0x3F))) {
            return 0xFFFFU;
        }
        arg0++;
        arg1--;
        if (arg0 >= 64) {
            arg0 -= 64;
        } else if (arg0 < 0) {
            arg0 += 64;
        }
        if (arg1 >= 64) {
            arg1 -= 64;
        } else if (arg1 < 0) {
            arg1 += 64;
        }
        return D_uvterra_rom_0040D718[arg0][arg1];
    }
    temp_v0 = arg1 - arg0;
    if ((temp_v0 == -1) || (temp_v0 == 0) || ((temp_v0 == 0x3F))) {
        return 0xFFFFU;
    }
    arg0--;
    arg1++;
    if (arg0 >= 64) {
        arg0 = arg0 - 64;
    } else if (arg0 < 0) {
        arg0 += 64;
    }
    if (arg1 >= 64) {
        arg1 -= 64;
    } else if (arg1 < 0) {
        arg1 += 64;
    }
    return D_uvterra_rom_0040D718[arg1][arg0];
}

#ifdef NEEDS_RODATA
void func_uvterra_rom_0040B26C(s16 *arg0, s16 *arg1, u16 *arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
                               f32 arg7, f32 arg8, f32 arg9, u8 arg10, f32 arg11, f32 arg12) {
    f32 temp_fa0;
    f32 temp_fv1;

    if (arg8 == 2.1401436e9f) {
        if (arg7 <= arg3) {
            UV_COMPUTE_LINE_MACRO(arg10, arg2, arg0);
        } else if (arg4 <= arg7) {
            UV_COMPUTE_LINE_MACRO(!arg10, arg2, arg0);
        } else {
            *arg0 = ROUNDF2((arg7 - arg3) * arg11);
            *arg1 = 47 - *arg0;
        }
    } else if (arg8 == 0.0f) {
        temp_fa0 = (arg8 * arg3) + arg7;
        if (temp_fa0 <= arg6) {
            UV_COMPUTE_LINE_MACRO(!arg10, arg2, arg0);
        } else if (arg5 <= temp_fa0) {
            UV_COMPUTE_LINE_MACRO(arg10, arg2, arg0);
        } else {
            *arg0 = ROUNDF2(63.0f - (temp_fa0 - arg6) * arg12);
            // FAKE
            if (1) {
            }
            *arg1 = ROUNDF2((temp_fa0 - arg6) * arg12 + 16.0f);
        }
    } else {
        temp_fa0 = (arg8 * arg3) + arg7;
        if (temp_fa0 < arg6) {
            temp_fv1 = (arg8 * arg4) + arg7;
            if (temp_fv1 <= arg6) {
                UV_COMPUTE_LINE_MACRO(!arg10, arg2, arg0);
            } else {
                *arg0 = ROUNDF2((arg6 - temp_fa0) * arg9 * arg11);
                if (temp_fv1 <= arg5) {
                    *arg1 = ROUNDF2((temp_fv1 - arg6) * arg12) + 16;
                } else if (arg5 < temp_fv1) {
                    *arg1 = 47 - ROUNDF2((arg5 - temp_fa0) * arg9 * arg11);
                }
            }

        } else if ((arg6 <= temp_fa0) && (temp_fa0 <= arg5)) {
            *arg0 = 63 - ROUNDF2((temp_fa0 - arg6) * arg12);
            temp_fv1 = (arg8 * arg4) + arg7;
            if (temp_fv1 < arg6) {
                *arg1 = ROUNDF2((arg6 - temp_fa0) * arg9 * arg11);
            } else if (temp_fv1 <= arg5) {
                *arg1 = ROUNDF2((temp_fv1 - arg6) * arg12) + 16;
            } else if (arg5 < temp_fv1) {
                *arg1 = 47 - ROUNDF2((arg5 - temp_fa0) * arg9 * arg11);
            }
        } else if (arg5 <= temp_fa0) {
            temp_fv1 = (arg8 * arg4) + arg7;
            if (arg5 <= temp_fv1) {
                UV_COMPUTE_LINE_MACRO(arg10, arg2, arg0);
            } else {
                *arg0 = 47 - ROUNDF2((arg5 - temp_fa0) * arg9 * arg11);
                if (arg6 <= temp_fv1) {
                    *arg1 = ROUNDF2((temp_fv1 - arg6) * arg12) + 16;
                } else if (temp_fv1 < arg6) {
                    *arg1 = ROUNDF2((arg6 - temp_fa0) * arg9 * arg11);
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_0040B26C.s")
#endif

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_0040B8C0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_0040BBC0.s")

#ifdef NEEDS_RODATA
u16 func_uvterra_rom_0040BD38(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
                              f32 arg7, f32 arg8, f32 arg9, f32 arg10, f32 arg11, void *arg12) {
    f32 sp50;
    f32 sp4C;
    f32 sp40;
    f32 sp38;
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_fv0;
    f32 var_fs0;
    f32 var_fs1;
    f32 var_fs2;
    f32 var_ft4;
    f32 var_ft5;
    s32 i;
    u16 sp5A;
    u16 sp58;
    u16 temp_v0;
    u16 temp_t4;

    sp5A = 0;
    sp58 = 0;
    sp50 = arg9 - arg8;
    sp4C = arg10 - arg11;

    if (arg4 < arg6) {
        var_ft5 = arg4;
        var_fs0 = arg6;
    } else {
        var_ft5 = arg6;
        var_fs0 = arg4;
    }

    if (arg5 < arg7) {
        var_fs1 = arg5;
        var_fs2 = arg7;
    } else {
        var_fs1 = arg7;
        var_fs2 = arg5;
    }

    temp_fa0 = 0.25f * sp50;
    var_ft4 = 2.0f * temp_fa0;
    sp38 = -temp_fa0;

    temp_fa1 = 0.25f * sp4C;
    sp40 = -temp_fa1;

    for (i = 0; (sp38 <= var_ft4) && (i < 4); i++) {
        if ((var_ft5 <= sp38) && ((sp38 - temp_fa0) <= var_fs0)) {
            sp58 |= 0x8888 >> i;
        }
        sp38 += temp_fa0;
    }
    temp_fv0 = 2.0f * temp_fa1;

    for (i = 0; (sp40 <= temp_fv0) && (i < 4); i++) {
        if ((var_fs1 <= sp40) && ((sp40 - temp_fa1) <= var_fs2)) {
            sp5A |= 0xF000 >> (i * 4);
        }
        sp40 += temp_fa1;
    }
    if (arg2 != arg0) {
        sp40 = (arg3 - arg1) / (arg2 - arg0);
        var_ft4 = arg3 - (sp40 * arg2);
    } else {
        sp40 = 2.1401436e9f;
        var_ft4 = arg2;
    }

    temp_t4 = sp5A & sp58;
    temp_v0 = func_uvterra_rom_0040BF74(sp50, sp4C, arg12, sp40, var_ft4);

    return temp_t4 & temp_v0;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_0040BD38.s")
#endif

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_0040BF74.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_0040C08C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_0040C0F8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_0040C218.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_0040C490.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_0040C50C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_0040C998.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_0040CA64.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_0040CEA8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_0040CF98.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_0040D050.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvterra_rom/func_uvterra_rom_0040D128.s")
