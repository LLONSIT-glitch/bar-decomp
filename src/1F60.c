#include "common.h"

typedef struct UnkStruct_8002D9B4_inner_s {
    s32 pad0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} UnkStruct_8002D9B4_inner;

typedef struct UnkStruct_8002D9B4_s {
    s32 pad0;
    u16 unk4;
    UnkStruct_8002D9B4_inner *unk8;
} UnkStruct_8002D9B4;

typedef struct UnkStruct_8002D9BC_s {
    u16 unk0;
    u16 *unk4;
    u16 *unk8;
} UnkStruct_8002D9BC;

typedef struct UnkStruct_80001BC0_s  {
    void (*unk0)(void);
} UnkStruct_80001BC0;

typedef struct UnkStruct_80003520_s {
    s32 unk0;
    void *(*unk4)(s32);
    void *(*unk8)(UnkStruct_80001BC0*);
} UnkStruct_80003520;

void func_800032E4(UnkStruct_80001BC0* arg1);                          /* extern */
extern UnkStruct_8002D9B4 *D_8002D9B4;
extern UnkStruct_8002D9BC *D_8002D9BC;
extern UnkStruct_8002D9B4_inner *D_8002D9A4;
extern u16 D_8002D9A0;
extern u8 D_FORM0[];
extern u8 D_FORM1[];
extern u8 UVTS_10_ROM_END[];


s32 func_800019B8(s32, s32);            /* extern */
s32 func_80001EAC(s32);                    /* extern */
UnkStruct_80003520 *func_80003520(s32); /* extern */
s32 uvLoadModuleCode(s32);                 /* extern */
void func_80003760(s32);                /* extern */
UnkStruct_8002D9BC *func_80001724(s32, s32);          /* extern */
s32 func_80001FC4(s32 arg0, s32 arg1);
void func_80001BC0(s32 arg0, UnkStruct_80001BC0* arg1);
void func_80001A68(s32 arg0, s32 arg1);

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/formLoader.s")

u16 func_800015D4(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_80001EAC(arg0);
    if (temp_v0 == -1) {
        return 0U;
    }
    if (func_80001FC4(temp_v0, arg1) == -1) {
        return 0U;
    }
    return D_8002D9B4[temp_v0].unk8[arg1].unk8;
}

u16 func_80001654(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_80001EAC(arg0);
    if (temp_v0 == -1) {
        return 0U;
    }
    return D_8002D9B4[temp_v0].unk4;
}

s32 func_800016A4(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_80001EAC(arg0);
    if (temp_v0 == -1) {
        return 0;
    }
    if (func_80001FC4(temp_v0, arg1) == -1) {
        return 0;
    }
    return D_8002D9B4[temp_v0].unk8[arg1].pad0;
}

UnkStruct_8002D9BC *func_80001724(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_80001EAC(arg0);
    if (temp_v0 == -1) {
        return NULL;
    }
    if (func_80001FC4(temp_v0, arg1) == -1) {
        return NULL;
    }
    return (UnkStruct_8002D9BC *) D_8002D9B4[temp_v0].unk8[arg1].unk4;
}

s32 func_800017A4(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_80001EAC(arg0);
    if (temp_v0 == -1) {
        return 0;
    }
    if (func_80001FC4(temp_v0, arg1) == -1) {
        return 0;
    }
    return D_8002D9B4[temp_v0].unk8[arg1].unkC;
}

s32 uvLoader(s32 tag, s32 arg1) {
    UnkStruct_8002D9B4_inner *temp_s0;
    s32 temp_v0;
    s32 i;

    temp_v0 = func_80001EAC(tag);
    if (temp_v0 == -1) {
        return 0;
    }
    temp_s0 = &D_8002D9B4[temp_v0].unk8[arg1];
    if (temp_s0->pad0 == 0) {
        temp_s0->unk4 = 0;
        return 0;
    }
    if ((tag == 'UVTX') && (D_8002D9BC != NULL)) {
        for (i = 0; i < D_8002D9BC->unk0; i++) {
            if (arg1 == D_8002D9BC->unk4[i]) {
                temp_v0 = func_800019B8('UVTX', D_8002D9BC->unk8[i]);
                temp_s0->unk4 = temp_v0;
                return temp_v0;
            }
        }
    }
    if (tag == 'UVMO') {
        D_8002D9A4 = temp_s0;
        temp_s0->unk4 = uvLoadModuleCode(temp_s0->pad0);
        D_8002D9A4 = NULL;
    } else if (D_8002D9B4[temp_v0].pad0 != 0xFFFF) {
        temp_s0->unk4 = func_80003520(D_8002D9B4[temp_v0].pad0)->unk4(temp_s0->pad0);
        func_80003760(D_8002D9B4[temp_v0].pad0);
    } else {
        temp_s0->unk4 = temp_s0->pad0;
    }
    return temp_s0->unk4;
}

void func_800019A8(s32 arg0) {
    D_8002D9A4->unk4 = arg0;
}

s32 func_800019B8(s32 arg0, s32 arg1) {
    UnkStruct_8002D9B4_inner* temp_v1;
    s32 ret;

    ret = func_80001EAC(arg0);
    if (ret == -1) {
        return 0;
    }
    if (func_80001FC4(ret, arg1) == -1) {
        return 0;
    }
    temp_v1 = &D_8002D9B4[ret].unk8[arg1];
    temp_v1->unk8++;
    if (temp_v1->unk8 == 1) {
        temp_v1->unk4 = uvLoader(arg0, (s32) arg1);
    }
    return temp_v1->unk4;
}

void func_80001A68(s32 arg0, s32 arg1) {
    UnkStruct_8002D9B4_inner *ptr;
    s32 temp_v0;
    

    temp_v0 = func_80001EAC(arg0);
    if (temp_v0 == -1) {
        return;
    }

    if (func_80001FC4(temp_v0, arg1) == -1) {
        return;
    }

    ptr = &D_8002D9B4[temp_v0].unk8[arg1];
    if (ptr->unk8 == 0) {
        return;
    }

    if (--D_8002D9B4[temp_v0].unk8[arg1].unk8) {
        return;
    }

    if ((arg0 == 'UVTX')) {
        if (D_8002D9BC != NULL) {
            s32 i;
            for (i = 0; i < D_8002D9BC->unk0; i++) {
                if (arg1 == D_8002D9BC->unk4[i]) {
                    func_80001A68('UVTX', D_8002D9BC->unk8[i]);
                    ptr->unk4 = 0;
                    ptr->unkC = 0;
                    return;
                }
            }
        }
    }

    arg1 = ptr->unk4;
    if (arg1 != 0) {
        func_80001BC0(arg0, arg1);
    }
    ptr->unk4 = 0;
    ptr->unkC = 0;
}

void func_80001BC0(s32 arg0, UnkStruct_80001BC0* arg1) {
    s32 temp_v0;
    

    temp_v0 = func_80001EAC(arg0);
    if (temp_v0 != -1) {
        if (arg0 == 'UVMO') {
            arg1->unk0();
            func_800032E4(arg1);
            return;
        }
        func_80003520(D_8002D9B4[temp_v0].pad0)->unk8(arg1);
        func_80003760(D_8002D9B4[temp_v0].pad0);
    }
}

void func_80001C6C(void) {
    s32 i;
    s32 j;
    
    for (i = 0; i < D_8002D9A0; i++) {
        for (j = 0; j < D_8002D9B4[i].unk4; j++) {
            D_8002D9B4[i].unk8[j].unk8 = 0;
        }
    }
}

u32 uvFileReadBlock(s32 arg0, u32 *sizeOut, void **arg2, s32 arg3) {
    u32 tag;
    u8 *sp20;
    u32 size;
    u8 *dst;

    tag = uvFileGetEntryTag(arg0, sizeOut, arg2);
    if (tag != 0) {
        sp20 = _uvMemAllocAlign8(*sizeOut);
        _uvMediaCopy(sp20, *arg2, *sizeOut);
        *arg2 = sp20;
    }
    if (tag == 'GZIP') { // 0x475A4950
        tag = (u32) uvMemRead(sp20, 4);
        size = (u32) uvMemRead(sp20 + 4, 4);
        if (!(arg3 & 2)) {
            dst = _uvMemAllocAlign8(size);
            mio0Decode(sp20 + 8, dst);
            _uvMemFree(sp20);
            *arg2 = dst;
        }
        *sizeOut = size;
    }
    return tag;
}

void uvConsumeBytes(void* dst, u8** ptr, u32 size) {
    u64 mem;

    if (size < sizeof(s64) + 1) {
        mem = uvMemRead(*ptr, size);
        *ptr += size;
        switch (size) {                             /* irregular */
        case sizeof(s8):
            *(s8*)dst = mem;
            return;
        case sizeof(s16):
            *(s16*)dst = mem;
            return;
        case sizeof(s32):
            *(s32*)dst = mem;
            return;
        case sizeof(s64):
            *(s64*)dst  = mem;
            return;
        }
    } else {
        _uvMediaCopy(dst, *ptr, size);
        *ptr += size;
    }
}


#ifdef NEEDS_BSS
s32 func_80001EAC(s32 arg0) {
    UnkStruct_8002D9B4* ptr;
    static s32 D_8001F790;
    

    if (arg0 == D_8002D9B4[D_8001F790].pad0) {
        return D_8001F790;
    }

    for (D_8001F790 = 0; D_8001F790 < D_8002D9A0; D_8001F790++) {
        if (arg0 == D_8002D9B4[D_8001F790].pad0) {
            return D_8001F790;
        }
    }

    return -1;
    
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_80001EAC.s")
#endif

#ifdef NEEDS_BSS
s32 func_80001F38(s32 arg0) {
    static s32 D_8001F794;
    UnkStruct_8002D9B4* var_a1;
    s32 var_v1;

    if (arg0 == D_8002D9B4[D_8001F794].pad0) {
        return D_8001F794;
    }
    
    for (D_8001F794 = 0; D_8001F794 < D_8002D9A0; D_8001F794++) {
        if (arg0 == D_8002D9B4[D_8001F794].pad0) {
            return D_8001F794;
        }
    }
    return -1;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_80001F38.s")
#endif

s32 func_80001FC4(s32 arg0, s32 arg1) {
    if ((arg1 < 0) || (arg1 >= D_8002D9B4[arg0].unk4)) {
        return -1;
    }
    return 0;
}


u8* func_80002004(s32 arg0) {
    int temp;
    s32 i;
    s32 j;

    for (i = arg0; i < D_8002D9A0; i++) {
        for (j = 0; j < D_8002D9B4[i].unk4; j++) {
            int temp = D_8002D9B4[i].unk8[j].pad0;
            if (temp) {
                return temp;
            }
        }
    }

    return UVTS_10_ROM_END;
}

void func_80002088(s32* arg0, s32* arg1, s32* arg2, s32 arg3) {
    s32 i;

    for (i = 0; i < D_8002D9A0; i++) {
        if (i >= arg3) {
            *arg2 = arg3;
            return;
        }

        arg0[i] = D_8002D9B4[i].pad0;
        arg1[i] = func_80002004(i + 1) - func_80002004(i);
    }

    *arg2 = i;
}

void func_8000218C(s32* arg0, s32* arg1, s32* arg2, s32 arg3) {
    s32 j;
    s32 i;

    for (i = 0; i < D_8002D9A0; i++) {
        if (i >= arg3) {
            *arg2 = arg3;
            return;
        }
        
        arg0[i] = D_8002D9B4[i].pad0;
        for (j = 0, arg1[i] = 0; j < D_8002D9B4[i].unk4; j++) {
            arg1[i] += D_8002D9B4[i].unk8[j].unkC;
        }
    }

    *arg2 = i;
}

void func_8000226C(s32* tagPtr, s32* arg1, s32* arg2, u32 arg3) {
    u32 var_v0;
    s32 var_a0;
    s32 var_v1;
    s32 temp_a3;   
    s32 var_t4;
    s32 var_t2;
    s32 var_t3;
    

    var_v0 = 0x80000000;
    for (var_v1 = 0; var_v1 < D_8002D9A0; var_v1++) {
        for (var_a0 = 0; var_a0 < D_8002D9B4[var_v1].unk4; var_a0++) {
            temp_a3 = D_8002D9B4[var_v1].unk8[var_a0].unk4;
            if ((temp_a3 < arg3) && (var_v0 < temp_a3)) {
                var_t2 = var_v1;
                var_t3 = var_a0;
                var_v0 = temp_a3;
                var_t4 = arg3 - temp_a3;
            }
        }
    }
 
    if (var_v0 != 0x80000000) {
        *tagPtr = D_8002D9B4[var_t2].pad0;
        *arg1 = var_t3;
        *arg2 = var_t4;
        return;
    }
    
    *tagPtr = 'CODE';
    *arg1 = 0;
    *arg2 = arg3 - var_v0;
}

void func_80002390(s32 arg0) {
    if (arg0 == 0xFFFF) {
        D_8002D9BC = 0;
    } else {
        D_8002D9BC = func_80001724('UVTP', arg0);
    }
    if (D_8002D9BC); // FAKE
}