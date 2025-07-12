#include "src/game/envfx_snow.h"

const GeoLayout ss1_golem_geo[] = {
	GEO_CULLING_RADIUS(30000),
	GEO_OPEN_NODE(),
		GEO_ASM(LAYER_PCL, geo_update_alpha_compare),
		GEO_DISPLAY_LIST(LAYER_PCL, ss1_golem_0013_object_01C41A50_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
