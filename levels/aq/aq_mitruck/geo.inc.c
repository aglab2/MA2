#include "src/game/envfx_snow.h"

const GeoLayout aq_mitruck_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, aq_mitruck_aq_mitruck_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
