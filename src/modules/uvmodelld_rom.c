// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "uvasset_types.h"


void func_uvmodelld_rom_0040006C(void);
ParsedUVMD *uvParseUVMD(u8 *arg0);
void func_uvmodelld_rom_00400158(Gfx *arg0, u16 arg1, u16 arg2);
ParsedUVMD *_uvParseUVMD(u8 *arg0);
void func_uvmodelld_rom_00400D38(ParsedUVMD *arg0);
void __entrypoint_func_uvmodelld_rom_400000(UvModelLd_Exports *exports);

// .data
s32 D_uvmodelld_rom_00400ED0[] = {0x000C0000, __entrypoint_func_uvmodelld_rom_400000, 0, 0};

// .bss
static UvLights_Exports *sUvLightsExports;
static UvFMtx_Rom_Exports *sUvFMtxExports;

void __entrypoint_func_uvmodelld_rom_400000(UvModelLd_Exports* exports) {
    uvUpdateFileAllocPtr(exports);
    exports->uvParseUVMD = uvParseUVMD;
    exports->func_uvmodelld_rom_0040006C = func_uvmodelld_rom_0040006C;
    exports->func_uvmodelld_rom_00400D38 = func_uvmodelld_rom_00400D38;
#ifdef __sgi
    #line 22
#endif
    sUvLightsExports = uvLoadModule('LGHT');
    // ! unused export
    sUvFMtxExports = uvLoadModule('FMTX');
}

void func_uvmodelld_rom_0040006C(void) {
    uvUnloadModule('FMTX');
    uvUnloadModule('LGHT');
}

// uvParseUVMD
ParsedUVMD *uvParseUVMD(u8 *arg0) {
    s32 fileId;
    s32 parsedUvModel;
    u32 blockSize;
    void *blockData;
    u32 tag;
    s32 ptr;

    parsedUvModel = 0;
    fileId = uvFileReadHeader(arg0);
    tag = uvFileReadBlock(fileId, &blockSize, &blockData, 1);
    while (tag != 0) {
        switch (tag) {
            case 'COMM':
                ptr = blockData;
                parsedUvModel = _uvParseUVMD(ptr);
                _uvMemFree(ptr);
                break;
            default:
                break;
        }

        tag = uvFileReadBlock(fileId, &blockSize, &blockData, 1);
    }
    uvFileFree(fileId);
    return parsedUvModel;
}

void func_uvmodelld_rom_00400158(Gfx *arg0, u16 arg1, u16 arg2) {
    // clang-format off
    if (arg2) { \
        arg0->words.w0 = (((((arg1 & 0x7C00) >> 0xA) * 2) & 0xFF) << 0x10) \
                  | (((((arg1 & 0x3E0) >> 5) * 2) & 0xFF) << 8) | (((arg1 & 0x1F) * 2) & 0xFF) \
                  | 0x06000000; \
        arg0->words.w1 = ((((((arg2 & 0x7C00) >> 0xA) * 2) & 0xFF) << 0x10) \
                   | (((((arg2 & 0x3E0) >> 5) * 2) & 0xFF) << 8) | (((arg2 & 0x1F) * 2) & 0xFF)); \
    } else {
        arg0->words.w0 = (((((arg1 & 0x7C00) >> 0xA) * 2) & 0xFF) << 0x10)
                  | (((((arg1 & 0x3E0) >> 5) * 2) & 0xFF) << 8) | (((arg1 & 0x1F) * 2) & 0xFF)
                  | 0x05000000;
        arg0->words.w1 = 0;
    }
    // clang-format on
}


ParsedUVMD *_uvParseUVMD(u8 *arg0) {
    s16 sp14E;
    s32 sp148;
    s32 sp144;
    s32 sp140;
    s32 var_s4;
    ParsedUVMD_1 *sp70;
    ParsedUVMD *sp134;
    Vtx *var_s7;
    s32 temp_v1;
    uvGfxState *var_a0;
    char pad[0xC];
    UnkStruct_uvlight_rom_00401758 spE8;
    u16 spE6;
    u16 spE4;
    u16 spE2;
    u16 spE0;
    u16 var_s2;
    u8 spDD;
    u8 spDC;
    s32 spD8;
    uvModelLOD *temp_s3;
    u8 *spD0;
    u8 *spCC;
    u32 spC8;
    s32 spC4;
    ParsedUVMD spA0;
    Gfx *temp_s3_2;
    s32 tmp2;
    u8 *assetsStart;
    u8 sp93;
    u8 sp92;
    s32 tmp1;

    uvConsumeBytes(&spA0.unk4, &arg0, sizeof(u8));
    uvConsumeBytes(&spA0.unk6, &arg0, sizeof(u8));
    uvConsumeBytes(&spA0.unk5, &arg0, sizeof(u8));
    uvConsumeBytes(&spA0.unk7, &arg0, sizeof(u8));
    uvConsumeBytes(&spA0.vtxCount, &arg0, sizeof(u16));
    uvConsumeBytes(&spE2, &arg0, sizeof(u16));
    uvConsumeBytes(&spE4, &arg0, sizeof(u16));
    if (spA0.unk5 & 0x80) {
        spA0.unk20 = _uvMemAllocAlign8(sizeof(ParsedUVMD_3C));
        uvConsumeBytes(&spA0.unk20->unk0, &arg0, sizeof(f32));
        uvConsumeBytes(&spA0.unk20->unk4, &arg0, sizeof(f32));
        uvConsumeBytes(&spA0.unk20->unk8, &arg0, sizeof(f32));
        uvConsumeBytes(&spA0.unk20->unkC, &arg0, sizeof(f32));
        uvConsumeBytes(&spA0.unk20->unk10, &arg0, sizeof(f32));
        uvConsumeBytes(&spA0.unk20->unk14, &arg0, sizeof(f32));
        uvConsumeBytes(&spA0.unk20->unk18, &arg0, sizeof(f32));
        uvConsumeBytes(&spA0.unk20->unk1C, &arg0, sizeof(f32));
        uvConsumeBytes(&spA0.unk20->unk20, &arg0, sizeof(s32));
        uvConsumeBytes(&spA0.unk20->unk24, &arg0, sizeof(s32));
        uvConsumeBytes(&sp14E, &arg0, sizeof(s16));
        spA0.unk20->unk2C = (s32) sp14E;
        uvConsumeBytes(&sp14E, &arg0, sizeof(s16));
        spA0.unk20->unk30 = (s32) sp14E;
        uvConsumeBytes(&sp14E, &arg0, sizeof(s16));
        spA0.unk20->unk34 = (s32) sp14E;
        uvConsumeBytes(&spA0.unk20->unk28, &arg0, sizeof(u8));
        if ((spA0.unk20->unk30 == -1) && (spA0.unk20->unk34 == -1) && (spA0.unk20->unk2C == -1)) {
            spA0.unk20->unk4 = 1000.0f;
        }
        spA0.unk20->unk0 *= 0.44704f;
        spA0.unk20->unk4 *= 0.44704f;
        spA0.unk20->unkC *= 0.44704f;
        spA0.unk20->unk10 *= 0.44704f;
        spA0.unk20->unk18 *= 0.01745329f;
        spA0.unk20->unk1C *= 0.0390419f;
        spA0.unk20->unk38 = 0;
        if (spA0.unk20->unk2C != -1) {
            uvLoadFile('UVMD', spA0.unk20->unk2C);
        }
        if (spA0.unk20->unk30 != -1) {
            uvLoadFile('UVMD', spA0.unk20->unk30);
        }
        if (spA0.unk20->unk34 != -1) {
            uvLoadFile('UVPX', spA0.unk20->unk34);
        }
    } else {
        spA0.unk20 = NULL;
    }
    uvConsumeBytes(&spA0.unkC, &arg0, sizeof(f32));
    uvConsumeBytes(&spA0.unk10, &arg0, sizeof(f32));
    uvConsumeBytes(&spA0.unk14, &arg0, sizeof(f32));

    /* ASSET PACKAGE STRUCTURE

        assetsStart - asset block start

        var_s7 (Vtx table)
        uvGfxState + Gfx (Interleaved?)
        ParsedUVMD
        ParsedUVMD_1s
        uvModelLODs
        Mtx4Fs
    */

    tmp2 = spA0.vtxCount * sizeof(Vtx);
    temp_v1 = spA0.unk4 * sizeof(ParsedUVMD_1);
    temp_s3_2 = spA0.unk6 * sizeof(Mtx4F);
    spC4 = tmp2 + (spE4 * sizeof(Gfx)) + (spE2 * sizeof(uvGfxState));
    var_s4 = spC4 + (u32)temp_s3_2 + temp_v1 + (spA0.unk4 * spA0.unk6 * sizeof(uvModelLOD));
    spC8 = var_s4 + sizeof(ParsedUVMD);
    assetsStart = _uvMemAlloc(spC8, 8);
    if (var_s4) {
    }
    if (temp_v1) {
    }
    if (temp_s3_2) {
    }
    spD0 = assetsStart + spC4;
    spCC = assetsStart;
    spD0 += sizeof(ParsedUVMD);

    if (spA0.unk6) {
    }

    sp134 = (void*)(assetsStart + spC4);
    spC8 -= sizeof(ParsedUVMD);
    *sp134 = spA0;

    spCC += tmp2;
    spC8 -= tmp2;
    spC4 -= tmp2;

    sp134->vtxTable = (Vtx*)assetsStart;
    spD8 = 0;

    var_s7 = (Vtx*)assetsStart;

    temp_s3_2 = (Gfx*)spD0;
    spC8 -= temp_v1;
    spD0 += temp_v1;
    sp70 = sp134->unk0 = temp_s3_2;
    for (sp148 = 0; sp148 < sp134->unk4; sp148++) {
        uvConsumeBytes(&sp70[sp148].unk8, &arg0, sizeof(u8));
        uvConsumeBytes(&sp70[sp148].unk9, &arg0, sizeof(u8));
        uvConsumeBytes(&sp70[sp148].unk4, &arg0, sizeof(f32));
        sp70[sp148].unk4 = SQ(sp70[sp148].unk4);
        // clang-format off
        temp_s3_2 = spD0;\
        spD0 += sp70[sp148].unk8 * 0x2C;\
        spC8 -= sp70[sp148].unk8 * 0x2C;
        // clang-format on
        temp_s3 = sp70[sp148].unk0 = temp_s3_2;
        for (sp144 = 0; sp144 < sp70[sp148].unk8; sp144++) {
            spDC = 0;
            uvConsumeBytes(&temp_s3[sp144].unk5, &arg0, sizeof(u8));
            uvConsumeBytes(&temp_s3[sp144].unk6, &arg0, sizeof(u8));
            uvConsumeBytes(&temp_s3[sp144].unk7, &arg0, sizeof(u8));
            uvConsumeBytes(&temp_s3[sp144].unk8, &arg0, sizeof(uvModelLOD_inner));
            temp_s3[sp144].unk8.unk0 *= sp134->unk10;
            temp_s3[sp144].unk8.unkC *= sp134->unk10;
            temp_s3[sp144].unk8.unk4 *= sp134->unk10;
            temp_s3[sp144].unk8.unk10 *= sp134->unk10;
            temp_s3[sp144].unk8.unk8 *= sp134->unk10;
            temp_s3[sp144].unk8.unk14 *= sp134->unk10;
            uvConsumeBytes(&sp93, &arg0, 1);
            uvConsumeBytes(&sp92, &arg0, 1);
            uvConsumeBytes(&temp_s3[sp144].unk4, &arg0, 1);

            if (temp_s3[sp144].unk4 != 0) {
                // clang-format off
                spC8 -= temp_s3[sp144].unk4 * sizeof(uvGfxState); \
                spC4 -= temp_s3[sp144].unk4 * sizeof(uvGfxState);
                // clang-format on
                temp_s3[sp144].stateTable = var_a0 = (void*)spCC;
                spCC += temp_s3[sp144].unk4 * sizeof(uvGfxState);
            } else {
                temp_s3[sp144].stateTable = var_a0 = NULL;
            }

            for (sp140 = 0; sp140 < temp_s3[sp144].unk4; sp140++) {
                uvConsumeBytes(&var_a0[sp140].state, &arg0, sizeof(s32));
                uvConsumeBytes(&spE8.unk2C, &arg0, sizeof(s32));
                uvConsumeBytes(&spE8.unk28, &arg0, sizeof(s32));
                uvConsumeBytes(&spE8.unk24, &arg0, sizeof(s32));
                uvConsumeBytes(&var_a0[sp140].unkE, &arg0, sizeof(s16));
                uvConsumeBytes(&var_a0[sp140].unk12, &arg0, sizeof(s16));
                uvConsumeBytes(&var_a0[sp140].unk10, &arg0, sizeof(s16));
                uvConsumeBytes(&var_a0[sp140].unk14, &arg0, sizeof(s16));
                uvConsumeBytes(&spE6, &arg0, sizeof(u16));
                uvConsumeBytes(&spE4, &arg0, sizeof(u16));
                tmp1 = var_a0[sp140].state & 0xFFF;
                if (tmp1 != 0xFFF) {
                    uvLoadFile('UVTX', tmp1);
                }
                if (var_a0[sp140].state & 0x40000) {
                    // Different function?
                    var_a0[sp140].unkC = sUvLightsExports->func_uvlight_rom_00401340(&spE8);
                } else {
                    var_a0[sp140].unkC = -1;
                }
                if (var_a0[sp140].state & 0x08000000) {
                    spDC = 1;
                }
                var_a0[sp140].unk0 = (s32) var_s7;
                _uvMediaCopy(var_s7, arg0, var_a0[sp140].unkE * sizeof(Vtx));
                arg0 = arg0 + var_a0[sp140].unkE * sizeof(Vtx);
                spD8 += var_a0[sp140].unkE;
                temp_s3_2 = (void*)spCC;
                // clang-format off
                spC8 -= spE4 * sizeof(Gfx); \
                spC4 -= spE4 * sizeof(Gfx);
                // clang-format on
                spCC += spE4 * sizeof(Gfx);
                var_a0[sp140].displayList = PHYSICAL_TO_K0(temp_s3_2);
                var_s2 = 0;
                for (var_s4 = 0, tmp2 = 0; var_s4 < spE6; var_s4++) {
                    uvConsumeBytes(&spE0, &arg0, sizeof(u16));
                    if (tmp2) {
                    }
                    if (spE0 & 0x8000) {
                        if (var_s2 == 0) {
                            var_s2 = spE0;
                        } else {
                            func_uvmodelld_rom_00400158(&temp_s3_2[tmp2], var_s2, spE0);
                            var_s2 = 0;
                            tmp2++;
                        }
                    } else {
                        if (var_s2 != 0) {
                            func_uvmodelld_rom_00400158(&temp_s3_2[tmp2], var_s2, 0);
                            var_s2 = 0;
                            tmp2++;
                        }
                        uvConsumeBytes(&spDD, &arg0, 1);
                        temp_v1 = ((s32) (spE0 & 0x6000) >> 0xA) | ((s32) (spDD & 0xE0) >> 5);
                        gSPVertex(&temp_s3_2[tmp2], PHYSICAL_TO_K0(var_s7 + ((spE0 & 0x1FFF))),
                                  temp_v1 + 1, spDD & 0x1F);
                        tmp2++;
                    }
                }
                var_s7 = &sp134->vtxTable[spD8];
                if (var_s2 != 0) {
                    func_uvmodelld_rom_00400158(&temp_s3_2[tmp2], var_s2, 0);
                    tmp2++;
                }
                gSPEndDisplayList(&temp_s3_2[tmp2]);
                tmp2++;
            }
            temp_s3[sp144].unk20 = spDC;
        }
    }
    sp134->unk8 = (void*)spD0;
    spC4 = sp134->unk6 * sizeof(Mtx4F);
    // FAKE u64 cast
    uvConsumeBytes((void *) (u64) sp134->unk8, &arg0, spC4);

    return sp134;
}

void func_uvmodelld_rom_00400D38(ParsedUVMD *arg0) {
    ParsedUVMD *sp6C;
    ParsedUVMD_1 *sp68;
    s32 j;
    s32 k;
    s32 i;
    uvGfxState *temp_s0;
    uvModelLOD *temp_s3;
    s32 uvtx;

    sp6C = arg0;
    for (i = 0; i < sp6C->unk4; i++) {
        sp68 = &sp6C->unk0[i];
        for (j = 0; j < sp68->unk8; j++) {
            temp_s3 = &sp68->unk0[j];
            for (k = 0; k < temp_s3->unk4; k++) {
                temp_s0 = &temp_s3->stateTable[k];
                uvtx = (temp_s0->state & 0xFFF);
                if (uvtx != 0xFFF) {
                    uvUnloadFile(0x55565458, uvtx);
                }
                if (temp_s0->unkC != -1) {
                    sUvLightsExports->func_uvlight_rom_00401624(temp_s0->unkC);
                }
            }
        }
    }

    _uvMemFree(sp6C->vtxTable);
}
