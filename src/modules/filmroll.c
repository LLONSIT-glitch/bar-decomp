// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "global_exports.h"

typedef struct UnkStruct_filmroll_004009C8_s {
    u8* unk0;
    u8* unk4;
} UnkStruct_filmroll_004009C8;

// .bss
s32 B_filmroll_004009C0[2]; // unreferenced padding
UnkStruct_filmroll_004009C8 D_filmroll_004009C8;
UnkStruct_004005C8 D_filmroll_004009D0;
UvMath_Exports D_filmroll_004009D8[10];
s32 D_filmroll_00400A78;
UnkStruct_004005C8 D_filmroll_00400A80;

void __entrypoint_func_filmroll_400000(Filmroll_Exports*);
void func_filmroll_00400060(void);
void func_filmroll_00400068(s32);
void func_filmroll_00400170(void);
void func_filmroll_0040035C(void);
void func_filmroll_00400588(UvMath_Exports*);
void func_filmroll_0040062C(void);
void func_filmroll_00400634(Unk_filmroll_00400634*);
void func_filmroll_00400720(void);

void __entrypoint_func_filmroll_400000(Filmroll_Exports* arg0) {
    uvUpdateFileAllocPtr(arg0);
    arg0->func_filmroll_00400060 = func_filmroll_00400060;
    arg0->func_filmroll_00400068 = func_filmroll_00400068;
    arg0->func_filmroll_00400170 = func_filmroll_00400170;
    arg0->func_filmroll_0040035C = func_filmroll_0040035C;
    arg0->func_filmroll_00400720 = func_filmroll_00400720;
}

void func_filmroll_00400060(void) {

}

void func_filmroll_00400068(s32 arg0) {
    s32 temp_t1;
    s32 v0;

    gUvGfxMgrExports->func_uvgfxmgr_rom_00402090();
    D_filmroll_004009C8.unk0 = gUvGfxMgrExports->func_uvgfxmgr_rom_00402074();
    D_filmroll_004009C8.unk4 = gUvGfxMgrExports->func_uvgfxmgr_rom_00402058();
    gUvGfxMgrExports->uvCopyFrameBuf(0);
    if (arg0 != 2) {
        if (((D_filmroll_004009C8.unk0 < D_filmroll_004009C8.unk4) != (arg0 == 1)) != 0) {
            gSndExports->func_snd_00401038();
            gUvGfxMgrExports->uvGfxBegin();
            gUvGfxMgrExports->uvGfxEnd();
            gUvGfxMgrExports->func_uvgfxmgr_rom_00402090();
            v0 = D_filmroll_004009C8.unk0;
            D_filmroll_004009C8.unk0 = D_filmroll_004009C8.unk4;
            D_filmroll_004009C8.unk4 = v0;
        }
    }
    func_80004B2C(1);
}

void func_filmroll_00400170(void) {
    u8* var_s0;
    s32 var_s2;
    s32 var_s5;

    var_s0 = D_filmroll_004009C8.unk0;
    var_s5 = 0;
    gUvGfxMgrExports->uvGfxEnd();
    gUvGfxMgrExports->func_uvgfxmgr_rom_00402090();
    if (var_s0 < D_filmroll_004009C8.unk4) {
        var_s2 = 1;
    } else {
        var_s2 = -1;
    }
    while (((var_s2 == -1) && (D_filmroll_004009C8.unk4 < var_s0)) || 
           ((var_s2 == 1) && (var_s0 < D_filmroll_004009C8.unk4))) {
        gSndExports->func_snd_00401038();
        gUvGfxMgrExports->uvGfxBegin();
        gUvGfxMgrExports->uvGfxEnd();
        osViSwapBuffer(var_s0);
        gUvGfxMgrExports->func_uvgfxmgr_rom_00402090();
        var_s0 += var_s2 * 0xF00;
        var_s5 = 1 - var_s5;
    }
    gSndExports->func_snd_00401038();
    gUvGfxMgrExports->uvGfxBegin();
    gUvGfxMgrExports->uvGfxEnd();
    osViSwapBuffer(D_filmroll_004009C8.unk4);
    gUvGfxMgrExports->func_uvgfxmgr_rom_00402090();
    gUvGfxMgrExports->uvCopyFrameBuf(1);
    func_80004B2C(0);
    gSndExports->func_snd_00401038();
    gUvGfxMgrExports->uvGfxBegin();
}

void func_filmroll_0040035C(void) {
    s32 var_s2;
    s32 fbIndex;
    u32 var_s0;

    var_s0 = D_filmroll_004009C8.unk0;
    fbIndex = 0;
    gUvGfxMgrExports->uvGfxEnd();
    gUvGfxMgrExports->func_uvgfxmgr_rom_00402090();
    if (var_s0 < (u32) D_filmroll_004009C8.unk4) {
        var_s2 = 1;
    } else {
        var_s2 = -1;
    }

    gSndExports->func_snd_00402504(&D_filmroll_004009D0);
    gSndExports->func_snd_00401800(&D_filmroll_004009D0, 0x59, 0x1F40, gSndExports->func_snd_004014B4() * 0.8f);
    while (((var_s2 == -1) && ((s32)D_filmroll_004009C8.unk4 < var_s0)) || 
           ((var_s2 == 1) && (var_s0 < (s32)D_filmroll_004009C8.unk4))) {
        gSndExports->func_snd_00401038();
        gUvGfxMgrExports->uvGfxBegin();
        gUvGfxMgrExports->uvGfxEnd();
        osViSwapBuffer((void* ) var_s0);
        gUvGfxMgrExports->func_uvgfxmgr_rom_00402090();
        var_s0 += var_s2 * 0x1180;
        if (fbIndex != 0) {
            osViBlack(FALSE);
        } else {
            osViBlack(TRUE);
        }
        fbIndex = 1 - fbIndex;
    }
    osViBlack(FALSE);
    gSndExports->func_snd_00401CDC(&D_filmroll_004009D0);
    gUvGfxMgrExports->uvCopyFrameBuf(fbIndex);
    gUvGfxMgrExports->uvGfxBegin();
}


void func_filmroll_00400588(UvMath_Exports* arg0) {
    f32 temp_ft4;

    D_filmroll_00400A78 += 1;
    arg0->unk0 = 1;
    arg0->uvSqrtf = (s32) (gUvMathExports->uvRandFLcg() * 319.0f);
    temp_ft4 = gUvMathExports->uvRandFLcg() * 239.0f;
    arg0->uvCosF = 0;
    arg0->uvSinF = (s32) temp_ft4;
}


void func_filmroll_0040062C(void) {

}

void func_filmroll_00400634(UvMath_Exports* arg0) {
    s32 temp_t0;
    s32 temp_t1;
    s32 i;
    s32 j;
    s16* v0;
    s16* v1;

    v0 = (s32) D_filmroll_004009C8.unk0;
    v1 = (s32) D_filmroll_004009C8.unk4;

    for (i = -arg0->uvCosF; i <= arg0->uvCosF; i++) {
        for (j = -arg0->uvCosF; j <= arg0->uvCosF; j++) {
            temp_t0 = arg0->uvSqrtf + i;
            temp_t1 = arg0->uvSinF + j;
            if ((temp_t0 >= 2) && (temp_t0 < 0x13E) && (temp_t1 >= 2) && (temp_t1 < 0xEE) && (SQ(arg0->uvCosF) >= (SQ(i) + SQ(j)))) {
                v1[((temp_t0 * 0x140) + temp_t1)] = v0[((temp_t0 * 0x140) + temp_t1)];
            }
        }
    }
}


void func_filmroll_00400720(void) {
    s32 i;
    s32 j;

    func_80004B2C(1);
    gUvGfxMgrExports->uvGfxEnd();
    gUvGfxMgrExports->func_uvgfxmgr_rom_00402090();
    gSndExports->func_snd_00402504(&D_filmroll_00400A80);
    gSndExports->func_snd_00401800(&D_filmroll_00400A80, 0x4F, 0x1F40, gSndExports->func_snd_004014B4() * 0.8f);
    D_filmroll_004009C8.unk0 = gUvGfxMgrExports->func_uvgfxmgr_rom_00402074();
    D_filmroll_004009C8.unk4 = gUvGfxMgrExports->func_uvgfxmgr_rom_00402058();
    D_filmroll_00400A78 = 0;
    for (i = 0; i < 10; i++) {
        D_filmroll_004009D8[i].unk0 = 0;
    }
    for (i = 0; i < 10; i++) {
        func_filmroll_00400588(D_filmroll_004009D8 + i);
    }

    for (j = 0; j < 180; j++) {
        for (i = 0; i < 10; i++) {
            if (D_filmroll_004009D8[i].unk0 != 0) {
                D_filmroll_004009D8[i].uvCosF += 1;
                func_filmroll_00400634(&D_filmroll_004009D8[i]);
                if (D_filmroll_004009D8[i].uvCosF >= 0xB) {
                    D_filmroll_004009D8[i].unk0 = 0;
                    D_filmroll_00400A78 -= 1;
                }
            } else if (D_filmroll_00400A78 < 0xA) {
                func_filmroll_00400588(D_filmroll_004009D8 + i);
            }
        }
        gSndExports->func_snd_00401038();
        gUvGfxMgrExports->uvGfxBegin();
        gUvGfxMgrExports->uvGfxEnd();
        gUvGfxMgrExports->func_uvgfxmgr_rom_00402090();
    } 
    gSndExports->func_snd_00401CDC(&D_filmroll_00400A80);
    gUvGfxMgrExports->uvCopyFrameBuf(0);
    func_80004B2C(0);
    gUvGfxMgrExports->uvGfxBegin();
}

// .data
s32 D_filmroll_004009B0[] = {0x00140000, __entrypoint_func_filmroll_400000, 0, 0};
