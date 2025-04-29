#include "src/game/envfx_snow.h"

const GeoLayout msp_ore_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, msp_ore_msp_ore_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
