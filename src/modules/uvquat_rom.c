// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"

void __entrypoint_func_uvquat_rom_400000(UvQuat_Exports *exports);
void func_uvquat_rom_004000A8(void);
void func_uvquat_rom_004000D8(UnkStruct_uvquat_rom_004000D8_Arg0_s *arg0,
                              UnkStruct_uvquat_rom_004000D8_Arg1_s *arg1);
void func_uvquat_rom_00400384(UnkStruct_uvquat_rom_004000D8_Arg0_s *arg0, f32 arg1, f32 arg2, f32 arg3);
void func_uvquat_rom_00400524(Mtx4F *arg0, UnkStruct_uvquat_rom_004000D8_Arg0_s *arg1);
void func_uvquat_rom_0040070C(UnkStruct_uvquat_rom_004000D8_Arg0_s *arg0,
                              UnkStruct_uvquat_rom_004000D8_Arg0_s *arg1, f32 arg2, f32 arg3, f32 arg4,
                              f32 arg5);
void func_uvquat_rom_0040087C(UnkStruct_uvquat_rom_004000D8_Arg0_s *arg0,
                              UnkStruct_uvquat_rom_004000D8_Arg0_s *arg1,
                              UnkStruct_uvquat_rom_004000D8_Arg0_s *arg2);
void func_uvquat_rom_00400998(UnkStruct_uvquat_rom_004000D8_Arg0_s *arg0,
                              UnkStruct_uvquat_rom_004000D8_Arg0_s *arg1);
void func_uvquat_rom_00400998(UnkStruct_uvquat_rom_004000D8_Arg0_s *arg0,
                              UnkStruct_uvquat_rom_004000D8_Arg0_s *arg1);
void func_uvquat_rom_004009BC(UnkStruct_uvquat_rom_004000D8_Arg0_s *arg0,
                              UnkStruct_uvquat_rom_004000D8_Arg0_s *arg1,
                              UnkStruct_uvquat_rom_004000D8_Arg0_s *arg2, f32 arg3);


// .bss
extern UvMath_Exports *D_uvquat_rom_00400B50;
extern UvFMtx_Rom_Exports *D_uvquat_rom_00400B54;
extern Mtx4F D_uvquat_rom_00400B58;

void __entrypoint_func_uvquat_rom_400000(UvQuat_Exports *exports) {
    uvSetFileDirOvlPtr((s32) exports);
    exports->func_uvquat_rom_004000A8 = func_uvquat_rom_004000A8;
    exports->func_uvquat_rom_004000D8 = func_uvquat_rom_004000D8;
    exports->func_uvquat_rom_00400384 = func_uvquat_rom_00400384;
    exports->func_uvquat_rom_00400524 = func_uvquat_rom_00400524;
    exports->func_uvquat_rom_0040070C = func_uvquat_rom_0040070C;
    exports->func_uvquat_rom_0040087C = func_uvquat_rom_0040087C;
    exports->func_uvquat_rom_00400998 = func_uvquat_rom_00400998;
    exports->func_uvquat_rom_004009BC = func_uvquat_rom_004009BC;
#line 1
    D_uvquat_rom_00400B50 = uvLoadModule('MATH');
    D_uvquat_rom_00400B54 = uvLoadModule('FMTX');
}

void func_uvquat_rom_004000A8(void) {
    uvUnloadModule('MATH');
    uvUnloadModule('FMTX');
}

void func_uvquat_rom_004000D8(UnkStruct_uvquat_rom_004000D8_Arg0_s *arg0,
                              UnkStruct_uvquat_rom_004000D8_Arg1_s *arg1) {
    f32 temp_fa1;
    f32 temp_ft5;
    f32 temp_fv0_2;
    f32 temp_fv1_2;
    s32 var_v0;

    temp_ft5 = arg1->unk0[1][1] + arg1->unk0[0][0];
    temp_fa1 = arg1->unk20[2] + temp_ft5;
    if (temp_fa1 >= 0.0f) {
        temp_fv0_2 = D_uvquat_rom_00400B50->uvSqrtf(temp_fa1 + 1.0f);
        temp_fv1_2 = 0.5f / temp_fv0_2;
        arg0->unkC = temp_fv0_2 * 0.5f;
        arg0->unk0 = (arg1->unk20[1] - arg1->unk0[1][2]) * temp_fv1_2;
        arg0->unk4 = (arg1->unk0[0][2] - arg1->unk20[0]) * temp_fv1_2;
        arg0->unk8 = (arg1->unk0[1][0] - arg1->unk0[0][1]) * temp_fv1_2;
        return;
    }
    var_v0 = 0;
    if (arg1->unk0[0][0] < arg1->unk0[1][1]) {
        var_v0 = 1;
    }
    if (arg1->unk0[var_v0][var_v0] < arg1->unk20[2]) {
        var_v0 = 2;
    }
    switch (var_v0) { /* irregular */
        case 0:
            temp_fv0_2 = D_uvquat_rom_00400B50->uvSqrtf(
                (arg1->unk0[0][0] - (arg1->unk0[1][1] + arg1->unk20[2])) + 1.0f);
            temp_fv1_2 = 0.5f / temp_fv0_2;
            arg0->unk0 = temp_fv0_2 * 0.5f;
            arg0->unk4 = (arg1->unk0[0][1] + arg1->unk0[1][0]) * temp_fv1_2;
            arg0->unk8 = (arg1->unk20[0] + arg1->unk0[0][2]) * temp_fv1_2;
            arg0->unkC = (arg1->unk20[1] - arg1->unk0[1][2]) * temp_fv1_2;
            return;
        case 1:
            temp_fv0_2 = D_uvquat_rom_00400B50->uvSqrtf(
                (arg1->unk0[1][1] - (arg1->unk20[2] + arg1->unk0[0][0])) + 1.0f);
            temp_fv1_2 = 0.5f / temp_fv0_2;
            arg0->unk4 = temp_fv0_2 * 0.5f;
            arg0->unk8 = (arg1->unk0[1][2] + arg1->unk20[1]) * temp_fv1_2;
            arg0->unk0 = (arg1->unk0[0][1] + arg1->unk0[1][0]) * temp_fv1_2;
            arg0->unkC = (arg1->unk0[0][2] - arg1->unk20[0]) * temp_fv1_2;
            return;
        case 2:
            temp_fv0_2 = D_uvquat_rom_00400B50->uvSqrtf((arg1->unk20[2] - temp_ft5) + 1.0f);
            temp_fv1_2 = 0.5f / temp_fv0_2;
            arg0->unk8 = temp_fv0_2 * 0.5f;
            arg0->unk0 = (arg1->unk20[0] + arg1->unk0[0][2]) * temp_fv1_2;
            arg0->unk4 = (arg1->unk0[1][2] + arg1->unk20[1]) * temp_fv1_2;
            arg0->unkC = (arg1->unk0[1][0] - arg1->unk0[0][1]) * temp_fv1_2;
            return;
    }
}

void func_uvquat_rom_00400384(UnkStruct_uvquat_rom_004000D8_Arg0_s *arg0, f32 arg1, f32 arg2,
                              f32 arg3) {
    f32 temp_ft4;
    f32 sp58;
    f32 temp_fa1;
    f32 temp_fs0;
    f32 sp4C;
    f32 sp48;
    f32 temp_fs1;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 pad;
    f32 temp_fa0;

    temp_fs0 = (arg1 + 1.5707963f) * 0.5f;
    temp_fs1 = D_uvquat_rom_00400B50->uvSinF(temp_fs0);
    temp_fs0 = D_uvquat_rom_00400B50->uvCosF(temp_fs0);
    temp_fa0 = -arg2 * 0.5f;
    sp4C = D_uvquat_rom_00400B50->uvSinF(temp_fa0);
    sp58 = D_uvquat_rom_00400B50->uvCosF(temp_fa0);

    sp48 = D_uvquat_rom_00400B50->uvSinF(((arg3 - 3.1415927f) * 0.5f));
    temp_fv0 = D_uvquat_rom_00400B50->uvCosF(((arg3 - 3.1415927f) * 0.5f));
    temp_fv1 = sp4C * sp48;
    temp_fa0 = sp4C * temp_fv0;
    temp_fa1 = sp58 * temp_fv0;
    temp_ft4 = sp58 * sp48;

    arg0->unk0 = (temp_fs0 * temp_fa1) + (temp_fs1 * temp_fv1);
    arg0->unk4 = (temp_fs0 * temp_ft4) - (temp_fs1 * temp_fa0);
    arg0->unk8 = (temp_fs0 * temp_fa0) + (temp_fs1 * temp_ft4);
    arg0->unkC = (-temp_fs0 * temp_fv1) + (temp_fs1 * temp_fa1);
}

void func_uvquat_rom_00400524(Mtx4F *arg0, UnkStruct_uvquat_rom_004000D8_Arg0_s *arg1) {
    f32 sp44;
    f32 sp40;
    f32 temp_ft5;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    static s32 firstTime = FALSE;

    if (!firstTime) {
        firstTime = TRUE;
        D_uvquat_rom_00400B54->func_00402B30(&D_uvquat_rom_00400B58, -1.5707964f, 0.0f, 3.1415927f);
    }

    sp44 = SQ(arg1->unk0);
    sp40 = SQ(arg1->unk4);
    temp_ft5 = SQ(arg1->unk8);
    sp38 = SQ(arg1->unkC);
    sp30 = arg1->unk4 * arg1->unk0;
    sp24 = arg1->unk8 * arg1->unk0;
    sp34 = arg1->unkC * arg1->unk0;
    sp2C = arg1->unk8 * arg1->unk4;
    sp28 = arg1->unkC * arg1->unk4;
    sp20 = arg1->unkC * arg1->unk8;

    arg0->m[0][0] = ((sp44 + sp40) - temp_ft5) - sp38;
    arg0->m[0][1] = 2.0f * (sp2C + sp34);
    arg0->m[0][2] = 2.0f * (sp28 - sp24);
    arg0->m[0][3] = 0.0f;
    arg0->m[1][0] = 2.0f * (sp2C - sp34);
    arg0->m[1][1] = ((sp44 - sp40) + temp_ft5) - sp38;
    arg0->m[1][2] = 2.0f * (sp20 + sp30);
    arg0->m[1][3] = 0.0f;
    arg0->m[2][0] = 2.0f * (sp24 + sp28);
    arg0->m[2][1] = 2.0f * (sp20 - sp30);
    arg0->m[2][2] = ((sp44 - sp40) - temp_ft5) + sp38;
    arg0->m[2][3] = 0.0f;
    arg0->m[3][0] = 0.0f;
    arg0->m[3][1] = 0.0f;
    arg0->m[3][2] = 0.0f;
    arg0->m[3][3] = 1.0f;
    D_uvquat_rom_00400B54->func_00400BB8(arg0, arg0, &D_uvquat_rom_00400B58);
}

static s32 unused[] = { 0x00200000, &__entrypoint_func_uvquat_rom_400000, 0 };

void func_uvquat_rom_0040070C(UnkStruct_uvquat_rom_004000D8_Arg0_s *arg0,
                              UnkStruct_uvquat_rom_004000D8_Arg0_s *arg1, f32 arg2, f32 arg3, f32 arg4,
                              f32 arg5) {
    f32 temp_ft4;

    temp_ft4 =
        (1.0f - (SQ(arg1->unkC) + (SQ(arg1->unk0) + SQ(arg1->unk4) + SQ(arg1->unk8)))) * (0.99f / arg5);
    arg0->unk0 = (arg1->unk0 * temp_ft4)
                 + (-0.5f * ((arg1->unk4 * arg4) + (arg1->unk8 * arg3) + (arg1->unkC * arg2)));
    arg0->unk4 = (arg1->unk4 * temp_ft4)
                 + (0.5f * (((arg1->unk0 * arg4) - (arg1->unkC * arg3)) + (arg1->unk8 * arg2)));
    arg0->unk8 = (arg1->unk8 * temp_ft4)
                 + (0.5f * (((arg1->unkC * arg4) + (arg1->unk0 * arg3)) - (arg1->unk4 * arg2)));
    arg0->unkC = (arg1->unkC * temp_ft4)
                 + (0.5f * ((-arg1->unk8 * arg4) + (arg1->unk4 * arg3) + (arg1->unk0 * arg2)));
}

void func_uvquat_rom_0040087C(UnkStruct_uvquat_rom_004000D8_Arg0_s *arg0,
                              UnkStruct_uvquat_rom_004000D8_Arg0_s *arg1,
                              UnkStruct_uvquat_rom_004000D8_Arg0_s *arg2) {
    UnkStruct_uvquat_rom_004000D8_Arg0_s quat;

    quat.unk0 = ((arg1->unkC * arg2->unk0) + (arg1->unk0 * arg2->unkC) + (arg1->unk4 * arg2->unk8))
                - (arg2->unk4 * arg1->unk8);
    quat.unk4 = ((arg1->unkC * arg2->unk4) + (arg1->unk4 * arg2->unkC) + (arg1->unk8 * arg2->unk0))
                - (arg2->unk8 * arg1->unk0);
    quat.unk8 = ((arg1->unkC * arg2->unk8) + (arg1->unk8 * arg2->unkC) + (arg1->unk0 * arg2->unk4))
                - (arg2->unk0 * arg1->unk4);
    quat.unkC = (((arg1->unkC * arg2->unkC) - (arg1->unk0 * arg2->unk0)) - (arg1->unk4 * arg2->unk4))
                - (arg2->unk0 * arg1->unk8);
    func_uvquat_rom_00400998(arg0, (UnkStruct_uvquat_rom_004000D8_Arg0_s *) &quat);
}

// uvQuatCopy
void func_uvquat_rom_00400998(UnkStruct_uvquat_rom_004000D8_Arg0_s *arg0,
                              UnkStruct_uvquat_rom_004000D8_Arg0_s *arg1) {
    arg0->unk0 = arg1->unk0;
    arg0->unk4 = arg1->unk4;
    arg0->unk8 = arg1->unk8;
    arg0->unkC = arg1->unkC;
}

void func_uvquat_rom_004009BC(UnkStruct_uvquat_rom_004000D8_Arg0_s *arg0,
                              UnkStruct_uvquat_rom_004000D8_Arg0_s *arg1,
                              UnkStruct_uvquat_rom_004000D8_Arg0_s *arg2, f32 arg3) {
    f32 temp_fv0;
    f32 var_fv1;

    var_fv1 = ((arg2->unkC * arg1->unkC)
               + ((arg1->unk0 * arg2->unk0) + (arg1->unk4 * arg2->unk4) + (arg1->unk8 * arg2->unk8)));
    temp_fv0 = (1.0f - arg3);
    if (var_fv1 < 0) {
        arg3 = -arg3;
    }

    arg0->unk0 = (f32) ((arg2->unk0 * arg3) + (arg1->unk0 * temp_fv0));
    arg0->unk4 = (f32) ((arg2->unk4 * arg3) + (arg1->unk4 * temp_fv0));
    arg0->unk8 = (f32) ((arg2->unk8 * arg3) + (arg1->unk8 * temp_fv0));
    arg0->unkC = (f32) ((arg2->unkC * arg3) + (arg1->unkC * temp_fv0));

    temp_fv0 = D_uvquat_rom_00400B50->uvSqrtf(SQ(arg0->unkC)
                                              + (SQ(arg0->unk0) + SQ(arg0->unk4) + SQ(arg0->unk8)));
    if (temp_fv0 == 0.0f) {
        return;
    }

    arg0->unk0 /= temp_fv0;
    arg0->unk4 /= temp_fv0;
    arg0->unk8 /= temp_fv0;
    arg0->unkC /= temp_fv0;
}
