#include "src/game/envfx_snow.h"

const GeoLayout cct_shutter_left_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, (s16)-185.0, (s16)300.0, (s16)119.99999046325684, cct_shutter_left_001_object_012432C4_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, (s16)-185.0, (s16)300.0, (s16)120.0, cct_shutter_left_002_object_0124316C_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, (s16)-185.0, (s16)300.0, (s16)119.99999046325684, cct_shutter_left_004_object_01242574_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, (s16)-499.99969482421875, (s16)0.0, (s16)0.0, cct_shutter_left_005_object_012424B4_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
