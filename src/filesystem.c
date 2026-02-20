#include "common.h"

static FormFileInfo sCurrentFiles[10];

void uvFileSetPadTagStart(s32);                               /* extern */

s32 uvFileReadHeader(u8* data) {
    FormFileInfo* form;
    s32 i;
    
    for (form = sCurrentFiles, i = 0; i < 10; i++, form++) {
        if (form->fileData == NULL) {
            break;
        }
    }

    if (i == 10) {
        *(volatile s32*)0 = 0;
        return -1;
    }
    
    form->fileData = data;
    form->fileSize = uvMemRead(&data[4], 4) + 8; // Read the file size from the header and add the first eight bytes.
    form->padType = uvMemRead(&data[8], 4);
    uvFileSetPadTagStart(i);
    return i;
}

void uvFileFree(s32 id) {
    if ((id >= 0) && (id < 10)) {
        sCurrentFiles[id].fileData = NULL;
    }
}

u8* uvFileGetDataPtr(s32 id) {
    return sCurrentFiles[id].fileData;
}

s32 uvFileGetSize(s32 id) {
    return sCurrentFiles[id].fileSize;
}

s32 uvFileGetPadType(s32 id) {
    return sCurrentFiles[id].padType;
}


u32 uvFileGetEntryTag(s32 id, u32* sizeOut, void** dest) {
    u32 currentTag;
    s32 pad;
    u32 localStack;
    

    if (sizeOut == NULL) {
        sizeOut = &localStack;
    }
    if ((u32) sCurrentFiles[id].padTagStart >= (u32) sCurrentFiles[id].fileSize) {
        return 0U;
    }
    do {
        currentTag = uvMemRead(sCurrentFiles[id].padTagStart + sCurrentFiles[id].fileData, 4U);
        *sizeOut = uvMemRead(sCurrentFiles[id].padTagStart + sCurrentFiles[id].fileData + 4, 4U);
        *dest = sCurrentFiles[id].padTagStart + sCurrentFiles[id].fileData  + 8;

        sCurrentFiles[id].padTagStart += *sizeOut + 8;
    } while (currentTag == 'PAD ');
    return currentTag;
}

u32 func_800025C8(s32 arg0, u32* arg1, void** arg2, s32 arg3, s32 arg4) {
    s32 count;
    u32 tag;
    s32 temp;
    u32 sp38;

    count = 0;
    sp38 = sCurrentFiles[arg0].padTagStart;
    uvFileSetPadTagStart(arg0);

    while ((tag = uvFileGetEntryTag(arg0, arg1, arg2)) != 0) {
        temp = tag;
        if ((temp == arg3) && (arg4 <= count++)) {
            break;
        }
    }
    sCurrentFiles[arg0].padTagStart = sp38;
    return tag;
}

void uvFileSetPadTagStart(s32 id) {
    sCurrentFiles[id].padTagStart = 12;
}
