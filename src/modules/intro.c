// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"

typedef struct UnkStruct_intro_00400A88_s {
    char pad0[0x48];
    void (*unk48)(s32);
} UnkStruct_intro_00400A88;

extern UnkStruct_80025C14* D_80025C14;
extern u8 D_intro_004009D0;
extern s32 D_intro_00400A98;
extern s32 D_intro_00400A9C;
extern UnkStruct_intro_00400A88* D_intro_00400A88;

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/intro/__entrypoint_func_intro_400000.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/intro/func_intro_004004F0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/intro/func_intro_004005CC.s")


void func_intro_00400820(void) {
    if (D_intro_004009D0 != 0) {
        D_80025C14->unk10(D_intro_00400A98);
        D_80025C14->unk10(D_intro_00400A9C);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/intro/func_intro_0040087C.s")

s32 func_intro_00400960(s32* arg0, void *arg1, void *arg2, s32* arg3) {
    if (arg3 == NULL) {
        return 1;
    }
    if (arg0[/*unk34*/13] == 0x116) {
        D_intro_00400A88->unk48(*arg3);
    }
    return 0;
}
