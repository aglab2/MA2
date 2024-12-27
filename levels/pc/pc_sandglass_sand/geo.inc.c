#include "src/game/envfx_snow.h"

const GeoLayout pc_sandglass_sand_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, pc_sandglass_sand_pc_sandglass_sand_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
