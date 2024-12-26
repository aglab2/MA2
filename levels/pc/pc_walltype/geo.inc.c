#include "src/game/envfx_snow.h"

const GeoLayout pc_walltype_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, pc_walltype_001_object_006C551C_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, pc_walltype_002_object_006C532C_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, pc_walltype_002_object_006C532C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
