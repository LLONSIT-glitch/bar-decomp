#include "common.h"

void func_80000FC8(void);                                  /* extern */
void func_800011A8(void);                                  /* extern */
void func_80002A30(void);                                  /* extern */
void func_80002EAC(s32);                                 /* extern */
void func_80003310(void);                                  /* extern */
void func_80003B80(void);                                  /* extern */
void func_80004274(void);                                  /* extern */
void Thread_Kernel(void*);                          /* extern */

extern s32 D_8002F7C8; // kernel thread stack
extern s32 D_8001F7DC;
extern s32 D_8002F8C8;
extern OSMesgQueue D_8002F800;
extern OSThread sKernelThread;
extern OSIoMesg D_8002F7E0;

void func_80004B40(void) {
    if (D_8001F7DC != 0) {
        func_80002A30();
        func_80003B80();
        func_800011A8();
        func_80000FC8();
        formLoader();
        func_80003310();
        D_8001F7DC = 0;
        if (D_8002F8C8 != 0) {
            *(s32*)0 = 0;
        }
    } else {
        func_80004274();
        func_80002EAC(0);
        formLoader();
        func_80003310();
        func_80000FC8();
    }
}

static void unusedFunction() {
}

void uvWaitForMesg(u8 msg) {
    if (!msg) {
        osRecvMesg(&D_8002F800, NULL, 1);
    }
}

void bootproc(void* arg0) {
    u32 devAddr;
    s32 i;
    u32 sp38[16];
    

    osInitialize();
    osAiSetFrequency(0x5622U);
    devAddr = 0xFFB000;
    for (i = 0; i < 16; i++, devAddr += 4) {
        osPiRawReadIo(devAddr, &sp38[i]);
    } 
    osCreateThread(&sKernelThread, 1, Thread_Kernel, &sp38, &D_8002F7C8, 0xC);
    osStartThread(&sKernelThread);
}


#pragma GLOBAL_ASM("asm/us/nonmatchings/5740/func_80004CC0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/5740/func_80004E18.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/5740/func_80004E5C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/5740/func_80004F20.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/5740/func_80004FD8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/5740/func_80005074.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/5740/func_800051B4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/5740/func_80005284.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/5740/Thread_Kernel.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/5740/func_80005390.s")

void _uvDMA(void *vAddr, u32 devAddr, u32 nbytes) {
    if ((!((s32) vAddr % 8)) && (!((s32) devAddr % 2)) && (nbytes < 0x400001U)) {
        if (nbytes & 1) {
            nbytes = (nbytes + 1) & ~1;
        }
        osWritebackDCache(vAddr, (s32) nbytes);
        osPiStartDma(&D_8002F7E0, 0, 0, devAddr, vAddr, nbytes, &D_8002F800);
        osInvalDCache(vAddr, (s32) nbytes);
        uvWaitForMesg(0U);
    }
}


#pragma GLOBAL_ASM("asm/us/nonmatchings/5740/func_80005484.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/5740/func_80005570.s")
