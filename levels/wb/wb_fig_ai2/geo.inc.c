#include "src/game/envfx_snow.h"

const GeoLayout wb_fig_ai2_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wb_fig_ai2_wb_fig_ai2_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wb_fig_ai2_001_object_005D7468_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wb_fig_ai2_002_object_005D6F20_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wb_fig_ai2_002_object_005D6F20_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wb_fig_ai2_003_object_005D61A8_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wb_fig_ai2_004_object_005D5918_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wb_fig_ai2_005_object_005D4FE0_mesh_layer_5),
		GEO_ROTATION_NODE_WITH_DL(LAYER_OPAQUE, (s16)-0.0, (s16)179.999991348578, (s16)0.0, wb_fig_ai2_006_object_005D4E48_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
