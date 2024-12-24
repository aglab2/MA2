#include "src/game/envfx_snow.h"

const GeoLayout hb_wall_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hb_wall_hb_wall_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
