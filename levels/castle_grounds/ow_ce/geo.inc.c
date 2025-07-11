#include "src/game/envfx_snow.h"

extern Gfx *geo_update_alpha_compare(s32 callContext, struct GraphNode *node, UNUSED void *context);
const GeoLayout ow_ce_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(LAYER_TRANSPARENT_DECAL, geo_update_alpha_compare),
		GEO_ASM(LAYER_PCL, geo_update_alpha_compare),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, ow_ce_ow_ce_mesh_layer_2),
		GEO_DISPLAY_LIST(LAYER_PCL, ow_ce_ow_ce_mesh_layer_1),
		// GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ow_ce_ow_ce_mesh_layer_5),
		// GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ow_ce_ow_ce_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
