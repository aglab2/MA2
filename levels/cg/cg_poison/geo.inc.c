#include "src/game/envfx_snow.h"

const GeoLayout cg_poison_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, cg_poison_000_object_005B0484_mesh_layer_5),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, (s16)0.0, (s16)294.998779296875, (s16)0.0, 0, -180, 0, cg_poison_001_object_005B03E4_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
