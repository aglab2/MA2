#include "src/game/envfx_snow.h"

const GeoLayout pl_searchlight_bottom_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, pl_searchlight_bottom_pl_searchlight_bottom_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
