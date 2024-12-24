#include "src/game/envfx_snow.h"

const GeoLayout hb_block_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hb_block_hb_block_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
