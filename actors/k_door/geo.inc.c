#include "src/game/envfx_snow.h"

extern Gfx *geo_update_alpha_compare(s32 callContext, struct GraphNode *node, UNUSED void *context);
const GeoLayout k_door_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(LAYER_PCL, geo_update_alpha_compare),
		GEO_DISPLAY_LIST(LAYER_PCL, k_door_object_00714AF4_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
