#include "src/game/envfx_snow.h"

const GeoLayout ow_cg_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ow_cg_ow_cg_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
