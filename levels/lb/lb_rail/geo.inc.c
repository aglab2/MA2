#include "src/game/envfx_snow.h"

const GeoLayout lb_rail_geo[] = {
	GEO_CULLING_RADIUS(30000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lb_rail_attach_00FCA364_004_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
