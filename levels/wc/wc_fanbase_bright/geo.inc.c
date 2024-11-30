#include "src/game/envfx_snow.h"

const GeoLayout wc_fanbase_bright_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wc_fanbase_bright_wc_fanbase_bright_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wc_fanbase_bright_wc_fanbase_bright_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
