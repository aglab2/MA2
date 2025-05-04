static struct FlipbookData flipbooks_opaque[] = {
    { LVL_BATCH_LAYER_OPAQUE_CW_DL_SPACE64_4_PAL_RGBA16, .tileScrollX=2 },
    { LVL_BATCH_LAYER_OPAQUE_CW_DL_SPACE64_8_PAL_RGBA16, .tileScrollX=2 },
};

static struct FlipbookData flipbooks_alpha[] = {
    { LVL_BATCH_LAYER_ALPHA_CW_DL_MIU32_CW005_PAL_RGBA16, .tileScrollX=-4 },
};

const struct FlipbookLayer cw_flipbooks[LAYER_COUNT] = {
    [ LAYER_OPAQUE ] = FLIPBOOK_LAYER_DECL(flipbooks_opaque),
    [ LAYER_ALPHA  ] = FLIPBOOK_LAYER_DECL(flipbooks_alpha),
};
