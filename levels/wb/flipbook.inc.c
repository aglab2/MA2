#include "flipbook.h"

static ALIGNED8 u8 wb_waters_ci4[] = {
    #include "levels/wb/tx_sea001.ci4.inc.c"
    #include "levels/wb/tx_sea002.ci4.inc.c"
    #include "levels/wb/tx_sea003.ci4.inc.c"
    #include "levels/wb/tx_sea004.ci4.inc.c"
    #include "levels/wb/tx_sea005.ci4.inc.c"
    #include "levels/wb/tx_sea006.ci4.inc.c"
    #include "levels/wb/tx_sea007.ci4.inc.c"
    #include "levels/wb/tx_sea008.ci4.inc.c"
    #include "levels/wb/tx_sea009.ci4.inc.c"
    #include "levels/wb/tx_sea010.ci4.inc.c"
    #include "levels/wb/tx_sea011.ci4.inc.c"
    #include "levels/wb/tx_sea012.ci4.inc.c"
    #include "levels/wb/tx_sea013.ci4.inc.c"
    #include "levels/wb/tx_sea014.ci4.inc.c"
    #include "levels/wb/tx_sea015.ci4.inc.c"
    #include "levels/wb/tx_sea016.ci4.inc.c"
    #include "levels/wb/tx_sea017.ci4.inc.c"
    #include "levels/wb/tx_sea018.ci4.inc.c"
    #include "levels/wb/tx_sea019.ci4.inc.c"
    #include "levels/wb/tx_sea020.ci4.inc.c"
};

static ALIGNED8 u8 wb_waters_pal[] = {
    #include "levels/wb/tx_sea001.ci4.pal"
    #include "levels/wb/tx_sea002.ci4.pal"
    #include "levels/wb/tx_sea003.ci4.pal"
    #include "levels/wb/tx_sea004.ci4.pal"
    #include "levels/wb/tx_sea005.ci4.pal"
    #include "levels/wb/tx_sea006.ci4.pal"
    #include "levels/wb/tx_sea007.ci4.pal"
    #include "levels/wb/tx_sea008.ci4.pal"
    #include "levels/wb/tx_sea009.ci4.pal"
    #include "levels/wb/tx_sea010.ci4.pal"
    #include "levels/wb/tx_sea011.ci4.pal"
    #include "levels/wb/tx_sea012.ci4.pal"
    #include "levels/wb/tx_sea013.ci4.pal"
    #include "levels/wb/tx_sea014.ci4.pal"
    #include "levels/wb/tx_sea015.ci4.pal"
    #include "levels/wb/tx_sea016.ci4.pal"
    #include "levels/wb/tx_sea017.ci4.pal"
    #include "levels/wb/tx_sea018.ci4.pal"
    #include "levels/wb/tx_sea019.ci4.pal"
    #include "levels/wb/tx_sea020.ci4.pal"
};

static struct FlipbookData flipbooks_xlu[] = {
    { LVL_BATCH_LAYER_TRANSPARENT_WB_DL_TX_SEA001_PAL_RGBA16, 20, 2, 0, 0, 0, wb_waters_ci4, wb_waters_pal },
};

const struct FlipbookLayer wb_flipbooks[LAYER_COUNT] = {
    [ LAYER_TRANSPARENT ] = FLIPBOOK_LAYER_DECL(flipbooks_xlu),
};
