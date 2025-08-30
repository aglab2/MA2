#include "src/game/envfx_snow.h"

const GeoLayout sh_rb_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH(LAYER_OPAQUE, sh_rb_sh_rb_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
