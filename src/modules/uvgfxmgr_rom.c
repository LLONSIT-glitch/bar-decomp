// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include <PR/sched.h>

typedef struct UvGfxStruct_s {
    char pad[0x58];
} UvGfxStruct;

typedef struct UvGfxMgr_Rom_00402628_s {
    /* 0x00 */ char pad0[8];
    /* 0x08 */ void (*unk8)(s32);                      /* inferred */
    /* 0x0C */ void (*unkC)(s32, s32);
} UvGfxMgr_Rom_00402628;                            /* size = 0x10 */

void func_uvgfxmgr_rom_00402090(void);
void func_80004958(s32, s32);                              /* extern */
extern void* D_uvgfxmgr_rom_00402260;
extern Gfx* sGfxDisplayListHead;
extern f32 D_uvgfxmgr_rom_00402420[];
extern u16 D_uvgfxmgr_rom_0040242C;
extern s32 D_uvgfxmgr_rom_00402430[];
extern void* D_uvgfxmgr_rom_0040243C;
extern u16 D_uvgfxmgr_rom_00402442;
extern u16 D_uvgfxmgr_rom_00402444;
extern s32 D_uvgfxmgr_rom_00402450;
extern s32 D_uvgfxmgr_rom_00402458[];
extern u16 D_uvgfxmgr_rom_00402460;
extern u16 D_uvgfxmgr_rom_00402462;
extern u16 D_uvgfxmgr_rom_00402464;
extern u16 D_uvgfxmgr_rom_00402466;
extern s32 D_uvgfxmgr_rom_00402470[];
extern s32 D_uvgfxmgr_rom_00402478;
extern void* D_uvgfxmgr_rom_00402484;
extern UvGfxStruct D_uvgfxmgr_rom_00402488[];
extern void (*D_uvgfxmgr_rom_0040261C)(void*, void*);
extern s32 D_uvgfxmgr_rom_00402618;
extern s32 D_uvgfxmgr_rom_00402620;
extern s32 D_uvgfxmgr_rom_00402624;
extern UvGfxMgr_Rom_00402628* D_uvgfxmgr_rom_00402628;
extern s32 D_uvgfxmgr_rom_00402264;

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
            osWritebackDCache(temp_a0, D_uvgfxmgr_rom_00402442 * D_uvgfxmgr_rom_00402444 * 2);
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
    gDPSetColorImage(sGfxDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_uvgfxmgr_rom_00402442,  osVirtualToPhysical(D_uvgfxmgr_rom_0040243C));
    gDPSetDepthImage(sGfxDisplayListHead++,  osVirtualToPhysical(D_uvgfxmgr_rom_00402260));
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
    switch (arg0) {                                 /* irregular */
    case 1:
        return D_uvgfxmgr_rom_00402620;
    case 2:
        return D_uvgfxmgr_rom_00402624;
    default:
        return 0;
    }
}

void (*func_uvgfxmgr_rom_00400AF0(void (*arg0)(void*, void*)))(void*, void*) {
    void (*temp_v0)(void*, void*);

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxmgr_rom/func_uvgfxmgr_rom_00400B24.s")

extern OSMesgQueue D_uvgfxmgr_rom_004025B8;

void func_uvgfxmgr_rom_00400F20(u16 arg0) {
    if (!(arg0)) {
        osRecvMesg(&D_uvgfxmgr_rom_004025B8, NULL, 1);
    }
}

void func_uvgfxmgr_rom_00400F58(s32 arg0) {
    D_uvgfxmgr_rom_00402478 = arg0;
}

extern s32 D_uvgfxmgr_rom_0040247C;
extern OSMesgQueue D_uvgfxmgr_rom_004025B8;

s32 func_uvgfxmgr_rom_00400F64(void) {
    if ((D_uvgfxmgr_rom_00402470[D_uvgfxmgr_rom_00402460] != 0) && (osRecvMesg(&D_uvgfxmgr_rom_004025B8, NULL, 0) == 0)) {
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
    gDPSetPrimColor(sGfxDisplayListHead++, 0, 0, 
                    r & 0xFF, 
                    g & 0xFF,
                    (s32)b & 0xFF, 
                    a & 0xFF );
    
    gDPSetFillColor(sGfxDisplayListHead++, GPACK_RGBA5551(r & 0xFF, g & 0xFF, (s32)b & 0xFF, a & 0xFF) << 16 | GPACK_RGBA5551(r & 0xFF, g & 0xFF,  (s32)b & 0xFF, a & 0xFF));
    
}


#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxmgr_rom/func_uvgfxmgr_rom_00401370.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxmgr_rom/func_uvgfxmgr_rom_004016AC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxmgr_rom/func_uvgfxmgr_rom_00401714.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxmgr_rom/func_uvgfxmgr_rom_00401788.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxmgr_rom/func_uvgfxmgr_rom_00401914.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxmgr_rom/func_uvgfxmgr_rom_004019F4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxmgr_rom/func_uvgfxmgr_rom_00401BD4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxmgr_rom/func_uvgfxmgr_rom_00401C5C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxmgr_rom/func_uvgfxmgr_rom_00401D94.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxmgr_rom/func_uvgfxmgr_rom_00401DC4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxmgr_rom/func_uvgfxmgr_rom_0040204C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxmgr_rom/func_uvgfxmgr_rom_00402058.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxmgr_rom/func_uvgfxmgr_rom_00402074.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxmgr_rom/func_uvgfxmgr_rom_00402090.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxmgr_rom/func_uvgfxmgr_rom_004020C8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxmgr_rom/func_uvgfxmgr_rom_00402198.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxmgr_rom/func_uvgfxmgr_rom_004021A4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxmgr_rom/func_uvgfxmgr_rom_004021B0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxmgr_rom/func_uvgfxmgr_rom_004021BC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxmgr_rom/func_uvgfxmgr_rom_004021C8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxmgr_rom/func_uvgfxmgr_rom_004021F4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgfxmgr_rom/func_uvgfxmgr_rom_00402234.s")

