#include "src/game/envfx_snow.h"

const GeoLayout ow_ce_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, ow_ce_ow_ce_mesh_layer_2),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ow_ce_ow_ce_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ow_ce_ow_ce_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ow_ce_ow_ce_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
