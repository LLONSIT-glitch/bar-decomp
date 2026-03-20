#include "ultra64.h"

typedef struct UnkStruct_00400C14_1_s {
    char pad[0x14];
} UnkStruct_00400C14_1;
 
typedef struct UnkStruct_00400C14_s {
    char pad[0xC];
    s32 unkC;
    s32 pad10;
} UnkStruct_00400C14;

void _uvMemFree(s32);                                  /* extern */
void func_80003760(s32 tag);                                 /* extern */


extern UnkStruct_00400C14* D_00400C14;
extern s32 D_00400C00;
extern s32 D_00400C04;
extern s32 D_00400C08;
extern s32 D_00400C10;

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvsort_rom/__entrypoint_func_uvsort_rom_400000.s")

void func_uvsort_rom_00400238(s32 arg0) {

}

void func_uvsort_rom_00400240(void) {
    s32 var_s0;
    s32 var_s1;

    for (var_s0 = 0; var_s0 < D_00400C10; var_s0++) {
        _uvMemFree(D_00400C14[var_s0].unkC);
    }
    _uvMemFree(D_00400C14);
    func_80003760('CHAN');
    D_00400C04 = 0;
    func_80003760('CBCK');
    D_00400C00 = 0;
    func_80003760('GMGR');
    D_00400C08 = 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvsort_rom/func_uvsort_rom_00400308.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvsort_rom/func_uvsort_rom_00400594.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvsort_rom/func_uvsort_rom_0040059C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvsort_rom/func_uvsort_rom_004006F8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvsort_rom/func_uvsort_rom_00400750.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvsort_rom/func_uvsort_rom_00400834.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvsort_rom/func_uvsort_rom_00400898.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvsort_rom/func_uvsort_rom_00400B24.s")

