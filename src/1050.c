// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"


s32 func_800015D4(s32, s32);                         
s32 uvGetModuleFileId(s32);                              
void uvUnloadModule(s32);                                
void _uvScInitClientList(void);                                 
void uvSysInit(void);                                 

#pragma GLOBAL_ASM("asm/us/nonmatchings/1050/func_80000450.s")

#ifdef NEEDS_RODATA
void uvSetGameState(s32 gameStateId) {
    s32 temp_v0;
    s32 var_s0;
    s32 pad;
    f32 temp_fs0;

    if (D_80025C08 != NULL) {
        D_80025C08->unk74();
        if (gCurrentGameState != -1) {
            D_8002D1A4->unkC(gCurrentGameState);
        }
        temp_v0 = func_800015D4('UVMO', uvGetModuleFileId('MIDI'));
        for (var_s0 = 0; var_s0 < temp_v0; var_s0++) {
            uvUnloadModule('MIDI');
        }
            
        temp_v0 = func_800015D4('UVMO', uvGetModuleFileId('EMIT'));
        for (var_s0 = 0; var_s0 < temp_v0; var_s0++) {
            uvUnloadModule('EMIT');
        }
        
        temp_v0 = func_800015D4('UVMO', uvGetModuleFileId('AMGR'));
        var_s0 = 0;
        for (var_s0 = 0; var_s0 < temp_v0; var_s0++) {
            uvUnloadModule('AMGR');
        }
        D_80025BE8->unk6C();
        _uvScInitClientList();

        temp_fs0 = uvClkGetSec(0x6A);
        
        while (temp_fs0 + 0.2f < uvClkGetSec(0x6A)) {
        }

    }
    gCurrentGameState = gameStateId;
    gGameStateFlag = -1;
    uvSysInit();
    D_80025C98 = 0;
    D_80025C9C = 0;
    D_80025C94 = 0;
    D_80025CAC = 0;
    D_80025CCC = 0;
    D_80025CB0 = 0;
    D_80025CD4 = 0;
    D_80025CD8 = 0;
    D_80025CDC = 0;
    D_80025CE0 = 0;
    D_80025CE4 = 0;
    D_80025CB4 = 0;
    D_80025CE8 = 0;
    D_8002D1A4 = uvLoadModule('game');
    D_8002D1A4->unk8(gameStateId);
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/1050/uvSetGameState.s")
#endif

// Displays error message and loops forever when no controllers are connected
void uvShowNoController(void) {
    s32 i;
    s32 line;
    s32 s4;
    s32 s3;
    func_800019B8('UVFT', 1);
    while (1) {
        D_80025C00->unk4(5); // font ID
        D_80025C00->unkC(0, 0x64, 0xC8, 0xFF); // RGBA color
        D_80025C08->unk4();
        D_80025C08->unk58(0, 0x13F, 0, 0xEF);
        D_80025C08->unk50(0, 0, 0);

        for (line = 0; line < 4; line++) {
            // clang-format off
            D_80025C00->unk24(0xA0 - (D_80025C00->unk18(gNoControllerStrings[line]) / 2), 150 - line * 20,
                              gNoControllerStrings[line]);
            // clang-format on
        }

        D_80025C00->unk28();
        D_80025C08->unk20();
    }
}
