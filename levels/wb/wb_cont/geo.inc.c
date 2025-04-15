#include "src/game/envfx_snow.h"

const GeoLayout wb_cont_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wb_cont_wb_cont_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wb_cont_wb_cont_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wb_cont_001_object_005E77CC_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
