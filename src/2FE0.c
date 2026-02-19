#include "common.h"

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_800023E0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80002484.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_800024A8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_800024BC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_800024D0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_800024E4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_800025C8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80002694.s")

void _uvMediaCopy(void* vAddr, void* devAddr, u32 nbytes) {
    s32 i;
    u8 *alignCeil;
    s32 alignDiff;
    u8 *src; // s1
    u8 buf[16];
    u8 *dst; // s2
    // nbytes -> s0
    s32 temp_a2;
    s32 temp_v0;

    dst = vAddr;
    src = devAddr;
    if ((u32)src & 0x80000000) {
        for (i = 0; (u32)i < nbytes; i++) {
            dst[i] = src[i];
        }
        return;
    }

    while (nbytes > 0x1000) {
        _uvMediaCopy(dst, src, 0x1000);
        nbytes -= 0x1000;
        dst += 0x1000;
        src += 0x1000;
    }

    if (nbytes != 0) {
        if (((s32)src | (s32) dst | nbytes) & 1) {
            // it appears the devs intended to cause a fault by storing to an unaligned address,
            // but IDO outsmarted them and broke this into two `sb` instructions
            // Debug Print removed..
            *(u16*)(1) = 0;
            return;
        }
        if ((s32)dst & 7) {
            alignCeil = (u8*)((s32)(dst + 7) & ~7);
            alignDiff = alignCeil - dst;
            temp_a2 = (u32)src & 2;
            
            if ((nbytes != (u32)alignDiff) != 0) {
                _uvDMA(alignCeil, src + alignDiff, nbytes - alignDiff);
            }
            temp_v0 = src - temp_a2;
            
            osPiWriteIo(temp_v0, &buf[0]);
            osPiWriteIo(temp_v0 + 4, &buf[4]);
            if (temp_a2) {
                osPiWriteIo(temp_v0 + 8, &buf[8]);
            }
            for (i = 0; i < alignDiff && i < nbytes; i++) {
                dst[i] = buf[i + temp_a2];
            }
            
        } else {
            _uvDMA(dst, src, nbytes);
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_8000285C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/uvMemRead.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80002A30.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80002A88.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80002AC8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80002AEC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80002B2C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80002B80.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80002CD0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80002EAC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80002F4C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80002F6C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_800031A8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80003240.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80003294.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_800032C4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_800032E4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80003310.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80003494.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_800034E0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80003520.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_8000355C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80003584.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80003760.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80003790.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80003A14.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80003AF0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80003B64.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80003B80.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80003C1C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80003CEC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80003E0C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80003E94.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80003F04.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80004014.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80004088.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80004274.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80004284.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80004298.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_800042DC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_800042E4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_800043E4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_800046EC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_8000481C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_8000487C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_800048C8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_800048D4.s")

void func_800048DC(void) {
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_800048E4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80004958.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80004A78.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80004A84.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80004B1C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2FE0/func_80004B2C.s")
