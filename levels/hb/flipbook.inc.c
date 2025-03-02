#include "flipbook.h"

static struct FlipbookData flipbooks_opa[] = {
    { LVL_BATCH_LAYER_OPAQUE_HB_DL_DZ_HB_RYUUSA_0001_PAL_RGBA16, 0, 0, .tileScrollX = 1 },
};

const struct FlipbookLayer hb_flipbooks[LAYER_COUNT] = {
    [ LAYER_OPAQUE ] = FLIPBOOK_LAYER_DECL(flipbooks_opa),
};
