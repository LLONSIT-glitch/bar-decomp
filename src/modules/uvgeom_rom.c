#include "common.h"
#include "module.h"

void func_80003760(s32 tag);                                 /* extern */
extern void* D_00401754;
extern u16 D_00401760;
extern Gfx* D_0040175C; 

typedef struct UvGeom_Rom_0040019C_s {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ s32 unk4;                            /* inferred */
    /* 0x08 */ Gfx* unk8;                           /* inferred */
    /* 0x0C */ s16 unkC;                            /* inferred */
    /* 0x0E */ s16 unkE;                            /* inferred */
    /* 0x10 */ s16 unk10;                           /* inferred */
    /* 0x12 */ s16 unk12;                           /* inferred */
} UvGeom_Rom_0040019C;                              /* size = 0x14 */


#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgeom_rom/__entrypoint_func_uvgeom_rom_400000.s")

void func_uvgeom_rom_00400124(void) {
    func_80003760('GMGR');
    if (D_00401760 & 1) {
        _uvMemFree(D_00401754);
    }
}

void func_uvgeom_rom_00400168(s32 arg0, Gfx** gdlh) {
    if (arg0 == 0) {
        gSPEndDisplayList(gdlh[0]++);
        D_0040175C = *gdlh;
    }
}

s32 func_uvgeom_rom_0040019C(s32 arg0, s32 arg1, UvGeom_Rom_0040019C* arg2, Gfx** arg3) {
    s32 var_v1;

    if (*arg3 == NULL) {
        *arg3 = D_0040175C;
        var_v1 = 0;
    } else {
        var_v1 = 1;
    }
    arg2->unk4 = 0x160FFF;
    arg2->unk10 = 0;
    arg2->unk12 = 0;
    arg2->unkC = -1;
    arg2->unkE = arg0;
    arg2->unk0 = arg1;
    arg2->unk8 = *arg3;
    return var_v1;
}


#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgeom_rom/func_uvgeom_rom_004001F0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgeom_rom/func_uvgeom_rom_00400398.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgeom_rom/func_uvgeom_rom_00400760.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgeom_rom/func_uvgeom_rom_00400F40.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgeom_rom/func_uvgeom_rom_00401270.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvgeom_rom/func_uvgeom_rom_00401518.s")

