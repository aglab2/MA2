#include "src/game/envfx_snow.h"

const GeoLayout wb_shuts_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wb_shuts_wb_shuts_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
