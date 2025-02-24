#include "src/game/envfx_snow.h"

const GeoLayout ow_fr_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(LAYER_ALPHA, geo_update_alpha_compare),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ow_fr_ow_fr_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
