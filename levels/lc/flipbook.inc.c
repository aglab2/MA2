#include "flipbook.h"

ALIGNED8 u8 lc_poisons_ci4[] = {
    #include "levels/lc/tx_poison001.ci4.inc.c"
    #include "levels/lc/tx_poison002.ci4.inc.c"
    #include "levels/lc/tx_poison003.ci4.inc.c"
    #include "levels/lc/tx_poison004.ci4.inc.c"
    #include "levels/lc/tx_poison005.ci4.inc.c"
    #include "levels/lc/tx_poison006.ci4.inc.c"
    #include "levels/lc/tx_poison007.ci4.inc.c"
    #include "levels/lc/tx_poison008.ci4.inc.c"
    #include "levels/lc/tx_poison009.ci4.inc.c"
    #include "levels/lc/tx_poison010.ci4.inc.c"
    #include "levels/lc/tx_poison011.ci4.inc.c"
    #include "levels/lc/tx_poison012.ci4.inc.c"
    #include "levels/lc/tx_poison013.ci4.inc.c"
};

ALIGNED8 u8 lc_poisons_pal[] = {
    #include "levels/lc/tx_poison001.ci4.pal"
    #include "levels/lc/tx_poison002.ci4.pal"
    #include "levels/lc/tx_poison003.ci4.pal"
    #include "levels/lc/tx_poison004.ci4.pal"
    #include "levels/lc/tx_poison005.ci4.pal"
    #include "levels/lc/tx_poison006.ci4.pal"
    #include "levels/lc/tx_poison007.ci4.pal"
    #include "levels/lc/tx_poison008.ci4.pal"
    #include "levels/lc/tx_poison009.ci4.pal"
    #include "levels/lc/tx_poison010.ci4.pal"
    #include "levels/lc/tx_poison011.ci4.pal"
    #include "levels/lc/tx_poison012.ci4.pal"
    #include "levels/lc/tx_poison013.ci4.pal"
};

static struct FlipbookData flipbooks_opaque[] = {
    { LVL_BATCH_LAYER_OPAQUE_LC_DL_MIU256_LC001_PAL_RGBA16_1, .shading = 1 },
    { LVL_BATCH_LAYER_OPAQUE_LC_DL_MIU256_LC001_PAL_RGBA16_2, .shading = 1 },
};

static struct FlipbookData flipbooks_xlu[] = {
    { LVL_BATCH_LAYER_TRANSPARENT_LC_DL_TX_POISON001_PAL_RGBA16, 13, 2, 0, 0, 0, lc_poisons_ci4, lc_poisons_pal },
};

const struct FlipbookLayer lc_flipbooks[LAYER_COUNT] = {
    [ LAYER_OPAQUE ] = FLIPBOOK_LAYER_DECL(flipbooks_opaque),
    [ LAYER_TRANSPARENT ] = FLIPBOOK_LAYER_DECL(flipbooks_xlu),
};
