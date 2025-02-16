static struct FlipbookData flipbooks_opaque[] = {
    { LVL_BATCH_LAYER_OPAQUE_MHE_DL_SPACE64_6_001_PAL_RGBA16, 0, 0, 0, 0, 0x1 },
    { LVL_BATCH_LAYER_OPAQUE_MHE_DL_SPACE64_20_001_PAL_RGBA16, 0, 0, 0, 0, 0x1 },
    { LVL_BATCH_LAYER_OPAQUE_MHE_DL_SPACE32_3_001_PAL_RGBA16, 0, 0, 0, 0, 0x8000 },
};

const struct FlipbookLayer mhe_flipbooks[LAYER_COUNT] = {
    [ LAYER_OPAQUE ] = FLIPBOOK_LAYER_DECL(flipbooks_opaque),
};
