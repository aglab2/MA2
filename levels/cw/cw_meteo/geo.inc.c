#include "src/game/envfx_snow.h"

const GeoLayout cw_meteo_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cw_meteo_cw_meteo_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
