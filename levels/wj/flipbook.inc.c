#include "flipbook.h"

static ALIGNED8 u8 wb_waters_ci4[] = {
    #include "levels/wj/tx_whiterain001.ci4.inc.c"
    #include "levels/wj/tx_whiterain002.ci4.inc.c"
    #include "levels/wj/tx_whiterain003.ci4.inc.c"
    #include "levels/wj/tx_whiterain004.ci4.inc.c"
    #include "levels/wj/tx_whiterain005.ci4.inc.c"
    #include "levels/wj/tx_whiterain006.ci4.inc.c"
    #include "levels/wj/tx_whiterain007.ci4.inc.c"
    #include "levels/wj/tx_whiterain008.ci4.inc.c"
    #include "levels/wj/tx_whiterain009.ci4.inc.c"
    #include "levels/wj/tx_whiterain010.ci4.inc.c"
};

static ALIGNED8 u8 wb_waters_pal[] = {
    #include "levels/wj/tx_whiterain001.ci4.pal"
    #include "levels/wj/tx_whiterain002.ci4.pal"
    #include "levels/wj/tx_whiterain003.ci4.pal"
    #include "levels/wj/tx_whiterain004.ci4.pal"
    #include "levels/wj/tx_whiterain005.ci4.pal"
    #include "levels/wj/tx_whiterain006.ci4.pal"
    #include "levels/wj/tx_whiterain007.ci4.pal"
    #include "levels/wj/tx_whiterain008.ci4.pal"
    #include "levels/wj/tx_whiterain009.ci4.pal"
    #include "levels/wj/tx_whiterain010.ci4.pal"
};

static struct FlipbookData flipbooks_xlu[] = {
    { LVL_BATCH_LAYER_TRANSPARENT_WJ_DL_TX_WHITERAIN001_PAL_RGBA16, .tileScrollX = 1 },
    { LVL_BATCH_LAYER_TRANSPARENT_WJ_DL_MIU128_WJ001_RGBA32, .tileScrollX = 5 },
};

const struct FlipbookLayer wj_flipbooks[LAYER_COUNT] = {
    [ LAYER_TRANSPARENT ] = FLIPBOOK_LAYER_DECL(flipbooks_xlu),
};
