#include "src/game/envfx_snow.h"

const GeoLayout cct_blockla_geo[] = {
	GEO_CULLING_RADIUS(30000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, cct_blockla_000_object_0123D284_001_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cct_blockla_000_object_0123D284_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
