#include "src/game/envfx_snow.h"

const GeoLayout ow2_lock_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(LAYER_TRANSPARENT, geo_update_alpha_compare),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ow2_lock_ow2_lock_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
