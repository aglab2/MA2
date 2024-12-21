#include "src/game/envfx_snow.h"

const GeoLayout rocket_launcher_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rocket_launcher_000_object_0073B3C4_mesh_layer_1),
		GEO_OBJ_ROCKET_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 19, -42, rocket_launcher_001_object_0073ACFC_mesh_layer_1),
		GEO_OBJ_ROCKET_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 19, 42, rocket_launcher_002_object_0073ABB4_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
