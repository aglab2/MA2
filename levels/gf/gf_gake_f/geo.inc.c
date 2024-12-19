#include "src/game/envfx_snow.h"

const GeoLayout gf_gake_f_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, gf_gake_f_gf_gake_f_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 718, 4995, -85, 0, -84, 0, gf_gake_f_001_object_00C6D700_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, gf_gake_f_001_object_00C6D700_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 246, 5001, -2163, 0, 119, 0, gf_gake_f_002_object_00C6CBD0_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, gf_gake_f_002_object_00C6CBD0_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT, 364, 4990, -776, 0, 176, 0, gf_gake_f_003_object_00C6C158_mesh_layer_5),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT, 125, 4990, -2268, -29, -136, -10, gf_gake_f_004_object_00C6B988_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
