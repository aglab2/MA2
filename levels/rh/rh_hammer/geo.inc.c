#include "src/game/envfx_snow.h"

const GeoLayout rh_hammer_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rh_hammer_rh_hammer_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, rh_hammer_001_object_011742F0_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
