#include "flipbook.h"

static ALIGNED8 u8 mh_waters_ci4[] = {
    #include "levels/mh/tx_sea001.ci4.inc.c"
    #include "levels/mh/tx_sea002.ci4.inc.c"
    #include "levels/mh/tx_sea003.ci4.inc.c"
    #include "levels/mh/tx_sea004.ci4.inc.c"
    #include "levels/mh/tx_sea005.ci4.inc.c"
    #include "levels/mh/tx_sea006.ci4.inc.c"
    #include "levels/mh/tx_sea007.ci4.inc.c"
    #include "levels/mh/tx_sea008.ci4.inc.c"
    #include "levels/mh/tx_sea009.ci4.inc.c"
    #include "levels/mh/tx_sea010.ci4.inc.c"
    #include "levels/mh/tx_sea011.ci4.inc.c"
    #include "levels/mh/tx_sea012.ci4.inc.c"
    #include "levels/mh/tx_sea013.ci4.inc.c"
    #include "levels/mh/tx_sea014.ci4.inc.c"
    #include "levels/mh/tx_sea015.ci4.inc.c"
    #include "levels/mh/tx_sea016.ci4.inc.c"
    #include "levels/mh/tx_sea017.ci4.inc.c"
    #include "levels/mh/tx_sea018.ci4.inc.c"
    #include "levels/mh/tx_sea019.ci4.inc.c"
    #include "levels/mh/tx_sea020.ci4.inc.c"
};

static ALIGNED8 u8 mh_waters_pal[] = {
    #include "levels/mh/tx_sea001.ci4.pal"
    #include "levels/mh/tx_sea002.ci4.pal"
    #include "levels/mh/tx_sea003.ci4.pal"
    #include "levels/mh/tx_sea004.ci4.pal"
    #include "levels/mh/tx_sea005.ci4.pal"
    #include "levels/mh/tx_sea006.ci4.pal"
    #include "levels/mh/tx_sea007.ci4.pal"
    #include "levels/mh/tx_sea008.ci4.pal"
    #include "levels/mh/tx_sea009.ci4.pal"
    #include "levels/mh/tx_sea010.ci4.pal"
    #include "levels/mh/tx_sea011.ci4.pal"
    #include "levels/mh/tx_sea012.ci4.pal"
    #include "levels/mh/tx_sea013.ci4.pal"
    #include "levels/mh/tx_sea014.ci4.pal"
    #include "levels/mh/tx_sea015.ci4.pal"
    #include "levels/mh/tx_sea016.ci4.pal"
    #include "levels/mh/tx_sea017.ci4.pal"
    #include "levels/mh/tx_sea018.ci4.pal"
    #include "levels/mh/tx_sea019.ci4.pal"
    #include "levels/mh/tx_sea020.ci4.pal"
};

static struct FlipbookData flipbooks_xlu[] = {
    { LVL_BATCH_LAYER_TRANSPARENT_MH_DL_TX_SEA001_CI4_PAL_RGBA16, 20, 2, 0, 0, 0, mh_waters_ci4, mh_waters_pal },
};

const struct FlipbookLayer mh_flipbooks[LAYER_COUNT] = {
    [ LAYER_TRANSPARENT ] = FLIPBOOK_LAYER_DECL(flipbooks_xlu),
};
