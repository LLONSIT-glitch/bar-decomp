#include "ultra64.h"

typedef struct UnkStruct_00400C14_s {
    /* 0x00 */ f32 unk0;
               f32 unk4;
    /* 0x08 */ u8 unk8;                             /* inferred */
    /* 0x09 */ u8 unk9;                             /* inferred */
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 unkB;                             /* inferred */
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s16 unk10;
} UnkStruct_00400C14;                               /* size = 0x14 */

typedef struct UnkStruct_00400C04_s {
    s32 pad0;
    void* (*unk4)(s32, s32, s32, s32);
} UnkStruct_00400C04;

typedef struct UnkStruct_00400C00_s {
    s32 pad0;
    char pad4[0xC];
    void* (*unk10)(s32, s32, s32, s32);
    char pad14[0x4];
    void* (*unk18)(s32, s32, u8);
} UnkStruct_00400C00;

extern UnkStruct_00400C14* D_00400C14;
extern UnkStruct_00400C00* D_00400C00;
extern UnkStruct_00400C04* D_00400C04;
extern s32 D_00400C08;
extern s32 D_00400C10;
extern s32 func_uvsort_rom_00400750;
extern s32 D_00400C18;
extern s32 D_00400C1C;
void func_uvsort_rom_004006F8(s32 arg0);
extern s32 D_00400BF0;

void _uvMemFree(s32);                                  /* extern */
void func_80003760(s32 tag);                                 /* extern */


#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvsort_rom/__entrypoint_func_uvsort_rom_400000.s")

void func_uvsort_rom_00400238(s32 arg0) {

}

void func_uvsort_rom_00400240(void) {
    s32 var_s0;
    s32 var_s1;

    for (var_s0 = 0; var_s0 < D_00400C10; var_s0++) {
        _uvMemFree(D_00400C14[var_s0].unkC);
    }
    _uvMemFree(D_00400C14);
    func_80003760('CHAN');
    D_00400C04 = 0;
    func_80003760('CBCK');
    D_00400C00 = 0;
    func_80003760('GMGR');
    D_00400C08 = 0;
}

s32 func_uvsort_rom_00400308(u8 arg0) {
    s32 i;
    u8 ret;
    u8 temp_v1;
    s32 j;
    s32 sp50;

    ret = 0xFF;
    for (i = 0; i < D_00400C10; i++) {
        if (D_00400C14[i].unk9 == 0) {
            D_00400C14[i].unk9 = 1;
            D_00400C14[i].unk8 = arg0;
            D_00400C14[i].unk0 = 0.0f;
            D_00400C14[i].unk4 = 0.0f;
            D_00400C14[i].unkA = 0;
            ret = i;
            break;
        }

        if (arg0 == D_00400C14[i].unk8) {
            return -1;
        }
    }
 
    if (ret == 0xFF) {
        return -1;
    }
    for (i = 0; i < D_00400C10; i++) {
        temp_v1 = D_00400C14[i].unkB;
        if ((temp_v1 == 0xFF) || (arg0 < D_00400C14[temp_v1].unk8)) {
            for (j = D_00400C10 - 2; j >= i; j--) {
                D_00400C14[j + 1].unkB = D_00400C14[j].unkB;
            }
            D_00400C14[i].unkB = ret;
            break;
        }
    }

    for (i = 0; i < D_00400C1C; i++) {
        if ((D_00400C18 << i) & 1) {
            D_00400C04->unk4(i, 6, &sp50, 0);
            if (D_00400C00->unk18(sp50, &func_uvsort_rom_00400750, arg0) != 0) {
                continue;
            } 
            D_00400C00->unk10(sp50, &func_uvsort_rom_00400750, 0, arg0);
        }
    }

    return ret;
}

void func_uvsort_rom_00400594(s32 arg0) {

}

void func_uvsort_rom_0040059C(s32 arg0) {
    s32 sp44;
    s32 var_s0;
    UnkStruct_00400C14* temp_v0;

    D_00400C04->unk4(arg0, 6, (s32) &sp44, 0);
    D_00400C00->unk10(sp44, (s32) &func_uvsort_rom_004006F8, 0, 1);
    for (var_s0 = 0; var_s0 < D_00400C10; var_s0++) {
        if (D_00400C14[var_s0].unk9 != 0) {
            if (D_00400C00->unk18(sp44, (s32) &func_uvsort_rom_00400750, D_00400C14[var_s0].unk8) != NULL) {
                continue;
            } 
            D_00400C00->unk10(sp44, (s32) &func_uvsort_rom_00400750, 0, D_00400C14[var_s0].unk8);
        }
    }
    D_00400C18 |= 1 << arg0;
}

void func_uvsort_rom_004006F8(s32 arg0) {
    s32 i;

    D_00400BF0 = 0;
    for (i = 0; i < D_00400C10; i++) {
        D_00400C14[i].unk10 = 0;
    }
}


#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvsort_rom/func_uvsort_rom_00400750.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvsort_rom/func_uvsort_rom_00400834.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvsort_rom/func_uvsort_rom_00400898.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvsort_rom/func_uvsort_rom_00400B24.s")

