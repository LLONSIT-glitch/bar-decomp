#ifndef UVMODELLD_ROM_H
#define UVMODELLD_ROM_H
typedef struct UvModelLd_Exports_s {
    /* 0x0 */ void (*func_uvmodelld_rom_0040006C)();                       /* inferred */
    /* 0x4 */ ParsedUVMD *(*uvParseUVMD)(u8 *);            /* inferred */
    /* 0x8 */ void (*func_uvmodelld_rom_00400D38)(ParsedUVMD *);           /* inferred */
} UvModelLd_Exports;                                /* size = 0xC */

#endif /* UVMODELLD_ROM_H */
