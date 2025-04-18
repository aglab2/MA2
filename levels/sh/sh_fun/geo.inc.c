#include "src/game/envfx_snow.h"

const GeoLayout sh_fun_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sh_fun_sh_fun_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
