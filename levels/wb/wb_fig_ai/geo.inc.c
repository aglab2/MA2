#include "src/game/envfx_snow.h"

const GeoLayout wb_fig_ai_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH(LAYER_OPAQUE, wb_fig_ai_wb_fig_ai_mesh_layer_1),
		GEO_BATCH(LAYER_OPAQUE, wb_fig_ai_001_object_005D42F0_mesh_layer_1),
		GEO_BATCH(LAYER_OPAQUE, wb_fig_ai_002_object_005D3DC0_mesh_layer_1),
		GEO_BATCH(LAYER_TRANSPARENT, wb_fig_ai_002_object_005D3DC0_mesh_layer_5),
		GEO_BATCH(LAYER_OPAQUE, wb_fig_ai_003_object_005D3130_mesh_layer_1),
		GEO_BATCH(LAYER_OPAQUE, wb_fig_ai_004_object_005D29C0_mesh_layer_1),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, 0,0,0, (s16)-0.0, (s16)179.999991348578, (s16)0.0, wb_fig_ai_005_object_005D21B8_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

extern Gfx *geo_wb_fig(s32 callContext, UNUSED struct GraphNode *node, Mat4 mtx);
const GeoLayout wb_fig_ai_geo_crumbling[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(0, geo_wb_fig),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, 0,0,0, (s16)-0.0, (s16)0, (s16)0.0, wb_fig_ai_wb_fig_ai_mesh_layer_1),
		GEO_ASM(1, geo_wb_fig),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, 0,0,0, (s16)-0.0, (s16)0, (s16)0.0, wb_fig_ai_001_object_005D42F0_mesh_layer_1),
		GEO_ASM(2, geo_wb_fig),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, 0,0,0, (s16)-0.0, (s16)0, (s16)0.0, wb_fig_ai_002_object_005D3DC0_mesh_layer_1),
		GEO_ASM(3, geo_wb_fig),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0,0,0, (s16)-0.0, (s16)0, (s16)0.0, wb_fig_ai_002_object_005D3DC0_mesh_layer_5),
		GEO_ASM(4, geo_wb_fig),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, 0,0,0, (s16)-0.0, (s16)0, (s16)0.0, wb_fig_ai_003_object_005D3130_mesh_layer_1),
		GEO_ASM(5, geo_wb_fig),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, 0,0,0, (s16)-0.0, (s16)0, (s16)0.0, wb_fig_ai_004_object_005D29C0_mesh_layer_1),
		GEO_ASM(6, geo_wb_fig),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, 0,0,0, (s16)-0.0, (s16)0, (s16)0.0, wb_fig_ai_005_object_005D21B8_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
