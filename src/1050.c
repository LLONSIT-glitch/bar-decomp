#include "common.h"

typedef struct UnkStruct_80025C00_s {
    s32 pad0;
    void (*unk4)(s32);
    char pad[0x4];
    void (*unkC)(s32, s32, s32, s32);
    char pad10[0x8];
    s32 (*unk18)(s32);
    char pad1C[0x8];
    void (*unk24)(s32, s32, s32);
    void (*unk28)(void);

} UnkStruct_80025C00;

typedef struct UnkStruct_80025C08_s {
    s32 pad0;
    void (*unk4)(void);
    char pad8[0x18];
    void (*unk20)(void);
    char padC[0x2C];
    void (*unk50)(s32, s32, s32);
    char pad54[0x4];
    void (*unk58)(s32, s32, s32, s32);
    char pad5C[0x18];
    void (*unk74)();
} UnkStruct_80025C08;

typedef struct UnkStruct_80025BE8_s {
    char pad[0x6C];
    void (*unk6C)(void);
} UnkStruct_80025BE8;

typedef struct UnkStruct_8002D1A4_s {
    char pad[0x8];
    void (*unk8)(s32);
    void (*unkC)(s32);
    
} UnkStruct_8002D1A4;

extern f32 D_80021000;
extern s32 D_80025C94;
extern s32 D_80025C98;
extern s32 D_80025C9C;
extern s32 D_80025CAC;
extern s32 D_80025CB0;
extern s32 D_80025CB4;
extern s32 D_80025CCC;
extern s32 D_80025CD4;
extern s32 D_80025CD8;
extern s32 D_80025CDC;
extern s32 D_80025CE0;
extern s32 D_80025CE4;
extern s32 D_80025CE8;
extern s32 D_80025CF8;
extern s32 D_80025D94;
extern UnkStruct_8002D1A4* D_8002D1A4;
extern UnkStruct_80025BE8* D_80025BE8;
extern s32 D_8001F634[];
extern UnkStruct_80025C00 *D_80025C00;
extern UnkStruct_80025C08 *D_80025C08;
extern f32 D_80021000;

void func_800019B8(s32, s32); /* extern */
s32 func_800015D4(s32, s32);                          /* extern */
s32 func_80003494(s32);                               /* extern */
void* func_80003520(s32);                             /* extern */
void func_80003760(s32);                                 /* extern */
void func_80004274(void);                                  /* extern */
void func_80004B40(void);                                  /* extern */

#pragma GLOBAL_ASM("asm/us/nonmatchings/1050/func_80000450.s")

#ifdef NEEDS_RODATA
void func_80000814(s32 arg0) {
    s32 temp_v0;
    s32 var_s0;
    s32 pad;
    f32 temp_fs0;

    if (D_80025C08 != NULL) {
        D_80025C08->unk74();
        if (D_80025D94 != -1) {
            D_8002D1A4->unkC(D_80025D94);
        }
        temp_v0 = func_800015D4('UVMO', func_80003494('MIDI'));
        for (var_s0 = 0; var_s0 < temp_v0; var_s0++) {
            func_80003760('MIDI');
        }
            
        temp_v0 = func_800015D4('UVMO', func_80003494('EMIT'));
        for (var_s0 = 0; var_s0 < temp_v0; var_s0++) {
            func_80003760('EMIT');
        }
        
        temp_v0 = func_800015D4('UVMO', func_80003494('AMGR'));
        var_s0 = 0;
        for (var_s0 = 0; var_s0 < temp_v0; var_s0++) {
            func_80003760('AMGR');
        }
        D_80025BE8->unk6C();
        func_80004274();

        temp_fs0 = uvClkGetSec(0x6A);
        
        while (temp_fs0 + 0.2f < uvClkGetSec(0x6A)) {
        }

    }
    D_80025D94 = arg0;
    D_80025CF8 = -1;
    func_80004B40();
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
    D_8002D1A4 = func_80003520('game');
    D_8002D1A4->unk8(arg0);
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/1050/func_80000814.s")
#endif

void func_80000A6C(void) {
    s32 i;
    s32 j;
    s32 s4;
    s32 s3;
    func_800019B8('UVFT', 1);
    while (1) {
        D_80025C00->unk4(5);
        D_80025C00->unkC(0, 0x64, 0xC8, 0xFF);
        D_80025C08->unk4();
        D_80025C08->unk58(0, 0x13F, 0, 0xEF);
        D_80025C08->unk50(0, 0, 0);

        for (j = 0; j < 4; j++) {
            D_80025C00->unk24(0xA0 - (D_80025C00->unk18(D_8001F634[j]) / 2), 150 - j * 20,
                              D_8001F634[j]);
        }

        D_80025C00->unk28();
        D_80025C08->unk20();
    }
}
