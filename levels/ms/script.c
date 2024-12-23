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
#include "levels/ms/header.h"

/* Fast64 begin persistent block [scripts] */
extern const GeoLayout ms_area_visual[];
#define ms_area_1 ms_area_visual
#define ms_area_2 ms_area_visual
#define ms_area_3 ms_area_visual
#define ms_area_4 ms_area_visual
#define ms_area_5 ms_area_visual
#define ms_area_6 ms_area_visual
#define ms_area_7 ms_area_visual
#define ms_area_8 ms_area_visual
#define ms_area_9 ms_area_visual
#define ms_area_10 ms_area_visual
/* Fast64 end persistent block [scripts] */

const LevelScript level_ms_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _ms_segment_7SegmentRomStart, _ms_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_MS_HAMMER, ms_hammer_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MS_BUFFER, ms_buffer_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MS_BUFFER_BREAK, ms_buffer_break_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MS_BREAK, ms_slane_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MS_SLANE_BREAK, ms_slane_break_geo), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ms_area_1, 1000, 0, -1800),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, -10010, -75, 17961),
		OBJECT(MODEL_BREAKABLE_BOX, 23204, 6700, -23125, 0, 0, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, 23404, 6700, -23125, 0, 0, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, 23604, 6700, -23125, 0, 0, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, 23804, 6700, -23125, 0, 0, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_NONE, 18629, 2000, -15926, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 2221, 2000, -15923, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -10800, 2000, -15917, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -22479, -1650, 134, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -21996, 803, -11152, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -18098, 3925, -11889, 0, 90, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_WHOMP, -16504, 3055, -11860, 0, 90, 0, 0x00000000, bhvSmallWhomp),
		OBJECT(MODEL_NONE, -14817, -75, -1511, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -10022, -74, 11027, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -22517, 350, -9805, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -21452, 3503, -11860, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -15601, 2830, -11841, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 4796, 2000, -15906, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_MS_HAMMER, -21918, 1158, -10675, 0, 0, 0, 0x00000000, bhvHammerUpDown),
		OBJECT(MODEL_MS_HAMMER, -22318, 1158, -10675, 0, 0, 0, 0x00000000, bhvHammerUpDown),
		OBJECT(MODEL_MS_HAMMER, -23016, 2033, -10941, 0, 0, 0, (80 << 16), bhvHammerUpDown),
		OBJECT(MODEL_MS_HAMMER, -23016, 2033, -11341, 0, 0, 0, (160 << 16), bhvHammerUpDown),
		OBJECT(MODEL_MS_HAMMER, -23016, 2280, -12012, 0, 0, 0, 0x00000000, bhvHammerUpDown),
		OBJECT(MODEL_HEAVE_HO, -7727, -75, 7068, 0, 0, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_HEAVE_HO, -18709, -1650, -1502, 0, 0, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_HEAVE_HO, -22184, 350, -10808, 0, 0, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_HEAVE_HO, -5448, 2000, -16327, 0, 0, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_HEAVE_HO, -8108, -75, 1285, 0, 0, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_RED_COIN, -2548, 2152, -16181, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -1134, 2152, -15665, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 136, 2152, -16181, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 1438, 2152, -15916, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 2825, 2152, -16207, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 4960, 2152, -16205, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3956, 2152, -16080, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 6345, 2152, -15582, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_MS_BREAK, -18350, -75, -1505, 0, 90, 0, 0x00000000, bhvMsBreak),
		OBJECT(MODEL_MS_BREAK, 8637, 2000, -15919, 0, 90, 0, (3 << 16), bhvMsBreak),
		OBJECT(MODEL_MS_BREAK, 9557, 2000, -15919, 0, 90, 0, 0x00000000, bhvMsBreak),
		OBJECT(MODEL_STAR, -10007, 1221, 12511, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -7497, 247, 9167, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -7373, 283, 5534, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -15072, 615, -1525, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -17127, -1527, -1144, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -22504, -1384, 687, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -22499, -377, -4394, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -21949, 350, -10841, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -17645, 4600, -12405, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -10803, 2280, -15920, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -4027, 944, -15923, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 11958, 922, -15916, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 23509, 6577, -23773, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, 10651, 2658, -15935, 0, 0, 0, 0x00000000, bhvHiddenRedCoinStar),
		OBJECT(MODEL_STAR, 7522, 3366, -16151, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_THWOMP, 11896, 2000, -15907, 0, 0, 0, 0x00000000, bhvThwomp2),
		OBJECT(MODEL_WHOMP, -10007, -75, 12511, 0, 0, 0, 0x00000000, bhvSmallWhomp),
		OBJECT(MODEL_WHOMP, -16633, -75, -1505, 0, 90, 0, 0x00000000, bhvSmallWhomp),
		OBJECT(MODEL_WHOMP, -22980, 350, -11023, 0, 0, 0, 0x00000000, bhvSmallWhomp),
		OBJECT(MODEL_WHOMP, -1308, 2000, -15926, 0, 0, 0, 0x00000000, bhvSmallWhomp),
		OBJECT(MODEL_WHOMP, 6376, 2000, -15909, 0, 0, 0, 0x00000000, bhvSmallWhomp),
		TERRAIN(ms_area_1_collision),
		MACRO_OBJECTS(ms_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, ms_area_2, 5000, 0, -1800),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -13320, 2083, -15832, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -16474, 3500, -18430, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_BREAKABLE_BOX, -16386, 3500, -16203, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -16386, 3500, -16403, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -16586, 3500, -16203, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -16586, 3500, -16403, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_STAR, -14841, 3500, -16061, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_PURPLE_SWITCH, -14832, 2000, -15992, 0, 0, 0, 0x00000000, bhvFloorSwitchHiddenObjects),
		OBJECT(MODEL_THWOMP, -16552, 3500, -14990, 0, 0, 0, 0x00000000, bhvThwomp2),
		TERRAIN(ms_area_2_collision),
		MACRO_OBJECTS(ms_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(3, ms_area_3, 5000, 0, -5800),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_MS_BUFFER, 14092, 5985, -4141, 0, 0, 0, (MODEL_MS_BUFFER_BREAK << 16), bhvBreakable),
		OBJECT(MODEL_MS_BUFFER, 14695, 5985, -4553, 0, 0, 0, (MODEL_MS_BUFFER_BREAK << 16), bhvBreakable),
		OBJECT(MODEL_NONE, -16481, 6980, 16354, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -5305, 4485, 17339, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -308, 5985, 3015, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 14287, 5985, -4663, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 14430, 5985, -10966, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -13484, 6139, 17347, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_GOAL, 21437, 6767, -11080, 0, 0, 0, 0x00000000, bhvGoal),
		OBJECT(MODEL_MS_HAMMER, -17502, 4413, 18469, 0, 0, 0, (120 << 16), bhvHammerUpDown),
		OBJECT(MODEL_MS_HAMMER, -17502, 5144, 18069, 0, 0, 0, (0 << 16), bhvHammerUpDown),
		OBJECT(MODEL_HEAVE_HO, -16790, 6500, 17316, 0, 0, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_HEAVE_HO, -305, 5985, 161, 0, 0, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_HEAVE_HO, 3079, 5985, -4441, 0, 0, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_MS_BREAK, -8847, 5005, 17341, 0, 0, 0, (2 << 16), bhvMsBreak),
		OBJECT(MODEL_MS_BREAK, -5305, 4985, 14733, 0, 0, 0, (2 << 16), bhvMsBreak),
		OBJECT(MODEL_MS_BREAK, -305, 5985, 5637, 0, 0, 0, (1 << 16), bhvMsBreak),
		OBJECT(MODEL_MS_BREAK, -305, 5985, 4352, 0, 0, 0, (1 << 16), bhvMsBreak),
		OBJECT(MODEL_STAR, -16517, 3816, 18333, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -4892, 5237, 15930, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -357, 6585, 4909, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 21382, 6800, -10163, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 14094, 6146, -4141, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_THWOMP, -5238, 5014, 12413, 0, 0, 0, 0x00000000, bhvThwomp2),
		OBJECT(MODEL_WHOMP, -5278, 4485, 16038, 0, 0, 0, 0x00000000, bhvSmallWhomp),
		OBJECT(MODEL_WHOMP, 14458, 5985, -10201, 0, 0, 0, 0x00000000, bhvSmallWhomp),
		OBJECT(MODEL_WHOMP, 14465, 5986, -6791, 0, 0, 0, 0x00000000, bhvSmallWhomp),
		TERRAIN(ms_area_3_collision),
		MACRO_OBJECTS(ms_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -10010, -75, 17961),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};