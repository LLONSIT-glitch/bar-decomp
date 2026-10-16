// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "uvasset_types.h"

s32 func_uvpfx_rom_004002BC(s32 arg0);
s32 func_uvpfx_rom_00400398(s32 arg0);
void func_uvpfx_rom_00400488(s32 arg0, Mtx4F *arg1);
void uvPfxProps(s32 arg0, ...);
void uvPfxGetProps(s32 arg0, ...);
void func_uvpfx_rom_00401810(void);
void func_uvpfx_rom_00401888(s32 arg0, s32 arg1);
void func_uvpfx_rom_004019A4(s32 arg0, f32 arg1, s32 arg2);
s32 func_uvpfx_rom_00401C6C(s32 arg0);
void func_uvpfx_rom_00401D88(f32 arg0);
void func_uvpfx_rom_00401E7C(s32 arg0);
void func_uvpfx_rom_00402008(s32 arg0);
void func_uvpfx_rom_004020D4(s32 arg0);
void func_uvpfx_rom_0040211C(s32 arg0);
void func_uvpfx_rom_004021FC(s32 arg0, f32 arg1);
void func_uvpfx_rom_0040374C(s32 arg0);
void func_uvpfx_rom_0040381C(s32 arg0, f32 arg1);
void func_uvpfx_rom_00403848(s32 arg0, s32 arg1, s16 arg2);
void func_uvpfx_rom_00403898(s32 arg0);
void func_uvpfx_rom_00404A60(Vec3F* arg0, Vec3F* arg1, Vec3F* arg2, f32 arg3, f32 arg4, s16* arg5, s16* arg6);
void func_uvpfx_rom_00404D2C(void);
void func_uvpfx_rom_0040242C(s32 arg0, s32 arg1);
void __entrypoint_func_uvpfx_rom_400000(UvPfx_Exports *exports);
void func_uvpfx_rom_004019A4(s32, f32, s32); 
void func_uvpfx_rom_00400264(s32 arg0);
void func_uvpfx_rom_00403AC8(s32 arg0, s32 arg1);

// .data
f32 D_uvpfx_rom_00404F40 = 0.0f;
f32 D_uvpfx_rom_00404F44[0x14] = {
    0.25f,
    0.65f,
    1.33f,
    1.33f,
    0.25f,
    0.65f,
    1.33f,
    1.33f,
    0.6f,
    0.8f,
    0.9f,
    0.95f,
    0.1f,
    0.3f,
    0.5f,
    0.7f,
    0.8f,
    0.85f,
    0.9f,
    0.95f,
}; /* const */

s32 D_uvpfx_rom_00404F94[] = {0x00500000, __entrypoint_func_uvpfx_rom_400000, 0};

// .bss
UnkStruct_uvpfx_rom_00404FA0* D_uvpfx_rom_00404FA0;
s32 D_uvpfx_rom_00404FA4;
s32 D_uvpfx_rom_00404FA8;
s32 sNoParticlesFlag;
Vec3F D_uvpfx_rom_00404FB0[256];
static UvFMtx_Rom_Exports* sUvFMtxExports;
static UvFVec_Rom_Exports* sUvFvecExports;
static UvGfxState_Rom_Exports* sUvGfxStateExports;
static UvGfxMgr_Exports* sUvGfxMgrExports;
static UvMath_Exports* sUvMathExports;
static UvChannel_Exports* sUvChannelExports;
static UvCback_Exports* sUvCbackExports;
static UvDGeom_Rom_Exports* sUvDGeomExports;
static UvTSeq_Exports* sUvTSeqExports;

void __entrypoint_func_uvpfx_rom_400000(UvPfx_Exports* exports) {
    s32 i;
    s32* temp_v0;

    uvUpdateFileAllocPtr(exports);
    exports->func_uvpfx_rom_00401810 = func_uvpfx_rom_00401810;
    exports->func_uvpfx_rom_00402008 = func_uvpfx_rom_00402008;
    exports->func_uvpfx_rom_00400264 = func_uvpfx_rom_00400264;
    exports->func_uvpfx_rom_004020D4 = func_uvpfx_rom_004020D4;
    exports->func_uvpfx_rom_004002BC = func_uvpfx_rom_004002BC;
    exports->func_uvpfx_rom_0040211C = func_uvpfx_rom_0040211C;
    exports->func_uvpfx_rom_00400398 = func_uvpfx_rom_00400398;
    exports->func_uvpfx_rom_0040374C = func_uvpfx_rom_0040374C;
    exports->func_uvpfx_rom_00400488 = func_uvpfx_rom_00400488;
    exports->func_uvpfx_rom_0040381C = func_uvpfx_rom_0040381C;
    exports->uvPfxProps = uvPfxProps;
    exports->func_uvpfx_rom_00403848 = func_uvpfx_rom_00403848;
    exports->uvPfxGetProps = uvPfxGetProps;
    exports->func_uvpfx_rom_00401C6C = func_uvpfx_rom_00401C6C;
    exports->func_uvpfx_rom_00401D88 = func_uvpfx_rom_00401D88;
    exports->func_uvpfx_rom_00401E7C = func_uvpfx_rom_00401E7C;
    exports->D_uvpfx_rom_00404FA0 = &D_uvpfx_rom_00404FA0;
    exports->D_uvpfx_rom_00404FA4 = &D_uvpfx_rom_00404FA4;
    exports->D_uvpfx_rom_00404FA8 = &D_uvpfx_rom_00404FA8;
    exports->sNoParticlesFlag = &sNoParticlesFlag;
    D_uvpfx_rom_00404FA8 = 0;
    temp_v0 = uvGetSystemProp(0x13);
    if (temp_v0 == NULL) {
        D_uvpfx_rom_00404FA4 = 0x100;
    } else {
        // clang-format off
        if (*temp_v0 != 0) { D_uvpfx_rom_00404FA4 = *temp_v0;} else {    D_uvpfx_rom_00404FA4 = 0x100; }
        // clang-format on
    }
    D_uvpfx_rom_00404FA0 = _uvMemAllocAlign8(D_uvpfx_rom_00404FA4 * 0xC);
    for (i = 0; i < D_uvpfx_rom_00404FA4; i++) {
        D_uvpfx_rom_00404FA0[i].unk0 = 0;
    }
    sUvFMtxExports = uvLoadModule('FMTX');
    sUvFvecExports = uvLoadModule('FVEC');
    sUvMathExports = uvLoadModule('MATH');
    sUvDGeomExports = uvLoadModule('DGEO');
    sUvGfxStateExports = uvLoadModule('STAT');
    sUvGfxMgrExports = uvLoadModule('GMGR');
    sUvChannelExports = uvLoadModule('CHAN');
    sUvCbackExports = uvLoadModule('CBCK');
    sUvTSeqExports = uvLoadModule('TSEQ');
}

void func_uvpfx_rom_00400264(s32 arg0) {
    CallbackList* callbackList;

    sUvChannelExports->func_uvchannel_rom_00400288(arg0, 6, &callbackList, 0);
    sUvCbackExports->uvAddCallback(callbackList, func_uvpfx_rom_00401E7C, NULL, 0x65);
}

s32 func_uvpfx_rom_004002BC(s32 arg0) {
    s32 i;
    s32 indexFound;
    UnkStruct_uvpfx_rom_00404FA0* var_v0;
    UnkStruct_uvpfx_rom_00404FA0_unk0* v1;
    UnkStruct_uvpfx_rom_00404FA0_unk4* temp_a0;

    indexFound = -1;
    for (i = 0; i < D_uvpfx_rom_00404FA8; i++) {
        v1 = D_uvpfx_rom_00404FA0[i].unk0;
        temp_a0 = D_uvpfx_rom_00404FA0[i].unk4;
        if ((arg0 == v1->unk2) && (temp_a0->unk24 == 0)) {
            temp_a0->unk24 = -1;
            temp_a0->unkC =  1000000.0f;
            indexFound = i;
            break;
        } 
        
    }
    if (indexFound < 0) {
        return -1;
    }
    v1 = D_uvpfx_rom_00404FA0[indexFound].unk0; 
    if (v1->unk4 == 1) {
        func_uvpfx_rom_0040374C(indexFound);
    } else {
        func_uvpfx_rom_0040211C(indexFound);
    }
    return indexFound;
}

s32 func_uvpfx_rom_00400398(s32 arg0) {
    UnkStruct_uvpfx_rom_00404FA0_unk0 *a1;
    s32 sp28;
    s32 var_a3;
    UnkStruct_uvpfx_rom_00404FA0_unk4 *temp_v1;
    f32 var_fv1;
    s32 i;

    var_a3 = -1;
    var_fv1 =  -2000000.0f;
    
    for (i = 0; i < D_uvpfx_rom_00404FA8; i++) {
        a1 = D_uvpfx_rom_00404FA0[i].unk0;
        temp_v1 = D_uvpfx_rom_00404FA0[i].unk4;
        if (arg0 == a1->unk2) {
            if (var_fv1 < temp_v1->unk8) {
                var_fv1 = temp_v1->unk8;
                sp28 = i;
            }
            if (temp_v1->unk24 == 0) {
                var_a3 = i;
            }
        }
    }
    if (var_a3 < 0) {
        var_a3 = sp28;
    }
    
    a1 = D_uvpfx_rom_00404FA0[var_a3].unk0;
    if (a1->unk4 == 1) {
        func_uvpfx_rom_0040374C(var_a3);
    } else {
        func_uvpfx_rom_0040211C(var_a3);
    }
    return var_a3;
}

void func_uvpfx_rom_00400488(s32 arg0, Mtx4F* arg1) {
    UnkStruct_uvpfx_rom_00404FA0_unk4* v1 = D_uvpfx_rom_00404FA0[arg0].unk4;
    sUvFMtxExports->uvMat4FCopy(&v1->unk80, arg1);
}

void uvPfxProps(s32 arg0, ...) {
    va_list args;
    UnkStruct_uvpfx_rom_00404FA0 *temp_v0;
    UnkStruct_uvpfx_rom_00404FA0_unk0 *temp_s3;
    UnkStruct_uvpfx_rom_00404FA0_unk4 *temp_s1;
    f32 var_fa0;
    f32 var_fv0;
    s16 temp_v0_2;
    s32 temp_s0;
    s32 temp_a1;
    ParsedUVTX* var_v1_3;
    s32 sp3C;
    UnkStruct_uvpfx_rom_00404FA0_unk28 *temp_s5;
   
    temp_s3 = D_uvpfx_rom_00404FA0[arg0].unk0;
    temp_s1 = D_uvpfx_rom_00404FA0[arg0].unk4;
    temp_s5 = temp_s3->unk28;
    va_start(args, arg0);
    
    while (TRUE) {
        temp_v0_2 = va_arg(args, s32);
        if (((temp_v0_2 & 0x2000) && (temp_s3->unk4 == 1))
            || ((temp_v0_2 & 0x4000) && (temp_s3->unk4 == 2))) {
            break;
        }

        switch (temp_v0_2) { /* irregular */
            case 0x1001:
                temp_s1->unk10 = va_arg(args, f64);
                break;
            case 0x1019:
                temp_s1->unk7C = va_arg(args, f64);
                break;
            case 0x1002:
                temp_s1->unk4 = va_arg(args, f64);
                break;
            case 0x1014:
                temp_s1->unk2A = va_arg(args, s32);
                break;
            case 0x1013:
                temp_a1 =  (s16)(va_arg(args, s16*)); // TODO: This is wrong...
                if (temp_a1 != 0xFF) {
                    var_v1_3 = NULL;
                    temp_s1->unk28 = sUvTSeqExports->uvTexSeqFindFree();
                    if (temp_s1->unk28 != 0xFF) {
                        sUvTSeqExports->uvTexSeqModel(temp_s1->unk28, temp_a1);
                        sp3C = sUvTSeqExports->uvTexSeqGetCurFrameTexture((s32) temp_s1->unk28);
                    }
                    if (sp3C != 0xFFF) {
                        var_v1_3 = uvLoadFile('UVTX', sp3C);
                    }
                    if (var_v1_3 != NULL) {
                        temp_s1->unk2C = 0xFFF;
                        temp_s1->unk2E = (u16) var_v1_3->width;
                        temp_s1->unk30 = (u16) var_v1_3->height;
                        func_uvpfx_rom_00401888(arg0, 0);
                    }
                } else {
                    temp_s1->unk28 = 0xFF;
                }
                break;
            case 0x1007:
                temp_s1->unk1C = va_arg(args, f64);
                break;
            case 0x1008:
                temp_s1->unk2C = va_arg(args, s32);
                if (temp_s1->unk2C != 0xFFF) {
                    var_v1_3 = uvLoadFile('UVTX', temp_s1->unk2C);
                    if (var_v1_3 != NULL) {
                        temp_s1->unk2E = (u16) var_v1_3->width;
                        temp_s1->unk30 = (u16) var_v1_3->height;
                        func_uvpfx_rom_00401888(arg0, 0);
                    }
                    temp_s1->unk28 = 0xFF;
                }
                break;
            case 0x1015:
                func_uvpfx_rom_00401888(arg0, va_arg(args, s32));
                break;
            case 0x1003:
                sUvFvecExports->uvVec3FSet(&temp_s1->unk70, va_arg(args, f64),
                                                 va_arg(args, f64), va_arg(args, f64));
                if (temp_s1->unk70.y < temp_s1->unk70.x) {
                    var_fv0 = temp_s1->unk70.x;
                } else {
                    var_fv0 = temp_s1->unk70.y;
                }
                if (var_fv0 < temp_s1->unk70.z) {
                    var_fa0 = temp_s1->unk70.z;
                } else {
                    var_fa0 = var_fv0;
                }
                temp_s3->unk38 = (temp_s3->unk34 * var_fa0 * 0.5f);
                break;
            case 0x1025:
                sUvFvecExports->uvVec3FSet(&temp_s1->unkC0, va_arg(args, f64), va_arg(args, f64), va_arg(args, f64));
                break;
            case 0x2004:
                temp_s3->unk1E = va_arg(args, s32);
                break;
            case 0x1005:
                temp_s3->unk16 = ((f32)va_arg(args, f64) * 255.0f);
                temp_s3->unk18 = ((f32)va_arg(args, f64)  * 255.0f);
                temp_s3->unk1A = ((f32)va_arg(args, f64) * 255.0f);
                temp_s3->unk1C = ((f32)va_arg(args, f64) * 255.0f);
                break;
            case 0x4026:
                if (temp_s3->unk4 == 1) {
                    temp_s5->unkE = ((f32)va_arg(args, f64) * 255.0f);
                    temp_s5->unk10 = ((f32)va_arg(args, f64) * 255.0f);
                    temp_s5->unk12 = ((f32)va_arg(args, f64) * 255.0f);
                    temp_s5->unk14 = ((f32)va_arg(args, f64) * 255.0f);
                } else {
                    f32 unused1 = va_arg(args, f64);
                    f32 unused2 = va_arg(args, f64);
                    f32 unused3 = va_arg(args, f64);
                    f32 unused4 = va_arg(args, f64);
                }
                break;
            case 0x1010:
                temp_s1->unk80.m[3][0] = va_arg(args, f64);
                temp_s1->unk80.m[3][1] = va_arg(args, f64);
                temp_s1->unk80.m[3][2] = va_arg(args, f64);
                break;
            case 0x1020:
                temp_s1->unk0 = va_arg(args, s32);
                break;
            case 0x1022:
                temp_s3->unk12 = (f32)va_arg(args, f64);
                break;
            case 0x1023:
                temp_s3->unk14 = va_arg(args, s32);
                break;
            case 0x1024:
                if (va_arg(args, s32) != 0) {
                    temp_s3->unk8 = (s32) (temp_s3->unk8 | 0x400000);
                    temp_s3->unkC = (s32) (temp_s3->unkC & 0xFFBFFFFF);
                } else {
                    temp_s3->unkC = (s32) (temp_s3->unkC | 0x400000);
                    temp_s3->unk8 = (s32) (temp_s3->unk8 & 0xFFBFFFFF);
                }
                break;
            case 0x1026:
                if (va_arg(args, s32) != 0) {
                    temp_s3->unk8 = (s32) (temp_s3->unk8 | 0x200000);
                    temp_s3->unkC = (s32) (temp_s3->unkC & 0xFFDFFFFF);
                } else {
                    temp_s3->unkC = (s32) (temp_s3->unkC | 0x200000);
                    temp_s3->unk8 = (s32) (temp_s3->unk8 & 0xFFDFFFFF);
                }
                break;
            case 0x4027:
                var_fv0 = va_arg(args, f64);
                temp_s5->unkA = (var_fv0 * 100.0f);
                break;
            case 0x1027:
                temp_s1->unk6E = va_arg(args, s32);
                break;
            case 0x1028:
                temp_s1->unkE4 = va_arg(args, s32);
                temp_s1->unkE8 = va_arg(args, s32);
                break;
            case 0x4029:
                var_fv0 = va_arg(args, f64);
                temp_s5->unkC = (var_fv0 * 100.0f);
                break;
            case 0x4030:
                temp_s1->unk18 = (s16)va_arg(args, s32);
                break;
            case 0x4033:
                temp_s1->unkD8 = (f32)va_arg(args, f64);
                temp_s1->unkDC = (f32)va_arg(args, f64);
                temp_s1->unkE0 = (f32)va_arg(args, f64);
                break;
            case 0:
                return;
            default:
                return;
        }
    }
}

void uvPfxGetProps(s32 arg0, ...) {
    va_list args;
    UnkStruct_uvpfx_rom_00404FA0 *temp_v1;
    UnkStruct_uvpfx_rom_00404FA0_unk0 *temp_v0;
    UnkStruct_uvpfx_rom_00404FA0_unk28 *temp_a1;
    UnkStruct_uvpfx_rom_00404FA0_unk2C *temp_a2;
    UnkStruct_uvpfx_rom_00404FA0_unk4 *temp_a0;
    s16 prop;

    temp_v0 = D_uvpfx_rom_00404FA0[arg0].unk0;
    temp_a0 = D_uvpfx_rom_00404FA0[arg0].unk4;
    temp_a1 = temp_v0->unk28;
    temp_a2 = temp_v0->unk2C;
    va_start(args, arg0);

    while (TRUE) {
        prop = (s32) va_arg(args, s32);
        switch (prop) { /* irregular */
            case 0x1001:
                *va_arg(args, f32 *) = temp_a0->unk10;
                break;
            case 0x1019:
                *va_arg(args, f32 *) = temp_a0->unk7C;
                break;
            case 0x1002:
                *va_arg(args, f32 *) = temp_a0->unk4;
                break;
            case 0x1013:
                *va_arg(args, s32 *) = temp_a0->unk28;
                break;
            case 0x1014:
                *va_arg(args, s32 *) = temp_a0->unk2A;
                break;
            case 0x1007:
                *va_arg(args, f32 *) = temp_a0->unk1C;
                break;
            case 0x1008:
                *va_arg(args, s32 *) = (s32) temp_a0->unk2C;
                break;
            case 0x1003:
                *va_arg(args, f32 *) = temp_a0->unk70.x;
                *va_arg(args, f32 *) = temp_a0->unk70.y;
                *va_arg(args, f32 *) = temp_a0->unk70.z;
                break;
            case 0x2004:
                *va_arg(args, s16 *) = temp_v0->unk1E;
                break;
            case 0x1005:
                *va_arg(args, f32 *) = (f32) temp_v0->unk16 / 255.0f;
                *va_arg(args, f32 *) = (f32) temp_v0->unk18 / 255.0f;
                *va_arg(args, f32 *) = (f32) temp_v0->unk1A / 255.0f;
                *va_arg(args, f32 *) = (f32) temp_v0->unk1C / 255.0f;
                break;
            case 0x4026:
                if (temp_v0->unk4 == 1) {
                    *va_arg(args, f32 *) = (f32) temp_a1->unkE / 255.0f;
                    *va_arg(args, f32 *) = (f32) temp_a1->unk10 / 255.0f;
                    *va_arg(args, f32 *) = (f32) temp_a1->unk12 / 255.0f;
                    *va_arg(args, f32 *) = (f32) temp_a1->unk14 / 255.0f;
                } else {
                    *va_arg(args, f32 *) = 1.0f;
                    *va_arg(args, f32 *) = 1.0f;
                    *va_arg(args, f32 *) = 1.0f;
                    *va_arg(args, f32 *) = 1.0f;
                }
                break;
            case 0x1010:
                *va_arg(args, f32 *) = temp_a0->unk80.m[3][0];
                *va_arg(args, f32 *) = temp_a0->unk80.m[3][1];
                *va_arg(args, f32 *) = temp_a0->unk80.m[3][2];
                break;
            case 0x1011:
                *va_arg(args, s32 *) = temp_a0->unk24 > 0;
                break;
            case 0x1012:
                *va_arg(args, f32*)  = temp_a2->unkC;
                break;
            case 0x1022:
                *va_arg(args, f32 *) = temp_v0->unk12;
                break;
            case 0x1023:
                *va_arg(args, s8 *) = temp_v0->unk14;
                break;
            case 0x1024:
                *va_arg(args, s16 *) = temp_v0->unk8 & 0x400000;
                break;
            case 0x1026:
                *va_arg(args, s16 *) = temp_v0->unk8 & 0x200000;
                break;
            case 0x4027:
                *va_arg(args, f32 *) = (f32) temp_a1->unkA * 0.01f;
                break;
            case 0x4029:
                *va_arg(args, f32 *) = temp_a1->unkC * 0.01f;
                break;
            case 0x4030:
                *va_arg(args, s16 *) = temp_a0->unk18;
                break;
            case 0x4033:
                *va_arg(args, f32 *) = temp_a0->unkD8;
                *va_arg(args, f32 *) = temp_a0->unkDC;
                *va_arg(args, f32 *) = temp_a0->unkE0;
                break;
            case 0:
                return;
            default:
                return;
        }
    }
}

void func_uvpfx_rom_00401810(void) {
    uvUnloadModule('FMTX');
    uvUnloadModule('FVEC');
    uvUnloadModule('MATH');
    uvUnloadModule('DGEO');
    uvUnloadModule('STAT');
    uvUnloadModule('CHAN');
    uvUnloadModule('CBCK');
    uvUnloadModule('TSEQ');
}

#define PI 3.1415927f
void func_uvpfx_rom_00401888(s32 arg0, s32 arg1) {
    Vec3F* var_s0;
    f32 temp_fs1;
    f32 var_fs0;
    s32 i;

    var_fs0 = 0.0f;
    for (i = 0; i < 5; i++) {
        if (arg1 != 0) {
            var_fs0 = 2.0f * sUvMathExports->uvRandFLcg() * PI;
        }
        func_uvpfx_rom_004019A4(i, var_fs0, arg0);
    }
    for (i = 0; i < 256; i++) {
        D_uvpfx_rom_00404FB0[i].x = 2.0f * (sUvMathExports->uvRandFLcg() - 0.5f);
        D_uvpfx_rom_00404FB0[i].y = 2.0f * (sUvMathExports->uvRandFLcg() - 0.5f);
        D_uvpfx_rom_00404FB0[i].z = (f32) (2.0f * (sUvMathExports->uvRandFLcg() - 0.5f));
    } 
}

void func_uvpfx_rom_004019A4(s32 arg0, f32 arg1, s32 arg2) {
    f32 sp88[2];
    f32 sp80[2];
    f32 sp78[2];
    Mtx4F sp38;
    Vec3F sp2C;
    UnkStruct_uvpfx_rom_00404FA0_unk4* temp_s0;

    temp_s0 = D_uvpfx_rom_00404FA0[arg2].unk4;
    sUvFMtxExports->uvMat4SetIdentity(&sp38);
    sUvFMtxExports->uvMat4RotateAxis(&sp38, arg1, 0x7A);
    sUvFvecExports->uvVec3FSet(&sp2C, 0.0f, 1.0f, 0.0f);
    sUvFMtxExports->func_uvfmtx_rom_004030FC(&sp38, &sp2C, &sp2C);
    sp88[0] = sp2C.x + 0.5f;
    sp88[1] = sp2C.y + 0.5f;
    sUvFvecExports->uvVec3FSet(&sp2C, -0.866f, -0.5f, 0.0f);
    sUvFMtxExports->func_uvfmtx_rom_004030FC(&sp38, &sp2C, &sp2C);
    sp80[0] = sp2C.x + 0.5f;
    sp80[1] = sp2C.y + 0.5f;
    sUvFvecExports->uvVec3FSet(&sp2C, 0.866f, -0.5f, 0.0f);
    sUvFMtxExports->func_uvfmtx_rom_004030FC(&sp38, &sp2C, &sp2C);
    sp78[0] = sp2C.x + 0.5f;
    sp78[1] = sp2C.y + 0.5f;
    temp_s0->unk32[arg0][0] = ((s16) (sp88[0] * temp_s0->unk2E) << 5);
    temp_s0->unk32[arg0][1] = ((s16) (sp88[1] * temp_s0->unk2E) << 5);
    temp_s0->unk32[arg0][2] = ((s16) (sp80[0] * temp_s0->unk2E) << 5);
    temp_s0->unk32[arg0][3] = ((s16) (sp80[1] * temp_s0->unk2E) << 5);
    temp_s0->unk32[arg0][4] = ((s16) (sp78[0] * temp_s0->unk2E) << 5);
    temp_s0->unk32[arg0][5] = ((s16) (sp78[1] * temp_s0->unk2E) << 5);
}

s32 func_uvpfx_rom_00401C6C(s32 arg0) {
    UnkStruct_uvpfx_rom_00404FA0* temp_v1;
    UnkStruct_uvpfx_rom_00404FA0_unk0* temp_v0;
    UnkStruct_uvpfx_rom_00404FA0_unk4* temp_a1;
    f32 temp_fa0;
    f32 temp_fv0;
    f32 temp_fv1;
    s16 temp_v1_2;
    s32 out;

    temp_v0 = D_uvpfx_rom_00404FA0[arg0].unk0;
    temp_a1 = D_uvpfx_rom_00404FA0[arg0].unk4;
    temp_a1->unk8 = (D_uvpfx_rom_00404F40 - temp_a1->unkC) - temp_a1->unk4;
    if (temp_a1->unk8 < 0.0f) {
        temp_a1->unk24 = -1;
        out = 0;
    }
    else if (temp_a1->unk10 < temp_a1->unk8) {
        temp_a1->unk24 = 0;
        out = 0;
    }
    else if (temp_a1->unk24 == 3) {
        temp_fa0 = (temp_a1->unk8 + 1.0f) - temp_a1->unk10;
        if ((temp_fa0 > 0.0f) && (temp_v0->unk14 != 0)) {
            temp_a1->unk26 = ((1.0f - temp_fa0) * 254.0f);
        } else {
            temp_a1->unk26 = 0xFF;
        }
        out = 1;
    } else if (temp_a1->unk24 == 2) {
        temp_a1->unk24 = 3;
        out = 1;
    } else {
        temp_a1->unk24 = 2;
        out = 1;
    }
    return out;
}

void func_uvpfx_rom_00401D88(f32 arg0) {
    s32 i;
    UnkStruct_uvpfx_rom_00404FA0_unk0 *temp_s0;

    D_uvpfx_rom_00404F40 += arg0;
    for (i = 0; i < D_uvpfx_rom_00404FA8; i++) {
        temp_s0 = D_uvpfx_rom_00404FA0[i].unk0;
        if (temp_s0 == NULL) {
            continue;
        }

        if (func_uvpfx_rom_00401C6C(i) != 0) {
            if (temp_s0->unk4 == 1) {
                func_uvpfx_rom_00403898(i);
            } else if (temp_s0->unk4 == 2) {
                func_uvpfx_rom_004021FC(i, arg0);
            }
        }
    }
}

void func_uvpfx_rom_00401E7C(s32 arg0) {
    s32 i;
    UnkStruct_uvpfx_rom_00404FA0_unk4 *temp_a0;
    UnkStruct_uvpfx_rom_00404FA0_unk0 *temp_v0;
    f32 sp40;
    f32 sp3C;
    
    if (sNoParticlesFlag) {
        return;
    }

    sUvGfxStateExports->uvGfxStatePush();
    sUvGfxStateExports->func_uvgfxstate_rom_004020DC(&sp40, &sp3C);
    sUvGfxStateExports->func_uvgfxstate_rom_00401F54(0, 0.0f);
    sUvGfxStateExports->func_uvgfxstate_rom_00401CE8();
    for (i = 0; i < D_uvpfx_rom_00404FA8; i++) {
        temp_v0 = D_uvpfx_rom_00404FA0[i].unk0;
        if (temp_v0 == NULL) {
            continue;
        }

        temp_a0 = D_uvpfx_rom_00404FA0[i].unk4;
        if ((temp_a0->unk24 > 0) && (temp_a0->unk0 == 0) && (temp_v0->unk2 != -1)) {
            if (temp_v0->unk4 == 1) {
                func_uvpfx_rom_00403AC8(i, arg0);
            } else {
                func_uvpfx_rom_0040242C(i, arg0);
            }
        }
    }
    sUvGfxStateExports->func_uvgfxstate_rom_00401F54(sp40, sp3C);
    sUvGfxStateExports->uvGfxStatePop();
}

void func_uvpfx_rom_00402008(s32 arg0) {
    UnkStruct_uvpfx_rom_00404FA0_unk0* temp_t0;
    UnkStruct_uvpfx_rom_00404FA0_unk4* temp_v1;

    temp_v1 = D_uvpfx_rom_00404FA0[arg0].unk4;
    temp_t0 = D_uvpfx_rom_00404FA0[arg0].unk0;
    if (temp_v1->unk28 != 0xFF) {
        sUvTSeqExports->uvTexSeqProps(temp_v1->unk28, TSEQ_PROP_ACTIVE(TRUE), TSEQ_PROP_CURR_FRAME(0), TSEQ_PROP_END);
    }
    temp_v1->unkC = D_uvpfx_rom_00404F40;
    if (temp_t0->unk4 == 1) {
        func_uvpfx_rom_0040374C(arg0);
    } else {
        func_uvpfx_rom_0040211C(arg0);
    }
    temp_v1->unk24 = -1;
}

void func_uvpfx_rom_004020D4(s32 arg0) {
    UnkStruct_uvpfx_rom_00404FA0_unk4* temp_v0;

    temp_v0 = D_uvpfx_rom_00404FA0[arg0].unk4;
    temp_v0->unkC = ((D_uvpfx_rom_00404F40 - temp_v0->unk10) + 1.0f) - temp_v0->unk4;
}

void func_uvpfx_rom_0040211C(s32 arg0) {
    UnkStruct_uvpfx_rom_00404FA0_unk0* temp_s2;
    UnkStruct_uvpfx_rom_00404FA0_unk4* temp_v0;
    Vec3F* var_s1;
    s32 i;

    temp_s2 = D_uvpfx_rom_00404FA0[arg0].unk0;
    temp_v0 = D_uvpfx_rom_00404FA0[arg0].unk4;
    temp_v0->unk20 = 0;
    temp_v0->unk14 = 0.0f;
    temp_v0->unk4 = 0.0f;
    if (temp_s2->unk2C->unk0 != 9) {
        return;
    }
        
    var_s1 = D_uvpfx_rom_00404FA0[arg0].unk8;
    for (i = 0; i < temp_s2->unk10; i++) {
        sUvFvecExports->uvVec3FSet(&var_s1[i], 0.0f, 0.0f, 0.0f);
    }
}

void func_uvpfx_rom_004021FC(s32 arg0, f32 arg1) {
    UnkStruct_uvpfx_rom_00404FA0* temp_v0;
    UnkStruct_uvpfx_rom_00404FA0_unk0* temp_s3;
    UnkStruct_uvpfx_rom_00404FA0_unk2C* temp_s6;
    UnkStruct_uvpfx_rom_00404FA0_unk4* temp_s2;
    Vec3F* temp_s4;
    f32 temp_fa0;
    f32 temp_fv0;
    s16 temp_v1;
    s16 i;
    s32 var_v0;

    temp_s3 = D_uvpfx_rom_00404FA0[arg0].unk0;
    temp_s2 = D_uvpfx_rom_00404FA0[arg0].unk4;
    temp_s4 = D_uvpfx_rom_00404FA0[arg0].unk8;
    temp_s6 = temp_s3->unk2C;

    switch (temp_s6->unk8) {                              /* irregular */
    case 0:

        if (temp_s2->unk10 < 2.0f * temp_s6->unkC) {
            temp_s2->unk10 = 2.0f * temp_s6->unkC;
        }
        break;
    case 1:
        if (temp_s2->unk10 < temp_s6->unkC) {
            temp_s2->unk10 = temp_s6->unkC;
        }
        break;
    }
    var_v0 = (s32) (temp_s2->unk10 / temp_s6->unkC);
    if (var_v0 <= 0) {
        var_v0 = 1;
    }
    temp_s2->unk10 = (f32) var_v0 * temp_s6->unkC;
    if (temp_s2->unk24 != 0) {
        if (temp_s2->unk20 >= (var_v0 - 1)) {
            temp_s2->unk22 = 1;
        } else {
            temp_s2->unk22 = 0;
        }
        temp_s2->unk14 += arg1;
    } else {
        temp_s2->unk2 = 1;
        return;
    }

    if (temp_s6->unkC < temp_s2->unk14) {
        temp_s2->unk20 += 1;
        temp_s2->unk14 = 0.0f;
    }
    if (temp_s2->unk2 != 0) {
        temp_s2->unk20 = 1;
        temp_s2->unk2 = 0;
        if (temp_s6->unk0 == 9) {
            for (i = 0; i < temp_s3->unk10; i++) {
                sUvFvecExports->uvVec3FSet(&temp_s4[i], 0.0f, 0.0f, 0.0f);
            }
        }
        if (temp_s6->unk8 == 0) {
            temp_s2->unk14 = 0.0f - temp_s6->unkC;
        } else {
            temp_s2->unk14 = 0.0f;
        }
    }
}

void func_uvpfx_rom_0040242C(s32 arg0, s32 arg1) {
    s16 var_s4;
    s32 sp2F8;
    s32 sp2F4;
    f32 temp_fa0;
    f32 var_ft4;
    f32 var_fs0;
    f32 var_fv0;
    s16 sp2DC[4];
    Vec3F sp2D0;
    UnkStruct_uvpfx_rom_00404FA0 *temp_v0;
    UnkStruct_uvpfx_rom_00404FA0_unk0 *temp_s2;
    UnkStruct_uvpfx_rom_00404FA0_unk4 *temp_s3;
    f32 temp_fv0;
    Vec3F sp2B4;
    Vec3F sp2A8;
    Vec3F sp29C;
    Vec3F sp290;
    Mtx4F sp250;
    Mtx4F sp210;
    Mtx4F sp1D0;
    Mtx4F sp190;
    Mtx4F sp150;
    f32 sp14C;
    f32 sp148;
    f32 sp144;
    f32 var_ft5;
    s32 sp13C;
    s32 sp138;
    s32 sp134;
    s32 sp130;
    f32 sp12C;
    Vec3F *sp128;
    f32 var_fv0_2;
    f32 var_fv1;
    UnkStruct_uvpfx_rom_00404FA0_unk2C *sp11C;
    f32 sp118;
    f32 sp114;
    f32 temp_fa1;
    f32 temp_fs0;
    f32 temp_fs1;
    s16 *temp_a2;
    s16 *temp_a3;
    s32 temp_s0;
    s32 spF8;
    s32 temp_s1;
    s32 spF0;
    Vec3F spE4;
    f32 spAC;
    s16 temp_v1_2;
    s16 temp_t1;
    s16 temp_t2;
    s16 temp_a0;
    s32 pad[2];
    f32 temp;
    Vec3F spC0;

    sp2F4 = 0;
    sp12C = 1.0f;
    temp_s2 = D_uvpfx_rom_00404FA0[arg0].unk0;
    temp_s3 = D_uvpfx_rom_00404FA0[arg0].unk4;
    sp128 = D_uvpfx_rom_00404FA0[arg0].unk8;
    sp11C = temp_s2->unk2C;
    if (temp_s3->unkE4 != 0) {
        temp_s3->unkE4(temp_s3->unkE8);
    }
    if (temp_s2->unk6 != 0) {
        sUvGfxMgrExports->uvGfxSetDepthSource(1);
        sUvChannelExports->func_uvchannel_rom_00400288(arg1, 5, &sp13C, &sp138, &sp134, &sp130, 1,
                                                          &sp250, 2, &sp210, 3, &sp1D0, 0);
        sUvFMtxExports->uvMat4RotateAxis(&sp250, -1.5707963f, 'x');
        sUvFMtxExports->uvMat4Mul(&sp190, &sp250, &sp210);
        sp118 = sp130 - sp134;
        sp114 = sp138 - sp13C;
    } else {
        sUvChannelExports->func_uvchannel_rom_00400288(arg1, 3, &sp1D0, 0);
        sUvFMtxExports->uvMat4InvertTranslationRotation(&sp210, &temp_s3->unk80);
        sUvFMtxExports->uvMat4Mul(&sp210, &sp210, &sp1D0);
    }
    sp2A8.x = temp_s3->unk80.m[3][0] - sp1D0.m[3][0];
    sp2A8.y = temp_s3->unk80.m[3][1] - sp1D0.m[3][1];
    sp2A8.z = temp_s3->unk80.m[3][2] - sp1D0.m[3][2];
    temp_fv0 = sUvFvecExports->uvVec3FLen(&sp2A8);
    if (temp_fv0 < 0.1f) {
        return;
    }
    if (temp_s3->unk7C < temp_fv0) {
        return;
    }
    temp_fa0 = temp_s3->unk7C * 0.8f;
    if (temp_fa0 < temp_fv0) {
        sp12C = (temp_s3->unk7C - temp_fv0) / (temp_s3->unk7C - temp_fa0);
    }
    // FAKE
    if (0) {
    }
    
    sp2A8.x *= 1.0f / temp_fv0;
    sp2A8.y *= 1.0f / temp_fv0;
    sp2A8.z *= 1.0f / temp_fv0;
    if (temp_s2->unk6 == 0) {
        if (sp11C->unk0 == 8) {
            if (temp_s2->unk24 == 1) {
                sUvFvecExports->uvVec3FSet(&sp2B4, 0.00f, temp_s2->unk12, 0.00f);
                sUvFvecExports->uvVec3FSet(&sp29C, temp_s2->unk12, 0.000f, 0.00f);
            } else {
                sUvFvecExports->uvVec3FSet(&sp2B4, 0.00f, 0.00f, temp_s2->unk12);
                sUvFMtxExports->func_uvfmtx_rom_004030FC(&sp210, &sp2B4, &sp2B4);
                sUvFvecExports->uvVec3FSet(&sp29C, temp_s2->unk12, 0.000f, 0.00f);
                sUvFMtxExports->func_uvfmtx_rom_004030FC(&sp210, &sp29C, &sp29C);
            }
        }
        sUvFMtxExports->uvMat4SetIdentity(&sp150);
        sUvFMtxExports->uvMat4Scale(&sp150, temp_s3->unk70.x * (1.0f / temp_s2->unk12),
                                          temp_s3->unk70.y * (1.0f / temp_s2->unk12),
                                          temp_s3->unk70.z * (1.0f / temp_s2->unk12));
        sUvFMtxExports->func_uvfmtx_rom_00400370(&sp210, &temp_s3->unk80);
        sUvFMtxExports->uvGfxMtxViewLoad(&sp210, 1);
        sUvFMtxExports->uvGfxMtxViewLoad(&sp150, 0);
    }
    if (temp_s3->unk2C != 0xFFF) {
        sp2F8 = temp_s3->unk2C;
    } else if (temp_s3->unk28 != 0xFF) {
        if (temp_s3->unk2A & 1) {
            sp2F8 = sUvTSeqExports->uvTexSeqGetCurFrameTexture((s32) temp_s3->unk28);
        } else {
            sp2F4 = 1;
        }
        if (temp_s3->unk2A & 4) {
            sUvGfxMgrExports->uvGfxSetEnvColorF(
                0.00f, 0.00f, 0.00f,
                sUvTSeqExports->func_uvtseq_rom_00400A10((s32) temp_s3->unk28));
        }
    } else {
        sp2F8 = 0xFFF;
    }
    temp_fs0 = var_fv0 - temp_a0;
    sUvGfxStateExports->uvGfxStateSetFlags(temp_s2->unk8);
    sUvGfxStateExports->func_uvgfxstate_rom_00401354(temp_s2->unkC);
    sp14C = sp11C->unkC * sp11C->unk4;
    sp148 = temp_s3->unk14 * sp11C->unk4;
    sp144 = sp11C->unkC / temp_s2->unk10;
    for (var_s4 = 0; var_s4 < temp_s2->unk10; var_s4++) {
        if (sp11C->unk8 == 0) {
            var_fv0 = (temp_s3->unk14 + (sp144 * var_s4)) * sp11C->unk4;
            if (sp14C < var_fv0) {
                var_fv0 -= sp14C;
                if (temp_s3->unk22 != 0) {
                    continue;
                }
            } else if (var_fv0 < 0.000f) {
                var_fv0 = 0.000f;
            }
        } else {
            var_fv0 = sp148;
        }
        temp_a0 = var_fv0;
        temp_v1_2 = (temp_a0 * temp_s2->unk10) + var_s4;
        temp_t1 = temp_v1_2 * sp11C->unk0;
        temp_t2 = (temp_v1_2 + temp_s2->unk10) * sp11C->unk0;
        temp_a3 = &temp_s2->unk30[temp_t1];
        temp_a2 = &temp_s2->unk30[temp_t2];
        spAC = 1.0f - (var_fv0 - temp_a0);
        temp_fs0 = var_fv0 - temp_a0;
        switch (temp_s2->unk1E) {
            default:

            case 1:
                sp2DC[0] = temp_s2->unk16;
                sp2DC[1] = temp_s2->unk18;
                sp2DC[2] = temp_s2->unk1A;
                break;

            case 3:
                sp2DC[0] = (temp_a3[3] * spAC) + (temp_a2[3] * temp_fs0);
                sp2DC[1] = (temp_a3[4] * spAC) + (temp_a2[4] * temp_fs0);
                sp2DC[2] = (temp_a3[5] * spAC) + (temp_a2[5] * temp_fs0);
                sp2DC[0] = (sp2DC[0] * temp_s2->unk16) / 255;
                sp2DC[1] = (sp2DC[1] * temp_s2->unk18) / 255;
                sp2DC[2] = (sp2DC[2] * temp_s2->unk1A) / 255;
                break;

            case 4:
                sp2DC[0] = (temp_a3[3] * spAC) + (temp_a2[3] * temp_fs0);
                sp2DC[1] = (temp_a3[4] * spAC) + (temp_a2[4] * temp_fs0);
                sp2DC[2] = (temp_a3[5] * spAC) + (temp_a2[5] * temp_fs0);
                temp_fv0 = 1.0f - temp_s2->unk20;
                sp2DC[0] = (sp2DC[0] * temp_fv0) + (temp_s2->unk16 * temp_s2->unk20);
                sp2DC[1] = (sp2DC[1] * temp_fv0) + (temp_s2->unk18 * temp_s2->unk20);
                sp2DC[2] = (sp2DC[2] * temp_fv0) + (temp_s2->unk1A * temp_s2->unk20);
                break;

            case 0:
                sp2DC[0] = (temp_a3[3] * spAC) + (temp_a2[3] * temp_fs0);
                sp2DC[1] = (temp_a3[4] * spAC) + (temp_a2[4] * temp_fs0);
                sp2DC[2] = (temp_a3[5] * spAC) + (temp_a2[5] * temp_fs0);
                break;
        }

        var_ft4 = spAC * 0.001f;
        var_ft5 = (var_fv0 - temp_a0) * 0.001f;
        temp_fs1 = (temp_a3[7] * (spAC * 0.001f)) + (temp_a2[7] * ((var_fv0 - temp_a0) * 0.001f));
        if (sp11C->unk0 == 9) {
            temp = spAC * 0.001f;
            var_fs0 = (temp_a3[8] * temp) + (temp_a2[8] * ((var_fv0 - temp_a0) * 0.001f));
        } else {
            var_fs0 = -1.0f;
        }
        if (temp_a2[7] == 0) {
            temp_a2[6] = 0;
            var_ft4 = 0.001f;
            var_ft5 = 0.00f;
        }
        sp2DC[3] = (temp_a3[6] * spAC) + (temp_a2[6] * temp_fs0);
        sp2DC[3] =  MIN(temp_s3->unk26, ((s16) sp2DC[3] * temp_s2->unk1C) * 0.00392f * temp_s3->unk1C * sp12C);
        sp2D0.x = ((temp_a3[0] * var_ft4) + (temp_a2[0] * var_ft5)) + temp_s3->unkC0.x;
        sp2D0.y = ((temp_a3[1] * var_ft4) + (temp_a2[1] * var_ft5)) + temp_s3->unkC0.y;
        sp2D0.z = ((temp_a3[2] * var_ft4) + (temp_a2[2] * var_ft5)) + temp_s3->unkC0.z;
        if (temp_s2->unk6 != 0) {
            sp2D0.x = temp_s3->unk80.m[3][0] + (sp2D0.x * temp_s3->unk70.x);
            sp2D0.y = temp_s3->unk80.m[3][1] + (sp2D0.y * temp_s3->unk70.y);
            sp2D0.z = temp_s3->unk80.m[3][2] + (sp2D0.z * temp_s3->unk70.z);
            temp_fv0 = sUvFMtxExports->func_uvfmtx_rom_00403180(&sp190, &spE4, &sp2D0);
            if (spE4.z < 0.00f) {
                spE4.z = 0.00f;
            }
            if ((!(temp_fv0 < 0.00001)) || (!((-0.00001) < temp_fv0))) {
                var_fv1 = 1.0f / temp_fv0;
            } else {
                var_fv1 = 1.0f;
            }
            temp_fa1 = ((0.5f * temp_fs1) * var_fv1) * sp114;
            spE4.x *= var_fv1;
            spE4.y *= var_fv1;
            spE4.z *= var_fv1;
            temp_s0 = (sp13C + (((spE4.x + 1.0f) * sp114) * 0.5f)) + 0.5f;
            temp_s1 = (sp134 + (((spE4.y + 1.0f) * sp118) * 0.5f)) + 0.5f;
            spF8 = (s32) (temp_s0 + (temp_fa1 * temp_s3->unk70.x));
            if (spF8 < sp13C) {
                continue;
            }
            spF0 = (s32) (temp_s1 + (temp_fa1 * temp_s3->unk70.z));
            if (spF0 < sp134) {
                continue;
            }
            temp_s0 -= temp_fa1 * temp_s3->unk70.x;
            if (sp138 < temp_s0) {
                continue;
            }
            temp_s1 -= temp_fa1 * temp_s3->unk70.z;
            if (sp130 < temp_s1) {
                continue;
            }
            if (sp2F4) {
                sp2F8 = sUvTSeqExports->uvTexSeqGetFrameTexture((s32) temp_s3->unk28, var_s4);
            }
            sUvGfxStateExports->uvGfxStateBindTexture(sp2F8);
            sUvGfxMgrExports->uvGfxSetPrimColor(sp2DC[0], sp2DC[1], sp2DC[2], sp2DC[3]);
            if (temp_s2->unk8 & 0x200000) {
                sUvGfxMgrExports->uvGfxPrimDepth((u32) (spE4.z * 32736.0f));
            }
            sUvGfxStateExports->func_uvgfxstate_rom_00402350(temp_s0, spF8, temp_s1, spF0, 0.000f,
                                                               1.0f, 0.00f, 1.0f);
        } else {
            if (sp11C->unk0 == 9) {
                sUvFvecExports->uvVec3FSub(&sp290, &sp2D0, &sp128[var_s4]);
                sUvFvecExports->uvVec3FNormalize(&sp290, &sp290);
                sUvFvecExports->uvVec3FScale(&sp2B4, &sp290, temp_s2->unk12 * var_fs0);
                if (temp_s2->unk24 == 1) {
                    sUvFvecExports->uvVec3FSet(&spC0, 0.000f, 0.000f, 1);
                    sUvFvecExports->uvVec3FCross(&sp29C, &sp290, &spC0);
                } else {
                    sUvFvecExports->uvVec3FCross(&sp29C, &sp290, &sp2A8);
                }
                sUvFvecExports->uvVec3FNormalize(&sp29C, &sp29C);
                sUvFvecExports->uvVec3FScale(&sp29C, &sp29C, temp_s2->unk12);
                sUvFvecExports->uvVec3FCopy(&sp128[var_s4], &sp2D0);
            }
            sUvFvecExports->uvVec3FScale(&sp2D0, &sp2D0, temp_s2->unk12);
            if (sp2F4 != 0) {
                sp2F8 = sUvTSeqExports->uvTexSeqGetFrameTexture((s32) temp_s3->unk28, var_s4);
            }
            sUvGfxStateExports->uvGfxStateBindTexture(sp2F8);
            if (temp_s3->unk6E != 0) {
                var_fv0_2 = -temp_fs1;
            } else {
                var_fv0_2 = temp_fs1;
            }
            func_uvpfx_rom_00404A60(&sp2D0, &sp2B4, &sp29C, var_fv0_2, temp_fs1,
                                    temp_s3->unk32[var_s4 % 4], sp2DC);
        }
    }

    if (temp_s2->unk6 != 0) {
        sUvGfxMgrExports->uvGfxSetDepthSource(0);
    }
    sUvFMtxExports->uvGfxMtxFViewPop();
}

void func_uvpfx_rom_0040374C(s32 arg0) {
    UnkStruct_uvpfx_rom_00404FA0* temp_v0;
    UnkStruct_uvpfx_rom_00404FA0_unk0* temp_s2;
    UnkStruct_uvpfx_rom_00404FA0_unk4* temp_v1;
    Vec3F* var_s1;
    s32 i;

    temp_s2 = D_uvpfx_rom_00404FA0[arg0].unk0;
    temp_v1 = D_uvpfx_rom_00404FA0[arg0].unk4;
    var_s1 = D_uvpfx_rom_00404FA0[arg0].unk8;
    temp_v1->unk22 = -1;
    temp_v1->unk14 = 0.0f;
    
    for (i = 0; i < temp_s2->unk28->unk0; i++) {
        sUvFvecExports->uvVec3FSet(&var_s1[i], 0, 0, 0);
    }
}

void func_uvpfx_rom_0040381C(s32 arg0, f32 arg1) {
    UnkStruct_uvpfx_rom_00404FA0_unk0* v0;
    UnkStruct_uvpfx_rom_00404FA0_unk28* v1;

    v0 = D_uvpfx_rom_00404FA0[arg0].unk0;
    v1 = v0->unk28;
    v1->unk18 = arg1;
}

void func_uvpfx_rom_00403848(s32 arg0, s32 arg1, s16 arg2) {
    UnkStruct_uvpfx_rom_00404FA0_unk0* v0;
    UnkStruct_uvpfx_rom_00404FA0_unk28* temp_v1;
    s16 temp_a3;

    v0 = D_uvpfx_rom_00404FA0[arg0].unk0;
    temp_v1 = v0->unk28;
    if (arg2 < temp_v1->unk0) {
        temp_v1->unk8 = arg2;
    } else {
        temp_v1->unk8 = temp_v1->unk0;
    }
    temp_v1->unk4 = arg1;
}


void func_uvpfx_rom_00403898(s32 arg0) {
    UnkStruct_uvpfx_rom_00404FA0* temp_v0;
    UnkStruct_uvpfx_rom_00404FA0_unk0* temp_t0;
    UnkStruct_uvpfx_rom_00404FA0_unk4* temp_s3;
    UnkStruct_uvpfx_rom_00404FA0_unk28* sp38;
    Vec3F* temp_s6;
    f32 temp_fv0;
    s16 i;

    temp_fv0 = sUvGfxMgrExports->func_uvgfxmgr_rom_00401004();
    temp_s3 = D_uvpfx_rom_00404FA0[arg0].unk4;
    temp_s6 = D_uvpfx_rom_00404FA0[arg0].unk8;
    sp38 = D_uvpfx_rom_00404FA0[arg0].unk0->unk28;
    if (temp_s3->unk22 == -1) {
        temp_s3->unk22 = 0;
        temp_s3->unk20 = 0;
        temp_s3->unkCC.x = temp_s3->unk80.m[3][0];
        temp_s3->unkCC.y = temp_s3->unk80.m[3][1];
        temp_s3->unkCC.z = temp_s3->unk80.m[3][2];
        return;
    }
    if ((temp_s3->unk22 < sp38->unk0) && (temp_s3->unk20 == 0)) {
        temp_s3->unk22++;
    }
    temp_s3->unkCC.x -= temp_s3->unk80.m[3][0] - (temp_s3->unkD8 * temp_fv0);
    temp_s3->unkCC.y -= temp_s3->unk80.m[3][1] - (temp_s3->unkDC * temp_fv0);
    temp_s3->unkCC.z -= temp_s3->unk80.m[3][2] - (temp_s3->unkE0 * temp_fv0);

    for (i = temp_s3->unk22 - 1; i > 0; i--) {
        sUvFvecExports->uvVec3FCopy(&temp_s6[i], &temp_s6[i - 1]);
        sUvFvecExports->uvVec3FAdd(&temp_s6[i], &temp_s6[i], (Vec3F* ) &temp_s3->unkCC);
    }
    sUvFvecExports->uvVec3FSet(temp_s6, 0, 0, 0.0f);
    temp_s3->unkCC.x = temp_s3->unk80.m[3][0];
    temp_s3->unkCC.y = temp_s3->unk80.m[3][1];
    temp_s3->unkCC.z = temp_s3->unk80.m[3][2];
    temp_s3->unk14 += temp_s3->unk18;
    if ((sp38->unk0 - 1) <= temp_s3->unk14) {
        temp_s3->unk14 = temp_s3->unk14 - (sp38->unk0 - 1);
    }
}

void func_uvpfx_rom_00403AC8(s32 arg0, s32 arg1) {
    UnkStruct_uvpfx_rom_00404FA0_unk0 *temp_s3;
    s32 sp2D0;
    s32 sp2CC;
    UnkStruct_uvpfx_rom_00404FA0_unk28 *temp_s7;
    Vec3F sp2BC;
    Vec3F sp2B0;
    Vec3F sp2A4;
    Vec3F sp298;
    UnkStruct_uvpfx_rom_00404FA0_unk4 *temp_s2;
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_fs0;
    f32 temp_ft0;
    f32 sp280;
    s16 sp274[6];
    Mtx4F sp234;
    Mtx4F sp1F4;
    Mtx4F sp1B4;
    Mtx4F sp174;
    Mtx4F sp134;
    f32 temp_ft1;
    f32 sp12C;
    f32 sp128;
    f32 temp_ft4;
    f32 temp_fv0;
    f32 temp_fv1;
    s32 sp118;
    s32 sp114;
    s32 sp110;
    s32 sp10C;
    s32 sp108;
    s32 sp104;
    Vec3F *sp100;
    f32 var_fs1;
    f32 var_fv0;
    f32 var_fv0_2;
    f32 var_fv1;
    s16 temp_a0;
    Vec3F spE0;
    s32 temp_s0;
    s32 spD8;
    s32 temp_s1;
    s32 spD0;
    s16 temp_ft2;
    s16 temp_ft3;
    s16 i;
    f32 *temp_v0_4;
    s32 pad[1];

    sp2CC = 0;
    sp12C = 1.0f;
    temp_s3 = D_uvpfx_rom_00404FA0[arg0].unk0;
    temp_s2 = D_uvpfx_rom_00404FA0[arg0].unk4;
    sp100 = D_uvpfx_rom_00404FA0[arg0].unk8;
    temp_s7 = temp_s3->unk28;
    if (temp_s2->unk22 < 2) {
        return;
    }

    if (temp_s3->unk6 != 0) {
        sUvGfxMgrExports->uvGfxSetDepthSource(1);
        sUvChannelExports->func_uvchannel_rom_00400288(arg1, 5, &sp118, &sp114, &sp110, &sp10C, 1,
                                                          &sp234, 2, &sp174, 3, &sp1B4, 0);
        sUvFMtxExports->uvMat4RotateAxis(&sp234, -1.5707963f, 'x');
        sUvFMtxExports->uvMat4Mul(&sp1F4, &sp234, &sp174);
        sp104 = sp10C - sp110;
        sp108 = sp114 - sp118;
    } else {
        sUvChannelExports->func_uvchannel_rom_00400288(arg1, 3, &sp1B4, 0);
        sUvFMtxExports->uvMat4InvertTranslationRotation(&sp174, &temp_s2->unk80);
        sUvFMtxExports->uvMat4Mul(&sp174, &sp174, &sp1B4);
    }
    sp2A4.x = temp_s2->unk80.m[3][0] - sp1B4.m[3][0];
    sp2A4.y = temp_s2->unk80.m[3][1] - sp1B4.m[3][1];
    sp2A4.z = temp_s2->unk80.m[3][2] - sp1B4.m[3][2];
    temp_fv0 = sUvFvecExports->uvVec3FLen(&sp2A4);
    if ((temp_fv0 < 0.1f)) {
        return;
    }

    if ((temp_s2->unk7C < temp_fv0)) {
        return;
    }
    temp_fa0 = temp_s2->unk7C * 0.8f;
    if (temp_fa0 < temp_fv0) {
        sp12C = (temp_s2->unk7C - temp_fv0) / (temp_s2->unk7C - temp_fa0);
    }
    // FAKE
    if (1) {}

    sp2A4.x *= 1.0f / temp_fv0;
    sp2A4.y *= 1.0f / temp_fv0;
    sp2A4.z *= 1.0f / temp_fv0;
    if (temp_s3->unk6 == 0) {
        if (temp_s3->unk24 == 1) {
            sUvFvecExports->uvVec3FSet(&sp2B0, 0.0f, 1.0f, 0.0f);
            sUvFvecExports->uvVec3FSet(&sp298, 1.0f, 0, 0.0f);
            sUvFvecExports->uvVec3FMult(&sp2B0, &sp2B0, &temp_s2->unk70);
            sUvFvecExports->uvVec3FScale(&sp2B0, &sp2B0, (f32) temp_s3->unk12);
            sUvFvecExports->uvVec3FMult(&sp298, &sp298, &temp_s2->unk70);
            sUvFvecExports->uvVec3FScale(&sp298, &sp298, (f32) temp_s3->unk12);
        } else if (temp_s3->unk24 == 0) {
            sUvFvecExports->uvVec3FSet(&sp2B0, 0.0f, 0.0f, 1.0f);
            sUvFMtxExports->func_uvfmtx_rom_004030FC(&sp174, &sp2B0, &sp2B0);
            sUvFvecExports->uvVec3FNormalize(&sp2B0, &sp2B0);
            sUvFvecExports->uvVec3FSet(&sp298, 1.0f, 0, 0.0f);
            sUvFMtxExports->func_uvfmtx_rom_004030FC(&sp174, &sp298, &sp298);
            sUvFvecExports->uvVec3FNormalize(&sp298, &sp298);
            sUvFvecExports->uvVec3FMult(&sp2B0, &sp2B0, &temp_s2->unk70);
            sUvFvecExports->uvVec3FScale(&sp2B0, &sp2B0, (f32) temp_s3->unk12);
            sUvFvecExports->uvVec3FMult(&sp298, &sp298, &temp_s2->unk70);
            sUvFvecExports->uvVec3FScale(&sp298, &sp298, (f32) temp_s3->unk12);
        }
        sUvFMtxExports->uvMat4SetIdentity(&sp134);
        sUvFMtxExports->uvMat4Scale(&sp134, 1.0f / temp_s3->unk12, 1.0f / temp_s3->unk12, 1.0f / temp_s3->unk12);
        sp134.m[3][0] = temp_s2->unk80.m[3][0];
        sp134.m[3][1] = temp_s2->unk80.m[3][1];
        sp134.m[3][2] = temp_s2->unk80.m[3][2];
        sUvFMtxExports->func_uvfmtx_rom_00400370(&sp134, &sp134);
        sUvFMtxExports->uvGfxMtxViewLoad(&sp134, 1U);
    }
    if (temp_s2->unk2C != 0xFFF) {
        sp2D0 = (s32) temp_s2->unk2C;
    } else {
        if (temp_s2->unk28 != 0xFF) {
            if (temp_s2->unk2A & 1) {
                sp2D0 = sUvTSeqExports->uvTexSeqGetCurFrameTexture(temp_s2->unk28);
            } else {
                sp2CC = 1;
            }
            if (temp_s2->unk2A & 4) {
                sUvGfxMgrExports->uvGfxSetEnvColorF(
                    0.0f, 0.0f, 0.0f,
                    sUvTSeqExports->func_uvtseq_rom_00400A10((s32) temp_s2->unk28));
            }
        } else {
            sp2D0 = 0xFFF;
        }
    }
    sUvGfxStateExports->uvGfxStateSetFlags(temp_s3->unk8);
    sUvGfxStateExports->func_uvgfxstate_rom_00401354(temp_s3->unkC);
    sp280 = (temp_s7->unk0 - 1) / (f32) temp_s3->unk10;
    for (i = 0; i < temp_s3->unk10; i++) {
        var_fv0 = temp_s2->unk14 + (sp280 * i);
        if (var_fv0 >= (temp_s7->unk0 - 1)) {
            var_fv0 -= (temp_s7->unk0 - 1);
        }
        temp_ft2 = var_fv0;
        temp_fs0 = var_fv0 / temp_s2->unk22;
        temp_fv1 = var_fv0 - temp_ft2;
        temp_fa1 = 1.0f - temp_fv1;
        if ((s32)var_fv0 < (temp_s2->unk22 - 1)) {
            if (temp_ft2 < (temp_s7->unk8 - 1)) {
                temp_v0_4 = &temp_s7->unk4[temp_ft2];
                var_fs1 = ((temp_v0_4[0] * temp_fa1) + (temp_v0_4[1] * temp_fv1)) * (0.01f * temp_s7->unkA);
            } else {
                var_fs1 = temp_s7->unkA * 0.01f;
            }

            sp2BC.x = (sp100[temp_ft2].x * temp_fa1) + (sp100[temp_ft2 + 1].x * temp_fv1)
                    + temp_s2->unkC0.x;
            sp2BC.y = (sp100[temp_ft2].y * temp_fa1) + (sp100[temp_ft2 + 1].y * temp_fv1)
                    + temp_s2->unkC0.y;
            sp2BC.z = (sp100[temp_ft2].z * temp_fa1) + (sp100[temp_ft2 + 1].z * temp_fv1)
                    + temp_s2->unkC0.z;
            sUvFvecExports->uvVec3FAddScaled(&sp2BC, &sp2BC,
                                                   temp_s7->unk18 * temp_fs0,
                                                   &D_uvpfx_rom_00404FB0[i]);
            if (temp_s3->unk24 == 2) {
                sUvFvecExports->uvVec3FSub(&sp2B0, &sp100[temp_ft2], &sp100[temp_ft2 + 1]);
                sUvFvecExports->uvVec3FCross(&sp298, &sp2B0, &sp2A4);
                sUvFvecExports->uvVec3FNormalize(&sp298, &sp298);
                sUvFvecExports->uvVec3FMult(&sp2B0, &sp2B0, &temp_s2->unk70);
                sUvFvecExports->uvVec3FMult(&sp298, &sp298, &temp_s2->unk70);
                sUvFvecExports->uvVec3FScale(&sp2B0, &sp2B0, temp_s3->unk12);
                sUvFvecExports->uvVec3FScale(&sp298, &sp298, temp_s3->unk12);
            }
            var_fv1 = 3.0f * temp_fs0;
            if (var_fv1 > 1.0f) {
                var_fv1 = 1.0f;
            }

            sp274[0] = ((temp_s3->unk16 * var_fv1) + (temp_s7->unkE * (1.0f - var_fv1)));
            sp274[1] = ((temp_s3->unk18 * var_fv1) + (temp_s7->unk10 * (1.0f - var_fv1)));
            sp274[2] = ((temp_s3->unk1A * var_fv1) + (temp_s7->unk12 * (1.0f - var_fv1)));
            sp274[3] = ((1.0f - temp_fs0)
                              * ((temp_s3->unk1C * var_fv1) + (temp_s7->unk14 * (1.0f - var_fv1)))
                              * temp_s2->unk1C * sp12C);
            if (temp_s2->unk26 < sp274[3]) {
                sp274[3] = temp_s2->unk26;
            }
            sp128 = temp_s7->unkC * 0.01f * var_fs1;
            if (temp_s3->unk6 != 0) {
                sp2BC.x = sp2BC.x + temp_s2->unk80.m[3][0];
                sp2BC.y = sp2BC.y + temp_s2->unk80.m[3][1];
                sp2BC.z = sp2BC.z + temp_s2->unk80.m[3][2];
                temp_fv0 =
                    sUvFMtxExports->func_uvfmtx_rom_00403180(&sp1F4, &spE0, &sp2BC);
                if (spE0.z < 0.0f) {
                    spE0.z = 0.0f;
                }
                if (temp_fv0 != 0.0f) {
                    var_fv1 = 1.0f / temp_fv0;
                } else {
                    var_fv1 = 1.0f;
                }
                temp_fa0 = var_fs1 * 0.5 * var_fv1 * sp108;
                spE0.x *= var_fv1;
                spE0.y *= var_fv1;
                spE0.z *= var_fv1;
                temp_s0 = (sp118 + ((spE0.x + 1.0f) * sp108 * 0.5f) + 0.5f);
                temp_s1 = (sp110 + ((spE0.y + 1.0f) * sp104 * 0.5f) + 0.5f);

                spD8 = (temp_s0 + (temp_fa0 * temp_s2->unk70.x));
                if (spD8 < sp118) {
                    continue;
                }

                spD0 = (temp_s1 + (temp_fa0 * temp_s2->unk70.z));
                if (spD0 < sp110) {
                    continue;
                }
                temp_s0 = (temp_s0 - (temp_fa0 * temp_s2->unk70.x));
                if (sp114 < temp_s0) {
                    continue;
                }
                temp_s1 = (temp_s1 - (temp_fa0 * temp_s2->unk70.z));
                if (sp10C < temp_s1) {
                    continue;
                }
                if (sp2CC != 0) {
                    sp2D0 = sUvTSeqExports->uvTexSeqGetFrameTexture((s32) temp_s2->unk28, i);
                }
                sUvGfxStateExports->uvGfxStateBindTexture(sp2D0);
                sUvGfxMgrExports->uvGfxSetPrimColor(sp274[0], sp274[1], sp274[2], sp274[3]);
                if (temp_s3->unk8 & 0x200000) {
                    sUvGfxMgrExports->uvGfxPrimDepth( (u32) (spE0.z * 32736.0f));
                }
                sUvGfxStateExports->func_uvgfxstate_rom_00402350(temp_s0, spD8, temp_s1, spD0,
                                                                   0, 1.0f, 0.0f, 1.0f);

            } else {
                sUvFvecExports->uvVec3FScale(&sp2BC, &sp2BC, temp_s3->unk12);
                if (sp2CC != 0) {
                    sp2D0 = sUvTSeqExports->uvTexSeqGetFrameTexture((s32) temp_s2->unk28, i);
                }
                sUvGfxStateExports->uvGfxStateBindTexture(sp2D0);
                if (temp_s2->unk6E != 0) {
                    var_fv0_2 = -sp128;
                } else {
                    var_fv0_2 = sp128;
                }
                func_uvpfx_rom_00404A60(&sp2BC, &sp2B0, &sp298, var_fv0_2, var_fs1,
                                        temp_s2->unk32[i % 4], sp274);
            }
        }
    }
    sUvFMtxExports->uvGfxMtxFViewPop();
    if (temp_s3->unk6 != 0) {
        sUvGfxMgrExports->uvGfxSetDepthSource(0);
    }
}

void func_uvpfx_rom_00404A60(Vec3F* arg0, Vec3F* arg1, Vec3F* arg2, f32 arg3, f32 arg4, s16* arg5, s16* arg6) {
    s16 vtxPoints[9];
    f32 temp_ft5;
    f32 temp_ft4;
    f32 temp_ft2;
    f32 temp_fa1;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 temp_fv1;

    temp_ft4 = (arg1->x * (-0.5f * arg3));
    temp_ft5 = arg1->y * (-0.5f * arg3);
    temp_fv1 = 0.866f * arg4;
    sp50 = arg1->z * (-0.5f * arg3);
    sp4C = arg2->x * temp_fv1;
    sp48 = arg2->y * temp_fv1;
    sp44 = arg2->z * temp_fv1;
    vtxPoints[0] = (arg0->x + (arg1->x * arg3));
    vtxPoints[1] = (arg0->y + (arg1->y * arg3));
    vtxPoints[2] = (arg0->z + (arg1->z * arg3));
    vtxPoints[3] = (arg0->x + temp_ft4 + sp4C);
    vtxPoints[4] = (arg0->y + temp_ft5 + sp48);
    vtxPoints[5] = (arg0->z + sp50 + sp44);
    vtxPoints[6] = ((arg0->x + temp_ft4) - sp4C);
    vtxPoints[7] = ((arg0->y + temp_ft5) - sp48);
    vtxPoints[8] = ((arg0->z + sp50) - sp44);

    sUvGfxMgrExports->uvGfxSetPrimColor(arg6[0], arg6[1], arg6[2], arg6[3]);
    sUvDGeomExports->uvVtxBeginPoly();
    sUvDGeomExports->uvVtx(vtxPoints[0], vtxPoints[1], vtxPoints[2], arg5[0], arg5[1], arg6[0], arg6[1], arg6[2], arg6[3]);
    sUvDGeomExports->uvVtx(vtxPoints[3], vtxPoints[4], vtxPoints[5], arg5[2], arg5[3], arg6[0], arg6[1], arg6[2], arg6[3]);
    sUvDGeomExports->uvVtx(vtxPoints[6], vtxPoints[7], vtxPoints[8], arg5[4], arg5[5], arg6[0], arg6[1], arg6[2], arg6[3]);
    sUvDGeomExports->uvVtxEndPoly();
}

void func_uvpfx_rom_00404D2C(void) {

}
