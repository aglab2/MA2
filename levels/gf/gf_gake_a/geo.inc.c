#include "src/game/envfx_snow.h"

const GeoLayout gf_gake_a_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, gf_gake_a_gf_gake_a_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 885, 5000, -1019, 11, 120, 7, gf_gake_a_001_object_00C60498_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, gf_gake_a_001_object_00C60498_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -495, 5001, -51, gf_gake_a_002_object_00C5F968_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, gf_gake_a_002_object_00C5F968_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 526, 5001, -2173, 0, -121, 0, gf_gake_a_003_object_00C5ED60_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, gf_gake_a_003_object_00C5ED60_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT, 145, 4990, -2278, -50, 35, 0, gf_gake_a_004_object_00C5E2E0_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
