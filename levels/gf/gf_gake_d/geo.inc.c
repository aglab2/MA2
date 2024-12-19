#include "src/game/envfx_snow.h"

const GeoLayout gf_gake_d_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, gf_gake_d_gf_gake_d_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -80, 4995, -42, 15, -92, 0, gf_gake_d_001_object_00C67B28_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, gf_gake_d_001_object_00C67B28_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT, 674, 4990, -856, 0, 116, 0, gf_gake_d_002_object_00C66FF8_mesh_layer_5),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT, 55, 4990, -2438, -50, -29, 0, gf_gake_d_003_object_00C66828_mesh_layer_5),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 76, 5001, -363, 0, -14, 0, gf_gake_d_004_object_00C65FC0_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, gf_gake_d_004_object_00C65FC0_mesh_layer_5),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
