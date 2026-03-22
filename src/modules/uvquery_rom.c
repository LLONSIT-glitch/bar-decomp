#include "common.h"

extern void *D_00400630;
extern void *D_00400634;
extern void *D_00400638;
extern void *D_00400644;
extern void *D_0040064C;
extern s32 D_0040063C;
extern s32 D_00400640;
extern s32 D_00400620;
extern s32 D_00400650;
extern s32 D_00400654;

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvquery_rom/__entrypoint_func_uvquery_rom_400000.s")

void func_uvquery_rom_004001AC(void) {
    _uvMemFree(D_00400630);
    _uvMemFree(D_00400634);
    _uvMemFree(D_00400638);
    _uvMemFree(D_00400644);
    _uvMemFree(D_0040064C);
}

s32 func_uvquery_rom_00400200(void) {
    return D_00400634;
}

s32 func_uvquery_rom_0040020C(void) {
    return D_00400630;
}

s32 func_uvquery_rom_00400218(void) {
    return D_00400638;
}

s32 func_uvquery_rom_00400224(void) {
    if (D_00400650 != 0) {
        return (D_00400654 < D_00400620) ? D_00400654 : D_00400620;
    }
    return D_00400620;
}


s32 *func_uvquery_rom_00400270(void) {
    return &D_0040063C;
}

s32 *func_uvquery_rom_0040027C(void) {
    return &D_00400640;
}

s32 func_uvquery_rom_00400288(void) {
    return D_00400644;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvquery_rom/func_uvquery_rom_00400294.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvquery_rom/func_uvquery_rom_004004CC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvquery_rom/func_uvquery_rom_004004F4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvquery_rom/func_uvquery_rom_00400558.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvquery_rom/func_uvquery_rom_004005C0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvquery_rom/func_uvquery_rom_004005D4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvquery_rom/func_uvquery_rom_004005EC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvquery_rom/func_uvquery_rom_004005F8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvquery_rom/func_uvquery_rom_00400604.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvquery_rom/func_uvquery_rom_00400610.s")

