#include "src/game/envfx_snow.h"

const GeoLayout ms_buffer_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ms_buffer_ms_buffer_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
