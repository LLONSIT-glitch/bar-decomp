#include "common.h"

static FormFileInfo D_8002D9C0[10];

void func_80002694(s32);                               /* extern */

s32 func_800023E0(u8* data) {
    FormFileInfo* form;
    s32 i;
    
    for (form = D_8002D9C0, i = 0; i < 10; i++, form++) {
        if (form->fileData == NULL) {
            break;
        }
    }

    if (i == 10) {
        *(s32*)0 = 0;
        return -1;
    }
    
    form->fileData = data;
    form->fileSize = uvMemRead(&data[4], 4) + 8; // Read the file size from the header and add the first eight bytes.
    form->padType = uvMemRead(&data[8], 4);
    func_80002694(i);
    return i;
}

void func_80002484(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 10)) {
        D_8002D9C0[arg0].fileData = NULL;
    }
}

u8* func_800024A8(s32 arg0) {
    return D_8002D9C0[arg0].fileData;
}

s32 func_800024BC(s32 arg0) {
    return D_8002D9C0[arg0].fileSize;
}

s32 func_800024D0(s32 arg0) {
    return D_8002D9C0[arg0].padType;
}


u32 func_800024E4(s32 arg0, u32* arg1, s32* arg2) {
    u32 currentTag;
    s32 pad;
    u32 localStack;
    

    if (arg1 == NULL) {
        arg1 = &localStack;
    }
    if ((u32) D_8002D9C0[arg0].padTagStart >= (u32) D_8002D9C0[arg0].fileSize) {
        return 0U;
    }
    do {
        currentTag = uvMemRead(D_8002D9C0[arg0].padTagStart + D_8002D9C0[arg0].fileData, 4U);
        *arg1 = uvMemRead(D_8002D9C0[arg0].padTagStart + D_8002D9C0[arg0].fileData + 4, 4U);
        *arg2 = D_8002D9C0[arg0].padTagStart + D_8002D9C0[arg0].fileData  + 8;

        D_8002D9C0[arg0].padTagStart += *arg1 + 8;
    } while (currentTag == 'PAD ');
    return currentTag;
}

u32 func_800025C8(s32 arg0, u32* arg1, s32* arg2, s32 arg3, s32 arg4) {
    s32 var_s0;
    u32 ret;
    s32 temp;
    u32 sp38;

    var_s0 = 0;
    sp38 = D_8002D9C0[arg0].padTagStart;
    func_80002694(arg0);

    while ((ret = func_800024E4(arg0, arg1, arg2)) != 0) {
        temp = ret;
        if ((temp == arg3) && (var_s0++ >= arg4)) {
            break;
        }
    }
    D_8002D9C0[arg0].padTagStart = sp38;
    return ret;
}

void func_80002694(s32 arg0) {
    D_8002D9C0[arg0].padTagStart = 12;
}
