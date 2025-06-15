#include "src/game/envfx_snow.h"

const GeoLayout cct_switch_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, (s16)0.0, (s16)83.4002685546875, (s16)0.0, (s16)-21.80641711401955, (s16)0.0, (s16)0.0, cct_switch_001_object_0123FA3C_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, cct_switch_001_object_0123FA3C_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT, (s16)0.08135000243782997, (s16)83.4002685546875, (s16)0.0, (s16)17.198783452759994, (s16)0.0, (s16)0.0, cct_switch_002_object_0123F52C_mesh_layer_5),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, cct_switch_002_object_0123F52C_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, (s16)0.0, (s16)84.5135498046875, (s16)0.0, cct_switch_cc_switchball_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cct_switch_cc_switchbase_mesh_layer_1),
		GEO_ROTATION_NODE_WITH_DL(LAYER_TRANSPARENT, (s16)0.0, (s16)-61.47051407719918, (s16)0.0, cct_switch_cc_switchface1_mesh_layer_5),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT, (s16)0.0, (s16)96.80000305175781, (s16)0.0, (s16)-0.0, (s16)62.28893466430679, (s16)0.0, cct_switch_001_object_0123EFFC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
