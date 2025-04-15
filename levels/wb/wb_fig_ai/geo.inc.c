#include "src/game/envfx_snow.h"

const GeoLayout wb_fig_ai_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wb_fig_ai_wb_fig_ai_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wb_fig_ai_001_object_005D42F0_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wb_fig_ai_002_object_005D3DC0_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wb_fig_ai_002_object_005D3DC0_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wb_fig_ai_003_object_005D3130_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wb_fig_ai_004_object_005D29C0_mesh_layer_1),
		GEO_ROTATION_NODE_WITH_DL(LAYER_OPAQUE, (s16)-0.0, (s16)179.999991348578, (s16)0.0, wb_fig_ai_005_object_005D21B8_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
