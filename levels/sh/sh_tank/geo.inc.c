#include "src/game/envfx_snow.h"

const GeoLayout sh_tank_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sh_tank_sh_tank_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sh_tank_001_object_00A77568_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
