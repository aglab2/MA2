#include "src/game/envfx_snow.h"

const GeoLayout pc_keydoor_blue_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, pc_keydoor_blue_pc_keydoor_blue_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, pc_keydoor_blue_pc_keydoor_blue_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
