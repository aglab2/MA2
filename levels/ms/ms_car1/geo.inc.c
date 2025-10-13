#include "src/game/envfx_snow.h"

const GeoLayout ms_car1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ms_car1_ms_car1_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, (s16)0.0, (s16)340.00000953674316, (s16)-1559.999942779541, ms_car1_001_object_00CB1608_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, (s16)0.0, (s16)359.99999046325684, (s16)1500.0000953674316, ms_car1_002_object_00CB142C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
