// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "uvasset_types.h"

void func_uvgui_rom_00400498(void);
void func_uvgui_rom_00400510(UnkStruct_uvgui_rom_00400510 *arg0);
void func_uvgui_rom_004006B8(UnkStruct_uvgui_rom_00400510 *arg0,
                             UnkStruct_uvgui_rom_00400510_unk0 *arg1);
void func_uvgui_rom_00400754(UnkStruct_uvgui_rom_00400510 *arg0);
void func_uvgui_rom_00400990(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, u8 arg5, u8 arg6,
                             u8 arg7, u8 arg8);
void func_uvgui_rom_00400F44(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 *arg4, u8 arg5, u8 arg6,
                             u8 arg7, u8 arg8);
void func_uvgui_rom_0040104C(s16 arg0, s16 arg1);
void func_uvgui_rom_0040126C(UnkStruct_uvgui_rom_00400510 *arg0, s16 arg1, s16 arg2, s16 arg3,
                             s16 arg4);
s32 func_uvgui_rom_00401290(UnkStruct_uvgui_rom_00400510 *arg0);
void func_uvgui_rom_004015B8(UnkStruct_uvgui_rom_00400510 *arg0, s16 arg1, s32 arg2);
void func_uvgui_rom_00401614(UnkStruct_uvgui_rom_00400510 *arg0, s16 uvds, s16 font);
void func_uvgui_rom_004016A0(UnkStruct_uvgui_rom_00400510 *arg0, s8 arg1);
void func_uvgui_rom_004016AC(UnkStruct_uvgui_rom_00400510 *arg0, s16 arg1, s16 arg2);
void func_uvgui_rom_004016E0(s16 arg0);
void func_uvgui_rom_004016F0(UnkStruct_uvgui_rom_00400510 *arg0);
void func_uvgui_rom_00401BC8(void);
s16 func_uvgui_rom_00401CA0(void);
UnkStruct_uvgui_rom_00407238 *func_uvgui_rom_00401CE0(s16 arg0);
void func_uvgui_rom_00401D10(void *arg0, u8 *arg1);
void func_uvgui_rom_00401D74(UnkStruct_uvgui_rom_00407238 *arg0, s16 arg1);
void func_uvgui_rom_00401D80(UnkStruct_uvgui_rom_00400510_unk0_unk28_inner *arg0, s16 arg1, s16 arg2,
                             s16 arg3, s16 arg4);
void func_uvgui_rom_00401DC4(UnkStruct_uvgui_rom_00400510_unk0_unk28_inner *arg0);
s32 func_uvgui_rom_004020A0(UnkStruct_uvgui_rom_00400510_unk0_unk28_inner *arg0, u8 arg1, s16 arg2,
                            s16 arg3, s32 arg4, f32 arg5, f32 arg6);
void func_uvgui_rom_0040221C(UnkStruct_uvgui_rom_00400510_unk0_unk28_inner *arg0, s16 arg1,
                             UvGuiRoutine routine);
void func_uvgui_rom_00402268(UnkStruct_uvgui_rom_00400510_unk0_unk28_inner *arg0, Inner28 *arg1);
void func_uvgui_rom_00402308(UnkStruct_uvgui_rom_00400510_unk0_unk28_inner *arg0, Inner2C *arg1);
void func_uvgui_rom_004023A8(UnkStruct_uvgui_rom_00400510_unk0_unk28_inner *arg0, Inner30 *arg1);
void func_uvgui_rom_00402638(void);
s16 func_uvgui_rom_00402698(void);
UnkStruct_uvgui_rom_00400510_unk0 *func_uvgui_rom_004026E8(s16 arg0);
void func_uvgui_rom_00402718(void *arg0, u8 *arg1);
void func_uvgui_rom_0040277C(UnkStruct_uvgui_rom_00400510_unk0 *arg0, s16 arg1);
void func_uvgui_rom_00402788(UnkStruct_uvgui_rom_00400510_unk0 *arg0, s16 arg1, s16 arg2, s16 arg3,
                             s16 arg4);
void func_uvgui_rom_004027AC(UnkStruct_uvgui_rom_00400510_unk0 *arg0,
                             UnkStruct_uvgui_rom_00400510_unk0_unk28 *arg1);
void func_uvgui_rom_00402850(UnkStruct_uvgui_rom_00400510_unk0 *arg0);
s32 func_uvgui_rom_0040293C(UnkStruct_uvgui_rom_00400510_unk0 *arg0, u8 arg1, s16 arg2, s16 arg3,
                            s32 arg4, f32 arg5, f32 arg6);
void func_uvgui_rom_00402B00(void);
s16 func_uvgui_rom_00402B60(void);
UnkStruct_uvgui_rom_00400510_unk0_unk28 *func_uvgui_rom_00402BA0(s16 arg0);
void func_uvgui_rom_00402BD0(void *arg0, u8 *arg1);
void func_uvgui_rom_00402C34(UnkStruct_uvgui_rom_00400510_unk0_unk28 *arg0, s16 arg1);
void func_uvgui_rom_00402C40(UnkStruct_uvgui_rom_00400510_unk0_unk28 *arg0, s16 arg1, s16 arg2,
                             s16 arg3, s16 arg4);
void func_uvgui_rom_00402C74(UnkStruct_uvgui_rom_00400510_unk0_unk28 *arg0,
                             UnkStruct_uvgui_rom_00400510_unk0_unk28_inner *arg1);
void func_uvgui_rom_00402D1C(UnkStruct_uvgui_rom_00400510_unk0_unk28 *arg0);
s32 func_uvgui_rom_00402E48(UnkStruct_uvgui_rom_00400510_unk0_unk28 *arg0, u8 arg1, s16 arg2, s16 arg3,
                            s32 arg4, f32 arg5, f32 arg6);
void func_uvgui_rom_0040300C(void);
s16 func_uvgui_rom_004031A4(void);
void func_uvgui_rom_004031E4(s16 arg0);
Inner28 *func_uvgui_rom_0040320C(s16 arg0);
void func_uvgui_rom_00403234(void *arg0, u8 *arg1);
void func_uvgui_rom_00403298(Inner28 *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_uvgui_rom_004032BC(Inner28 *arg0);
void func_uvgui_rom_004037D8(Inner28 *arg0, s32 arg1);
void func_uvgui_rom_004037E0(Inner28 *arg0, f32 arg1, f32 arg2, f32 arg3, s32 *arg4);
void func_uvgui_rom_004038D8(Inner28 *arg0, s16 arg1);
void func_uvgui_rom_004038E4(Inner28 *arg0, u8 arg1, f32 arg2);
void func_uvgui_rom_00403C50(Inner28 *arg0, s16 arg1);
void func_uvgui_rom_00403CA4(Inner28 *arg0, s32 arg1);
void func_uvgui_rom_00403CAC(void);
s16 func_uvgui_rom_00403E78(void);
void func_uvgui_rom_00403EB8(s16 arg0);
Inner30 *func_uvgui_rom_00403EE0(s16 arg0);
void func_uvgui_rom_00403F08(Inner30 *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_uvgui_rom_00403F2C(Inner30 *arg0, u8 *arg1, u8 *arg2);
void func_uvgui_rom_00404010(Inner30 *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 *arg5);
void func_uvgui_rom_0040404C(Inner30 *arg0, s32 arg1);
void func_uvgui_rom_00404054(Inner30 *arg0, u8 button, f32 arg2);
void func_uvgui_rom_004046B4(Inner30 *arg0);
void func_uvgui_rom_00405CEC(Inner30 *arg0, s16 arg1);
void func_uvgui_rom_00405D1C(Inner30 *arg0, ...);
void func_uvgui_rom_00405D78(void);
s16 func_uvgui_rom_00405F20(void);
void func_uvgui_rom_00405F60(s16 arg0);
Inner2C *func_uvgui_rom_00405F90(s16 arg0);
void func_uvgui_rom_00405FC0(Inner2C *arg0, u8 *arg1);
void func_uvgui_rom_00406024(Inner2C *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_uvgui_rom_00406048(Inner2C *arg0);
void func_uvgui_rom_00406B00(Inner2C *arg0, s32 arg1);
void func_uvgui_rom_00406B08(Inner2C *arg0, f32 arg1, f32 arg2, Vec3F *arg3, Vec3F *arg4);
void func_uvgui_rom_00406B7C(Inner2C *arg0, s16 arg1);
void func_uvgui_rom_00406B88(Inner2C *arg0, u8 arg1, f32 arg2);
void func_uvgui_rom_00406E28(Inner2C *arg0, s16 arg1);
void __entrypoint_func_uvgui_rom_400000(UvGui_Exports *exports);

// exports
Inner2C D_uvgui_rom_00406F20[10];
static UvFMtx_Rom_Exports *D_uvgui_rom_00407218;
static UvFont_Exports *D_uvgui_rom_0040721C;
static UvGfxMgr_Exports *D_uvgui_rom_00407220;
static UvGfxState_Rom_Exports *D_uvgui_rom_00407224;
static UvDGeom_Rom_Exports *D_uvgui_rom_00407228;
static UvGrph_Exports *D_uvgui_rom_0040722C;
static UvCont_Exports *D_uvgui_rom_00407230;
static UvString_Exports *D_uvgui_rom_00407234;
UnkStruct_uvgui_rom_00407238 D_uvgui_rom_00407238[120];
UnkStruct_uvgui_rom_00400510_unk0 D_uvgui_rom_00408A98[8];
UnkStruct_uvgui_rom_00400510_unk0_unk28 D_uvgui_rom_00408D78[50];
Inner28 D_uvgui_rom_0040D558[135];
Inner30 D_uvgui_rom_0040FB50[20];

// .data
s16 D_uvgui_rom_00406F00 = 0;

void __entrypoint_func_uvgui_rom_400000(UvGui_Exports *exports) {
    uvUpdateFileAllocPtr(exports);
    exports->func_uvgui_rom_00406048 = func_uvgui_rom_00406048;
    exports->func_uvgui_rom_00406B00 = func_uvgui_rom_00406B00;
    exports->func_uvgui_rom_00406B08 = func_uvgui_rom_00406B08;
    exports->func_uvgui_rom_00406B7C = func_uvgui_rom_00406B7C;
    exports->func_uvgui_rom_00400510 = func_uvgui_rom_00400510;
    exports->func_uvgui_rom_004006B8 = func_uvgui_rom_004006B8;
    exports->func_uvgui_rom_00400754 = func_uvgui_rom_00400754;
    exports->func_uvgui_rom_00400990 = func_uvgui_rom_00400990;
    exports->func_uvgui_rom_00400F44 = func_uvgui_rom_00400F44;
    exports->func_uvgui_rom_0040104C = func_uvgui_rom_0040104C;
    exports->func_uvgui_rom_0040126C = func_uvgui_rom_0040126C;
    exports->func_uvgui_rom_00401290 = func_uvgui_rom_00401290;
    exports->func_uvgui_rom_004015B8 = func_uvgui_rom_004015B8;
    exports->func_uvgui_rom_00402C34 = func_uvgui_rom_00402C34;
    exports->func_uvgui_rom_00402C40 = func_uvgui_rom_00402C40;
    exports->func_uvgui_rom_00402C74 = func_uvgui_rom_00402C74;
    exports->func_uvgui_rom_00402D1C = func_uvgui_rom_00402D1C;
    exports->func_uvgui_rom_00406B88 = func_uvgui_rom_00406B88;
    exports->func_uvgui_rom_00402E48 = func_uvgui_rom_00402E48;
    exports->func_uvgui_rom_00406E28 = func_uvgui_rom_00406E28;
    exports->func_uvgui_rom_0040300C = func_uvgui_rom_0040300C;
    exports->func_uvgui_rom_004031A4 = func_uvgui_rom_004031A4;
    exports->func_uvgui_rom_004031E4 = func_uvgui_rom_004031E4;
    exports->func_uvgui_rom_0040320C = func_uvgui_rom_0040320C;
    exports->func_uvgui_rom_00403234 = func_uvgui_rom_00403234;
    exports->func_uvgui_rom_00401614 = func_uvgui_rom_00401614;
    exports->func_uvgui_rom_004016A0 = func_uvgui_rom_004016A0;
    exports->func_uvgui_rom_004016AC = func_uvgui_rom_004016AC;
    exports->func_uvgui_rom_004016E0 = func_uvgui_rom_004016E0;
    exports->func_uvgui_rom_00403298 = func_uvgui_rom_00403298;
    exports->func_uvgui_rom_004016F0 = func_uvgui_rom_004016F0;
    exports->func_uvgui_rom_004032BC = func_uvgui_rom_004032BC;
    exports->func_uvgui_rom_00401BC8 = func_uvgui_rom_00401BC8;
    exports->func_uvgui_rom_004037D8 = func_uvgui_rom_004037D8;
    exports->func_uvgui_rom_00401CA0 = func_uvgui_rom_00401CA0;
    exports->func_uvgui_rom_004037E0 = func_uvgui_rom_004037E0;
    exports->func_uvgui_rom_00401CE0 = func_uvgui_rom_00401CE0;
    exports->func_uvgui_rom_004038D8 = func_uvgui_rom_004038D8;
    exports->func_uvgui_rom_00401D10 = func_uvgui_rom_00401D10;
    exports->func_uvgui_rom_004038E4 = func_uvgui_rom_004038E4;
    exports->func_uvgui_rom_00401D74 = func_uvgui_rom_00401D74;
    exports->func_uvgui_rom_00403C50 = func_uvgui_rom_00403C50;
    exports->func_uvgui_rom_00403CA4 = func_uvgui_rom_00403CA4;
    exports->func_uvgui_rom_00403CAC = func_uvgui_rom_00403CAC;
    exports->func_uvgui_rom_00403E78 = func_uvgui_rom_00403E78;
    exports->func_uvgui_rom_00400498 = func_uvgui_rom_00400498;
    exports->func_uvgui_rom_00401D80 = func_uvgui_rom_00401D80;
    exports->func_uvgui_rom_00401DC4 = func_uvgui_rom_00401DC4;
    exports->func_uvgui_rom_004020A0 = func_uvgui_rom_004020A0;
    exports->func_uvgui_rom_0040221C = func_uvgui_rom_0040221C;
    exports->func_uvgui_rom_00402268 = func_uvgui_rom_00402268;
    exports->func_uvgui_rom_00403EB8 = func_uvgui_rom_00403EB8;
    exports->func_uvgui_rom_00402308 = func_uvgui_rom_00402308;
    exports->func_uvgui_rom_00403EE0 = func_uvgui_rom_00403EE0;
    exports->func_uvgui_rom_004023A8 = func_uvgui_rom_004023A8;
    exports->func_uvgui_rom_00403F08 = func_uvgui_rom_00403F08;
    exports->func_uvgui_rom_00402638 = func_uvgui_rom_00402638;
    exports->func_uvgui_rom_00403F2C = func_uvgui_rom_00403F2C;
    exports->func_uvgui_rom_00402698 = func_uvgui_rom_00402698;
    exports->func_uvgui_rom_00404010 = func_uvgui_rom_00404010;
    exports->func_uvgui_rom_004026E8 = func_uvgui_rom_004026E8;
    exports->func_uvgui_rom_0040404C = func_uvgui_rom_0040404C;
    exports->func_uvgui_rom_00404054 = func_uvgui_rom_00404054;
    exports->func_uvgui_rom_004046B4 = func_uvgui_rom_004046B4;
    exports->func_uvgui_rom_00405CEC = func_uvgui_rom_00405CEC;
    exports->func_uvgui_rom_00405D1C = func_uvgui_rom_00405D1C;
    exports->func_uvgui_rom_00402718 = func_uvgui_rom_00402718;
    exports->func_uvgui_rom_0040277C = func_uvgui_rom_0040277C;
    exports->func_uvgui_rom_00402788 = func_uvgui_rom_00402788;
    exports->func_uvgui_rom_004027AC = func_uvgui_rom_004027AC;
    exports->func_uvgui_rom_00405D78 = func_uvgui_rom_00405D78;
    exports->func_uvgui_rom_00402850 = func_uvgui_rom_00402850;
    exports->func_uvgui_rom_00405F20 = func_uvgui_rom_00405F20;
    exports->func_uvgui_rom_0040293C = func_uvgui_rom_0040293C;
    exports->func_uvgui_rom_00405F60 = func_uvgui_rom_00405F60;
    exports->func_uvgui_rom_00402B00 = func_uvgui_rom_00402B00;
    exports->func_uvgui_rom_00405F90 = func_uvgui_rom_00405F90;
    exports->func_uvgui_rom_00402B60 = func_uvgui_rom_00402B60;
    exports->func_uvgui_rom_00405FC0 = func_uvgui_rom_00405FC0;
    exports->func_uvgui_rom_00402BA0 = func_uvgui_rom_00402BA0;
    exports->func_uvgui_rom_00406024 = func_uvgui_rom_00406024;
    exports->func_uvgui_rom_00402BD0 = func_uvgui_rom_00402BD0;
#ifdef __sgi
#line 1
#endif
    D_uvgui_rom_00407218 = uvLoadModule('FMTX');
    D_uvgui_rom_0040721C = uvLoadModule('FONT');
    D_uvgui_rom_00407220 = uvLoadModule('GMGR');
    D_uvgui_rom_00407224 = uvLoadModule('STAT');
    D_uvgui_rom_00407228 = uvLoadModule('DGEO');
    D_uvgui_rom_0040722C = uvLoadModule('grph');
    D_uvgui_rom_00407234 = uvLoadModule('STRG');
    D_uvgui_rom_00407230 = uvLoadModule('CONT');
}

void func_uvgui_rom_00400498(void) {
    uvUnloadModule('FMTX');
    uvUnloadModule('FONT');
    uvUnloadModule('GMGR');
    uvUnloadModule('STAT');
    uvUnloadModule('DGEO');
    uvUnloadModule('grph');
    uvUnloadModule('CONT');
    uvUnloadModule('STRG');
}

void func_uvgui_rom_00400510(UnkStruct_uvgui_rom_00400510 *arg0) {
    s32 i;

    func_uvgui_rom_00401BC8();
    func_uvgui_rom_00402B00();
    func_uvgui_rom_00402638();
    func_uvgui_rom_00403CAC();
    func_uvgui_rom_0040300C();
    func_uvgui_rom_00405D78();
    arg0->unk50 = 0;

    // clang-format off
    for (i = 0; i < 20; i++) { arg0->unk0[i] = 0;}
    // clang-format on

    arg0->unk54 = 0;
    arg0->unk56 = D_uvgui_rom_00407220->uvGetScreenWidth() - 1;
    arg0->unk58 = 0;
    arg0->unk5A = D_uvgui_rom_00407220->uvGetScreenHeight() - 1;
    arg0->unk70 = (s16) (D_uvgui_rom_00407220->uvGetScreenWidth() / 2);
    arg0->unk72 = (s16) (D_uvgui_rom_00407220->uvGetScreenHeight() / 2);
    arg0->unk68 = arg0->unk70;
    arg0->unk6C = arg0->unk72;
    arg0->unk74 = 0x8000;
    arg0->unk78 = 0x4000;
    arg0->unk7C = 0;
    arg0->unk80 = 1;
    arg0->unk5C = 0;
    arg0->fontId = -1;
    arg0->unk8A = 1;
    arg0->unk8B = 1;
    arg0->unk60 = 0.0f;
    arg0->unk64 = 0.0f;

    for (i = 0; i < MAXCONTROLLERS; i++) {
        if (!D_uvgui_rom_00407230->uvControllerPlugged(i)) {
            break;
        }
    }
    arg0->contNo = i - 1;
}

void func_uvgui_rom_004006B8(UnkStruct_uvgui_rom_00400510 *arg0,
                             UnkStruct_uvgui_rom_00400510_unk0 *arg1) {
    s16 temp_a3;
    s32 i;

    for (i = 0; i < 20; i++) {
        if (arg0->unk0[i] == 0) {
            break;
        }
    }

    if (i == 20) {
        return;
    }

    arg0->unk0[i] = arg1;
    arg0->unk50 += 1;
    temp_a3 = (arg0->unk5A - (i * 0xC)) - 0xC;
    func_uvgui_rom_00402788(arg1, arg0->unk54, arg0->unk56, temp_a3, temp_a3 + 0xC);
}

void func_uvgui_rom_00400754(UnkStruct_uvgui_rom_00400510 *arg0) {
    s32 i;
    Mtx4F sp7C;
    Mtx4F sp3C;

    D_uvgui_rom_00407220->func_uvgfxmgr_rom_00401BD4(0, D_uvgui_rom_00407220->uvGetScreenWidth() - 1, 0,
                                                     D_uvgui_rom_00407220->uvGetScreenHeight() - 1);
    D_uvgui_rom_00407218->uvMat4SetOrtho(&sp7C, -0.5f,
                                         (f32) D_uvgui_rom_00407220->uvGetScreenWidth() + 0.5f, -0.5f,
                                         (f32) D_uvgui_rom_00407220->uvGetScreenHeight() + 0.5f);
    D_uvgui_rom_00407218->uvGfxMtxProjPushF(&sp7C);
    D_uvgui_rom_00407218->uvMat4SetIdentity(&sp3C);
    D_uvgui_rom_00407218->func_uvfmtx_rom_004029DC(&sp3C);
    D_uvgui_rom_00407224->uvGfxStatePush();
    D_uvgui_rom_00407224->func_uvgfxstate_rom_00401F54(0.0f, 0.0f);
    D_uvgui_rom_00407224->uvGfxStateSetFlags(0x04800FFF);
    D_uvgui_rom_00407224->func_uvgfxstate_rom_00401354(0x9A640000);
    if (arg0->fontId >= 0) {
        D_uvgui_rom_0040721C->uvSetFont(arg0->fontId);
    }

    for (i = 0; i < arg0->unk50; i++) {
        func_uvgui_rom_00402850(arg0->unk0[i]);
    }
    D_uvgui_rom_0040721C->uvFontGenDList();
    if (((u8) arg0->unk8A != 0) && (D_uvgui_rom_00406F00 == 0)) {
        func_uvgui_rom_0040104C(arg0->unk70, arg0->unk72);
    }
    D_uvgui_rom_00407224->uvGfxStatePop();
}

void func_uvgui_rom_00400990(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, u8 arg5, u8 arg6,
                             u8 arg7, u8 arg8) {
    D_uvgui_rom_00407228->uvVtxBeginPoly();
    D_uvgui_rom_00407228->uvVtx(arg0 + arg4, arg2 + arg4, 0, 0, 0, arg5, arg6, arg7, arg8);
    D_uvgui_rom_00407228->uvVtx(arg1 - arg4, arg2 + arg4, 0, 0, 0, arg5, arg6, arg7, arg8);
    D_uvgui_rom_00407228->uvVtx(arg1 - arg4, arg3 - arg4, 0, 0, 0, arg5, arg6, arg7, arg8);
    D_uvgui_rom_00407228->uvVtx(arg0 + arg4, arg3 - arg4, 0, 0, 0, arg5, arg6, arg7, arg8);
    D_uvgui_rom_00407228->uvVtxEndPoly();
    if (arg5 >= 0x15) {
        arg5 = (arg5 - 0x14);
    }
    if (arg6 >= 0x15) {
        arg6 = (arg6 - 0x14);
    }
    if (arg7 >= 0x15) {
        arg7 = (arg7 - 0x14);
    }
    D_uvgui_rom_00407228->uvVtxBeginPoly();
    D_uvgui_rom_00407228->uvVtx(arg1, arg3, 0, 0, 0, arg5, arg6, arg7, arg8);
    D_uvgui_rom_00407228->uvVtx(arg0, arg3, 0, 0, 0, arg5, arg6, arg7, arg8);
    D_uvgui_rom_00407228->uvVtx(arg0 + arg4, arg3 - arg4, 0, 0, 0, arg5, arg6, arg7, arg8);
    D_uvgui_rom_00407228->uvVtx(arg1 - arg4, arg3 - arg4, 0, 0, 0, arg5, arg6, arg7, arg8);
    D_uvgui_rom_00407228->uvVtxEndPoly();
    if (arg5 >= 0x15) {
        arg5 = (arg5 - 0x14);
    }
    if (arg6 >= 0x15) {
        arg6 = (arg6 - 0x14);
    }
    if (arg7 >= 0x15) {
        arg7 = (arg7 - 0x14);
    }
    D_uvgui_rom_00407228->uvVtxBeginPoly();
    D_uvgui_rom_00407228->uvVtx(arg0, arg2, 0, 0, 0, arg5, arg6, arg7, arg8);
    D_uvgui_rom_00407228->uvVtx(arg0 + arg4, arg2 + arg4, 0, 0, 0, arg5, arg6, arg7, arg8);
    D_uvgui_rom_00407228->uvVtx(arg0 + arg4, arg3 - arg4, 0, 0, 0, arg5, arg6, arg7, arg8);
    D_uvgui_rom_00407228->uvVtx(arg0, arg3, 0, 0, 0, arg5, arg6, arg7, arg8);
    D_uvgui_rom_00407228->uvVtxEndPoly();
    if (arg5 >= 0x15) {
        arg5 = (arg5 - 0x14);
    }
    if (arg6 >= 0x15) {
        arg6 = (arg6 - 0x14);
    }
    if (arg7 >= 0x15) {
        arg7 = (arg7 - 0x14);
    }
    D_uvgui_rom_00407228->uvVtxBeginPoly();
    D_uvgui_rom_00407228->uvVtx(arg0, arg2, 0, 0, 0, arg5, arg6, arg7, arg8);
    D_uvgui_rom_00407228->uvVtx(arg1, arg2, 0, 0, 0, arg5, arg6, arg7, arg8);
    D_uvgui_rom_00407228->uvVtx(arg1 - arg4, arg2 + arg4, 0, 0, 0, arg5, arg6, arg7, arg8);
    D_uvgui_rom_00407228->uvVtx(arg0 + arg4, arg2 + arg4, 0, 0, 0, arg5, arg6, arg7, arg8);
    D_uvgui_rom_00407228->uvVtxEndPoly();
    if (arg5 >= 0x15) {
        arg5 = (arg5 - 0x14);
    }
    if (arg6 >= 0x15) {
        arg6 = (arg6 - 0x14);
    }
    if (arg7 >= 0x15) {
        arg7 = (arg7 - 0x14);
    }
    D_uvgui_rom_00407228->uvVtxBeginPoly();
    D_uvgui_rom_00407228->uvVtx(arg1, arg2, 0, 0, 0, arg5, arg6, arg7, arg8);
    D_uvgui_rom_00407228->uvVtx(arg1, arg3, 0, 0, 0, arg5, arg6, arg7, arg8);
    D_uvgui_rom_00407228->uvVtx(arg1 - arg4, arg3 - arg4, 0, 0, 0, arg5, arg6, arg7, arg8);
    D_uvgui_rom_00407228->uvVtx(arg1 - arg4, arg2 + arg4, 0, 0, 0, arg5, arg6, arg7, arg8);
    D_uvgui_rom_00407228->uvVtxEndPoly();
}

void func_uvgui_rom_00400F44(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 *arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8) {
    s16 pad[2];
    s16 sp22;
    s16 other;
    s16 sp1D;
    s16 sp1C;
    s32 v0;
    
    sp22 = D_uvgui_rom_0040721C->uvFontWidth(arg4);
    v0 = (s16)D_uvgui_rom_0040721C->uvFontHeight();
    sp1C = (arg2 + ((s32) ((s16) (arg3 - arg2) - v0) / 2)) - 1;
    D_uvgui_rom_0040721C->uvFontColor(arg5, arg6, arg7, arg8);
    D_uvgui_rom_0040721C->uvFontPrintStr((s16) ((arg0 + ((s32) ((s16) (arg1 - arg0) - sp22) / 2)) - 1), sp1C, arg4);
}

void func_uvgui_rom_0040104C(s16 arg0, s16 arg1) {
    u8 sp5F;
    u8 sp5E;
    u8 sp5D;
    s32 pad;
    static s32 D_uvgui_rom_00406F04 = 0;

    D_uvgui_rom_00406F04 = D_uvgui_rom_00406F04 == 0;
    if (D_uvgui_rom_00406F04) {
        sp5D = 0xFF;
        sp5E = 0xFF;
        sp5F = 0xFF;
    } else {
        sp5D = 0;
        sp5E = 0;
        sp5F = 0;
    }
    D_uvgui_rom_00407228->uvVtxBeginPoly();
    D_uvgui_rom_00407228->uvVtx(arg0, arg1, 0, 0, 0, sp5F, sp5E, sp5D, 0x7F);
    D_uvgui_rom_00407228->uvVtx(arg0 + 6, arg1 - 0xD, 0, 0, 0, sp5F, sp5E, sp5D, 0x7F);
    D_uvgui_rom_00407228->uvVtx(arg0 + 6, arg1 - 6, 0, 0, 0, sp5F, sp5E, sp5D, 0x7F);
    D_uvgui_rom_00407228->uvVtxEndPoly();
    D_uvgui_rom_00407228->uvVtxBeginPoly();
    D_uvgui_rom_00407228->uvVtx(arg0, arg1, 0, 0, 0, sp5F, sp5E, sp5D, 0x7F);
    D_uvgui_rom_00407228->uvVtx(arg0 + 6, arg1 - 6, 0, 0, 0, sp5F, sp5E, sp5D, 0x7F);
    D_uvgui_rom_00407228->uvVtx(arg0 + 0xD, arg1 - 6, 0, 0, 0, sp5F, sp5E, sp5D, 0x7F);
    D_uvgui_rom_00407228->uvVtxEndPoly();
}

void func_uvgui_rom_0040126C(UnkStruct_uvgui_rom_00400510 *arg0, s16 arg1, s16 arg2, s16 arg3,
                             s16 arg4) {
    arg0->unk54 = arg1;
    arg0->unk56 = arg2;
    arg0->unk58 = arg3;
    arg0->unk5A = arg4;
}

s32 func_uvgui_rom_00401290(UnkStruct_uvgui_rom_00400510 *arg0) {
    f32 temp_fv0_2;
    s32 i;
    s32 v0;

    if ((u8)arg0->unk8B != 0) {
        func_uvgui_rom_004016F0(arg0);
        arg0->unk8B = 0U;
    }
    arg0->unk5C = 0;
    if (D_uvgui_rom_00407230->uvControllerButtonPress((u8)arg0->contNo, arg0->unk74) != 0) {
        arg0->unk5C = 1;
    }
    if (D_uvgui_rom_00407230->uvControllerButtonPress((u8)arg0->contNo, arg0->unk78) != 0) {
        arg0->unk5C = 2;
    }
    arg0->unk60 = D_uvgui_rom_00407230->uvControllerGetStick((u8)arg0->contNo, arg0->unk7C);
    arg0->unk64 = D_uvgui_rom_00407230->uvControllerGetStick((u8)arg0->contNo, arg0->unk80);
    if (arg0->unk60 >= 0.0f) {
        v0 = 1;
    } else {
        v0 = -1;
    }
    arg0->unk60 = arg0->unk60 * (v0 * arg0->unk60);
    if (arg0->unk64 >= 0.0f) {
        v0 = 1;
    } else {
        v0 = -1;
    }
    arg0->unk64 = arg0->unk64 * (v0 * arg0->unk64);
    if (D_uvgui_rom_00407230->uvControllerButtonPress((u8)arg0->contNo, L_JPAD) != 0) {
        arg0->unk60 -= 0.25f;
    }
    if (D_uvgui_rom_00407230->uvControllerButtonPress((u8)arg0->contNo, R_JPAD) != 0) {
        arg0->unk60 += 0.25f;
    }
    if (D_uvgui_rom_00406F00 == 0) {
        temp_fv0_2 = D_uvgui_rom_00407220->func_uvgfxmgr_rom_00401004();
        arg0->unk68 = arg0->unk68 + (240.0f * arg0->unk60 * temp_fv0_2);
        arg0->unk6C = arg0->unk6C + (240.0f * arg0->unk64 * temp_fv0_2);
        if (arg0->unk68 < (arg0->unk54 + 1)) {
            arg0->unk68 = (arg0->unk54 + 1);
        } else {
            if ((arg0->unk56 - 1) < arg0->unk68) {
                arg0->unk68 = (arg0->unk56 - 1);
            }
        }
        if (arg0->unk6C < (arg0->unk58 + 1)) {
            arg0->unk6C = (arg0->unk58 + 1);
        } else {
            if ((arg0->unk5A - 1) < arg0->unk6C) {
                arg0->unk6C = (arg0->unk5A - 1);
            }
        }
        arg0->unk70 = arg0->unk68;
        arg0->unk72 = arg0->unk6C;
    }

    for (i = 0; i < arg0->unk50; i++) {
        func_uvgui_rom_0040293C(arg0->unk0[i], arg0->contNo, arg0->unk70, arg0->unk72, arg0->unk5C,
                                arg0->unk60, arg0->unk64);
    }
    return 1;
}

void func_uvgui_rom_004015B8(UnkStruct_uvgui_rom_00400510 *arg0, s16 arg1, s32 arg2) {
    switch (arg1) {
        case 1:
            arg0->unk74 = arg2;
            break;
        case 2:
            // FAKE
            arg1++;
            arg1--;

            arg0->unk78 = arg2;
            break;
        case 17:
            arg0->unk7C = arg2;
            break;
        case 18:
            arg0->unk80 = arg2;
            break;
        case 16:
            arg0->contNo = arg2;
            break;
        default:
            break;
    }
}

void func_uvgui_rom_00401614(UnkStruct_uvgui_rom_00400510 *arg0, s16 uvds, s16 font) {
    arg0->uvds = uvds;
    arg0->fontId = font;
    if (uvds != -1) {
        uvLoadFile('UVDS', uvds);
    }
    D_uvgui_rom_0040721C->uvSetFont(font);
    arg0->unk8B = 1;
}

void func_uvgui_rom_004016A0(UnkStruct_uvgui_rom_00400510 *arg0, s8 arg1) {
    arg0->unk8A = arg1;
}

void func_uvgui_rom_004016AC(UnkStruct_uvgui_rom_00400510 *arg0, s16 arg1, s16 arg2) {
    arg0->unk70 = arg1;
    arg0->unk72 = arg2;
    arg0->unk68 = (f32) arg0->unk70;
    arg0->unk6C = (f32) arg0->unk72;
}

void func_uvgui_rom_004016E0(s16 arg0) {
    D_uvgui_rom_00406F00 = arg0;
}

void func_uvgui_rom_004016F0(UnkStruct_uvgui_rom_00400510 *arg0) {
    UnkStruct_uvgui_rom_00400510_unk0 *temp_v1;
    s16 var_s2;
    s16 two;
    s32 temp_s3;
    s32 i;
    s32 j;
    s32 k;
    s32 temp_t8;
    s32 temp_v0_2;
    s32 sp8C;
    s32 var_fp;
    s32 sp5C;
    s32 temp;
    s32 temp_t2;

    UnkStruct_uvgui_rom_00400510_unk0_unk28 *temp_s5;
    UnkStruct_uvgui_rom_00400510_unk0_unk28_inner *temp_s1;

    D_uvgui_rom_0040721C->uvSetFont(arg0->fontId);
    for (i = 0; i < arg0->unk50; i++) {
        temp_v1 = arg0->unk0[i];
        sp8C = temp_v1->unk20;
        for (j = 0; j < temp_v1->unk58; j++) {
            var_fp = 0;
            temp_s5 = temp_v1->unk28[j];
            temp_s5->unk16C = D_uvgui_rom_0040721C->uvFontWidth(temp_s5->unk0);
            temp_s5->unk20 = (s16) (sp8C - 2);
            temp_s5->unk22 = (s16) (temp_s5->unk20 + temp_s5->unk16C + 8);
            sp8C = temp_s5->unk22 + 3;

            func_uvgui_rom_00402C40(temp_s5, temp_s5->unk20, temp_s5->unk22, temp_s5->unk24,
                                    (s32) temp_s5->unk26);

            two = 2;
            for (k = 0; k < temp_s5->unk168; k++) {
                temp_s1 = temp_s5->unk28[k];
                temp_v0_2 = D_uvgui_rom_0040721C->uvFontWidth(temp_s1->unk0);
                if (var_fp < temp_v0_2) {
                    var_fp = temp_v0_2;
                }
            }

            sp5C = var_fp / two;
            for (k = 0; k < temp_s5->unk168; k++) {
                temp_s1 = temp_s5->unk28[k];

                temp_v0_2 = ((temp_v1->unk22 - temp_v1->unk20) + 1); // t1
                temp_t2 = ((temp_v1->unk22 + temp_v1->unk20) / 2);
                temp_t8 = ((temp_s5->unk20 + temp_s5->unk22) / 2);

                temp = ((var_fp * ((temp_t8 - temp_t2) / (f32) temp_v0_2)) / 2);
                temp_s1->unkE = (((temp_t8 - sp5C) - temp) - 2);
                temp_s1->unk10 = (temp_s1->unkE + var_fp + 4);
                func_uvgui_rom_00401D80(temp_s1, temp_s1->unkE, temp_s1->unk10, temp_s1->unk12,
                                        temp_s1->unk14);
                if (temp_s1->unk30 != 0) {
                    if (temp_s5->unk22 < (D_uvgui_rom_00407220->uvGetScreenWidth() / 2)) {
                        var_s2 = (arg0->unk56 - temp_s1->unk10) - 0x14;
                        if (var_s2 < 0x28) {
                            var_s2 = 0x28;
                        } else if (var_s2 >= 0xA1) {
                            var_s2 = 0xA0;
                        }
                        temp_s3 = D_uvgui_rom_00407220->uvGetScreenHeight();
                        func_uvgui_rom_00403F08(
                            temp_s1->unk30, (s16) (temp_s1->unk10 + 0xA),
                            (s16) (temp_s1->unk10 + var_s2 + 0xA), (s16) ((temp_s3 / 2) - (var_s2 / 2)),
                            (D_uvgui_rom_00407220->uvGetScreenHeight() / 2) + (var_s2 / 2));
                    } else {
                        var_s2 = (temp_s1->unkE - arg0->unk54) - 0x14;
                        if (var_s2 < 0x28) {
                            var_s2 = 0x28;
                        } else if (var_s2 >= 0xA1) {
                            var_s2 = 0xA0;
                        }

                        temp_s3 = D_uvgui_rom_00407220->uvGetScreenHeight();
                        func_uvgui_rom_00403F08(
                            temp_s1->unk30, (s16) ((temp_s1->unkE - var_s2) - 0xA),
                            (s16) (temp_s1->unkE - 0xA), (s16) ((temp_s3 / 2) - (var_s2 / 2)),
                            (D_uvgui_rom_00407220->uvGetScreenHeight() / 2) + (var_s2 / 2));
                    }
                }
            }
        }
    }
}

void func_uvgui_rom_00401BC8(void) {
    UnkStruct_uvgui_rom_00407238 *var_v1;
    s32 i;

    for (i = 0; i < 120; i++) {
        D_uvgui_rom_00407238[i].unkC = 0;
        D_uvgui_rom_00407238[i].unkE = 0;
        D_uvgui_rom_00407238[i].unk10 = 0x41;
        D_uvgui_rom_00407238[i].unk12 = 0;
        D_uvgui_rom_00407238[i].unk14 = 0xC;
        D_uvgui_rom_00407238[i].unk1C = 0;
        D_uvgui_rom_00407238[i].unk20 = 0;
        D_uvgui_rom_00407238[i].unk24 = 0;
        D_uvgui_rom_00407238[i].unk28 = 0;
        D_uvgui_rom_00407238[i].unk2C = 0;
        D_uvgui_rom_00407238[i].unk30 = 0;
    }
}

s16 func_uvgui_rom_00401CA0(void) {
    s32 i;

    for (i = 0; i < 120; i++) {
        if (D_uvgui_rom_00407238[i].unkC == 0) {
            break;
        }
    }

    D_uvgui_rom_00407238[i].unkC = 1;
    return i;
}

UnkStruct_uvgui_rom_00407238 *func_uvgui_rom_00401CE0(s16 arg0) {
    return &D_uvgui_rom_00407238[arg0];
}

void func_uvgui_rom_00401D10(void *arg0, u8 *arg1) {
    u8 sp34[12];
    u8 pad;
    s32 i;

    for (i = 0; i < 12; i++) {
        if (arg1[i] >= 'a') {
            sp34[i] = arg1[i] - ' ';
        } else {
            sp34[i] = arg1[i];
        }
    }
    _uvMediaCopy(arg0, sp34, 12);
}

void func_uvgui_rom_00401D74(UnkStruct_uvgui_rom_00407238 *arg0, s16 arg1) {
    arg0->unkC = arg1;
}

void func_uvgui_rom_00401D80(UnkStruct_uvgui_rom_00400510_unk0_unk28_inner *arg0, s16 arg1, s16 arg2,
                             s16 arg3, s16 arg4) {
    arg0->unkE = arg1;
    arg0->unk10 = arg2;
    arg0->unk12 = arg3;
    arg0->unk14 = arg4;
    arg0->unk18 = arg0->unk14 - arg0->unk12;
    arg0->unk16 = arg0->unk10 - arg0->unkE;
}

void func_uvgui_rom_00401DC4(UnkStruct_uvgui_rom_00400510_unk0_unk28_inner *arg0) {
    u8 var_t1;
    u8 var_t0;
    u8 var_v1;
    u8 var_t2;
    s16 temp_v0;
    int s;
    Inner28 *v1;

    temp_v0 = arg0->unkC;
    switch (temp_v0) {
        case 1:
            var_v1 = 0;
            var_t0 = 0;
            var_t1 = 0;
            var_t2 = 0x50;
            break;
        case 2:
            var_v1 = 0xFF;
            var_t0 = 0xFF;
            var_t1 = 0xFF;
            var_t2 = 0xFF;
            break;
        case 3:
            var_v1 = 0;
            var_t0 = 0;
            var_t1 = 0;
            var_t2 = 0xFF;
            break;
        case 4:
            var_v1 = 0;
            var_t0 = 0;
            var_t1 = 0;
            var_t2 = 0x40;
            break;
        default:
            return;
    }

    func_uvgui_rom_00400990(arg0->unkE, arg0->unk10, arg0->unk12, arg0->unk14, 2, var_t1, var_t0,
                            var_v1, var_t2);

    temp_v0 = arg0->unkC;
    switch (temp_v0) { /* irregular */
        case 1:
            var_t1 = 0xFF;
            var_t0 = 0xFF;
            var_v1 = 0xFF;
            var_t2 = 0xC8;
            break;
        case 2:
            var_t1 = 0;
            var_t0 = 0;
            var_v1 = 0;
            var_t2 = 0xFF;
            break;
        case 3:
            var_t1 = 0;
            var_t0 = 0xFF;
            var_v1 = 0;
            var_t2 = 0xFF;
            break;
        case 4:
            var_t1 = 0xFF;
            var_t0 = 0;
            var_v1 = 0;
            var_t2 = 0xFF;
            break;
    }
    func_uvgui_rom_00400F44(arg0->unkE, arg0->unk10, arg0->unk12, arg0->unk14, arg0->unk0, var_t1, var_t0,
                            var_v1, var_t2);

    if (arg0->unk28 != NULL) {
        v1 = arg0->unk28;
        if (arg0->unkC == 3) {
            if (v1->unk1E == 1) {
                func_uvgui_rom_00403C50(v1, 2);
                func_uvgui_rom_004016E0(1);
            } else {
                func_uvgui_rom_00403C50(v1, 1);
                func_uvgui_rom_004016E0(0);
            }
        }
        if (arg0->unkC == 2) {
            func_uvgui_rom_004032BC(arg0->unk28);
        }
    }

    if (arg0->unk2C != NULL) {
        Inner2C *v1 = arg0->unk2C;
        if (arg0->unkC == 3) {
            if (v1->unk1E == 1) {
                func_uvgui_rom_00406E28(v1, 2);
                func_uvgui_rom_004016E0(1);
            } else {
                func_uvgui_rom_00406E28(v1, 1);
                func_uvgui_rom_004016E0(0);
            }
        }
        if (arg0->unkC == 2) {
            func_uvgui_rom_00406048(arg0->unk2C);
        }
    }

    if (arg0->unk30 != NULL) {
        Inner30 *v1 = arg0->unk30;
        if (arg0->unkC == 3) {
            if (arg0->unk30->unk5E == 1) {
                func_uvgui_rom_00405CEC(v1, 2);
                func_uvgui_rom_004016E0(1);
            } else {
                func_uvgui_rom_00405CEC(v1, 1);
                func_uvgui_rom_004016E0(0);
            }
        }
        if (arg0->unkC == 2) {
            func_uvgui_rom_004046B4(arg0->unk30);
        }
    }
}

s32 func_uvgui_rom_004020A0(UnkStruct_uvgui_rom_00400510_unk0_unk28_inner *arg0, u8 arg1, s16 arg2,
                            s16 arg3, s32 arg4, f32 arg5, f32 arg6) {
    if (arg0->unk28 != NULL) {
        func_uvgui_rom_004038E4(arg0->unk28, arg1, arg5);
    }
    if (arg0->unk30 != NULL) {
        func_uvgui_rom_00404054(arg0->unk30, arg1, arg5);
    }
    if (arg0->unk2C != NULL) {
        func_uvgui_rom_00406B88(arg0->unk2C, arg1, arg5);
    }
    if (arg2 < arg0->unkE) {
        arg0->unkC = 1;
        return 0;
    }
    if (arg0->unk10 < arg2) {
        arg0->unkC = 1;
        return 0;
    }
    if (arg3 < arg0->unk12) {
        arg0->unkC = 1;
        return 0;
    }
    if (arg0->unk14 < arg3) {
        arg0->unkC = 1;
        return 0;
    }
    if (arg4 & 1) {
        arg0->unkC = 3;
        if (arg0->unk20 != NULL) {
            arg0->unk20(arg0);
        }
    } else if (arg4 & 2) {
        arg0->unkC = 4;
        if (arg0->unk24 != NULL) {
            arg0->unk24(arg0);
        }
    } else {
        arg0->unkC = 2;
        if (arg0->unk1C != NULL) {
            arg0->unk1C(arg0);
        }
    }
    return 1;
}

void func_uvgui_rom_0040221C(UnkStruct_uvgui_rom_00400510_unk0_unk28_inner *arg0, s16 arg1,
                             UvGuiRoutine routine) {
    switch (arg1) { /* irregular */
        case 2:
            arg0->unk1C = routine;
            return;
        case 3:
            arg0->unk20 = routine;
            return;
        case 4:
            arg0->unk24 = routine;
            return;
    }
}

void func_uvgui_rom_00402268(UnkStruct_uvgui_rom_00400510_unk0_unk28_inner *arg0, Inner28 *arg1) {
    arg0->unk28 = arg1;
    func_uvgui_rom_00403298(arg1, (s16) ((D_uvgui_rom_00407220->uvGetScreenWidth() / 2) - 0x5A),
                            (s16) ((D_uvgui_rom_00407220->uvGetScreenWidth() / 2) + 0x5A), 0x16, 0x30);
}

void func_uvgui_rom_00402308(UnkStruct_uvgui_rom_00400510_unk0_unk28_inner *arg0, Inner2C *arg1) {
    arg0->unk2C = arg1;
    func_uvgui_rom_00406024(arg1, (s16) ((D_uvgui_rom_00407220->uvGetScreenWidth() / 2) - 0x5A),
                            (s16) ((D_uvgui_rom_00407220->uvGetScreenWidth() / 2) + 0x5A), 0x16, 0x52);
}

void func_uvgui_rom_004023A8(UnkStruct_uvgui_rom_00400510_unk0_unk28_inner *arg0, Inner30 *arg1) {
    arg0->unk30 = arg1;
    if (arg0->unk10 < (D_uvgui_rom_00407220->uvGetScreenWidth() / 2)) {
        func_uvgui_rom_00403F08(arg1, (arg0->unk10 + 0xA), (arg0->unk10 + 0xAA),
                                ((D_uvgui_rom_00407220->uvGetScreenHeight() / 2) - 0x50),
                                (D_uvgui_rom_00407220->uvGetScreenHeight() / 2) + 0x50);
        return;
    }
    if ((D_uvgui_rom_00407220->uvGetScreenWidth() / 2) < arg0->unkE) {
        func_uvgui_rom_00403F08(arg1, (arg0->unkE - 0xAA), (arg0->unkE - 0xA),
                                ((D_uvgui_rom_00407220->uvGetScreenHeight() / 2) - 0x50),
                                (D_uvgui_rom_00407220->uvGetScreenHeight() / 2) + 0x50);
        return;
    }
    func_uvgui_rom_00403F08(arg1, ((D_uvgui_rom_00407220->uvGetScreenWidth() / 2) - 0x50),
                            ((D_uvgui_rom_00407220->uvGetScreenWidth() / 2) + 0x50),
                            ((D_uvgui_rom_00407220->uvGetScreenHeight() / 2) - 0x50),
                            (D_uvgui_rom_00407220->uvGetScreenHeight() / 2) + 0x50);
}

void func_uvgui_rom_00402638(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 8; i++) {
        D_uvgui_rom_00408A98[i].unk1E = 0;
        for (j = 0; j < 12; j++) {
            D_uvgui_rom_00408A98[i].unk28[j] = NULL;
        }
        D_uvgui_rom_00408A98[i].unk58 = 0;
        D_uvgui_rom_00408A98[i].unk5A = -1;
    }
}

s16 func_uvgui_rom_00402698(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if (D_uvgui_rom_00408A98[i].unk1E == 0) {
            break;
        }
    }

    if (i == 8) {
        return -1;
    }

    D_uvgui_rom_00408A98[i].unk1E = 1;
    return i;
}

UnkStruct_uvgui_rom_00400510_unk0 *func_uvgui_rom_004026E8(s16 arg0) {
    return &D_uvgui_rom_00408A98[arg0];
}

void func_uvgui_rom_00402718(void *arg0, u8 *arg1) {
    u8 sp30[30];
    s32 i;

    for (i = 0; i < 30; i++) {
        if (arg1[i] >= 'a') {
            sp30[i] = arg1[i] - ' ';
        } else {
            sp30[i] = arg1[i];
        }
    }
    _uvMediaCopy(arg0, sp30, 30);
}

void func_uvgui_rom_0040277C(UnkStruct_uvgui_rom_00400510_unk0 *arg0, s16 arg1) {
    arg0->unk1E = arg1;
}

void func_uvgui_rom_00402788(UnkStruct_uvgui_rom_00400510_unk0 *arg0, s16 arg1, s16 arg2, s16 arg3,
                             s16 arg4) {
    arg0->unk20 = arg1;
    arg0->unk22 = arg2;
    arg0->unk24 = arg3;
    arg0->unk26 = arg4;
}

void func_uvgui_rom_004027AC(UnkStruct_uvgui_rom_00400510_unk0 *arg0,
                             UnkStruct_uvgui_rom_00400510_unk0_unk28 *arg1) {
    s16 temp_a1;
    s32 i;
    s16 a3;
    s16 a2;

    for (i = 0; i < 12; i++) {
        if (arg0->unk28[i] == NULL) {
            break;
        }
    }
    if (i == 12) {
        return;
    }

    arg0->unk28[i] = arg1;
    arg0->unk58 += 1;
    a3 = arg0->unk26;
    a2 = arg0->unk24;
    temp_a1 = (arg0->unk20 + (i * 0x44) + 6);
    func_uvgui_rom_00402C40(arg1, temp_a1, temp_a1 + 0x41, a2, a3);
}

void func_uvgui_rom_00402850(UnkStruct_uvgui_rom_00400510_unk0 *arg0) {
    s32 i;

    func_uvgui_rom_00400990(arg0->unk20, arg0->unk22, arg0->unk24, arg0->unk26, 3, 0x2CU, 0x94U, 0xFFU,
                            0xFFU);
    if (arg0->unk1E != 2) {
        func_uvgui_rom_00400F44(arg0->unk20, arg0->unk22, arg0->unk24, arg0->unk26, arg0->unk0, 0xFFU,
                                0xFFU, 0xFFU, 0xFFU);
        return;
    }

    for (i = 0; i < arg0->unk58; i++) {
        func_uvgui_rom_00402D1C(arg0->unk28[i]);
    }
}

s32 func_uvgui_rom_0040293C(UnkStruct_uvgui_rom_00400510_unk0 *arg0, u8 arg1, s16 arg2, s16 arg3,
                            s32 arg4, f32 arg5, f32 arg6) {
    UnkStruct_uvgui_rom_00400510_unk0 *var_s0;
    s32 i;
    s32 matchFound;

    if (arg0->unk1E == 2) {
        matchFound = -1;
        for (i = 0; i < arg0->unk58; i++) {
            if (func_uvgui_rom_00402E48(arg0->unk28[i], arg1, arg2, arg3, arg4, arg5, arg6) != 0) {
                matchFound = i;
            }
        }
        if (i == arg0->unk58) {
            arg0->unk5A = matchFound;
        }
    } else {
        arg0->unk5A = -1;
    }
    if (arg0->unk5A >= 0) {
        return 1;
    }
    if (arg2 < arg0->unk20) {
        arg0->unk1E = 1;
        return 0;
    }
    if (arg0->unk22 < arg2) {
        arg0->unk1E = 1;
        return 0;
    }
    if (arg3 < arg0->unk24) {
        arg0->unk1E = 1;
        return 0;
    }
    if (arg0->unk26 < arg3) {
        arg0->unk1E = 1;
        return 0;
    }
    arg0->unk1E = 2;
    return 1;
}

void func_uvgui_rom_00402B00(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 50; i++) {
        D_uvgui_rom_00408D78[i].unk1E = 0;
        for (j = 0; j < 80; j++) {
            D_uvgui_rom_00408D78[i].unk28[j] = NULL;
        }
        D_uvgui_rom_00408D78[i].unk168 = 0;
        D_uvgui_rom_00408D78[i].unk16A = -1;
    }
}

s16 func_uvgui_rom_00402B60(void) {
    UnkStruct_uvgui_rom_00400510_unk0_unk28 *var_a0;
    s32 i;

    for (i = 0; i < 50; i++) {
        if (D_uvgui_rom_00408D78[i].unk1E == 0) {
            break;
        }
    }

    D_uvgui_rom_00408D78[i].unk1E = 1;
    return i;
}

UnkStruct_uvgui_rom_00400510_unk0_unk28 *func_uvgui_rom_00402BA0(s16 arg0) {
    return &D_uvgui_rom_00408D78[arg0];
}

void func_uvgui_rom_00402BD0(void *arg0, u8 *arg1) {
    u8 sp30[30];
    s32 i;

    for (i = 0; i < 30; i++) {
        if (arg1[i] >= 'a') {
            sp30[i] = arg1[i] - ' ';
        } else {
            sp30[i] = arg1[i];
        }
    }
    _uvMediaCopy(arg0, sp30, 30);
}

void func_uvgui_rom_00402C34(UnkStruct_uvgui_rom_00400510_unk0_unk28 *arg0, s16 arg1) {
    arg0->unk1E = arg1;
}

void func_uvgui_rom_00402C40(UnkStruct_uvgui_rom_00400510_unk0_unk28 *arg0, s16 arg1, s16 arg2,
                             s16 arg3, s16 arg4) {
    arg0->unk20 = arg1;
    arg0->unk22 = arg2;
    arg0->unk24 = arg3;
    arg0->unk26 = arg4;
    arg0->unk16C = arg0->unk22 - arg0->unk20;
}

void func_uvgui_rom_00402C74(UnkStruct_uvgui_rom_00400510_unk0_unk28 *arg0,
                             UnkStruct_uvgui_rom_00400510_unk0_unk28_inner *arg1) {
    s16 temp_t0;
    s32 i;

    for (i = 0; i < 80; i++) {
        if (arg0->unk28[i] == 0) {
            break;
        }
    }

    if (i == 80) {
        return;
    }

    arg0->unk28[i] = arg1;
    arg0->unk168 = (s16) (arg0->unk168 + 1);
    temp_t0 = arg0->unk24 - (i * 0xC);

    func_uvgui_rom_00401D80(arg1, arg0->unk20, (s16) (arg0->unk20 + 0x40), (temp_t0 - 0xB), temp_t0);
}

void func_uvgui_rom_00402D1C(UnkStruct_uvgui_rom_00400510_unk0_unk28 *arg0) {
    s32 i;
    s32 var_v0;

    switch (arg0->unk1E) {
        case 1:
            var_v0 = 0x7F;
            break;
        case 2:
            var_v0 = 0xFF;
            break;
        default:
            return;
    }
    func_uvgui_rom_00400990(arg0->unk20, arg0->unk22, arg0->unk24, arg0->unk26, 2, 0xD5U, 0xD7U, 0x25U,
                            var_v0);
    switch (arg0->unk1E) {
        case 1:
            var_v0 = 0xFF;
            break;
        case 2:
            var_v0 = 0;
            break;
        default:
            return;
    }
    func_uvgui_rom_00400F44(arg0->unk20, arg0->unk22, arg0->unk24, arg0->unk26, arg0->unk0, var_v0, 0U,
                            0U, 0xFFU);
    if (arg0->unk1E != 1) {
        for (i = 0; i < arg0->unk168; i++) {
            func_uvgui_rom_00401DC4(arg0->unk28[i]);
        }
    }
}

s32 func_uvgui_rom_00402E48(UnkStruct_uvgui_rom_00400510_unk0_unk28 *arg0, u8 arg1, s16 arg2, s16 arg3,
                            s32 arg4, f32 arg5, f32 arg6) {
    UnkStruct_uvgui_rom_00400510_unk0_unk28 *var_s0;
    s32 i;
    s32 var_s3;
    s16 var_v0;

    if (arg0->unk1E == 2) {
        var_s3 = -1;
        for (i = 0; i < arg0->unk168; i++) {
            if (func_uvgui_rom_004020A0(arg0->unk28[i], arg1, arg2, arg3, arg4, arg5, arg6) != 0) {
                var_s3 = i;
            }
        }
        if (i == arg0->unk168) {
            arg0->unk16A = var_s3;
        }
    } else {
        arg0->unk16A = -1;
    }
    if (arg0->unk16A >= 0) {
        return 1;
    }
    if (arg2 < arg0->unk20) {
        arg0->unk1E = 1;
        return 0;
    }
    if (arg0->unk22 < arg2) {
        arg0->unk1E = 1;
        return 0;
    }
    if (arg3 < arg0->unk24) {
        arg0->unk1E = 1;
        return 0;
    }
    if (arg0->unk26 < arg3) {
        arg0->unk1E = 1;
        return 0;
    }
    arg0->unk1E = 2;
    return 1;
}

void func_uvgui_rom_0040300C(void) {
    Inner28 *var_s0;
    s32 i;

    for (i = 0; i < 135; i++) {
        var_s0 = &D_uvgui_rom_0040D558[i];
        var_s0->unk1E = 0;
        var_s0->unk20 = 0x11;
        var_s0->unk30 = 1.0f;
        var_s0->unk34 = -1.0f;
        var_s0->unk28 = 0.0f;
        var_s0->unk24 = 0.0f;
        var_s0->unk2C = 0;
        var_s0->unk44 = 0;
        func_uvgui_rom_00403298(var_s0,
                                (s16) ((s32) (D_uvgui_rom_00407220->uvGetScreenWidth() - 0xB4) / 2),
                                (s16) ((s32) (D_uvgui_rom_00407220->uvGetScreenWidth() + 0xB4) / 2),
                                (s16) ((D_uvgui_rom_00407220->uvGetScreenHeight() - 0x28) / 2),
                                (D_uvgui_rom_00407220->uvGetScreenHeight() + 0x28) / 2);
        var_s0->unk40 = 0;
    }
}

s16 func_uvgui_rom_004031A4(void) {
    s32 i;

    for (i = 0; i < 135; i++) {
        if (D_uvgui_rom_0040D558[i].unk1E == 0) {
            break;
        }
    }
    D_uvgui_rom_0040D558[i].unk1E = 1;
    return i;
}

void func_uvgui_rom_004031E4(s16 arg0) {
    D_uvgui_rom_0040D558[arg0].unk1E = 0;
}

Inner28 *func_uvgui_rom_0040320C(s16 arg0) {
    return &D_uvgui_rom_0040D558[arg0];
}

void func_uvgui_rom_00403234(void *arg0, u8 *arg1) {
    u8 sp30[30];
    s32 i;

    for (i = 0; i < 30; i++) {
        if (arg1[i] >= 'a') {
            sp30[i] = arg1[i] - ' ';
        } else {
            sp30[i] = arg1[i];
        }
    }
    _uvMediaCopy(arg0, sp30, 30);
}

void func_uvgui_rom_00403298(Inner28 *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    arg0->unk38 = arg1;
    arg0->unk3A = arg2;
    arg0->unk3C = arg3;
    arg0->unk3E = arg4;
}

void func_uvgui_rom_004032BC(Inner28 *arg0) {
    u8 var_v0;
    u8 var_v1;
    u8 var_t0;
    u8 var_t1;
    s16 sp7A;
    s16 sp78;
    s16 sp76;
    s16 sp74;
    s16 temp_a0;
    f32 var_fa0;
    s16 pad6A;
    s16 sp68;
    u8 sp50[24];
    s32 temp_v0_4;

    if (arg0->unk2C != 0) {
        if (arg0->unk20 & 2) {
            if ((*arg0->unk2C) < arg0->unk28) {
                var_fa0 = arg0->unk28 - (*arg0->unk2C);
            } else {
                var_fa0 = -(arg0->unk28 - (*arg0->unk2C));
            }
            if (var_fa0 > 1.0f) {
                if (arg0->unk28 >= 0.0f) {
                    arg0->unk28 = *arg0->unk2C;
                } else {
                    arg0->unk28 = *arg0->unk2C;
                }
            }
        } else {
            arg0->unk28 = *((f32 *) arg0->unk2C);
        }
        if (arg0->unk28 >= 0.0f) {
            arg0->unk24 = (f32) ((s32) (arg0->unk28 + 0.5f));
        } else {
            arg0->unk24 = (f32) ((s32) (arg0->unk28 - 0.5f));
        }
    }
    switch (arg0->unk1E) {
        case 1:
            var_v0 = 0xD5;
            var_v1 = 0xD7;
            var_t0 = 0x25;
            var_t1 = 0xFF;
            break;

        case 2:
            var_v0 = 0xFF;
            var_v1 = 0xFF;
            var_t0 = 0xFF;
            var_t1 = 0xFF;
            break;

        default:
            break;
    }

    func_uvgui_rom_00400990(arg0->unk38, arg0->unk3A, arg0->unk3C, arg0->unk3E, 2, var_v0, var_v1,
                            var_t0, var_t1);
    sp7A = arg0->unk38 + 5;
    sp78 = arg0->unk3A - 5;
    sp76 = (arg0->unk3C + (((s32) (arg0->unk3E - arg0->unk3C)) / 5)) + 5;
    sp74 = arg0->unk3E - 5;
    if (arg0->unk1E == 2) {
        func_uvgui_rom_00400990(sp7A, sp78, sp76, sp74, 2, 0x32U, 0x32U, 0x32U, 0xFFU);
    }
    if (arg0->unk34 != arg0->unk30) {
        var_fa0 = (arg0->unk28 - arg0->unk30) / (arg0->unk34 - arg0->unk30);
    } else {
        var_fa0 = 0.5f;
    }
    if (arg0->unk20 & 2) {
        temp_v0_4 = ((s32) arg0->unk34) - ((s32) arg0->unk30);
        if (temp_v0_4 > 0) {
            var_fa0 = ((f32) ((s32) ((temp_v0_4 * var_fa0) + 0.5f))) / temp_v0_4;
        } else {
            var_fa0 = 0.5f;
        }
    }
    if (arg0->unk1E == 2) {
        var_t0 = 0xFF;
        var_v1 = 0xFF;
        var_v0 = 0xFF;
        var_t1 = 0xFF;
        // FAKE
        if (1) {
        }
    } else {
        var_t0 = 0;
        var_v1 = 0;
        var_v0 = 0;
        var_t1 = 0x50;
    }
    temp_a0 = (s32) (((f32) ((s16) ((sp78 - sp7A) - 0xC))) * var_fa0);
    temp_a0 = (sp7A + temp_a0) + 3;
    func_uvgui_rom_00400990(temp_a0, temp_a0 + 6, sp76 + 2, sp74 - 2, 2, var_v0, var_v1, var_t0,
                            var_t1);
    if ((arg0->unk44 != 0) && (arg0->unk20 & 2)) {
        func_uvgui_rom_00403234(arg0, arg0->unk44[(s32) arg0->unk24]);
    }
    D_uvgui_rom_0040721C->uvFontWidth(&arg0->unk0);
    D_uvgui_rom_0040721C->uvFontColor(0, 0, 0, 255);
    D_uvgui_rom_0040721C->uvFontPrintStr(arg0->unk38 + 7, arg0->unk3C + 2, &arg0->unk0);
    if (arg0->unk20 & 0x10) {
        if (arg0->unk20 & 1) {
            D_uvgui_rom_00407234->uvSprintf(sp50, "%f", arg0->unk28);
        }
        if (arg0->unk20 & 2) {
            D_uvgui_rom_00407234->uvSprintf(sp50, "%d", (s32) arg0->unk24);
        }
        sp68 = D_uvgui_rom_0040721C->uvFontWidth(sp50);
        D_uvgui_rom_0040721C->uvFontColor(0, 0, 0, 255);
        D_uvgui_rom_0040721C->uvFontPrintStr((arg0->unk3A - sp68) - 7, arg0->unk3C + 2, sp50);
    }
}

void func_uvgui_rom_004037D8(Inner28 *arg0, s32 arg1) {
    arg0->unk40 = arg1;
}

void func_uvgui_rom_004037E0(Inner28 *arg0, f32 arg1, f32 arg2, f32 arg3, s32 *arg4);

void func_uvgui_rom_004037E0(Inner28 *arg0, f32 arg1, f32 arg2, f32 arg3, s32 *arg4) {
    f32 temp_fv0;

    arg0->unk30 = arg1;
    arg0->unk2C = arg4;
    arg0->unk34 = arg2;
    if (arg0->unk2C != NULL) {
        if (arg0->unk20 & 2) {
            arg0->unk28 = *arg0->unk2C;
        } else {
            arg0->unk28 = *(f32 *) arg0->unk2C;
        }
    } else {
        arg0->unk28 = arg3;
    }

    if (arg0->unk20 & 2) {
        if (arg0->unk28 >= 0.0f) {
            arg0->unk24 = (s32) (arg0->unk28 + 0.5f);
        } else {
            arg0->unk24 = (s32) (arg0->unk28 - 0.5f);
        }
    } else {
        arg0->unk24 = arg0->unk28;
    }
}

void func_uvgui_rom_004038D8(Inner28 *arg0, s16 arg1) {
    arg0->unk20 = arg1;
}
    
void func_uvgui_rom_004038E4(Inner28 *arg0, u8 arg1, f32 arg2) {
    f32 temp_ft4;
    f32 var_fv1;
    f32 var_fv0;
    if (arg0->unk1E != 2) {
        return;
    }
    if ((arg0->unk2C != 0) && (!(arg0->unk20 & 2))) {
        arg0->unk28 = *((f32 *) arg0->unk2C);
    }
    temp_ft4 = (arg0->unk34 - arg0->unk30) * 0.5f;
    var_fv1 = D_uvgui_rom_00407220->func_uvgfxmgr_rom_00401004();
    if (arg2 > 0.0f) {
        arg2 *= arg2;
    } else {
        arg2 *= -arg2;
    }
    if (arg0->unk20 == 0x11) {
        arg0->unk28 += ((0.5f * arg2) * temp_ft4) * var_fv1;
        if (arg0->unk28 < arg0->unk30) {
            arg0->unk28 = arg0->unk30;
        } else if (arg0->unk28 > arg0->unk34) {
            arg0->unk28 = arg0->unk34;
        }
        arg0->unk24 = arg0->unk28;
    } else {
        var_fv0 = 20.0f / (arg0->unk34 - arg0->unk30);
        if (var_fv0 < 1.0f) {
            var_fv0 = 1.0f;
        } else if (var_fv0 > 100.0f) {
            var_fv0 = 100.0f;
        }
        var_fv0 = (((var_fv0 * 0.5f) * arg2) * temp_ft4) * var_fv1;
        if (D_uvgui_rom_00407230->uvControllerButtonPress(arg1, 0x0200) != 0) {
            var_fv0 = -1.0f;
        }
        if (D_uvgui_rom_00407230->uvControllerButtonPress(arg1, 0x0100) != 0) {
            var_fv0 = 1.0f;
        }
        arg0->unk28 += var_fv0;
        if (arg0->unk28 < arg0->unk30) {
            arg0->unk28 = arg0->unk30;
        } else if (arg0->unk28 > arg0->unk34) {
            arg0->unk28 = arg0->unk34;
        }
        arg0->unk24 = ROUNDF(arg0->unk28);
    }
    if (arg0->unk2C != 0) {
        if (arg0->unk20 & 2) {
            *arg0->unk2C = ROUNDF(arg0->unk28);
        } else {
            *((f32 *) arg0->unk2C) = arg0->unk28;
        }
    }
    if (arg0->unk40 != 0) {
        arg0->unk40(arg0);
    }
}

void func_uvgui_rom_00403C50(Inner28* arg0, s16 arg1) {
    if (arg1 != arg0->unk1E) {
        if (arg0->unk40 != NULL) {
            arg0->unk40(arg0);
        }
    }
    arg0->unk1E = arg1;
}


void func_uvgui_rom_00403CA4(Inner28 *arg0, s32 arg1) {
    arg0->unk44 = arg1;
}

void func_uvgui_rom_00403CAC(void) {
    Inner30 *var_s0;
    s32 i;

    for (i = 0; i < 20; i++) {
        var_s0 = &D_uvgui_rom_0040FB50[i];
        var_s0->unk5E = 0;
        var_s0->unk68 = 0.0f;
        var_s0->unk6C = -1.0f;
        var_s0->unk70 = 1.0f;
        var_s0->unk80 = 0;
        var_s0->unk74 = 0.0f;
        var_s0->unk78 = -1.0f;
        var_s0->unk7C = 1.0f;
        var_s0->unk60 = -1;
        var_s0->unk62 = 1;
        func_uvgui_rom_00403F08(var_s0, ((D_uvgui_rom_00407220->uvGetScreenWidth() / 2) - 0x50),
                                ((D_uvgui_rom_00407220->uvGetScreenWidth() / 2) + 0x50),
                                ((D_uvgui_rom_00407220->uvGetScreenHeight() / 2) - 0x50),
                                (D_uvgui_rom_00407220->uvGetScreenHeight() / 2) + 0x50);
        var_s0->unk8C = 0;
        func_uvgui_rom_00403F2C(var_s0, "INPUT", "OUTPUT");
    }
}

s16 func_uvgui_rom_00403E78(void) {
    s32 i;

    for (i = 0; i < 20; i++) {
        if (D_uvgui_rom_0040FB50[i].unk5E == 0) {
            break;
        }
    }
    D_uvgui_rom_0040FB50[i].unk5E = 1;
    return i;
}

void func_uvgui_rom_00403EB8(s16 arg0) {
    D_uvgui_rom_0040FB50[arg0].unk5E = 0;
}

Inner30 *func_uvgui_rom_00403EE0(s16 arg0) {
    return &D_uvgui_rom_0040FB50[arg0];
}

void func_uvgui_rom_00403F08(Inner30 *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    arg0->unk84 = arg1;
    arg0->unk86 = arg2;
    arg0->unk88 = arg3;
    arg0->unk8A = arg4;
}

void func_uvgui_rom_00403F2C(Inner30 *arg0, u8 *arg1, u8 *arg2) {
    u8 sp30[0x1E];
    s32 i;

    D_uvgui_rom_00407234->uvSprintf(arg0->unk40, "%s_vs_%s", arg1, arg2);
    for (i = 0; i < 0x1E; i++) {
        if (arg1[i] >= 'a') {
            sp30[i] = arg1[i] - ' ';
        } else {
            sp30[i] = arg1[i];
        }
    }
    _uvMediaCopy(arg0->unk4, sp30, 0x1EU);
    for (i = 0; i < 0x1E; i++) {
        if (arg2[i] >= 'a') {
            sp30[i] = arg2[i] - ' ';
        } else {
            sp30[i] = arg2[i];
        }
    }
    _uvMediaCopy(arg0->unk22, sp30, 0x1EU);
}

void func_uvgui_rom_00404010(Inner30 *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 *arg5) {
    arg0->unk0 = arg1;
    arg0->unk6C = arg2;
    arg0->unk80 = arg5;
    arg0->unk70 = arg3;
    if (arg5 != NULL) {
        arg0->unk68 = *arg5;
        return;
    }
    arg0->unk68 = arg4;
}

void func_uvgui_rom_0040404C(Inner30 *arg0, s32 arg1) {
    arg0->unk8C = arg1;
}

void func_uvgui_rom_00404054(Inner30 *arg0, u8 button, f32 arg2) {
    UvGrphInnerStruct *temp_t1;
    UvGrphInnerStruct *var_t2;
    UvGrphInnerStruct *var_t0;
    UvGrphStruct *sp38;
    f32 var_fa0_2;
    f32 temp_fv1;
    f32 var_fa1;
    f32 sp28;
    f32 sp24;
    s32 i;

    if ((arg0->unk0 == NULL) || (arg0->unk5E != 2)) {
        arg0->unk60 = -1;
        return;
    }
    sp38 = arg0->unk0;
    // FAKE: Increase compiler stack for arg1
    if (button) {
    }

    if (D_uvgui_rom_00407230->uvControllerButtonPress(button, START_BUTTON) != 0) {
        D_uvgui_rom_0040722C->func_uvgrph_rom_00400148(arg0->unk40, &sp38->count);
        arg0->unk64 = 0x3C;
    }
    sp28 = (arg0->unk70 - arg0->unk6C) * 0.5f;
    sp24 = D_uvgui_rom_00407220->func_uvgfxmgr_rom_00401004();
    if (arg0->unk80 != NULL) {
        arg0->unk68 = *arg0->unk80;
    }
    if (arg2 > 0.0f) {
        arg2 *= arg2;
    } else {
        arg2 *= -arg2;
    }
    if (arg0->unk62) {
        arg0->unk68 += 0.5f * arg2 * sp28 * sp24;
        if (arg0->unk68 < arg0->unk6C) {
            arg0->unk68 = arg0->unk6C;
        } else {
            if (arg0->unk70 < arg0->unk68) {
                arg0->unk68 = arg0->unk70;
            }
        }

        // FAKE
        if (1) {
        }
    }

    if (arg0->unk80 != NULL) {
        *arg0->unk80 = arg0->unk68;
    }
    if (D_uvgui_rom_00407230->uvControllerButtonHeld(button, Z_TRIG) != 0) {
        if (D_uvgui_rom_00407230->uvControllerButtonPress(button, L_CBUTTONS) != 0) {
            arg0->unk60 -= 1;
            if (arg0->unk60 < 0) {
                arg0->unk60 = sp38->count - 1;
            }
        }
        if (D_uvgui_rom_00407230->uvControllerButtonPress(button, R_CBUTTONS) != 0) {
            arg0->unk60 += 1;
            if (arg0->unk60 >= sp38->count) {
                arg0->unk60 = 0;
            }
        }
        if (D_uvgui_rom_00407230->uvControllerButtonPress(button, U_CBUTTONS) != 0) {
            arg0->unk60 = D_uvgui_rom_0040722C->func_uvgrph_rom_00400194(sp38, (s32) arg0->unk60);
        }
        if (D_uvgui_rom_00407230->uvControllerButtonPress(button, D_CBUTTONS) != 0) {
            arg0->unk60 = D_uvgui_rom_0040722C->func_uvgrph_rom_004002AC(sp38, (s32) arg0->unk60);
        }
        if (arg0->unk60 == -1) {
            return;
        }
    }

    temp_t1 = &sp38->arr[arg0->unk60];
    if (arg0->unk60 < (sp38->count - 1)) {
        var_t2 = &sp38->arr[arg0->unk60 + 1];
    } else {
        var_t2 = NULL;
    }
    if (arg0->unk60 >= 2) {
        var_t0 = &sp38->arr[arg0->unk60 - 1];
    } else {
        var_t0 = NULL;
    }

    var_fa0_2 = sp38->arr->x;
    temp_fv1 = sp38->arr[sp38->count - 1].x;
    if (D_uvgui_rom_00407230->uvControllerButtonHeld(button, Z_TRIG) == 0) {
        if (D_uvgui_rom_00407230->uvControllerButtonHeld(button, L_CBUTTONS) != 0) {
            temp_t1->x -= (temp_fv1 - var_fa0_2) * 0.0025f;
            if (var_t0 != NULL) {
                if (temp_t1->x < var_t0->x) {
                    temp_t1->x = var_t0->x;
                }
            }
        }
        if (D_uvgui_rom_00407230->uvControllerButtonHeld(button, R_CBUTTONS) != 0) {
            temp_t1->x += (temp_fv1 - var_fa0_2) * 0.0025f;
            if (var_t2 != NULL) {
                if (var_t2->x < temp_t1->x) {
                    temp_t1->x = var_t2->x;
                }
            }
        }
        var_fa0_2 = 1000000.0f;
        for (i = 0; i < sp38->count; i++) {
            if (sp38->arr[i].y < var_fa0_2) {
                var_fa0_2 = sp38->arr[i].y;
            }
        }
        temp_fv1 = -1000000.0f;
        for (i = 0; i < sp38->count; i++) {
            if (temp_fv1 < sp38->arr[i].y) {
                temp_fv1 = sp38->arr[i].y;
            }
        }

        var_fa1 = (temp_fv1 - var_fa0_2) * 0.15f * sp24;
        if (var_fa1 < 0.005f) {
            var_fa1 = 0.005f;
        } else if (var_fa1 > 10.0f) {
            var_fa1 = 10.0f;
        }
        if (D_uvgui_rom_00407230->uvControllerButtonHeld(button, D_CBUTTONS) != 0) {
            temp_t1->y -= var_fa1;
        }
        if (D_uvgui_rom_00407230->uvControllerButtonHeld(button, U_CBUTTONS) != 0) {
            temp_t1->y += var_fa1;
        }
    }

    if (arg0->unk8C != NULL) {
        arg0->unk8C(arg0);
    }
}

void func_uvgui_rom_004046B4(Inner30 *arg0) {
    UvGrphStruct *sp1D4;
    f32 spA4;
    f32 temp_fa1;
    f32 sp1C8;
    f32 sp1C4;
    f32 sp1C0;
    f32 var_fs0;
    f32 var_fs1;
    f32 var_fs2;
    f32 var_fs3;
    f32 temp_fs5;
    f32 sp1A8;
    f32 sp1A4;
    f32 sp1A0;
    f32 sp19C;
    UvGrphInnerStruct *s0;
    f32 sp194;
    u8 var_s6;
    u8 sp192;
    u8 var_s5;
    u8 sp190;
    Mtx4F sp150;
    Mtx4F sp110;
    u8 spD4[0x3C];
    s32 i;
    UvGrphInnerStruct *var_v0;
    UvGrphInnerStruct *var_v1;

    static s32 D_uvgui_rom_00406F08 = 0;

    sp1D4 = arg0->unk0;
    if ((sp1D4 == NULL) || (sp1D4->count == 0)) {
        return;
    }

    if (arg0->unk80 != NULL) {
        arg0->unk68 = *arg0->unk80;
    }
    D_uvgui_rom_00407220->func_uvgfxmgr_rom_00401BD4(0, D_uvgui_rom_00407220->uvGetScreenWidth() - 1, 0,
                                                     D_uvgui_rom_00407220->uvGetScreenHeight() - 1);
    D_uvgui_rom_00407218->uvMat4SetOrtho(&sp150, 0.0f, (D_uvgui_rom_00407220->uvGetScreenWidth() - 1),
                                         0.0f, (D_uvgui_rom_00407220->uvGetScreenHeight() - 1));
    D_uvgui_rom_00407218->uvGfxMtxProjPushF(&sp150);
    D_uvgui_rom_00407218->uvMat4SetIdentity(&sp110);
    D_uvgui_rom_00407218->func_uvfmtx_rom_004029DC(&sp110);
    D_uvgui_rom_00407224->uvGfxStatePush();
    D_uvgui_rom_00407224->uvGfxStateSetFlags(0x800FFF);
    D_uvgui_rom_00407224->func_uvgfxstate_rom_00401354(0x600000);
    D_uvgui_rom_00407228->uvVtxBeginPoly();
    D_uvgui_rom_00407228->uvVtx(arg0->unk84 - 2, arg0->unk88 - 2, 0, 0, 0, 0, 0, 0, 0x7F);
    D_uvgui_rom_00407228->uvVtx(arg0->unk86 + 2, arg0->unk88 - 2, 0, 0, 0, 0, 0, 0, 0x7F);
    D_uvgui_rom_00407228->uvVtx(arg0->unk86 + 2, arg0->unk8A + 2, 0, 0, 0, 0, 0, 0, 0x7F);
    D_uvgui_rom_00407228->uvVtx(arg0->unk84 - 2, arg0->unk8A + 2, 0, 0, 0, 0, 0, 0, 0x7F);
    D_uvgui_rom_00407228->uvVtxEndPoly();
    D_uvgui_rom_00407224->uvGfxStatePop();
    sp1A8 = sp1D4->arr->x;
    sp1A4 = sp1D4->arr[sp1D4->count - 1].x;

    sp1A0 = 1000000.0f;
    for (i = 0; i < sp1D4->count; i++) {
        if (sp1D4->arr[i].y < sp1A0) {
            sp1A0 = sp1D4->arr[i].y;
        }
    }
    sp19C = -1000000.0f;
    for (i = 0; i < sp1D4->count; i++) {
        if (sp19C < sp1D4->arr[i].y) {
            sp19C = sp1D4->arr[i].y;
        }
    }

    if (ABS_2(sp1A0 - sp19C) < 2.0f) {
        sp1A0 -= (0.01f * (sp1A4 - sp1A8));
        sp19C += (0.01f * (sp1A4 - sp1A8));
    }

    sp1C0 = (sp1A4 - sp1A8) * 0.02f;
    spA4 = ((sp19C - sp1A0) / (sp1A4 - sp1A8));
    temp_fs5 = (f32) (arg0->unk86 - arg0->unk84) / (sp1A4 - sp1A8);
    sp194 = (f32) (arg0->unk8A - arg0->unk88) / (sp19C - sp1A0);
    D_uvgui_rom_00407220->func_uvgfxmgr_rom_00401BD4(arg0->unk84, arg0->unk86, arg0->unk88,
                                                     arg0->unk8A);
    D_uvgui_rom_00407218->uvMat4SetOrtho(
        &sp150, (sp1A8 - (2.0f * sp1C0)) * temp_fs5, ((2.0f * sp1C0) + sp1A4) * temp_fs5,
        (sp1A0 - ((2.0f * sp1C0) * spA4)) * sp194, (((2.0f * sp1C0) * spA4) + sp19C) * sp194);
    D_uvgui_rom_00407218->uvGfxMtxProjPushF(&sp150);
    D_uvgui_rom_00407218->uvMat4SetIdentity(&sp110);
    D_uvgui_rom_00407218->func_uvfmtx_rom_004029DC(&sp110);
    D_uvgui_rom_00407224->uvGfxStatePush();
    D_uvgui_rom_00407224->uvGfxStateSetFlags(0x800FFF);
    D_uvgui_rom_00407224->func_uvgfxstate_rom_00401354(0x600000);
    for (i = 0; i < (sp1D4->count - 1); i++) {
        var_v0 = &sp1D4->arr[i];
        var_v1 = &sp1D4->arr[i + 1];
        sp1C8 = var_v0->x * temp_fs5;
        sp1C4 = var_v1->x * temp_fs5;
        var_fs2 = var_v0->y * sp194;
        var_fs0 = var_v1->y * sp194;
        if (arg0->unk5E == 2) {
            if (arg0->unk64 > 0) {
                arg0->unk64--;
                var_s6 = 0xFF;
                sp192 = 0;
                var_s5 = 0;
                sp190 = 0xFF;
            } else {
                if (i % 2) {
                    var_s6 = 0xFF;
                    sp192 = 0xFF;
                    var_s5 = 0xFF;
                    sp190 = 0x7F;
                } else {
                    var_s6 = 0xC8;
                    sp192 = 0xC8;
                    var_s5 = 0xC8;
                    sp190 = 0x7F;
                }
            }
        } else {
            var_s6 = 0xFF;
            sp192 = 0xFF;
            var_s5 = 0;
            sp190 = 0x7F;
        }
        if ((var_fs2 < 0) && (var_fs0 < 0)) {
            var_fs3 = var_fs2;
            var_fs1 = var_fs0;
            var_fs0 = 0;
            var_fs2 = 0;
        } else {
            var_fs1 = 0;
            var_fs3 = 0;
        }
        if ((var_fs2 >= 0) && (var_fs0 >= 0)) {
            D_uvgui_rom_00407228->uvVtxBeginPoly();
            D_uvgui_rom_00407228->uvVtx(sp1C8, var_fs3, 0, 0, 0, var_s6, sp192, var_s5, sp190);
            D_uvgui_rom_00407228->uvVtx(sp1C4, var_fs1, 0, 0, 0, var_s6, sp192, var_s5, sp190);
            D_uvgui_rom_00407228->uvVtx(sp1C4, var_fs0, 0, 0, 0, var_s6, sp192, var_s5, sp190);
            D_uvgui_rom_00407228->uvVtx(sp1C8, var_fs2, 0, 0, 0, var_s6, sp192, var_s5, sp190);
            D_uvgui_rom_00407228->uvVtxEndPoly();
        } else {
            f32 var_fs1 = var_v0->x * temp_fs5;
            f32 var_fs0 = var_v0->y * sp194;
            f32 var_fs2 = var_v1->x * temp_fs5;
            f32 var_fs3 = var_v1->y * sp194;
            if (var_fs3 < var_fs0) {
                D_uvgui_rom_00407228->uvVtxBeginPoly();
                D_uvgui_rom_00407228->uvVtx(var_fs1, 0, 0, 0, 0, var_s6, sp192, var_s5, sp190);
                D_uvgui_rom_00407228->uvVtx(
                    (var_fs2 - ((var_fs3 / (var_fs3 - var_fs0)) * (var_fs2 - var_fs1))), 0, 0, 0, 0,
                    var_s6, sp192, var_s5, sp190);
                D_uvgui_rom_00407228->uvVtx(var_fs1, var_fs0, 0, 0, 0, var_s6, sp192, var_s5, sp190);
                D_uvgui_rom_00407228->uvVtxEndPoly();
                D_uvgui_rom_00407228->uvVtxBeginPoly();
                D_uvgui_rom_00407228->uvVtx(
                    (var_fs2 - ((var_fs3 / (var_fs3 - var_fs0)) * (var_fs2 - var_fs1))), 0, 0, 0, 0,
                    var_s6, sp192, var_s5, sp190);
                D_uvgui_rom_00407228->uvVtx(var_fs2, var_fs3, 0, 0, 0, var_s6, sp192, var_s5, sp190);
                D_uvgui_rom_00407228->uvVtx(var_fs2, 0, 0, 0, 0, var_s6, sp192, var_s5, sp190);
                D_uvgui_rom_00407228->uvVtxEndPoly();
            } else {
                D_uvgui_rom_00407228->uvVtxBeginPoly();
                D_uvgui_rom_00407228->uvVtx(var_fs1, 0, 0, 0, 0, var_s6, sp192, var_s5, sp190);
                D_uvgui_rom_00407228->uvVtx(var_fs1, var_fs0, 0, 0, 0, var_s6, sp192, var_s5, sp190);
                D_uvgui_rom_00407228->uvVtx(
                    (var_fs2 - ((var_fs3 / (var_fs3 - var_fs0)) * (var_fs2 - var_fs1))), 0, 0, 0, 0,
                    var_s6, sp192, var_s5, sp190);
                D_uvgui_rom_00407228->uvVtxEndPoly();
                D_uvgui_rom_00407228->uvVtxBeginPoly();
                D_uvgui_rom_00407228->uvVtx(
                    (var_fs2 - ((var_fs3 / (var_fs3 - var_fs0)) * (var_fs2 - var_fs1))), 0, 0, 0, 0,
                    var_s6, sp192, var_s5, sp190);
                D_uvgui_rom_00407228->uvVtx(var_fs2, 0, 0, 0, 0, var_s6, sp192, var_s5, sp190);
                D_uvgui_rom_00407228->uvVtx(var_fs2, var_fs3, 0, 0, 0, var_s6, sp192, var_s5, sp190);
                D_uvgui_rom_00407228->uvVtxEndPoly();
            }
        }
    }
    if ((sp1A8 < 0) && (sp1A4 > 0)) {
        D_uvgui_rom_00407228->uvVtxBeginPoly();
        D_uvgui_rom_00407228->uvVtx(-1, (sp1A0 * sp194), 0, 0, 0, 0, 0, 0, 0xFF);
        D_uvgui_rom_00407228->uvVtx(1, (sp1A0 * sp194), 0, 0, 0, 0, 0, 0, 0xFF);
        D_uvgui_rom_00407228->uvVtx(1, (sp19C * sp194), 0, 0, 0, 0, 0, 0, 0xFF);
        D_uvgui_rom_00407228->uvVtx(-1, (sp19C * sp194), 0, 0, 0, 0, 0, 0, 0xFF);
        D_uvgui_rom_00407228->uvVtxEndPoly();
    }
    if ((sp1A0 < 0) && (sp19C > 0)) {
        D_uvgui_rom_00407228->uvVtxBeginPoly();
        D_uvgui_rom_00407228->uvVtx((sp1A8 * temp_fs5), -1, 0, 0, 0, 0, 0, 0, 0xFF);
        D_uvgui_rom_00407228->uvVtx((sp1A4 * temp_fs5), -1, 0, 0, 0, 0, 0, 0, 0xFF);
        D_uvgui_rom_00407228->uvVtx((sp1A4 * temp_fs5), 1, 0, 0, 0, 0, 0, 0, 0xFF);
        D_uvgui_rom_00407228->uvVtx((sp1A8 * temp_fs5), 1, 0, 0, 0, 0, 0, 0, 0xFF);
        D_uvgui_rom_00407228->uvVtxEndPoly();
    }
    if ((arg0->unk60 != -1) && (arg0->unk60 < sp1D4->count)) {
        s0 = &sp1D4->arr[arg0->unk60];
        sp1C0 *= 0.5f;
        sp1C8 = (s0->x - sp1C0) * temp_fs5;
        sp1C4 = (s0->x + sp1C0) * temp_fs5;
        temp_fa1 = sp1C0 * spA4;
        var_fs3 = (s0->y - temp_fa1) * sp194;
        var_fs2 = (s0->y + temp_fa1) * sp194;
        sp1C0 *= 2.0f;
        D_uvgui_rom_00406F08 = !D_uvgui_rom_00406F08;
        if (D_uvgui_rom_00406F08) {
            var_s6 = 0xFF;
            sp192 = 0xFF;
            var_s5 = 0;
            sp190 = 0xFF;
        } else {
            var_s6 = 0;
            sp192 = 0;
            var_s5 = 0;
            sp190 = 0xFF;
        }

        D_uvgui_rom_00407228->uvVtxBeginPoly();
        D_uvgui_rom_00407228->uvVtx(sp1C8, var_fs3, 0, 0, 0, var_s6, sp192, var_s5, sp190);
        D_uvgui_rom_00407228->uvVtx(sp1C4, var_fs3, 0, 0, 0, var_s6, sp192, var_s5, sp190);
        D_uvgui_rom_00407228->uvVtx(sp1C4, var_fs2, 0, 0, 0, var_s6, sp192, var_s5, sp190);
        D_uvgui_rom_00407228->uvVtx(sp1C8, var_fs2, 0, 0, 0, var_s6, sp192, var_s5, sp190);
        D_uvgui_rom_00407228->uvVtxEndPoly();
    }
    arg0->unk74 = D_uvgui_rom_0040722C->func_uvgrph_rom_00400080(sp1D4, arg0->unk68);
    temp_fa1 = (sp1C0 * spA4);
    sp1C8 = (arg0->unk68 - sp1C0) * temp_fs5;
    sp1C4 = (arg0->unk68 + sp1C0) * temp_fs5;
    var_fs3 = ((arg0->unk74 - temp_fa1) * sp194);
    var_fs2 = ((arg0->unk74 + temp_fa1) * sp194);

    D_uvgui_rom_00407228->uvVtxBeginPoly();
    D_uvgui_rom_00407228->uvVtx(sp1C8, (arg0->unk74 * sp194), 0, 0, 0, 0, 0xFF, 0xFF, 0xFF);
    D_uvgui_rom_00407228->uvVtx((arg0->unk68 * temp_fs5), var_fs3, 0, 0, 0, 0, 0xFF, 0xFF, 0xFF);
    D_uvgui_rom_00407228->uvVtx(sp1C4, (arg0->unk74 * sp194), 0, 0, 0, 0, 0xFF, 0xFF, 0xFF);
    D_uvgui_rom_00407228->uvVtx((arg0->unk68 * temp_fs5), var_fs2, 0, 0, 0, 0, 0xFF, 0xFF, 0xFF);
    D_uvgui_rom_00407228->uvVtxEndPoly();
    if (arg0->unk5E != 2) {
        D_uvgui_rom_0040721C->uvFontColor(0xFF, 0xFF, 0, 0xFF);
        D_uvgui_rom_00407234->uvSprintf(spD4, "%s * %s", arg0->unk4, arg0->unk22);
        D_uvgui_rom_0040721C->uvFontPrintStr(
            (s32) ((arg0->unk84 + arg0->unk86) - D_uvgui_rom_0040721C->uvFontWidth(spD4)) / 2,
            (arg0->unk8A - D_uvgui_rom_0040721C->uvFontHeight()) - 2, spD4);
    }
    if (arg0->unk5E == 2) {
        var_s6 = 0;
    } else {
        var_s6 = 0xFF;
    }
    D_uvgui_rom_0040721C->uvFontColor(var_s6, 0xFF, 0xFF, 0xFF);
    D_uvgui_rom_00407234->uvSprintf(spD4, "%f", arg0->unk68);
    D_uvgui_rom_0040721C->uvFontPrintStr(arg0->unk84 + 4, arg0->unk88 - 2, spD4);
    D_uvgui_rom_00407234->uvSprintf(spD4, "%f", arg0->unk74);
    D_uvgui_rom_0040721C->uvFontPrintStr((arg0->unk86 - D_uvgui_rom_0040721C->uvFontWidth(spD4)) - 4,
                                         arg0->unk88 - 2, spD4);
    if ((arg0->unk5E == 2) && (arg0->unk60 != -1)) {
        D_uvgui_rom_0040721C->uvFontColor(0xFF, 0xFF, 0, 0xFF);
        s0 = &sp1D4->arr[arg0->unk60];
        D_uvgui_rom_00407234->uvSprintf(spD4, "%f", s0->x);
        D_uvgui_rom_0040721C->uvFontPrintStr(
            arg0->unk84 + 4, arg0->unk8A - (D_uvgui_rom_0040721C->uvFontHeight() * 2), spD4);
        D_uvgui_rom_00407234->uvSprintf(spD4, "%f", s0->y);
        D_uvgui_rom_0040721C->uvFontPrintStr(
            (arg0->unk86 - D_uvgui_rom_0040721C->uvFontWidth(spD4)) - 4,
            arg0->unk8A - (D_uvgui_rom_0040721C->uvFontHeight() * 2), spD4);
    }
    D_uvgui_rom_00407224->uvGfxStatePop();
    D_uvgui_rom_00407220->func_uvgfxmgr_rom_00401BD4(0, D_uvgui_rom_00407220->uvGetScreenWidth() - 1, 0,
                                                     D_uvgui_rom_00407220->uvGetScreenHeight() - 1);
    D_uvgui_rom_00407218->uvMat4SetOrtho(&sp150, -0.5f, D_uvgui_rom_00407220->uvGetScreenWidth() + 0.5f,
                                         -0.5f, D_uvgui_rom_00407220->uvGetScreenHeight() + 0.5f);
    D_uvgui_rom_00407218->uvGfxMtxProjPushF(&sp150);
}

void func_uvgui_rom_00405CEC(Inner30 *arg0, s16 arg1) {
    if ((arg1 == 2) && (arg0->unk5E != 2)) {
        arg0->unk60 = 0;
    }
    arg0->unk5E = arg1;
}

void func_uvgui_rom_00405D1C(Inner30 *arg0, ...) {
    s16 prop;
    va_list args;

    va_start(args, arg0);
    while (TRUE) {
        prop = va_arg(args, s32);
        if (prop == 0) {
            break;
        }
        if (prop != 1) {
            break;
        }
        arg0->unk62 = va_arg(args, s32);
    }
    va_end(args);
}

void func_uvgui_rom_00405D78(void) {
    Inner2C *var_s0;
    s32 i;

    for (i = 0; i < 10; i++) {
        var_s0 = &D_uvgui_rom_00406F20[i];
        var_s0->unk1E = 0;
        var_s0->unk20 = 1;
        var_s0->unk34 = 1.0f;
        var_s0->unk38 = -1.0f;
        var_s0->unk24 = 0.0f;
        var_s0->unk28 = 0.0f;
        var_s0->unk2C = 0.0f;
        var_s0->unk30 = 0;
        var_s0->unk44 = -1;
        func_uvgui_rom_00406024(var_s0,
                                (s16) ((s32) (D_uvgui_rom_00407220->uvGetScreenWidth() - 0xB4) / 2),
                                ((D_uvgui_rom_00407220->uvGetScreenWidth() + 0xB4) / 2),
                                (s16) ((s32) (D_uvgui_rom_00407220->uvGetScreenHeight() - 0x50) / 2),
                                (s32) (D_uvgui_rom_00407220->uvGetScreenHeight() + 0x50) / 2);
        var_s0->unk48 = 0;
    }
}

s16 func_uvgui_rom_00405F20(void) {
    s32 i;

    i = 0;
    for (i = 0; i < 10; i++) {
        if (D_uvgui_rom_00406F20[i].unk1E == 0) {
            break;
        }
    }
    D_uvgui_rom_00406F20[i].unk1E = 1;
    return i;
}

void func_uvgui_rom_00405F60(s16 arg0) {
    D_uvgui_rom_00406F20[arg0].unk1E = 0;
}

Inner2C *func_uvgui_rom_00405F90(s16 arg0) {
    return &D_uvgui_rom_00406F20[arg0];
}

void func_uvgui_rom_00405FC0(Inner2C *arg0, u8 *arg1) {
    u8 sp30[0x1E];
    s32 i;

    for (i = 0; i < 0x1E; i++) {
        if (arg1[i] >= 'a') {
            sp30[i] = arg1[i] - ' ';
        } else {
            sp30[i] = arg1[i];
        }
    }

    _uvMediaCopy(arg0->unk0, sp30, 0x1EU);
}

void func_uvgui_rom_00406024(Inner2C *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    arg0->unk3C = arg1;
    arg0->unk3E = arg2;
    arg0->unk40 = arg3;
    arg0->unk42 = arg4;
}

void func_uvgui_rom_00406048(Inner2C *arg0) {
    u8 spAF;
    u8 spAE;
    u8 spAD;
    u8 spAC;
    s16 spAA;
    s16 spA8;
    s16 spA6;
    s16 spA4;
    s16 spA2;
    s16 spA0;
    s16 sp9E;
    s16 sp9C;
    s16 sp9A;
    s16 sp98;
    s16 sp96;
    s16 sp94;
    s16 sp92;
    s16 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    u8 sp6C[0x18];
    f32 sp68;
    f32 temp_fa1;
    s32 pad;
    f32 sp5C;

    if (arg0->unk30 != 0) {
        arg0->unk24 = arg0->unk30->x;
        arg0->unk28 = arg0->unk30->y;
        arg0->unk2C = arg0->unk30->z;
    }

    // clang-format off
    switch (arg0->unk1E) {
        case 1:
            spAF = 0xD5;\
            spAE = 0xD7;\
            spAD = 0x25;\
            spAC = 0xFF;
            break;
        case 2:
            spAF = 0xFF;\
            spAE = 0xFF;\
            spAD = 0xFF;\
            spAC = 0xFF;
            break;
    }
    // clang-format on

    func_uvgui_rom_00400990(arg0->unk3C, arg0->unk3E, arg0->unk40, arg0->unk42, 2, spAF, spAE, spAD,
                            spAC);
    if (arg0->unk20 == 1) {
        sp94 = arg0->unk3E - 5;
        sp92 = arg0->unk40 + 5;
        sp90 = arg0->unk42 - 5;
        sp96 = (sp94 - sp90) + sp92;
        spAF = arg0->unk24 * 255.0f;
        spAE = arg0->unk28 * 255.0f;
        spAD = arg0->unk2C * 255.0f;
        spAC = 0xFF;
        func_uvgui_rom_00400990(sp96, sp94, sp92, sp90, 2, spAF, spAE, spAD, spAC);
    } else {
        sp96 = arg0->unk3E;
        sp94 = arg0->unk3E;
        sp92 = arg0->unk40;
        sp90 = arg0->unk42;
    }
    spAA = arg0->unk3C + 5;
    spA8 = sp96 - 5;
    spA6 = arg0->unk40 + ((arg0->unk42 - arg0->unk40) / 5) + 5;
    spA4 = arg0->unk42 - 5;
    if (arg0->unk1E == 2) {
        func_uvgui_rom_00400990(spAA, spA8, spA6, spA4, 2, 0x32, 0x32, 0x32, 0xFF);
    }

    if (arg0->unk38 != arg0->unk34) {
        sp8C = (arg0->unk24 - arg0->unk34) / (arg0->unk38 - arg0->unk34);
        sp84 = (arg0->unk28 - arg0->unk34) / (arg0->unk38 - arg0->unk34);
        sp88 = (arg0->unk2C - arg0->unk34) / (arg0->unk38 - arg0->unk34);
    } else {
        sp8C = sp84 = sp88 = 0.5f;
    }
    sp98 = ((spA4 - spA6) - 8) / 3;
    sp9A = spA4 - 2;
    sp9C = sp9A - sp98;
    if (arg0->unk1E == 2) {
        if (arg0->unk44 == 0) {
            spAF = spAE = spAD = 0xFF;
            spAC = 0xFF;
        } else {
            spAF = spAE = spAD = 0x32;
            spAC = 0xFF;
        }
    } else {
        spAF = spAE = spAD = 0;
        spAC = 0x50;
    }
    spA2 = (spA8 - spAA) - 0xC;
    spA0 = spAA + (s16) (spA2 * sp8C) + 3;
    sp9E = spA0 + 6;
    func_uvgui_rom_00400990(spA0, sp9E, sp9C, sp9A, 2, spAF, spAE, spAD, spAC);
    sp9A = sp9C - 2;
    sp9C = sp9A - sp98;
    if (arg0->unk1E == 2) {
        if (arg0->unk44 == 1) {
            spAF = spAE = spAD = 0xFF;
            spAC = 0xFF;
        } else {
            spAF = spAE = spAD = 0x32;
            spAC = 0xFF;
        }
    } else {
        spAF = spAE = spAD = 0;
        spAC = 0x50;
    }
    spA0 = spAA + (s16) (spA2 * sp84) + 3;
    sp9E = spA0 + 6;
    func_uvgui_rom_00400990(spA0, sp9E, sp9C, sp9A, 2, spAF, spAE, spAD, spAC);
    sp9A = sp9C - 2;
    sp9C = sp9A - sp98;
    if (arg0->unk1E == 2) {
        if (arg0->unk44 == 2) {
            spAF = spAE = spAD = 0xFF;
            spAC = 0xFF;
        } else {
            spAF = spAE = spAD = 0x32;
            spAC = 0xFF;
        }
    } else {
        spAF = spAE = spAD = 0;
        spAC = 0x50;
    }
    spA0 = spAA + (s16) (spA2 * sp88) + 3;
    sp9E = spA0 + 6;
    func_uvgui_rom_00400990(spA0, sp9E, sp9C, sp9A, 2, spAF, spAE, spAD, spAC);
    D_uvgui_rom_0040721C->uvFontWidth(arg0->unk0);
    D_uvgui_rom_0040721C->uvFontColor(0, 0, 0, 0xFF);
    D_uvgui_rom_0040721C->uvFontPrintStr(arg0->unk3C + 7, arg0->unk40 + 2, arg0->unk0);
    if ((arg0->unk20 == 1) && (arg0->unk1E == 2)) {
        if (arg0->unk44 != -1) {
            switch (arg0->unk44) {
                case 0:
                    sp68 = arg0->unk24;
                    break;
                case 1:
                    sp68 = arg0->unk28;
                    break;
                case 2:
                    sp68 = arg0->unk2C;
                    break;
            }
            temp_fa1 = (arg0->unk24 + arg0->unk28 + arg0->unk2C) / 3.0f;
            if (temp_fa1 > 0.5f) {
                spAD = 0;
                spAE = 0;
                spAF = 0;
                spAC = 0xFF;
            } else {
                spAD = 0xFF;
                spAE = 0xFF;
                spAF = 0xFF;
                spAC = 0xFF;
            }
            D_uvgui_rom_0040721C->uvFontColor(spAF, spAE, spAD, spAC);
            D_uvgui_rom_00407234->uvSprintf(sp6C, "%f", sp68);
            D_uvgui_rom_0040721C->uvFontPrintStr(
                ((sp94 + sp96) - (s16) D_uvgui_rom_0040721C->uvFontWidth(sp6C)) / 2,
                (s32) ((sp90 + sp92) + 0xC) / 2, sp6C);
            D_uvgui_rom_00407234->uvSprintf(sp6C, "%d", (s32) (sp68 * 255.0f));
            D_uvgui_rom_0040721C->uvFontPrintStr(
                ((sp94 + sp96) - (s16) D_uvgui_rom_0040721C->uvFontWidth(sp6C)) / 2,
                (s32) ((sp90 + sp92) - 0xC) / 2, sp6C);
            return;
        }
    }
    if ((arg0->unk20 == 2) && (arg0->unk1E == 2)) {
        if (arg0->unk44 != -1) {
            switch (arg0->unk44) {
                case 0:
                    sp5C = arg0->unk24;
                    break;
                case 1:
                    sp5C = arg0->unk28;
                    break;
                case 2:
                    sp5C = arg0->unk2C;
                    break;
            }
            D_uvgui_rom_00407234->uvSprintf(sp6C, "%f", sp5C);
            D_uvgui_rom_0040721C->uvFontPrintStr(
                (spA8 - (s16) D_uvgui_rom_0040721C->uvFontWidth(sp6C)) - 2, arg0->unk40 + 2, sp6C);
        }
    }
}

void func_uvgui_rom_00406B00(Inner2C *arg0, s32 arg1) {
    arg0->unk48 = arg1;
}

void func_uvgui_rom_00406B08(Inner2C *arg0, f32 arg1, f32 arg2, Vec3F *arg3, Vec3F *arg4) {
    if (arg0->unk20 == 1) {
        arg1 = 0.0f, arg2 = 1.0f;
    }

    arg0->unk34 = arg1;
    arg0->unk38 = arg2;
    arg0->unk30 = arg4;
    if (arg4 != NULL) {
        arg0->unk24 = arg4->x;
        arg0->unk28 = arg4->y;
        arg0->unk2C = arg4->z;
        return;
    }
    arg0->unk24 = arg3->x;
    arg0->unk28 = arg3->y;
    arg0->unk2C = arg3->z;
}

void func_uvgui_rom_00406B7C(Inner2C *arg0, s16 arg1) {
    arg0->unk20 = arg1;
}

void func_uvgui_rom_00406B88(Inner2C *arg0, u8 arg1, f32 arg2) {
    f32 temp_ft4;
    f32 temp_fv0;

    if (arg0->unk1E != 2) {
        return;
    }

    if (arg0->unk44 == -1) {
        arg0->unk44 = 0;
    }
    if (D_uvgui_rom_00407230->uvControllerButtonPress(arg1, Z_TRIG) != 0) {
        arg0->unk44 += 1;
        if (arg0->unk44 >= 3) {
            arg0->unk44 = 0;
        }
    }
    if (arg0->unk30 != NULL) {
        arg0->unk24 = arg0->unk30->x;
        arg0->unk28 = arg0->unk30->y;
        arg0->unk2C = arg0->unk30->z;
    }
    temp_ft4 = (arg0->unk38 - arg0->unk34) * 0.5f;
    temp_fv0 = D_uvgui_rom_00407220->func_uvgfxmgr_rom_00401004();
    if (arg2 > 0.0f) {
        arg2 *= arg2;
    } else {
        arg2 *= -arg2;
    }
    switch (arg0->unk44) { /* irregular */
        case 0:
            arg0->unk24 += 0.5f * arg2 * temp_ft4 * temp_fv0;
            if (arg0->unk24 < arg0->unk34) {
                arg0->unk24 = arg0->unk34;
            } else {
                if (arg0->unk38 < arg0->unk24) {
                    arg0->unk24 = arg0->unk38;
                }
            }
            break;
        case 1:
            arg0->unk28 += 0.5f * arg2 * temp_ft4 * temp_fv0;
            if (arg0->unk28 < arg0->unk34) {
                arg0->unk28 = arg0->unk34;
            } else {
                if (arg0->unk38 < arg0->unk28) {
                    arg0->unk28 = arg0->unk38;
                }
            }
            break;
        case 2:
            arg0->unk2C += 0.5f * arg2 * temp_ft4 * temp_fv0;
            if (arg0->unk2C < arg0->unk34) {
                arg0->unk2C = arg0->unk34;
            } else {
                if (arg0->unk38 < arg0->unk2C) {
                    arg0->unk2C = arg0->unk38;
                }
            }
            break;
    }
    if (arg0->unk30 != NULL) {
        arg0->unk30->x = arg0->unk24;
        arg0->unk30->y = arg0->unk28;
        arg0->unk30->z = arg0->unk2C;
    }
    if (arg0->unk48 != NULL) {
        arg0->unk48(arg0);
    }
}

void func_uvgui_rom_00406E28(Inner2C *arg0, s16 arg1) {
    arg0->unk1E = arg1;
}

s32 D_uvgui_rom_00406F0C[] = {0x01480000, __entrypoint_func_uvgui_rom_400000, 0, 0};