// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/intro/__entrypoint_func_intro_400000.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/intro/func_intro_004004F0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/intro/func_intro_004005CC.s")

extern UnkStruct_80025C14* D_80025C14;
extern u8 D_intro_004009D0;
extern s32 D_intro_00400A98;
extern s32 D_intro_00400A9C;

void func_intro_00400820(void) {
    if (D_intro_004009D0 != 0) {
        D_80025C14->unk10(D_intro_00400A98);
        D_80025C14->unk10(D_intro_00400A9C);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/intro/func_intro_0040087C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/intro/func_intro_00400960.s")

