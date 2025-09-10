#include "src/game/envfx_snow.h"

const GeoLayout ow2_sr_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(LAYER_PCL, geo_update_alpha_compare),
		GEO_ASM(LAYER_TRANSPARENT, geo_update_alpha_compare),
		GEO_DISPLAY_LIST(LAYER_PCL, ow2_sr_0136_object_00B06AE4_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ow2_sr_0136_object_00B06AE4_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
