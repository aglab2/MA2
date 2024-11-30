#include "src/game/envfx_snow.h"

const GeoLayout wc_rock_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wc_rock_wc_rock_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
