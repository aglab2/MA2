// 0x17000084

extern Gfx *geo_update_layer_smoke(s32 callContext, struct GraphNode *node, UNUSED void *context);
const GeoLayout burn_smoke_geo[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_BATCH_ASM(0, geo_update_layer_smoke),
      GEO_SWITCH_CASE(2, geo_switch_anim_state),
      GEO_OPEN_NODE(),
         GEO_BATCH_DISPLAY_LIST(LAYER_TRANSPARENT, LAYER_TRANSPARENT_SMOKE, burn_smoke_seg4_dl),
         GEO_BATCH_DISPLAY_LIST(LAYER_ALPHA, LAYER_ALPHA_SMOKE, burn_smoke_seg4_dl),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};
