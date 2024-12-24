#include "src/game/envfx_snow.h"

const GeoLayout hb_updown_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hb_updown_hb_updown_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
