#include "common.h"

typedef struct UnkStruct_8002DA60_s {
    /* 0x0 */ struct UnkStruct_8002DA60_s* unk0;                             /* inferred */
    /* 0x4 */ s32 unk4;
} UnkStruct_8002DA60;                               /* size = 0x8 */

void func_80002A88(void);                                  /* extern */
void func_80002AEC(s32);                                /* extern */
void func_80002B2C(s32);                                /* extern */
extern u8 D_8001F7D0;
extern s32 D_8002F7D8;
extern UnkStruct_8002DA60* D_8002DA60;
extern UnkStruct_8002DA60 D_80033770[];

extern s32 D_8001F7A0;
extern s32 D_8001F7A4;


void func_80002A30(void) {
    func_80002A88();
    if ((D_8002F7D8 != 0) || (D_8001F7D0 != 0)) {
        func_80002B2C(D_8001F7D0);
        func_80002AEC(D_8001F7D0);
    }
}

void func_80002A88(void) {
    D_8002DA60 = D_80033770;
    D_8002DA60->unk0 = NULL;
    D_8002DA60->unk4 = ((u32) 0x80400000) - ((u32) D_80033770);
    D_8001F7A0 = 1;
    D_8001F7A4 = 1;
}

void func_80002AC8(void) {
    UnkStruct_8002DA60 *var_v0;

    var_v0 = D_8002DA60;
    while (var_v0 != NULL) {
        var_v0 = var_v0->unk0;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80002AEC.s")

void func_80002B2C(s32 arg0) {
    UnkStruct_8002DA60* var_s0;

    for (var_s0 = D_8002DA60; var_s0 != NULL; var_s0 = var_s0->unk0) {
        uvMemSet(var_s0 + 1, arg0 & 0xFF & 0xFF, var_s0->unk4 - 8);
    }
}

void func_80002B80(UnkStruct_8002DA60* arg0) {
    UnkStruct_8002DA60* var_a2;
    UnkStruct_8002DA60* var_v0;
    s32 temp_v1;

    var_v0 = NULL;
    temp_v1 = arg0->unk4;
    if (D_8002DA60 == NULL) {
        D_8002DA60 = arg0;
        D_8001F7A0 += 1;
        return;
    }

    var_a2 = D_8002DA60;
    while (var_a2 != NULL && var_a2 < arg0) {
        var_v0 = var_a2;
        var_a2 = var_a2->unk0;
    }
    
    if (var_v0 != NULL) {
        if ((u32)arg0 == ( (u32) var_v0 + (u32)var_v0->unk4)) {
            if ((u32)var_a2 == ((u32)arg0 + (u32)temp_v1)) {
                var_v0->unk4 += temp_v1;
                var_v0->unk4 = var_v0->unk4 + var_a2->unk4;
                var_v0->unk0 = var_a2->unk0;
                D_8001F7A0 -= 1;
                return;
            }
        }
    }
    if (var_v0 != NULL) {
        if ((u32)arg0 == ((u32)var_v0 + (u32)var_v0->unk4)) {
            var_v0->unk4 += temp_v1;
            return;
        }
    }
    if ((u32)var_a2 == ((u32)arg0 + temp_v1)) {
        arg0->unk0 = var_a2->unk0;
        
        arg0->unk4 = (0, temp_v1) + var_a2->unk4; // FAKE
        if (var_v0 != NULL) {
            var_v0->unk0 = arg0;
            return;
        }
        D_8002DA60 = arg0;
        return;
    }
    arg0->unk0 = var_a2;
    if (var_v0 != NULL) {
        var_v0->unk0 = arg0;
    } else {
        D_8002DA60 = arg0;
    }
    D_8001F7A0++;
    if ((u32) D_8001F7A4 < (u32) D_8001F7A0) {
        D_8001F7A4 = D_8001F7A0;
    }
}


#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80002CD0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80002EAC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80002F4C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80002F6C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_800031A8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80003240.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80003294.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_800032C4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_800032E4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80003310.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80003494.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_800034E0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80003520.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_8000355C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80003584.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80003760.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80003790.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80003A14.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80003AF0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80003B64.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80003B80.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80003C1C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80003CEC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80003E0C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80003E94.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80003F04.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80004014.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80004088.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80004274.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80004284.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80004298.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_800042DC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_800042E4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_800043E4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_800046EC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_8000481C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_8000487C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_800048C8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_800048D4.s")

void func_800048DC(void) {
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_800048E4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80004958.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80004A78.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80004A84.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80004B1C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80004B2C.s")
