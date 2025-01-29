#include "src/game/envfx_snow.h"

extern Gfx *geo_update_primcolor(s32 callContext, struct GraphNode *node, UNUSED void *context);
const GeoLayout checkpoint_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(LAYER_OPAQUE, geo_update_primcolor),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, checkpoint_000_object_0071CBF4_mesh_layer_1),
		GEO_OBJ_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, (s16)150.0 , (s16)95.00001907348633, (s16)0.0, 0, 0   , 0, checkpoint_001_object_0071BD34_mesh_layer_1),
		GEO_OBJ_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, (s16)-150.0, (s16)95.00001907348633, (s16)0.0, 0, -180, 0, checkpoint_002_object_0071B57C_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
