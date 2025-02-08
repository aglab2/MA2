#include "src/game/envfx_snow.h"

const GeoLayout aq_milift_geo[] = {
	GEO_CULLING_RADIUS(30000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, aq_milift_aq_milift_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
