#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "make_const_nonconst.h"
#include "levels/cct/header.h"

/* Fast64 begin persistent block [scripts] */
#include "levels/cct/area_1/collision.inc.c"
#include "level_config.h"
extern const GeoLayout cct_area_1[];
static struct LevelConfig cfg = { };
#define SEQ_LEVEL_GRASS 0x43

#define bhvCoinFormation bhvCoinFormationCC
#define bhvGoombaTripletSpawner bhvGoombaTripletSpawnerCC
#define bhvHeaveHo bhvHeaveHoCC
#define bhvSnufit bhvSnufitCC
#define bhvThwomp2 bhvThwomp2CC

/* Fast64 end persistent block [scripts] */

const LevelScript level_cct_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _cct_segment_7SegmentRomStart, _cct_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	LOAD_MODEL_FROM_GEO(MODEL_CCT_TIMESTOP, cct_switch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCT_GATE, cct_goaldoor_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCT_GATE_BREAKA, cct_goaldoor_breaka_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCT_GATE_BREAKB, cct_goaldoor_breakb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCT_GATE_BREAKC, cct_goaldoor_breakc_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCT_SHUTTER_LEFT, cct_shutter_left_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCT_SHUTTER_RIGHT, cct_shutter_right_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCT_PLATFORM_BIG, cct_stepb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCT_PLATFORM, cct_step_geo), 
	/* Fast64 begin persistent block [level commands] */
	LOAD_MODEL_FROM_GEO_NO_HEAP(MODEL_CCT_GATE_HIT, cc_goaldoor_hit_geo), 
	LOAD_MODEL_FROM_GEO_NO_HEAP(MODEL_CCT_GATE_HIT_BREAK, cc_goaldoor_hitbreak_geo), 
	LVL_CONFIG(&cfg),
	/* Fast64 end persistent block [level commands] */

	AREA(1, cct_area_1, 0, 0, 0),
		WARP_NODE(0x0A, LEVEL_CCE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, 1569, 1076, -4649),
		OBJECT(MODEL_CHECKPOINT, 2789, 1076, -1116, 0, 180, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_NONE, 2799, 7155, 1532, 0, 90, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -9900, -5924, -9157, 0, 90, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -9900, -5924, -8112, 0, 90, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -8494, -5524, -13998, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -11313, -5524, -13998, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 9995, 7156, 5004, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 9995, 7156, 7509, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 2789, 1076, -1692, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -7365, -5924, -5402, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -9902, -5924, -5407, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -9915, -5924, -12140, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -9907, -5124, -15005, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 10002, 7156, 10006, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -9895, -5124, -15620, 0, -180, 0, (4 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -3234, -561, -5504, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -3234, -2034, -5504, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -3234, -3818, -5504, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -9882, -5606, -9792, 0, 90, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 10005, 7156, 8751, 0, 0, 0, 0x00000000, bhvShutter),
		OBJECT(MODEL_NONE, 10005, 7156, 6244, 0, 0, 0, 0x00000000, bhvShutter),
		OBJECT(MODEL_NONE, 6013, 7156, 5003, 0, 90, 0, 0x00000000, bhvShutter),
		OBJECT(MODEL_NONE, 2805, 7156, 2061, 0, 0, 0, 0x00000000, bhvShutter),
		OBJECT(MODEL_NONE, 2801, 1076, -433, 0, 0, 0, 0x00000000, bhvShutter),
		OBJECT(MODEL_NONE, -405, 1072, -5401, 0, 90, 0, 0x00000000, bhvShutter),
		OBJECT(MODEL_NONE, -9897, -5924, -6632, 0, 0, 0, 0x00000000, bhvShutter),
		OBJECT(MODEL_NONE, -9894, -5924, -11147, 0, 0, 0, 0x00000000, bhvShutter),
		OBJECT(MODEL_NONE, 7489, 7156, 5001, 0, 0, 0, 0x00000000, bhvCCTFlames),
		OBJECT(MODEL_CCT_GATE, -9903, -5124, -15900, 0, 0, 0, 0x00000000, bhvCCTGate),
		OBJECT(MODEL_NONE, 10010, 7156, 7503, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 10010, 7156, 5004, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 7529, 7156, 5003, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -10208, -5924, -4902, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -10319, -5924, -5929, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -10819, -5924, -12178, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -8956, -5924, -12157, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -9884, -5924, -9662, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_HEAVE_HO, 4589, 7156, 4853, 0, 0, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_HEAVE_HO, 3429, 7156, 4026, 0, 0, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_HEAVE_HO, 2826, 7156, 2798, 0, 0, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_HEAVE_HO, 2098, 1076, -3399, 0, 0, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_HEAVE_HO, 3151, 1076, -3897, 0, 0, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_HEAVE_HO, 2179, 1076, -5266, 0, 0, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_HEAVE_HO, 1820, 1076, -4833, 0, 0, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_HEAVE_HO, 1406, 1076, -4363, 0, 0, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_HEAVE_HO, 550, 1076, -5372, 0, 0, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_HEAVE_HO, -10529, -5124, -14467, 0, 0, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_HEAVE_HO, -10322, -5124, -15428, 0, 0, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_HEAVE_HO, -9519, -5124, -15512, 0, 0, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_HEAVE_HO, -9360, -5124, -14445, 0, 0, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_WOODEN_SIGNPOST, 9982, 7156, 9526, 0, 0, 0, (36 << 24) | (36 << 16), bhvMessagePanel),
		OBJECT(MODEL_CCT_PLATFORM_BIG, -1734, 775, -5504, 0, 0, 0, 0x00000000, bhvCCTPlatformBig),
		OBJECT(MODEL_CCT_PLATFORM_BIG, -3234, 629, -6504, 0, -90, 0, 0x00000000, bhvCCTPlatformBig),
		OBJECT(MODEL_CCT_PLATFORM_BIG, -3234, -5625, -5532, 0, 90, 0, (1 << 16), bhvCCTPlatformBig),
		OBJECT(MODEL_CCT_PLATFORM_BIG, -3234, -5456, -5523, 0, 90, 0, (2 << 16), bhvCCTPlatformBig),
		OBJECT(MODEL_CCT_PLATFORM, -11312, -5814, -12073, 0, -90, 0, 0x00000000, bhvCCTPlatform),
		OBJECT(MODEL_CCT_PLATFORM, -8495, -5814, -12073, 0, -90, 0, 0x00000000, bhvCCTPlatform),
		OBJECT(MODEL_CCT_PLATFORM, -9412, -5745, -13441, 0, 0, 0, 0x00000000, bhvCCTPlatform),
		OBJECT(MODEL_CCT_PLATFORM, -10407, -5745, -13441, 0, 0, 0, 0x00000000, bhvCCTPlatform),
		OBJECT(MODEL_CCT_PLATFORM, -11362, -5365, -15700, 0, 0, 0, 0x00000000, bhvCCTPlatform),
		OBJECT(MODEL_CCT_PLATFORM, -8445, -5365, -15700, 0, 0, 0, 0x00000000, bhvCCTPlatform),
		OBJECT(MODEL_CCT_PLATFORM_BIG, -4824, 760, -5504, 0, -180, 0, 0x00000000, bhvCCTPlatformBig),
		OBJECT(MODEL_NONE, -1734, 997, -5504, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -3234, 851, -6504, 0, -90, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -6046, -5831, -5400, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -3217, -2911, -5532, 0, 90, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, 188, 1840, -5387, 0, -90, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_STAR, 10354, 7307, 5008, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 7506, 7480, 5004, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 2821, 7927, 2449, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 2813, 1865, 1691, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -4813, 1379, -5504, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, -7427, -5690, -5401, 0, 0, 0, 0x00000000, bhvHiddenStar),
		OBJECT(MODEL_STAR, -9897, -5032, -7990, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, 10002, 7527, 10006, 0, 180, 0, (0xa << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_THWOMP, -9882, -5924, -7602, 0, 0, 0, (1 << 16), bhvThwomp2),
		OBJECT(MODEL_THWOMP, -10325, -5924, -7602, 0, 0, 0, (1 << 16), bhvThwomp2),
		OBJECT(MODEL_THWOMP, -9482, -5924, -7602, 0, 0, 0, (1 << 16), bhvThwomp2),
		OBJECT(MODEL_THWOMP, -9882, -5924, -8177, 0, 0, 0, 0x00000000, bhvThwomp2),
		OBJECT(MODEL_THWOMP, -10325, -5924, -8177, 0, 0, 0, 0x00000000, bhvThwomp2),
		OBJECT(MODEL_THWOMP, -9482, -5924, -8177, 0, 0, 0, 0x00000000, bhvThwomp2),
		OBJECT(MODEL_THWOMP, -9882, -5924, -10602, 0, 0, 0, (1 << 16), bhvThwomp2),
		OBJECT(MODEL_THWOMP, -10325, -5924, -10602, 0, 0, 0, (1 << 16), bhvThwomp2),
		OBJECT(MODEL_THWOMP, -9482, -5924, -10602, 0, 0, 0, (1 << 16), bhvThwomp2),
		OBJECT(MODEL_CCT_TIMESTOP, 10360, 7156, 5004, 0, 0, 0, 0x00000000, bhvCCTimestop),
		OBJECT(MODEL_CCT_TIMESTOP, 2801, 1076, -2784, 0, 0, 0, 0x00000000, bhvCCTimestop),
		OBJECT(MODEL_CCT_TIMESTOP, -7368, -5924, -5401, 0, 0, 0, 0x00000000, bhvCCTimestop),
		OBJECT(MODEL_CCT_TIMESTOP, -9880, -5026, -9900, 90, 0, 0, (100 << 24), bhvCCTimestop),
		OBJECT(MODEL_CCT_TIMESTOP, -9918, -5397, -13930, 90, 0, 0, (255 << 24), bhvCCTimestop),
		OBJECT(MODEL_CCT_TIMESTOP, 103, 1843, -5387, 90, 0, -90, (100 << 24), bhvCCTimestop),
		OBJECT(MODEL_CCT_TIMESTOP, -3234, -5456, -5523, 0, 90, 0, (100 << 24), bhvCCTimestop),
		TERRAIN(cct_area_1_collision),
		MACRO_OBJECTS(cct_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 1569, 1076, -4649),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};