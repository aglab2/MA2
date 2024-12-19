#include "src/game/envfx_snow.h"

const GeoLayout gf_gake_e_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, gf_gake_e_gf_gake_e_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 856, 5001, -1494, 0, 93, 0, gf_gake_e_001_object_00C6AA60_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, gf_gake_e_001_object_00C6AA60_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT, 614, 4990, -2166, 0, 116, 0, gf_gake_e_002_object_00C69E58_mesh_layer_5),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 576, 5001, -183, 0, 76, 0, gf_gake_e_003_object_00C69688_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, gf_gake_e_003_object_00C69688_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 780, 4995, -292, 13, 107, 7, gf_gake_e_004_object_00C68C08_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, gf_gake_e_004_object_00C68C08_mesh_layer_5),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
