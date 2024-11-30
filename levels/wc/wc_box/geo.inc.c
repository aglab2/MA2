#include "src/game/envfx_snow.h"

const GeoLayout wc_box_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wc_box_wc_box_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wc_box_wc_box_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
