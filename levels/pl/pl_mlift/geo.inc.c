#include "src/game/envfx_snow.h"

const GeoLayout pl_mlift_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, pl_mlift_pl_mlift_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 30, 0, pl_mlift_001_object_00C3BF9C_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
