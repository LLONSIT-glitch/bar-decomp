// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"

extern s32 D_track7_004000B0;
extern void func_track7_00400094(void);
extern void func_track7_0040009C(void);
extern UnkStruct_80025CF0 gGameSettings[];
extern s32 D_80025DE0;
    
void __entrypoint_func_track7_400000(Track7_Exports *exports) {
    uvSetFileDirOvlPtr(exports);
    exports->func_track7_00400094 = &func_track7_00400094;
    exports->func_track7_0040009C = &func_track7_0040009C;
    #line 1
    D_80025DE0 = &D_track7_004000B0;
    D_80025CB0 = uvLoadModule('tdta');
    if (gCurrentGameState != 0xA) {
        D_80025CB0->unk24();
    }
    uvUnloadModule('tdta');
    D_80025CB0 = NULL;
}

void func_track7_00400094(void) {
}

void func_track7_0040009C(void) {
}
