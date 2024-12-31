#include "src/game/envfx_snow.h"

const GeoLayout ee_capsule_inside_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, (s16)0.0, (s16)95.0, (s16)0.0, ee_capsule_inside_001_object_0059EDA8_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, (s16)0.0, (s16)-95.0, (s16)0.0, ee_capsule_inside_002_object_0059E918_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
