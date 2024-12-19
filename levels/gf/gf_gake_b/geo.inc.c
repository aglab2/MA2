#include "src/game/envfx_snow.h"

const GeoLayout gf_gake_b_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, gf_gake_b_gf_gake_b_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 213, 5000, -731, 0, 167, 0, gf_gake_b_001_object_00C635A8_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, gf_gake_b_001_object_00C635A8_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT, 795, 4990, -58, -50, 30, 0, gf_gake_b_002_object_00C62F38_mesh_layer_5),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 394, 5001, -374, 0, -21, 0, gf_gake_b_003_object_00C626D0_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, gf_gake_b_003_object_00C626D0_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 226, 5001, -2183, 0, 51, 0, gf_gake_b_004_object_00C61C50_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, gf_gake_b_004_object_00C61C50_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT, 34, 4990, -1956, 0, -8, 0, gf_gake_b_005_object_00C611D0_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
