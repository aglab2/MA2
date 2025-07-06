#include "src/game/envfx_snow.h"

Gfx *geo_ccr_anim(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx);
const GeoLayout ccr_capsule_anim_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
        GEO_ASM(0, geo_ccr_anim),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, (s16)480.0, (s16)290.0, (s16)0.0, (s16)0.0, (s16)0.0, (s16)0.0, ccr_capsule_anim_001_object_012119FC_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, (s16)-270.0, (s16)800.0, (s16)0.0, ccr_capsule_anim_002_object_01210D7C_mesh_layer_1),
		GEO_CLOSE_NODE(),

		GEO_ASM(1, geo_ccr_anim),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, (s16)-1.9999999949504854e-05, (s16)290.0, (s16)-480.0, (s16)-2.504476844154668e-06, (s16)89.99996835353231, (s16)2.5044776583766666e-06, ccr_capsule_anim_003_object_012108CC_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, (s16)-269.9999809265137, (s16)800.0, (s16)-5.237014192971401e-05, ccr_capsule_anim_004_object_0120FC74_mesh_layer_1),
		GEO_CLOSE_NODE(),

		GEO_ASM(2, geo_ccr_anim),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, (s16)-480.0, (s16)290.0, (s16)3.999999989900971e-05, (s16)-6.830192426900745e-06, (s16)179.999991348578, (s16)-1.866933528522283e-05, ccr_capsule_anim_005_object_0120F7D4_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, (s16)-270.0, (s16)800.0, (s16)1.7164729797514156e-05, ccr_capsule_anim_006_object_0120EB84_mesh_layer_1),
		GEO_CLOSE_NODE(),

		GEO_ASM(3, geo_ccr_anim),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, (s16)6.000000212225132e-05, (s16)290.0, (s16)480.0, (s16)-2.504476844154668e-06, (s16)-89.99996835353231, (s16)-2.5044776583766666e-06, ccr_capsule_anim_007_object_0120E6E4_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, (s16)-269.9999809265137, (s16)800.0, (s16)5.237014647718752e-05, ccr_capsule_anim_008_object_0120DA64_mesh_layer_1),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
