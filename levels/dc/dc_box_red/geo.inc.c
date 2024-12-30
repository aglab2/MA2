#include "src/game/envfx_snow.h"

const GeoLayout dc_box_red_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, dc_box_red_dc_box_red_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, dc_box_red_dc_box_red_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
