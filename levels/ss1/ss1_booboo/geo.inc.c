#include "src/game/envfx_snow.h"

const GeoLayout ss1_booboo_geo[] = {
	GEO_CULLING_RADIUS(30000),
	GEO_OPEN_NODE(),
		GEO_ASM(LAYER_PCL, geo_update_alpha_compare),
		GEO_DISPLAY_LIST(LAYER_PCL, ss1_booboo_attach_00C0DCCC_002_mesh_layer_1),
		GEO_ASM(LAYER_TRANSPARENT, geo_update_alpha_compare),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ss1_booboo_attach_00C0DCCC_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
