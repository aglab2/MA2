#include "flipbook.h"

static struct FlipbookData flipbooks_opa[] = {
    { LVL_BATCH_LAYER_OPAQUE_DC_DL_KD_DC_YUKA4_PAL_RGBA16, 0, 0, 0, 0, FLIPBOOK_PRIM_COLOR_SHADING_DECL(0x8000) },
};

static struct FlipbookData flipbooks_xlu[] = {
    { LVL_BATCH_LAYER_TRANSPARENT_DC_DL_KD_DC_HASIRA92_PAL_RGBA16, 0, 0, 0, 0, FLIPBOOK_PRIM_COLOR_SHADING_DECL(0) },
};

const struct FlipbookLayer dc_flipbooks[LAYER_COUNT] = {
    // [ LAYER_TRANSPARENT ] = FLIPBOOK_LAYER_DECL(flipbooks_xlu),
    // [ LAYER_OPAQUE ] = FLIPBOOK_LAYER_DECL(flipbooks_opa),
};
