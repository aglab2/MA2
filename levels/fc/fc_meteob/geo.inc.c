#include "src/game/envfx_snow.h"

const GeoLayout fc_meteob_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, fc_meteob_fc_meteob_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
