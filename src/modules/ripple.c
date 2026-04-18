// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "global_exports.h"

typedef struct Ripple_s {
    Mtx4F unk0;
    f32 curSize;
    f32 fade;
    f32 initSize;
    s32 active;
} Ripple; // size = 0x50

extern Ripple D_ripple_00400748[];
extern s32 D_ripple_00401648;

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/ripple/func_ripple_00400000.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/ripple/func_ripple_004001E8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/ripple/func_ripple_004002D8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/ripple/func_ripple_004004C4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/ripple/func_ripple_004005A0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/ripple/__entrypoint_func_ripple_400604.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/ripple/func_ripple_004006AC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/ripple/func_ripple_004006B8.s")


void func_ripple_004006E0(void) {
    int i;
    // clang-format off
    for (i = 0; i < 12; i++) {  D_ripple_00400748[i].active = FALSE; }
    // clang-format on
    D_ripple_00401648 = 0;
}
