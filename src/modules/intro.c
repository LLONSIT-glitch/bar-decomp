// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"

typedef struct UnkStruct_80025BD8_s {
    char pad0[0x14];
    void (*unk14)(f32);
} UnkStruct_80025BD8;

typedef struct UnkStruct_80025C54_s {
    char pad0[0xC];
    void  (*unkC)(s32, f32);
    u8   pad10[0x124 - 0x10];
    s32  (*unk124)(s32);
} UnkStruct_80025C54;

typedef struct UnkStruct_80025C64_s {
    char pad00[8];
    void (*unk8)(s32, s32);
    char pad68[0x64];
    s32 (*unk70)(void);
    s32 (*unk74)(s32);
    void (*unk78)(s32, s32);
} UnkStruct_80025C64;

typedef struct UnkStruct_80025C84_s {
    s32 pad0;
    s32 (*unk4)(s32);
} UnkStruct_80025C84;

typedef struct UnkStruct_80025C90_s {
    /* 0x00 */ char pad0[0x20];
    /* 0x20 */ s32 (*unk20)(s32);                   /* inferred */
    /* 0x24 */ char pad24[0x10];                    /* maybe part of unk20[5]? */
    /* 0x34 */ void (*unk34)(s32);
    /* 0x38 */ void (*unk38)(s32,s32);
} UnkStruct_80025C90;                               /* size = 0x38 */

typedef struct UnkStruct_8002CCB0_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
} UnkStruct_8002CCB0;

typedef struct UnkStruct_intro_004009C0_s {
    s32 pad0;
} UnkStruct_intro_004009C0;

typedef struct UnkStruct_intro_00400A88_s {
    char pad0[0x48];
    void (*unk48)(s32);
} UnkStruct_intro_00400A88;

typedef struct UnkStruct_intro_00400A84_s {
    char pad0[0x8];
    void (*unk8)(s32, s32); 
    void (*unkC)(s32);
    char pad24[0x10];
} UnkStruct_intro_00400A84;

extern UnkStruct_80025C14* D_80025C14;
extern u8 D_intro_004009D0;
extern s32 D_intro_00400A98;
extern s32 D_intro_00400A9C;
extern UnkStruct_intro_00400A88* D_intro_00400A88;
extern UnkStruct_80025C64* D_80025C64;
extern UnkStruct_80025C74* D_80025C74;
extern UnkStruct_80025C90* D_80025C90;
extern UnkStruct_intro_004009C0 D_intro_004009C0;
//extern UnkStruct_80025CAC* D_80025CAC;
extern UnkStruct_80025C84* D_80025C84;
extern UnkStruct_8002CCB0 D_8002CCB0[];
extern s32 D_intro_00400A94;
extern s32 D_intro_00400AA0[];
extern UnkStruct_8002CCB0 D_intro_00400AA8[];
extern UnkStruct_80025CF0 gDebugDisplayState[]; 
extern UnkStruct_80025BD8* D_80025BD8;
extern UnkStruct_80025C54* D_80025C54;
extern f32 D_intro_004009C8;
extern f32 D_intro_004009D4[];
extern s32 D_intro_004009EC[];
extern UnkStruct_intro_00400A84* D_intro_00400A84;
extern s32 D_intro_00400A90;
extern s32 gCurrentReplayEvent;


#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/intro/__entrypoint_func_intro_400000.s")

void func_intro_004004F0(void) {
    int i;

    gDebugDisplayState->numAiCars = (s32) D_intro_00400A94;
    if (gDebugDisplayState->gameStateFlag != 2) {
        gDebugDisplayState->currentTrack = D_80025C84->unk4(0);
        gDebugDisplayState->finishedIntroCount = 0;
        gDebugDisplayState->dbgOptsRecordIntro = 0;
        gDebugDisplayState->introReplayState = 0;
    }

    for (i = 0; i < 2; i++) {
        D_8002CCB0[i] = D_intro_00400AA8[i]; // M2C_MEMCPY_ALIGNED indicates a struct copy
        gDebugDisplayState->unk704C[i] = D_intro_00400AA0[i];
    }
    
}

void func_intro_004005CC(void) {
    s32 sp1C;
    f32 temp_fv1;

    sp1C = D_80025C90->unk20(0);
    temp_fv1 = D_intro_004009D4[gDebugDisplayState->finishedIntroCount] - uvClkGetSec(1);
    if (((sp1C & 0x1000) || (sp1C & 0x8000)) && (gDebugDisplayState->dbgOptsRecordIntro == 0)) {
        gDebugDisplayState->gameStateFlag = 0xE;
    } else {
        if ((gDebugDisplayState->dbgOptsRecordIntro != 0) && (temp_fv1 < -2.0f)) {
            D_80025C90->unk38(&gCurrentReplayEvent, sp1C);
            gDebugDisplayState->finishedIntroCount++;
            if (gDebugDisplayState->finishedIntroCount >= 6) {
                gDebugDisplayState->gameStateFlag = 0xE;
                return;
            }
            gDebugDisplayState->gameStateFlag = 2;
            gDebugDisplayState->currentTrack = D_intro_004009EC[gDebugDisplayState->finishedIntroCount];
            return;
        }
        if (temp_fv1 < 0.0f) {
            if (gDebugDisplayState->dbgOptsRecordIntro == 0) {
                gDebugDisplayState->finishedIntroCount++;
                if (gDebugDisplayState->finishedIntroCount >= 6) {
                    gDebugDisplayState->gameStateFlag = 0xE;
                    return;
                }
                gDebugDisplayState->gameStateFlag = 2;
                gDebugDisplayState->currentTrack = D_intro_004009EC[gDebugDisplayState->finishedIntroCount];
                return;
            }
        }
        if ((temp_fv1 < D_intro_004009C8) && (gDebugDisplayState->dbgOptsRecordIntro == 0)) {
            D_intro_004009D0 = 1;
            return;
        }
    }
    D_intro_00400A84->unk8(D_intro_00400A90, sp1C);
    D_80025BD8->unk14(0);
    if (gDebugDisplayState->unkPtr90 != 0) {
        D_80025C54->unkC(0, gDebugDisplayState->unk80);
        D_80025C54->unk124(gDebugDisplayState->unkPtr90);
    }
    D_intro_00400A88->unk4C();
    D_intro_00400A84->unkC(D_intro_00400A90);
}

void func_intro_00400820(void) {
    if (D_intro_004009D0 != 0) {
        D_80025C14->unk10(D_intro_00400A98);
        D_80025C14->unk10(D_intro_00400A9C);
    }
}

void func_intro_0040087C(void) {
    s32 sp1C;
    s32 temp_v0;
    s16 a0;

    sp1C = D_80025C74->unk28 + 0x10;
    D_80025C74->unk14();
    a0 = D_80025C64->unk70(); // (sll a0,v0,0x10 and sra t0,a0,0x10) means there is a conversion from s16 to s32
    temp_v0 = D_80025C64->unk74(a0);
    D_80025C64->unk78(temp_v0, &D_intro_004009C0);
    D_80025C64->unk8(sp1C, temp_v0);
    D_80025C90->unk34(temp_v0);
    if (D_80025CAC != 0) {
        D_80025CAC->unk14(temp_v0);
    }
}

s32 func_intro_00400960(s32* arg0, void *arg1, void *arg2, s32* arg3) {
    if (arg3 == NULL) {
        return 1;
    }
    if (arg0[/*unk34*/13] == 0x116) {
        D_intro_00400A88->unk48(*arg3);
    }
    return 0;
}
