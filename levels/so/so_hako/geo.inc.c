#include "src/game/envfx_snow.h"

const GeoLayout so_hako_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, so_hako_so_hako_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
