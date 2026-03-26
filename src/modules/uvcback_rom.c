#include "common.h"

typedef struct UvCback_Rom_004000F0_s {
    s32 unk0; // Count of something
    s32 unk4;
} UvCback_Rom_004000F0;

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvcback_rom/__entrypoint_func_uvcback_rom_400000.s")

void func_uvcback_rom_00400078(void) {

}

void* func_uvcback_rom_00400080(s32 arg0) {
    s32* ptr;
    u32 size;

    size = (arg0 * 8) + 4;
    ptr = _uvMemAllocAlign8(size);
    uvMemSet(ptr, 0, size);
    *ptr = arg0;
    return ptr;
}

void func_uvcback_rom_004000D0(void* ptr) {
    _uvMemFree(ptr);
}

void func_uvcback_rom_004000F0(UvCback_Rom_004000F0* arg0, s32 arg1) {
    void* (*temp_v0)(s32);
    s32 var_s1;
    s32 count;
    UvCback_Rom_004000F0* var_s0;

    if (arg0 != NULL) {
        count = arg0->unk0;
        for (var_s1 = 0; var_s1 < count; var_s1++) {
            temp_v0 = arg0[var_s1].unk4;
            if (temp_v0 != NULL) {
                temp_v0(arg1);
                count = arg0->unk0;
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvcback_rom/func_uvcback_rom_0040016C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvcback_rom/func_uvcback_rom_00400320.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvcback_rom/func_uvcback_rom_004003C8.s")

