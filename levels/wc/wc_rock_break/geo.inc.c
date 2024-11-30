#include "src/game/envfx_snow.h"

const GeoLayout wc_rock_break_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -131, 0, -62, wc_rock_break_wc_rock_break1_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 97, -2, -102, wc_rock_break_wc_rock_break2_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -86, 0, 103, wc_rock_break_wc_rock_break3_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 101, 0, 80, wc_rock_break_wc_rock_break4_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wc_rock_break_wc_rock_break5_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 61, -112, wc_rock_break_wc_rock_break6_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 86, 110, wc_rock_break_wc_rock_break7_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 103, 86, -7, wc_rock_break_wc_rock_break8_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
