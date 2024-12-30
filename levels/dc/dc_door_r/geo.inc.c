#include "src/game/envfx_snow.h"

const GeoLayout dc_door_r_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, dc_door_r_dc_door_r_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
