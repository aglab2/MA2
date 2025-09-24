#include "src/game/envfx_snow.h"

const GeoLayout k_spark_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(0, geo_update_layer_transparency),
		GEO_SWITCH_CASE(8, geo_switch_anim_state),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, k_spark_Plane_mesh_layer_5_1),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, k_spark_Plane_mesh_layer_5_2),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, k_spark_Plane_mesh_layer_5_3),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, k_spark_Plane_mesh_layer_5_4),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, k_spark_Plane_mesh_layer_5_5),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, k_spark_Plane_mesh_layer_5_6),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, k_spark_Plane_mesh_layer_5_7),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, k_spark_Plane_mesh_layer_5_8),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
