// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "stdarg.h"

// Apparently With prop 8 you can set the Imtx stack size, see modules/uvimtx_rom.c
static s32 sUnusedPropArray[24];

void uvUnusedProps(s32 index, ...) {
    va_list args;

    va_start(args, index);
    while (index != 0) {
        // If the prop value exceds the array size, stop 
        if (index >= 23) {
            break;
        }
        sUnusedPropArray[index - 1] = va_arg(args, s32);
        index = va_arg(args, s32);
    }
    
    va_end(args);
}

void* uvGetUnknownProp(s32 index) {
    return sUnusedPropArray[index - 1];
}
