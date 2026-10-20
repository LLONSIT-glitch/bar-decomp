#ifndef UVTERRA_ROM_H
#define UVTERRA_ROM_H

typedef struct UvTerra_Exports_s {
    /* 0x00 */ void (*func_uvterra_rom_004005A4)(void);
    /* 0x04 */ void (*func_uvterra_rom_00400640)(s32);
    /* 0x08 */ void (*func_uvterra_rom_004006E0)(s32, s32);
    /* 0x0C */ s32 (*func_uvterra_rom_00400774)(s32);
    /* 0x10 */ void (*func_uvterra_rom_0040078C)(s32);
    /* 0x14 */ void (*func_uvterra_rom_00400E70)(s32, u32, f32, f32, f32 *, Vec3F *);
    /* 0x18 */ void (*func_uvterra_rom_004010B4)(s32, u32, Vec3F *);
    /* 0x1C */ s32 (*func_uvterra_rom_004011A4)(s32, u32);
    /* 0x20 */ s32 (*func_uvterra_rom_00401284)(s32, f32, f32, f32, f32, s32 *, s32 *, s32 *);
    /* 0x24 */ void *(*func_uvterra_rom_00401E28)(s32);
    /* 0x28 */ u32 (*func_uvterra_rom_00401E64)(s32, f32, f32, s32 **);
    /* 0x2C */ s32 (*func_uvterra_rom_00402244)(s32, f32, f32, f32, f32, f32, f32, s32 **, f32 **);
    /* 0x30 */ void (*func_uvterra_rom_00403270)(s32, u32, s8 *, s8 *, s8 *);
    /* 0x34 */ void (*func_uvterra_rom_00403464)(s32, u32, Vec3F *, Vec3F *, Vec3F *);
    /* 0x38 */ s32 (*func_uvterra_rom_00403630)(s32, f32, f32, f32 *, f32 *);
    /* 0x3C */ s32 (*func_uvterra_rom_004037B8)(s32, u32, f32 *, f32 *);
    /* 0x40 */ s32 (*func_uvterra_rom_0040385C)(s32, s32, f32, f32, f32, f32, f32, f32, s32 **, f32 **, Vec3F **, s32 **);
    /* 0x44 */ s32 (*func_uvterra_rom_00404E14)(s32, s32, f32, f32, f32, f32, s32 **, f32 **, Vec3F **, s32 **);
    /* 0x48 */ s32 (*func_uvterra_rom_004060A4)(s32, u32);
    /* 0x4C */ s32 (*func_uvterra_rom_00406160)(s32, s32, s32 **);
    /* 0x50 */ void (*func_uvterra_rom_00406648)(s32, u32, f32, f32, u8 *, u8 *, u8 *, u8 *);
    /* 0x54 */ void (*func_uvterra_rom_00406C60)(s32, u32, f32, f32, u8 *, u8 *, u8 *, u8 *);
    /* 0x58 */ s32 (*func_uvterra_rom_004071A4)(s32, f32, f32, f32 **);
    /* 0x5C */ void (*func_uvterra_rom_004072BC)(s32);
    /* 0x60 */ s32 (*func_uvterra_rom_004072C8)(void);
    /* 0x64 */ void (*func_uvterra_rom_004072D4)(s32);
    /* 0x68 */ s32 (*func_uvterra_rom_004072E0)(void);
    /* 0x6C */ s32 (*func_uvterra_rom_004074EC)(s32, s32, s32 **);
    /* 0x70 */ void (*func_uvterra_rom_00407680)(s32, f32);
    /* 0x74 */ s32 (*func_uvterra_rom_00407A80)(s32, s32, s32);
    /* 0x78 */ void (*func_uvterra_rom_00408300)(s32, s32, Mtx4F *);
    /* 0x7C */ void (*func_uvterra_rom_00408534)(s32, ...);
    /* 0x80 */ void (*func_uvterra_rom_00408614)(s32, s32, Mtx4F *);
    /* 0x84 */ u16 (*func_uvterra_rom_004087D8)(s32);
    /* 0x88 */ void (*func_uvterra_rom_0040880C)(s32, s32);
    /* 0x8C */ s32 (*func_uvterra_rom_0040888C)(s32, f32, f32, f32);
    /* 0x90 */ s32 (*func_uvterra_rom_00408AD8)(s32, f32, f32, f32, f32, s32 **, f32 **, Vec3F **);
    /* 0x94 */ s32 (*func_uvterra_rom_00409394)(s32, f32, f32, f32, f32, f32, f32, s32 **, f32 **, Vec3F **);
    /* 0x98 */ void (*func_uvterra_rom_0040AB14)(s32, ...);
    /* 0x9C */ void (*func_uvterra_rom_0040ABB4)(s32, s32);
    /* 0xA0 */ s32 (*func_uvterra_rom_0040ABE0)(s32);
    /* 0xA4 */ UnkSobjDraw *(*func_uvterra_rom_0040AC14)(s32);
    /* 0xA8 */ u8 (*func_uvterra_rom_0040AC8C)(s32);
    /* 0xAC */ void (*func_uvterra_rom_0040D128)(s32, s32, f32, f32, void *(*)(s32, s32), s32, f32);
    /* 0xB0 */ s32 *D_uvterra_rom_0040FBD8;
    /* 0xB4 */ s32 *D_uvterra_rom_0040FBDC;
    /* 0xB8 */ s32 *D_uvterra_rom_0040FBE0;
} UvTerra_Exports;                                  /* size = 0xBC */
#endif /* UVTERRA_ROM_H */
