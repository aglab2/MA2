#include "src/game/envfx_snow.h"

const GeoLayout checkpoint_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, checkpoint_000_object_0071CBF4_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 150, 95, 0, checkpoint_001_object_0071BD34_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -150, 95, 0, 0, -180, 0, checkpoint_002_object_0071B57C_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
