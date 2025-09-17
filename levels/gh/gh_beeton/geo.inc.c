#include "src/game/envfx_snow.h"

const GeoLayout gh_beeton_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, gh_beeton_gh_beeton_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, (s16)0.0, (s16)0.0, (s16)-35.99994659423828, gh_beeton_001_object_00540104_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, (s16)-10.0, (s16)40.0, (s16)5.0, gh_beeton_002_object_0053FD04_mesh_layer_5),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, gh_beeton_002_object_0053FD04_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, (s16)10.0, (s16)40.0, (s16)5.0, gh_beeton_003_object_0053FBD4_mesh_layer_5),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, gh_beeton_003_object_0053FBD4_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, (s16)0.0, (s16)0.0, (s16)39.00001525878906, gh_beeton_004_object_0053FAA4_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
