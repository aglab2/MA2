#include "src/game/envfx_snow.h"

const GeoLayout fc_meteoc_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, fc_meteoc_fc_meteoc_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
