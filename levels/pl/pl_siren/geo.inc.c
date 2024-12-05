#include "src/game/envfx_snow.h"

const GeoLayout pl_siren_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, pl_siren_pl_siren_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, pl_siren_pl_siren_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
