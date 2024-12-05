#include "src/game/envfx_snow.h"

const GeoLayout pl_elv_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, pl_elv_pl_elv_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, pl_elv_001_object_00C37A54_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, pl_elv_001_object_00C37A54_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, pl_elv_002_object_00C37278_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, pl_elv_002_object_00C37278_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
