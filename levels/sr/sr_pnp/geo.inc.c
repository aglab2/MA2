#include "src/game/envfx_snow.h"

const GeoLayout sr_pnp_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sr_pnp_sr_pnp_mesh_layer_1),
		GEO_OBJ_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 0,0,0, 0,0,0, sr_pnp_001_object_00D76AE8_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, (s16)0.0, (s16)147.5, (s16)0.0, sr_pnp_002_object_00D764CC_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
