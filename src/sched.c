#include "common.h"
#include <PR/sched.h>

typedef struct UnkStruct_8022B6CC {
    s32 unk0;
    s32 unk4;
} UnkStruct_8022B6CC_t;

#define VIDEO_MSG 666
#define RSP_DONE_MSG 667
#define RDP_DONE_MSG 668
#define PRE_NMI_MSG 669

extern OSViMode D_8024B7D0[];
extern s32 D_802B9C58;
extern OSScTask *D_8002EE00[];
extern OSScTask *D_8002EDF8;
extern u8 D_8002F250;
extern u8 gSchedRspStatus;
extern u8 gSchedRdpStatus;
extern u8 D_8002F253;
extern u8 D_8002F254;
extern u8 D_8002F255;
extern u8 D_8002F256;
extern u8 D_8002F257;
extern u8 D_8002F258;
extern s32 D_8002F25C;
extern s32 D_8002F260;
extern s32 D_8002F264;
extern s32 D_8002F268;
extern s32 D_8002F274;
extern OSSched *D_8002F4F8;
extern s32 gSchedRingIdx;
extern s32 D_8001F7C0;
extern s32 D_8001F7C4;
extern OSScTask *D_8002EE08;
extern s32 D_8002F26C;
extern OSMesgQueue D_8002EE10;
extern OSMesg D_8002EE28[];
extern s32 gSchedStack[];
extern OSSched D_8002F278[];
extern OSSched *D_8002F4F8;
extern f64 D_8002EDD0[];
extern s32 D_8001F7C0;

void __scMain(void *);
void func_800048DC(void);
void func_80003F04(void);
void func_80004958(s32, s32);
void func_800048E4(void);
void _uvScCreateScheduler(OSSched *sc, void *stack, s32 priority, u8 mode, u8 numFields);
void _uvScHandleRetrace(void);
void _uvScHandleRSP(void);
void _uvScHandleRDP(void);
void _uvScHandleNMI(void);

void uvSetVideoMode(void) {
    s32 viMode;
    OSSched *temp;

    osCreateMesgQueue(&D_8002EE10, D_8002EE28, 0xA);

    switch (osTvType) {
        case OS_TV_PAL:
            viMode = OS_VI_PAL_LAN1;
            break;
        case OS_TV_NTSC:
            viMode = OS_VI_NTSC_LAN1;
            break;
        case OS_TV_MPAL:
            viMode = OS_VI_MPAL_LAN1;
            break;
        default:
            viMode = OS_VI_PAL_LAN1;
            break;
    }

    temp = D_8002F4F8 = D_8002F278;
    _uvScCreateScheduler(temp, gSchedStack, 0x7F, viMode, 1);
}

void func_80003C1C(void) {
    OSMesg sp2C;
    int temp;
    while (osRecvMesg(&D_8002F4F8->interruptQ, &sp2C, OS_MESG_NOBLOCK) != -1) {
    }

    temp = D_8002F257 = 0;
    D_8002F258 = temp;
    D_8002EE00[1] = D_8002EDF8 = NULL;
    D_8002EE00[0] = NULL;
    gSchedRspStatus = gSchedRdpStatus = D_8002F254 = D_8002F253 = 0;
}

void func_80003CEC(void) {
    OSScTask *temp_a3;

    temp_a3 = D_8002EE00[D_8002F256];
    if (D_8002F274 == 0) {
        if (temp_a3 == NULL) {
            func_800048DC();
            return;
        }
        if ((D_8002F254 == 0) && (gSchedRspStatus != 0x67) && (gSchedRdpStatus == 0)) {
            func_80004958(0, 0x32);
            osSendMesg(temp_a3->msgQ, temp_a3->msg, 1);
            if (D_8001F7C4 < D_8001F7C0) {
                D_8002F250 = (D_8001F7C0 - D_8001F7C4) + 1;
            } else {
                D_8002F250 = 1;
                if (D_8002F26C == 0) {
                    osViSwapBuffer(temp_a3->framebuffer);
                }
            }
            D_8002EE08 = D_8002EE00[D_8002F256];
            D_8002EE00[D_8002F256] = NULL;
        }
    }
}

void func_80003E0C(void) {
    if (D_8002EDF8 != NULL) {
        func_80004958(1, 0x2C);
        if (D_8002F274 == 0) {
            osSendMesg(D_8002EDF8->msgQ, D_8002EDF8->msg, 1);
        }
        D_8002EDF8 = NULL;
        if (D_8002EE00[D_8002F256] != NULL) {
            func_80003F04();
        }
    }
}

void func_80003E94(void) {
    if ((D_8002F274 == 0) && (D_8002EDF8 != NULL)) {
        gSchedRspStatus = 0x61;
        func_80004958(1, 0x29);
        osWritebackDCacheAll();
        osSpTaskLoad(&D_8002EDF8->list);
        osSpTaskStartGo(&D_8002EDF8->list);
    }
}

void func_80003F04(void) {
    OSScTask *scTask;

    scTask = D_8002EE00[D_8002F256];
    if (((D_8002F274 == 0) || (D_8002F254 != 0)) && (scTask != NULL) && (gSchedRspStatus != 'g')
        && ((D_8002F254 != 0) || (gSchedRdpStatus != 'g'))) {
        if (osViGetCurrentFramebuffer() == osViGetNextFramebuffer()) {
            gSchedRspStatus = 'g';
            if (D_8002F254 == 0) {
                D_8002F25C += 1;
                gSchedRdpStatus = 'g';
            }
            func_80004958(1, 0x2A);
            D_8002F254 = D_8002F253 = 0;
            osWritebackDCacheAll();
            osSpTaskLoad(&scTask->list);
            osSpTaskStartGo(&scTask->list);
        }
    }
}

void func_80004014(void) {
    // _uvDebugPrintf("Recovered from a bad display list\n");

    IO_WRITE(SP_STATUS_REG, 0x2902);
    if (gSchedRspStatus != 0) {
        osSendMesg(&D_8002F4F8->interruptQ, (void *) RSP_DONE_MSG, 0);
    }
    if (gSchedRdpStatus != 0) {
        osSendMesg(&D_8002F4F8->interruptQ, (void *) RDP_DONE_MSG, 0);
    }
}

void _uvScCreateScheduler(OSSched *sc, void *stack, s32 priority, u8 mode, u8 numFields) {

    D_8002F4F8 = sc;
    D_8002EE00[1] = 0;
    D_8002EE00[0] = 0;
    D_8002EDF8 = 0;
    D_8002F250 = 0;
    gSchedRspStatus = 0;
    gSchedRdpStatus = 0;
    D_8002F253 = 0;
    D_8002F254 = 0;
    D_8002F255 = 0;
    D_8002F256 = 0;
    D_8002F257 = 0;
    D_8002F258 = 0;
    D_8002F25C = 0;
    gSchedRingIdx = 0;
    D_8002F260 = 0;
    D_8002F274 = 0;
    D_8002F264 = 1;
    D_8002F268 = 1;

    if ((sc && sc) != 0) {
    } // fakematch

    sc->clientList = 0;
    sc->curRSPTask = 0;
    sc->curRDPTask = 0;
    sc->frameCount = 0;
    sc->audioListHead = 0;
    sc->gfxListHead = 0;
    sc->audioListTail = (OSScTask *) &sc->audioListHead;
    sc->gfxListTail = (OSScTask *) &sc->gfxListHead;
    sc->retraceMsg.type = OS_SC_RETRACE_MSG;
    sc->prenmiMsg.type = OS_SC_PRE_NMI_MSG;

    osCreateMesgQueue(&sc->interruptQ, sc->intBuf, OS_SC_MAX_MESGS);
    osCreateMesgQueue(&sc->cmdQ, sc->cmdMsgBuf, OS_SC_MAX_MESGS);
    osCreateViManager(OS_PRIORITY_VIMGR);
    osViSetMode(&osViModeTable[mode]);
    osViBlack(TRUE);
    osViSwapBuffer((void *) 0x100000);
    osViSetSpecialFeatures(0x44);
    osSetEventMesg(OS_EVENT_SP, &sc->interruptQ, (OSMesg) RSP_DONE_MSG);
    osSetEventMesg(OS_EVENT_DP, &sc->interruptQ, (OSMesg) RDP_DONE_MSG);
    osSetEventMesg(OS_EVENT_PRENMI, &sc->interruptQ, (OSMesg) PRE_NMI_MSG);
    osViSetEvent(&sc->interruptQ, (OSMesg) VIDEO_MSG, (u32) numFields);

    osCreateThread(&sc->thread, 4, __scMain, (void *) sc, stack, priority);
    osStartThread(&sc->thread);

    uvClkReset(0x69);
    func_800048E4();
}

void func_80004274(void) {
    D_8002F4F8->clientList = NULL;
}

void _uvScAddClient(OSSched *sc, OSScClient *client, OSMesgQueue *mq) {
    client->msgQ = mq;
    client->next = sc->clientList;
    sc->clientList = (OSScClient *) client;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/sched/func_80004298.s")

s32 func_800042DC(OSSched *s) {
    return &s->cmdQ;
}

void __scMain(void *arg0) {
    OSMesg msg;
    msg = NULL;

    while (1) {
        osRecvMesg(&D_8002F4F8->interruptQ, &msg, 1);

        switch ((int) msg) {
            case VIDEO_MSG:
                _uvScHandleRetrace();
                break;
            case RSP_DONE_MSG:
                _uvScHandleRSP();
                break;
            case RDP_DONE_MSG:
                _uvScHandleRDP();
                break;
            case PRE_NMI_MSG:
                _uvScHandleNMI();
                break;
            default:
                //_uvDebugPrintf("unknown sched interrupt mesg: 0x%x\n", msg);
                break;
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/sched/_uvScHandleRetrace.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/sched/_uvScHandleRSP.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/sched/_uvScHandleRDP.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/sched/_uvScHandleNMI.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/sched/func_800048C8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/sched/func_800048D4.s")

void func_800048DC(void) {
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/sched/func_800048E4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/sched/func_80004958.s")

void func_80004A78(s32 arg0) {
    D_8001F7C0 = arg0;
}

f64 func_80004A84(void) {
    int idx1;
    int idx2;
    idx1 = (gSchedRingIdx + 1) % 5;
    idx2 = (gSchedRingIdx + 2) % 5;
    return D_8002EDD0[idx2] - D_8002EDD0[idx1];
}

void func_80004B1C(s32 arg0, s32 arg1, s32 arg2) {
}

void func_80004B2C(s32 arg0) {
    D_8002F26C = arg0;
}
