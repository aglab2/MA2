#include "src/game/envfx_snow.h"

const GeoLayout pl_roll_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_OBJ_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 0,0,0, 0,0,0, pl_roll_pl_roll_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, pl_roll_001_object_00C3B014_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
