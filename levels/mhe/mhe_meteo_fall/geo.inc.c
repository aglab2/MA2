#include "src/game/envfx_snow.h"

const GeoLayout mhe_meteo_fall_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, mhe_meteo_fall_mhe_meteo_fall_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
