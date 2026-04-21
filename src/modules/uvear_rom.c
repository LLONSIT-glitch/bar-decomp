// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"


typedef struct UnkStruct_uvear_rom_00400854_s {
    /* 0x00 */ f32 unk0;                            /* inferred */
    /* 0x04 */ f32 unk4;                            /* inferred */
    /* 0x08 */ f32 unk8;                            /* inferred */
    /* 0x0C */ f32 unkC;                            /* inferred */
    /* 0x10 */ f32 unk10;                           /* inferred */
    /* 0x14 */ f32 unk14;                           /* inferred */
    /* 0x18 */ f32 unk18;                           /* inferred */
    /* 0x1C */ f32 unk1C;                           /* inferred */
    /* 0x20 */ f32 unk20;                           /* inferred */
    /* 0x24 */ f32 unk24;                           /* inferred */
    /* 0x28 */ f32 unk28;                           /* inferred */
    /* 0x2C */ f32 unk2C;                           /* inferred */
    /* 0x30 */ f32 unk30;                           /* inferred */
    /* 0x34 */ f32 unk34;                           /* inferred */
    /* 0x38 */ f32 unk38;                           /* inferred */
    /* 0x3C */ char pad3C[4];
    /* 0x40 */ f64 unk40;                           /* inferred */
} UnkStruct_uvear_rom_0040085;                      /* size = 0x48 */

extern UnkStruct_uvear_rom_0040085* D_uvear_rom_00400854;

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvear_rom/__entrypoint_func_uvear_rom_400000.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvear_rom/func_uvear_rom_0040018C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvear_rom/func_uvear_rom_004001BC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvear_rom/func_uvear_rom_00400230.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvear_rom/func_uvear_rom_00400290.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvear_rom/func_uvear_rom_004002E0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvear_rom/func_uvear_rom_00400340.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvear_rom/func_uvear_rom_00400390.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvear_rom/func_uvear_rom_00400424.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvear_rom/func_uvear_rom_00400494.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvear_rom/func_uvear_rom_004004E4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvear_rom/func_uvear_rom_004006D4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvear_rom/func_uvear_rom_0040077C.s")
