#include "src/game/envfx_snow.h"
#include "actors/purple_switch/geo_header.h"

extern Gfx *geo_update_primcolor(s32 callContext, struct GraphNode *node, UNUSED void *context);
const GeoLayout purple_switch_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(LAYER_OPAQUE, geo_update_primcolor),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, purple_switch_purple_switch_mesh_layer_1),
		GEO_OBJ_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 0,0,0, 0,0,0, purple_switch_001_object_0071765C_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
