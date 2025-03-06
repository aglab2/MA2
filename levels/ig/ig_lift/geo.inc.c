#include "src/game/envfx_snow.h"

const GeoLayout ig_lift_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ig_lift_ig_lift_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, (s16)0.0, (s16)30.0, (s16)0.0, ig_lift_001_object_007F05E8_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
