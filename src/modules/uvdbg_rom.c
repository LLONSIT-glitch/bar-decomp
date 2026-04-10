// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "uvfmtx_rom.h"
#include "uvgfxmgr_rom.h"
#include "uvstring_rom.h"

/*
 * D_uvdbg_rom_00402FD8 = uvLoadModule('FONT');
 * D_uvdbg_rom_00402FDC = uvLoadModule('STRG');
 * D_uvdbg_rom_00402FE0 = uvLoadModule('AMGR');
 * D_uvdbg_rom_00402FE4 = uvLoadModule('STAT');
 * D_uvdbg_rom_00402FE8 = uvLoadModule('GMGR');
 * D_uvdbg_rom_00402FEC = uvLoadModule('GEOM');
 * D_uvdbg_rom_00402FF0 = uvLoadModule('CONT');
 * D_uvdbg_rom_00402FF4 = uvLoadModule('FMTX');
 * D_uvdbg_rom_00402FF8 = uvLoadModule('CHAN');
 * D_uvdbg_rom_00402FFC = uvLoadModule('CBCK');
 */

struct Entry {
    f64 unk0;
    s32 unk8;
};

typedef struct UnkStruct_8002E440_s {
    struct Entry entry[30];
} UnkStruct_8002E440;

extern UvFMtx_Rom_Exports* D_uvdbg_rom_00402FF4;
extern UvGfxMgr_Exports* D_uvdbg_rom_00402FE8;
extern UvString_Exports* D_uvdbg_rom_00402FDC;
extern f32 D_uvdbg_rom_00402F70;
extern f32 D_uvdbg_rom_00402F74;
extern f32 D_uvdbg_rom_00402F78;
extern f32 D_uvdbg_rom_00402F7C;
extern f32 D_uvdbg_rom_00402F80;
extern f32 D_uvdbg_rom_00402F84;
extern f32 D_uvdbg_rom_00402F88;
extern f32 D_uvdbg_rom_00402F8C;
extern f32 D_uvdbg_rom_00402F90;
extern f32 D_uvdbg_rom_00402F94;
extern f32 D_uvdbg_rom_00402F98;
extern f32 D_uvdbg_rom_00402F9C;
extern f32 D_uvdbg_rom_00402FA0;
extern f32 D_uvdbg_rom_00402FA4;
extern f32 D_uvdbg_rom_00402FA8;
extern f32 D_uvdbg_rom_00402FAC;
extern f32 D_uvdbg_rom_00402FB0;
extern f32 D_uvdbg_rom_00402FB4;

extern UnkStruct_8002E440 D_8002E440[];
extern s32 D_8002EDB8[];

void func_uvdbg_rom_00400000(s32 arg0) {
    D_uvdbg_rom_00402F70 = (f32) uvClkGetSec(0);
}

void func_uvdbg_rom_0040002C(s32 arg0) {
    D_uvdbg_rom_00402F74 = (f32) uvClkGetSec(0);
}

void func_uvdbg_rom_00400058(s32 arg0) {
    D_uvdbg_rom_00402F78 = (f32) uvClkGetSec(0);
}

void func_uvdbg_rom_00400084(s32 arg0) {
    D_uvdbg_rom_00402F7C = (f32) uvClkGetSec(0);
}

void func_uvdbg_rom_004000B0(s32 arg0) {
    D_uvdbg_rom_00402F80 = (f32) uvClkGetSec(0);
}

void func_uvdbg_rom_004000DC(s32 arg0) {
    D_uvdbg_rom_00402F84 = (f32) uvClkGetSec(0);
}

void func_uvdbg_rom_00400108(s32 arg0) {
    D_uvdbg_rom_00402F88 = (f32) uvClkGetSec(0);
}

void func_uvdbg_rom_00400134(s32 arg0) {
    D_uvdbg_rom_00402F8C = (f32) uvClkGetSec(0);
}

void func_uvdbg_rom_00400160(s32 arg0) {
    D_uvdbg_rom_00402F90 = (f32) uvClkGetSec(0);
}

void func_uvdbg_rom_0040018C(s32 arg0) {
    D_uvdbg_rom_00402F94 = (f32) uvClkGetSec(0);
}

void func_uvdbg_rom_004001B8(s32 arg0) {
    D_uvdbg_rom_00402F98 = (f32) uvClkGetSec(0);
}

void func_uvdbg_rom_004001E4(s32 arg0) {
    D_uvdbg_rom_00402F9C = (f32) uvClkGetSec(0);
}

void func_uvdbg_rom_00400210(s32 arg0) {
    D_uvdbg_rom_00402FA0 = (f32) uvClkGetSec(0);
}

void func_uvdbg_rom_0040023C(s32 arg0) {
    D_uvdbg_rom_00402FA4 = (f32) uvClkGetSec(0);
}

void func_uvdbg_rom_00400268(s32 arg0) {
    D_uvdbg_rom_00402FA8 = (f32) uvClkGetSec(0);
}

void func_uvdbg_rom_00400294(s32 arg0) {
    D_uvdbg_rom_00402FAC = (f32) uvClkGetSec(0);
}

void func_uvdbg_rom_004002C0(s32 arg0) {
    D_uvdbg_rom_00402FB0 = (f32) uvClkGetSec(0);
}

void func_uvdbg_rom_004002EC(s32 arg0) {
    D_uvdbg_rom_00402FB4 = (f32) uvClkGetSec(0);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdbg_rom/__entrypoint_func_uvdbg_rom_400318.s")

void func_uvdbg_rom_00400490(void) {
    uvUnloadModule('FONT');
    uvUnloadModule('STRG');
    uvUnloadModule('AMGR');
    uvUnloadModule('STAT');
    uvUnloadModule('GMGR');
    uvUnloadModule('DGEO');
    uvUnloadModule('CONT');
    uvUnloadModule('FMTX');
    uvUnloadModule('CHAN');
    uvUnloadModule('CBCK');
}

extern f64 D_8002EDD0[];
extern s32 gSchedRingIdx;

f64 func_uvdbg_rom_00400520(void) {
    s32 temp_hi;

    temp_hi = (s32) (gSchedRingIdx + 1) % 5;
    return D_8002EDD0[(s32) (temp_hi + 1) % 5] - D_8002EDD0[temp_hi];
}

f64 func_uvdbg_rom_004005B8(void) {
    s32 new_var;
    s32 temp_hi;
    s32 j;
    s32 var_a1;
    s32 var_a2;
    s32 i;
    f64 var_fv1;
    new_var = gSchedRingIdx;
    for (i = ((s32) (new_var + 1)) % 5, var_a1 = 0, var_a2 = 0; i != new_var; i = (i + 1) % 5) {
        for (j = 0; j < D_8002EDB8[i]; j++) {
            struct Entry *t0 = &(D_8002E440 + i)->entry[j];
            if (!var_a1) {
                if (t0->unk8 == 0x2A) {
                    var_a1 = 1;
                    var_fv1 = t0->unk0;
                }
                continue;
            }
            if (var_a1) {
                if (t0->unk8 == 0x2B) {
                    var_a2 |= 1;
                }
                if (t0->unk8 == 0x30) {
                    var_a2 |= 2;
                }
            }
            if (var_a2 == 3) {
                return t0->unk0 - var_fv1;
            }
        }
    }

    return 0;
}

f64 func_uvdbg_rom_0040075C(void) {
    s32 new_var;
    s32 temp_hi;
    s32 j;
    s32 var_a1;
    s32 var_a2;
    s32 i;
    f64 var_fv1;
    new_var = gSchedRingIdx;
    for (i = ((s32) (new_var + 1)) % 5, var_a1 = 0, var_a2 = 0; i != new_var; i = (i + 1) % 5) {
        for (j = 0; j < D_8002EDB8[i]; j++) {
            struct Entry *t0 = &(D_8002E440 + i)->entry[j];
            if (!var_a1) {
                if (t0->unk8 == 0x29) {
                    var_a1 = 1;
                    var_fv1 = t0->unk0;
                }
                continue;
            }

            if (var_a1 && t0->unk8 == 0x2C) {
                var_a2 |= 1;
            }

            if (var_a2 == 1) {
                return t0->unk0 - var_fv1;
            }
        }
    }

    return 0;
}

extern UnkStruct_8002E440 D_8002DAE0[];
extern s32 D_8002EDA0[];

f64 func_uvdbg_rom_004008E4(void) {
    s32 new_var;
    s32 temp_hi;
    s32 j;
    s32 var_a1;
    s32 var_a2;
    s32 i;
    f64 var_fv1;

    new_var = gSchedRingIdx;
    i = ((s32) (new_var + 1)) % 5;
    var_fv1 = 0;
    var_a1 = 0;

    for (; i != new_var; i = (i + 1) % 5) {
        for (j = 0; j < D_8002EDA0[i]; j++) {
            struct Entry *t0 = &(D_8002DAE0 + i)->entry[j];
            if (!var_a1) {
                if (t0->unk8 == 0x29) {
                    var_a1 = 1;
                    var_fv1 = t0->unk0;
                }
                continue;
            }

            if (var_a1) {
                if (t0->unk8 == 0x2C) {
                    return t0->unk0 - var_fv1;
                }
            }
        }
    }

    return 0.0;
}

f64 func_uvdbg_rom_00400A2C(void) {
    s32 new_var;
    s32 temp_hi;
    s32 j;
    s32 var_a1;
    s32 var_a2;
    s32 i;
    f64 var_fv1;

    new_var = gSchedRingIdx;
    i = ((s32) (new_var + 1)) % 5;
    var_fv1 = 0;
    var_a1 = 0;

    for (; i != new_var; i = (i + 1) % 5) {
        for (j = 0; j < D_8002EDA0[i]; j++) {
            struct Entry *t0 = &(D_8002DAE0 + i)->entry[j];
            if (!var_a1) {
                if (t0->unk8 == 0x2A) {
                    var_a1 = 1;
                    var_fv1 = t0->unk0;
                }
                continue;
            }

            if (var_a1) {
                if (t0->unk8 == 0x2B) {
                    return t0->unk0 - var_fv1;
                }
            }
        }
    }

    return 0.0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdbg_rom/func_uvdbg_rom_00400B74.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdbg_rom/func_uvdbg_rom_00400D74.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdbg_rom/func_uvdbg_rom_00400E74.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdbg_rom/func_uvdbg_rom_004011BC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdbg_rom/func_uvdbg_rom_004011C4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdbg_rom/func_uvdbg_rom_004011D0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdbg_rom/func_uvdbg_rom_00401318.s")

void func_uvdbg_rom_004014DC(void) {

}

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdbg_rom/func_uvdbg_rom_004014E4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdbg_rom/func_uvdbg_rom_004017A0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdbg_rom/func_uvdbg_rom_004017A8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdbg_rom/func_uvdbg_rom_00401AFC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdbg_rom/func_uvdbg_rom_00401B90.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdbg_rom/func_uvdbg_rom_00401D20.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdbg_rom/func_uvdbg_rom_00401D94.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdbg_rom/func_uvdbg_rom_00401DE8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdbg_rom/func_uvdbg_rom_00402128.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdbg_rom/func_uvdbg_rom_00402490.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdbg_rom/func_uvdbg_rom_00402590.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdbg_rom/func_uvdbg_rom_004025B8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdbg_rom/func_uvdbg_rom_0040262C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdbg_rom/func_uvdbg_rom_004029D4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdbg_rom/func_uvdbg_rom_004029E0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdbg_rom/func_uvdbg_rom_00402A14.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdbg_rom/func_uvdbg_rom_00402CB8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdbg_rom/func_uvdbg_rom_00402D00.s")
