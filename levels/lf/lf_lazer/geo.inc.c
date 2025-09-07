#include "src/game/envfx_snow.h"

const GeoLayout lf_lazer_geo[] = {
	GEO_CULLING_RADIUS(30000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lf_lazer_001_object_0130597C_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lf_lazer_002_object_01305504_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lf_lazer_003_object_01304DE4_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
