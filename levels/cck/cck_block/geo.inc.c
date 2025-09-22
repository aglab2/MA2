#include "src/game/envfx_snow.h"

extern Gfx *geo_update_primcolor(s32 callContext, struct GraphNode *node, UNUSED void *context);
extern Gfx *geo_update_primcolor_inv(s32 callContext, struct GraphNode *node, UNUSED void *context);
const GeoLayout cck_block_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(LAYER_TRANSPARENT, geo_update_primcolor),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, cck_block_001_object_0124541C_mesh_layer_5),
		GEO_ASM(LAYER_TRANSPARENT, geo_update_primcolor_inv),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, cck_block_002_object_0124512C_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cck_block_003_object_01244E3C_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
