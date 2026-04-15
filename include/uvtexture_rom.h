#ifndef UVTEXTURE_ROM_H
#define UVTEXTURE_ROM_H
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

typedef struct {
    u8 pad0[0x2];
    s16 bmfmt;
    s16 bitdepth;
    s16 width;
    s16 height;
    s16 unkA;
    s16 texelHeight;
    s16 nbitmaps;
    void *buf;
    Bitmap *bitmap;
} ParsedUVBT;
#endif /* UVTEXTURE_ROM_H */
