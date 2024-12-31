#include "src/game/envfx_snow.h"

const GeoLayout ee_capsule_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ee_capsule_ee_capsule_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, (s16)0.0, (s16)-250.0, (s16)0.0, ee_capsule_001_object_0059C3E0_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, (s16)0.000152587890625, (s16)70.0, (s16)1.9073486328125e-05, ee_capsule_002_object_0059BE68_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, (s16)0.0, (s16)250.0, (s16)0.0, ee_capsule_003_object_0059BCF8_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, (s16)0.00030517578125, (s16)-70.0, (s16)3.814697265625e-05, ee_capsule_004_object_0059B780_mesh_layer_1),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
