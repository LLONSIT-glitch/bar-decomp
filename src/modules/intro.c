// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"

typedef struct UnkStruct_80025C64_s {
    char pad00[8];
    void (*unk8)(s32, s32);
    char pad68[0x64];
    s32 (*unk70)(void);
    s32 (*unk74)(s32);
    void (*unk78)(s32, s32);
} UnkStruct_80025C64;

typedef struct UnkStruct_80025C90_s {
    char pad34[0x34];
    void (*unk34)(s32);
} UnkStruct_80025C90;

typedef struct UnkStruct_intro_004009C0_s {
    s32 pad0;
} UnkStruct_intro_004009C0;

typedef struct UnkStruct_intro_00400A88_s {
    char pad0[0x48];
    void (*unk48)(s32);
} UnkStruct_intro_00400A88;

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


#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/intro/__entrypoint_func_intro_400000.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/intro/func_intro_004004F0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/intro/func_intro_004005CC.s")


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
