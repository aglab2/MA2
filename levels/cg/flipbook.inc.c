#include "flipbook.h"

ALIGNED8 u8 cg_matrixs_ci4[] = {
    #include "levels/cg/tx_light001.ci4.inc.c"
    #include "levels/cg/tx_light002.ci4.inc.c"
    #include "levels/cg/tx_light003.ci4.inc.c"
    #include "levels/cg/tx_light004.ci4.inc.c"
    #include "levels/cg/tx_light005.ci4.inc.c"
};

ALIGNED8 u8 cg_matrixs_pal[] = {
    #include "levels/cg/tx_light001.ci4.pal"
    #include "levels/cg/tx_light002.ci4.pal"
    #include "levels/cg/tx_light003.ci4.pal"
    #include "levels/cg/tx_light004.ci4.pal"
    #include "levels/cg/tx_light005.ci4.pal"
};

static struct FlipbookData flipbooks_opaque[] = {
    { LVL_BATCH_LAYER_OPAQUE_CG_DL_OBJLANDTABLE0022_UV_SA2LVL_0_F3D, 5, 10, -5, 0, cg_matrixs_ci4, cg_matrixs_pal },
};

const struct FlipbookLayer cg_flipbooks[LAYER_COUNT] = {
    [ LAYER_OPAQUE ] = FLIPBOOK_LAYER_DECL(flipbooks_opaque),
};
