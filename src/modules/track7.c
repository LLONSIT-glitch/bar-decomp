// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"

typedef struct UnkStruct_80025CB0_s {
    char pad[0x24];
    void (*unk24)(void);
} UnkStruct_80025CB0;

void* func_80003520(s32, s32);                        /* extern */
void func_80003760(s32);                                 /* extern */
extern s32 D_004000B0;
extern void func_track7_00400094(void);
extern void func_track7_0040009C(void);
extern UnkStruct_80025CF0 gGameSettings[];
    
void __entrypoint_func_track7_400000(Track7_Exports *arg0) {
    uvSetFileDirOvlPtr(arg0);
    arg0->func_track7_00400094 = &func_track7_00400094;
    arg0->func_track7_0040009C = &func_track7_0040009C;
    #line 1
    gGameSettings->unkF0 = &D_004000B0;
    D_80025CB0 = func_80003520('tdta', arg0);
    if (gCurrentGameState != 0xA) {
        D_80025CB0->unk24();
    }
    func_80003760('tdta');
    D_80025CB0 = NULL;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/track7/func_track7_00400094.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/track7/func_track7_0040009C.s")
