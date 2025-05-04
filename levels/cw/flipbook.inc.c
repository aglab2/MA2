static struct FlipbookData flipbooks_opaque[] = {
    { LVL_BATCH_LAYER_OPAQUE_CW_DL_SPACE64_4_PAL_RGBA16, .tileScrollX=2 },
    { LVL_BATCH_LAYER_OPAQUE_CW_DL_SPACE64_8_PAL_RGBA16, .tileScrollX=2 },
};

const struct FlipbookLayer cw_flipbooks[LAYER_COUNT] = {
    [ LAYER_OPAQUE ] = FLIPBOOK_LAYER_DECL(flipbooks_opaque),
};
