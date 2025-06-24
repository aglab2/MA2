#include "src/game/envfx_snow.h"

const GeoLayout cce_door_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cce_door_001_object_0054ABA4_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, cce_door_001_object_0054ABA4_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, (s16)0.0, (s16)250.0, (s16)1.0000000149011612, cce_door_002_object_0054822C_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
