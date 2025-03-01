#include "src/game/envfx_snow.h"

const GeoLayout pl_tank_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, pl_tank_pl_tank_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, pl_tank_pl_tank_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, pl_tank_001_object_00C41030_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, pl_tank_001_object_00C41030_mesh_layer_2),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
