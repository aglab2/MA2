#include "src/game/envfx_snow.h"

const GeoLayout mhe_bigshutter_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, mhe_bigshutter_mhe_bigshutter_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, (s16)650.0, (s16)-65.0, (s16)-9.000000318337698e-05, mhe_bigshutter_008_object_00D4A770_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mhe_bigshutter_008_object_00D4A770_mesh_layer_5),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
