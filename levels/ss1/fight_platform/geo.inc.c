#include "src/game/envfx_snow.h"

const GeoLayout fight_platform_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_9_VERTS, 0x9B, 600),
	GEO_OPEN_NODE(),
		GEO_ASM(LAYER_PCL, geo_update_alpha_compare),
		GEO_DISPLAY_LIST(LAYER_PCL, fight_platform_spiner_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
