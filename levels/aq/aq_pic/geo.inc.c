#include "src/game/envfx_snow.h"

const GeoLayout aq_pic_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, aq_pic_aq_pic_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
