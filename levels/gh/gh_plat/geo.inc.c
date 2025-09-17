#include "src/game/envfx_snow.h"

const GeoLayout gh_plat_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, gh_plat_gf_plat_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
