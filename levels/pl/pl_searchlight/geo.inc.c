#include "src/game/envfx_snow.h"

const GeoLayout pl_searchlight_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 0, 0, 158, pl_searchlight_001_object_00C4977C_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 158, pl_searchlight_002_object_00C4956C_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
