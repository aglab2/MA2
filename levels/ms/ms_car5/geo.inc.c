#include "src/game/envfx_snow.h"

const GeoLayout ms_car5_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ms_car5_ms_car5_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ms_car5_ms_car5_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, (s16)0.0, (s16)444.9999809265137, (s16)-1489.9999618530273, ms_car5_001_object_00CB2EDC_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, (s16)0.0, (s16)444.9999809265137, (s16)1549.995231628418, ms_car5_002_object_00CB2D00_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
