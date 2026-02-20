#include "common.h"

void func_80000FC8(void);                                  /* extern */
void func_800011A8(void);                                  /* extern */
void func_80002A30(void);                                  /* extern */
void func_80002EAC(s32);                                 /* extern */
void func_80003310(void);                                  /* extern */
void func_80003B80(void);                                  /* extern */
void func_80004274(void);                                  /* extern */
void Thread_Kernel(void*);                          /* extern */
s32 func_80003A14(u32 arg0, s32 *arg1);
s32 func_800034E0(u32);

extern s32* D_8002DA74;
extern s32 D_8002F7C8; // kernel thread stack
extern s32 D_8001F7DC;
extern s32 D_8002F8C8;
extern OSMesgQueue D_8002F800;
extern OSThread sKernelThread;
extern OSIoMesg D_8002F7E0;
extern u16 D_8001F800[];
extern u16 D_8001F7E0[];
extern u8 D_8001F820;
extern void* D_8002F818;
extern OSMesgQueue D_8002F828;
extern OSContStatus D_8002FC30;

void func_80004CC0(u16 *arg0, s32 red, s32 green, u16 blue, u16 alpha);

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

void func_80004E18(u16* arg0, s32 arg1, s32 arg2, u16 arg3, u16 arg4) {
    func_80004CC0(arg0, arg1, D_8001F7E0[arg2], arg3, arg4);
}

void func_80004E5C(s32 arg0, s32 arg1) {
    s16 var_s0;
    s16 i;

    var_s0 = arg0;
    for (i = 0; i < 13; i++) {
        var_s0 += 0xA;
        if ( D_8001F800[i] == 0) {
            var_s0 = arg0;
            arg1 += 0x10;
        } else {
            func_80004CC0(var_s0, (s16)arg1,  D_8001F800[i], 0xFFFFU, 1U);
        }
    } 
}

void func_80004F20(u32 arg0, s32 arg1, s32 arg2) {
    s16 i;

    for (i = 0; i < 8; i++) {
        func_80004E18((u16* ) (s16) ((i * 0xA) + arg1), (s16) arg2, (arg0 >> (0x1C - (i * 4))) & 0xF, 0xFFFFU, 1U);
    } 
}

void func_80004FD8(s32 arg0, s32 arg1) {
    u32 temp_v0;
    s32 sp20;

    temp_v0 = func_80003A14(arg0, &sp20);
    if (temp_v0 != 0) {
        int temp;
        func_80004F20(temp_v0, 0x14, arg1);
        arg0 -= func_800034E0(temp_v0);
        arg0 -= D_8002DA74[sp20];
    } else {
        arg0 += 0x7FFFFBB0;
    }
    func_80004F20(arg0, 0x78, arg1);
    osWritebackDCacheAll();
}

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

u8 uvContMesgInit(OSMesgQueue** arg0, OSContStatus** arg1) {
    s32 pad;
    void* sp68;
    OSMesgQueue sp50;
    OSTimer sp30;
    OSMesg mesg;

    *arg1 = &D_8002FC30;
    if (D_8001F820 == 0) {
        osCreateMesgQueue(&sp50, &sp68, 2);
        osSetTimer(&sp30,  0x2710, 0, &sp50, &sp68);
        osRecvMesg(&sp50, &mesg, OS_MESG_BLOCK);
        osCreateMesgQueue(&D_8002F828, &D_8002F818, 3);
        osSetEventMesg(OS_EVENT_SI, &D_8002F828, (void* )0x33333333);
        osContInit(&D_8002F828, &D_8001F820, *arg1);
    }
    *arg0 = &D_8002F828;
    return D_8001F820;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/5740/func_80005570.s")
