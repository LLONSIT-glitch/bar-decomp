#include "common.h"
#include "module.h"

// Todo replace these structs with the actual exports of uvcback_rom and uvgfxmgr_rom
typedef struct UnkStruct_00400764_s {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ void (*unk10)(s32, void (*)(s32), s32, s32); /* inferred */
    /* 0x14 */ void (*unk14)(s32, s32);
} UnkStruct_00400764;                               /* size = 0x18 */

typedef struct UnkStruct_00400760_s {
    /* 0x00 */ char pad0[8];
    /* 0x08 */ Gfx **(*unk8)(void);                    /* inferred */
    /* 0x0C */ char padC[4];
    /* 0x10 */ s32 (*unk10)(s32);
} UnkStruct_00400760;                               /* size = 0x14 */

extern UnkStruct_00400760 *D_00400760;
extern UnkStruct_00400764 *D_00400764;
extern void *D_00400774;
extern s32 D_00400750[];
extern s32 D_00400758[];
extern s32 D_00400754[];
extern s32 D_0040075C[];
extern s16 D_0040076A;
extern s16 D_0040076C;
extern s16 D_00400768;
extern Mtx* D_00400770[];

void __entrypoint_func_uvimtx_rom_400000(UvImtx_Rom_Exports *arg0);
void func_uvimtx_rom_0040018C(void);
void func_uvimtx_rom_0040020C(s32 arg0);
void func_uvimtx_rom_0040020C(s32 arg0);
void func_uvimtx_rom_00400250(Mtx *dst, Mtx src);
void func_uvimtx_rom_004002D8(Mtx *m);
void func_uvimtx_rom_00400324(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_uvimtx_rom_00400338(uvMtx *dst, uvMtx src);
void func_uvimtx_rom_00400410(Mtx mtx);
void func_uvimtx_rom_0040048C(void);
void func_uvimtx_rom_004004D8(Mtx mtx);
Mtx *func_uvimtx_rom_00400554(Mtx arg0, u16 arg16);
Mtx *func_uvimtx_rom_00400554(Mtx mtx, u16);
void func_uvimtx_rom_0040062C(Mtx *arg0, u16 arg1);
void func_uvimtx_rom_0040062C(Mtx *arg0, u16 arg1);
s32 func_uvimtx_rom_004006E0(s32 arg0);

void __entrypoint_func_uvimtx_rom_400000(UvImtx_Rom_Exports* arg0) {
    s16* temp_v0;

    uvSetFileDirOvlPtr((s32) arg0);
    arg0->func_uvimtx_rom_0040018C = func_uvimtx_rom_0040018C;
    arg0->func_uvimtx_rom_004006E0 = func_uvimtx_rom_004006E0;
    arg0->func_uvimtx_rom_00400250 = func_uvimtx_rom_00400250;
    arg0->func_uvimtx_rom_004002D8 = func_uvimtx_rom_004002D8;
    arg0->func_uvimtx_rom_00400324 = func_uvimtx_rom_00400324;
    arg0->func_uvimtx_rom_00400338 = func_uvimtx_rom_00400338;
    arg0->func_uvimtx_rom_00400410 = func_uvimtx_rom_00400410;
    arg0->func_uvimtx_rom_0040048C = func_uvimtx_rom_0040048C;
    arg0->func_uvimtx_rom_004004D8 = func_uvimtx_rom_004004D8;
    arg0->func_uvimtx_rom_00400554 = func_uvimtx_rom_00400554;
    arg0->func_uvimtx_rom_0040062C = func_uvimtx_rom_0040062C;
    temp_v0 = uvUnusedGetProp(8);
    if (temp_v0 == NULL) {
        D_00400768 = 0x64;
    } else {
        if (*temp_v0 != 0) {
            D_00400768 = *temp_v0;
        } else {
            D_00400768 = 0x64;
        }
    }
    D_00400760 = uvGetModuleExports(0x474D4752);
    D_00400764 = uvGetModuleExports(0x4342434B);

    // Create two 4x4 dynamic matrices
    *D_00400770 = _uvMemAlloc(D_00400768 * sizeof(Mtx), 4 * 4);
    D_00400774 = _uvMemAlloc(D_00400768 * sizeof(Mtx), 4 * 4);
    D_00400764->unk10(D_00400760->unk10(1), func_uvimtx_rom_0040020C, 0, 0);
}


void func_uvimtx_rom_0040018C(void) {
    _uvMemFree(D_00400770[0]);
    _uvMemFree(D_00400774);
    D_00400764->unk14(D_00400760->unk10(1), &func_uvimtx_rom_0040020C);
    func_80003760('GMGR');
    func_80003760('CBCK');
}

void func_uvimtx_rom_0040020C(s32 arg0) {
    D_0040076A ^= 1;
    D_00400750[D_0040076A] = 0;
    D_00400758[D_0040076A] = 0;
    D_0040076C = 0;
}

void func_uvimtx_rom_00400250(Mtx* dst, Mtx src) {
    dst->m[0][0] = src.m[0][0];
    dst->m[0][1] = src.m[0][1];
    dst->m[0][2] = src.m[0][2];
    dst->m[0][3] = src.m[0][3];
    dst->m[1][0] = src.m[1][0];
    dst->m[1][1] = src.m[1][1];
    dst->m[1][2] = src.m[1][2];
    dst->m[1][3] = src.m[1][3];
    dst->m[2][0] = src.m[2][0];
    dst->m[2][1] = src.m[2][1];
    dst->m[2][2] = src.m[2][2];
    dst->m[2][3] = src.m[2][3];
    dst->m[3][0] = src.m[3][0];
    dst->m[3][1] = src.m[3][1];
    dst->m[3][2] = src.m[3][2];
    dst->m[3][3] = src.m[3][3];
}

void func_uvimtx_rom_004002D8(Mtx* m) {
    m->m[0][0] = 0x10000;
    m->m[0][1] = 0;
    m->m[0][2] = 1;
    m->m[0][3] = 0;
    m->m[1][1] = 0x10000;
    m->m[1][0] = 0;
    m->m[1][3] = 1;
    m->m[1][2] = 0;
    m->m[2][0] = 0;
    m->m[2][1] = 0;
    m->m[2][2] = 0;
    m->m[2][3] = 0;
    m->m[3][0] = 0;
    m->m[3][1] = 0;
    m->m[3][2] = 0;
    m->m[3][3] = 0;
}

void func_uvimtx_rom_00400324(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {

}


void func_uvimtx_rom_00400338(uvMtx* dst, uvMtx src) {
    uvMtx* srcPtr = &src;
    uvMtx* dstPtr = dst;
    Mtx stack;
    
    if (dst == srcPtr) {
        dstPtr = (uvMtx*)&stack;
    }
    
    dstPtr->u.i[0][1] = src.u.i[1][0];
    dstPtr->u.i[0][2] = src.u.i[2][0];
    dstPtr->u.i[1][0] = src.u.i[0][1];
    dstPtr->u.i[1][2] = src.u.i[2][1];
    dstPtr->u.i[2][0] = src.u.i[0][2];
    dstPtr->u.i[2][1] = src.u.i[1][2];
    dstPtr->u.f[0][1] = src.u.f[1][0];
    dstPtr->u.f[0][2] = src.u.f[2][0];
    dstPtr->u.f[1][0] = src.u.f[0][1];
    dstPtr->u.f[1][2] = src.u.f[2][1];
    dstPtr->u.f[2][0] = src.u.f[0][2];
    dstPtr->u.f[2][1] = src.u.f[1][2];
    
    if (srcPtr == dstPtr) {
        func_uvimtx_rom_00400250((Mtx*)dst, stack);
    }
}

void func_uvimtx_rom_00400410(Mtx mtx) {
    func_uvimtx_rom_00400554(mtx, 2);
}

void func_uvimtx_rom_0040048C(void) {
    Gfx** gdlh;

    gdlh = D_00400760->unk8();

    gSPPopMatrix((*gdlh)++, G_MTX_MODELVIEW);
}

void func_uvimtx_rom_004004D8(Mtx mtx) {
    func_uvimtx_rom_00400554(mtx, 6);
}

Mtx* func_uvimtx_rom_00400554(Mtx arg0, u16 arg16) {
    Mtx* sp54;
    if (D_0040076C >= D_00400768) {
        return NULL;
    }

    sp54 = &D_00400770[D_0040076A][D_0040076C];
    func_uvimtx_rom_00400250(sp54, arg0);    
    D_0040076C++;    
    func_uvimtx_rom_0040062C(sp54, arg16);    
    return sp54;
}

void func_uvimtx_rom_0040062C(Mtx* arg0, u16 arg1) {
    Gfx** gdlh;

    gdlh = D_00400760->unk8();
    gSPMatrix(gdlh[0]++, VIRTUAL_TO_PHYSICAL2(arg0), arg1);
    if (!(arg1 & 2)) {
        D_00400758[D_0040076A]++;
    }
    D_00400750[D_0040076A]++;
}

s32 func_uvimtx_rom_004006E0(s32 arg0) {
    switch (arg0) {
    case 0:
        return D_00400754[0 - D_0040076A];
    case 1:
        return D_0040075C[0 - D_0040076A];
    default:
        return 0;
    }
}
