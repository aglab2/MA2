#include "src/game/envfx_snow.h"

const GeoLayout ow_ph_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(LAYER_ALPHA, geo_update_alpha_compare),
		GEO_ASM(LAYER_TRANSPARENT, geo_update_alpha_compare),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ow_ph_ow_ph_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ow_ph_ow_ph_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
