#ifndef BAR_UV_FILESYSTEM_H
#define BAR_UV_FILESYSTEM_H

#include <PR/ultratypes.h>

s32 uvFileReadHeader(u8* data);
void uvFileFree(s32 idx);
u8* uvFileGetDataPtr(s32 id);
s32 uvFileGetSize(s32 id);
s32 uvFileGetPadType(s32 id);
u32 uvFileGetEntryTag(s32 id, u32* sizeOut, void** dest);
u32 func_800025C8(s32 arg0, u32* arg1, void** arg2, s32 arg3, s32 arg4);
void uvFileSetPadTagStart(s32 id);
u32 uvFileReadBlock(s32 arg0, u32* sizeOut, void** arg2, s32 arg3);

#endif /* BAR_UV_FILESYSTEM_H */
