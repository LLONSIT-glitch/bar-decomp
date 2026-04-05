// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include <PR/sched.h>

typedef struct UvGfxStruct_s {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ char pad4[4];
    /* 0x08 */ s32 unk8;                            /* inferred */
    /* 0x0C */ void* unkC;                          /* inferred */
    /* 0x10 */ OSTask task;                           /* inferred */
    /* 0x50 */ OSMesgQueue* unk50;                  /* inferred */
    /* 0x54 */ void* unk54;                         /* inferred */
} UvGfxStruct;                                      /* size = 0x58 */

typedef struct UvGfxMgr_Rom_00402628_s {
    /* 0x00 */ char pad0[8];
    /* 0x08 */ void (*unk8)(s32); /* inferred */
    /* 0x0C */ void (*unkC)(s32, s32);
} UvGfxMgr_Rom_00402628; /* size = 0x10 */

typedef struct uvGfxViewport_s {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ s16 unk6;
    /* 0x8 */ s16 x0; // left?
    /* 0xA */ s16 x1; // right?
    /* 0xC */ s16 y0; // top?
    /* 0xE */ s16 y1; // bottom?
    /* 010 */ Vp vp;
} uvGfxViewport;

void func_uvgfxmgr_rom_00402090(void);
void func_80004958(s32, s32); /* extern */
extern void *D_uvgfxmgr_rom_00402260;
extern Gfx *sGfxDisplayListHead;
extern f32 D_uvgfxmgr_rom_00402420[];
extern u16 D_uvgfxmgr_rom_0040242C;
extern s32 D_uvgfxmgr_rom_00402430[];
extern void *D_uvgfxmgr_rom_0040243C;
extern u16 sScreenWidth;
extern u16 sScreenHeight;
extern s32 D_uvgfxmgr_rom_00402450;
extern Gfx* D_uvgfxmgr_rom_00402458[];
extern u16 D_uvgfxmgr_rom_00402460;
extern u16 D_uvgfxmgr_rom_00402462;
extern u16 D_uvgfxmgr_rom_00402464;
extern u16 D_uvgfxmgr_rom_00402466;
extern s32 D_uvgfxmgr_rom_00402470[];
extern s32 D_uvgfxmgr_rom_00402478;
extern void *D_uvgfxmgr_rom_00402484;
extern UvGfxStruct D_uvgfxmgr_rom_00402488[];
extern void (*D_uvgfxmgr_rom_0040261C)(void *, void *);
extern void (*D_uvgfxmgr_rom_00402618)(s32, s32);
extern s32 D_uvgfxmgr_rom_0040247C;

extern s32 D_uvgfxmgr_rom_00402620;
extern s32 D_uvgfxmgr_rom_00402624;
extern UvGfxMgr_Rom_00402628 *D_uvgfxmgr_rom_00402628;
extern s32 D_uvgfxmgr_rom_00402264;
extern OSMesgQueue D_uvgfxmgr_rom_004025B8;
extern s16 D_uvgfxmgr_rom_00402408;
extern s16 D_uvgfxmgr_rom_0040240A;
extern s16 D_uvgfxmgr_rom_0040240C;
extern s16 D_uvgfxmgr_rom_0040240E;
extern Gfx D_uvgfxmgr_rom_00402278[];

void func_uvgfxmgr_rom_00400F20(u16 arg0);

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxmgr_rom/__entrypoint_func_uvgfxmgr_rom_400000.s")

void func_uvgfxmgr_rom_00400794(void) {
    func_uvgfxmgr_rom_00402090();
    D_uvgfxmgr_rom_00402628->unk8(D_uvgfxmgr_rom_00402620);
    D_uvgfxmgr_rom_00402628->unk8(D_uvgfxmgr_rom_00402624);
    uvUnloadModule('CBCK');
}

void func_uvgfxmgr_rom_004007F8(void) {
    s32 temp_a0;

    if (D_uvgfxmgr_rom_00402478 == 1) {
        temp_a0 = D_uvgfxmgr_rom_00402430[D_uvgfxmgr_rom_00402464];
        if (D_uvgfxmgr_rom_0040261C != NULL) {
            D_uvgfxmgr_rom_0040261C(temp_a0, D_uvgfxmgr_rom_00402260);
            osWritebackDCache(temp_a0, sScreenWidth * sScreenHeight * 2);
        }
        D_uvgfxmgr_rom_00402420[D_uvgfxmgr_rom_00402466] = uvClkGetSec(103);
        uvClkReset(103);
        func_80004958(0, 42);
        D_uvgfxmgr_rom_00402460 = D_uvgfxmgr_rom_00402462++;
        if (D_uvgfxmgr_rom_00402462 >= 2) {
            D_uvgfxmgr_rom_00402462 = 0;
        }
        D_uvgfxmgr_rom_00402464 = D_uvgfxmgr_rom_00402466++;

        if (D_uvgfxmgr_rom_00402466 >= D_uvgfxmgr_rom_0040242C) {
            D_uvgfxmgr_rom_00402466 = 0;
        }
        D_uvgfxmgr_rom_00402470[D_uvgfxmgr_rom_00402462] = 1;
        D_uvgfxmgr_rom_00402484 = &D_uvgfxmgr_rom_00402488[D_uvgfxmgr_rom_00402462];
        D_uvgfxmgr_rom_0040243C = D_uvgfxmgr_rom_00402430[D_uvgfxmgr_rom_00402466];
        sGfxDisplayListHead = D_uvgfxmgr_rom_00402458[D_uvgfxmgr_rom_00402462];
    }
    gSPSegment(sGfxDisplayListHead++, 0, 0);
    gDPPipeSync(sGfxDisplayListHead++);
    gDPSetColorImage(sGfxDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, sScreenWidth,
                     osVirtualToPhysical(D_uvgfxmgr_rom_0040243C));
    gDPSetDepthImage(sGfxDisplayListHead++, osVirtualToPhysical(D_uvgfxmgr_rom_00402260));
    gDPPipeSync(sGfxDisplayListHead++);
    D_uvgfxmgr_rom_00402450 = 0;
    if (D_uvgfxmgr_rom_00402620 != 0) {
        D_uvgfxmgr_rom_00402628->unkC(D_uvgfxmgr_rom_00402620, 0);
    }
}

Gfx **func_uvgfxmgr_rom_00400A88(void) {
    return &sGfxDisplayListHead;
}

// uvGfxDisplayList
void func_uvgfxmgr_rom_00400A94(u32 dl) {
    gSPDisplayList(sGfxDisplayListHead++, dl);
}

s32 func_uvgfxmgr_rom_00400AB8(s32 arg0) {
    switch (arg0) { /* irregular */
        case 1:
            return D_uvgfxmgr_rom_00402620;
        case 2:
            return D_uvgfxmgr_rom_00402624;
        default:
            return 0;
    }
}

void (*func_uvgfxmgr_rom_00400AF0(void (*arg0)(void *, void *)))(void *, void *) {
    void (*temp_v0)(void *, void *);

    temp_v0 = D_uvgfxmgr_rom_0040261C;
    D_uvgfxmgr_rom_0040261C = arg0;
    return temp_v0;
}

s32 func_uvgfxmgr_rom_00400B04(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_uvgfxmgr_rom_00402618;
    D_uvgfxmgr_rom_00402618 = arg0;
    return temp_v0;
}

void func_uvgfxmgr_rom_00400B18(s32 arg0) {
    D_uvgfxmgr_rom_00402264 = arg0;
}

OSMesgQueue* _uvScGetCmdQ(s32);                     /* extern */
extern s32 D_800218B0;
extern s32 D_uvgfxmgr_rom_00402268[];
extern s32 D_uvgfxmgr_rom_004022C0;
extern s32 D_uvgfxmgr_rom_004022C4;
extern s32 D_uvgfxmgr_rom_00402414;
extern s32 D_uvgfxmgr_rom_00402418;
extern s32 D_uvgfxmgr_rom_00402468;
extern s32 sScheduler;

void func_uvgfxmgr_rom_00400B24(void) {
    s32 pad;
    UvGfxStruct* temp_a3;
    s32 pad2[2];
    s32 temp_a0;

    gDPFullSync(sGfxDisplayListHead++);
    gSPEndDisplayList(sGfxDisplayListHead++);
    D_uvgfxmgr_rom_00402468 = sGfxDisplayListHead - D_uvgfxmgr_rom_00402458[D_uvgfxmgr_rom_00402462];
    temp_a3 = &D_uvgfxmgr_rom_00402488[D_uvgfxmgr_rom_00402462];
    if (D_uvgfxmgr_rom_00402264 == 1) {
        temp_a3->unkC = D_uvgfxmgr_rom_00402260;
    } else {
        temp_a3->unkC = D_uvgfxmgr_rom_00402430[D_uvgfxmgr_rom_00402466];
    }
    temp_a3->unk0 = 0;
    temp_a3->unk50 = &D_uvgfxmgr_rom_004025B8;
    temp_a3->unk54 = &D_uvgfxmgr_rom_00402268[D_uvgfxmgr_rom_00402466];
    temp_a3->unk8 = 0x53;
    temp_a3->task.t.type = M_GFXTASK;
    temp_a3->task.t.flags = 0;
    temp_a3->task.t.ucode_boot = (u64* ) rspBootTextStart;
    temp_a3->task.t.ucode_boot_size = rspBootTextEnd - rspBootTextStart;
    temp_a3->task.t.ucode_size = 0x1000;
    temp_a3->task.t.ucode_data_size = 0x800;
    temp_a3->task.t.dram_stack = D_uvgfxmgr_rom_004022C4;
    temp_a3->task.t.dram_stack_size = 0x400;
    temp_a3->task.t.data_ptr = (u64* ) D_uvgfxmgr_rom_00402458[D_uvgfxmgr_rom_00402462];
    temp_a3->task.t.data_size = D_uvgfxmgr_rom_00402468 * sizeof(Gfx);
    temp_a3->task.t.yield_data_ptr = D_uvgfxmgr_rom_004022C0;
    temp_a3->task.t.yield_data_size = 0xC00;
    temp_a3->task.t.ucode = (u64* ) gspF3DEX2_fifoTextStart; // gspF3DEX2_fifoTextStart
    temp_a3->task.t.ucode_data = gspF3DEX2_fifoDataStart;
    temp_a3->task.t.output_buff = D_uvgfxmgr_rom_00402414;
    temp_a3->task.t.output_buff_size = D_uvgfxmgr_rom_00402418;
    func_80004958(0, 0x2B);
    if (D_uvgfxmgr_rom_00402618 != NULL) {
        D_uvgfxmgr_rom_00402618(D_uvgfxmgr_rom_00402430[D_uvgfxmgr_rom_00402466], D_uvgfxmgr_rom_00402260);
        osWritebackDCache((void* ) D_uvgfxmgr_rom_00402430[D_uvgfxmgr_rom_00402466], sScreenWidth * sScreenHeight * 2);
    }
    osWritebackDCacheAll();
    osSendMesg(_uvScGetCmdQ(sScheduler), temp_a3, 1);
    if (D_uvgfxmgr_rom_00402624 != 0) {
        D_uvgfxmgr_rom_00402628->unkC(D_uvgfxmgr_rom_00402624, 0);
    }
    if (D_uvgfxmgr_rom_00402478 == 0) {
        if (D_uvgfxmgr_rom_0040247C != 0) {
            func_uvgfxmgr_rom_00400F20(0U);
        }
        D_uvgfxmgr_rom_0040247C = 1;
        temp_a0 = D_uvgfxmgr_rom_00402430[D_uvgfxmgr_rom_00402464];
        if (D_uvgfxmgr_rom_0040261C != NULL) {
            D_uvgfxmgr_rom_0040261C((void* ) temp_a0, D_uvgfxmgr_rom_00402260);
            osWritebackDCache((void* ) temp_a0, sScreenWidth * sScreenHeight * 2);
        }
        D_uvgfxmgr_rom_00402420[D_uvgfxmgr_rom_00402466] = (f32) uvClkGetSec(0x67);
        uvClkReset(0x67);
        func_80004958(0, 0x2A);
        D_uvgfxmgr_rom_00402460 = D_uvgfxmgr_rom_00402462++;
        if (D_uvgfxmgr_rom_00402462 >= 2) {
            D_uvgfxmgr_rom_00402462 = 0;
        }
        D_uvgfxmgr_rom_00402464 = D_uvgfxmgr_rom_00402466++;
        if (D_uvgfxmgr_rom_00402466 >= (s32) D_uvgfxmgr_rom_0040242C) {
            D_uvgfxmgr_rom_00402466 = 0;
        }
        D_uvgfxmgr_rom_0040243C = (void* ) D_uvgfxmgr_rom_00402430[D_uvgfxmgr_rom_00402466];
        sGfxDisplayListHead = (Gfx* ) D_uvgfxmgr_rom_00402458[D_uvgfxmgr_rom_00402462];
    }
}

void func_uvgfxmgr_rom_00400F20(u16 arg0) {
    if (!(arg0)) {
        osRecvMesg(&D_uvgfxmgr_rom_004025B8, NULL, 1);
    }
}

void func_uvgfxmgr_rom_00400F58(s32 arg0) {
    D_uvgfxmgr_rom_00402478 = arg0;
}

s32 func_uvgfxmgr_rom_00400F64(void) {
    if ((D_uvgfxmgr_rom_00402470[D_uvgfxmgr_rom_00402460] != 0)
        && (osRecvMesg(&D_uvgfxmgr_rom_004025B8, NULL, 0) == 0)) {
        D_uvgfxmgr_rom_00402470[D_uvgfxmgr_rom_00402460] = 0;
    }
    D_uvgfxmgr_rom_0040247C = 1;
    return D_uvgfxmgr_rom_00402470[D_uvgfxmgr_rom_00402460] == 0;
}

extern f32 D_uvgfxmgr_rom_00402480;

void func_uvgfxmgr_rom_00400FF8(f32 arg0) {
    D_uvgfxmgr_rom_00402480 = arg0;
}

f32 func_uvgfxmgr_rom_00401004(void) {
    if (D_uvgfxmgr_rom_00402480 > 0.0f) {
        return D_uvgfxmgr_rom_00402480;
    }
    return D_uvgfxmgr_rom_00402420[D_uvgfxmgr_rom_00402460];
}

// uvGfxEnableGamma
void func_uvgfxmgr_rom_00401048(s32 enable) {
    if (enable) {
        osViSetSpecialFeatures(OS_VI_GAMMA_ON);
        return;
    }
    osViSetSpecialFeatures(OS_VI_GAMMA_OFF);
}

void func_uvgfxmgr_rom_0040107C(f32 red, f32 green, f32 blue, f32 alpha) {
    u32 r;
    u32 g;
    u32 b;
    u32 a;

    gDPPipeSync(sGfxDisplayListHead++);
    r = red * 255.0f;
    g = green * 255.0f;
    b = blue * 255.0f;
    a = alpha * 255.0f;
    gDPSetPrimColor(sGfxDisplayListHead++, 0, 0, r & 0xFF, g & 0xFF, (s32) b & 0xFF, a & 0xFF);

    gDPSetFillColor(sGfxDisplayListHead++,
                    GPACK_RGBA5551(r & 0xFF, g & 0xFF, (s32) b & 0xFF, a & 0xFF) << 16
                        | GPACK_RGBA5551(r & 0xFF, g & 0xFF, (s32) b & 0xFF, a & 0xFF));
}

void func_uvgfxmgr_rom_00401370(s8 red, s8 green, s8 blue, s8 alpha) {
    gDPSetPrimColor(sGfxDisplayListHead++, 0, 0, red, green, blue, alpha);
    gDPSetFillColor(sGfxDisplayListHead++, GPACK_RGBA5551(red, green, blue, alpha) << 16
                                               | GPACK_RGBA5551(red, green, blue, alpha));
}

void func_uvgfxmgr_rom_00401430(f32 red, f32 green, f32 blue, f32 alpha) {
    u32 r;
    u32 g;
    u32 b;
    u32 a;
    r = red * 255.0f;
    g = green * 255.0f;
    b = blue * 255.0f;
    a = alpha * 255.0f;
    gDPSetEnvColor(sGfxDisplayListHead++, r & 0xff, g & 0xff, b & 0xff, a & 0xff);
}

void func_uvgfxmgr_rom_004016AC(s8 r, s8 g, s8 b, s8 a) {
    gDPSetEnvColor(sGfxDisplayListHead++, r, g, b, a);
}

void func_uvgfxmgr_rom_00401714(s32 arg0, s32 arg1, u32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    gDPSetConvert(sGfxDisplayListHead++, arg0, arg1, arg2, arg3, arg4, arg5);
}

void func_uvgfxmgr_rom_00401788(u8 red, u8 green, u8 alpha) {
    gDPPipeSync(sGfxDisplayListHead++);

    gDPSetCycleType(sGfxDisplayListHead++, G_CYC_FILL);
    gDPSetFillColor(sGfxDisplayListHead++,
                    GPACK_RGBA5551(red, green, alpha, 1) << 16 | GPACK_RGBA5551(red, green, alpha, 1));

    gDPFillRectangle(sGfxDisplayListHead++, D_uvgfxmgr_rom_00402408,
                     sScreenHeight - D_uvgfxmgr_rom_0040240E, D_uvgfxmgr_rom_0040240A,
                     sScreenHeight - D_uvgfxmgr_rom_0040240C);
    gDPPipeSync(sGfxDisplayListHead++);
    gDPSetCycleType(sGfxDisplayListHead++, G_CYC_2CYCLE);
    gDPSetFillColor(sGfxDisplayListHead++, 0x10001);
}

void func_uvgfxmgr_rom_00401914(void) {
    gDPPipeSync(sGfxDisplayListHead++);
    gDPSetCycleType(sGfxDisplayListHead++, G_CYC_FILL);
    gDPSetFillColor(sGfxDisplayListHead++, 0x00000000);
    gDPFillRectangle(sGfxDisplayListHead++, 0, sScreenWidth, 0, sScreenHeight);
    gDPPipeSync(sGfxDisplayListHead++);
    gDPSetCycleType(sGfxDisplayListHead++, G_CYC_2CYCLE);
    gDPSetFillColor(sGfxDisplayListHead++, 0x10001);
}

void func_uvgfxmgr_rom_004019F4(uvGfxViewport *vp, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 var_a2;
    s32 var_a3;

    vp->x0 = arg1;
    vp->x1 = arg2;
    vp->y0 = arg3;
    vp->y1 = arg4;
    if (vp->x0 < 0) {
        vp->x0 = 0;
    } else if (vp->x0 > sScreenWidth) {
        vp->x0 = sScreenWidth;
    }

    if (vp->x1 < 0) {
        vp->x1 = 0;
    } else if (vp->x1 > sScreenWidth) {
        vp->x1 = sScreenWidth;
    }

    if (vp->y1 < 0) {
        vp->y1 = 0;
    } else if (vp->y1 > sScreenHeight) {
        vp->y1 = sScreenHeight;
    }

    if (vp->y0 < 0) {
        vp->y0 = 0;
    } else if (vp->y0 > sScreenHeight) {
        vp->y0 = sScreenHeight;
    }

    vp->unk0 = vp->x0;
    if (vp->unk0 < 0) {
        vp->unk0 = 0;
    }
    vp->unk2 = vp->x1;
    if (vp->unk2 > sScreenWidth - 1) {
        vp->unk2 = sScreenWidth - 1;
    }
    vp->unk4 = vp->y0;
    if (vp->unk4 < 0) {
        vp->unk4 = 0;
    }
    vp->unk6 = vp->y1;
    if (vp->unk6 > sScreenHeight - 1) {
        vp->unk6 = sScreenHeight - 1;
    }

    var_a2 = vp->unk2 - vp->unk0;
    var_a3 = vp->unk6 - vp->unk4;

    vp->vp.vp.vscale[0] = (var_a2 << 1);
    vp->vp.vp.vscale[1] = (var_a3 << 1);
    vp->vp.vp.vscale[2] = 0x1FF;
    vp->vp.vp.vscale[3] = 0;
    vp->vp.vp.vtrans[0] = (u16) ((vp->unk0 + (var_a2 >> 1)) & 0xFFFF) << 2;
    vp->vp.vp.vtrans[1] = (u16) (((sScreenHeight - vp->unk4) - (var_a3 >> 1)) & 0xFFFF) << 2;
    vp->vp.vp.vtrans[2] = 0x1FF;
    vp->vp.vp.vtrans[3] = 0;
    D_uvgfxmgr_rom_00402408 = vp->x0;
    D_uvgfxmgr_rom_0040240A = vp->x1;
    D_uvgfxmgr_rom_0040240C = vp->y0;
    D_uvgfxmgr_rom_0040240E = vp->y1;
}

void func_uvgfxmgr_rom_00401C5C(s32); /* extern */
extern uvGfxViewport D_uvgfxmgr_rom_004022C8[];

void func_uvgfxmgr_rom_00401BD4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    uvGfxViewport *temp_t8;

    temp_t8 = &D_uvgfxmgr_rom_004022C8[D_uvgfxmgr_rom_00402450];
    if (D_uvgfxmgr_rom_00402450 < 0xB) {
        func_uvgfxmgr_rom_004019F4(temp_t8, arg0, arg1, arg2, arg3);
        func_uvgfxmgr_rom_00401C5C(D_uvgfxmgr_rom_00402450);
        D_uvgfxmgr_rom_00402450 += 1;
    }
}

void func_uvgfxmgr_rom_00401C5C(s32 vp_id) {
    uvGfxViewport *vp;
    vp = &D_uvgfxmgr_rom_004022C8[vp_id];

    gSPViewport(sGfxDisplayListHead++, OS_PHYSICAL_TO_K0(&vp->vp));
    gDPSetScissor(sGfxDisplayListHead++, G_SC_NON_INTERLACE, vp->x0, sScreenHeight - vp->y1, vp->x1,
                  sScreenHeight - vp->y0);
    D_uvgfxmgr_rom_00402408 = vp->x0;
    D_uvgfxmgr_rom_0040240A = vp->x1;
    D_uvgfxmgr_rom_0040240C = vp->y0;
    D_uvgfxmgr_rom_0040240E = vp->y1;
}

void func_uvgfxmgr_rom_00401D94(s16 persp) {
    gSPPerspNormalize(sGfxDisplayListHead++, persp);
}

void func_uvgfxmgr_rom_00401DC4(void) {
    uvGfxViewport *vp;

    if ((D_uvgfxmgr_rom_00402260 != NULL) && (D_uvgfxmgr_rom_0040243C != NULL)) {
        vp = &D_uvgfxmgr_rom_004022C8[D_uvgfxmgr_rom_00402450 - 1];

        gDPPipeSync(sGfxDisplayListHead++);
        gDPSetRenderMode(sGfxDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
        gDPPipeSync(sGfxDisplayListHead++);
        gDPSetCycleType(sGfxDisplayListHead++, G_CYC_FILL);
        gDPPipeSync(sGfxDisplayListHead++);
        gDPSetFillColor(sGfxDisplayListHead++, 0xFFFCFFFC);
        gDPPipeSync(sGfxDisplayListHead++);
        gDPSetColorImage(sGfxDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, sScreenWidth,
                         osVirtualToPhysical(D_uvgfxmgr_rom_00402260));
        gDPPipeSync(sGfxDisplayListHead++);
        gDPFillRectangle(sGfxDisplayListHead++, vp->x0, sScreenHeight - vp->y1, vp->x1,
                         sScreenHeight - vp->y0);
        gDPPipeSync(sGfxDisplayListHead++);
        gDPSetColorImage(sGfxDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, sScreenWidth,
                         osVirtualToPhysical(D_uvgfxmgr_rom_0040243C));
        gDPPipeSync(sGfxDisplayListHead++);
        gDPSetCycleType(sGfxDisplayListHead++, G_CYC_2CYCLE);
        gDPPipeSync(sGfxDisplayListHead++);
    }
}

void *func_uvgfxmgr_rom_0040204C(void) {
    return D_uvgfxmgr_rom_00402260;
}

s32 func_uvgfxmgr_rom_00402058(void) {
    return D_uvgfxmgr_rom_00402430[D_uvgfxmgr_rom_00402466];
}

s32 func_uvgfxmgr_rom_00402074(void) {
    return D_uvgfxmgr_rom_00402430[D_uvgfxmgr_rom_00402464];
}

void func_uvgfxmgr_rom_00402090(void) {
    if (D_uvgfxmgr_rom_0040247C != 0) {
        func_uvgfxmgr_rom_00400F20(0U);
        D_uvgfxmgr_rom_0040247C = 0;
    }
}

void func_uvgfxmgr_rom_004020C8(s32 arg0) {
    s32 var_a1;
    s32 var_a0;

    if ((arg0 >= 0) && (arg0 < 2)) {
        if (arg0 != 0) {
            var_a1 = D_uvgfxmgr_rom_00402430[D_uvgfxmgr_rom_00402466];
            var_a0 = D_uvgfxmgr_rom_00402430[D_uvgfxmgr_rom_00402464];
        } else {
            var_a1 = D_uvgfxmgr_rom_00402430[D_uvgfxmgr_rom_00402464];
            var_a0 = D_uvgfxmgr_rom_00402430[D_uvgfxmgr_rom_00402466];
        }
        func_uvgfxmgr_rom_00402090();
        _uvMediaCopy((void* ) var_a0, (void* ) var_a1, sScreenWidth * sScreenHeight * 2);
        osWritebackDCacheAll();
    }
}

void func_uvgfxmgr_rom_00402198(s32 height) {
    sScreenHeight = height;
}

void func_uvgfxmgr_rom_004021A4(s32 arg0) {
    sScreenWidth = arg0;
}

u16 func_uvgfxmgr_rom_004021B0(void) {
    return sScreenHeight;
}

u16 func_uvgfxmgr_rom_004021BC(void) {
    return sScreenWidth;
}

void func_uvgfxmgr_rom_004021C8(void) {
    gSPDisplayList(sGfxDisplayListHead++, D_uvgfxmgr_rom_00402278);
}

void func_uvgfxmgr_rom_004021F4(s32 usePrimitiveDepth) {
    gDPSetDepthSource(sGfxDisplayListHead++, usePrimitiveDepth ? G_ZS_PRIM : G_ZS_PIXEL);
}

void func_uvgfxmgr_rom_00402234(s32 z) {
    gDPSetPrimDepth(sGfxDisplayListHead++, z, 0);
}