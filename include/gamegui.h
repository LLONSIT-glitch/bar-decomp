#ifndef GAMEGUI_H
#define GAMEGUI_H


typedef struct UnkStruct_gamegui_00402C68_s {
    /* 0x000 */ u8 unk0;                            /* inferred */
                s32 unk4;
                s32 unk8;   
    /* 0x00C */ s32 unkC;                           /* inferred */
    /* 0x010 */ uvGui gui;
    /* 0x09C */ void (*unk9C)(void);                       /* inferred */
    s32 unk100;
} UnkStruct_gamegui_00402C68;                       /* size = 0x100 */


typedef struct GameGui_Exports_s {
    /* 0x00 */ void (*func_gamegui_004000A8)(void);                      /* inferred */
    /* 0x04 */ void (*func_gamegui_004000B0)(void);                      /* inferred */
    /* 0x08 */ void (*func_gamegui_00401748)(void);                      /* inferred */
    /* 0x0C */ void (*func_gamegui_00401A7C)(void);                      /* inferred */
    /* 0x10 */ void (*func_gamegui_00401AD8)(s32);                  /* inferred */
    /* 0x14 */ void (*func_gamegui_00401E7C)(void);                     /* inferred */
    /* 0x18 */ void (*func_gamegui_00401FE0)(void);                     /* inferred */
    /* 0x1C */ void (*func_gamegui_00402030)(void (*arg0)(void));              /* inferred */
    /* 0x20 */ void (*func_gamegui_00402358)(s32);                  /* inferred */
    /* 0x24 */ u8 (*func_gamegui_004023B0)(void);                       /* inferred */
    /* 0x28 */ UnkStruct_gamegui_00402C68 *D_gamegui_00402C68;   /* inferred */
} GameGui_Exports;                                  /* size = 0x2C */

#endif /* GAMEGUI_H */
