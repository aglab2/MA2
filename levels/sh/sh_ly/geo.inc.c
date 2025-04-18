#include "src/game/envfx_snow.h"

const GeoLayout sh_ly_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sh_ly_sh_ly_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
