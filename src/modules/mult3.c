// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "global_exports.h"

void func_mult3_004000D4(void);
void func_mult3_00400124(void);

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/mult3/__entrypoint_func_mult3_400000.s")

void func_mult3_004000D4(void) {
    uvUnloadModule('lttr');
    uvUnloadModule('pwup');
    uvUnloadModule('wpon');
    gLetterExports = 0;
    gWeaponExports = 0;
    gPowerupExports = 0;
}

void func_mult3_00400124(void) {

}
