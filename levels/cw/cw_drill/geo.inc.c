#include "src/game/envfx_snow.h"

const GeoLayout cw_drill_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, (s16)0.0, (s16)1400.0, (s16)0.0, cw_drill_001_object_00ABAD7C_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cw_drill_002_object_00ABA764_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, (s16)1212.5, (s16)700.0, (s16)0.0, cw_drill_003_object_00AB9D44_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, (s16)1212.5, (s16)-700.0, (s16)0.0, cw_drill_004_object_00AB9734_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, (s16)0.0, (s16)-1400.0, (s16)0.0, cw_drill_005_object_00AB911C_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, (s16)-1212.5, (s16)-700.0, (s16)0.0, cw_drill_006_object_00AB8B0C_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, (s16)-1212.5, (s16)700.0, (s16)0.0, cw_drill_007_object_00AB84FC_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
