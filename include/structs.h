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
    s32 unk0;
    s32 (*unk4)(void);
    char pad8[8];
    void (*unk10)(s32);
    s32 (*unk14)(s32);
    char pad18[4];
    void (*unk1C)(s32, ...);
} UnkStruct_80025C14;

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

typedef struct UnkStruct_80025CAC_s {
    char pad14[0x14];
    void (*unk14)(s32);
} UnkStruct_80025CAC;

typedef struct UnkStruct_80025CF0_s {
    /* 80025CF0 */
    s32 debugState;
    s32 numMaxTxts;
    s32 gameStateFlag;
    s32 unkC;
    /* 80025D00 */
    s32 unk10;
    s32 finishedIntroCount;
    s32 optionsMusicVol;
    s32 optionsSfxVol;
    /* 80025D10 */
    s32 optionsSpeechVol;
    s32 numPlayers;
    s32 numAiCars;
    f32 dbgPlayerLead;
    /* 80025D20 */
    f32 dbgMxSpeed;
    s32 dbgDefaultMaterialFlag;
    s32 dbgAiDbgState;
    s32 dbgRaceAiRecord;
    /* 80025D30 */
    s32 dbgSteerAssist;
    s32 currentTrack;
    s32 unk48; // always 3 upon startup
    s32 unk4C;
    /* 80025D40 */
    s32 unk50;
    s32 dbgDispMasks;
    s32 dbgDispViGamma;
    s32 dbgDispViGamDith;
    /* 80025D50 */
    s32 dbgDispViDivot;
    s32 dbgDispViDither;
    s32 dbgDispAntialias;
    s32 dbgDispTxtFilter;
    /* 80025D60 */
    s32 dbgDispTxtPersp;
    s32 dbgDispTxtDetail;
    s32 dbgDispMipmap;
    f32 unk7C;
    /* 80025D70 */
    f32 unk80;
    s16 initFlag;   // 1 = show normal start up, 0 = jump to main menu
    s16 pauseFlag; // 80025D76
    s32 raceState;
    s32 unk8C;
    /* 80025D80 */
    s32 unkPtr90;
    s32 unk94;
    s32 unk98;
    s16 introReplayState;
    s16 unk9E;
    /* 80025D90 */
    s32 dbgOptsRecordIntro;
    s32 currentGameState;
    s32 dbgOptsGlare;
    s32 dbgOptsFrameRate;
    /* 80025DA0 */
    s32 dbgAbortMode;
    s32 dbgInfLapsFlag;
    s32 dbgHudState;
    s32 dbgFrateDisp;
    /* 80025DB0 */
    s32 dbgSuspensionFlag;
    s32 dbgTileSort;
    s32 dbgTrackWeather; // doesn't work even though it's referenced
    s32 dbgOptsCarShadow;
    u8  paddingCC[0x704C - 0xCC];
    s32 unk704C[2];
} UnkStruct_80025CF0;

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
