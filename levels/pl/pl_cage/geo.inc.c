#include "src/game/envfx_snow.h"

const GeoLayout pl_cage_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, pl_cage_pl_cage_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, pl_cage_001_object_00C44E28_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
