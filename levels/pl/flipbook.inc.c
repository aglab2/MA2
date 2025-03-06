#include "flipbook.h"

static struct FlipbookData flipbooks_xlu[] = {
    { LVL_BATCH_LAYER_TRANSPARENT_PL_DL_MIU32_PL001_PAL_RGBA16, .shading = 1 },
};

const struct FlipbookLayer pl_flipbooks[LAYER_COUNT] = {
    [ LAYER_TRANSPARENT ] = FLIPBOOK_LAYER_DECL(flipbooks_xlu),
};
