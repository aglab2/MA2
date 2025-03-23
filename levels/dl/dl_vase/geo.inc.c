#include "src/game/envfx_snow.h"

const GeoLayout dl_vase_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, dl_vase_dl_vase_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
