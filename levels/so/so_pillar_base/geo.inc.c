#include "src/game/envfx_snow.h"

const GeoLayout so_pillar_base_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, so_pillar_base_so_pillar_base_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
