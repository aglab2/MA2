#include "src/game/envfx_snow.h"

extern Gfx *geo_update_alpha_compare(s32 callContext, struct GraphNode *node, UNUSED void *context);
const GeoLayout ss1_space_geo[] = {
	GEO_CULLING_RADIUS(30000),
	GEO_OPEN_NODE(),
		GEO_ASM(LAYER_PCL, geo_update_alpha_compare),
		GEO_DISPLAY_LIST(LAYER_PCL, ss1_space_object_012539D4_mesh_layer_1),
		GEO_ASM(LAYER_TRANSPARENT, geo_update_alpha_compare),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ss1_space_object_012539D4_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
