#include "common.h"

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/formLoader.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_800015D4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_80001654.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_800016A4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_80001724.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_800017A4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/uvLoader.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_800019A8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_800019B8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_80001A68.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_80001BC0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_80001C6C.s")

u32 uvFileReadBlock(s32 arg0, u32* sizeOut, void** arg2, s32 arg3) {
    u32 tag;
    u8* sp20;
    u32 size;
    u8* dst;

    tag = func_800024E4(arg0, sizeOut, arg2);
    if (tag != 0) {
        sp20 = func_80002F4C(*sizeOut);
        _uvMediaCopy(sp20, *arg2, *sizeOut);
        *arg2 = sp20;
    }
    if (tag == 'GZIP') { // 0x475A4950
        tag = (u32) uvMemRead(sp20, 4);
        size = (u32) uvMemRead(sp20 + 4, 4);
        if (!(arg3 & 2)) {
            dst = func_80002F4C(size);
            mio0Decode(sp20 + 8, dst);
            func_800031A8(sp20);
            *arg2 = dst;
        }
        *sizeOut = size;
    }
    return tag;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_80001DDC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_80001EAC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_80001F38.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_80001FC4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_80002004.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_80002088.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_8000218C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_8000226C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_80002390.s")
