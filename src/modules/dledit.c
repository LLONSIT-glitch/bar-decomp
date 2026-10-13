// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"


void func_dledit_00400090(void);
Gfx *func_dledit_00400098(Gfx *gdl, s32 w);
void func_dledit_004000C8(Gfx *gdl, s32 arg1);
s32 func_dledit_00400100(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_dledit_00400174(Gfx *arg0, RGBAF *arg1, s32 arg2);
void func_dledit_004001F8(CombineMode *arg0, Gfx *arg1);
void func_dledit_0040030C(Gfx *gdl, RGBAF *color);
void func_dledit_004003D4(CombineMode *arg0, Gfx *arg1);
Gfx *func_dledit_004004FC(Gfx *gdl, s32 w);
void __entrypoint_func_dledit_400000(DlEdit_Exports *exports);

// .bss
s32 B_dledit_00400790; // unreferenced padding

// .data
char *D_dledit_00400600[22] = {
    "COMBINED",
    "TEXEL0",
    "TEXEL1",
    "PRIMITIVE",
    "SHADE",
    "ENVIRON",
    "KEYCENTER",
    "KEYSCALE",
    "ACOMBINED",
    "ATEXEL0",
    "ATEXEL1",
    "APRIMITIVE",
    "ASHADE",
    "AENVIRON",
    "LODFRACT",
    "PRIMLOD",
    "NOISE",
    "K4",
    "K5",
    "1",
    "0",
    "UNDEFINED",
};

s32 D_dledit_00400658[3][9] = {
    { 0, 1, 2, 3, 4, 5, 0x13, 0x10, 0x14 },
    { 0, 1, 2, 3, 4, 5, 6, 0x11, 0x14 },
    { 0, 1, 2, 3, 4, 5, 7, 8, 9 },
};

s32 D_dledit_004006C4[0x11] = {
    0,
    1,
    2,
    3,
    4,
    5,
    0x13,
    0x14,
    0x15,
    0xA,
    0xB,
    0xC,
    0xD,
    0xE,
    0xF,
    0x12,
    0x14,
};

s32 D_dledit_00400708[4][8] = {
    { 8, 9, 0xA, 0xB, 0xC, 0xD, 0x13, 0x14 },
    { 8, 9, 0xA, 0xB, 0xC, 0xD, 0x13, 0x14 },
    { 0xE, 9, 0xA, 0xB, 0xC, 0xD, 0xF, 0x14 },
    { 8, 9, 0xA, 0xB, 0xC, 0xD, 0x13, 0x14 },
};

s32 D_dledit_00400788[] = {0x00240000, __entrypoint_func_dledit_400000};


void __entrypoint_func_dledit_400000(DlEdit_Exports* exports) {
    uvUpdateFileAllocPtr(exports);
    exports->func_dledit_00400090 = func_dledit_00400090;
    exports->func_dledit_00400098 = func_dledit_00400098;
    exports->func_dledit_004000C8 = func_dledit_004000C8;
    exports->func_dledit_00400100 = func_dledit_00400100;
    exports->func_dledit_00400174 = func_dledit_00400174;
    exports->func_dledit_004001F8 = func_dledit_004001F8;
    exports->func_dledit_0040030C = func_dledit_0040030C;
    exports->func_dledit_004003D4 = func_dledit_004003D4;
    exports->func_dledit_004004FC = func_dledit_004004FC;
}

void func_dledit_00400090(void) {

}

Gfx* func_dledit_00400098(Gfx* gdl, s32 w) {
    while (TRUE) {
        s32 word = *(u8*)gdl;
        if (word == w) {
            return gdl;
        }
        
        gdl++;
        if ((s8) word == G_ENDDL) {
            return NULL;
        }
    }
}

void func_dledit_004000C8(Gfx* gdl, s32 arg1) {
    Gfx* dl;

    dl = func_dledit_00400098(gdl, G_SETTIMG);
    if (dl != NULL) {
        dl->words.w1 = (u32)OS_PHYSICAL_TO_K0(arg1);
    }
}

s32 func_dledit_00400100(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_v1;

    if (arg3 >= 9) {
        var_v1 = D_dledit_004006C4[arg3];
    } else if (arg1 != 0) {
        var_v1 = D_dledit_00400708[arg2][arg3];
    } else {
        var_v1 = D_dledit_00400658[arg2][arg3];
    }
    return D_dledit_00400600[var_v1];
}


void func_dledit_00400174(Gfx *gdl, RGBAF *color, s32 arg2) {
    if (gdl == NULL) {
        return;
    }
    gdl->words.w0 = (arg2 << 8) << 16;
    gdl->words.w1 =
        (((((s32) (color->alpha * 255.0f)) & 0xFF) | ((((s32) (255.0f * color->red)) << 19) << 5))
         | ((((s32) (255.0f * color->green)) & 0xFF) << 0x10))
        | ((((s32) (255.0f * color->blue)) & 0xFF) << 8);
}

void func_dledit_004001F8(CombineMode *mode, Gfx *gdl) {
    if (gdl == NULL) {
        return;
    }

    gdl->words.w0 =
        (((((int) ((((mode->unk28 & 0x1F) | ((mode->unk20 & 0xF) << 5)) | ((mode->unk0 & 0xF) << 0x14))
                   | ((mode->unk8 & 0x1F) << 0xF)))
           | ((mode->unk10 & 7) << 0xC))
          | ((mode->unk18 & 7) << 9))
         & 0xFFFFFF)
        | 0xFC000000;
    gdl->words.w1 =
        (((((((((mode->unk3C & 7) | ((mode->unk24 & 0xF) << 0x18)) | ((mode->unk30 & 7) << 0x15))
              | ((mode->unk38 & 7) << 0x12))
             | ((mode->unk2C & 7) << 6))
            | ((mode->unk34 & 7) * 8))
           | ((mode->unk4 << 7) << 21))
          | ((mode->unkC & 7) << 0xF))
         | ((mode->unk14 & 7) << 0xC))
        | ((mode->unk1C & 7) << 9);
}

void func_dledit_0040030C(Gfx* gdl, RGBAF* color) {
    u32 w1;

    if (gdl == NULL) {
        return;
    }

    w1 = gdl->words.w1;
    
    color->red = (((w1 >> 0x18) & 0xFF) / 255.0f);
    color->green = (((w1 >> 0x10) & 0xFF) / 255.0f);
    color->blue = (((w1 >> 8) & 0xFF) / 255.0f);
    color->alpha = ((w1 & 0xFF) / 255.0f);
}

void func_dledit_004003D4(CombineMode* arg0, Gfx* gdl) {
    s32 i;
    u32 temp_v0;
    u32 temp_v1;
    s32 end;

    if (gdl != NULL) {
        temp_v0 = gdl->words.w0;
        temp_v1 = gdl->words.w1;
        arg0->arr[0].unk0 = (s32) ((temp_v0 >> 0x14) & 0xF);
        arg0->arr[0].unk4 = (s32) ((temp_v1 >> 0x1C) & 0xF);
        arg0->arr[0].unk8 = (s32) ((temp_v0 >> 0xF) & 0x1F);
        arg0->arr[0].unkC = (s32) ((temp_v1 >> 0xF) & 7);
        arg0->arr[0].unk10 = (s32) ((temp_v0 >> 0xC) & 7);
        arg0->arr[0].unk14 = (s32) ((temp_v1 >> 0xC) & 7);
        arg0->arr[0].unk18 = (s32) ((temp_v0 >> 9) & 7);
        arg0->arr[0].unk1C = (s32) ((temp_v1 >> 9) & 7);
        arg0->arr[1].unk0 = (s32) ((temp_v0 >> 5) & 0xF);
        arg0->arr[1].unk4 = (s32) ((temp_v1 >> 0x18) & 0xF);
        arg0->arr[1].unk8 = (s32) (temp_v0 & 0x1F);
        arg0->arr[1].unkC = (s32) ((temp_v1 >> 6) & 7);
        arg0->arr[1].unk10 = (s32) ((temp_v1 >> 0x15) & 7);
        arg0->arr[1].unk14 = (s32) ((temp_v1 >> 3) & 7);
        arg0->arr[1].unk18 = (s32) ((temp_v1 >> 0x12) & 7);
        arg0->arr[1].unk1C = (s32) (temp_v1 & 7);
    }
    for (i = 0; i < 2; i++) {
        if (arg0->arr[i].unk0 >= 9) {
            arg0->arr[i].unk0 = 8;
        }
        if (arg0->arr[i].unk4 >= 9) {
            arg0->arr[i].unk4 = 8;
        }
        if (arg0->arr[i].unk8 >= 0x11) {
            arg0->arr[i].unk8 = 0x10;
        }
    }
}

Gfx* func_dledit_004004FC(Gfx* gdl, s32 w) {
    while (TRUE) {
        u8 byte = *(u8*)gdl;
        s32 word = gdl->words.w0;
        if (word == w) {
            return gdl;
        }
        
        gdl++;
        if ((s8) byte == G_ENDDL) {
            return NULL;
        }
    }
}
