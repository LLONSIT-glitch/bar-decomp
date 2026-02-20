#ifndef BAR_FUNCTIONS_H
#define BAR_FUNCTIONS_H
s32 func_800023E0(u8* data);
u64 uvMemRead(void* vAddr, u32 nbytes);
void _uvDMA(void* vAddr, u32 devAddr, u32 nbytes);
void _uvMediaCopy(void* vAddr, void* devAddr, u32 nbytes);
void uvMemSet(void* vAddr, u8 value, u32 nbytes);
#endif /* BAR_FUNCTIONS_H */
