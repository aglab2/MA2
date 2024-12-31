#include "src/game/envfx_snow.h"

const GeoLayout ee_hatch_b_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ee_hatch_b_ee_laststep_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, (s16)-107.5, (s16)-40.0, (s16)0.0, ee_hatch_b_001_object_0057ED04_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, (s16)107.5, (s16)-40.0, (s16)0.0, ee_hatch_b_002_object_0057E698_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
