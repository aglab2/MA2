static ALIGNED8 u8 danger_ci4[] = {
    #include "levels/mhe/tx_danger001.ci4.inc.c"
    #include "levels/mhe/tx_danger002.ci4.inc.c"
    #include "levels/mhe/tx_danger003.ci4.inc.c"
    #include "levels/mhe/tx_danger004.ci4.inc.c"
};

static ALIGNED8 u8 danger_pal[] = {
    #include "levels/mhe/tx_danger001.ci4.pal"
    #include "levels/mhe/tx_danger002.ci4.pal"
    #include "levels/mhe/tx_danger003.ci4.pal"
    #include "levels/mhe/tx_danger004.ci4.pal"
};


static struct FlipbookData flipbooks_opaque[] = {
    { LVL_BATCH_LAYER_OPAQUE_MSP_DL_SPACE64_14_PAL_RGBA16, .tileScrollY = 2, },
    { LVL_BATCH_LAYER_OPAQUE_MSP_DL_SPACE64_20_PAL_RGBA16, .shading = 1 },
    { LVL_BATCH_LAYER_OPAQUE_MSP_DL_SPACE64_6_PAL_RGBA16, .shading = 1, },
    { LVL_BATCH_LAYER_OPAQUE_MSP_DL_SPACE64_20_PAL_RGBA16_1, .shading = 1 },
    { LVL_BATCH_LAYER_OPAQUE_MSP_DL_SPACE64_20_PAL_RGBA16_2, .shading = 1 },
    { LVL_BATCH_LAYER_OPAQUE_MSP_DL_SPACE32_3_PAL_RGBA16, .shading = 0x8000 },
    { LVL_BATCH_LAYER_OPAQUE_MSP_DL_MAD32_1_PAL_RGBA16, .tileScrollY = 3, },
    { LVL_BATCH_LAYER_OPAQUE_MSP_DL_MAD32_1_PAL_RGBA16_1, .tileScrollY = 3, },
    { LVL_BATCH_LAYER_OPAQUE_MSP_DL_MIU64_MAD014_PAL_RGBA16, 4, 4, .ci4s = danger_ci4, .pals = danger_pal }
};

const struct FlipbookLayer msp_flipbooks[LAYER_COUNT] = {
    [ LAYER_OPAQUE ] = FLIPBOOK_LAYER_DECL(flipbooks_opaque),
};
