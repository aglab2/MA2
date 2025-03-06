#include "src/game/envfx_snow.h"

const GeoLayout ig_bombe_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ig_bombe_ig_bombe_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, ig_bombe_ig_bombe_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ig_bombe_ig_bombe_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
