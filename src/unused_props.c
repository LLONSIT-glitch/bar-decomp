#include "common.h"
#include "stdarg.h"

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

s32 uvUnusedGetProp(s32 index) {
    return sUnusedPropArray[index - 1];
}
