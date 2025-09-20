#include "src/game/envfx_snow.h"

const GeoLayout k_door_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, k_door_object_00714AF4_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
