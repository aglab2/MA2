#include "src/game/envfx_snow.h"

extern Gfx *geo_update_transparency(s32 callContext, struct GraphNode *node, UNUSED void *context);
const GeoLayout lc_shutter_left_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(GEO_TRANSPARENCY_MODE_NORMAL, geo_update_transparency),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, (s16)-185.0, (s16)300.0, (s16)120.0, lc_shutter_left_001_object_00597510_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, (s16)-185.0, (s16)300.0, (s16)120.0, lc_shutter_left_002_object_00597380_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, (s16)-185.0, (s16)300.0, (s16)120.0, lc_shutter_left_004_object_00596348_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, (s16)-499.99969482421875, (s16)0.0, (s16)0.0, lc_shutter_left_005_object_00596238_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
