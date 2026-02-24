#include "common.h"

typedef struct MemBlock_s {
    /* 0x0 */ struct MemBlock_s* next;                             /* inferred */
    /* 0x4 */ s32 size;
} MemBlock;                               /* size = 0x8 */

void _uvMemAllocInit(void);                                  /* extern */
void func_80002AEC(s32);                                /* extern */
void func_80002B2C(s32);                                /* extern */

extern MemBlock* gMemBlockHead;
extern MemBlock gMemBlock[];

extern s32 D_8001F7A0;
extern s32 D_8001F7A4;
extern s32 D_8001F7A8;
extern s32 D_8001F7AC;
extern s32 D_8001F7B0;
extern s32 D_8001F7B4;
extern s32 D_8001F7B8;
extern s32 D_8001F7BC;
extern u8 D_8001F7D0;
extern s32 D_8002F7D8;


void* _uvMemAlloc(u32 size, u32 alignment);

void func_80002A30(void) {
    _uvMemAllocInit();
    if ((D_8002F7D8 != 0) || (D_8001F7D0 != 0)) {
        func_80002B2C(D_8001F7D0);
        func_80002AEC(D_8001F7D0);
    }
}

void _uvMemAllocInit(void) {
    gMemBlockHead = gMemBlock;
    gMemBlockHead->next = NULL;
    gMemBlockHead->size = ((u32) 0x80400000) - ((u32) gMemBlock);
    D_8001F7A0 = 1;
    D_8001F7A4 = 1;
}

void func_80002AC8(void) {
    MemBlock *var_v0;

    var_v0 = gMemBlockHead;
    while (var_v0 != NULL) {
        var_v0 = var_v0->next;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80002AEC.s")

void func_80002B2C(s32 arg0) {
    MemBlock* var_s0;

    for (var_s0 = gMemBlockHead; var_s0 != NULL; var_s0 = var_s0->next) {
        uvMemSet(var_s0 + 1, arg0 & 0xFF & 0xFF, var_s0->size - 8);
    }
}

void func_80002B80(MemBlock* arg0) {
    MemBlock* var_a2;
    MemBlock* var_v0;
    s32 temp_v1;

    var_v0 = NULL;
    temp_v1 = arg0->size;
    if (gMemBlockHead == NULL) {
        gMemBlockHead = arg0;
        D_8001F7A0 += 1;
        return;
    }

    var_a2 = gMemBlockHead;
    while (var_a2 != NULL && var_a2 < arg0) {
        var_v0 = var_a2;
        var_a2 = var_a2->next;
    }
    
    if (var_v0 != NULL) {
        if ((u32)arg0 == ( (u32) var_v0 + (u32)var_v0->size)) {
            if ((u32)var_a2 == ((u32)arg0 + (u32)temp_v1)) {
                var_v0->size += temp_v1;
                var_v0->size = var_v0->size + var_a2->size;
                var_v0->next = var_a2->next;
                D_8001F7A0 -= 1;
                return;
            }
        }
    }
    if (var_v0 != NULL) {
        if ((u32)arg0 == ((u32)var_v0 + (u32)var_v0->size)) {
            var_v0->size += temp_v1;
            return;
        }
    }
    if ((u32)var_a2 == ((u32)arg0 + temp_v1)) {
        arg0->next = var_a2->next;
        
        arg0->size = (0, temp_v1) + var_a2->size; // FAKE
        if (var_v0 != NULL) {
            var_v0->next = arg0;
            return;
        }
        gMemBlockHead = arg0;
        return;
    }
    arg0->next = var_a2;
    if (var_v0 != NULL) {
        var_v0->next = arg0;
    } else {
        gMemBlockHead = arg0;
    }
    D_8001F7A0++;
    if ((u32) D_8001F7A4 < (u32) D_8001F7A0) {
        D_8001F7A4 = D_8001F7A0;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/func_80002CD0.s")

void func_80002EAC(s32 arg0) {
    _uvMemAllocInit();
    D_8001F7A0 = 1;
    D_8001F7A4 = 1;
    D_8001F7A8 = 0;
    D_8001F7AC = 0;
    D_8001F7B0 = 0;
    D_8001F7B4 = 0;
    D_8001F7B8 = 0;
    D_8001F7BC = 0;
    if ((arg0 != 0) || (D_8002F7D8 != 0) || (D_8001F7D0 != 0)) {
        func_80002B2C((s32) D_8001F7D0);
        func_80002AEC((s32) D_8001F7D0);
    }
}


void *_uvMemAllocAlign8(u32 size) {
    return _uvMemAlloc(size, 8U);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/_uvMemAlloc.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3630/_uvMemFree.s")

UNUSED void _uvMemUnusedDbgFunc(void) {
    MemBlock* block;
    s32 size;
    u32 var_a0;
    u32 var_v1;
    s32 blockSize;

    
    for (blockSize = 0, var_v1 = 0, var_a0 = -1, block = gMemBlockHead; block != NULL; block = block->next, blockSize += size) {
        size = block->size;
        if (size < var_a0) {
            var_a0 = size;
        }
        
        if (var_v1 < size) {
            var_v1 = size;
        }
    }
}

UNUSED s32 _uvMemGetBlocksSize(void) {
    MemBlock* block;
    s32 blocksSize;

    block = gMemBlockHead;
    blocksSize = 0;
    
    while (block != NULL) {
        blocksSize += block->size;
        block = block->next;
    }
    
    return blocksSize;
}

void* _uvMemAllocAlign16(u32 size) {
   return _uvMemAlloc(size, 0x10U);
}

void func_800032E4(void *arg0) {
    _uvMemFree(arg0);
}
