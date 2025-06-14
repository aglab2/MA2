#include "src/game/envfx_snow.h"

const GeoLayout cc_goaldoor_hit_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cc_goaldoor_hit_001_object_0054E5CC_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cc_goaldoor_hit_002_object_0054DE7C_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, cc_goaldoor_hit_003_object_0054B8CC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
