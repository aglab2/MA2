#include "src/game/envfx_snow.h"

const GeoLayout ow_wc_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(LAYER_TRANSPARENT, geo_update_alpha_compare),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ow_wc_ow_wc_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
