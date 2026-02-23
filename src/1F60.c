#include "common.h"

typedef struct UnkStruct_8002D9B4_inner_s {
    s32 pad0;
    s32 unk4;
    char pad[0x8];
} UnkStruct_8002D9B4_inner;

typedef struct UnkStruct_8002D9B4_s {
    s32 pad0;
    u16 unk4;
    UnkStruct_8002D9B4_inner *unk8;
} UnkStruct_8002D9B4;

typedef struct UnkStruct_8002D9BC_s {
    u16 unk0;
    u16 *unk4;
    s16 *unk8;
} UnkStruct_8002D9BC;

typedef struct UnkStruct_80003520_s {
    s32 unk0;
    void *(*unk4)(s32);
} UnkStruct_80003520;

extern UnkStruct_8002D9B4 *D_8002D9B4;
extern UnkStruct_8002D9BC *D_8002D9BC;
extern UnkStruct_8002D9B4_inner *D_8002D9A4;

s32 func_800019B8(s32, u16);            /* extern */
s32 func_80001EAC(void);                    /* extern */
UnkStruct_80003520 *func_80003520(s32); /* extern */
s32 func_80003584(s32);                 /* extern */
void func_80003760(s32);                /* extern */

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/formLoader.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_800015D4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_80001654.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_800016A4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_80001724.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_800017A4.s")

s32 uvLoader(s32 tag, s32 arg1) {
    UnkStruct_8002D9B4_inner *temp_s0;
    s32 temp_v0;
    s32 i;

    temp_v0 = func_80001EAC();
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
        temp_s0->unk4 = func_80003584(temp_s0->pad0);
        D_8002D9A4 = NULL;
    } else if (D_8002D9B4[temp_v0].pad0 != 0xFFFF) {
        temp_s0->unk4 = func_80003520(D_8002D9B4[temp_v0].pad0)->unk4(temp_s0->pad0);
        func_80003760(D_8002D9B4[temp_v0].pad0);
    } else {
        temp_s0->unk4 = temp_s0->pad0;
    }
    return temp_s0->unk4;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_800019A8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_800019B8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_80001A68.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_80001BC0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_80001C6C.s")

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
            func_800031A8(sp20);
            *arg2 = dst;
        }
        *sizeOut = size;
    }
    return tag;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_80001DDC.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_80002004.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_80002088.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_8000218C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_8000226C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_80002390.s")
