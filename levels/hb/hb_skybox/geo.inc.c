#include "src/game/envfx_snow.h"

const GeoLayout hb_skybox_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hb_skybox_hb_skybox_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
