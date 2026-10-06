#ifndef UVGUI_ROM_H
#define UVGUI_ROM_H



typedef void (*UvGuiRoutine)(void* arg0);

// Item entry unk28, unk2C, unk30 possible inner struct
typedef struct Inner28_s {
    /* 0x00 */ s8 unk0;                             /* inferred */
    /* 0x01 */ char pad1[0x1D];                     /* maybe part of unk0[0x1E]? */
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ s16 unk20;
    /* 0x22 */ char pad22[2];
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ s32* unk2C;
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ s16 unk38;
    /* 0x3A */ s16 unk3A;
    /* 0x3C */ s16 unk3C;
    /* 0x3E */ s16 unk3E;
    /* 0x40 */ void (*unk40)(void*);
    /* 0x44 */ s32* unk44;
} Inner28;                                          /* size = 0x48 */

typedef struct Inner2C_s {
    /* 0x00 */ u8 unk0[0x1E];
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ s16 unk20;
    /* 0x22 */ char pad22[2];
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ Vec3F* unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
    /* 0x3C */ s16 unk3C;                           /* inferred */
    /* 0x3E */ s16 unk3E;                           /* inferred */
    /* 0x40 */ s16 unk40;                           /* inferred */
    /* 0x42 */ s16 unk42;                           /* inferred */
    /* 0x44 */ s16 unk44;
    /* 0x46 */ char pad46[2];
    /* 0x48 */ void (*unk48)(void*);
} Inner2C;                                          /* size = 0x4C */

typedef struct Inner30_s {
    /* 0x00 */ UvGrphStruct* unk0;
    /* 0x04 */ s8 unk4[0x1E];
    /* 0x22 */ u8 unk22[0x1E];
    /* 0x40 */ u8 unk40[0x1E];
    /* 0x5E */ s16 unk5E;
    /* 0x60 */ s16 unk60;
    /* 0x62 */ s16 unk62;
    /* 0x64 */ s16 unk64;
    /* 0x66 */ char pad66[2];
    /* 0x68 */ f32 unk68;
    /* 0x6C */ f32 unk6C;
    /* 0x70 */ f32 unk70;
    /* 0x74 */ f32 unk74;                           /* inferred */
    /* 0x78 */ f32 unk78;
    /* 0x7C */ f32 unk7C; 
    /* 0x80 */ f32* unk80;
    /* 0x84 */ s16 unk84;
    /* 0x86 */ s16 unk86;
    /* 0x88 */ s16 unk88;
    /* 0x8A */ s16 unk8A;
    /* 0x8C */ void (*unk8C)(void*);
} Inner30;                                          /* size = 0x90 */

// Item Entry?
typedef struct UnkStruct_uvgui_rom_00400510_unk0_unk28_inner_s {
    /* 0x00 */ u8 unk0[0xB];
    /* 0x0B */ char padB[1];
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ s16 unk12;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ s16 unk18;
    /* 0x1A */ char pad1A[2];
    /* 0x1C */ UvGuiRoutine unk1C; /* inferred */
    /* 0x20 */ UvGuiRoutine unk20; /* inferred */
    /* 0x24 */ UvGuiRoutine unk24; /* inferred */
    /* 0x28 */ Inner28* unk28;
    /* 0x2C */ Inner2C* unk2C;
    /* 0x30 */ Inner30* unk30;
} UnkStruct_uvgui_rom_00400510_unk0_unk28_inner;    /* size = 0x34 */

// MenuEntry?
typedef struct UnkStruct_uvgui_rom_00400510_unk0_unk28_s {
    /* 0x001 */ u8 unk0[0x1E];                    /* maybe part of unk0[0x20]? */
    /* 0x01E */ s16 unk1E;
    /* 0x020 */ s16 unk20;                          /* inferred */
    /* 0x022 */ s16 unk22;                          /* inferred */
    /* 0x024 */ s16 unk24;                          /* inferred */
    /* 0x026 */ s16 unk26;                          /* inferred */
    /* 0x028 */ UnkStruct_uvgui_rom_00400510_unk0_unk28_inner* unk28[80]; // itemEntry?
    /* 0x168 */ s16 unk168;                         /* inferred */
    /* 0x16A */ s16 unk16A;
    /* 0x16C */ s16 unk16C;                         /* inferred */
    /* 0x16E */ char pad16E[2];
} UnkStruct_uvgui_rom_00400510_unk0_unk28;          /* size = 0x170 */

typedef struct UnkStruct_uvgui_rom_00400510_unk0_s {
    /* 0x00 */ u8 unk0[0x1E];
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ s16 unk20;
    /* 0x22 */ s16 unk22;
    /* 0x24 */ s16 unk24;                           /* inferred */
    /* 0x26 */ s16 unk26;                           /* inferred */
    /* 0x28 */ UnkStruct_uvgui_rom_00400510_unk0_unk28* unk28[0xC];
    /* 0x58 */ s16 unk58;
    /* 0x5A */ s16 unk5A;
} UnkStruct_uvgui_rom_00400510_unk0;                /* size = 0x5C */

typedef struct UnkStruct_uvgui_rom_00400510_s {
    /* 0x00 */ UnkStruct_uvgui_rom_00400510_unk0* unk0[0x14];
    /* 0x50 */ s16 unk50;
    /* 0x52 */ char pad52[2];
    /* 0x54 */ s16 unk54;
    /* 0x56 */ s16 unk56;
    /* 0x58 */ s16 unk58;
    /* 0x5A */ s16 unk5A;
    /* 0x5C */ s32 unk5C;
    /* 0x60 */ f32 unk60;
    /* 0x64 */ f32 unk64;
    /* 0x68 */ f32 unk68;
    /* 0x6C */ f32 unk6C;
    /* 0x70 */ s16 unk70;
    /* 0x72 */ s16 unk72;
    /* 0x74 */ s32 unk74;
    /* 0x78 */ s32 unk78;
    /* 0x7C */ s32 unk7C;
    /* 0x80 */ s32 unk80;
    /* 0x84 */ s8 contNo;
    /* 0x85 */ char pad85[1];
    /* 0x86 */ s16 uvds;                           /* inferred */
    /* 0x88 */ s16 fontId;
    /* 0x8A */ s8 unk8A;
    /* 0x8B */ s8 unk8B;
} UnkStruct_uvgui_rom_00400510;                     /* size = 0x8C */


// Could be UnkStruct_uvgui_rom_00400510_unk0_unk28_inner?
typedef struct UnkStruct_uvgui_rom_00407238_s {
    /* 0x00 */ char pad0[0xC];
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;                            /* inferred */
    /* 0x10 */ s16 unk10;                           /* inferred */
    /* 0x12 */ s16 unk12;                           /* inferred */
    /* 0x14 */ s16 unk14;                           /* inferred */
    /* 0x16 */ char pad16[6];                       /* maybe part of unk14[4]? */
    /* 0x1C */ s32 unk1C;                           /* inferred */
    /* 0x20 */ s32 unk20;                           /* inferred */
    /* 0x24 */ s32 unk24;                           /* inferred */
    /* 0x28 */ s32 unk28;                           /* inferred */
    /* 0x2C */ s32 unk2C;                           /* inferred */
    /* 0x30 */ s32 unk30;                           /* inferred */
} UnkStruct_uvgui_rom_00407238;                     /* size = 0x34 */

typedef struct UvGui_Exports_s {
    /* 0x000 */ void (*func_uvgui_rom_00400498)(void);
    /* 0x004 */ void (*func_uvgui_rom_00400510)(UnkStruct_uvgui_rom_00400510 *);
    /* 0x008 */ void (*func_uvgui_rom_004006B8)(UnkStruct_uvgui_rom_00400510 *, UnkStruct_uvgui_rom_00400510_unk0 *);
    /* 0x00C */ void (*func_uvgui_rom_00400754)(UnkStruct_uvgui_rom_00400510 *);
    /* 0x010 */ void (*func_uvgui_rom_00400990)(s16, s16, s16, s16, s16, u8, u8, u8, u8);
    /* 0x014 */ void (*func_uvgui_rom_00400F44)(s16, s16, s16, s16, u8 *, u8, u8, u8, u8);
    /* 0x018 */ void (*func_uvgui_rom_0040104C)(s16, s16);
    /* 0x01C */ void (*func_uvgui_rom_0040126C)(UnkStruct_uvgui_rom_00400510 *, s16, s16, s16, s16);
    /* 0x020 */ s32 (*func_uvgui_rom_00401290)(UnkStruct_uvgui_rom_00400510 *);
    /* 0x024 */ void (*func_uvgui_rom_004015B8)(UnkStruct_uvgui_rom_00400510 *, s16, s32);
    /* 0x028 */ void (*func_uvgui_rom_00401614)(UnkStruct_uvgui_rom_00400510 *, s16, s16);
    /* 0x02C */ void (*func_uvgui_rom_004016A0)(UnkStruct_uvgui_rom_00400510 *, s8);
    /* 0x030 */ void (*func_uvgui_rom_004016AC)(UnkStruct_uvgui_rom_00400510 *, s16, s16);
    /* 0x034 */ void (*func_uvgui_rom_004016E0)(s16);
    /* 0x038 */ void (*func_uvgui_rom_004016F0)(UnkStruct_uvgui_rom_00400510 *);
    /* 0x03C */ void (*func_uvgui_rom_00401BC8)(void);
    /* 0x040 */ s16 (*func_uvgui_rom_00401CA0)(void);
    /* 0x044 */ UnkStruct_uvgui_rom_00407238 *(*func_uvgui_rom_00401CE0)(s16);
    /* 0x048 */ void (*func_uvgui_rom_00401D10)(void *, u8 *);
    /* 0x04C */ void (*func_uvgui_rom_00401D74)(UnkStruct_uvgui_rom_00407238 *, s16);
    /* 0x050 */ void (*func_uvgui_rom_00401D80)(UnkStruct_uvgui_rom_00400510_unk0_unk28_inner *, s16, s16, s16, s16);
    /* 0x054 */ void (*func_uvgui_rom_00401DC4)(UnkStruct_uvgui_rom_00400510_unk0_unk28_inner *);
    /* 0x058 */ s32 (*func_uvgui_rom_004020A0)(UnkStruct_uvgui_rom_00400510_unk0_unk28_inner *, u8, s16, s16, s32, f32, f32);
    /* 0x05C */ void (*func_uvgui_rom_0040221C)(UnkStruct_uvgui_rom_00400510_unk0_unk28_inner *, s16, void (*)(void *));
    /* 0x060 */ void (*func_uvgui_rom_00402268)(UnkStruct_uvgui_rom_00400510_unk0_unk28_inner *, Inner28 *);
    /* 0x064 */ void (*func_uvgui_rom_00402308)(UnkStruct_uvgui_rom_00400510_unk0_unk28_inner *, Inner2C *);
    /* 0x068 */ void (*func_uvgui_rom_004023A8)(UnkStruct_uvgui_rom_00400510_unk0_unk28_inner *, Inner30 *);
    /* 0x06C */ void (*func_uvgui_rom_00402638)(void);
    /* 0x070 */ s16 (*func_uvgui_rom_00402698)(void);
    /* 0x074 */ UnkStruct_uvgui_rom_00400510_unk0 *(*func_uvgui_rom_004026E8)(s16);
    /* 0x078 */ void (*func_uvgui_rom_00402718)(void *, u8 *);
    /* 0x07C */ void (*func_uvgui_rom_0040277C)(UnkStruct_uvgui_rom_00400510_unk0 *, s16);
    /* 0x080 */ void (*func_uvgui_rom_00402788)(UnkStruct_uvgui_rom_00400510_unk0 *, s16, s16, s16, s16);
    /* 0x084 */ void (*func_uvgui_rom_004027AC)(UnkStruct_uvgui_rom_00400510_unk0 *, UnkStruct_uvgui_rom_00400510_unk0_unk28 *);
    /* 0x088 */ void (*func_uvgui_rom_00402850)(UnkStruct_uvgui_rom_00400510_unk0 *);
    /* 0x08C */ s32 (*func_uvgui_rom_0040293C)(UnkStruct_uvgui_rom_00400510_unk0 *, u8, s16, s16, s32, f32, f32);
    /* 0x090 */ void (*func_uvgui_rom_00402B00)(void);
    /* 0x094 */ s16 (*func_uvgui_rom_00402B60)(void);
    /* 0x098 */ UnkStruct_uvgui_rom_00400510_unk0_unk28 *(*func_uvgui_rom_00402BA0)(s16);
    /* 0x09C */ void (*func_uvgui_rom_00402BD0)(void *, u8 *);
    /* 0x0A0 */ void (*func_uvgui_rom_00402C34)(UnkStruct_uvgui_rom_00400510_unk0_unk28 *, s16);
    /* 0x0A4 */ void (*func_uvgui_rom_00402C40)(UnkStruct_uvgui_rom_00400510_unk0_unk28 *, s16, s16, s16, s16);
    /* 0x0A8 */ void (*func_uvgui_rom_00402C74)(UnkStruct_uvgui_rom_00400510_unk0_unk28 *, UnkStruct_uvgui_rom_00400510_unk0_unk28_inner *);
    /* 0x0AC */ void (*func_uvgui_rom_00402D1C)(UnkStruct_uvgui_rom_00400510_unk0_unk28 *);
    /* 0x0B0 */ s32 (*func_uvgui_rom_00402E48)(UnkStruct_uvgui_rom_00400510_unk0_unk28 *, u8, s16, s16, s32, f32, f32);
    /* 0x0B4 */ void (*func_uvgui_rom_0040300C)(void);
    /* 0x0B8 */ s16 (*func_uvgui_rom_004031A4)(void);
    /* 0x0BC */ void (*func_uvgui_rom_004031E4)(s16);
    /* 0x0C0 */ Inner28 *(*func_uvgui_rom_0040320C)(s16);
    /* 0x0C4 */ void (*func_uvgui_rom_00403234)(void *, u8 *);
    /* 0x0C8 */ void (*func_uvgui_rom_00403298)(Inner28 *, s16, s16, s16, s16);
    /* 0x0CC */ void (*func_uvgui_rom_004032BC)(Inner28 *);
    /* 0x0D0 */ void (*func_uvgui_rom_004037D8)(Inner28 *, s32);
    /* 0x0D4 */ void (*func_uvgui_rom_004037E0)(Inner28 *, f32, f32, f32, s32 *);
    /* 0x0D8 */ void (*func_uvgui_rom_004038D8)(Inner28 *, s16);
    /* 0x0DC */ void (*func_uvgui_rom_004038E4)(Inner28 *, u8, f32);
    /* 0x0E0 */ void (*func_uvgui_rom_00403C50)(Inner28 *, s16);
    /* 0x0E4 */ void (*func_uvgui_rom_00403CA4)(Inner28 *, s32);
    /* 0x0E8 */ void (*func_uvgui_rom_00403CAC)(void);
    /* 0x0EC */ s16 (*func_uvgui_rom_00403E78)(void);
    /* 0x0F0 */ void (*func_uvgui_rom_00403EB8)(s16);
    /* 0x0F4 */ Inner30 *(*func_uvgui_rom_00403EE0)(s16);
    /* 0x0F8 */ void (*func_uvgui_rom_00403F08)(Inner30 *, s16, s16, s16, s16);
    /* 0x0FC */ void (*func_uvgui_rom_00403F2C)(Inner30 *, u8 *, u8 *);
    /* 0x100 */ void (*func_uvgui_rom_00404010)(Inner30 *, s32, f32, f32, f32, f32 *);
    /* 0x104 */ void (*func_uvgui_rom_0040404C)(Inner30 *, s32);
    /* 0x108 */ void (*func_uvgui_rom_00404054)(Inner30 *, u8, f32);
    /* 0x10C */ void (*func_uvgui_rom_004046B4)(Inner30 *);
    /* 0x110 */ void (*func_uvgui_rom_00405CEC)(Inner30 *, s16);
    /* 0x114 */ void (*func_uvgui_rom_00405D1C)(Inner30 *, ...);
    /* 0x118 */ void (*func_uvgui_rom_00405D78)(void);
    /* 0x11C */ s16 (*func_uvgui_rom_00405F20)(void);
    /* 0x120 */ void (*func_uvgui_rom_00405F60)(s16);
    /* 0x124 */ Inner2C *(*func_uvgui_rom_00405F90)(s16);
    /* 0x128 */ void (*func_uvgui_rom_00405FC0)(Inner2C *, u8 *);
    /* 0x12C */ void (*func_uvgui_rom_00406024)(Inner2C *, s16, s16, s16, s16);
    /* 0x130 */ void (*func_uvgui_rom_00406048)(Inner2C *);
    /* 0x134 */ void (*func_uvgui_rom_00406B00)(Inner2C *, s32);
    /* 0x138 */ void (*func_uvgui_rom_00406B08)(Inner2C *, f32, f32, Vec3F *, Vec3F *);
    /* 0x13C */ void (*func_uvgui_rom_00406B7C)(Inner2C *, s16);
    /* 0x140 */ void (*func_uvgui_rom_00406B88)(Inner2C *, u8, f32);
    /* 0x144 */ void (*func_uvgui_rom_00406E28)(Inner2C *, s16);     /* inferred */
} UvGui_Exports;                                    /* size = 0x144 */
 


#endif /* UVGUI_ROM_H */
