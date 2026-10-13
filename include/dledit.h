#ifndef DLEDIT_H
#define DLEDIT_H

typedef struct RGBAF_s {
    f32 red;
    f32 green;
    f32 blue;
    f32 alpha;
} RGBAF;

typedef struct CombineMode_inner_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} CombineMode_inner;

typedef struct CombineMode_s {
    union {
        struct {
            /* 0x00 */ s32 unk0; 
            /* 0x04 */ s32 unk4; 
            /* 0x08 */ s32 unk8; 
            /* 0x0C */ s32 unkC; 
            /* 0x10 */ s32 unk10;
            /* 0x14 */ s32 unk14;
            /* 0x18 */ s32 unk18;
            /* 0x1C */ s32 unk1C;
            /* 0x20 */ s32 unk20;
            /* 0x24 */ s32 unk24;
            /* 0x28 */ s32 unk28;
            /* 0x2C */ s32 unk2C;
            /* 0x30 */ s32 unk30;
            /* 0x34 */ s32 unk34;
            /* 0x38 */ s32 unk38;
            /* 0x3C */ s32 unk3C;
        };
        CombineMode_inner arr[2];
    };
} CombineMode;

typedef struct DlEdit_Exports_s {
    /* 0x00 */ void (*func_dledit_00400090)();                     
    /* 0x04 */ Gfx *(*func_dledit_00400098)(Gfx *, s32);           
    /* 0x08 */ void (*func_dledit_004000C8)(Gfx *, s32);           
    /* 0x0C */ s32 (*func_dledit_00400100)(s32, s32, s32, s32);    
    /* 0x10 */ void (*func_dledit_00400174)(Gfx *, RGBAF *, s32); 
    /* 0x14 */ void (*func_dledit_004001F8)(CombineMode *, Gfx *);       
    /* 0x18 */ void (*func_dledit_0040030C)(Gfx *, RGBAF *);      
    /* 0x1C */ void (*func_dledit_004003D4)(CombineMode *, Gfx *);
    /* 0x20 */ Gfx *(*func_dledit_004004FC)(Gfx *, s32);          
} DlEdit_Exports;                                   /* size = 0x24 */

#endif /* DLEDIT_H */
