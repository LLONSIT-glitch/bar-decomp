#ifndef UVQUAT_ROM_H
#define UVQUAT_ROM_H

typedef struct UnkStruct_uvquat_rom_004000D8_Arg0_s {
    /* 0x00 */ f32 unk0;                /* inferred */
    /* 0x04 */ f32 unk4;                /* inferred */
    /* 0x08 */ f32 unk8;                /* inferred */
    /* 0x0C */ f32 unkC;                /* inferred */
} UnkStruct_uvquat_rom_004000D8_Arg0_s; /* size = 0x10 */

typedef struct UnkStruct_uvquat_rom_004000D8_Arg1_s {
    /* 0x00 */ f32 unk0[2][4];
    /* 0x20 */ f32 unk20[3];            /* inferred */
} UnkStruct_uvquat_rom_004000D8_Arg1_s; /* size = 0x2C */

typedef struct UvQuat_Exports_s {
    /* 0x00 */ void (*func_uvquat_rom_004000A8)(void);                      /* inferred */
    /* 0x04 */ void (*func_uvquat_rom_004000D8)(UnkStruct_uvquat_rom_004000D8_Arg0_s*, UnkStruct_uvquat_rom_004000D8_Arg1_s*); /* inferred */
    /* 0x08 */ void (*func_uvquat_rom_00400384)(UnkStruct_uvquat_rom_004000D8_Arg0_s*, f32, f32, f32); /* inferred */
    /* 0x0C */ void (*func_uvquat_rom_00400524)(Mtx4F*, UnkStruct_uvquat_rom_004000D8_Arg0_s*); /* inferred */
    /* 0x10 */ void (*func_uvquat_rom_0040070C)(UnkStruct_uvquat_rom_004000D8_Arg0_s*, UnkStruct_uvquat_rom_004000D8_Arg0_s*, f32, f32, f32, f32); /* inferred */
    /* 0x14 */ void (*func_uvquat_rom_0040087C)(UnkStruct_uvquat_rom_004000D8_Arg0_s*, UnkStruct_uvquat_rom_004000D8_Arg0_s*, UnkStruct_uvquat_rom_004000D8_Arg0_s*); /* inferred */
    /* 0x18 */ void (*func_uvquat_rom_00400998)(UnkStruct_uvquat_rom_004000D8_Arg0_s*, UnkStruct_uvquat_rom_004000D8_Arg0_s*); /* inferred */
    /* 0x1C */ void (*func_uvquat_rom_004009BC)(UnkStruct_uvquat_rom_004000D8_Arg0_s*, UnkStruct_uvquat_rom_004000D8_Arg0_s*, UnkStruct_uvquat_rom_004000D8_Arg0_s*, f32); /* inferred */
} UvQuat_Exports;                                   /* size = 0x20 */

#endif /* UVQUAT_ROM_H */
