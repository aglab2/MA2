// 0x16000E14
extern const Gfx ow_dl_billboard_num_0[];
extern const Gfx ow_dl_billboard_num_1[];
extern const Gfx ow_dl_billboard_num_2[];
extern const Gfx ow_dl_billboard_num_3[];
extern const Gfx ow_dl_billboard_num_4[];
extern const Gfx ow_dl_billboard_num_5[];
extern const Gfx ow_dl_billboard_num_6[];
extern const Gfx ow_dl_billboard_num_7[];
extern const Gfx ow_dl_billboard_num_8[];
extern const Gfx ow_dl_billboard_num_9[];
extern const Gfx ow_dl_billboard_num_percent[];

extern const Gfx ow_dl_billboard_num_C[];
extern const Gfx ow_dl_billboard_num_L[];
extern const Gfx ow_dl_billboard_num_E[];
extern const Gfx ow_dl_billboard_num_A[];
extern const Gfx ow_dl_billboard_num_R[];
extern const Gfx ow_dl_billboard_num_O[];
extern const Gfx ow_dl_billboard_num_U[];
extern const Gfx ow_dl_billboard_num_S[];

const GeoLayout ow_number_geo[] = {
    GEO_NODE_START(),
    GEO_OPEN_NODE(),
       GEO_ASM(LAYER_OCCLUDE_SILHOUETTE_ALPHA, geo_update_alpha_compare),
       GEO_SWITCH_CASE(11, geo_switch_anim_state),
       GEO_OPEN_NODE(),
          GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, ow_dl_billboard_num_0),
          GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, ow_dl_billboard_num_1),
          GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, ow_dl_billboard_num_2),
          GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, ow_dl_billboard_num_3),
          GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, ow_dl_billboard_num_4),
          GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, ow_dl_billboard_num_5),
          GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, ow_dl_billboard_num_6),
          GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, ow_dl_billboard_num_7),
          GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, ow_dl_billboard_num_8),
          GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, ow_dl_billboard_num_9),
          GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, ow_dl_billboard_num_percent),
       GEO_CLOSE_NODE(),
    GEO_CLOSE_NODE(),
    GEO_END(),
 };

const GeoLayout ow_clear_geo[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_ASM(LAYER_OCCLUDE_SILHOUETTE_ALPHA, geo_update_alpha_compare),
      GEO_TRANSLATE_NODE_WITH_DL(LAYER_OCCLUDE_SILHOUETTE_ALPHA, -100, 0, 0, ow_dl_billboard_num_C),
      GEO_TRANSLATE_NODE_WITH_DL(LAYER_OCCLUDE_SILHOUETTE_ALPHA, -50, 0, 0, ow_dl_billboard_num_L),
      GEO_TRANSLATE_NODE_WITH_DL(LAYER_OCCLUDE_SILHOUETTE_ALPHA,   0, 0, 0, ow_dl_billboard_num_E),
      GEO_TRANSLATE_NODE_WITH_DL(LAYER_OCCLUDE_SILHOUETTE_ALPHA,  50, 0, 0, ow_dl_billboard_num_A),
      GEO_TRANSLATE_NODE_WITH_DL(LAYER_OCCLUDE_SILHOUETTE_ALPHA, 100, 0, 0, ow_dl_billboard_num_R),

      GEO_TRANSLATE_NODE_WITH_DL(LAYER_OCCLUDE_SILHOUETTE_ALPHA,  -125, -70, 0, ow_dl_billboard_num_C),
      GEO_TRANSLATE_NODE_WITH_DL(LAYER_OCCLUDE_SILHOUETTE_ALPHA,   -75, -70, 0, ow_dl_billboard_num_O),
      GEO_TRANSLATE_NODE_WITH_DL(LAYER_OCCLUDE_SILHOUETTE_ALPHA,   -25, -70, 0, ow_dl_billboard_num_U),
      GEO_TRANSLATE_NODE_WITH_DL(LAYER_OCCLUDE_SILHOUETTE_ALPHA,    25, -70, 0, ow_dl_billboard_num_R),
      GEO_TRANSLATE_NODE_WITH_DL(LAYER_OCCLUDE_SILHOUETTE_ALPHA,    75, -70, 0, ow_dl_billboard_num_S),
      GEO_TRANSLATE_NODE_WITH_DL(LAYER_OCCLUDE_SILHOUETTE_ALPHA,   125, -70, 0, ow_dl_billboard_num_E),

      GEO_CLOSE_NODE(),
   GEO_END(),
};
