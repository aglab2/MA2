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

ALIGNED8 u8 cg_poisons_ci4[] = {
    #include "levels/cg/tx_poison001.ci4.inc.c"
    #include "levels/cg/tx_poison002.ci4.inc.c"
    #include "levels/cg/tx_poison003.ci4.inc.c"
    #include "levels/cg/tx_poison004.ci4.inc.c"
    #include "levels/cg/tx_poison005.ci4.inc.c"
    #include "levels/cg/tx_poison006.ci4.inc.c"
    #include "levels/cg/tx_poison007.ci4.inc.c"
    #include "levels/cg/tx_poison008.ci4.inc.c"
    #include "levels/cg/tx_poison009.ci4.inc.c"
    #include "levels/cg/tx_poison010.ci4.inc.c"
    #include "levels/cg/tx_poison011.ci4.inc.c"
    #include "levels/cg/tx_poison012.ci4.inc.c"
    #include "levels/cg/tx_poison013.ci4.inc.c"
};

ALIGNED8 u8 cg_poisons_pal[] = {
    #include "levels/cg/tx_poison001.ci4.pal"
    #include "levels/cg/tx_poison002.ci4.pal"
    #include "levels/cg/tx_poison003.ci4.pal"
    #include "levels/cg/tx_poison004.ci4.pal"
    #include "levels/cg/tx_poison005.ci4.pal"
    #include "levels/cg/tx_poison006.ci4.pal"
    #include "levels/cg/tx_poison007.ci4.pal"
    #include "levels/cg/tx_poison008.ci4.pal"
    #include "levels/cg/tx_poison009.ci4.pal"
    #include "levels/cg/tx_poison010.ci4.pal"
    #include "levels/cg/tx_poison011.ci4.pal"
    #include "levels/cg/tx_poison012.ci4.pal"
    #include "levels/cg/tx_poison013.ci4.pal"
};

static struct FlipbookData flipbooks_opaque[] = {
    { LVL_BATCH_LAYER_OPAQUE_CG_DL_TX_LIGHT001_PAL_RGBA16, 5, 10, -5, 0, cg_matrixs_ci4, cg_matrixs_pal },
};

static struct FlipbookData flipbooks_xlu[] = {
    { LVL_BATCH_LAYER_TRANSPARENT_CG_DL_TX_POISON001_PAL_RGBA16  , 13, 2, 0, 0, cg_poisons_ci4, cg_poisons_pal },
    { LVL_BATCH_LAYER_TRANSPARENT_CG_DL_TX_POISON001_PAL_RGBA16_1, 13, 2, 0, 0, cg_poisons_ci4, cg_poisons_pal },
};

const struct FlipbookLayer cg_flipbooks[LAYER_COUNT] = {
    [ LAYER_OPAQUE ] = FLIPBOOK_LAYER_DECL(flipbooks_opaque),
    [ LAYER_TRANSPARENT ] = FLIPBOOK_LAYER_DECL(flipbooks_xlu),
};
