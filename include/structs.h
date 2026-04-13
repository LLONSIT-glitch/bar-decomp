// SPDX-License-Identifier: AGPL-3.0-or-later
#ifndef BAR_STRUCTS_H 
#define BAR_STRUCTS_H
typedef struct UnkStruct_80025C00_s {
    s32 pad0;
    void (*unk4)(s32);                // fontSet
    char pad[0x4];
    void (*unkC)(s32, s32, s32, s32); // fontColor
    char pad10[0x8];
    s32 (*unk18)(s32);
    char pad1C[0x8];
    void (*unk24)(s32, s32, s32);
    void (*unk28)(void);

} UnkStruct_80025C00;

typedef struct UnkStruct_80025C08_s {
    s32 pad0;
    void (*unk4)(void);
    char pad8[0x18];
    void (*unk20)(void);
    char padC[0x2C];
    void (*unk50)(s32, s32, s32); // bg solid color
    char pad54[0x4];
    void (*unk58)(s32, s32, s32, s32);
    char pad5C[0x18];
    void (*unk74)();
    char pad78[0xC];
    s32 (*unk84)(void);
    s32 (*unk88)(void);
} UnkStruct_80025C08;

// logo and intro
typedef struct UnkStruct_80025C14_s {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 (*unk4)(void*);
    /* 0x08 */ char pad8[8];                        /* maybe part of unk4[3]? */
    /* 0x10 */ void (*unk10)(s32);                     /* inferred */
    /* 0x14 */ char pad14[8];                       /* maybe part of unk10[3]? */
    /* 0x1C */ void (*unk1C)(s32, ...);
} UnkStruct_80025C14;                               /* size = 0x20 */

typedef struct UnkStruct_80025C74_s {
    s32 pad0;
    s32 unk4;
    u8 pad8[0x10 - 0x8];
    void (*unk10)(s32);
    void (*unk14)(void);
    s32 pad18;
    void (*unk1C)(s32);
    u8 pad20[0x28 - 0x20];
    s32 unk28;
} UnkStruct_80025C74;

typedef struct UnkStruct_80025BE8_s {
    char pad[0x6C];
    void (*unk6C)(void);
} UnkStruct_80025BE8;

typedef struct UnkStruct_8002D1A4_s {
    char pad[0x8];
    void (*unk8)(s32);
    void (*unkC)(s32);
    char pad10[0x58];
    void (*unk68)(void);
    
} UnkStruct_8002D1A4;
#endif /* BAR_STRUCTS_H */
