#include "src/game/envfx_snow.h"

const GeoLayout end_block_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, end_block_Circle_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_ALPHA, end_block_Circle_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
