#include "src/game/envfx_snow.h"

extern Gfx *geo_update_alpha_compare(s32 callContext, struct GraphNode *node, UNUSED void *context);
const GeoLayout lb_sparkle_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(LAYER_TRANSPARENT, geo_update_alpha_compare),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lb_sparkle_sparkle_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
