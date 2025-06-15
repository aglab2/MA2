#include "src/game/envfx_snow.h"

const GeoLayout cct_shutter_right_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cct_shutter_right_cc_shutter_right_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, (s16)-102.5, (s16)74.99999523162842, (s16)151.0000228881836, cct_shutter_right_007_object_01241A54_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
