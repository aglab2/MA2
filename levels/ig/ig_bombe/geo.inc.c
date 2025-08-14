#include "src/game/envfx_snow.h"

extern Gfx *geo_ig_light(s32 callContext, struct GraphNode *node, UNUSED void *context);
const GeoLayout ig_bombe_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(LAYER_OPAQUE, geo_ig_light),
		GEO_ASM(LAYER_TRANSPARENT_DECAL, geo_ig_light),
		GEO_ASM(LAYER_ALPHA, geo_ig_light),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ig_bombe_ig_bombe_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, ig_bombe_ig_bombe_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ig_bombe_ig_bombe_mesh_layer_4),
		GEO_ASM(0x800 | LAYER_OPAQUE, geo_ig_light),
		GEO_ASM(0x800 | LAYER_TRANSPARENT_DECAL, geo_ig_light),
		GEO_ASM(0x800 | LAYER_ALPHA, geo_ig_light),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
