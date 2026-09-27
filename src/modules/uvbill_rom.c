// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "uvasset_types.h"
#include "stdarg.h"

typedef struct UnkTerraExports_s {
    /* 0x00 */ char pad0[0xAC];
    /* 0xAC */ void (*unkAC)(s32, s32, f32, f32, void (*)(s32, void *), void *, f32); /* inferred */
} UnkTerraExports;

typedef struct UnkStruct_uvbill_rom_004003B4_s {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 unk2; /* inferred */
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 unk4; /* inferred */
    /* 0x05 */ u8 unk5; /* inferred */
    /* 0x06 */ u8 unk6; /* inferred */
    /* 0x07 */ char pad7[1];
    /* 0x08 */ u16 unk8;  /* inferred */
    /* 0x0A */ u16 unkA;  /* inferred */
    /* 0x0C */ f32 unkC;  /* maybe part of unkA[3]? */
    /* 0x10 */ f32 unk10; /* inferred */
    /* 0x14 */ f32 unk14; /* inferred */
    /* 0x18 */ f32 unk18; /* inferred */
    /* 0x1C */ f32 unk1C; /* inferred */
    /* 0x20 */ f32 unk20;
    /* 0x24 */ u8 unk24; /* inferred */
    /* 0x25 */ u8 unk25; /* inferred */
    /* 0x26 */ u8 unk26; /* inferred */
    /* 0x27 */ u8 unk27; /* inferred */
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s16 unk2C; /* inferred */
    /* 0x2E */ char pad2E[2];
    /* 0x30 */ Mtx4F unk30;         /* inferred */
    /* 0x70 */ void (*unk70)(void); /* inferred */
    /* 0x74 */ void (*unk74)(void); /* inferred */
} UnkStruct_uvbill_rom_004003B4;    /* size = 0x78 */

void func_uvbill_rom_00400318(void);
void func_uvbill_rom_004003B4(s32 arg0, UnkStruct_uvbill_rom_004003B4 *arg1);
void func_uvbill_rom_00400D9C(s32 arg0);
void func_uvbill_rom_00400DEC(s32 arg0);
s32 func_uvbill_rom_004010B8(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 arg6,
                             s32 **arg7, f32 **arg8, Vec3F **arg9);
s32 func_uvbill_rom_00401388(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
s32 func_uvbill_rom_00401418(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 **arg5);
void func_uvbill_rom_0040154C(s32 arg0, Mtx4F *arg1);
void func_uvbill_rom_004015A4(s32 arg0, ...);
s32 func_uvbill_rom_00401E40(void);
void func_uvbill_rom_00401F5C(s32 arg0);
void func_uvbill_rom_004002C0(s32 arg0);
void __entrypoint_func_uvbill_rom_400000(UvBill_Exports *exports);

// .data
UnkStruct_uvbill_rom_004003B4 *D_uvbill_rom_00402000 = NULL;
s32 *D_uvbill_rom_00402004 = NULL;
Vec3F *D_uvbill_rom_00402008 = NULL;
f32 *D_uvbill_rom_0040200C = NULL;
s32 D_uvbill_rom_00402010[] = { 0x00240000, __entrypoint_func_uvbill_rom_400000, 0, 0 };

// .bss
s32 D_uvbill_rom_00402020;
static UvGfxState_Rom_Exports *sUvGfxState;
static UvFMtx_Rom_Exports *sUvFmtxExports;
static UvChannelExports *sUvChannelExports;
static UvMath_Exports *sUvMathExports;
static UvIntersect_Exports *sUvIntersectExports;
static UvDGeom_Rom_Exports *sUvDGeomExports;
static UvGfxMgr_Exports *sUvGfxMgrExports;
static UvCback_Exports *sUvCbackExports;
static UvTSeq_Exports *sUvTSeqExports;
static UnkTerraExports *sUvTerraExports; // terra exports

void __entrypoint_func_uvbill_rom_400000(UvBill_Exports *exports) {
    s32 *count;

    uvUpdateFileAllocPtr(exports);
    exports->func_uvbill_rom_00400318 = func_uvbill_rom_00400318;
    exports->func_uvbill_rom_004002C0 = func_uvbill_rom_004002C0;
    exports->func_uvbill_rom_004010B8 = func_uvbill_rom_004010B8;
    exports->func_uvbill_rom_00401388 = func_uvbill_rom_00401388;
    exports->func_uvbill_rom_00401418 = func_uvbill_rom_00401418;
    exports->func_uvbill_rom_0040154C = func_uvbill_rom_0040154C;
    exports->func_uvbill_rom_004015A4 = func_uvbill_rom_004015A4;
    exports->func_uvbill_rom_00401E40 = func_uvbill_rom_00401E40;
    exports->func_uvbill_rom_00401F5C = func_uvbill_rom_00401F5C;
    count = uvGetSystemProp(SYSTEM_PROPID_BILL_COUNT);
    if (count == NULL) {
        D_uvbill_rom_00402020 = 0x64;
    } else {
        if (*count != 0) {
            D_uvbill_rom_00402020 = *count;
        } else {
            D_uvbill_rom_00402020 = 0x64;
        }
    }
    // FAKE
    do {
    } while (0);
    D_uvbill_rom_00402000 =
        _uvMemAllocAlign8(D_uvbill_rom_00402020 * sizeof(UnkStruct_uvbill_rom_004003B4));
    D_uvbill_rom_00402004 = _uvMemAllocAlign8(D_uvbill_rom_00402020 * sizeof(s32));
    D_uvbill_rom_00402008 = _uvMemAllocAlign8(D_uvbill_rom_00402020 * sizeof(Vec3F));
    D_uvbill_rom_0040200C = _uvMemAllocAlign8(D_uvbill_rom_00402020 * sizeof(f32));

    uvMemSet(D_uvbill_rom_00402000, 0, D_uvbill_rom_00402020 * sizeof(UnkStruct_uvbill_rom_004003B4));
    uvMemSet(D_uvbill_rom_00402004, 0, D_uvbill_rom_00402020 * sizeof(s32));
    uvMemSet(D_uvbill_rom_00402008, 0, D_uvbill_rom_00402020 * sizeof(Vec3F));
    uvMemSet(D_uvbill_rom_0040200C, 0, D_uvbill_rom_00402020 * sizeof(f32));
    sUvGfxState = uvLoadModule('STAT');
    sUvChannelExports = uvLoadModule('CHAN');
    sUvFmtxExports = uvLoadModule('FMTX');
    sUvMathExports = uvLoadModule('MATH');
    sUvTSeqExports = uvLoadModule('TSEQ');
    sUvDGeomExports = uvLoadModule('DGEO');
    sUvGfxMgrExports = uvLoadModule('GMGR');
    sUvCbackExports = uvLoadModule('CBCK');
    sUvTerraExports = uvLoadModule('TERR');
    sUvCbackExports->uvAddCallback(sUvGfxMgrExports->func_uvgfxmgr_rom_00400AB8(1),
                                   func_uvbill_rom_00400D9C, 0, 0);
}

void func_uvbill_rom_004002C0(s32 arg0) {
    CallbackList *callbackList;

    sUvChannelExports->func_uvchannel_rom_00400288(arg0, 6, &callbackList, 0);
    sUvCbackExports->uvAddCallback(callbackList, func_uvbill_rom_00400DEC, 0, 0x32);
}

void func_uvbill_rom_00400318(void) {
    _uvMemFree(D_uvbill_rom_0040200C);
    _uvMemFree(D_uvbill_rom_00402008);
    _uvMemFree(D_uvbill_rom_00402004);
    _uvMemFree(D_uvbill_rom_00402000);
    uvUnloadModule('STAT');
    uvUnloadModule('CHAN');
    uvUnloadModule('FMTX');
    uvUnloadModule('MATH');
    uvUnloadModule('TSEQ');
    uvUnloadModule('DGEO');
    uvUnloadModule('CBCK');
}

void func_uvbill_rom_004003B4(s32 arg0, UnkStruct_uvbill_rom_004003B4 *arg1) {
    s32 var_a1;
    u16 spCA;
    u16 spC8;
    u16 spC6;
    u16 spC4;
    u16 spC2;
    u16 spC0;
    u16 spBE;
    u16 spBC;
    s16 pad;
    s16 spB8;
    s16 spB6;
    s32 var_v1;
    f32 temp_fv0;
    f32 spA8;
    f32 temp_fv1;
    f32 spA0;
    Mtx4F sp60;
    ParsedUVTX *var_a2;
    s32 var_v0;

    if (arg1->unk27 == 0) {
        return;
    }

    sUvGfxState->uvGfxStatePush();
    sUvGfxState->uvGfxStateSetFlags(0x04E20FFF);
    sUvGfxState->func_uvgfxstate_rom_00401354(0x99140000);
    if (arg1->unk70 != NULL) {
        arg1->unk70();
    }
    if (arg1->unk2 == 0) {
        if (arg1->unk74 != NULL) {
            arg1->unk74();
        }
        sUvGfxState->uvGfxStatePop();
        return;
    }
    if (arg1->unk8 != 0xFF) {
        var_a1 = sUvTSeqExports->func_uvtseq_rom_0040093C(arg1->unk8);
    } else {
        if (arg1->unkA != 0xFFF) {
            var_a1 = arg1->unkA;
        } else {
            var_a1 = 0xFFF;
        }
    }
    if (var_a1 != 0xFFF) {
        var_a2 = uvGetLoadedFile('UVTX', var_a1);
    } else {
        var_a2 = NULL;
    }
    if ((var_a1 != 0xFFF) && (var_a2 != NULL)) {
        sUvGfxState->uvGfxStateBindTexture(var_a1);
        if (arg1->unk10 == 0.0f) {
            spCA = 0;
            spC8 = 0;
            var_v0 = var_a2->width << 5;
            spC2 = spC6 = var_v0;
            spC4 = 0;
            var_v1 = var_a2->height << 5;
            spBC = spC0 = var_v1;
            spBE = 0;
        } else {
            spA0 = arg1->unk10 * 0.0174533f;
            spA8 = sUvMathExports->uvSinF(spA0);
            temp_fv0 = sUvMathExports->uvCosF(spA0);
            temp_fv1 = var_a2->width * 16.0f;
            spA0 = var_a2->height * 16.0f;
            spCA = ((-temp_fv1 * temp_fv0) + (spA0 * spA8) + temp_fv1);
            spC8 = (((-temp_fv1 * spA8) - (spA0 * temp_fv0)) + spA0);
            spC6 = ((temp_fv1 * temp_fv0) + (spA0 * spA8) + temp_fv1);
            spC4 = (((temp_fv1 * spA8) - (spA0 * temp_fv0)) + spA0);
            spC2 = (((temp_fv1 * temp_fv0) - (spA0 * spA8)) + temp_fv1);
            spC0 = ((temp_fv1 * spA8) + (spA0 * temp_fv0) + spA0);
            spBE = (((-temp_fv1 * temp_fv0) - (spA0 * spA8)) + temp_fv1);
            spBC = ((-temp_fv1 * spA8) + (spA0 * temp_fv0) + spA0);
        }
        if (arg1->unk5 != 0) {
            var_v0 = spCA;
            spCA = spC2;
            spC2 = var_v0;
            var_v0 = spC6;
            spC6 = spBE;
            spBE = var_v0;
        }
        if (arg1->unk6 != 0) {
            var_v0 = spC8;
            spC8 = spC0;
            spC0 = var_v0;
            var_v0 = spC4;
            spC4 = spBC;
            spBC = var_v0;
        }
    }
    if (arg1->unk27 < 0xFF) {
        sUvGfxState->uvGfxStateSetFlags(0x04800000);
    }
    sUvFmtxExports->uvMat4FCopy(&sp60, &arg1->unk30);
    sUvFmtxExports->uvMat4Scale(&sp60, arg1->unk14, arg1->unk18, arg1->unk1C);
    sUvFmtxExports->func_00402858(&sp60);
    sUvDGeomExports->uvVtxBeginPoly();
    if (arg1->unk4 != 0) {
        spB8 = -1;
        spB6 = 1;
    } else {
        spB8 = 0;
        spB6 = 2;
    }
    if (arg1->unk2C != 0) {
        sUvDGeomExports->func_uvdgeom_rom_00400424(arg1->unk2C - 1, 4);
    } else {
        arg1->unk2C = sUvDGeomExports->uvVtx(-1, 0, spB8, spCA, spC8, arg1->unk24, arg1->unk25,
                                             arg1->unk26, arg1->unk27)
                      + 1;

        sUvDGeomExports->uvVtx(1, 0, spB8, spC6, spC4, arg1->unk24, arg1->unk25, arg1->unk26,
                               arg1->unk27);
        sUvDGeomExports->uvVtx(1, 0, spB6, spC2, spC0, arg1->unk24, arg1->unk25, arg1->unk26,
                               arg1->unk27);
        sUvDGeomExports->uvVtx(-1, 0, spB6, spBE, spBC, arg1->unk24, arg1->unk25, arg1->unk26,
                               arg1->unk27);
    }
    sUvDGeomExports->uvVtxEndPoly();
    sUvFmtxExports->uvGfxMtxFViewPop();
    if (arg1->unk74 != NULL) {
        arg1->unk74();
    }
    sUvGfxState->uvGfxStatePop();
}

void func_uvbill_rom_00400D9C(s32 arg0) {
    s32 i;

    for (i = 0; i < D_uvbill_rom_00402020; i++) {
        UnkStruct_uvbill_rom_004003B4 *a0 = &D_uvbill_rom_00402000[i];
        a0->unk2C = 0;
    }
}

void func_uvbill_rom_00400DEC(s32 arg0) {
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv1;
    f32 var_fa0;
    s32 i;
    UnkStruct_uvbill_rom_004003B4 *temp_s0;
    Mtx4F sp9C;
    Vec3F sp90;

    for (i = 0; i < D_uvbill_rom_00402020; i++) {
        temp_s0 = &D_uvbill_rom_00402000[i];
        if (temp_s0->unk3 == 0) {
            continue;
        }
        sUvChannelExports->func_uvchannel_rom_00400288(arg0, 7, &sp90, 3, &sp9C, 0);
        temp_fs1 = temp_s0->unk30.m[3][0] - sp90.x;
        temp_fs2 = temp_s0->unk30.m[3][1] - sp90.y;
        temp_fs0 = temp_s0->unk30.m[3][2] - sp90.z;
        temp_fv0 = sUvMathExports->uvSqrtf(SQ(temp_fs1) + SQ(temp_fs2) + SQ(temp_fs0));
        if (temp_s0->unk20 < temp_fv0) {
            continue;
        } else if (sUvChannelExports->func_uvchannel_rom_004014E8(arg0, temp_fs1, temp_fs2, temp_fs0,
                                                                  temp_s0->unkC)
                   == 0) {
            continue;
        }

        if (temp_s0->unk0 == 3) {
            sUvFmtxExports->func_00400588(&temp_s0->unk30, &sp9C);
        } else if (temp_s0->unk0 == 2) {
            temp_fv0_2 = sUvMathExports->uvSqrtf(SQ(temp_fs1) + SQ(temp_fs2));
            if (temp_fv0_2 != 0.0f) {
                var_fa0 = 1.0f / temp_fv0_2;
            } else {
                var_fa0 = 1.0f;
            }
            temp_fv0_2 = temp_fs1 * var_fa0;
            temp_fv1 = temp_fs2 * var_fa0;
            temp_s0->unk30.m[0][2] = 0.0f;
            temp_s0->unk30.m[1][2] = 0.0f;
            temp_s0->unk30.m[2][0] = 0.0f;
            temp_s0->unk30.m[1][1] = temp_fv1;
            temp_s0->unk30.m[0][0] = (f32) -temp_fv1;
            temp_s0->unk30.m[0][1] = temp_fv0_2;
            temp_s0->unk30.m[1][0] = temp_fv0_2;
            temp_s0->unk30.m[2][1] = 0.0f;
            temp_s0->unk30.m[2][2] = 1.0f;
        }
        sUvTerraExports->unkAC(arg0, 1, temp_s0->unk30.m[3][0], temp_s0->unk30.m[3][1],
                               func_uvbill_rom_004003B4, temp_s0, temp_fv0);
    }
}

s32 func_uvbill_rom_004010B8(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 arg6,
                             s32 **arg7, f32 **arg8, Vec3F **arg9) {
    f32 temp_fv0;
    s32 i;
    s32 var_s3;
    f32 spA8;
    s32 var_s4;
    UnkStruct_uvbill_rom_004003B4 *temp_s0;

    *arg7 = D_uvbill_rom_00402004;
    *arg8 = D_uvbill_rom_0040200C;
    *arg9 = D_uvbill_rom_00402008;
    var_s4 = 0;

    if ((arg0 == arg3) && (arg1 == arg4) && (arg2 == arg5)) {
        var_s4 = func_uvbill_rom_00401418(arg0, arg1, arg2, 0.0f, arg6, arg7);
        if (var_s4 > 0) {
            *D_uvbill_rom_0040200C = 0.0f;
            temp_fv0 = *D_uvbill_rom_0040200C;
            D_uvbill_rom_00402008->z = temp_fv0;
            D_uvbill_rom_00402008->y = temp_fv0;
            D_uvbill_rom_00402008->x = temp_fv0;
            *arg8 = D_uvbill_rom_0040200C;
            *arg9 = D_uvbill_rom_00402008;
            return var_s4;
        }
    }
    for (i = 0; i < D_uvbill_rom_00402020; i++) {
        temp_s0 = &D_uvbill_rom_00402000[i];
        if ((temp_s0->unk3 != 0) && ((arg6 == 0) || (temp_s0->unk28 & arg6))) {
            //! @bug: sUvIntersectExports is uninitialized!
            if (sUvIntersectExports->func_uvintersect_rom_00400144(
                    arg0, arg1, arg2, arg3, arg4, arg5, temp_s0->unk30.m[3][0], temp_s0->unk30.m[3][1],
                    temp_s0->unk30.m[3][2], temp_s0->unkC, &spA8)
                == 0) {
                continue;
            }
            sUvIntersectExports->func_uvintersect_rom_00400700(
                arg0, arg1, arg2, arg3, arg4, arg5, spA8, temp_s0->unk30.m[3][0],
                temp_s0->unk30.m[3][1], temp_s0->unk30.m[3][2], &D_uvbill_rom_00402008[var_s4]);
            D_uvbill_rom_00402004[var_s4] = i;
            D_uvbill_rom_0040200C[var_s4] = spA8;
            var_s4++;
        }
    }
    return var_s4;
}

s32 func_uvbill_rom_00401388(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    UnkStruct_uvbill_rom_004003B4 *temp_v0;
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 temp_fv1;

    temp_v0 = &D_uvbill_rom_00402000[arg0];
    temp_fv0 = arg1 - temp_v0->unk30.m[3][0];
    temp_fv1 = arg2 - temp_v0->unk30.m[3][1];
    temp_ft4 = arg3 - temp_v0->unk30.m[3][2];
    temp_ft5 = temp_v0->unkC + arg4;
    if ((SQ(temp_fv0) + SQ(temp_fv1) + SQ(temp_ft4)) <= SQ(temp_ft5)) {
        return TRUE;
    }
    return FALSE;
}

s32 func_uvbill_rom_00401418(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 **arg5) {
    s32 i;
    s32 var_s2;
    UnkStruct_uvbill_rom_004003B4 *temp_v0;

    var_s2 = 0;
    for (i = 0; i < D_uvbill_rom_00402020; i++) {
        temp_v0 = &D_uvbill_rom_00402000[i];
        if ((temp_v0->unk3 != 0) && ((arg4 == 0) || (temp_v0->unk28 & arg4))) {
            if (func_uvbill_rom_00401388(i, arg0, arg1, arg2, arg3) == 0) {
                continue;
            }
            D_uvbill_rom_00402004[var_s2] = i;
            var_s2++;
        }
    }
    *arg5 = D_uvbill_rom_00402004;
    return var_s2;
}

void func_uvbill_rom_0040154C(s32 arg0, Mtx4F *arg1) {
    UnkStruct_uvbill_rom_004003B4 *a0;
    if ((arg0 >= 0) && (arg0 < D_uvbill_rom_00402020)) {
        sUvFmtxExports->uvMat4FCopy(&GET_ITEM(UnkStruct_uvbill_rom_004003B4, arg0)->unk30, arg1);
    }
}

void func_uvbill_rom_004015A4(s32 arg0, ...) {
    UnkStruct_uvbill_rom_004003B4 *temp_s0;
    f32 var_fv0;
    s32 temp_v1;
    va_list args;
    f32 y = 10.0f;

    if ((arg0 < 0) || (arg0 >= D_uvbill_rom_00402020)) {
        return;
    }
    temp_s0 = &D_uvbill_rom_00402000[arg0];
    va_start(args, arg0);
    while (TRUE) {
        temp_v1 = va_arg(args, s32);
        // FAKE: Make IDO reserve ft4 for the literal and fa1 for y...
        if (y > 4) {
        }
        if (y > 4) {
        }
        if (y > 4) {
        }
        if (y > 4) {
        }
        if (y > 4) {
        }

        switch (temp_v1) {
            case 0:
                return;
            case 1:
                temp_s0->unk30.m[3][0] = va_arg(args, f64);
                temp_s0->unk30.m[3][1] = va_arg(args, f64);
                temp_s0->unk30.m[3][2] = va_arg(args, f64);
                break;
            case 2:
                temp_s0->unk3 = va_arg(args, s32);
                break;
            case 3:
                temp_v1 = va_arg(args, s32);
                if (temp_v1 > 0 && temp_v1 < 4) {
                    temp_s0->unk0 = temp_v1;
                }
                break;
            case 4:
                temp_s0->unk8 = va_arg(args, s32);
                break;
            case 5:
                temp_s0->unkA = va_arg(args, s32);
                break;
            case 6:
                temp_s0->unk4 = va_arg(args, s32);
                if (temp_s0->unk4 != 0) {
                    var_fv0 = temp_s0->unk1C;
                } else {
                    var_fv0 = 2.0f * temp_s0->unk1C;
                }
                temp_s0->unkC = sUvMathExports->uvSqrtf(SQ(temp_s0->unk14) + SQ(var_fv0));
                break;
            case 7:
                temp_s0->unk14 = va_arg(args, f64);
                temp_s0->unk18 = va_arg(args, f64);
                temp_s0->unk1C = va_arg(args, f64);
                if (temp_s0->unk4 != 0) {
                    var_fv0 = temp_s0->unk1C;
                } else {
                    var_fv0 = 2.0f * temp_s0->unk1C;
                }
                temp_s0->unkC = sUvMathExports->uvSqrtf(SQ(temp_s0->unk14) + SQ(var_fv0));
                break;
            case 9:
                temp_s0->unk28 = va_arg(args, s32);
                break;
            case 8:
                var_fv0 = va_arg(args, f64);
                temp_s0->unk24 = var_fv0 * 255.0f;
                var_fv0 = va_arg(args, f64);
                temp_s0->unk25 = var_fv0 * 255.0f;
                var_fv0 = va_arg(args, f64);
                temp_s0->unk26 = var_fv0 * 255.0f;
                var_fv0 = va_arg(args, f64);
                temp_s0->unk27 = var_fv0 * 255.0f;
                break;
            case 10:
                temp_s0->unk20 = va_arg(args, f64);
                break;
            case 11:
                temp_s0->unk10 = va_arg(args, f64);
                break;
            case 12:
                var_fv0 = va_arg(args, f64);
                temp_s0->unk27 = var_fv0 * 255.0f;
                break;
            case 13:
                temp_s0->unk2 = va_arg(args, s32);
                break;
            case 14:
                temp_s0->unk5 = va_arg(args, s32);
                break;
            case 15:
                temp_s0->unk6 = va_arg(args, s32);
                break;
            default:
                return;
        }
    }
}

s32 func_uvbill_rom_00401E40(void) {
    s32 i;
    UnkStruct_uvbill_rom_004003B4 *var_v1;

    for (i = 0; i < D_uvbill_rom_00402020; i++) {
        var_v1 = &D_uvbill_rom_00402000[i];
        if (var_v1->unk1 == 0) {
            var_v1->unk0 = 2;
            var_v1->unk1 = 1;
            var_v1->unk3 = 1;
            var_v1->unkA = 0xFFF;
            var_v1->unk8 = 0xFF;
            var_v1->unk27 = 0xFF;
            var_v1->unk26 = 0xFF;
            var_v1->unk25 = 0xFF;
            var_v1->unk24 = 0xFF;
            var_v1->unk4 = 0;
            var_v1->unk28 = 0;
            var_v1->unk1C = 1.0f;
            var_v1->unk18 = 1.0f;
            var_v1->unk14 = 1.0f;
            var_v1->unkC = sUvMathExports->uvSqrtf(5.0f);
            var_v1->unk5 = 0;
            var_v1->unk6 = 0;
            var_v1->unk10 = 0.0f;
            var_v1->unk20 = 100000.0f;
            var_v1->unk2 = 1;
            var_v1->unk2C = 0;
            var_v1->unk74 = NULL;
            var_v1->unk70 = NULL;
            sUvFmtxExports->uvMat4SetIdentity(&var_v1->unk30);
            return i;
        }
    }
    return 0xFFFF;
}

void func_uvbill_rom_00401F5C(s32 arg0) {
    if ((arg0 < 0) || (arg0 >= D_uvbill_rom_00402020)) {
        return;
    }

    if (D_uvbill_rom_00402000[arg0].unk1 != 0) {
        D_uvbill_rom_00402000[arg0].unk3 = 0;
        D_uvbill_rom_00402000[arg0].unk1 = 0;
    }
}
