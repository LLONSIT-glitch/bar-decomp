// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include <PR/sp.h>

typedef struct UnkUVTX_1C {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    u8 unk18;
} UnkUVTX_1C; // size = 0x1C

typedef struct ParsedUVTX {
    void *unk0;
    Gfx *unk4;
    u16 size;
    void *data;
    u16 padA;
    u8 pad[2];
    u16 unk12;
    u16 unk14;
    s32 pad18;
    u16 width;
    u16 height;
    u8 unk20;
    u8 unk21;
    u8 unk22;
    u8 unk23;
    u8 unk24;
    u8 unk25;
    u8 unk26;
    f32 unk28;
} ParsedUVTX;

typedef struct uvSprite_s {
    /* 00 */ u8 unk0;
    /* 01 */ u8 unk1;
    /* 02 */ s16 width;
    /* 04 */ s16 height;
    /* 06 */ s16 unk6;
    /* 08 */ s16 unk8;
    /* 0A */ u16 textureId;
    /* 0xC */ Bitmap *bitmap;
    /* 10 */ Sprite sprite;
} uvSprite_t; // size 0x54

extern uvSprite_t *D_uvsprt_rom_004033C0;
extern s32 D_uvsprt_rom_004033C4;

// .bss
extern s32 sScissorXmax;
extern s32 sScissorYmax;
extern s32 sScissorXmin;
extern s32 sScissorYmin;

// .data
extern s32* sPrevBitmapBuf;

void func_uvsprt_rom_00400000(uvSprite_t *sprite, ParsedUVTX *uvtx);
void func_uvsprt_rom_004000A4(uvSprite_t *sprite, ParsedUVTX *uvtx);

void func_uvsprt_rom_00400000(uvSprite_t *sprite, ParsedUVTX *uvtx) {
    Bitmap *bitmap;

    if ((u16) sprite->unk8 == 0xFFFF) {
        sprite->bitmap = NULL;
    }
    bitmap = sprite->bitmap;
    if (bitmap == NULL) {
        bitmap = _uvMemAllocAlign8(sizeof(Bitmap));
        sprite->bitmap = bitmap;
    }
    bitmap->width = uvtx->width - 1;
    sprite->bitmap->width_img = (s16) uvtx->width;
    sprite->bitmap->s = 0;
    sprite->bitmap->t = 0;
    sprite->bitmap->buf = uvtx->data;
    sprite->bitmap->actualHeight = (s16) uvtx->height;
    sprite->bitmap->LUToffset = 0;
}

void func_uvsprt_rom_004000A4(uvSprite_t *sprite, ParsedUVTX *uvtx) {
    Sprite *sp = &sprite->sprite;

    if (uvtx != NULL) {
        sp->width = uvtx->width - 1;
        sp->height = uvtx->height - 1;
        sp->bmheight = uvtx->height - 1;
        sp->bmHreal = (s16) uvtx->height;
        sp->bmfmt = 0;
        sp->bmsiz = 2;
        sp->attr = 0x200;

        if (uvtx->unk21 != 1) {
            sp->attr |= 1;
        }
        if (uvtx->unk21 == 1) {
            sp->bmfmt = 4;
        } else if (uvtx->unk21 == 2) {
            sp->bmfmt = 3;
        } else {
            sp->bmfmt = 0;
        }
        if (uvtx->unk24 == 4) {
            sp->bmsiz = 0;
        } else if (uvtx->unk24 == 8) {
            sp->bmsiz = 1;
        } else {
            sp->bmsiz = 2;
        }
        sp->scalex = 1.0f;
        sp->scaley = 1.0f;
    }

    sp->expx = 0;
    sp->expy = 0;
    sp->zdepth = 0x1234;
    sp->red = 0xFF;
    sp->green = 0xFF;
    sp->blue = 0xFF;
    sp->alpha = 0xFF;
    sp->startTLUT = 0;
    sp->nTLUT = 0;
    sp->LUT = NULL;
    sp->istart = 0;
    sp->istep = 1;
    sp->nbitmaps = 1;
    sp->ndisplist = 0x24;
    sp->scalex = 1.0f;
    sp->scaley = 1.0f;
    sp->bitmap = sprite->bitmap;
    sp->frac_s = 0;
    sp->frac_t = 0;
}

s32 func_uvsprt_rom_004001EC(void) {
    s32 i;

    for (i = 0; i < D_uvsprt_rom_004033C4; i++) {
        if (D_uvsprt_rom_004033C0[i].unk1 == 0) {
            D_uvsprt_rom_004033C0[i].unk1 = 1;
            return i;
        }
    }

    return -1;
}

void func_uvsprt_rom_0040023C(s32 arg0) {
    D_uvsprt_rom_004033C0[arg0].unk0 = 0;
    D_uvsprt_rom_004033C0[arg0].unk1 = 0;
}

void func_uvsprt_rom_00400274(void) {
    uvUnloadModule('GMGR');
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvsprt_rom/__entrypoint_func_uvsprt_rom_400298.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvsprt_rom/func_uvsprt_rom_0040046C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvsprt_rom/func_uvsprt_rom_004004CC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvsprt_rom/func_uvsprt_rom_004005F8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvsprt_rom/func_uvsprt_rom_004006B0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvsprt_rom/func_uvsprt_rom_00400868.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvsprt_rom/func_uvsprt_rom_004008AC.s")

// uvSprtProps
#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvsprt_rom/func_uvsprt_rom_004008F0.s")

#ifdef NEEDS_RODATA
// uvDrawBitMap
void func_uvsprt_rom_00400CF4(Gfx **glp, Sprite *s, Bitmap *b, s32 x, s32 y, s32 xx, s32 yy, s32 fs,
                              s32 ft, s32 sx, s32 sy) {
    s32 rs, rt;
    s32 rxh, ryh;
    s32 rxl, ryl;
    Gfx *gl;
    s32 tex_width, tex_height;
    Gtexrect gt, *g;
    s32 s_clamp, t_clamp, s_mask, t_mask, s_lod, t_lod;

    g = &gt;

    tex_width = b->width_img;
    tex_height = s->bmHreal;

    gl = *glp;

    /* Scissoring */
    if ((x >= sScissorXmax) || (y >= sScissorYmax)) {

        return;
    }

    if ((xx < sScissorXmin) || (yy < sScissorYmin)) {
        return;
    }

    if (x < sScissorXmin) {
        rxh = sScissorXmin * 4;
        rs = (b->s << 5) + fs + (((sScissorXmin - x) * sx) >> 5);
#ifdef DEBUG_SCISSOR
        emPrintf("Sprite Scissoring: Left Edge (%d) not in range (%d,%d)\n", x, sScissorXmin,
                 sScissorXmax);
#endif
    } else {
        rxh = x * 4;
        rs = (b->s << 5) + fs;
    };

    if (y < sScissorYmin) {
        ryh = sScissorYmin * 4;
        rt = (b->t << 5) + ft + (((sScissorYmin - y) * sy) >> 5);
#ifdef DEBUG_SCISSOR
        emPrintf("Sprite Scissoring: Top Edge (%d) not in range (%d,%d)\n", y, sScissorYmin,
                 sScissorYmax);
#endif
    } else {
        ryh = y * 4;
        rt = (b->t << 5) + ft;
    }

    if (xx >= sScissorXmax) {
        rxl = sScissorXmax * 4;
#ifdef DEBUG_SCISSOR
        emPrintf("Sprite Scissoring: Right Edge (%d) not in range (%d,%d)\n", xx, sScissorXmin,
                 sScissorXmax);
#endif
    } else {
        rxl = xx * 4;
    };

    if (yy >= sScissorYmax) {
        ryl = sScissorYmax * 4;
#ifdef DEBUG_SCISSOR
        emPrintf("Sprite Scissoring: Bottom Edge (%d) not in range (%d,%d)\n", yy, sScissorYmin,
                 sScissorYmax);
#endif
    } else {
        ryl = yy * 4;
    };

    s_clamp = G_TX_CLAMP;
    t_clamp = G_TX_CLAMP;
    s_mask = G_TX_NOMASK;
    t_mask = G_TX_NOMASK;
    s_lod = G_TX_NOLOD;
    t_lod = G_TX_NOLOD;

#define LOAD_TEX

#ifdef LOAD_TEX
    if (b->buf != sPrevBitmapBuf) {
        switch (s->bmsiz) {
#if BUILD_VERSION >= VERSION_J
            case G_IM_SIZ_DD:
                gDPLoadTextureTile_4b(gl++, b->buf, s->bmfmt, tex_width, tex_height, b->s, b->t,
                                      b->s + b->width, b->t + b->actualHeight, 0, s_clamp, t_clamp,
                                      s_mask, t_mask, s_lod, t_lod);
                break;
#endif
            case G_IM_SIZ_4b:
                if (s->attr & SP_TEXSHUF) {
                    gDPLoadTextureBlock_4bS(gl++, b->buf, s->bmfmt, tex_width, tex_height, 0, s_clamp,
                                            t_clamp, s_mask, t_mask, s_lod, t_lod);
                } else {
                    gDPLoadTextureBlock_4b(gl++, b->buf, s->bmfmt, tex_width, tex_height, 0, s_clamp,
                                           t_clamp, s_mask, t_mask, s_lod, t_lod);
                };
                break;

            case G_IM_SIZ_8b:
                if (s->attr & SP_TEXSHUF) {
                    gDPLoadTextureBlockS(gl++, b->buf, s->bmfmt, G_IM_SIZ_8b, tex_width, tex_height, 0,
                                         s_clamp, t_clamp, s_mask, t_mask, s_lod, t_lod);
                } else {
                    gDPLoadTextureBlock(gl++, b->buf, s->bmfmt, G_IM_SIZ_8b, tex_width, tex_height, 0,
                                        s_clamp, t_clamp, s_mask, t_mask, s_lod, t_lod);
                };
                break;
            case G_IM_SIZ_16b:
                if (s->bmfmt == G_IM_FMT_YUV) {
                    if (s->attr & SP_TEXSHUF) {
                        gDPLoadTextureBlockYuvS(gl++, b->buf, s->bmfmt, G_IM_SIZ_16b, tex_width,
                                                tex_height, 0, s_clamp, t_clamp, s_mask, t_mask, s_lod,
                                                t_lod);
                    } else {
                        if (b->LUToffset != 0) { /* Split Y and UV areas */
                            unsigned char *uv, *addr;
                            int j;
                            s32 tmem, siz;

                            gDPSetTextureImage(gl++, G_IM_FMT_I, G_IM_SIZ_8b, 1, b->buf);
                            gDPSetTile(gl++, G_IM_FMT_I, G_IM_SIZ_8b, 0, 256, G_TX_LOADTILE, 0, t_clamp,
                                       t_mask, t_lod, s_clamp, s_mask, s_lod);
                            gDPLoadSync(gl++);
                            gDPLoadBlock(gl++, G_TX_LOADTILE, 0, 0, tex_width * tex_height - 1,
                                         CALC_DXT(tex_width, 1));
                            gDPLoadSync(gl++);

                            uv = ((unsigned char *) b->buf)
                                 + ((tex_width * tex_height) / 2) * b->LUToffset;

                            for (j = 0; j <= (tex_height / 2); j++) {
                                addr = uv + ((tex_height / 2) - 2 - j) * tex_width;
                                siz = 3 * tex_width;
                                tmem = (tex_width / 8) * (tex_height - 2 - 2 * j);
                                if (tmem < 0) {
                                    addr += (-tmem) * 8;
                                    siz -= (-tmem) * 8;
                                    tmem = 0;
                                };
                                if (j == 0)
                                    siz = 2 * tex_width;

                                gDPSetTextureImage(gl++, G_IM_FMT_I, G_IM_SIZ_8b, 1, addr);
                                gDPSetTile(gl++, G_IM_FMT_I, G_IM_SIZ_8b, 0, tmem, G_TX_LOADTILE, 0,
                                           t_clamp, t_mask, t_lod, s_clamp, s_mask, s_lod);
                                gDPLoadSync(gl++);
                                gDPLoadBlock(gl++, G_TX_LOADTILE, 0, 0, siz - 1,
                                             CALC_DXT(tex_width, 1));
                                gDPLoadSync(gl++);
                            };

                            gDPSetTile(gl++, s->bmfmt, G_IM_SIZ_16b, (((tex_width) * 1) + 7) >> 3, 0,
                                       G_TX_RENDERTILE, 0, t_clamp, t_mask, t_lod, s_clamp, s_mask,
                                       s_lod);
                            gDPSetTileSize(gl++, G_TX_RENDERTILE, 0, 0,
                                           ((tex_width) -1) << G_TEXTURE_IMAGE_FRAC,
                                           ((tex_height) -1) << G_TEXTURE_IMAGE_FRAC);

                        } else {
                            gDPLoadTextureBlockYuv(gl++, b->buf, s->bmfmt, G_IM_SIZ_16b, tex_width,
                                                   tex_height, 0, s_clamp, t_clamp, s_mask, t_mask,
                                                   s_lod, t_lod);
                        };
                    };
                } else {
                    if (s->attr & SP_TEXSHUF) {
                        gDPLoadTextureBlockS(gl++, b->buf, s->bmfmt, G_IM_SIZ_16b, tex_width,
                                             tex_height, 0, s_clamp, t_clamp, s_mask, t_mask, s_lod,
                                             t_lod);
                    } else {
                        gDPLoadTextureBlock(gl++, b->buf, s->bmfmt, G_IM_SIZ_16b, tex_width, tex_height,
                                            0, s_clamp, t_clamp, s_mask, t_mask, s_lod, t_lod);
                    };
                };
                break;
            case G_IM_SIZ_32b:
                if (s->attr & SP_TEXSHUF) {
                    gDPLoadTextureBlockS(gl++, b->buf, s->bmfmt, G_IM_SIZ_32b, tex_width, tex_height, 0,
                                         s_clamp, t_clamp, s_mask, t_mask, s_lod, t_lod);
                } else {
                    gDPLoadTextureBlock(gl++, b->buf, s->bmfmt, G_IM_SIZ_32b, tex_width, tex_height, 0,
                                        s_clamp, t_clamp, s_mask, t_mask, s_lod, t_lod);
                };
                break;
        }
        sPrevBitmapBuf = b->buf;
    }
#endif /* LOAD_TEX */

    g->cmd = G_TEXRECT;
    g->tile = 0;

    g->xh = rxh;
    g->xl = rxl;
    g->yh = ryh;
    g->yl = ryl;

    g->s = rs;
    g->t = rt;

    if ((s->attr & SP_FASTCOPY) && (s->bmfmt != G_IM_FMT_YUV))
        g->dsdx = sx * 4;
    else
        g->dsdx = sx;

    g->dtdy = sy;

    gSPTextureRectangle(gl++, g->xh, g->yh, g->xl, g->yl, g->tile, g->s, g->t, g->dsdx, g->dtdy);

    gDPPipeSync(gl++);

    *glp = gl;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvsprt_rom/func_uvsprt_rom_00400CF4.s")
#endif

extern u16 sSpriteAttribute;

void func_uvsprt_rom_00402414(Gfx **glistp) {
    Gfx *gl;

    gl = *glistp;
    sSpriteAttribute = 0;
    sScissorXmin = 0;
    sScissorYmin = 0;
    sScissorXmax = 320; // Screen width
    sScissorYmax = 240; // Screen height
    /* Turn on texturing */
    gDPPipeSync(gl++);
    gDPSetCycleType(gl++, G_CYC_1CYCLE);
    gSPTexture(gl++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPSetAlphaCompare(gl++, G_AC_NONE);
    gDPSetTexturePersp(gl++, G_TP_NONE);
    gDPSetTextureFilter(gl++, G_TF_BILERP);
    gDPSetTextureConvert(gl++, G_TC_FILT);
    gDPSetTextureDetail(gl++, G_TD_CLAMP);
    gDPSetTextureLOD(gl++, G_TL_TILE);
    gDPSetTextureLUT(gl++, G_TT_NONE);

#define SPRITE_SURF G_RM_TEX_EDGE
#define SPRITE_SURF2 G_RM_TEX_EDGE2

    gDPSetRenderMode(gl++, SPRITE_SURF, SPRITE_SURF2);
    *glistp = gl;
}


// uvSpriteDraw
#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvsprt_rom/func_uvsprt_rom_00402540.s")

// uvSpriteFinish
void func_uvsprt_rom_004032A0(Gfx **glistp) {
    Gfx *gl;

    gl = *glistp;

    /* Turn off texturing */
    gSPTexture(gl++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_OFF);
    gDPSetCombineMode(gl++, G_CC_SHADE, G_CC_SHADE);

    if (sSpriteAttribute & SP_TRANSPARENT) {
        /* Turn off transparency */
        gDPSetRenderMode(gl++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    }

    if (sSpriteAttribute & SP_CUTOUT) {
        /* Turn off Alpha write enable */
        gDPSetAlphaCompare(gl++, G_AC_NONE);
    }

    gSPEndDisplayList(gl++);

    *glistp = gl;
}
