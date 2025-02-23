#include "src/game/envfx_snow.h"

const GeoLayout ce_car4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ce_car4_ce_car4_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, (s16)0.0, (s16)329.9999952316284, (s16)-1350.0, ce_car4_001_object_00CAFD20_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, (s16)0.0, (s16)329.9999952316284, (s16)1587.5, ce_car4_002_object_00CAFB68_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
