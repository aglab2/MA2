#include "flipbook.h"

static ALIGNED8 u8 waters_ci4[] = {
    #include "levels/gf/tx_jungle001.ci4.inc.c"
    #include "levels/gf/tx_jungle002.ci4.inc.c"
    #include "levels/gf/tx_jungle003.ci4.inc.c"
    #include "levels/gf/tx_jungle004.ci4.inc.c"
    #include "levels/gf/tx_jungle005.ci4.inc.c"
    #include "levels/gf/tx_jungle006.ci4.inc.c"
    #include "levels/gf/tx_jungle007.ci4.inc.c"
    #include "levels/gf/tx_jungle008.ci4.inc.c"
    #include "levels/gf/tx_jungle009.ci4.inc.c"
    #include "levels/gf/tx_jungle010.ci4.inc.c"
    #include "levels/gf/tx_jungle011.ci4.inc.c"
    #include "levels/gf/tx_jungle012.ci4.inc.c"
    #include "levels/gf/tx_jungle013.ci4.inc.c"
    #include "levels/gf/tx_jungle014.ci4.inc.c"
};

static ALIGNED8 u8 waters_pal[] = {
    #include "levels/gf/tx_jungle001.ci4.pal"
    #include "levels/gf/tx_jungle002.ci4.pal"
    #include "levels/gf/tx_jungle003.ci4.pal"
    #include "levels/gf/tx_jungle004.ci4.pal"
    #include "levels/gf/tx_jungle005.ci4.pal"
    #include "levels/gf/tx_jungle006.ci4.pal"
    #include "levels/gf/tx_jungle007.ci4.pal"
    #include "levels/gf/tx_jungle008.ci4.pal"
    #include "levels/gf/tx_jungle009.ci4.pal"
    #include "levels/gf/tx_jungle010.ci4.pal"
    #include "levels/gf/tx_jungle011.ci4.pal"
    #include "levels/gf/tx_jungle012.ci4.pal"
    #include "levels/gf/tx_jungle013.ci4.pal"
    #include "levels/gf/tx_jungle014.ci4.pal"
};

static struct FlipbookData flipbooks_xlu[] = {
    { LVL_BATCH_LAYER_TRANSPARENT_GF_DL_TX_JUNGLE001_PAL_RGBA16, 14, 2, 0, 0, waters_ci4, waters_pal },
};

const struct FlipbookLayer gf_flipbooks[LAYER_COUNT] = {
    [ LAYER_TRANSPARENT ] = FLIPBOOK_LAYER_DECL(flipbooks_xlu),
};
