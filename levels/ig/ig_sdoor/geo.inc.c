#include "src/game/envfx_snow.h"

const GeoLayout ig_sdoor_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ig_sdoor_object_007FB16C_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, ig_sdoor_object_007FB16C_002_mesh_layer_2),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
