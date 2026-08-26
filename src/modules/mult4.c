// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "global_exports.h"

void func_mult4_004000D4(void);
void func_mult4_00400124(void);

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/mult4/__entrypoint_func_mult4_400000.s")

void func_mult4_004000D4(void) {
    uvUnloadModule('lttr');
    uvUnloadModule('pwup');
    uvUnloadModule('wpon');
    gLetterExports = 0;
    gWeaponExports = 0;
    gPowerupExports = 0;
}

void func_mult4_00400124(void) {

}
