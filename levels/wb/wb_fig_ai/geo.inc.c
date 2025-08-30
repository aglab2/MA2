#include "src/game/envfx_snow.h"

const GeoLayout wb_fig_ai_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
#if 0
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, 0, 0, 0, wb_fig_ai_wb_fig_ai_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, 0, 0, 0, wb_fig_ai_001_object_005D42F0_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, 0, 0, 0, wb_fig_ai_002_object_005D3DC0_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_TRANSPARENT, 0, 0, 0, wb_fig_ai_002_object_005D3DC0_mesh_layer_5),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, 0, 0, 0, wb_fig_ai_003_object_005D3130_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, 0, 0, 0, wb_fig_ai_004_object_005D29C0_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 0, 0, (f32)-0.0, (f32)179.999991348578, (f32)0.0, wb_fig_ai_005_object_005D21B8_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, (f32)32800.0, (f32)-1598.5000610351562, (f32)-83210.0, wb_dl_0000_object_00C4C788_mesh_layer_1),
#else
		GEO_BATCH(LAYER_OPAQUE, wb_fig_ai_wb_fig_ai_mesh_layer_1),
		GEO_BATCH(LAYER_OPAQUE, wb_fig_ai_001_object_005D42F0_mesh_layer_1),
		GEO_BATCH(LAYER_OPAQUE, wb_fig_ai_002_object_005D3DC0_mesh_layer_1),
		GEO_BATCH(LAYER_TRANSPARENT, wb_fig_ai_002_object_005D3DC0_mesh_layer_5),
		GEO_BATCH(LAYER_OPAQUE, wb_fig_ai_003_object_005D3130_mesh_layer_1),
		GEO_BATCH(LAYER_OPAQUE, wb_fig_ai_004_object_005D29C0_mesh_layer_1),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, 0,0,0, (s16)-0.0, (s16)179.999991348578, (s16)0.0, wb_fig_ai_005_object_005D21B8_mesh_layer_1),
#endif
	GEO_CLOSE_NODE(),
	GEO_END(),
};
