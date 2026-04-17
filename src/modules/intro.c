// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"

typedef struct UnkStruct_80025BD8_s {
    char pad0[0x14];
    void (*unk14)(f32);
} UnkStruct_80025BD8;

typedef struct UnkStruct_80025C54_s {
    char pad0[0xC];
    void (*unkC)(s32, f32);
    u8 pad10[0x120 - 0x10];
    s32 (*unk120)(s32);
    s32 (*unk124)(s32);
    s32 (*unk128)(s32, s32, f32);
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
    char pad0[0x10];
    s32 (*unk10)(void);
    s32 (*unk20)(s32);
    char pad24[0x1C];
    void (*unk34)(s32);
    void (*unk38)(s32,s32);
    void (*unk3C)(s32);
} UnkStruct_80025C90;

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
    char pad0[0x8 - 0x0];
    void (*unk8)(s32,s32);
    char padC[0x14 - 0xC];
    void (*unk14)(s32,s32);
    char padC[0x48 - 0x14];
    void (*unk48)(s32);
    void (*unk4C)(void);
} UnkStruct_intro_00400A88;

typedef struct UnkStruct_intro_00400A90_s {
    /* 0x00 */ struct UnkPlayer* unk0;
    /* 0x04 */ s32 (*unk4)(void*);
    /* 0x08 */ s32 (*unk8[2])(void*);                       /* maybe part of unk4[3]? */
    /* 0x0C */ void (*unkC)(s32);
    /* 0x10 */ void (*unk10)(s32);
    /* 0x14 */ s32 (*unk14)(s32);                   /* inferred */
    /* 0x18 */ char pad18[4];
    /* 0x1C */ void (*unk1C)(s32, ...);
} UnkStruct_intro_00400A90;

typedef struct UnkStruct_intro_00400A84_s {
    char pad0[0x4];
    s32 (*unk4)(s32);
    void (*unk8)(struct UnkPlayer*);
    void (*unkC)(struct UnkPlayer*);
    char pad24[0x10];
} UnkStruct_intro_00400A84;

typedef struct Intro_Exports_s {
    /* 0x00 */ void (*func_intro_004004F0)(void);                      /* inferred */
    /* 0x04 */ void (*func_intro_004005CC)(void);
    /* 0x08 */ void (*func_intro_00400820)(void);
} Intro_Exports;

typedef struct UnkStruct_80025C88_s {
    /* 0x00 */ void (*unk0)(void);                      /* inferred */
    /* 0x04 */ void (*unk4)(s32, s32);
} UnkStruct_80025C88;

typedef struct UnkStruct_80025C78_s {
    /* 0x00 */ void (*unk0)(void);                      /* inferred */
    /* 0x04 */ void (*unk4)(s32, s32);
               char pad8[0x34-0x8];
               void (*unk34)(s32);
               void (*unk38)(s32);
               void (*unk3C)(s32);
} UnkStruct_80025C78;

typedef struct UnkStruct_80025C10_s {
    /* 0x00 */ void (*unk0)(void);                      /* inferred */
    /* 0x04 */ void (*unk4)(s32, s32);
               char pad8[0x4C-0x8];
               void (*unk4C)(s32, s32);
} UnkStruct_80025C10;

typedef struct UnkStruct_80025BE4_s {
    char pad8[0x2C];
    void (*unk2C)(void);                      /* inferred */
} UnkStruct_80025BE4;



typedef struct UnkPlayer_Unk0 {
    u8 pad0[0x118];
    s32 unk118;
} UnkPlayer_Unk0;
typedef struct UnkPlayer_Unk4 {
    u8 pad0[0x404];
    s32 unk404;
    s32 unk408;
} UnkPlayer_Unk4;
typedef struct UnkPlayer_UnkC {
    u8 pad0[0x140];
    s32 unk140;
} UnkPlayer_UnkC;
typedef struct UnkPlayer {
    UnkPlayer_Unk0* unk0;
    UnkPlayer_Unk4* unk4;
    s32 pad8[0x1];
    UnkPlayer_UnkC* unkC;
} UnkPlayer;

void __entrypoint_func_intro_400000(Intro_Exports *arg0);
void func_intro_004004F0(void);
void func_intro_004005CC(void);
void func_intro_00400820(void);
void func_intro_0040087C(void);
s32 func_intro_00400960(s32* arg0, void *arg1, void *arg2, s32* arg3);

extern UnkStruct_80025BE4* D_80025BE4;
extern UnkStruct_80025C10* D_80025C10;
extern UnkStruct_80025C14* D_80025C14;
extern UnkStruct_80025C54* D_80025C54;
extern UnkStruct_80025C74* D_80025C74;
extern UnkStruct_80025C78* D_80025C78;
extern UnkStruct_80025C88* D_80025C88;
extern UnkStruct_80025C90* D_80025C90;
extern UnkStruct_8002CCB0 D_8002CCB0[];
extern u8 D_intro_00400A04[];
extern u8 D_intro_00400A0C[];
extern u16 D_intro_00400A14[];
extern s32 D_intro_00400A20[][2];
extern UnkStruct_8002CCB0 D_intro_00400A50;
extern UnkStruct_intro_00400A84* D_intro_00400A84;
extern UnkStruct_intro_00400A88* D_intro_00400A88;
extern UnkStruct_8002D1A4* D_intro_00400A8C;
extern UnkStruct_intro_00400A90 D_intro_00400A90;
extern s32 D_intro_00400A98;
extern s32 D_intro_00400AA0[];
extern UnkStruct_8002CCB0 D_intro_00400AA8[];
extern s32 gCurrentReplayEvent;
extern UnkStruct_80025CF0 gDebugDisplayState[];
extern UnkStruct_80025BD8* D_80025BD8;
extern UnkStruct_80025C54* D_80025C54;
extern f32 D_intro_004009C8;
extern f32 D_intro_004009D4[];
extern s32 D_intro_004009EC[];
extern UnkStruct_intro_00400A84* D_intro_00400A84;
//extern s32 D_intro_00400A90;
extern s32 gCurrentReplayEvent;
extern UnkStruct_80025C90* D_80025C90;
extern u8 D_intro_004009D0;
extern s32 D_intro_00400A94;
extern UnkStruct_80025C84* D_80025C84;
extern UnkStruct_80025C64* D_80025C64;
extern s32 D_intro_00400A9C;
extern UnkStruct_intro_004009C0 D_intro_004009C0;
extern UnkStruct_80025C84* D_80025C84;


void __entrypoint_func_intro_400000(Intro_Exports *arg0) {
    s32 pad[3];
    s32 sp70;
    s32 temp_a2;
    s32 i;

    s32 j;

    uvSetFileDirOvlPtr(arg0);
    arg0->func_intro_004004F0 = func_intro_004004F0;
    arg0->func_intro_004005CC = &func_intro_004005CC;
    arg0->func_intro_00400820 = func_intro_00400820;
    
    D_intro_00400A90.unk4  = gDebugDisplayState->numAiCars;
    gDebugDisplayState->numAiCars = 0;
    for (j = 0; j < 2; j++) {
        D_intro_00400AA8[j] = D_8002CCB0[j];
        D_intro_00400AA0[j] = gDebugDisplayState->unk704C[j];
        D_8002CCB0[j] = D_intro_00400A50;
        gDebugDisplayState->unk704C[j] = 0;
    }
    D_intro_00400A84 = uvLoadModule('plyr');
    D_intro_00400A88 = uvLoadModule('motn');
    D_intro_00400A8C = func_800034E0('cara');
    if (gDebugDisplayState->unkPtr90 != 0) {
        D_80025C54->unk128(gDebugDisplayState->unkPtr90, 0, 1.0f);
    }
    D_intro_00400A90.unk0 = D_intro_00400A84->unk4(0);
    sp70 = D_intro_00400A90.unk0->unkC;
    D_80025C88->unk4(6, &sp70);
    D_intro_00400A90.unk0->unkC->unk140 = 3;
    D_intro_00400A90.unk0->unk4->unk408 = D_intro_00400A04[gDebugDisplayState->finishedIntroCount];
    D_intro_00400A90.unk0->unk4->unk404 = D_intro_00400A0C[gDebugDisplayState->finishedIntroCount];
    D_intro_00400A90.unk0->unk0->unk118 = 1;
    D_intro_00400A88->unk8(D_intro_00400A90.unk0->unk0, 0xA);
    D_intro_00400A88->unk14(D_intro_00400A90.unk0->unk0, 0x42569446);
    D_intro_00400A8C->unk8(D_intro_00400A90.unk0->unk4);
    if (gDebugDisplayState->unkPtr90 != 0) {
        D_80025C54->unk120(gDebugDisplayState->unkPtr90);
    }

    for (i = 0; i < 2; i++) {
        func_800019B8('UVBT', D_intro_00400A20[gDebugDisplayState->finishedIntroCount][i]);
        D_intro_00400A90.unk8[i] = D_80025C14->unk4();
        D_80025C14->unk1C(D_intro_00400A90.unk8[i], 9, D_intro_00400A20[gDebugDisplayState->finishedIntroCount][i], 3, 1, 0xB, 1, 0xC, 0, 6, 0, 0);
    }

    temp_a2 = 0xA0 - (D_80025C14->unk14(D_intro_00400A90.unk8[0]) / 2); // This broke the entire function lol
    D_80025C14->unk1C(D_intro_00400A90.unk8[0], 2, temp_a2, 0x64, 0);
    D_80025C14->unk1C(D_intro_00400A90.unk8[1], 2, temp_a2, 0x64, 0);
    func_800019B8('UVMD', 0x116);
    D_80025C10->unk4C(0x116, func_intro_00400960);
    D_80025C74->unk1C((s32) func_intro_0040087C);
    D_80025C74->unk10(0);
    D_80025C90->unk10();
    if (gDebugDisplayState->dbgOptsRecordIntro == 0) {
        D_80025C90->unk3C(&gCurrentReplayEvent);
        gDebugDisplayState->introReplayState = 1;
    }
    uvClkReset(1);
    D_80025C78->unk3C(gDebugDisplayState->optionsMusicVol);
    D_80025BE4->unk2C();
    D_80025C78->unk34(D_intro_00400A14[gDebugDisplayState->finishedIntroCount]);
    D_80025C78->unk38(0);
}

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
            D_80025C90->unk38((s32) &gCurrentReplayEvent, sp1C);
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
                } else {
                    gDebugDisplayState->gameStateFlag = 2;
                    gDebugDisplayState->currentTrack = D_intro_004009EC[gDebugDisplayState->finishedIntroCount];
                }
                return;
            }
        }
        if ((temp_fv1 < D_intro_004009C8) && (gDebugDisplayState->dbgOptsRecordIntro == 0)) {
            D_intro_004009D0 = 1;
            return;
        }
    }

    D_intro_00400A84->unk8(D_intro_00400A90.unk0);
    D_80025BD8->unk14(0.0f);
    if (gDebugDisplayState->unkPtr90 != 0) {
        D_80025C54->unkC(0, gDebugDisplayState->unk80);
        D_80025C54->unk124(gDebugDisplayState->unkPtr90);
    }
    D_intro_00400A88->unk4C();
    D_intro_00400A84->unkC(D_intro_00400A90.unk0);
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
