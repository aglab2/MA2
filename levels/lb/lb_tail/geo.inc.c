#include "src/game/envfx_snow.h"

const GeoLayout lb_tail_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(LAYER_PCL, geo_update_alpha_compare),
		GEO_DISPLAY_LIST(LAYER_PCL, lb_tail_tail_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
