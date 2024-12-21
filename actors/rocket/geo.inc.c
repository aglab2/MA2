#include "src/game/envfx_snow.h"

const GeoLayout rocket_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rocket_rocket_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 0, 31, 0, 0, 0, 90, rocket_001_object_00739824_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 23, -7, 0, 0, 0, 90, rocket_002_object_0073948C_mesh_layer_1),

		GEO_OBJ_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 0, -5, 0, 0, 0, 110, rocket_003_object_007392C4_mesh_layer_1),

		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -8, 50, 9, 17, -2, 84, rocket_005_object_00738E0C_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -8, 50, -9, 0, 0, 90, rocket_006_object_00738844_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 9, 50, 9, -163, 2, -96, rocket_007_object_00738284_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 9, 50, -9, 163, -2, -96, rocket_008_object_00737CAC_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
