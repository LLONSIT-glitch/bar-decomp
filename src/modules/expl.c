// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "global_exports.h"

typedef struct {
    s32 unk0;
    u8 pad4[0x14 - 0x4];
} Unk_004004B8;

extern Unk_004004B8 D_expl_004004B8[20];
extern s32 D_expl_00400648;
extern void func_expl_004000AC(void);
extern void func_expl_0040011C(void);
extern void func_expl_004002D0(void);
extern s32 func_expl_00400370(void);

void __entrypoint_func_expl_400000(Expl_Exports* exports) {
    s32 i;

    uvUpdateFileAllocPtr(exports);
    // TODO: i don't know what's going on with the reordering
    exports->func_expl_004000AC = func_expl_004000AC;
    exports->func_expl_0040011C = func_expl_0040011C;
    exports->func_expl_004002D0 = func_expl_004002D0; 
    exports->func_expl_00400370 = func_expl_00400370;
    #line 27
    uvLoadFile('UVPX', 3);

    for(i = 0; i < ARRAY_COUNT(D_expl_004004B8); i++) {
        D_expl_004004B8[i].unk0 = -1;
    }

    gSndExports->func_snd_00402504(&D_expl_00400648);
}

void func_expl_004000AC(void) {
    gSndExports->func_snd_00401CDC(&D_expl_00400648);
}

void func_expl_004000E0(void) {
    gUvGfxMgrExports->uvGfxSetPrimColorF(1.0f, 1.0f, 1.0f, 1.0f);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/expl/func_expl_0040011C.s")

void func_expl_004002D0(void) {
    s32 pad;
    s32 i;
    s32 sp3C;

    for (i = 0; i < ARRAY_COUNT(D_expl_004004B8); i++) {
        if (D_expl_004004B8[i].unk0 < 0) {
            continue;
        }
        gUvPfxExports->func_uvpfx_rom_004012CC(D_expl_004004B8[i].unk0, 0x1011, &sp3C, 0);
        if (sp3C == 0) {
            D_expl_004004B8[i].unk0 = -1;
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/expl/func_expl_00400370.s")
