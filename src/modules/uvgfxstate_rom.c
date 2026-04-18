// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "uvfmtx_rom.h"
#include "uvgfxmgr_rom.h"
#include "uvimtx_rom.h"
#include "uvmath_rom.h"

/*
 * sUvGfxMgrExports = uvLoadModule('GMGR');
 * D_uvgfxstate_rom_00402D10 = uvLoadModule('GEOM');
 * D_uvgfxstate_rom_00402D14 = uvLoadModule('TEXT');
 * D_uvgfxstate_rom_00402D18 = uvLoadModule('LGHT');
 * D_uvgfxstate_rom_00402D1C = uvLoadModule('CBCK');
 * sUvImtxExports = uvLoadModule('IMTX');
 * sUvFmtxExports = uvLoadModule('FMTX');
 * sUvMathExports = uvLoadModule('MATH');
 */

void uvGfxClampLook(LookAt* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9);
void func_uvgfxstate_rom_00400C68(LookAt *arg0, Hilite *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, f32 arg11, f32 arg12, f32 arg13, f32 arg14, f32 arg15, f32 arg16, s32 arg17, s32 arg18);
void uvGfxSync(void);                   /* extern */
void func_uvgfxstate_rom_0040049C(Mtx4F* arg0, s32 arg1);

// .bss
extern UvFMtx_Rom_Exports* sUvFmtxExports;
extern UvGfxMgr_Exports* sUvGfxMgrExports;
extern UvMath_Exports* sUvMathExports;
extern UvImtx_Rom_Exports* sUvImtxExports;

// Not classified yet
extern Mtx4F D_uvgfxstate_rom_00402C60;
extern s32 D_uvgfxstate_rom_00402D30;
extern s32 D_uvgfxstate_rom_00402DEC;
extern s32 D_uvgfxstate_rom_00402DF0;
extern LookAt* D_uvgfxstate_rom_00402DF8[];
extern s32 D_uvgfxstate_rom_00402E00;
extern s32 D_uvgfxstate_rom_00402E04;
extern Hilite* D_uvgfxstate_rom_00402E08[];
extern UvFMtx_Rom_Exports* sUvFmtxExports;
extern UvGfxMgr_Exports* sUvGfxMgrExports;
extern UvMath_Exports* sUvMathExports;
extern UvImtx_Rom_Exports* sUvImtxExports;
extern s32 D_uvgfxstate_rom_00402D00;
extern s32 D_uvgfxstate_rom_00402D30;
extern s32 D_uvgfxstate_rom_00402D60[];
#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxstate_rom/__entrypoint_func_uvgfxstate_rom_400000.s")

// Module cleanup function
#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxstate_rom/func_uvgfxstate_rom_00400390.s")

void func_uvgfxstate_rom_00400440(u32 mode) {
    Gfx** gdl;

    gdl = sUvGfxMgrExports->uvGetDisplayListHead();
    uvGfxSync();
    gDPSetColorDither(gdl[0]++, mode);
}

void func_uvgfxstate_rom_0040049C(Mtx4F *arg0, s32 arg1) {
    Mtx4F spC0;
    Mtx4F sp80;
    Gfx **gdl;

    gdl = sUvGfxMgrExports->uvGetDisplayListHead();

    if (D_uvgfxstate_rom_00402DEC > D_uvgfxstate_rom_00402DF0) {
        sUvFmtxExports->func_004029B8(&spC0);
        sUvFmtxExports->func_00401604(&sp80, &spC0);
        if (arg1 != 0) {
            uvGfxClampLook(
                &D_uvgfxstate_rom_00402DF8[D_uvgfxstate_rom_00402D30][D_uvgfxstate_rom_00402DF0],
                sp80.m[3][0], sp80.m[3][1], sp80.m[3][2], arg0->m[3][0], arg0->m[3][1], arg0->m[3][2],
                sp80.m[1][0], sp80.m[1][1], sp80.m[1][2]);
            goto lookAt; // Required to match
        }
        if (D_uvgfxstate_rom_00402E04 < D_uvgfxstate_rom_00402E00) {
            func_uvgfxstate_rom_00400C68(
                &D_uvgfxstate_rom_00402DF8[D_uvgfxstate_rom_00402D30][D_uvgfxstate_rom_00402DF0],
                &D_uvgfxstate_rom_00402E08[D_uvgfxstate_rom_00402D30][D_uvgfxstate_rom_00402E04], 0.0f,
                0.0f, 500.0f, arg0->m[3][0], arg0->m[3][1], arg0->m[3][2], 0.0f, 1.0f, 0.0f,
                D_uvgfxstate_rom_00402C60.m[0][0], D_uvgfxstate_rom_00402C60.m[0][1],
                D_uvgfxstate_rom_00402C60.m[0][2], D_uvgfxstate_rom_00402C60.m[0][3],
                D_uvgfxstate_rom_00402C60.m[1][0], D_uvgfxstate_rom_00402C60.m[1][1], 32, 32);
            gDPSetHilite1Tile(gdl[0]++, G_TX_RENDERTILE, &D_uvgfxstate_rom_00402E08[D_uvgfxstate_rom_00402D30][D_uvgfxstate_rom_00402E04], 32, 32);
            gDPSetHilite2Tile(gdl[0]++, G_TX_MIRROR, &D_uvgfxstate_rom_00402E08[D_uvgfxstate_rom_00402D30][D_uvgfxstate_rom_00402E04], 32, 32);
            D_uvgfxstate_rom_00402E04++;
        lookAt:
            uvGfxSync();
            gSPLookAt(gdl[0]++,
                      &D_uvgfxstate_rom_00402DF8[D_uvgfxstate_rom_00402D30][D_uvgfxstate_rom_00402DF0])
                D_uvgfxstate_rom_00402DF0++;
        }
    }
}

void uvGfxClampLook(LookAt* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9) {
    f32 len;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;

    sp58 = arg4 - arg1;
    sp54 = arg5 - arg2;
    sp50 = arg6 - arg3;

    len = sqrtf(SQ(sp58) + SQ(sp54) + SQ(sp50));
    if (len != 0.0f) {
        len = -1.0f / len;
    } else {
        len = -255.0f;
    }
    sp58 *= len;
    sp54 *= len;
    sp50 *= len;

    sp4C = (arg8 * sp50) - (arg9 * sp54);
    sp48 = (arg9 * sp58) - (arg7 * sp50);
    sp44 = (arg7 * sp54) - (arg8 * sp58);

    len = sqrtf(SQ(sp4C) + SQ(sp48) + SQ(sp44));
    if (len != 0.0f) {
        len = 1.0f / len;
    } else {
        len = 255.0f;
    }
    sp4C *= len;
    sp48 *= len;
    sp44 *= len;

    arg7 = (sp54 * sp44) - (sp50 * sp48);
    arg8 = (sp50 * sp4C) - (sp58 * sp44);
    arg9 = (sp58 * sp48) - (sp54 * sp4C);

    len = sqrtf(SQ(arg7) + SQ(arg8) + SQ(arg9));
    if (len != 0.0f) {
        len = 1.0f / len;
    } else {
        len = 255.0f;
    }
    arg7 *= len;
    arg8 *= len;
    arg9 *= len;

    arg0->l[0].l.dir[0] = (s32)MIN(sp4C * 128.0f, 127.0f) & 0xFF;
    arg0->l[0].l.dir[1] = (s32)MIN(sp48 * 128.0f, 127.0f) & 0xFF;
    arg0->l[0].l.dir[2] = (s32)MIN(sp44 * 128.0f, 127.0f) & 0xFF;


    arg0->l[1].l.dir[0] = (s32)MIN(arg7 * 128.0f, 127.0f) & 0xFF;
    arg0->l[1].l.dir[1] = (s32)MIN(arg8 * 128.0f, 127.0f) & 0xFF;
    arg0->l[1].l.dir[2] = (s32)MIN(arg9 * 128.0f, 127.0f) & 0xFF;
    arg0->l[0].l.col[0] = 0;
    arg0->l[0].l.col[1] = 0;
    arg0->l[0].l.col[2] = 0;
    arg0->l[0].l.pad1 = 0;
    arg0->l[0].l.colc[0] = 0;
    arg0->l[0].l.colc[1] = 0;
    arg0->l[0].l.colc[2] = 0;
    arg0->l[0].l.pad2 = 0;
    arg0->l[1].l.col[0] = 0;
    arg0->l[1].l.col[1] = 0x80;
    arg0->l[1].l.col[2] = 0;
    arg0->l[1].l.pad1 = 0;
    arg0->l[1].l.colc[0] = 0;
    arg0->l[1].l.colc[1] = 0x80;
    arg0->l[1].l.colc[2] = 0;
    arg0->l[1].l.pad2 = 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxstate_rom/func_uvgfxstate_rom_00400C68.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxstate_rom/func_uvgfxstate_rom_00401314.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxstate_rom/func_uvgfxstate_rom_00401354.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxstate_rom/func_uvgfxstate_rom_00401398.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxstate_rom/func_uvgfxstate_rom_004013DC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxstate_rom/func_uvgfxstate_rom_004013F0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxstate_rom/func_uvgfxstate_rom_00401400.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxstate_rom/func_uvgfxstate_rom_00401418.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxstate_rom/func_uvgfxstate_rom_0040143C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxstate_rom/func_uvgfxstate_rom_00401460.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxstate_rom/func_uvgfxstate_rom_0040146C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxstate_rom/func_uvgfxstate_rom_00401498.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxstate_rom/func_uvgfxstate_rom_004017EC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxstate_rom/func_uvgfxstate_rom_00401CE8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxstate_rom/func_uvgfxstate_rom_00401DD0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxstate_rom/func_uvgfxstate_rom_00401E60.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxstate_rom/func_uvgfxstate_rom_00401F54.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxstate_rom/func_uvgfxstate_rom_004020DC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxstate_rom/func_uvgfxstate_rom_004020F8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxstate_rom/func_uvgfxstate_rom_00402218.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxstate_rom/func_uvgfxstate_rom_00402254.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxstate_rom/func_uvgfxstate_rom_004022B0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxstate_rom/func_uvgfxstate_rom_00402350.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxstate_rom/func_uvgfxstate_rom_004029B8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxstate_rom/func_uvgfxstate_rom_00402B14.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxstate_rom/func_uvgfxstate_rom_00402B28.s")

void uvGfxSync(void) {
    Gfx** gdl;

    gdl = sUvGfxMgrExports->uvGetDisplayListHead();
    if (D_uvgfxstate_rom_00402D00 != 2) {
        D_uvgfxstate_rom_00402D60[D_uvgfxstate_rom_00402D30]++;
        gDPPipeSync(gdl[0]++);
    }
}
