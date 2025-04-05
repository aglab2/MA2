#include "src/game/envfx_snow.h"

const GeoLayout so_kaiten_geo[] = {
	GEO_CULLING_RADIUS(3000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, so_kaiten_so_kaiten_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, so_kaiten_so_kaiten_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
