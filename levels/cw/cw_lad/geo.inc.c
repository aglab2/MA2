#include "src/game/envfx_snow.h"

extern Gfx *geo_cw_lad_rotate(s32 callContext, struct GraphNode *node, UNUSED s32 context);
const GeoLayout cw_lad_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH(LAYER_OPAQUE, cw_dl_000_object_00AC0D10_014_mesh_layer_1),
		GEO_ASM(0, geo_cw_lad_rotate),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 0, 0, (f32)-4.5990091965273835e-05, (f32)0, (f32)-3.232971362524833e-05, cw_dl_001_object_00AC0330_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
