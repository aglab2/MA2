#include "flipbook.h"

static struct FlipbookData flipbooks_xlu[] = {
    // { LVL_BATCH_LAYER_TRANSPARENT_PC_DL_KD_PC_BAKU1_PAL_RGBA16, 0, 0, .tileScrollX = 16 },
    { LVL_BATCH_LAYER_TRANSPARENT_PC_DL_KD_PC_MON3_PAL_RGBA16, 0, 0, .shading = 1 },
};

const struct FlipbookLayer pc_flipbooks[LAYER_COUNT] = {
    [ LAYER_TRANSPARENT ] = FLIPBOOK_LAYER_DECL(flipbooks_xlu),
};
