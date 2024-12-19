#include "src/game/envfx_snow.h"

const GeoLayout gf_gake_c_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, gf_gake_c_gf_gake_c_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 509, 5000, -1809, 0, 7, 0, gf_gake_c_001_object_00C65070_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, gf_gake_c_001_object_00C65070_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT, 305, 4976, -2088, 0, -60, 0, gf_gake_c_002_object_00C64A00_mesh_layer_5),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT, 714, 4990, -36, 0, -174, 0, gf_gake_c_003_object_00C64300_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
