// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"


extern f32 D_00403750;
extern f32 D_00403754;
extern f32 D_00403758;

void uvUnloadModule(s32 tag);                                 /* extern */

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/__entrypoint_func_uvfmtx_rom_400000.s")

void func_uvfmtx_rom_00400310(void) {
    uvUnloadModule('MATH');
    uvUnloadModule('FVEC');
    uvUnloadModule('IMTX');
}

void func_uvfmtx_rom_0040034C(f32 arg0, f32 arg1, f32 arg2) {
    D_00403750 = arg0;
    D_00403754 = arg1;
    D_00403758 = arg2;
}


#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00400370.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00400504.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00400588.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_004005D4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00400894.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00400B68.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00400BB8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00400FF8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00401000.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00401408.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_004014D0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00401580.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00401604.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00401790.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00401B88.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00401C3C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00401D0C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00401DA8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00401F74.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00402038.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00402110.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_004021E0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_0040246C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00402628.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_004027CC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00402858.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_004028DC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00402908.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_004029B8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_004029DC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00402B30.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00402D40.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00402D84.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00402DB0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00402DFC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00402E2C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00402E7C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00402EAC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00402EFC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00402F2C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00402F5C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00403020.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_004030FC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00403180.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00403248.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00403290.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00403480.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00403568.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfmtx_rom/func_uvfmtx_rom_00403648.s")

