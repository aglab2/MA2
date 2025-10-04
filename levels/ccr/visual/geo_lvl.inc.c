#include "src/game/envfx_snow.h"

extern const GeoLayout ccr_dl_001_object_011C808C_geo[];
extern const GeoLayout ccr_dl_001_object_011CD4D4_geo[];
extern const GeoLayout ccr_dl_001_object_011F507C_geo[];
extern const GeoLayout ccr_dl_001_object_011F507C_001_geo[];
extern const GeoLayout ccr_dl_001_object_011F507C_002_geo[];
extern const GeoLayout ccr_dl_001_object_011F507C_003_geo[];
extern const GeoLayout ccr_dl_001_object_011FA8FC_geo[];
extern const GeoLayout ccr_dl_001_object_011FA8FC_001_geo[];
extern const GeoLayout ccr_dl_001_object_011FA8FC_002_geo[];
extern const GeoLayout ccr_dl_001_object_011FFA6C_geo[];
extern const GeoLayout ccr_dl_001_object_011FFA6C_001_geo[];
extern const GeoLayout ccr_dl_001_object_011FFA6C_002_geo[];
extern const GeoLayout ccr_dl_001_object_01208A14_geo[];
extern const GeoLayout ccr_dl_001_object_0120D1B4_geo[];
extern const GeoLayout ccr_dl_001_object_011E068C_geo[];
extern const GeoLayout ccr_dl_001_object_011E068C_001_geo[];
extern const GeoLayout ccr_dl_001_object_011E068C_002_geo[];
extern const GeoLayout ccr_dl_001_object_011E068C_003_geo[];
extern const GeoLayout ccr_dl_001_object_011E3CF4_geo[];
extern const GeoLayout ccr_dl_001_object_011E3CF4_001_geo[];
extern const GeoLayout ccr_dl_001_object_011E3CF4_002_geo[];
extern const GeoLayout ccr_dl_001_object_011E3CF4_003_geo[];

#define geo_cc_switch geo_switch_cc
Gfx *geo_ccr_mov(s32 callContext, struct GraphNode *node, UNUSED void *context);
Gfx *geo_ccr_anim_end(s32 callContext, struct GraphNode *node, UNUSED void *context);
Gfx *geo_ccr_anim2_end(s32 callContext, struct GraphNode *node, UNUSED void *context);
Gfx *geo_ccr_anim_rots(s32 callContext, struct GraphNode *node, UNUSED void *context);

const GeoLayout ccr_area_1_geo[] = {
	GEO_BATCH_NODE_START_WITH_FLIPBOOK(batch_lvl_dls_ccr, ccr_flipbooks),
	GEO_OPEN_NODE(),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, (f32)0.0, (f32)-1300.0, (f32)-7500.0, ccr_dl_0000_object_013C2EFC_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, (f32)0.0, (f32)-1300.0, (f32)-7500.0, ccr_dl_0001_object_013C2AA4_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_0002_object_013C2894_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, (f32)0.0, (f32)6200.0, (f32)0.0, ccr_dl_0003_object_013C176C_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, (f32)0.0, (f32)6300.0, (f32)0.0, ccr_dl_0004_object_013C10D4_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_0005_object_013C34E4_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 0, 0, (f32)-0.0, (f32)-90.00000933466734, (f32)0.0, ccr_dl_0005_object_013C34E4_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 0, 0, (f32)-0.0, (f32)90.00000933466734, (f32)0.0, ccr_dl_0007_object_013C015C_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 0, 0, (f32)-0.0, (f32)-179.999991348578, (f32)0.0, ccr_dl_0007_object_013C015C_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, (f32)-800.0, (f32)200.0, (f32)800.0, ccr_dl_0009_object_013BF55C_mesh_layer_1),
        GEO_ASM(0, geo_ccr_mov),
		GEO_LVL_TRANSLATE_NODE(LAYER_OPAQUE, (f32)0.0, (f32)-4000.0, (f32)0.0),
		GEO_OPEN_NODE(),
			GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)0.0, (f32)0, (f32)0.0, ccr_dl_001_object_011B141C_mesh_layer_5),
			GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)0.0, (f32)-22.500002333666835, (f32)0.0, ccr_dl_002_object_011B131C_mesh_layer_5),
			GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)0.0, (f32)-45.00000125223908, (f32)0.0, ccr_dl_003_object_011B121C_mesh_layer_5),
			GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)-0.0, (f32)-90.00000933466734, (f32)0.0, ccr_dl_004_object_011B111C_mesh_layer_5),
			GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)-0.0, (f32)-112.500004838145, (f32)0.0, ccr_dl_005_object_011B101C_mesh_layer_5),
			GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)-0.0, (f32)-135.000014002001, (f32)0.0, ccr_dl_006_object_011B0F1C_mesh_layer_5),
			GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)-0.0, (f32)45.00000125223908, (f32)0.0, ccr_dl_007_object_011B0E1C_mesh_layer_5),
			GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)-0.0, (f32)67.50003432175718, (f32)0.0, ccr_dl_008_object_011B0D1C_mesh_layer_5),
			GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)-0.0, (f32)90.00000933466734, (f32)0.0, ccr_dl_009_object_011B0C1C_mesh_layer_5),
			GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)-0.0, (f32)135.000014002001, (f32)0.0, ccr_dl_010_object_011B0B1C_mesh_layer_5),
			GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)-0.0, (f32)157.50000950547866, (f32)0.0, ccr_dl_011_object_011B0A1C_mesh_layer_5),
			GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)-0.0, (f32)-179.999991348578, (f32)0.0, ccr_dl_012_object_011B091C_mesh_layer_5),
		GEO_CLOSE_NODE(),
        GEO_ASM(1, geo_ccr_mov),
		GEO_LVL_TRANSLATE_NODE(LAYER_OPAQUE, (f32)0.0, (f32)-4000.0, (f32)0.0),
		GEO_OPEN_NODE(),
			GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)0.0, (f32)0, (f32)0.0, ccr_dl_001_object_011B2054_mesh_layer_5),
			GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)0.0, (f32)-22.500002333666835, (f32)0.0, ccr_dl_002_object_011B1F54_mesh_layer_5),
			GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)0.0, (f32)-45.00000125223908, (f32)0.0, ccr_dl_003_object_011B1E54_mesh_layer_5),
			GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)-0.0, (f32)-90.00000933466734, (f32)0.0, ccr_dl_004_object_011B1D54_mesh_layer_5),
			GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)-0.0, (f32)-112.500004838145, (f32)0.0, ccr_dl_005_object_011B1C54_mesh_layer_5),
			GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)-0.0, (f32)-135.000014002001, (f32)0.0, ccr_dl_006_object_011B1B54_mesh_layer_5),
			GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)-0.0, (f32)45.00000125223908, (f32)0.0, ccr_dl_007_object_011B1A54_mesh_layer_5),
			GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)-0.0, (f32)67.50003432175718, (f32)0.0, ccr_dl_008_object_011B1954_mesh_layer_5),
			GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)-0.0, (f32)90.00000933466734, (f32)0.0, ccr_dl_009_object_011B1854_mesh_layer_5),
			GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)-0.0, (f32)135.000014002001, (f32)0.0, ccr_dl_010_object_011B1754_mesh_layer_5),
			GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)-0.0, (f32)157.50000950547866, (f32)0.0, ccr_dl_011_object_011B1654_mesh_layer_5),
			GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)-0.0, (f32)-179.999991348578, (f32)0.0, ccr_dl_012_object_011B1554_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 0, 0, (f32)-0.0, (f32)-90.00000933466734, (f32)0.0, ccr_dl_001_object_011B2F74_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 0, 0, (f32)-0.0, (f32)-179.999991348578, (f32)0.0, ccr_dl_002_object_011B2B04_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_001_object_011B3894_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 0, 0, (f32)-0.0, (f32)90.00000933466734, (f32)0.0, ccr_dl_002_object_011B341C_mesh_layer_1),
		GEO_SWITCH_CASE(32, geo_switch_cc),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, ccr_dl_001_object_011C808C_geo),
			GEO_BRANCH(1, ccr_dl_002_object_011C808C_geo),
			GEO_BRANCH(1, ccr_dl_003_object_011C761C_geo),
			GEO_BRANCH(1, ccr_dl_004_object_011C6BAC_geo),
			GEO_BRANCH(1, ccr_dl_005_object_011C613C_geo),
			GEO_BRANCH(1, ccr_dl_006_object_011C56CC_geo),
			GEO_BRANCH(1, ccr_dl_007_object_011C4C5C_geo),
			GEO_BRANCH(1, ccr_dl_008_object_011C41EC_geo),
			GEO_BRANCH(1, ccr_dl_009_object_011C377C_geo),
			GEO_BRANCH(1, ccr_dl_010_object_011C2D0C_geo),
			GEO_BRANCH(1, ccr_dl_011_object_011C229C_geo),
			GEO_BRANCH(1, ccr_dl_012_object_011C182C_geo),
			GEO_BRANCH(1, ccr_dl_013_object_011C0DBC_geo),
			GEO_BRANCH(1, ccr_dl_014_object_011C034C_geo),
			GEO_BRANCH(1, ccr_dl_015_object_011BF8DC_geo),
			GEO_BRANCH(1, ccr_dl_016_object_011BEE6C_geo),
			GEO_BRANCH(1, ccr_dl_017_object_011BE3FC_geo),
			GEO_BRANCH(1, ccr_dl_018_object_011BD98C_geo),
			GEO_BRANCH(1, ccr_dl_019_object_011BCF1C_geo),
			GEO_BRANCH(1, ccr_dl_020_object_011BC4AC_geo),
			GEO_BRANCH(1, ccr_dl_021_object_011BBA3C_geo),
			GEO_BRANCH(1, ccr_dl_022_object_011BAFCC_geo),
			GEO_BRANCH(1, ccr_dl_023_object_011BA55C_geo),
			GEO_BRANCH(1, ccr_dl_024_object_011B9AEC_geo),
			GEO_BRANCH(1, ccr_dl_025_object_011B907C_geo),
			GEO_BRANCH(1, ccr_dl_026_object_011B860C_geo),
			GEO_BRANCH(1, ccr_dl_027_object_011B7B9C_geo),
			GEO_BRANCH(1, ccr_dl_028_object_011B712C_geo),
			GEO_BRANCH(1, ccr_dl_029_object_011B66BC_geo),
			GEO_BRANCH(1, ccr_dl_030_object_011B5C4C_geo),
			GEO_BRANCH(1, ccr_dl_031_object_011B51DC_geo),
			GEO_BRANCH(1, ccr_dl_032_object_011B476C_geo),
		GEO_CLOSE_NODE(),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_001_object_011CD8B4_mesh_layer_5),
		/*
		GEO_SWITCH_CASE(20, geo_cc_switch),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, ccr_dl_001_object_011CD4D4_geo),
			GEO_BRANCH(1, ccr_dl_002_object_011CD4D4_geo),
			GEO_BRANCH(1, ccr_dl_003_object_011CD0F4_geo),
			GEO_BRANCH(1, ccr_dl_004_object_011CCD14_geo),
			GEO_BRANCH(1, ccr_dl_005_object_011CC934_geo),
			GEO_BRANCH(1, ccr_dl_006_object_011CC554_geo),
			GEO_BRANCH(1, ccr_dl_007_object_011CC174_geo),
			GEO_BRANCH(1, ccr_dl_008_object_011CBD94_geo),
			GEO_BRANCH(1, ccr_dl_009_object_011CB9B4_geo),
			GEO_BRANCH(1, ccr_dl_010_object_011CB5D4_geo),
			GEO_BRANCH(1, ccr_dl_011_object_011CB1F4_geo),
			GEO_BRANCH(1, ccr_dl_012_object_011CAE14_geo),
			GEO_BRANCH(1, ccr_dl_013_object_011CAA34_geo),
			GEO_BRANCH(1, ccr_dl_014_object_011CA654_geo),
			GEO_BRANCH(1, ccr_dl_015_object_011CA274_geo),
			GEO_BRANCH(1, ccr_dl_016_object_011C9E94_geo),
			GEO_BRANCH(1, ccr_dl_017_object_011C9AB4_geo),
			GEO_BRANCH(1, ccr_dl_018_object_011C96D4_geo),
			GEO_BRANCH(1, ccr_dl_019_object_011C92F4_geo),
			GEO_BRANCH(1, ccr_dl_020_object_011C8F14_geo),
		GEO_CLOSE_NODE(),
		*/
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, (f32)0.0, (f32)-1700.0, (f32)-5500.0, ccr_dl_001_object_011E406C_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)0.0, (f32)1300.0, (f32)-5500.0, (f32)-0.0, (f32)0.0, (f32)-179.999991348578, ccr_dl_002_object_011E3F34_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, (f32)0.0, (f32)-200.0, (f32)-5500.0, ccr_dl_001_object_011E51BC_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)0.0, (f32)-200.0, (f32)-5500.0, (f32)-0.0, (f32)-179.999991348578, (f32)0.0, ccr_dl_002_object_011E4D84_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, (f32)0.0, (f32)-3200.0, (f32)-5500.0, ccr_dl_003_object_011E494C_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)0.0, (f32)-3200.0, (f32)-5500.0, (f32)-0.0, (f32)-179.999991348578, (f32)0.0, ccr_dl_004_object_011E4514_mesh_layer_1),
		GEO_SWITCH_CASE(16, geo_switch_cc),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, ccr_dl_001_object_011F507C_geo),
			GEO_BRANCH(1, ccr_dl_002_object_011F507C_geo),
			GEO_BRANCH(1, ccr_dl_003_object_011F410C_geo),
			GEO_BRANCH(1, ccr_dl_004_object_011F3164_geo),
			GEO_BRANCH(1, ccr_dl_005_object_011F21E4_geo),
			GEO_BRANCH(1, ccr_dl_006_object_011F1254_geo),
			GEO_BRANCH(1, ccr_dl_007_object_011F02DC_geo),
			GEO_BRANCH(1, ccr_dl_008_object_011EF334_geo),
			GEO_BRANCH(1, ccr_dl_009_object_011EE3C4_geo),
			GEO_BRANCH(1, ccr_dl_010_object_011ED454_geo),
			GEO_BRANCH(1, ccr_dl_011_object_011EC4E4_geo),
			GEO_BRANCH(1, ccr_dl_012_object_011EB574_geo),
			GEO_BRANCH(1, ccr_dl_013_object_011EA5FC_geo),
			GEO_BRANCH(1, ccr_dl_014_object_011E967C_geo),
			GEO_BRANCH(1, ccr_dl_015_object_011E8704_geo),
			GEO_BRANCH(1, ccr_dl_016_object_011E7784_geo),
		GEO_CLOSE_NODE(),
		GEO_SWITCH_CASE(16, geo_switch_cc),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, ccr_dl_001_object_011F507C_001_geo),
			GEO_BRANCH(1, ccr_dl_002_object_011F507C_001_geo),
			GEO_BRANCH(1, ccr_dl_003_object_011F410C_001_geo),
			GEO_BRANCH(1, ccr_dl_004_object_011F3164_001_geo),
			GEO_BRANCH(1, ccr_dl_005_object_011F21E4_001_geo),
			GEO_BRANCH(1, ccr_dl_006_object_011F1254_001_geo),
			GEO_BRANCH(1, ccr_dl_007_object_011F02DC_001_geo),
			GEO_BRANCH(1, ccr_dl_008_object_011EF334_001_geo),
			GEO_BRANCH(1, ccr_dl_009_object_011EE3C4_001_geo),
			GEO_BRANCH(1, ccr_dl_010_object_011ED454_001_geo),
			GEO_BRANCH(1, ccr_dl_011_object_011EC4E4_001_geo),
			GEO_BRANCH(1, ccr_dl_012_object_011EB574_001_geo),
			GEO_BRANCH(1, ccr_dl_013_object_011EA5FC_001_geo),
			GEO_BRANCH(1, ccr_dl_014_object_011E967C_001_geo),
			GEO_BRANCH(1, ccr_dl_015_object_011E8704_001_geo),
			GEO_BRANCH(1, ccr_dl_016_object_011E7784_001_geo),
		GEO_CLOSE_NODE(),
		GEO_SWITCH_CASE(16, geo_switch_cc),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, ccr_dl_001_object_011F507C_002_geo),
			GEO_BRANCH(1, ccr_dl_002_object_011F507C_002_geo),
			GEO_BRANCH(1, ccr_dl_003_object_011F410C_002_geo),
			GEO_BRANCH(1, ccr_dl_004_object_011F3164_002_geo),
			GEO_BRANCH(1, ccr_dl_005_object_011F21E4_002_geo),
			GEO_BRANCH(1, ccr_dl_006_object_011F1254_002_geo),
			GEO_BRANCH(1, ccr_dl_007_object_011F02DC_002_geo),
			GEO_BRANCH(1, ccr_dl_008_object_011EF334_002_geo),
			GEO_BRANCH(1, ccr_dl_009_object_011EE3C4_002_geo),
			GEO_BRANCH(1, ccr_dl_010_object_011ED454_002_geo),
			GEO_BRANCH(1, ccr_dl_011_object_011EC4E4_002_geo),
			GEO_BRANCH(1, ccr_dl_012_object_011EB574_002_geo),
			GEO_BRANCH(1, ccr_dl_013_object_011EA5FC_002_geo),
			GEO_BRANCH(1, ccr_dl_014_object_011E967C_002_geo),
			GEO_BRANCH(1, ccr_dl_015_object_011E8704_002_geo),
			GEO_BRANCH(1, ccr_dl_016_object_011E7784_002_geo),
		GEO_CLOSE_NODE(),
		GEO_SWITCH_CASE(16, geo_switch_cc),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, ccr_dl_001_object_011F507C_003_geo),
			GEO_BRANCH(1, ccr_dl_002_object_011F507C_003_geo),
			GEO_BRANCH(1, ccr_dl_003_object_011F410C_003_geo),
			GEO_BRANCH(1, ccr_dl_004_object_011F3164_003_geo),
			GEO_BRANCH(1, ccr_dl_005_object_011F21E4_003_geo),
			GEO_BRANCH(1, ccr_dl_006_object_011F1254_003_geo),
			GEO_BRANCH(1, ccr_dl_007_object_011F02DC_003_geo),
			GEO_BRANCH(1, ccr_dl_008_object_011EF334_003_geo),
			GEO_BRANCH(1, ccr_dl_009_object_011EE3C4_003_geo),
			GEO_BRANCH(1, ccr_dl_010_object_011ED454_003_geo),
			GEO_BRANCH(1, ccr_dl_011_object_011EC4E4_003_geo),
			GEO_BRANCH(1, ccr_dl_012_object_011EB574_003_geo),
			GEO_BRANCH(1, ccr_dl_013_object_011EA5FC_003_geo),
			GEO_BRANCH(1, ccr_dl_014_object_011E967C_003_geo),
			GEO_BRANCH(1, ccr_dl_015_object_011E8704_003_geo),
			GEO_BRANCH(1, ccr_dl_016_object_011E7784_003_geo),
		GEO_CLOSE_NODE(),
		GEO_SWITCH_CASE(0, geo_switch_cc2),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, ccr_dl_001_object_011FA8FC_geo),
			GEO_BRANCH(1, ccr_dl_002_object_011FA8FC_geo),
			GEO_BRANCH(1, ccr_dl_003_object_011FA0D4_geo),
			GEO_BRANCH(1, ccr_dl_004_object_011F98AC_geo),
			GEO_BRANCH(1, ccr_dl_005_object_011F9084_geo),
			GEO_BRANCH(1, ccr_dl_006_object_011F8874_geo),
			GEO_BRANCH(1, ccr_dl_007_object_011F804C_geo),
			GEO_BRANCH(1, ccr_dl_008_object_011F783C_geo),
			GEO_BRANCH(1, ccr_dl_009_object_011F7034_geo),
			GEO_BRANCH(1, ccr_dl_010_object_011F682C_geo),
		GEO_CLOSE_NODE(),
		GEO_SWITCH_CASE(0, geo_switch_cc2),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, ccr_dl_001_object_011FA8FC_001_geo),
			GEO_BRANCH(1, ccr_dl_002_object_011FA8FC_001_geo),
			GEO_BRANCH(1, ccr_dl_003_object_011FA0D4_001_geo),
			GEO_BRANCH(1, ccr_dl_004_object_011F98AC_001_geo),
			GEO_BRANCH(1, ccr_dl_005_object_011F9084_001_geo),
			GEO_BRANCH(1, ccr_dl_006_object_011F8874_001_geo),
			GEO_BRANCH(1, ccr_dl_007_object_011F804C_001_geo),
			GEO_BRANCH(1, ccr_dl_008_object_011F783C_001_geo),
			GEO_BRANCH(1, ccr_dl_009_object_011F7034_001_geo),
			GEO_BRANCH(1, ccr_dl_010_object_011F682C_001_geo),
		GEO_CLOSE_NODE(),
		GEO_SWITCH_CASE(0, geo_switch_cc2),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, ccr_dl_001_object_011FA8FC_002_geo),
			GEO_BRANCH(1, ccr_dl_002_object_011FA8FC_002_geo),
			GEO_BRANCH(1, ccr_dl_003_object_011FA0D4_002_geo),
			GEO_BRANCH(1, ccr_dl_004_object_011F98AC_002_geo),
			GEO_BRANCH(1, ccr_dl_005_object_011F9084_002_geo),
			GEO_BRANCH(1, ccr_dl_006_object_011F8874_002_geo),
			GEO_BRANCH(1, ccr_dl_007_object_011F804C_002_geo),
			GEO_BRANCH(1, ccr_dl_008_object_011F783C_002_geo),
			GEO_BRANCH(1, ccr_dl_009_object_011F7034_002_geo),
			GEO_BRANCH(1, ccr_dl_010_object_011F682C_002_geo),
		GEO_CLOSE_NODE(),
		GEO_SWITCH_CASE(1, geo_switch_cc2),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, ccr_dl_001_object_011FFA6C_geo),
			GEO_BRANCH(1, ccr_dl_002_object_011FFA6C_geo),
			GEO_BRANCH(1, ccr_dl_003_object_011FF254_geo),
			GEO_BRANCH(1, ccr_dl_004_object_011FEA2C_geo),
			GEO_BRANCH(1, ccr_dl_005_object_011FE204_geo),
			GEO_BRANCH(1, ccr_dl_006_object_011FD9DC_geo),
			GEO_BRANCH(1, ccr_dl_007_object_011FD1CC_geo),
			GEO_BRANCH(1, ccr_dl_008_object_011FC9BC_geo),
			GEO_BRANCH(1, ccr_dl_009_object_011FC184_geo),
			GEO_BRANCH(1, ccr_dl_010_object_011FB96C_geo),
		GEO_CLOSE_NODE(),
		GEO_SWITCH_CASE(1, geo_switch_cc2),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, ccr_dl_001_object_011FFA6C_001_geo),
			GEO_BRANCH(1, ccr_dl_002_object_011FFA6C_001_geo),
			GEO_BRANCH(1, ccr_dl_003_object_011FF254_001_geo),
			GEO_BRANCH(1, ccr_dl_004_object_011FEA2C_001_geo),
			GEO_BRANCH(1, ccr_dl_005_object_011FE204_001_geo),
			GEO_BRANCH(1, ccr_dl_006_object_011FD9DC_001_geo),
			GEO_BRANCH(1, ccr_dl_007_object_011FD1CC_001_geo),
			GEO_BRANCH(1, ccr_dl_008_object_011FC9BC_001_geo),
			GEO_BRANCH(1, ccr_dl_009_object_011FC184_001_geo),
			GEO_BRANCH(1, ccr_dl_010_object_011FB96C_001_geo),
		GEO_CLOSE_NODE(),
		GEO_SWITCH_CASE(1, geo_switch_cc2),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, ccr_dl_001_object_011FFA6C_002_geo),
			GEO_BRANCH(1, ccr_dl_002_object_011FFA6C_002_geo),
			GEO_BRANCH(1, ccr_dl_003_object_011FF254_002_geo),
			GEO_BRANCH(1, ccr_dl_004_object_011FEA2C_002_geo),
			GEO_BRANCH(1, ccr_dl_005_object_011FE204_002_geo),
			GEO_BRANCH(1, ccr_dl_006_object_011FD9DC_002_geo),
			GEO_BRANCH(1, ccr_dl_007_object_011FD1CC_002_geo),
			GEO_BRANCH(1, ccr_dl_008_object_011FC9BC_002_geo),
			GEO_BRANCH(1, ccr_dl_009_object_011FC184_002_geo),
			GEO_BRANCH(1, ccr_dl_010_object_011FB96C_002_geo),
		GEO_CLOSE_NODE(),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, (f32)0.0, (f32)-150.0, (f32)-8750.0, ccr_dl_001_object_01200A84_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)0.0, (f32)-150.0, (f32)-8750.0, (f32)-0.0, (f32)179.999991348578, (f32)0.0, ccr_dl_002_object_012006B4_mesh_layer_1),
		GEO_LVL_TRANSLATE_NODE(LAYER_OPAQUE, (f32)-3.3345013856887817, (f32)-951.6317749023438, (f32)-8397.611083984375),
		GEO_OPEN_NODE(),
			GEO_BATCH(LAYER_OPAQUE, ccr_dl_001_object_01245D44_mesh_layer_1),
			GEO_BATCH(LAYER_TRANSPARENT, ccr_dl_002_object_01245634_mesh_layer_5),
			GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, (f32)0.0, (f32)0.0, (f32)-130.0, ccr_dl_003_object_01245594_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_LVL_TRANSLATE_ROTATE_NODE(LAYER_OPAQUE, (f32)-3.3345019817352295, (f32)-951.6313171386719, (f32)-4602.493591308594, (f32)6.830189170012751e-06, (f32)-179.99997768819966, (f32)2.2255581957367457e-12),
		GEO_OPEN_NODE(),
			GEO_BATCH(LAYER_OPAQUE, ccr_dl_001_object_01245D44_001_mesh_layer_1),
			GEO_BATCH(LAYER_TRANSPARENT, ccr_dl_002_object_01245634_001_mesh_layer_5),
			GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, (f32)0.0, (f32)0.0, (f32)-130.0, ccr_dl_003_object_01245594_001_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, (f32)800.0, (f32)200.0, (f32)-800.0, ccr_dl_0010_object_013BE8FC_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, (f32)-800.0, (f32)200.0, (f32)-800.0, ccr_dl_0011_object_013BE05C_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)0.0, (f32)2500.0, (f32)0.0, (f32)-0.0, (f32)-90.00000933466734, (f32)0.0, ccr_dl_0012_object_013C3474_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, (f32)0.0, (f32)2500.0, (f32)0.0, ccr_dl_0012_object_013C3474_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)0.0, (f32)2500.0, (f32)0.0, (f32)-0.0, (f32)-179.999991348578, (f32)0.0, ccr_dl_0012_object_013C3474_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)0.0, (f32)2500.0, (f32)0.0, (f32)-0.0, (f32)90.00000933466734, (f32)0.0, ccr_dl_0012_object_013C3474_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, (f32)0.0, (f32)-1300.0, (f32)-7500.0, ccr_dl_0016_object_013BC0FC_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)0.0, (f32)-150.0, (f32)-8750.0, (f32)-0.0, (f32)-179.999991348578, (f32)0.0, ccr_dl_0017_object_013C33CC_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, (f32)0.0, (f32)-150.0, (f32)-8750.0, ccr_dl_0017_object_013C33CC_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, (f32)0.0, (f32)-1300.0, (f32)-7500.0, ccr_dl_0019_object_013BB4BC_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)0.0, (f32)-1300.0, (f32)-8700.000610351562, (f32)-0.0, (f32)179.999991348578, (f32)0.0, ccr_dl_0020_object_013C3394_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, (f32)0.0, (f32)-1300.0, (f32)-8800.0, ccr_dl_0020_object_013C3394_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)0.00035000000934815034, (f32)-200.0, (f32)-5500.0, (f32)-0.0, (f32)179.999991348578, (f32)0.0, ccr_dl_0022_object_013C335C_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, (f32)0.00035000000934815034, (f32)-200.0, (f32)-5500.0, ccr_dl_0022_object_013C335C_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, (f32)0.00035000000934815034, (f32)-1700.0, (f32)-5500.0, ccr_dl_0024_object_013B73AC_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)0.00035000000934815034, (f32)-1700.0, (f32)-5500.0, (f32)-0.0, (f32)-179.999991348578, (f32)0.0, ccr_dl_0025_object_013C3324_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, (f32)0.00035000000934815034, (f32)-1700.0, (f32)-5500.0, ccr_dl_0025_object_013C3324_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)0.00035000000934815034, (f32)1300.0, (f32)-5500.0, (f32)-5.008956130975331e-06, (f32)5.008955316753333e-06, (f32)-179.999991348578, ccr_dl_0025_object_013C3324_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)0.00035000000934815034, (f32)1300.0, (f32)-5500.0, (f32)-179.999991348578, (f32)-0.0, (f32)-0.0, ccr_dl_0025_object_013C3324_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)0.0004099999932805076, (f32)-700.0, (f32)-6500.0, (f32)179.999991348578, (f32)5.00895694519733e-06, (f32)5.008956130975331e-06, ccr_dl_0029_object_013C327C_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, (f32)0.000290000007225899, (f32)300.0, (f32)-4500.0, ccr_dl_0029_object_013C327C_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, (f32)0.0, (f32)0.0, (f32)2000.0, ccr_dl_0031_object_013B5234_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_0032_object_013B504C_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, (f32)0.0, (f32)6200.0, (f32)0.0, ccr_dl_0033_object_013B35BC_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, (f32)-800.0, (f32)200.0, (f32)800.0, ccr_dl_0034_object_013B317C_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, (f32)800.0, (f32)200.0, (f32)-800.0, ccr_dl_0035_object_013B1024_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, (f32)-800.0, (f32)200.0, (f32)-800.0, ccr_dl_0036_object_013AF7CC_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)800.0, (f32)200.0, (f32)800.0, (f32)-0.0, (f32)-179.999991348578, (f32)0.0, ccr_dl_0037_object_013AE8CC_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_0038_object_013ADD8C_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)0.0, (f32)5000.0, (f32)0.0, (f32)-0.0, (f32)-90.00000933466734, (f32)0.0, ccr_dl_0039_object_013C3244_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)0.0, (f32)5000.0, (f32)0.0, (f32)-0.0, (f32)-179.999991348578, (f32)0.0, ccr_dl_0039_object_013C3244_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)0.0, (f32)5000.0, (f32)0.0, (f32)-0.0, (f32)90.00000933466734, (f32)0.0, ccr_dl_0039_object_013C3244_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, (f32)0.0, (f32)5000.0, (f32)0.0, ccr_dl_0039_object_013C3244_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 0, 0, (f32)-0.0, (f32)-90.00000933466734, (f32)0.0, ccr_dl_0043_object_013C319C_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_0043_object_013C319C_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 0, 0, (f32)-0.0, (f32)-179.999991348578, (f32)0.0, ccr_dl_0043_object_013C319C_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 0, 0, (f32)-0.0, (f32)90.00000933466734, (f32)0.0, ccr_dl_0043_object_013C319C_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, (f32)-6000.0, (f32)300.0, (f32)0.0001300000076298602, ccr_dl_0047_object_013AAE9C_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)2500.0, (f32)2850.0, (f32)-0.00022000000171829015, (f32)-0.0, (f32)-90.00000933466734, (f32)0.0, ccr_dl_0048_object_013C30F4_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)0.00011000000085914508, (f32)2850.0, (f32)2500.0, (f32)-0.0, (f32)-179.999991348578, (f32)0.0, ccr_dl_0048_object_013C30F4_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)-2500.0, (f32)2850.0, (f32)0.0, (f32)-0.0, (f32)90.00000933466734, (f32)0.0, ccr_dl_0048_object_013C30F4_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, (f32)0.0, (f32)2850.0, (f32)-2500.0, ccr_dl_0048_object_013C30F4_mesh_layer_1),

		// proper cycle
		GEO_ASM(0, geo_ccr_anim_rots),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)0.0, (f32)2100.0, (f32)0.0, (f32)3.182825851950456e-07, (f32)-25.603626632142287, (f32)9.511219774979581e-08, ccr_dl_001_object_011D0A3C_mesh_layer_1),
		GEO_ASM(0, geo_ccr_anim_rots),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)0.0, (f32)2100.0, (f32)0.0, (f32)3.182825851950456e-07, (f32)64.39638270252505, (f32)9.511225499978009e-08, ccr_dl_001_object_011D0A3C_001_mesh_layer_1),
		GEO_ASM(0, geo_ccr_anim_rots),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)7.066675058874407e-19, (f32)2100.0, (f32)6.098637220230962e-19, (f32)3.182825343061707e-07, (f32)154.39637154662486, (f32)9.511221047201454e-08, ccr_dl_001_object_011D0A3C_002_mesh_layer_1),
		GEO_ASM(0, geo_ccr_anim_rots),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)1.6263033879752274e-18, (f32)2100.0, (f32)5.227404393298084e-19, (f32)3.182825343061707e-07, (f32)-115.60361547624211, (f32)9.511220411090518e-08, ccr_dl_001_object_011D0A3C_003_mesh_layer_1),

		// inverse cycle
		GEO_ASM(1, geo_ccr_anim_rots),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)0.0, (f32)3100.0, (f32)0.0, (f32)2.527824201960481e-07, (f32)-24.999390532122526, (f32)-1.3106535484818018e-08, ccr_dl_002_object_011D03CC_mesh_layer_1),
		GEO_ASM(1, geo_ccr_anim_rots),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)0.0, (f32)3100.0, (f32)0.0, (f32)2.527824456404856e-07, (f32)65.0006222176394, (f32)-1.3106527533431315e-08, ccr_dl_002_object_011D03CC_001_mesh_layer_1),
		GEO_ASM(1, geo_ccr_anim_rots),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)7.066675058874407e-19, (f32)3100.0, (f32)6.098637220230962e-19, (f32)2.5278234386273577e-07, (f32)155.00061106173922, (f32)-1.3106528328569986e-08, ccr_dl_002_object_011D03CC_002_mesh_layer_1),
		GEO_ASM(1, geo_ccr_anim_rots),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)1.6263033879752274e-18, (f32)3100.0, (f32)5.227404393298084e-19, (f32)2.5278234386273577e-07, (f32)-114.99937596112777, (f32)-1.3106521967460622e-08, ccr_dl_002_object_011D03CC_003_mesh_layer_1),

		// inverse cycle + half shift
		GEO_ASM(3, geo_ccr_anim_rots),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)0.0, (f32)4099.998474121094, (f32)0.0, (f32)-1.5086030577555708e-05, (f32)-64.48425991638643, (f32)-2.260209023285272e-06, ccr_dl_003_object_011CFD5C_mesh_layer_1),
		GEO_ASM(3, geo_ccr_anim_rots),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)0.0, (f32)4099.998474121094, (f32)0.0, (f32)-1.5086027320667714e-05, (f32)25.515742588091733, (f32)-2.260208616174273e-06, ccr_dl_003_object_011CFD5C_001_mesh_layer_1),
		GEO_ASM(3, geo_ccr_anim_rots),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)7.066675058874407e-19, (f32)4099.998474121094, (f32)6.098637220230962e-19, (f32)-1.5086027320667714e-05, (f32)115.51573826238074, (f32)-2.2602082090632738e-06, ccr_dl_003_object_011CFD5C_002_mesh_layer_1),
		GEO_ASM(3, geo_ccr_anim_rots),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)1.6263033879752274e-18, (f32)4099.998474121094, (f32)5.227404393298084e-19, (f32)-1.508602406377972e-05, (f32)-154.48424876048625, (f32)-2.2602082090632738e-06, ccr_dl_003_object_011CFD5C_003_mesh_layer_1),

		// proper cycle + half shift
		GEO_ASM(2, geo_ccr_anim_rots),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)0.0, (f32)5100.0, (f32)0.0, (f32)-6.3727018486300315e-06, (f32)-64.99511708516836, (f32)1.8036792269727356e-06, ccr_dl_004_object_011CF6EC_mesh_layer_1),
		GEO_ASM(2, geo_ccr_anim_rots),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)0.0, (f32)5100.0, (f32)0.0, (f32)-6.372702255741031e-06, (f32)25.00489907968814, (f32)1.8036788198617365e-06, ccr_dl_004_object_011CF6EC_001_mesh_layer_1),
		GEO_ASM(2, geo_ccr_anim_rots),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)7.06667570510926e-19, (f32)5100.0, (f32)6.098637866465816e-19, (f32)-6.372702255741031e-06, (f32)115.0048810935988, (f32)1.8036798376392346e-06, ccr_dl_004_object_011CF6EC_002_mesh_layer_1),
		GEO_ASM(2, geo_ccr_anim_rots),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)1.6263033879752274e-18, (f32)5100.0, (f32)5.227403423945804e-19, (f32)-6.372701034408034e-06, (f32)-154.99509226888986, (f32)1.8036794305282353e-06, ccr_dl_004_object_011CF6EC_003_mesh_layer_1),

		GEO_ASM(3, geo_ccr_anim_rots),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)0.0, (f32)99.9878978729248, (f32)0.0, (f32)-1.5086030577555708e-05, (f32)-64.48425991638643, (f32)-2.260209023285272e-06, ccr_dl_005_object_011CF07C_mesh_layer_1),
		GEO_ASM(3, geo_ccr_anim_rots),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)5.692061405548898e-18, (f32)99.98809814453125, (f32)-1.4230153513872246e-18, (f32)-1.5086027320667714e-05, (f32)25.515742588091733, (f32)-2.260208616174273e-06, ccr_dl_005_object_011CF07C_001_mesh_layer_1),
		GEO_ASM(3, geo_ccr_anim_rots),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)1.4520561117303128e-18, (f32)99.9884033203125, (f32)-5.082197683525802e-18, (f32)-1.5086027320667714e-05, (f32)115.51573826238074, (f32)-2.2602082090632738e-06, ccr_dl_005_object_011CF07C_002_mesh_layer_1),
		GEO_ASM(3, geo_ccr_anim_rots),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)-4.065757629832759e-18, (f32)99.98870849609375, (f32)-2.3910524145488446e-18, (f32)-1.508602406377972e-05, (f32)-154.48424876048625, (f32)-2.2602082090632738e-06, ccr_dl_005_object_011CF07C_003_mesh_layer_1),

		GEO_ASM(1, geo_ccr_anim_rots),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)0.0, (f32)5760.001220703125, (f32)0.0, (f32)2.527824201960481e-07, (f32)-24.999390532122526, (f32)-1.3106535484818018e-08, ccr_dl_006_object_011CEA0C_mesh_layer_1),
		GEO_ASM(1, geo_ccr_anim_rots),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)0.0, (f32)5760.001220703125, (f32)0.0, (f32)2.527824456404856e-07, (f32)65.0006222176394, (f32)-1.3106527533431315e-08, ccr_dl_006_object_011CEA0C_001_mesh_layer_1),
		GEO_ASM(1, geo_ccr_anim_rots),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)7.066675058874407e-19, (f32)5760.001220703125, (f32)6.098637220230962e-19, (f32)2.5278234386273577e-07, (f32)155.00061106173922, (f32)-1.3106528328569986e-08, ccr_dl_006_object_011CEA0C_002_mesh_layer_1),
		GEO_ASM(1, geo_ccr_anim_rots),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)1.6263033879752274e-18, (f32)5760.001220703125, (f32)5.227404393298084e-19, (f32)2.5278234386273577e-07, (f32)-114.99937596112777, (f32)-1.3106521967460622e-08, ccr_dl_006_object_011CEA0C_003_mesh_layer_1),
		
		GEO_ASM(2, geo_ccr_anim_rots),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)0.0, (f32)1100.0, (f32)0.0, (f32)-6.3727018486300315e-06, (f32)-64.99511708516836, (f32)1.8036792269727356e-06, ccr_dl_007_object_011CE39C_mesh_layer_1),
		GEO_ASM(2, geo_ccr_anim_rots),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)-1.0842021724855044e-18, (f32)1100.0001525878906, (f32)1.0842021724855044e-18, (f32)-6.372702255741031e-06, (f32)25.00489907968814, (f32)1.8036788198617365e-06, ccr_dl_007_object_011CE39C_001_mesh_layer_1),
		GEO_ASM(2, geo_ccr_anim_rots),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)2.8750722385993617e-18, (f32)1100.0003051757812, (f32)2.7782683254880465e-18, (f32)-6.372702255741031e-06, (f32)115.0048810935988, (f32)1.8036798376392346e-06, ccr_dl_007_object_011CE39C_002_mesh_layer_1),
		GEO_ASM(2, geo_ccr_anim_rots),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, (f32)4.87890977618477e-18, (f32)1100.0004577636719, (f32)-2.729866368932389e-18, (f32)-6.372701034408034e-06, (f32)-154.99509226888986, (f32)1.8036794305282353e-06, ccr_dl_007_object_011CE39C_003_mesh_layer_1),

		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 0, 0, (f32)-9.334666014167418e-06, (f32)0, (f32)-2.504480508153661e-06, ccr_dl_002_object_011B245C_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 0, 0, (f32)-9.334666014167418e-06, (f32)-90, (f32)-2.504480508153661e-06, ccr_dl_002_object_011B245C_mesh_layer_1),
		GEO_SWITCH_CASE(51, geo_ccr_anim_end),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, ccr_dl_001_object_01208A14_geo),
			GEO_BRANCH(1, ccr_dl_002_object_01208A14_geo),
			GEO_BRANCH(1, ccr_dl_003_object_01208824_geo),
			GEO_BRANCH(1, ccr_dl_004_object_01208634_geo),
			GEO_BRANCH(1, ccr_dl_005_object_01208444_geo),
			GEO_BRANCH(1, ccr_dl_006_object_01208254_geo),
			GEO_BRANCH(1, ccr_dl_007_object_01208064_geo),
			GEO_BRANCH(1, ccr_dl_008_object_01207E74_geo),
			GEO_BRANCH(1, ccr_dl_009_object_01207C7C_geo),
			GEO_BRANCH(1, ccr_dl_010_object_01207A8C_geo),
			GEO_BRANCH(1, ccr_dl_011_object_012078A4_geo),
			GEO_BRANCH(1, ccr_dl_012_object_012076B4_geo),
			GEO_BRANCH(1, ccr_dl_013_object_012074C4_geo),
			GEO_BRANCH(1, ccr_dl_014_object_012072D4_geo),
			GEO_BRANCH(1, ccr_dl_015_object_012070E4_geo),
			GEO_BRANCH(1, ccr_dl_016_object_01206EF4_geo),
			GEO_BRANCH(1, ccr_dl_017_object_01206CE4_geo),
			GEO_BRANCH(1, ccr_dl_018_object_01206AF4_geo),
			GEO_BRANCH(1, ccr_dl_019_object_01206904_geo),
			GEO_BRANCH(1, ccr_dl_020_object_0120671C_geo),
			GEO_BRANCH(1, ccr_dl_021_object_0120652C_geo),
			GEO_BRANCH(1, ccr_dl_022_object_01206344_geo),
			GEO_BRANCH(1, ccr_dl_023_object_0120615C_geo),
			GEO_BRANCH(1, ccr_dl_024_object_01205F4C_geo),
			GEO_BRANCH(1, ccr_dl_025_object_01205D64_geo),
			GEO_BRANCH(1, ccr_dl_026_object_01205B84_geo),
			GEO_BRANCH(1, ccr_dl_027_object_012059A4_geo),
			GEO_BRANCH(1, ccr_dl_028_object_012057C4_geo),
			GEO_BRANCH(1, ccr_dl_029_object_012055E4_geo),
			GEO_BRANCH(1, ccr_dl_030_object_012053FC_geo),
			GEO_BRANCH(1, ccr_dl_031_object_0120521C_geo),
			GEO_BRANCH(1, ccr_dl_032_object_0120503C_geo),
			GEO_BRANCH(1, ccr_dl_033_object_01204E5C_geo),
			GEO_BRANCH(1, ccr_dl_034_object_01204C7C_geo),
			GEO_BRANCH(1, ccr_dl_035_object_01204A9C_geo),
			GEO_BRANCH(1, ccr_dl_036_object_012048BC_geo),
			GEO_BRANCH(1, ccr_dl_037_object_012046DC_geo),
			GEO_BRANCH(1, ccr_dl_038_object_012045DC_geo),
			GEO_BRANCH(1, ccr_dl_039_object_012044DC_geo),
			GEO_BRANCH(1, ccr_dl_040_object_012043DC_geo),
			GEO_BRANCH(1, ccr_dl_041_object_012042DC_geo),
			GEO_BRANCH(1, ccr_dl_042_object_012041DC_geo),
			GEO_BRANCH(1, ccr_dl_043_object_012040DC_geo),
			GEO_BRANCH(1, ccr_dl_044_object_01203FDC_geo),
			GEO_BRANCH(1, ccr_dl_045_object_01203EDC_geo),
			GEO_BRANCH(1, ccr_dl_046_object_01203DDC_geo),
			GEO_BRANCH(1, ccr_dl_047_object_01203CDC_geo),
			GEO_BRANCH(1, ccr_dl_048_object_01203BDC_geo),
			GEO_BRANCH(1, ccr_dl_049_object_01203ADC_geo),
			GEO_BRANCH(1, ccr_dl_050_object_012039DC_geo),
			GEO_BRANCH(1, ccr_dl_051_object_012038DC_geo),
		GEO_CLOSE_NODE(),
		GEO_SWITCH_CASE(16, geo_ccr_anim2_end),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, ccr_dl_001_object_0120D1B4_geo),
			GEO_BRANCH(1, ccr_dl_002_object_0120D1B4_geo),
			GEO_BRANCH(1, ccr_dl_003_object_0120D00C_geo),
			GEO_BRANCH(1, ccr_dl_004_object_0120CDF4_geo),
			GEO_BRANCH(1, ccr_dl_005_object_0120CB54_geo),
			GEO_BRANCH(1, ccr_dl_006_object_0120C854_geo),
			GEO_BRANCH(1, ccr_dl_007_object_0120C4EC_geo),
			GEO_BRANCH(1, ccr_dl_008_object_0120C124_geo),
			GEO_BRANCH(1, ccr_dl_009_object_0120BCF4_geo),
			GEO_BRANCH(1, ccr_dl_010_object_0120B844_geo),
			GEO_BRANCH(1, ccr_dl_011_object_0120B32C_geo),
			GEO_BRANCH(1, ccr_dl_012_object_0120ADB4_geo),
			GEO_BRANCH(1, ccr_dl_013_object_0120A7C4_geo),
			GEO_BRANCH(1, ccr_dl_014_object_0120A14C_geo),
			GEO_BRANCH(1, ccr_dl_015_object_01209A8C_geo),
			GEO_BRANCH(1, ccr_dl_016_object_01209364_geo),
		GEO_CLOSE_NODE(),
		GEO_SWITCH_CASE(60, geo_cc_switch),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, ccr_dl_001_object_011E068C_geo),
			GEO_BRANCH(1, ccr_dl_002_object_011E068C_geo),
			GEO_BRANCH(1, ccr_dl_003_object_011E05BC_geo),
			GEO_BRANCH(1, ccr_dl_004_object_011E04EC_geo),
			GEO_BRANCH(1, ccr_dl_005_object_011E041C_geo),
			GEO_BRANCH(1, ccr_dl_006_object_011E034C_geo),
			GEO_BRANCH(1, ccr_dl_007_object_011E027C_geo),
			GEO_BRANCH(1, ccr_dl_008_object_011E01AC_geo),
			GEO_BRANCH(1, ccr_dl_009_object_011E00DC_geo),
			GEO_BRANCH(1, ccr_dl_010_object_011E000C_geo),
			GEO_BRANCH(1, ccr_dl_011_object_011DFF3C_geo),
			GEO_BRANCH(1, ccr_dl_012_object_011DFE6C_geo),
			GEO_BRANCH(1, ccr_dl_013_object_011DFD9C_geo),
			GEO_BRANCH(1, ccr_dl_014_object_011DFCCC_geo),
			GEO_BRANCH(1, ccr_dl_015_object_011DFBFC_geo),
			GEO_BRANCH(1, ccr_dl_016_object_011DFB2C_geo),
			GEO_BRANCH(1, ccr_dl_017_object_011DFA2C_geo),
			GEO_BRANCH(1, ccr_dl_018_object_011DF92C_geo),
			GEO_BRANCH(1, ccr_dl_019_object_011DF82C_geo),
			GEO_BRANCH(1, ccr_dl_020_object_011DF72C_geo),
			GEO_BRANCH(1, ccr_dl_021_object_011DF62C_geo),
			GEO_BRANCH(1, ccr_dl_022_object_011DF52C_geo),
			GEO_BRANCH(1, ccr_dl_023_object_011DF42C_geo),
			GEO_BRANCH(1, ccr_dl_024_object_011DF32C_geo),
			GEO_BRANCH(1, ccr_dl_025_object_011DF22C_geo),
			GEO_BRANCH(1, ccr_dl_026_object_011DF12C_geo),
			GEO_BRANCH(1, ccr_dl_027_object_011DF02C_geo),
			GEO_BRANCH(1, ccr_dl_028_object_011DEF2C_geo),
			GEO_BRANCH(1, ccr_dl_029_object_011DEE2C_geo),
			GEO_BRANCH(1, ccr_dl_030_object_011DED2C_geo),
			GEO_BRANCH(1, ccr_dl_031_object_011DEC2C_geo),
			GEO_BRANCH(1, ccr_dl_032_object_011DEB2C_geo),
			GEO_BRANCH(1, ccr_dl_033_object_011DEA2C_geo),
			GEO_BRANCH(1, ccr_dl_034_object_011DE92C_geo),
			GEO_BRANCH(1, ccr_dl_035_object_011DE82C_geo),
			GEO_BRANCH(1, ccr_dl_036_object_011DE72C_geo),
			GEO_BRANCH(1, ccr_dl_037_object_011DE62C_geo),
			GEO_BRANCH(1, ccr_dl_038_object_011DE52C_geo),
			GEO_BRANCH(1, ccr_dl_039_object_011DE42C_geo),
			GEO_BRANCH(1, ccr_dl_040_object_011DE32C_geo),
			GEO_BRANCH(1, ccr_dl_041_object_011DE22C_geo),
			GEO_BRANCH(1, ccr_dl_042_object_011DE12C_geo),
			GEO_BRANCH(1, ccr_dl_043_object_011DE02C_geo),
			GEO_BRANCH(1, ccr_dl_044_object_011DDF2C_geo),
			GEO_BRANCH(1, ccr_dl_045_object_011DDE2C_geo),
			GEO_BRANCH(1, ccr_dl_046_object_011DDD5C_geo),
			GEO_BRANCH(1, ccr_dl_047_object_011DDC8C_geo),
			GEO_BRANCH(1, ccr_dl_048_object_011DDBBC_geo),
			GEO_BRANCH(1, ccr_dl_049_object_011DDAEC_geo),
			GEO_BRANCH(1, ccr_dl_050_object_011DDA1C_geo),
			GEO_BRANCH(1, ccr_dl_051_object_011DD94C_geo),
			GEO_BRANCH(1, ccr_dl_052_object_011DD87C_geo),
			GEO_BRANCH(1, ccr_dl_053_object_011DD7AC_geo),
			GEO_BRANCH(1, ccr_dl_054_object_011DD6DC_geo),
			GEO_BRANCH(1, ccr_dl_055_object_011DD60C_geo),
			GEO_BRANCH(1, ccr_dl_056_object_011DD53C_geo),
			GEO_BRANCH(1, ccr_dl_057_object_011DD46C_geo),
			GEO_BRANCH(1, ccr_dl_058_object_011DD39C_geo),
			GEO_BRANCH(1, ccr_dl_059_object_011DD2CC_geo),
			GEO_BRANCH(1, ccr_dl_060_object_011DD224_geo),
		GEO_CLOSE_NODE(),
		GEO_SWITCH_CASE(60, geo_cc_switch),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, ccr_dl_001_object_011E068C_001_geo),
			GEO_BRANCH(1, ccr_dl_002_object_011E068C_001_geo),
			GEO_BRANCH(1, ccr_dl_003_object_011E05BC_001_geo),
			GEO_BRANCH(1, ccr_dl_004_object_011E04EC_001_geo),
			GEO_BRANCH(1, ccr_dl_005_object_011E041C_001_geo),
			GEO_BRANCH(1, ccr_dl_006_object_011E034C_001_geo),
			GEO_BRANCH(1, ccr_dl_007_object_011E027C_001_geo),
			GEO_BRANCH(1, ccr_dl_008_object_011E01AC_001_geo),
			GEO_BRANCH(1, ccr_dl_009_object_011E00DC_001_geo),
			GEO_BRANCH(1, ccr_dl_010_object_011E000C_001_geo),
			GEO_BRANCH(1, ccr_dl_011_object_011DFF3C_001_geo),
			GEO_BRANCH(1, ccr_dl_012_object_011DFE6C_001_geo),
			GEO_BRANCH(1, ccr_dl_013_object_011DFD9C_001_geo),
			GEO_BRANCH(1, ccr_dl_014_object_011DFCCC_001_geo),
			GEO_BRANCH(1, ccr_dl_015_object_011DFBFC_001_geo),
			GEO_BRANCH(1, ccr_dl_016_object_011DFB2C_001_geo),
			GEO_BRANCH(1, ccr_dl_017_object_011DFA2C_001_geo),
			GEO_BRANCH(1, ccr_dl_018_object_011DF92C_001_geo),
			GEO_BRANCH(1, ccr_dl_019_object_011DF82C_001_geo),
			GEO_BRANCH(1, ccr_dl_020_object_011DF72C_001_geo),
			GEO_BRANCH(1, ccr_dl_021_object_011DF62C_001_geo),
			GEO_BRANCH(1, ccr_dl_022_object_011DF52C_001_geo),
			GEO_BRANCH(1, ccr_dl_023_object_011DF42C_001_geo),
			GEO_BRANCH(1, ccr_dl_024_object_011DF32C_001_geo),
			GEO_BRANCH(1, ccr_dl_025_object_011DF22C_001_geo),
			GEO_BRANCH(1, ccr_dl_026_object_011DF12C_001_geo),
			GEO_BRANCH(1, ccr_dl_027_object_011DF02C_001_geo),
			GEO_BRANCH(1, ccr_dl_028_object_011DEF2C_001_geo),
			GEO_BRANCH(1, ccr_dl_029_object_011DEE2C_001_geo),
			GEO_BRANCH(1, ccr_dl_030_object_011DED2C_001_geo),
			GEO_BRANCH(1, ccr_dl_031_object_011DEC2C_001_geo),
			GEO_BRANCH(1, ccr_dl_032_object_011DEB2C_001_geo),
			GEO_BRANCH(1, ccr_dl_033_object_011DEA2C_001_geo),
			GEO_BRANCH(1, ccr_dl_034_object_011DE92C_001_geo),
			GEO_BRANCH(1, ccr_dl_035_object_011DE82C_001_geo),
			GEO_BRANCH(1, ccr_dl_036_object_011DE72C_001_geo),
			GEO_BRANCH(1, ccr_dl_037_object_011DE62C_001_geo),
			GEO_BRANCH(1, ccr_dl_038_object_011DE52C_001_geo),
			GEO_BRANCH(1, ccr_dl_039_object_011DE42C_001_geo),
			GEO_BRANCH(1, ccr_dl_040_object_011DE32C_001_geo),
			GEO_BRANCH(1, ccr_dl_041_object_011DE22C_001_geo),
			GEO_BRANCH(1, ccr_dl_042_object_011DE12C_001_geo),
			GEO_BRANCH(1, ccr_dl_043_object_011DE02C_001_geo),
			GEO_BRANCH(1, ccr_dl_044_object_011DDF2C_001_geo),
			GEO_BRANCH(1, ccr_dl_045_object_011DDE2C_001_geo),
			GEO_BRANCH(1, ccr_dl_046_object_011DDD5C_001_geo),
			GEO_BRANCH(1, ccr_dl_047_object_011DDC8C_001_geo),
			GEO_BRANCH(1, ccr_dl_048_object_011DDBBC_001_geo),
			GEO_BRANCH(1, ccr_dl_049_object_011DDAEC_001_geo),
			GEO_BRANCH(1, ccr_dl_050_object_011DDA1C_001_geo),
			GEO_BRANCH(1, ccr_dl_051_object_011DD94C_001_geo),
			GEO_BRANCH(1, ccr_dl_052_object_011DD87C_001_geo),
			GEO_BRANCH(1, ccr_dl_053_object_011DD7AC_001_geo),
			GEO_BRANCH(1, ccr_dl_054_object_011DD6DC_001_geo),
			GEO_BRANCH(1, ccr_dl_055_object_011DD60C_001_geo),
			GEO_BRANCH(1, ccr_dl_056_object_011DD53C_001_geo),
			GEO_BRANCH(1, ccr_dl_057_object_011DD46C_001_geo),
			GEO_BRANCH(1, ccr_dl_058_object_011DD39C_001_geo),
			GEO_BRANCH(1, ccr_dl_059_object_011DD2CC_001_geo),
			GEO_BRANCH(1, ccr_dl_060_object_011DD224_001_geo),
		GEO_CLOSE_NODE(),
		GEO_SWITCH_CASE(60, geo_cc_switch),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, ccr_dl_001_object_011E068C_002_geo),
			GEO_BRANCH(1, ccr_dl_002_object_011E068C_002_geo),
			GEO_BRANCH(1, ccr_dl_003_object_011E05BC_002_geo),
			GEO_BRANCH(1, ccr_dl_004_object_011E04EC_002_geo),
			GEO_BRANCH(1, ccr_dl_005_object_011E041C_002_geo),
			GEO_BRANCH(1, ccr_dl_006_object_011E034C_002_geo),
			GEO_BRANCH(1, ccr_dl_007_object_011E027C_002_geo),
			GEO_BRANCH(1, ccr_dl_008_object_011E01AC_002_geo),
			GEO_BRANCH(1, ccr_dl_009_object_011E00DC_002_geo),
			GEO_BRANCH(1, ccr_dl_010_object_011E000C_002_geo),
			GEO_BRANCH(1, ccr_dl_011_object_011DFF3C_002_geo),
			GEO_BRANCH(1, ccr_dl_012_object_011DFE6C_002_geo),
			GEO_BRANCH(1, ccr_dl_013_object_011DFD9C_002_geo),
			GEO_BRANCH(1, ccr_dl_014_object_011DFCCC_002_geo),
			GEO_BRANCH(1, ccr_dl_015_object_011DFBFC_002_geo),
			GEO_BRANCH(1, ccr_dl_016_object_011DFB2C_002_geo),
			GEO_BRANCH(1, ccr_dl_017_object_011DFA2C_002_geo),
			GEO_BRANCH(1, ccr_dl_018_object_011DF92C_002_geo),
			GEO_BRANCH(1, ccr_dl_019_object_011DF82C_002_geo),
			GEO_BRANCH(1, ccr_dl_020_object_011DF72C_002_geo),
			GEO_BRANCH(1, ccr_dl_021_object_011DF62C_002_geo),
			GEO_BRANCH(1, ccr_dl_022_object_011DF52C_002_geo),
			GEO_BRANCH(1, ccr_dl_023_object_011DF42C_002_geo),
			GEO_BRANCH(1, ccr_dl_024_object_011DF32C_002_geo),
			GEO_BRANCH(1, ccr_dl_025_object_011DF22C_002_geo),
			GEO_BRANCH(1, ccr_dl_026_object_011DF12C_002_geo),
			GEO_BRANCH(1, ccr_dl_027_object_011DF02C_002_geo),
			GEO_BRANCH(1, ccr_dl_028_object_011DEF2C_002_geo),
			GEO_BRANCH(1, ccr_dl_029_object_011DEE2C_002_geo),
			GEO_BRANCH(1, ccr_dl_030_object_011DED2C_002_geo),
			GEO_BRANCH(1, ccr_dl_031_object_011DEC2C_002_geo),
			GEO_BRANCH(1, ccr_dl_032_object_011DEB2C_002_geo),
			GEO_BRANCH(1, ccr_dl_033_object_011DEA2C_002_geo),
			GEO_BRANCH(1, ccr_dl_034_object_011DE92C_002_geo),
			GEO_BRANCH(1, ccr_dl_035_object_011DE82C_002_geo),
			GEO_BRANCH(1, ccr_dl_036_object_011DE72C_002_geo),
			GEO_BRANCH(1, ccr_dl_037_object_011DE62C_002_geo),
			GEO_BRANCH(1, ccr_dl_038_object_011DE52C_002_geo),
			GEO_BRANCH(1, ccr_dl_039_object_011DE42C_002_geo),
			GEO_BRANCH(1, ccr_dl_040_object_011DE32C_002_geo),
			GEO_BRANCH(1, ccr_dl_041_object_011DE22C_002_geo),
			GEO_BRANCH(1, ccr_dl_042_object_011DE12C_002_geo),
			GEO_BRANCH(1, ccr_dl_043_object_011DE02C_002_geo),
			GEO_BRANCH(1, ccr_dl_044_object_011DDF2C_002_geo),
			GEO_BRANCH(1, ccr_dl_045_object_011DDE2C_002_geo),
			GEO_BRANCH(1, ccr_dl_046_object_011DDD5C_002_geo),
			GEO_BRANCH(1, ccr_dl_047_object_011DDC8C_002_geo),
			GEO_BRANCH(1, ccr_dl_048_object_011DDBBC_002_geo),
			GEO_BRANCH(1, ccr_dl_049_object_011DDAEC_002_geo),
			GEO_BRANCH(1, ccr_dl_050_object_011DDA1C_002_geo),
			GEO_BRANCH(1, ccr_dl_051_object_011DD94C_002_geo),
			GEO_BRANCH(1, ccr_dl_052_object_011DD87C_002_geo),
			GEO_BRANCH(1, ccr_dl_053_object_011DD7AC_002_geo),
			GEO_BRANCH(1, ccr_dl_054_object_011DD6DC_002_geo),
			GEO_BRANCH(1, ccr_dl_055_object_011DD60C_002_geo),
			GEO_BRANCH(1, ccr_dl_056_object_011DD53C_002_geo),
			GEO_BRANCH(1, ccr_dl_057_object_011DD46C_002_geo),
			GEO_BRANCH(1, ccr_dl_058_object_011DD39C_002_geo),
			GEO_BRANCH(1, ccr_dl_059_object_011DD2CC_002_geo),
			GEO_BRANCH(1, ccr_dl_060_object_011DD224_002_geo),
		GEO_CLOSE_NODE(),
		GEO_SWITCH_CASE(60, geo_cc_switch),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, ccr_dl_001_object_011E068C_003_geo),
			GEO_BRANCH(1, ccr_dl_002_object_011E068C_003_geo),
			GEO_BRANCH(1, ccr_dl_003_object_011E05BC_003_geo),
			GEO_BRANCH(1, ccr_dl_004_object_011E04EC_003_geo),
			GEO_BRANCH(1, ccr_dl_005_object_011E041C_003_geo),
			GEO_BRANCH(1, ccr_dl_006_object_011E034C_003_geo),
			GEO_BRANCH(1, ccr_dl_007_object_011E027C_003_geo),
			GEO_BRANCH(1, ccr_dl_008_object_011E01AC_003_geo),
			GEO_BRANCH(1, ccr_dl_009_object_011E00DC_003_geo),
			GEO_BRANCH(1, ccr_dl_010_object_011E000C_003_geo),
			GEO_BRANCH(1, ccr_dl_011_object_011DFF3C_003_geo),
			GEO_BRANCH(1, ccr_dl_012_object_011DFE6C_003_geo),
			GEO_BRANCH(1, ccr_dl_013_object_011DFD9C_003_geo),
			GEO_BRANCH(1, ccr_dl_014_object_011DFCCC_003_geo),
			GEO_BRANCH(1, ccr_dl_015_object_011DFBFC_003_geo),
			GEO_BRANCH(1, ccr_dl_016_object_011DFB2C_003_geo),
			GEO_BRANCH(1, ccr_dl_017_object_011DFA2C_003_geo),
			GEO_BRANCH(1, ccr_dl_018_object_011DF92C_003_geo),
			GEO_BRANCH(1, ccr_dl_019_object_011DF82C_003_geo),
			GEO_BRANCH(1, ccr_dl_020_object_011DF72C_003_geo),
			GEO_BRANCH(1, ccr_dl_021_object_011DF62C_003_geo),
			GEO_BRANCH(1, ccr_dl_022_object_011DF52C_003_geo),
			GEO_BRANCH(1, ccr_dl_023_object_011DF42C_003_geo),
			GEO_BRANCH(1, ccr_dl_024_object_011DF32C_003_geo),
			GEO_BRANCH(1, ccr_dl_025_object_011DF22C_003_geo),
			GEO_BRANCH(1, ccr_dl_026_object_011DF12C_003_geo),
			GEO_BRANCH(1, ccr_dl_027_object_011DF02C_003_geo),
			GEO_BRANCH(1, ccr_dl_028_object_011DEF2C_003_geo),
			GEO_BRANCH(1, ccr_dl_029_object_011DEE2C_003_geo),
			GEO_BRANCH(1, ccr_dl_030_object_011DED2C_003_geo),
			GEO_BRANCH(1, ccr_dl_031_object_011DEC2C_003_geo),
			GEO_BRANCH(1, ccr_dl_032_object_011DEB2C_003_geo),
			GEO_BRANCH(1, ccr_dl_033_object_011DEA2C_003_geo),
			GEO_BRANCH(1, ccr_dl_034_object_011DE92C_003_geo),
			GEO_BRANCH(1, ccr_dl_035_object_011DE82C_003_geo),
			GEO_BRANCH(1, ccr_dl_036_object_011DE72C_003_geo),
			GEO_BRANCH(1, ccr_dl_037_object_011DE62C_003_geo),
			GEO_BRANCH(1, ccr_dl_038_object_011DE52C_003_geo),
			GEO_BRANCH(1, ccr_dl_039_object_011DE42C_003_geo),
			GEO_BRANCH(1, ccr_dl_040_object_011DE32C_003_geo),
			GEO_BRANCH(1, ccr_dl_041_object_011DE22C_003_geo),
			GEO_BRANCH(1, ccr_dl_042_object_011DE12C_003_geo),
			GEO_BRANCH(1, ccr_dl_043_object_011DE02C_003_geo),
			GEO_BRANCH(1, ccr_dl_044_object_011DDF2C_003_geo),
			GEO_BRANCH(1, ccr_dl_045_object_011DDE2C_003_geo),
			GEO_BRANCH(1, ccr_dl_046_object_011DDD5C_003_geo),
			GEO_BRANCH(1, ccr_dl_047_object_011DDC8C_003_geo),
			GEO_BRANCH(1, ccr_dl_048_object_011DDBBC_003_geo),
			GEO_BRANCH(1, ccr_dl_049_object_011DDAEC_003_geo),
			GEO_BRANCH(1, ccr_dl_050_object_011DDA1C_003_geo),
			GEO_BRANCH(1, ccr_dl_051_object_011DD94C_003_geo),
			GEO_BRANCH(1, ccr_dl_052_object_011DD87C_003_geo),
			GEO_BRANCH(1, ccr_dl_053_object_011DD7AC_003_geo),
			GEO_BRANCH(1, ccr_dl_054_object_011DD6DC_003_geo),
			GEO_BRANCH(1, ccr_dl_055_object_011DD60C_003_geo),
			GEO_BRANCH(1, ccr_dl_056_object_011DD53C_003_geo),
			GEO_BRANCH(1, ccr_dl_057_object_011DD46C_003_geo),
			GEO_BRANCH(1, ccr_dl_058_object_011DD39C_003_geo),
			GEO_BRANCH(1, ccr_dl_059_object_011DD2CC_003_geo),
			GEO_BRANCH(1, ccr_dl_060_object_011DD224_003_geo),
		GEO_CLOSE_NODE(),
		GEO_SWITCH_CASE(60, geo_cc_switch),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, ccr_dl_001_object_011E3CF4_geo),
			GEO_BRANCH(1, ccr_dl_002_object_011E3CF4_geo),
			GEO_BRANCH(1, ccr_dl_003_object_011E3C24_geo),
			GEO_BRANCH(1, ccr_dl_004_object_011E3B54_geo),
			GEO_BRANCH(1, ccr_dl_005_object_011E3A84_geo),
			GEO_BRANCH(1, ccr_dl_006_object_011E39B4_geo),
			GEO_BRANCH(1, ccr_dl_007_object_011E38E4_geo),
			GEO_BRANCH(1, ccr_dl_008_object_011E3814_geo),
			GEO_BRANCH(1, ccr_dl_009_object_011E3744_geo),
			GEO_BRANCH(1, ccr_dl_010_object_011E3674_geo),
			GEO_BRANCH(1, ccr_dl_011_object_011E35A4_geo),
			GEO_BRANCH(1, ccr_dl_012_object_011E34D4_geo),
			GEO_BRANCH(1, ccr_dl_013_object_011E3404_geo),
			GEO_BRANCH(1, ccr_dl_014_object_011E3334_geo),
			GEO_BRANCH(1, ccr_dl_015_object_011E3264_geo),
			GEO_BRANCH(1, ccr_dl_016_object_011E3194_geo),
			GEO_BRANCH(1, ccr_dl_017_object_011E3094_geo),
			GEO_BRANCH(1, ccr_dl_018_object_011E2F94_geo),
			GEO_BRANCH(1, ccr_dl_019_object_011E2E94_geo),
			GEO_BRANCH(1, ccr_dl_020_object_011E2D94_geo),
			GEO_BRANCH(1, ccr_dl_021_object_011E2C94_geo),
			GEO_BRANCH(1, ccr_dl_022_object_011E2B94_geo),
			GEO_BRANCH(1, ccr_dl_023_object_011E2A94_geo),
			GEO_BRANCH(1, ccr_dl_024_object_011E2994_geo),
			GEO_BRANCH(1, ccr_dl_025_object_011E2894_geo),
			GEO_BRANCH(1, ccr_dl_026_object_011E2794_geo),
			GEO_BRANCH(1, ccr_dl_027_object_011E2694_geo),
			GEO_BRANCH(1, ccr_dl_028_object_011E2594_geo),
			GEO_BRANCH(1, ccr_dl_029_object_011E2494_geo),
			GEO_BRANCH(1, ccr_dl_030_object_011E2394_geo),
			GEO_BRANCH(1, ccr_dl_031_object_011E2294_geo),
			GEO_BRANCH(1, ccr_dl_032_object_011E2194_geo),
			GEO_BRANCH(1, ccr_dl_033_object_011E2094_geo),
			GEO_BRANCH(1, ccr_dl_034_object_011E1F94_geo),
			GEO_BRANCH(1, ccr_dl_035_object_011E1E94_geo),
			GEO_BRANCH(1, ccr_dl_036_object_011E1D94_geo),
			GEO_BRANCH(1, ccr_dl_037_object_011E1C94_geo),
			GEO_BRANCH(1, ccr_dl_038_object_011E1B94_geo),
			GEO_BRANCH(1, ccr_dl_039_object_011E1A94_geo),
			GEO_BRANCH(1, ccr_dl_040_object_011E1994_geo),
			GEO_BRANCH(1, ccr_dl_041_object_011E1894_geo),
			GEO_BRANCH(1, ccr_dl_042_object_011E1794_geo),
			GEO_BRANCH(1, ccr_dl_043_object_011E1694_geo),
			GEO_BRANCH(1, ccr_dl_044_object_011E1594_geo),
			GEO_BRANCH(1, ccr_dl_045_object_011E1494_geo),
			GEO_BRANCH(1, ccr_dl_046_object_011E13C4_geo),
			GEO_BRANCH(1, ccr_dl_047_object_011E12F4_geo),
			GEO_BRANCH(1, ccr_dl_048_object_011E1224_geo),
			GEO_BRANCH(1, ccr_dl_049_object_011E1154_geo),
			GEO_BRANCH(1, ccr_dl_050_object_011E1084_geo),
			GEO_BRANCH(1, ccr_dl_051_object_011E0FB4_geo),
			GEO_BRANCH(1, ccr_dl_052_object_011E0EE4_geo),
			GEO_BRANCH(1, ccr_dl_053_object_011E0E14_geo),
			GEO_BRANCH(1, ccr_dl_054_object_011E0D44_geo),
			GEO_BRANCH(1, ccr_dl_055_object_011E0C74_geo),
			GEO_BRANCH(1, ccr_dl_056_object_011E0BA4_geo),
			GEO_BRANCH(1, ccr_dl_057_object_011E0AD4_geo),
			GEO_BRANCH(1, ccr_dl_058_object_011E0A04_geo),
			GEO_BRANCH(1, ccr_dl_059_object_011E0934_geo),
			GEO_BRANCH(1, ccr_dl_060_object_011E0864_geo),
		GEO_CLOSE_NODE(),
		GEO_SWITCH_CASE(60, geo_cc_switch),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, ccr_dl_001_object_011E3CF4_001_geo),
			GEO_BRANCH(1, ccr_dl_002_object_011E3CF4_001_geo),
			GEO_BRANCH(1, ccr_dl_003_object_011E3C24_001_geo),
			GEO_BRANCH(1, ccr_dl_004_object_011E3B54_001_geo),
			GEO_BRANCH(1, ccr_dl_005_object_011E3A84_001_geo),
			GEO_BRANCH(1, ccr_dl_006_object_011E39B4_001_geo),
			GEO_BRANCH(1, ccr_dl_007_object_011E38E4_001_geo),
			GEO_BRANCH(1, ccr_dl_008_object_011E3814_001_geo),
			GEO_BRANCH(1, ccr_dl_009_object_011E3744_001_geo),
			GEO_BRANCH(1, ccr_dl_010_object_011E3674_001_geo),
			GEO_BRANCH(1, ccr_dl_011_object_011E35A4_001_geo),
			GEO_BRANCH(1, ccr_dl_012_object_011E34D4_001_geo),
			GEO_BRANCH(1, ccr_dl_013_object_011E3404_001_geo),
			GEO_BRANCH(1, ccr_dl_014_object_011E3334_001_geo),
			GEO_BRANCH(1, ccr_dl_015_object_011E3264_001_geo),
			GEO_BRANCH(1, ccr_dl_016_object_011E3194_001_geo),
			GEO_BRANCH(1, ccr_dl_017_object_011E3094_001_geo),
			GEO_BRANCH(1, ccr_dl_018_object_011E2F94_001_geo),
			GEO_BRANCH(1, ccr_dl_019_object_011E2E94_001_geo),
			GEO_BRANCH(1, ccr_dl_020_object_011E2D94_001_geo),
			GEO_BRANCH(1, ccr_dl_021_object_011E2C94_001_geo),
			GEO_BRANCH(1, ccr_dl_022_object_011E2B94_001_geo),
			GEO_BRANCH(1, ccr_dl_023_object_011E2A94_001_geo),
			GEO_BRANCH(1, ccr_dl_024_object_011E2994_001_geo),
			GEO_BRANCH(1, ccr_dl_025_object_011E2894_001_geo),
			GEO_BRANCH(1, ccr_dl_026_object_011E2794_001_geo),
			GEO_BRANCH(1, ccr_dl_027_object_011E2694_001_geo),
			GEO_BRANCH(1, ccr_dl_028_object_011E2594_001_geo),
			GEO_BRANCH(1, ccr_dl_029_object_011E2494_001_geo),
			GEO_BRANCH(1, ccr_dl_030_object_011E2394_001_geo),
			GEO_BRANCH(1, ccr_dl_031_object_011E2294_001_geo),
			GEO_BRANCH(1, ccr_dl_032_object_011E2194_001_geo),
			GEO_BRANCH(1, ccr_dl_033_object_011E2094_001_geo),
			GEO_BRANCH(1, ccr_dl_034_object_011E1F94_001_geo),
			GEO_BRANCH(1, ccr_dl_035_object_011E1E94_001_geo),
			GEO_BRANCH(1, ccr_dl_036_object_011E1D94_001_geo),
			GEO_BRANCH(1, ccr_dl_037_object_011E1C94_001_geo),
			GEO_BRANCH(1, ccr_dl_038_object_011E1B94_001_geo),
			GEO_BRANCH(1, ccr_dl_039_object_011E1A94_001_geo),
			GEO_BRANCH(1, ccr_dl_040_object_011E1994_001_geo),
			GEO_BRANCH(1, ccr_dl_041_object_011E1894_001_geo),
			GEO_BRANCH(1, ccr_dl_042_object_011E1794_001_geo),
			GEO_BRANCH(1, ccr_dl_043_object_011E1694_001_geo),
			GEO_BRANCH(1, ccr_dl_044_object_011E1594_001_geo),
			GEO_BRANCH(1, ccr_dl_045_object_011E1494_001_geo),
			GEO_BRANCH(1, ccr_dl_046_object_011E13C4_001_geo),
			GEO_BRANCH(1, ccr_dl_047_object_011E12F4_001_geo),
			GEO_BRANCH(1, ccr_dl_048_object_011E1224_001_geo),
			GEO_BRANCH(1, ccr_dl_049_object_011E1154_001_geo),
			GEO_BRANCH(1, ccr_dl_050_object_011E1084_001_geo),
			GEO_BRANCH(1, ccr_dl_051_object_011E0FB4_001_geo),
			GEO_BRANCH(1, ccr_dl_052_object_011E0EE4_001_geo),
			GEO_BRANCH(1, ccr_dl_053_object_011E0E14_001_geo),
			GEO_BRANCH(1, ccr_dl_054_object_011E0D44_001_geo),
			GEO_BRANCH(1, ccr_dl_055_object_011E0C74_001_geo),
			GEO_BRANCH(1, ccr_dl_056_object_011E0BA4_001_geo),
			GEO_BRANCH(1, ccr_dl_057_object_011E0AD4_001_geo),
			GEO_BRANCH(1, ccr_dl_058_object_011E0A04_001_geo),
			GEO_BRANCH(1, ccr_dl_059_object_011E0934_001_geo),
			GEO_BRANCH(1, ccr_dl_060_object_011E0864_001_geo),
		GEO_CLOSE_NODE(),
		GEO_SWITCH_CASE(60, geo_cc_switch),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, ccr_dl_001_object_011E3CF4_002_geo),
			GEO_BRANCH(1, ccr_dl_002_object_011E3CF4_002_geo),
			GEO_BRANCH(1, ccr_dl_003_object_011E3C24_002_geo),
			GEO_BRANCH(1, ccr_dl_004_object_011E3B54_002_geo),
			GEO_BRANCH(1, ccr_dl_005_object_011E3A84_002_geo),
			GEO_BRANCH(1, ccr_dl_006_object_011E39B4_002_geo),
			GEO_BRANCH(1, ccr_dl_007_object_011E38E4_002_geo),
			GEO_BRANCH(1, ccr_dl_008_object_011E3814_002_geo),
			GEO_BRANCH(1, ccr_dl_009_object_011E3744_002_geo),
			GEO_BRANCH(1, ccr_dl_010_object_011E3674_002_geo),
			GEO_BRANCH(1, ccr_dl_011_object_011E35A4_002_geo),
			GEO_BRANCH(1, ccr_dl_012_object_011E34D4_002_geo),
			GEO_BRANCH(1, ccr_dl_013_object_011E3404_002_geo),
			GEO_BRANCH(1, ccr_dl_014_object_011E3334_002_geo),
			GEO_BRANCH(1, ccr_dl_015_object_011E3264_002_geo),
			GEO_BRANCH(1, ccr_dl_016_object_011E3194_002_geo),
			GEO_BRANCH(1, ccr_dl_017_object_011E3094_002_geo),
			GEO_BRANCH(1, ccr_dl_018_object_011E2F94_002_geo),
			GEO_BRANCH(1, ccr_dl_019_object_011E2E94_002_geo),
			GEO_BRANCH(1, ccr_dl_020_object_011E2D94_002_geo),
			GEO_BRANCH(1, ccr_dl_021_object_011E2C94_002_geo),
			GEO_BRANCH(1, ccr_dl_022_object_011E2B94_002_geo),
			GEO_BRANCH(1, ccr_dl_023_object_011E2A94_002_geo),
			GEO_BRANCH(1, ccr_dl_024_object_011E2994_002_geo),
			GEO_BRANCH(1, ccr_dl_025_object_011E2894_002_geo),
			GEO_BRANCH(1, ccr_dl_026_object_011E2794_002_geo),
			GEO_BRANCH(1, ccr_dl_027_object_011E2694_002_geo),
			GEO_BRANCH(1, ccr_dl_028_object_011E2594_002_geo),
			GEO_BRANCH(1, ccr_dl_029_object_011E2494_002_geo),
			GEO_BRANCH(1, ccr_dl_030_object_011E2394_002_geo),
			GEO_BRANCH(1, ccr_dl_031_object_011E2294_002_geo),
			GEO_BRANCH(1, ccr_dl_032_object_011E2194_002_geo),
			GEO_BRANCH(1, ccr_dl_033_object_011E2094_002_geo),
			GEO_BRANCH(1, ccr_dl_034_object_011E1F94_002_geo),
			GEO_BRANCH(1, ccr_dl_035_object_011E1E94_002_geo),
			GEO_BRANCH(1, ccr_dl_036_object_011E1D94_002_geo),
			GEO_BRANCH(1, ccr_dl_037_object_011E1C94_002_geo),
			GEO_BRANCH(1, ccr_dl_038_object_011E1B94_002_geo),
			GEO_BRANCH(1, ccr_dl_039_object_011E1A94_002_geo),
			GEO_BRANCH(1, ccr_dl_040_object_011E1994_002_geo),
			GEO_BRANCH(1, ccr_dl_041_object_011E1894_002_geo),
			GEO_BRANCH(1, ccr_dl_042_object_011E1794_002_geo),
			GEO_BRANCH(1, ccr_dl_043_object_011E1694_002_geo),
			GEO_BRANCH(1, ccr_dl_044_object_011E1594_002_geo),
			GEO_BRANCH(1, ccr_dl_045_object_011E1494_002_geo),
			GEO_BRANCH(1, ccr_dl_046_object_011E13C4_002_geo),
			GEO_BRANCH(1, ccr_dl_047_object_011E12F4_002_geo),
			GEO_BRANCH(1, ccr_dl_048_object_011E1224_002_geo),
			GEO_BRANCH(1, ccr_dl_049_object_011E1154_002_geo),
			GEO_BRANCH(1, ccr_dl_050_object_011E1084_002_geo),
			GEO_BRANCH(1, ccr_dl_051_object_011E0FB4_002_geo),
			GEO_BRANCH(1, ccr_dl_052_object_011E0EE4_002_geo),
			GEO_BRANCH(1, ccr_dl_053_object_011E0E14_002_geo),
			GEO_BRANCH(1, ccr_dl_054_object_011E0D44_002_geo),
			GEO_BRANCH(1, ccr_dl_055_object_011E0C74_002_geo),
			GEO_BRANCH(1, ccr_dl_056_object_011E0BA4_002_geo),
			GEO_BRANCH(1, ccr_dl_057_object_011E0AD4_002_geo),
			GEO_BRANCH(1, ccr_dl_058_object_011E0A04_002_geo),
			GEO_BRANCH(1, ccr_dl_059_object_011E0934_002_geo),
			GEO_BRANCH(1, ccr_dl_060_object_011E0864_002_geo),
		GEO_CLOSE_NODE(),
		GEO_SWITCH_CASE(60, geo_cc_switch),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, ccr_dl_001_object_011E3CF4_003_geo),
			GEO_BRANCH(1, ccr_dl_002_object_011E3CF4_003_geo),
			GEO_BRANCH(1, ccr_dl_003_object_011E3C24_003_geo),
			GEO_BRANCH(1, ccr_dl_004_object_011E3B54_003_geo),
			GEO_BRANCH(1, ccr_dl_005_object_011E3A84_003_geo),
			GEO_BRANCH(1, ccr_dl_006_object_011E39B4_003_geo),
			GEO_BRANCH(1, ccr_dl_007_object_011E38E4_003_geo),
			GEO_BRANCH(1, ccr_dl_008_object_011E3814_003_geo),
			GEO_BRANCH(1, ccr_dl_009_object_011E3744_003_geo),
			GEO_BRANCH(1, ccr_dl_010_object_011E3674_003_geo),
			GEO_BRANCH(1, ccr_dl_011_object_011E35A4_003_geo),
			GEO_BRANCH(1, ccr_dl_012_object_011E34D4_003_geo),
			GEO_BRANCH(1, ccr_dl_013_object_011E3404_003_geo),
			GEO_BRANCH(1, ccr_dl_014_object_011E3334_003_geo),
			GEO_BRANCH(1, ccr_dl_015_object_011E3264_003_geo),
			GEO_BRANCH(1, ccr_dl_016_object_011E3194_003_geo),
			GEO_BRANCH(1, ccr_dl_017_object_011E3094_003_geo),
			GEO_BRANCH(1, ccr_dl_018_object_011E2F94_003_geo),
			GEO_BRANCH(1, ccr_dl_019_object_011E2E94_003_geo),
			GEO_BRANCH(1, ccr_dl_020_object_011E2D94_003_geo),
			GEO_BRANCH(1, ccr_dl_021_object_011E2C94_003_geo),
			GEO_BRANCH(1, ccr_dl_022_object_011E2B94_003_geo),
			GEO_BRANCH(1, ccr_dl_023_object_011E2A94_003_geo),
			GEO_BRANCH(1, ccr_dl_024_object_011E2994_003_geo),
			GEO_BRANCH(1, ccr_dl_025_object_011E2894_003_geo),
			GEO_BRANCH(1, ccr_dl_026_object_011E2794_003_geo),
			GEO_BRANCH(1, ccr_dl_027_object_011E2694_003_geo),
			GEO_BRANCH(1, ccr_dl_028_object_011E2594_003_geo),
			GEO_BRANCH(1, ccr_dl_029_object_011E2494_003_geo),
			GEO_BRANCH(1, ccr_dl_030_object_011E2394_003_geo),
			GEO_BRANCH(1, ccr_dl_031_object_011E2294_003_geo),
			GEO_BRANCH(1, ccr_dl_032_object_011E2194_003_geo),
			GEO_BRANCH(1, ccr_dl_033_object_011E2094_003_geo),
			GEO_BRANCH(1, ccr_dl_034_object_011E1F94_003_geo),
			GEO_BRANCH(1, ccr_dl_035_object_011E1E94_003_geo),
			GEO_BRANCH(1, ccr_dl_036_object_011E1D94_003_geo),
			GEO_BRANCH(1, ccr_dl_037_object_011E1C94_003_geo),
			GEO_BRANCH(1, ccr_dl_038_object_011E1B94_003_geo),
			GEO_BRANCH(1, ccr_dl_039_object_011E1A94_003_geo),
			GEO_BRANCH(1, ccr_dl_040_object_011E1994_003_geo),
			GEO_BRANCH(1, ccr_dl_041_object_011E1894_003_geo),
			GEO_BRANCH(1, ccr_dl_042_object_011E1794_003_geo),
			GEO_BRANCH(1, ccr_dl_043_object_011E1694_003_geo),
			GEO_BRANCH(1, ccr_dl_044_object_011E1594_003_geo),
			GEO_BRANCH(1, ccr_dl_045_object_011E1494_003_geo),
			GEO_BRANCH(1, ccr_dl_046_object_011E13C4_003_geo),
			GEO_BRANCH(1, ccr_dl_047_object_011E12F4_003_geo),
			GEO_BRANCH(1, ccr_dl_048_object_011E1224_003_geo),
			GEO_BRANCH(1, ccr_dl_049_object_011E1154_003_geo),
			GEO_BRANCH(1, ccr_dl_050_object_011E1084_003_geo),
			GEO_BRANCH(1, ccr_dl_051_object_011E0FB4_003_geo),
			GEO_BRANCH(1, ccr_dl_052_object_011E0EE4_003_geo),
			GEO_BRANCH(1, ccr_dl_053_object_011E0E14_003_geo),
			GEO_BRANCH(1, ccr_dl_054_object_011E0D44_003_geo),
			GEO_BRANCH(1, ccr_dl_055_object_011E0C74_003_geo),
			GEO_BRANCH(1, ccr_dl_056_object_011E0BA4_003_geo),
			GEO_BRANCH(1, ccr_dl_057_object_011E0AD4_003_geo),
			GEO_BRANCH(1, ccr_dl_058_object_011E0A04_003_geo),
			GEO_BRANCH(1, ccr_dl_059_object_011E0934_003_geo),
			GEO_BRANCH(1, ccr_dl_060_object_011E0864_003_geo),
		GEO_CLOSE_NODE(),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_object_011B005C_mesh_layer_1),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_object_011B3C1C_mesh_layer_5),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_object_011B3D1C_mesh_layer_5),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_object_011CDC2C_mesh_layer_5),
		GEO_LVL_BATCH_TRANSLATE_NODE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_object_011CDD2C_mesh_layer_5),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, (f32)800.0, (f32)200.00009536743164, (f32)800.0, (f32)6.830189170012751e-06, (f32)-179.999991348578, (f32)1.0313298951447214e-12, ccr_dl_rainbow_mesh_layer_5),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, (f32)-787.6600646972656, (f32)1150.0003814697266, (f32)731.3005828857422, (f32)6.830189170012751e-06, (f32)-179.999991348578, (f32)1.0313298951447214e-12, ccr_dl_rainbow_001_mesh_layer_5),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, (f32)714.7996520996094, (f32)1149.9999237060547, (f32)-798.3274841308594, (f32)-6.830191612678746e-06, (f32)-89.99996835353231, (f32)1.3660375083137507e-05, ccr_dl_rainbow_002_mesh_layer_5),
		GEO_LVL_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, (f32)799.9998474121094, (f32)200.00009536743164, (f32)801.6664886474609, (f32)-6.830191612678746e-06, (f32)-89.99996835353231, (f32)1.3660375083137507e-05, ccr_dl_rainbow_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_001_object_011C808C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_001_object_011C8AFC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_002_object_011C808C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_002_object_011C808C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_003_object_011C761C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_003_object_011C761C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_004_object_011C6BAC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_004_object_011C6BAC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_005_object_011C613C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_005_object_011C613C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_006_object_011C56CC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_006_object_011C56CC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_007_object_011C4C5C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_007_object_011C4C5C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_008_object_011C41EC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_008_object_011C41EC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_009_object_011C377C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_009_object_011C377C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_010_object_011C2D0C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_010_object_011C2D0C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_011_object_011C229C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_011_object_011C229C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_012_object_011C182C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_012_object_011C182C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_013_object_011C0DBC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_013_object_011C0DBC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_014_object_011C034C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_014_object_011C034C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_015_object_011BF8DC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_015_object_011BF8DC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_016_object_011BEE6C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_016_object_011BEE6C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_017_object_011BE3FC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_017_object_011BE3FC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_018_object_011BD98C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_018_object_011BD98C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_019_object_011BCF1C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_019_object_011BCF1C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_020_object_011BC4AC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_020_object_011BC4AC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_021_object_011BBA3C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_021_object_011BBA3C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_022_object_011BAFCC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_022_object_011BAFCC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_023_object_011BA55C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_023_object_011BA55C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_024_object_011B9AEC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_024_object_011B9AEC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_025_object_011B907C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_025_object_011B907C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_026_object_011B860C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_026_object_011B860C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_027_object_011B7B9C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_027_object_011B7B9C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_028_object_011B712C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_028_object_011B712C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_029_object_011B66BC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_029_object_011B66BC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_030_object_011B5C4C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_030_object_011B5C4C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_031_object_011B51DC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_031_object_011B51DC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_032_object_011B476C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_032_object_011B476C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_001_object_011CD4D4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_001_object_011CD8B4_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_002_object_011CD4D4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_002_object_011CD4D4_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_003_object_011CD0F4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_003_object_011CD0F4_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_004_object_011CCD14_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_004_object_011CCD14_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_005_object_011CC934_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_005_object_011CC934_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_006_object_011CC554_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_006_object_011CC554_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_007_object_011CC174_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_007_object_011CC174_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_008_object_011CBD94_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_008_object_011CBD94_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_009_object_011CB9B4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_009_object_011CB9B4_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_010_object_011CB5D4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_010_object_011CB5D4_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_011_object_011CB1F4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_011_object_011CB1F4_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_012_object_011CAE14_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_012_object_011CAE14_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_013_object_011CAA34_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_013_object_011CAA34_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_014_object_011CA654_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_014_object_011CA654_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_015_object_011CA274_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_015_object_011CA274_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_016_object_011C9E94_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_016_object_011C9E94_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_017_object_011C9AB4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_017_object_011C9AB4_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_018_object_011C96D4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_018_object_011C96D4_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_019_object_011C92F4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_019_object_011C92F4_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_020_object_011C8F14_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_020_object_011C8F14_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_001_object_011F507C_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-3000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_001_object_011F5FEC_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_002_object_011F507C_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-3000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_002_object_011F507C_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_003_object_011F410C_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-3000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_003_object_011F410C_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_004_object_011F3164_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-3000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_004_object_011F3164_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_005_object_011F21E4_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-3000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_005_object_011F21E4_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_006_object_011F1254_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-3000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_006_object_011F1254_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_007_object_011F02DC_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-3000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_007_object_011F02DC_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_008_object_011EF334_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-3000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_008_object_011EF334_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_009_object_011EE3C4_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-3000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_009_object_011EE3C4_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_010_object_011ED454_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-3000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_010_object_011ED454_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_011_object_011EC4E4_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-3000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_011_object_011EC4E4_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_012_object_011EB574_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-3000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_012_object_011EB574_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_013_object_011EA5FC_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-3000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_013_object_011EA5FC_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_014_object_011E967C_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-3000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_014_object_011E967C_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_015_object_011E8704_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-3000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_015_object_011E8704_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_016_object_011E7784_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-3000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_016_object_011E7784_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_001_object_011F507C_001_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-4000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_001_object_011F5FEC_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_002_object_011F507C_001_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-4000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_002_object_011F507C_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_003_object_011F410C_001_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-4000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_003_object_011F410C_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_004_object_011F3164_001_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-4000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_004_object_011F3164_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_005_object_011F21E4_001_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-4000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_005_object_011F21E4_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_006_object_011F1254_001_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-4000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_006_object_011F1254_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_007_object_011F02DC_001_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-4000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_007_object_011F02DC_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_008_object_011EF334_001_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-4000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_008_object_011EF334_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_009_object_011EE3C4_001_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-4000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_009_object_011EE3C4_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_010_object_011ED454_001_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-4000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_010_object_011ED454_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_011_object_011EC4E4_001_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-4000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_011_object_011EC4E4_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_012_object_011EB574_001_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-4000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_012_object_011EB574_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_013_object_011EA5FC_001_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-4000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_013_object_011EA5FC_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_014_object_011E967C_001_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-4000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_014_object_011E967C_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_015_object_011E8704_001_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-4000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_015_object_011E8704_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_016_object_011E7784_001_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-4000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_016_object_011E7784_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_001_object_011F507C_002_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-5000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_001_object_011F5FEC_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_002_object_011F507C_002_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-5000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_002_object_011F507C_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_003_object_011F410C_002_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-5000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_003_object_011F410C_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_004_object_011F3164_002_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-5000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_004_object_011F3164_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_005_object_011F21E4_002_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-5000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_005_object_011F21E4_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_006_object_011F1254_002_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-5000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_006_object_011F1254_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_007_object_011F02DC_002_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-5000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_007_object_011F02DC_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_008_object_011EF334_002_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-5000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_008_object_011EF334_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_009_object_011EE3C4_002_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-5000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_009_object_011EE3C4_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_010_object_011ED454_002_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-5000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_010_object_011ED454_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_011_object_011EC4E4_002_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-5000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_011_object_011EC4E4_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_012_object_011EB574_002_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-5000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_012_object_011EB574_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_013_object_011EA5FC_002_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-5000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_013_object_011EA5FC_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_014_object_011E967C_002_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-5000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_014_object_011E967C_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_015_object_011E8704_002_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-5000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_015_object_011E8704_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_016_object_011E7784_002_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-5000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_016_object_011E7784_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_001_object_011F507C_003_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-3000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_001_object_011F5FEC_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_002_object_011F507C_003_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-3000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_002_object_011F507C_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_003_object_011F410C_003_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-3000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_003_object_011F410C_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_004_object_011F3164_003_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-3000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_004_object_011F3164_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_005_object_011F21E4_003_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-3000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_005_object_011F21E4_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_006_object_011F1254_003_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-3000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_006_object_011F1254_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_007_object_011F02DC_003_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-3000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_007_object_011F02DC_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_008_object_011EF334_003_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-3000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_008_object_011EF334_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_009_object_011EE3C4_003_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-3000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_009_object_011EE3C4_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_010_object_011ED454_003_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-3000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_010_object_011ED454_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_011_object_011EC4E4_003_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-3000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_011_object_011EC4E4_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_012_object_011EB574_003_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-3000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_012_object_011EB574_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_013_object_011EA5FC_003_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-3000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_013_object_011EA5FC_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_014_object_011E967C_003_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-3000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_014_object_011E967C_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_015_object_011E8704_003_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-3000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_015_object_011E8704_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_016_object_011E7784_003_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-3000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_016_object_011E7784_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_001_object_011FA8FC_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-2500.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_001_object_011FB10C_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_002_object_011FA8FC_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-2500.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_002_object_011FA8FC_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_003_object_011FA0D4_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-2500.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_003_object_011FA0D4_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_004_object_011F98AC_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-2500.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_004_object_011F98AC_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_005_object_011F9084_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-2500.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_005_object_011F9084_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_006_object_011F8874_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-2500.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_006_object_011F8874_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_007_object_011F804C_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-2500.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_007_object_011F804C_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_008_object_011F783C_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-2500.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_008_object_011F783C_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_009_object_011F7034_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-2500.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_009_object_011F7034_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_010_object_011F682C_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-2500.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_010_object_011F682C_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_001_object_011FA8FC_001_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)-1200.0, (s16)-6500.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_001_object_011FB10C_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_002_object_011FA8FC_001_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)-1200.0, (s16)-6500.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_002_object_011FA8FC_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_003_object_011FA0D4_001_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)-1200.0, (s16)-6500.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_003_object_011FA0D4_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_004_object_011F98AC_001_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)-1200.0, (s16)-6500.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_004_object_011F98AC_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_005_object_011F9084_001_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)-1200.0, (s16)-6500.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_005_object_011F9084_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_006_object_011F8874_001_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)-1200.0, (s16)-6500.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_006_object_011F8874_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_007_object_011F804C_001_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)-1200.0, (s16)-6500.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_007_object_011F804C_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_008_object_011F783C_001_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)-1200.0, (s16)-6500.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_008_object_011F783C_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_009_object_011F7034_001_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)-1200.0, (s16)-6500.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_009_object_011F7034_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_010_object_011F682C_001_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)-1200.0, (s16)-6500.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_010_object_011F682C_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_001_object_011FA8FC_002_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-2500.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_001_object_011FB10C_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_002_object_011FA8FC_002_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-2500.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_002_object_011FA8FC_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_003_object_011FA0D4_002_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-2500.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_003_object_011FA0D4_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_004_object_011F98AC_002_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-2500.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_004_object_011F98AC_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_005_object_011F9084_002_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-2500.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_005_object_011F9084_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_006_object_011F8874_002_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-2500.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_006_object_011F8874_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_007_object_011F804C_002_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-2500.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_007_object_011F804C_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_008_object_011F783C_002_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-2500.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_008_object_011F783C_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_009_object_011F7034_002_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-2500.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_009_object_011F7034_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_010_object_011F682C_002_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-2500.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_010_object_011F682C_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_001_object_011FFA6C_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-6000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_001_object_012002AC_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_002_object_011FFA6C_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-6000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_002_object_011FFA6C_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_003_object_011FF254_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-6000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_003_object_011FF254_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_004_object_011FEA2C_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-6000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_004_object_011FEA2C_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_005_object_011FE204_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-6000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_005_object_011FE204_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_006_object_011FD9DC_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-6000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_006_object_011FD9DC_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_007_object_011FD1CC_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-6000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_007_object_011FD1CC_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_008_object_011FC9BC_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-6000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_008_object_011FC9BC_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_009_object_011FC184_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-6000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_009_object_011FC184_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_010_object_011FB96C_geo[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, (s16)-6000.0, (s16)300.0, (s16)0.0, (s16)-0.0, (s16)90.00000933466734, (s16)0.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_010_object_011FB96C_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_001_object_011FFA6C_001_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)-1200.0, (s16)-7000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_001_object_012002AC_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_002_object_011FFA6C_001_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)-1200.0, (s16)-7000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_002_object_011FFA6C_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_003_object_011FF254_001_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)-1200.0, (s16)-7000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_003_object_011FF254_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_004_object_011FEA2C_001_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)-1200.0, (s16)-7000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_004_object_011FEA2C_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_005_object_011FE204_001_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)-1200.0, (s16)-7000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_005_object_011FE204_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_006_object_011FD9DC_001_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)-1200.0, (s16)-7000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_006_object_011FD9DC_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_007_object_011FD1CC_001_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)-1200.0, (s16)-7000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_007_object_011FD1CC_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_008_object_011FC9BC_001_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)-1200.0, (s16)-7000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_008_object_011FC9BC_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_009_object_011FC184_001_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)-1200.0, (s16)-7000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_009_object_011FC184_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_010_object_011FB96C_001_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)-1200.0, (s16)-7000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_010_object_011FB96C_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_001_object_011FFA6C_002_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-4000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_001_object_012002AC_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_002_object_011FFA6C_002_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-4000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_002_object_011FFA6C_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_003_object_011FF254_002_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-4000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_003_object_011FF254_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_004_object_011FEA2C_002_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-4000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_004_object_011FEA2C_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_005_object_011FE204_002_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-4000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_005_object_011FE204_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_006_object_011FD9DC_002_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-4000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_006_object_011FD9DC_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_007_object_011FD1CC_002_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-4000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_007_object_011FD1CC_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_008_object_011FC9BC_002_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-4000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_008_object_011FC9BC_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_009_object_011FC184_002_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-4000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_009_object_011FC184_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_010_object_011FB96C_002_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, (s16)0.0, (s16)300.0, (s16)-4000.0),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_010_object_011FB96C_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_001_object_01208A14_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_001_object_01208C04_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_002_object_01208A14_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_002_object_01208A14_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_003_object_01208824_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_003_object_01208824_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_004_object_01208634_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_004_object_01208634_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_005_object_01208444_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_005_object_01208444_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_006_object_01208254_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_006_object_01208254_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_007_object_01208064_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_007_object_01208064_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_008_object_01207E74_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_008_object_01207E74_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_009_object_01207C7C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_009_object_01207C7C_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_010_object_01207A8C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_010_object_01207A8C_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_011_object_012078A4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_011_object_012078A4_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_012_object_012076B4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_012_object_012076B4_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_013_object_012074C4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_013_object_012074C4_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_014_object_012072D4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_014_object_012072D4_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_015_object_012070E4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_015_object_012070E4_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_016_object_01206EF4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_016_object_01206EF4_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_017_object_01206CE4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_017_object_01206CE4_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_018_object_01206AF4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_018_object_01206AF4_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_019_object_01206904_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_019_object_01206904_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_020_object_0120671C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_020_object_0120671C_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_021_object_0120652C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_021_object_0120652C_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_022_object_01206344_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_022_object_01206344_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_023_object_0120615C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_023_object_0120615C_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_024_object_01205F4C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_024_object_01205F4C_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_025_object_01205D64_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_025_object_01205D64_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_026_object_01205B84_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_026_object_01205B84_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_027_object_012059A4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_027_object_012059A4_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_028_object_012057C4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_028_object_012057C4_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_029_object_012055E4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_029_object_012055E4_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_030_object_012053FC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_030_object_012053FC_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_031_object_0120521C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_031_object_0120521C_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_032_object_0120503C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_032_object_0120503C_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_033_object_01204E5C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_033_object_01204E5C_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_034_object_01204C7C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_034_object_01204C7C_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_035_object_01204A9C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_035_object_01204A9C_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_036_object_012048BC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_OPAQUE, 0, 0, 0, ccr_dl_036_object_012048BC_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_037_object_012046DC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_037_object_012046DC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_038_object_012045DC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_038_object_012045DC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_039_object_012044DC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_039_object_012044DC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_040_object_012043DC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_040_object_012043DC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_041_object_012042DC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_041_object_012042DC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_042_object_012041DC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_042_object_012041DC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_043_object_012040DC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_043_object_012040DC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_044_object_01203FDC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_044_object_01203FDC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_045_object_01203EDC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_045_object_01203EDC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_046_object_01203DDC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_046_object_01203DDC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_047_object_01203CDC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_047_object_01203CDC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_048_object_01203BDC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_048_object_01203BDC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_049_object_01203ADC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_049_object_01203ADC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_050_object_012039DC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_050_object_012039DC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_051_object_012038DC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_051_object_012038DC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_001_object_0120D1B4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_001_object_0120D2EC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_002_object_0120D1B4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_002_object_0120D1B4_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_003_object_0120D00C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_003_object_0120D00C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_004_object_0120CDF4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_004_object_0120CDF4_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_005_object_0120CB54_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_005_object_0120CB54_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_006_object_0120C854_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_006_object_0120C854_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_007_object_0120C4EC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_007_object_0120C4EC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_008_object_0120C124_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_008_object_0120C124_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_009_object_0120BCF4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_009_object_0120BCF4_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_010_object_0120B844_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_010_object_0120B844_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_011_object_0120B32C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_011_object_0120B32C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_012_object_0120ADB4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_012_object_0120ADB4_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_013_object_0120A7C4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_013_object_0120A7C4_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_014_object_0120A14C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_014_object_0120A14C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_015_object_01209A8C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_015_object_01209A8C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_016_object_01209364_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_016_object_01209364_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_001_object_011E068C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_001_object_011E075C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_002_object_011E068C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_002_object_011E068C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_003_object_011E05BC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_003_object_011E05BC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_004_object_011E04EC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_004_object_011E04EC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_005_object_011E041C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_005_object_011E041C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_006_object_011E034C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_006_object_011E034C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_007_object_011E027C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_007_object_011E027C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_008_object_011E01AC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_008_object_011E01AC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_009_object_011E00DC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_009_object_011E00DC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_010_object_011E000C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_010_object_011E000C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_011_object_011DFF3C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_011_object_011DFF3C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_012_object_011DFE6C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_012_object_011DFE6C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_013_object_011DFD9C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_013_object_011DFD9C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_014_object_011DFCCC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_014_object_011DFCCC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_015_object_011DFBFC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_015_object_011DFBFC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_016_object_011DFB2C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_016_object_011DFB2C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_017_object_011DFA2C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_017_object_011DFA2C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_018_object_011DF92C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_018_object_011DF92C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_019_object_011DF82C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_019_object_011DF82C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_020_object_011DF72C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_020_object_011DF72C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_021_object_011DF62C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_021_object_011DF62C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_022_object_011DF52C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_022_object_011DF52C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_023_object_011DF42C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_023_object_011DF42C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_024_object_011DF32C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_024_object_011DF32C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_025_object_011DF22C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_025_object_011DF22C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_026_object_011DF12C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_026_object_011DF12C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_027_object_011DF02C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_027_object_011DF02C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_028_object_011DEF2C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_028_object_011DEF2C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_029_object_011DEE2C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_029_object_011DEE2C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_030_object_011DED2C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_030_object_011DED2C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_031_object_011DEC2C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_031_object_011DEC2C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_032_object_011DEB2C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_032_object_011DEB2C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_033_object_011DEA2C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_033_object_011DEA2C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_034_object_011DE92C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_034_object_011DE92C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_035_object_011DE82C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_035_object_011DE82C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_036_object_011DE72C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_036_object_011DE72C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_037_object_011DE62C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_037_object_011DE62C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_038_object_011DE52C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_038_object_011DE52C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_039_object_011DE42C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_039_object_011DE42C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_040_object_011DE32C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_040_object_011DE32C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_041_object_011DE22C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_041_object_011DE22C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_042_object_011DE12C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_042_object_011DE12C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_043_object_011DE02C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_043_object_011DE02C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_044_object_011DDF2C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_044_object_011DDF2C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_045_object_011DDE2C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_045_object_011DDE2C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_046_object_011DDD5C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_046_object_011DDD5C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_047_object_011DDC8C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_047_object_011DDC8C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_048_object_011DDBBC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_048_object_011DDBBC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_049_object_011DDAEC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_049_object_011DDAEC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_050_object_011DDA1C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_050_object_011DDA1C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_051_object_011DD94C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_051_object_011DD94C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_052_object_011DD87C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_052_object_011DD87C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_053_object_011DD7AC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_053_object_011DD7AC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_054_object_011DD6DC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_054_object_011DD6DC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_055_object_011DD60C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_055_object_011DD60C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_056_object_011DD53C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_056_object_011DD53C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_057_object_011DD46C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_057_object_011DD46C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_058_object_011DD39C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_058_object_011DD39C_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_059_object_011DD2CC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_059_object_011DD2CC_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_060_object_011DD224_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_060_object_011DD224_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_001_object_011E068C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_001_object_011E075C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_002_object_011E068C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_002_object_011E068C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_003_object_011E05BC_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_003_object_011E05BC_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_004_object_011E04EC_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_004_object_011E04EC_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_005_object_011E041C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_005_object_011E041C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_006_object_011E034C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_006_object_011E034C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_007_object_011E027C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_007_object_011E027C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_008_object_011E01AC_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_008_object_011E01AC_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_009_object_011E00DC_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_009_object_011E00DC_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_010_object_011E000C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_010_object_011E000C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_011_object_011DFF3C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_011_object_011DFF3C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_012_object_011DFE6C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_012_object_011DFE6C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_013_object_011DFD9C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_013_object_011DFD9C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_014_object_011DFCCC_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_014_object_011DFCCC_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_015_object_011DFBFC_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_015_object_011DFBFC_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_016_object_011DFB2C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_016_object_011DFB2C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_017_object_011DFA2C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_017_object_011DFA2C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_018_object_011DF92C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_018_object_011DF92C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_019_object_011DF82C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_019_object_011DF82C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_020_object_011DF72C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_020_object_011DF72C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_021_object_011DF62C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_021_object_011DF62C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_022_object_011DF52C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_022_object_011DF52C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_023_object_011DF42C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_023_object_011DF42C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_024_object_011DF32C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_024_object_011DF32C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_025_object_011DF22C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_025_object_011DF22C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_026_object_011DF12C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_026_object_011DF12C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_027_object_011DF02C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_027_object_011DF02C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_028_object_011DEF2C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_028_object_011DEF2C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_029_object_011DEE2C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_029_object_011DEE2C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_030_object_011DED2C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_030_object_011DED2C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_031_object_011DEC2C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_031_object_011DEC2C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_032_object_011DEB2C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_032_object_011DEB2C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_033_object_011DEA2C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_033_object_011DEA2C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_034_object_011DE92C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_034_object_011DE92C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_035_object_011DE82C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_035_object_011DE82C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_036_object_011DE72C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_036_object_011DE72C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_037_object_011DE62C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_037_object_011DE62C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_038_object_011DE52C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_038_object_011DE52C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_039_object_011DE42C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_039_object_011DE42C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_040_object_011DE32C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_040_object_011DE32C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_041_object_011DE22C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_041_object_011DE22C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_042_object_011DE12C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_042_object_011DE12C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_043_object_011DE02C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_043_object_011DE02C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_044_object_011DDF2C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_044_object_011DDF2C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_045_object_011DDE2C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_045_object_011DDE2C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_046_object_011DDD5C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_046_object_011DDD5C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_047_object_011DDC8C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_047_object_011DDC8C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_048_object_011DDBBC_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_048_object_011DDBBC_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_049_object_011DDAEC_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_049_object_011DDAEC_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_050_object_011DDA1C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_050_object_011DDA1C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_051_object_011DD94C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_051_object_011DD94C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_052_object_011DD87C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_052_object_011DD87C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_053_object_011DD7AC_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_053_object_011DD7AC_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_054_object_011DD6DC_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_054_object_011DD6DC_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_055_object_011DD60C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_055_object_011DD60C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_056_object_011DD53C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_056_object_011DD53C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_057_object_011DD46C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_057_object_011DD46C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_058_object_011DD39C_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_058_object_011DD39C_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_059_object_011DD2CC_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_059_object_011DD2CC_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_060_object_011DD224_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_060_object_011DD224_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_001_object_011E068C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_001_object_011E075C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_002_object_011E068C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_002_object_011E068C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_003_object_011E05BC_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_003_object_011E05BC_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_004_object_011E04EC_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_004_object_011E04EC_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_005_object_011E041C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_005_object_011E041C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_006_object_011E034C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_006_object_011E034C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_007_object_011E027C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_007_object_011E027C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_008_object_011E01AC_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_008_object_011E01AC_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_009_object_011E00DC_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_009_object_011E00DC_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_010_object_011E000C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_010_object_011E000C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_011_object_011DFF3C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_011_object_011DFF3C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_012_object_011DFE6C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_012_object_011DFE6C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_013_object_011DFD9C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_013_object_011DFD9C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_014_object_011DFCCC_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_014_object_011DFCCC_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_015_object_011DFBFC_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_015_object_011DFBFC_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_016_object_011DFB2C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_016_object_011DFB2C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_017_object_011DFA2C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_017_object_011DFA2C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_018_object_011DF92C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_018_object_011DF92C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_019_object_011DF82C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_019_object_011DF82C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_020_object_011DF72C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_020_object_011DF72C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_021_object_011DF62C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_021_object_011DF62C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_022_object_011DF52C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_022_object_011DF52C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_023_object_011DF42C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_023_object_011DF42C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_024_object_011DF32C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_024_object_011DF32C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_025_object_011DF22C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_025_object_011DF22C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_026_object_011DF12C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_026_object_011DF12C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_027_object_011DF02C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_027_object_011DF02C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_028_object_011DEF2C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_028_object_011DEF2C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_029_object_011DEE2C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_029_object_011DEE2C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_030_object_011DED2C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_030_object_011DED2C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_031_object_011DEC2C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_031_object_011DEC2C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_032_object_011DEB2C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_032_object_011DEB2C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_033_object_011DEA2C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_033_object_011DEA2C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_034_object_011DE92C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_034_object_011DE92C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_035_object_011DE82C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_035_object_011DE82C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_036_object_011DE72C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_036_object_011DE72C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_037_object_011DE62C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_037_object_011DE62C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_038_object_011DE52C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_038_object_011DE52C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_039_object_011DE42C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_039_object_011DE42C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_040_object_011DE32C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_040_object_011DE32C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_041_object_011DE22C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_041_object_011DE22C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_042_object_011DE12C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_042_object_011DE12C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_043_object_011DE02C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_043_object_011DE02C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_044_object_011DDF2C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_044_object_011DDF2C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_045_object_011DDE2C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_045_object_011DDE2C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_046_object_011DDD5C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_046_object_011DDD5C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_047_object_011DDC8C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_047_object_011DDC8C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_048_object_011DDBBC_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_048_object_011DDBBC_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_049_object_011DDAEC_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_049_object_011DDAEC_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_050_object_011DDA1C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_050_object_011DDA1C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_051_object_011DD94C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_051_object_011DD94C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_052_object_011DD87C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_052_object_011DD87C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_053_object_011DD7AC_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_053_object_011DD7AC_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_054_object_011DD6DC_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_054_object_011DD6DC_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_055_object_011DD60C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_055_object_011DD60C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_056_object_011DD53C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_056_object_011DD53C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_057_object_011DD46C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_057_object_011DD46C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_058_object_011DD39C_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_058_object_011DD39C_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_059_object_011DD2CC_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_059_object_011DD2CC_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_060_object_011DD224_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_060_object_011DD224_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_001_object_011E068C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_001_object_011E075C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_002_object_011E068C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_002_object_011E068C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_003_object_011E05BC_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_003_object_011E05BC_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_004_object_011E04EC_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_004_object_011E04EC_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_005_object_011E041C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_005_object_011E041C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_006_object_011E034C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_006_object_011E034C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_007_object_011E027C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_007_object_011E027C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_008_object_011E01AC_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_008_object_011E01AC_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_009_object_011E00DC_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_009_object_011E00DC_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_010_object_011E000C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_010_object_011E000C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_011_object_011DFF3C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_011_object_011DFF3C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_012_object_011DFE6C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_012_object_011DFE6C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_013_object_011DFD9C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_013_object_011DFD9C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_014_object_011DFCCC_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_014_object_011DFCCC_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_015_object_011DFBFC_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_015_object_011DFBFC_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_016_object_011DFB2C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_016_object_011DFB2C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_017_object_011DFA2C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_017_object_011DFA2C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_018_object_011DF92C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_018_object_011DF92C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_019_object_011DF82C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_019_object_011DF82C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_020_object_011DF72C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_020_object_011DF72C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_021_object_011DF62C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_021_object_011DF62C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_022_object_011DF52C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_022_object_011DF52C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_023_object_011DF42C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_023_object_011DF42C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_024_object_011DF32C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_024_object_011DF32C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_025_object_011DF22C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_025_object_011DF22C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_026_object_011DF12C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_026_object_011DF12C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_027_object_011DF02C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_027_object_011DF02C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_028_object_011DEF2C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_028_object_011DEF2C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_029_object_011DEE2C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_029_object_011DEE2C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_030_object_011DED2C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_030_object_011DED2C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_031_object_011DEC2C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_031_object_011DEC2C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_032_object_011DEB2C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_032_object_011DEB2C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_033_object_011DEA2C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_033_object_011DEA2C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_034_object_011DE92C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_034_object_011DE92C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_035_object_011DE82C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_035_object_011DE82C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_036_object_011DE72C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_036_object_011DE72C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_037_object_011DE62C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_037_object_011DE62C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_038_object_011DE52C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_038_object_011DE52C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_039_object_011DE42C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_039_object_011DE42C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_040_object_011DE32C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_040_object_011DE32C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_041_object_011DE22C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_041_object_011DE22C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_042_object_011DE12C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_042_object_011DE12C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_043_object_011DE02C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_043_object_011DE02C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_044_object_011DDF2C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_044_object_011DDF2C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_045_object_011DDE2C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_045_object_011DDE2C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_046_object_011DDD5C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_046_object_011DDD5C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_047_object_011DDC8C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_047_object_011DDC8C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_048_object_011DDBBC_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_048_object_011DDBBC_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_049_object_011DDAEC_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_049_object_011DDAEC_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_050_object_011DDA1C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_050_object_011DDA1C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_051_object_011DD94C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_051_object_011DD94C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_052_object_011DD87C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_052_object_011DD87C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_053_object_011DD7AC_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_053_object_011DD7AC_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_054_object_011DD6DC_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_054_object_011DD6DC_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_055_object_011DD60C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_055_object_011DD60C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_056_object_011DD53C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_056_object_011DD53C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_057_object_011DD46C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_057_object_011DD46C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_058_object_011DD39C_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_058_object_011DD39C_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_059_object_011DD2CC_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_059_object_011DD2CC_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_060_object_011DD224_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_060_object_011DD224_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_001_object_011E3CF4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_001_object_011E3DC4_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_002_object_011E3CF4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_002_object_011E3CF4_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_003_object_011E3C24_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_003_object_011E3C24_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_004_object_011E3B54_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_004_object_011E3B54_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_005_object_011E3A84_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_005_object_011E3A84_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_006_object_011E39B4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_006_object_011E39B4_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_007_object_011E38E4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_007_object_011E38E4_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_008_object_011E3814_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_008_object_011E3814_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_009_object_011E3744_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_009_object_011E3744_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_010_object_011E3674_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_010_object_011E3674_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_011_object_011E35A4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_011_object_011E35A4_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_012_object_011E34D4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_012_object_011E34D4_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_013_object_011E3404_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_013_object_011E3404_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_014_object_011E3334_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_014_object_011E3334_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_015_object_011E3264_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_015_object_011E3264_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_016_object_011E3194_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_016_object_011E3194_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_017_object_011E3094_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_017_object_011E3094_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_018_object_011E2F94_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_018_object_011E2F94_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_019_object_011E2E94_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_019_object_011E2E94_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_020_object_011E2D94_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_020_object_011E2D94_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_021_object_011E2C94_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_021_object_011E2C94_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_022_object_011E2B94_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_022_object_011E2B94_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_023_object_011E2A94_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_023_object_011E2A94_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_024_object_011E2994_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_024_object_011E2994_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_025_object_011E2894_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_025_object_011E2894_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_026_object_011E2794_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_026_object_011E2794_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_027_object_011E2694_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_027_object_011E2694_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_028_object_011E2594_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_028_object_011E2594_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_029_object_011E2494_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_029_object_011E2494_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_030_object_011E2394_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_030_object_011E2394_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_031_object_011E2294_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_031_object_011E2294_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_032_object_011E2194_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_032_object_011E2194_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_033_object_011E2094_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_033_object_011E2094_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_034_object_011E1F94_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_034_object_011E1F94_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_035_object_011E1E94_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_035_object_011E1E94_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_036_object_011E1D94_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_036_object_011E1D94_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_037_object_011E1C94_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_037_object_011E1C94_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_038_object_011E1B94_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_038_object_011E1B94_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_039_object_011E1A94_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_039_object_011E1A94_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_040_object_011E1994_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_040_object_011E1994_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_041_object_011E1894_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_041_object_011E1894_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_042_object_011E1794_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_042_object_011E1794_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_043_object_011E1694_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_043_object_011E1694_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_044_object_011E1594_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_044_object_011E1594_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_045_object_011E1494_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_045_object_011E1494_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_046_object_011E13C4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_046_object_011E13C4_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_047_object_011E12F4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_047_object_011E12F4_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_048_object_011E1224_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_048_object_011E1224_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_049_object_011E1154_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_049_object_011E1154_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_050_object_011E1084_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_050_object_011E1084_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_051_object_011E0FB4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_051_object_011E0FB4_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_052_object_011E0EE4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_052_object_011E0EE4_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_053_object_011E0E14_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_053_object_011E0E14_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_054_object_011E0D44_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_054_object_011E0D44_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_055_object_011E0C74_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_055_object_011E0C74_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_056_object_011E0BA4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_056_object_011E0BA4_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_057_object_011E0AD4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_057_object_011E0AD4_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_058_object_011E0A04_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_058_object_011E0A04_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_059_object_011E0934_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_059_object_011E0934_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_060_object_011E0864_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE(LAYER_TRANSPARENT, 0, 0, 0, ccr_dl_060_object_011E0864_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_001_object_011E3CF4_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_001_object_011E3DC4_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_002_object_011E3CF4_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_002_object_011E3CF4_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_003_object_011E3C24_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_003_object_011E3C24_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_004_object_011E3B54_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_004_object_011E3B54_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_005_object_011E3A84_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_005_object_011E3A84_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_006_object_011E39B4_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_006_object_011E39B4_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_007_object_011E38E4_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_007_object_011E38E4_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_008_object_011E3814_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_008_object_011E3814_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_009_object_011E3744_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_009_object_011E3744_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_010_object_011E3674_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_010_object_011E3674_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_011_object_011E35A4_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_011_object_011E35A4_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_012_object_011E34D4_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_012_object_011E34D4_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_013_object_011E3404_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_013_object_011E3404_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_014_object_011E3334_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_014_object_011E3334_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_015_object_011E3264_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_015_object_011E3264_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_016_object_011E3194_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_016_object_011E3194_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_017_object_011E3094_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_017_object_011E3094_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_018_object_011E2F94_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_018_object_011E2F94_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_019_object_011E2E94_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_019_object_011E2E94_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_020_object_011E2D94_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_020_object_011E2D94_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_021_object_011E2C94_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_021_object_011E2C94_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_022_object_011E2B94_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_022_object_011E2B94_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_023_object_011E2A94_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_023_object_011E2A94_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_024_object_011E2994_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_024_object_011E2994_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_025_object_011E2894_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_025_object_011E2894_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_026_object_011E2794_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_026_object_011E2794_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_027_object_011E2694_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_027_object_011E2694_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_028_object_011E2594_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_028_object_011E2594_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_029_object_011E2494_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_029_object_011E2494_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_030_object_011E2394_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_030_object_011E2394_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_031_object_011E2294_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_031_object_011E2294_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_032_object_011E2194_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_032_object_011E2194_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_033_object_011E2094_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_033_object_011E2094_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_034_object_011E1F94_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_034_object_011E1F94_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_035_object_011E1E94_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_035_object_011E1E94_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_036_object_011E1D94_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_036_object_011E1D94_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_037_object_011E1C94_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_037_object_011E1C94_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_038_object_011E1B94_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_038_object_011E1B94_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_039_object_011E1A94_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_039_object_011E1A94_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_040_object_011E1994_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_040_object_011E1994_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_041_object_011E1894_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_041_object_011E1894_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_042_object_011E1794_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_042_object_011E1794_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_043_object_011E1694_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_043_object_011E1694_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_044_object_011E1594_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_044_object_011E1594_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_045_object_011E1494_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_045_object_011E1494_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_046_object_011E13C4_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_046_object_011E13C4_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_047_object_011E12F4_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_047_object_011E12F4_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_048_object_011E1224_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_048_object_011E1224_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_049_object_011E1154_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_049_object_011E1154_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_050_object_011E1084_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_050_object_011E1084_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_051_object_011E0FB4_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_051_object_011E0FB4_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_052_object_011E0EE4_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_052_object_011E0EE4_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_053_object_011E0E14_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_053_object_011E0E14_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_054_object_011E0D44_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_054_object_011E0D44_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_055_object_011E0C74_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_055_object_011E0C74_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_056_object_011E0BA4_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_056_object_011E0BA4_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_057_object_011E0AD4_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_057_object_011E0AD4_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_058_object_011E0A04_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_058_object_011E0A04_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_059_object_011E0934_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_059_object_011E0934_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_060_object_011E0864_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830189170012751e-06, (f32)90.00000933466734, (f32)-2.878709675882815e-13, ccr_dl_060_object_011E0864_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_001_object_011E3CF4_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_001_object_011E3DC4_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_002_object_011E3CF4_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_002_object_011E3CF4_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_003_object_011E3C24_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_003_object_011E3C24_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_004_object_011E3B54_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_004_object_011E3B54_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_005_object_011E3A84_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_005_object_011E3A84_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_006_object_011E39B4_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_006_object_011E39B4_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_007_object_011E38E4_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_007_object_011E38E4_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_008_object_011E3814_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_008_object_011E3814_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_009_object_011E3744_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_009_object_011E3744_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_010_object_011E3674_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_010_object_011E3674_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_011_object_011E35A4_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_011_object_011E35A4_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_012_object_011E34D4_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_012_object_011E34D4_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_013_object_011E3404_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_013_object_011E3404_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_014_object_011E3334_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_014_object_011E3334_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_015_object_011E3264_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_015_object_011E3264_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_016_object_011E3194_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_016_object_011E3194_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_017_object_011E3094_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_017_object_011E3094_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_018_object_011E2F94_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_018_object_011E2F94_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_019_object_011E2E94_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_019_object_011E2E94_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_020_object_011E2D94_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_020_object_011E2D94_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_021_object_011E2C94_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_021_object_011E2C94_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_022_object_011E2B94_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_022_object_011E2B94_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_023_object_011E2A94_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_023_object_011E2A94_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_024_object_011E2994_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_024_object_011E2994_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_025_object_011E2894_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_025_object_011E2894_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_026_object_011E2794_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_026_object_011E2794_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_027_object_011E2694_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_027_object_011E2694_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_028_object_011E2594_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_028_object_011E2594_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_029_object_011E2494_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_029_object_011E2494_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_030_object_011E2394_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_030_object_011E2394_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_031_object_011E2294_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_031_object_011E2294_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_032_object_011E2194_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_032_object_011E2194_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_033_object_011E2094_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_033_object_011E2094_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_034_object_011E1F94_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_034_object_011E1F94_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_035_object_011E1E94_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_035_object_011E1E94_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_036_object_011E1D94_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_036_object_011E1D94_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_037_object_011E1C94_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_037_object_011E1C94_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_038_object_011E1B94_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_038_object_011E1B94_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_039_object_011E1A94_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_039_object_011E1A94_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_040_object_011E1994_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_040_object_011E1994_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_041_object_011E1894_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_041_object_011E1894_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_042_object_011E1794_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_042_object_011E1794_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_043_object_011E1694_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_043_object_011E1694_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_044_object_011E1594_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_044_object_011E1594_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_045_object_011E1494_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_045_object_011E1494_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_046_object_011E13C4_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_046_object_011E13C4_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_047_object_011E12F4_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_047_object_011E12F4_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_048_object_011E1224_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_048_object_011E1224_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_049_object_011E1154_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_049_object_011E1154_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_050_object_011E1084_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_050_object_011E1084_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_051_object_011E0FB4_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_051_object_011E0FB4_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_052_object_011E0EE4_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_052_object_011E0EE4_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_053_object_011E0E14_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_053_object_011E0E14_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_054_object_011E0D44_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_054_object_011E0D44_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_055_object_011E0C74_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_055_object_011E0C74_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_056_object_011E0BA4_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_056_object_011E0BA4_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_057_object_011E0AD4_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_057_object_011E0AD4_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_058_object_011E0A04_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_058_object_011E0A04_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_059_object_011E0934_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_059_object_011E0934_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_060_object_011E0864_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)180, (f32)6.147204626094671e-20, ccr_dl_060_object_011E0864_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_001_object_011E3CF4_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_001_object_011E3DC4_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_002_object_011E3CF4_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_002_object_011E3CF4_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_003_object_011E3C24_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_003_object_011E3C24_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_004_object_011E3B54_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_004_object_011E3B54_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_005_object_011E3A84_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_005_object_011E3A84_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_006_object_011E39B4_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_006_object_011E39B4_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_007_object_011E38E4_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_007_object_011E38E4_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_008_object_011E3814_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_008_object_011E3814_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_009_object_011E3744_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_009_object_011E3744_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_010_object_011E3674_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_010_object_011E3674_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_011_object_011E35A4_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_011_object_011E35A4_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_012_object_011E34D4_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_012_object_011E34D4_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_013_object_011E3404_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_013_object_011E3404_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_014_object_011E3334_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_014_object_011E3334_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_015_object_011E3264_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_015_object_011E3264_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_016_object_011E3194_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_016_object_011E3194_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_017_object_011E3094_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_017_object_011E3094_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_018_object_011E2F94_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_018_object_011E2F94_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_019_object_011E2E94_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_019_object_011E2E94_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_020_object_011E2D94_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_020_object_011E2D94_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_021_object_011E2C94_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_021_object_011E2C94_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_022_object_011E2B94_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_022_object_011E2B94_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_023_object_011E2A94_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_023_object_011E2A94_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_024_object_011E2994_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_024_object_011E2994_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_025_object_011E2894_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_025_object_011E2894_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_026_object_011E2794_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_026_object_011E2794_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_027_object_011E2694_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_027_object_011E2694_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_028_object_011E2594_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_028_object_011E2594_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_029_object_011E2494_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_029_object_011E2494_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_030_object_011E2394_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_030_object_011E2394_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_031_object_011E2294_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_031_object_011E2294_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_032_object_011E2194_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_032_object_011E2194_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_033_object_011E2094_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_033_object_011E2094_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_034_object_011E1F94_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_034_object_011E1F94_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_035_object_011E1E94_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_035_object_011E1E94_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_036_object_011E1D94_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_036_object_011E1D94_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_037_object_011E1C94_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_037_object_011E1C94_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_038_object_011E1B94_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_038_object_011E1B94_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_039_object_011E1A94_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_039_object_011E1A94_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_040_object_011E1994_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_040_object_011E1994_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_041_object_011E1894_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_041_object_011E1894_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_042_object_011E1794_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_042_object_011E1794_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_043_object_011E1694_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_043_object_011E1694_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_044_object_011E1594_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_044_object_011E1594_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_045_object_011E1494_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_045_object_011E1494_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_046_object_011E13C4_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_046_object_011E13C4_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_047_object_011E12F4_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_047_object_011E12F4_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_048_object_011E1224_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_048_object_011E1224_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_049_object_011E1154_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_049_object_011E1154_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_050_object_011E1084_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_050_object_011E1084_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_051_object_011E0FB4_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_051_object_011E0FB4_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_052_object_011E0EE4_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_052_object_011E0EE4_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_053_object_011E0E14_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_053_object_011E0E14_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_054_object_011E0D44_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_054_object_011E0D44_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_055_object_011E0C74_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_055_object_011E0C74_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_056_object_011E0BA4_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_056_object_011E0BA4_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_057_object_011E0AD4_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_057_object_011E0AD4_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_058_object_011E0A04_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_058_object_011E0A04_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_059_object_011E0934_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_059_object_011E0934_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccr_dl_060_object_011E0864_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BATCH_TRANSLATE_ROTATE(LAYER_TRANSPARENT, 0, 0, 0, (f32)6.830188355790752e-06, (f32)270, (f32)-2.8787125877675943e-13, ccr_dl_060_object_011E0864_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};

const GeoLayout ccr_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND_COLOR(0x0001),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, 0, 0, -10, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, ccr_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

