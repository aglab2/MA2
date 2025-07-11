#include "src/game/envfx_snow.h"

const GeoLayout ss1_space_geo[] = {
	GEO_CULLING_RADIUS(30000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ss1_space_object_012539D4_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ss1_space_object_012539D4_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
