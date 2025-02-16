#include "src/game/envfx_snow.h"

const GeoLayout mhe_meteoshut_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, mhe_meteoshut_mhe_meteoshut_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, (s16)0.0, (s16)400.00118255615234, (s16)0.000152587890625, mhe_meteoshut_001_object_00D44468_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, (s16)0.0, (s16)399.9996566772461, (s16)5.0, mhe_meteoshut_002_object_00D43FCC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
