#include "common.h"

s32 func_80001724(s32, s32);                          
s32 func_80003494(s32); 
s32 func_8000355C(s32);                             
void func_80001A68(s32, s32);
s32 func_800019B8(s32, s32);                            
s16 func_80001654(s32);                               
s32 func_800016A4(s32, s32);                          

extern s32* D_8002DA70;
extern s32* D_8002DA74;
extern s16 D_8002DA78;

typedef struct {
    s32 unk0;
    void (*unk4)(void*);
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
} Unk80003584_SP48;

void func_80003310(void) {
    s32 i;
    s32 v0_2;
    s32 temp_v0;
    u32 sp70;
    Unk80003584_SP48 sp4C;

    D_8002DA78 = func_80001654('UVMO');
    D_8002DA70 = _uvMemAllocAlign8(D_8002DA78 * 4);
    D_8002DA74 = _uvMemAllocAlign8(D_8002DA78 * 4);
    for (i = 0; i < D_8002DA78; i++) {
        temp_v0 = func_800016A4('UVMO', i);
        if (temp_v0 != 0) {
            v0_2 = uvFileReadHeader(temp_v0);
            func_800025C8(v0_2, &sp70, (void** ) &temp_v0, 'COMM', 0);
            _uvMediaCopy(&sp4C, (void* ) temp_v0, sp70);
            uvFileFree(v0_2);
            D_8002DA70[i] = sp4C.unk1C;
            D_8002DA74[i] = sp4C.unk0;
        } else {
            D_8002DA70[i] = 0;
            D_8002DA74[i] = 0;
        }
    }
}

s32 func_80003494(s32 arg0) {
    s32 var_v1;
    s32* var_a1;

    for (var_v1 = 0; var_v1 < D_8002DA78; var_v1++) {
        if (arg0 == D_8002DA70[var_v1]) {
            return var_v1;
        }
    }

    return -1;
}

s32 func_800034E0(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_80003494(arg0);
    if (temp_v0 == -1) {
        return 0;
    }
    return func_80001724('UVMO', temp_v0);
}


s32 func_80003520(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_80003494(arg0);
    if (temp_v0 == -1) {
        return 0;
    }
    return func_8000355C(temp_v0);
}

s32 func_8000355C(s32 arg0) {
    func_800019B8('UVMO', arg0);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/3F10/func_80003584.s")

void func_80003760(s32 tag) {
    func_80001A68('UVMO', func_80003494(tag));
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/3F10/func_80003790.s")

s32 func_80003A14(u32 arg0, s32* arg1) {
    s32 i;
    s32 var_s4;
    u32 temp_v0;
    u32 var_s1;

    var_s1 = 0;
    var_s4 = -1;
    for (i = 0; i < func_80001654('UVMO'); i++) {
        temp_v0 = func_80001724('UVMO', i);
        if ((temp_v0 < arg0) && (var_s1 < temp_v0)) {
            var_s4 = i;
            var_s1 = temp_v0;
        }
    }
    if (arg1 != NULL) {
        *arg1 = var_s4;
    }
    if (var_s4 == -1) {
        return 0;
    }
    return D_8002DA70[var_s4];
}

