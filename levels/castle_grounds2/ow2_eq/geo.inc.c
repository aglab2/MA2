#include "src/game/envfx_snow.h"

const GeoLayout ow2_eq_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(LAYER_PCL, geo_update_alpha_compare),
		GEO_ASM(LAYER_ALPHA, geo_update_alpha_compare),
		GEO_DISPLAY_LIST(LAYER_PCL, ow2_eq_object_0084BAEC_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ow2_eq_object_0084BAEC_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
