static ALIGNED8 u8 danger_ci4[] = {
    #include "levels/mhe/tx_danger001.ci4.inc.c"
    #include "levels/mhe/tx_danger002.ci4.inc.c"
    #include "levels/mhe/tx_danger003.ci4.inc.c"
    #include "levels/mhe/tx_danger004.ci4.inc.c"
    #include "levels/mhe/tx_danger005.ci4.inc.c"
    #include "levels/mhe/tx_danger006.ci4.inc.c"
    #include "levels/mhe/tx_danger007.ci4.inc.c"
    #include "levels/mhe/tx_danger008.ci4.inc.c"
    #include "levels/mhe/tx_danger009.ci4.inc.c"
    #include "levels/mhe/tx_danger010.ci4.inc.c"
    #include "levels/mhe/tx_danger011.ci4.inc.c"
    #include "levels/mhe/tx_danger012.ci4.inc.c"
    #include "levels/mhe/tx_danger013.ci4.inc.c"
};

static ALIGNED8 u8 danger_pal[] = {
    #include "levels/mhe/tx_danger001.ci4.pal"
    #include "levels/mhe/tx_danger002.ci4.pal"
    #include "levels/mhe/tx_danger003.ci4.pal"
    #include "levels/mhe/tx_danger004.ci4.pal"
    #include "levels/mhe/tx_danger005.ci4.pal"
    #include "levels/mhe/tx_danger006.ci4.pal"
    #include "levels/mhe/tx_danger007.ci4.pal"
    #include "levels/mhe/tx_danger008.ci4.pal"
    #include "levels/mhe/tx_danger009.ci4.pal"
    #include "levels/mhe/tx_danger010.ci4.pal"
    #include "levels/mhe/tx_danger011.ci4.pal"
    #include "levels/mhe/tx_danger012.ci4.pal"
    #include "levels/mhe/tx_danger013.ci4.pal"
};


static struct FlipbookData flipbooks_opaque[] = {
    { LVL_BATCH_LAYER_OPAQUE_MHE_DL_SPACE64_6_001_PAL_RGBA16, 0, 0, 0, 0, 0x1, NULL, NULL },
    { LVL_BATCH_LAYER_OPAQUE_MHE_DL_SPACE64_20_001_PAL_RGBA16, 0, 0, 0, 0, 0x1, NULL, NULL },
    { LVL_BATCH_LAYER_OPAQUE_MHE_DL_SPACE32_3_001_PAL_RGBA16, 0, 0, 0, 0, 0x8000, NULL, NULL },
    { LVL_BATCH_LAYER_OPAQUE_MHE_DL_TX_DANGER001_PAL_RGBA16, 13, 2, 0, 0, 0, danger_ci4, danger_pal },
};

const struct FlipbookLayer mhe_flipbooks[LAYER_COUNT] = {
    [ LAYER_OPAQUE ] = FLIPBOOK_LAYER_DECL(flipbooks_opaque),
};
