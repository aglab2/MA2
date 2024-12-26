#include "src/game/envfx_snow.h"

const GeoLayout pc_door_g_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, pc_door_g_pc_door_g_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
