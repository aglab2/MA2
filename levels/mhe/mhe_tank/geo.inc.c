#include "src/game/envfx_snow.h"

const GeoLayout mhe_tank_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, mhe_tank_mhe_tank_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mhe_tank_mhe_tank_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
