#include "src/game/envfx_snow.h"

const GeoLayout ee_tank_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ee_tank_ee_tank_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, (s16)0.0, (s16)135.00003814697266, (s16)-0.00019073486328125, ee_tank_001_object_00580D10_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
