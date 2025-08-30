#include "src/game/envfx_snow.h"

const GeoLayout sh_lr_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH(LAYER_OPAQUE, sh_lr_sh_lr_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
