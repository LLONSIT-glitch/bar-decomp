#ifndef BAR_UV_MEMORY_H
#define BAR_UV_MEMORY_H
typedef struct MemBlock_s {
    /* 0x0 */ struct MemBlock_s* next;
    /* 0x4 */ s32 size;
} MemBlock;
#endif /* BAR_UV_MEMORY_H */

