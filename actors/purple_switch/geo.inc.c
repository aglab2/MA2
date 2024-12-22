#include "src/game/envfx_snow.h"
#include "actors/purple_switch/geo_header.h"

const GeoLayout purple_switch_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, purple_switch_purple_switch_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, purple_switch_001_object_0071765C_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
