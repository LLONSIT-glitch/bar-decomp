// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
typedef struct UnkStruct_80025C14_s {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 (*unk4)(void*);
    /* 0x08 */ char pad8[8];                        /* maybe part of unk4[3]? */
    /* 0x10 */ void (*unk10)(s32);                     /* inferred */
    /* 0x14 */ char pad14[8];                       /* maybe part of unk10[3]? */
    /* 0x1C */ void (*unk1C)(s32, ...);
} UnkStruct_80025C14;                               /* size = 0x20 */

typedef struct UnkStruct_80025C74_s {
    char pad0[4];
    s32 unk4;
    char pad8[0x8];
    void (*unk10)(s32);
    char pad[0x8];
    void (*unk1C)(s32);
} UnkStruct_80025C74;

typedef struct UnkStruct_80025C88_s {
    s32 pad0;
    void (*unk4)(s32, s32);
} UnkStruct_80025C88;

typedef struct UnkStruct_80025C2C_s {
    /* 0x0 */ char pad0[8];
    /* 0x8 */ f32 (*unk8)(f32);                     /* inferred */
} UnkStruct_80025C2C;      

typedef struct UnkStruct_80025C44_s {
    /* 0x00 */ char pad0[0xC];
    /* 0x0C */ void (*unkC)(s32);                        /* inferred */
    /* 0x10 */ void (*unk10)(s32);                       /* inferred */
    /* 0x14 */ char pad14[0x3C];                    /* maybe part of unk10[0x10]? */
    /* 0x50 */ void (*unk50)(void);                        /* inferred */
    /* 0x50 */ void (*unk54)(void);                        /* inferred */
} UnkStruct_80025C44;                               /* size = 0x54 */

typedef struct LogoModule_Exports_s {
    void* func_logo_00400174;
    void* func_logo_0040017C;
    void* func_logo_00400184;
} LogoModule_Exports;

extern UnkStruct_80025C2C* D_80025C2C;
extern UnkStruct_80025C44* D_80025C44;

extern UnkStruct_80025C08* D_80025C08;
extern UnkStruct_80025C14* D_80025C14;
extern UnkStruct_80025C74* D_80025C74;
extern UnkStruct_80025C88* D_80025C88;

void __entrypoint_func_logo_400000(LogoModule_Exports* arg0) ;
//void uvSetFileDirOvlPtr(void*);
extern void func_logo_00400174(void);
extern void func_logo_0040017C(void);
extern void func_logo_00400184(void);

extern s32 D_004002E0[2]; //padding?
extern s32 D_004002E8[2];
extern s32 D_004002D0[];

void __entrypoint_func_logo_400000(LogoModule_Exports* exports) {
    uvSetFileDirOvlPtr(exports);

    exports->func_logo_00400174 = func_logo_00400174;
    exports->func_logo_0040017C = func_logo_0040017C;
    exports->func_logo_00400184 = func_logo_00400184;

    D_004002E8[0] = D_80025C14->unk4(exports);
    D_004002E8[1] = 0;

    func_800019B8('UVBT', 0x28);

    D_80025C14->unk1C(
        D_004002E8[0], 9, 0x28, 2,
        0, 0, 3, 1,
        7, 0, 0, 0,
        0xFF, 0
    );

    D_80025C08->unk58(
        0,
        D_80025C08->unk88(),
        0,
        D_80025C08->unk84()
    );

    D_80025C74->unk10(0);
    D_80025C74->unk1C(D_80025C74->unk4);

    D_80025C88->unk4(0, 0);
}

void func_logo_00400174(void) {

}

void func_logo_0040017C(void) {

}

void func_logo_00400184(void) {
    s32 sp28;
    s32 var_a2;

    if (D_004002E8[1] < 0x5A) {
        var_a2 = (s32) ( D_80025C2C->unk8((++D_004002E8[1] * 1.5707963f) / 90.0f) * (0,255.0f));
    } else {
        var_a2 = 0xFF;
    }
    D_80025C44->unk50();
    D_80025C44->unkC(0x04800000);
    D_80025C44->unk10(0x600000);
    D_80025C14->unk1C(D_004002E8[0], 7, var_a2, var_a2, var_a2, 0xFF, 0);
    D_80025C14->unk10(D_004002E8[0]);
    D_80025C44->unk54();
}
