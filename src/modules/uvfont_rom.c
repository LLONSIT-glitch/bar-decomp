// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"

typedef struct ParsedUVFT {
    char* str;
    u8 pad4[0x4];
    u8 bmfmt;
    u8 bmsiz;
    Bitmap* bitmap;
    void* imag[0x2C];
} ParsedUVFT; // size = 0x80

typedef struct FontMessage_s {
    s32 x;
    s32 y;
    f32 scaleX;
    f32 scaleY;
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    s16 str16[50];
    ParsedUVFT* font;
} FontMessage; // size = 0x70

extern ParsedUVFT* D_uvfont_rom_004009EC;
extern UvString_Exports* D_uvfont_rom_0040255C;
extern UvGfxMgr_Exports* D_uvfont_rom_00402560;
extern UvCback_Exports* D_uvfont_rom_00402564;
extern UvGfxState_Rom_Exports* D_uvfont_rom_00402568;
extern UvSprt_Rom_Exports* D_uvfont_rom_0040256C;
extern s32 D_uvfont_rom_004009E4; // sFontCurWidth
extern f32 D_uvfont_rom_004009DC; // sFontScaleX
extern f32 D_uvfont_rom_004009E0; // sFontScaleY
extern u8 D_uvfont_rom_004009C4;
extern u8 D_uvfont_rom_004009C8;
extern u8 D_uvfont_rom_004009CC;
extern u8 D_uvfont_rom_004009D0;
extern Sprite D_uvfont_rom_00400980;
extern s32 D_uvfont_rom_004009E8;
extern FontMessage D_uvfont_rom_00400D20[];
extern s32 D_uvfont_rom_00402558;


void func_uvfont_rom_00400840(s32 arg0);
void func_uvfont_rom_0040074C(Gfx **gdl, FontMessage *fontMesg);

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfont_rom/__entrypoint_func_uvfont_rom_400000.s")

// uvModuleCleanup
void func_uvfont_rom_00400148(void) {
    D_uvfont_rom_00402564->func_uvcback_rom_00400320(D_uvfont_rom_00402560->func_uvgfxmgr_rom_00400AB8(1), (s32) func_uvfont_rom_00400840);
    uvUnloadModule('STRG');
    uvUnloadModule('GMGR');
    uvUnloadModule('CBCK');
    uvUnloadModule('STAT');
}

void func_uvfont_rom_004001C8(s32 id) {
    if (((D_uvfont_rom_004009EC = func_80001724('UVFT', id)) != 0) || (((D_uvfont_rom_004009EC = func_800019B8('UVFT', id)) != 0))) {
        D_uvfont_rom_004009E4 =  D_uvfont_rom_004009EC->bitmap->width;
    }
}

// uvFontScale
void func_uvfont_rom_0040023C(f64 arg0, f64 arg1) {
    D_uvfont_rom_004009DC = (f32) arg0;
    D_uvfont_rom_004009E0 = (f32) arg1;
}

// uvFontColor
void func_uvfont_rom_00400258(u8 red, u8 green, u8 blue, u8 alpha) {
    D_uvfont_rom_004009C4 = red;
    D_uvfont_rom_004009C8 = green;
    D_uvfont_rom_004009CC = blue;
    D_uvfont_rom_004009D0 = alpha;
}


// stubbed uvFontStrLen?
s32 func_uvfont_rom_0040028C(s32 arg0) {
    return 0;
}

// stubbed uvFontStr16WidthFont?
s32 func_uvfont_rom_00400298(s32 arg0) {
    return 0;
}

// uvFontStrWidth
s32 func_uvfont_rom_004002A4(ParsedUVFT* font, const char* str) {
    s32 len;
    char* ch;
    s32 width;
    s32 i;
    s32 j;

    len = D_uvfont_rom_0040255C->uvStrlen(str);

    width = 0;
    for (i = 0, j = 0; i < len; i++, j++) {
        if (str[j] == 0) {
            return width;
        }
        if (str[j] == '\n') {
            continue;
        }
        ch = D_uvfont_rom_0040255C->uvStrChr(font->str, str[j]);
        if (ch != 0) {
            width += font->bitmap[ch - font->str].width;
        } else {
            width += D_uvfont_rom_004009E4;
        }
    }

    return width * D_uvfont_rom_004009DC;
}

// uvFontWidth
s32 func_uvfont_rom_004003C8(const char *str) {
    return func_uvfont_rom_004002A4(D_uvfont_rom_004009EC, str);
}

s32 func_uvfont_rom_004003F0(void) {
    return (s32) ((f32) D_uvfont_rom_004009EC->bitmap->actualHeight * D_uvfont_rom_004009E0);
}

// stubbed: uvFontPrintStr16?
s32 func_uvfont_rom_00400428(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return 0;
}

// uvFontPrint
#ifdef NON_MATCHING
void func_uvfont_rom_00400440(s32 x, s32 y, char* str) {
    char* chrPos;
    s32 i;
    char* s1;
    s32 len;
    UvString_Exports* t1;

    y += (s32) (D_uvfont_rom_004009EC->bitmap->actualHeight * D_uvfont_rom_004009E0);
    y = D_uvfont_rom_00402560->uvGetScreenHeight() - y;
    D_uvfont_rom_00400D20[D_uvfont_rom_004009E8].x = x;
    D_uvfont_rom_00400D20[D_uvfont_rom_004009E8].y = y;
    D_uvfont_rom_00400D20[D_uvfont_rom_004009E8].r = D_uvfont_rom_004009C4;
    D_uvfont_rom_00400D20[D_uvfont_rom_004009E8].g = D_uvfont_rom_004009C8;
    D_uvfont_rom_00400D20[D_uvfont_rom_004009E8].b = D_uvfont_rom_004009CC;
    D_uvfont_rom_00400D20[D_uvfont_rom_004009E8].a = D_uvfont_rom_004009D0;
    D_uvfont_rom_00400D20[D_uvfont_rom_004009E8].scaleX = D_uvfont_rom_004009DC;
    D_uvfont_rom_00400D20[D_uvfont_rom_004009E8].scaleY = D_uvfont_rom_004009E0;
    if (1);
    len = D_uvfont_rom_0040255C->uvStrlen(str);
    if (len > 0x32) {
        str[0x31] = 0;
        len = 0x32;
    }

    for (i = 0; i < len; i++) {
        chrPos = D_uvfont_rom_0040255C->uvStrChr(D_uvfont_rom_004009EC->str, str[i]);
        if (chrPos != NULL) {
            D_uvfont_rom_00400D20[D_uvfont_rom_004009E8].str16[i] = chrPos - D_uvfont_rom_004009EC->str;
        } else {
            D_uvfont_rom_00400D20[D_uvfont_rom_004009E8].str16[i] = -2;
        }
    }

    D_uvfont_rom_00400D20[D_uvfont_rom_004009E8].str16[len] = -1;
    D_uvfont_rom_00400D20[D_uvfont_rom_004009E8].font = D_uvfont_rom_004009EC;
    if (D_uvfont_rom_004009E8 < 0x31) {
        D_uvfont_rom_004009E8++;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfont_rom/func_uvfont_rom_00400440.s")
#endif

// uvFontSpriteWidth
s32 func_uvfont_rom_0040065C(Sprite* sprite, s16* str16, ParsedUVFT* font) {
    s32 width;
    s32 i;
    Bitmap* bitmap;

    bitmap = sprite->bitmap;
    for (i = 0, width = 0; str16[i] != -1; i++) {
        if (!(i < 0x32)) {
            break;
        }
        if ((str16[i] == -2) || (str16[i] == -3)) {
            bitmap[i] = font->bitmap[0];
            bitmap[i].buf = NULL;
            width += font->bitmap[0].width;
        } else {
            bitmap[i] = font->bitmap[str16[i]];
            width += font->bitmap[str16[i]].width;
        }
    }
    sprite->nbitmaps = i;
    return width;
}

// uvFontMsgGenDlist
void func_uvfont_rom_0040074C(Gfx** gdl, FontMessage* fontMesg) {
    D_uvfont_rom_00400980.height = fontMesg->font->bitmap->actualHeight;
    D_uvfont_rom_00400980.width = func_uvfont_rom_0040065C(&D_uvfont_rom_00400980, fontMesg->str16, fontMesg->font);
    D_uvfont_rom_00400980.bmfmt = fontMesg->font->bmfmt;
    D_uvfont_rom_00400980.bmsiz = fontMesg->font->bmsiz;
    D_uvfont_rom_00400980.x = fontMesg->x;
    D_uvfont_rom_00400980.y = fontMesg->y;
    D_uvfont_rom_00400980.red = fontMesg->r;
    D_uvfont_rom_00400980.green = fontMesg->g;
    D_uvfont_rom_00400980.blue = fontMesg->b;
    D_uvfont_rom_00400980.alpha = fontMesg->a;
    D_uvfont_rom_00400980.scalex = fontMesg->scaleX;
    D_uvfont_rom_00400980.scaley = fontMesg->scaleY;
    D_uvfont_rom_00400980.rsp_dl = *gdl;
    D_uvfont_rom_00400980.rsp_dl_next = NULL;
    if (D_uvfont_rom_0040256C->uvSpriteDraw(&D_uvfont_rom_00400980) != NULL) {
        *gdl = D_uvfont_rom_00400980.rsp_dl_next;
        *gdl = *gdl - 1;
    }
}

#ifdef NEEDS_DATA
extern s32 D_uvfont_rom_004009F0;
extern s32 D_uvfont_rom_00402558;

void func_uvfont_rom_00400840(s32 arg0) {
    static s32 D_uvfont_rom_004009F0;

    D_uvfont_rom_004009F0++;
    if (D_uvfont_rom_004009F0 != 0) {
        D_uvfont_rom_004009F0 = -1;
        D_uvfont_rom_00402558 = 0;

    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvfont_rom/func_uvfont_rom_00400840.s")
#endif

// uvFontGenDlist
void func_uvfont_rom_00400878(void) {
    Gfx** gdl;
    s32 i;

    if (D_uvfont_rom_004009E8 == 0) {
        return;
    }

    gdl = D_uvfont_rom_00402560->uvGetDisplayListHead();
    D_uvfont_rom_0040256C->uvSpriteDrawInit(gdl);
    for (i = 0; i < D_uvfont_rom_004009E8; i++) {
        func_uvfont_rom_0040074C(gdl, &D_uvfont_rom_00400D20[i]);
    }

    D_uvfont_rom_0040256C->uvSpriteDrawFinish(gdl);
    *gdl -= 1;
    D_uvfont_rom_00402558 += D_uvfont_rom_004009E8;
    D_uvfont_rom_004009E8 = 0;
    if (D_uvfont_rom_00402568 != NULL) {
        D_uvfont_rom_00402568->func_uvgfxstate_rom_004022B0();
    }
}
