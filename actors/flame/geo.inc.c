// 0x16000B10
const GeoLayout red_flame_shadow_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0x50, 20),
   GEO_OPEN_NODE(),
      GEO_BRANCH_AND_LINK(red_flame_geo),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

extern const Gfx flame_seg3_dl_draw[];

// 0x16000B2C
const GeoLayout red_flame_geo[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_BATCH_DISPLAY_LIST_ANIM(LAYER_TRANSPARENT, LAYER_TRANSPARENT_RED_FLAMES_FIRST, flame_seg3_dl_draw, 8),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x16000B8C
const GeoLayout blue_flame_geo[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_BATCH_DISPLAY_LIST_ANIM(LAYER_TRANSPARENT, LAYER_TRANSPARENT_BLUE_FLAMES_FIRST, flame_seg3_dl_draw, 8),
   GEO_CLOSE_NODE(),
   GEO_END(),
};
