#include "src/game/envfx_snow.h"

const GeoLayout ce_car3_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ce_car3_ce_car3_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, (s16)0.0, (s16)320.0000047683716, (s16)-1480.000114440918, ce_car3_001_object_00CB635C_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, (s16)0.0, (s16)320.0000047683716, (s16)1325.0, ce_car3_002_object_00CB6180_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
