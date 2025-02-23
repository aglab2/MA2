#include "src/game/envfx_snow.h"

const GeoLayout ce_car2_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ce_car2_ce_car2_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, (s16)0.0, (s16)390.00000953674316, (s16)-1365.8443450927734, ce_car2_001_object_00CB4A18_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, (s16)0.0, (s16)390.00000953674316, (s16)1719.9951171875, ce_car2_002_object_00CB483C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
