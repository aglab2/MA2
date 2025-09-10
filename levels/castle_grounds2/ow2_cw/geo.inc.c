#include "src/game/envfx_snow.h"

const GeoLayout ow2_cw_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(LAYER_PCL, geo_update_alpha_compare),
		GEO_ASM(LAYER_TRANSPARENT, geo_update_alpha_compare),
		GEO_DISPLAY_LIST(LAYER_PCL, ow2_cw_000_object_00AC4730_008_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ow2_cw_000_object_00AC4730_008_mesh_layer_5),
		GEO_ASM(LAYER_PCL, geo_update_alpha_compare),
		GEO_DISPLAY_LIST(LAYER_PCL, ow2_cw_000_object_00AC4730_008_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
