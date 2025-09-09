#include "src/game/envfx_snow.h"

const GeoLayout ow2_sh_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(LAYER_PCL, geo_update_alpha_compare),
		GEO_DISPLAY_LIST(LAYER_PCL, ow2_sh_000_object_00A898F8_021_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
