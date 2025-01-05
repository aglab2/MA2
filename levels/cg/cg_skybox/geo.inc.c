#include "src/game/envfx_snow.h"

const GeoLayout cg_skybox_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cg_skybox_cg_skybox_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
