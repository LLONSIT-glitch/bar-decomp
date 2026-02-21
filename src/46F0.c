#include "common.h"
#include "stdarg.h"

extern s32 D_8002DA80[];

void func_80003AF0(s32 arg0, ...) {
    va_list args;
    s32 arg;

    va_start(args, arg0);
    while (arg0 != 0) {
        if (arg0 >= 0x17) {
            break;
        }
        D_8002DA80[arg0 - 1] = va_arg(args, s32);
        arg0 = va_arg(args, s32);
    }
    
    va_end(args);
}

s32 func_80003B64(s32 arg0) {
    return D_8002DA80[arg0 - 1];
}
