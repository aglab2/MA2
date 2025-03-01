#include "src/game/envfx_snow.h"

const GeoLayout pl_bombe_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, pl_bombe_pl_bombe_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, pl_bombe_pl_bombe_mesh_layer_6),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
