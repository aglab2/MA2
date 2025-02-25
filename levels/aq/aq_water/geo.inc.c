#include "src/game/envfx_snow.h"

const GeoLayout aq_water_geo[] = {
	GEO_CULLING_RADIUS(30000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, aq_water_aq_water_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
