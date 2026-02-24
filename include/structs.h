#ifndef BAR_STRUCTS_H 
#define BAR_STRUCTS_H
typedef struct UnkStruct_80025C00_s {
    s32 pad0;
    void (*unk4)(s32);
    char pad[0x4];
    void (*unkC)(s32, s32, s32, s32);
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
    void (*unk50)(s32, s32, s32);
    char pad54[0x4];
    void (*unk58)(s32, s32, s32, s32);
    char pad5C[0x18];
    void (*unk74)();
} UnkStruct_80025C08;

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
