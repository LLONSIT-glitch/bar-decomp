#include "uv_clocks.h"
#include "macros.h"

extern u32 D_8002D940;
extern s32 D_8002D944;
extern uvClockState_t D_8002D948[];
extern uvClockState_t D_8002D960[];

/* Need to make these one arrays because the compiler doesn't want to put them before the stubbed string */
static const f64 D_80021030[1] = {93.875101696};
static const f64 D_80021038[1] = {45751932.2845432162};

uvClockState_t* uvGetClock(s32 clk_id) {
    if (clk_id >= 100) {
        return &D_8002D960[clk_id - 100];
    }
    if (clk_id >= 3) {
        return NULL;
    }
    return &D_8002D948[clk_id];
}

void uvClkInit(void) {
    D_8002D940 = osGetCount();
    D_8002D944 = 0;
}

void uvClkUpdate(void) {
    u32 count;

    count = osGetCount();
    if (((u32) D_8002D940 >= 0xF0000001U) && (count < 0x10000000U)) {
        D_8002D944 += 1;
    }
    D_8002D940 = count;
}

f64 uvClkGetSec(s32 clk_id) {
    uvClockState_t* clock;
    f64 var_fv1;
    f64 var_fa0;
 
    clock = uvGetClock(clk_id);
    if (clock == NULL) {
        // _uvDebugPrintf("uvClkGetSec: unknown clock %d\n", clk_id);
        return 0.0;
    }
    uvClkUpdate();
    var_fv1 = D_8002D944 - clock->unk0;
    var_fv1 *= D_80021030[0];
    var_fa0 = ((f64)D_8002D940 - clock->unk4) / D_80021038[0];
    return var_fv1 + var_fa0;
}

void uvClkReset(s32 clk_id) {
    uvClockState_t* clock;

    uvClkUpdate();
    clock = uvGetClock(clk_id);
    if (clock != NULL) {
        clock->unk4 = D_8002D940;
        clock->unk0 = D_8002D944;
    } else {
        PRINTF("Null free head\n");
    }
}
