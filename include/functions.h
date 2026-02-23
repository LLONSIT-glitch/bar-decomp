#ifndef BAR_FUNCTIONS_H
#define BAR_FUNCTIONS_H
u32 uvFileGetEntryTag(s32 arg0, u32* arg1, void** arg2);
void* func_80002F4C(u32);
void func_800031A8(void*);
void mio0Decode(void* src, u8* dst);
u64 uvMemRead(void* vAddr, u32 nbytes);
void _uvDMA(void* vAddr, u32 devAddr, u32 nbytes);
void _uvMediaCopy(void* vAddr, void* devAddr, u32 nbytes);
void uvMemSet(void* vAddr, u8 value, u32 nbytes);
void *_uvMemAllocAlign8(u32 size);
void* _uvMemAllocAlign16(u32 size);
void formLoader(void);
#endif /* BAR_FUNCTIONS_H */
