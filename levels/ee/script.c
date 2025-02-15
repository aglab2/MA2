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
#include "levels/ee/header.h"

/* Fast64 begin persistent block [scripts] */
extern const GeoLayout ee_area_visual[];
#define ee_area_1 ee_area_visual
#define ee_area_2 ee_area_visual
#define ee_area_3 ee_area_visual
#define ee_area_4 ee_area_visual
#define ee_area_5 ee_area_visual
#define ee_area_6 ee_area_visual
#define ee_area_7 ee_area_visual
#define ee_area_8 ee_area_visual
#define ee_area_9 ee_area_visual
#define ee_area_10 ee_area_visual
#include "levels/ee/area_1/collision.inc.c"
#include "levels/ee/area_2/collision.inc.c"
#include "levels/ee/area_3/collision.inc.c"
#include "levels/ee/area_4/collision.inc.c"
#include "levels/ee/area_5/collision.inc.c"
/* Fast64 end persistent block [scripts] */

const LevelScript level_ee_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _ee_segment_7SegmentRomStart, _ee_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ee_area_1, 1000, 632, -2000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, -10000, -6316, 20000),
		OBJECT(MODEL_CHECKPOINT, -16515, -536, -6200, 0, 0, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_STAR, -10006, -5887, 20818, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -7512, -1120, 9856, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -7526, 333, 4829, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -11147, -199, -967, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -19079, -216, -2002, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -15722, -8, -6221, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -16551, 1865, -9204, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -16528, -4123, -18238, 0, 0, 0, 0x00000000, bhvStar),
		TERRAIN(ee_area_1_collision),
		MACRO_OBJECTS(ee_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, ee_area_2, 1000, 632, -6000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_STAR, -16578, 1895, 15773, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -17329, 1774, 13005, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -15989, 1979, 7454, 0, 0, 0, 0x00000000, bhvStar),
		TERRAIN(ee_area_2_collision),
		MACRO_OBJECTS(ee_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(3, ee_area_3, -3000, 632, -6000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CHECKPOINT, 5467, 2044, 3268, 0, 0, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHECKPOINT, 9457, 4044, -14272, 0, 0, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_RED_COIN, 8461, -1695, -15681, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 8860, -2097, -17482, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 9694, -1420, -16089, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 10343, -1240, -17456, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 8860, -2386, -16761, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 10158, -2067, -16108, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 10523, -2069, -15131, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 8115, -2522, -17493, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_STAR, 9426, -2304, -16497, 0, 0, 0, 0x00000000, bhvHiddenRedCoinStar),
		OBJECT(MODEL_STAR, 9444, 1298, -10295, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 12362, 2702, 8545, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 3080, 2392, 7380, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 8412, 2289, 2237, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 9456, 4127, 994, 0, 0, 0, 0x00000000, bhvStar),
		TERRAIN(ee_area_3_collision),
		MACRO_OBJECTS(ee_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(4, ee_area_4, -3000, 632, -10000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CHECKPOINT, 13161, 3124, 8478, 0, 0, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_STAR, 9444, 3568, 19145, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 9464, -2617, 12062, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 8752, 3777, 7783, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 19004, 3679, 7361, 0, 0, 0, 0x00000000, bhvStar),
		TERRAIN(ee_area_4_collision),
		MACRO_OBJECTS(ee_area_4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(5, ee_area_5, 1000, -230, -10000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_GOAL, -7693, -18428, 8277, 0, 0, 0, 0x00000000, bhvGoal),
		OBJECT(MODEL_STAR, -8876, 10187, 8407, 0, 0, 0, 0x00000000, bhvStar),
		TERRAIN(ee_area_5_collision),
		MACRO_OBJECTS(ee_area_5_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -10000, -6316, 20000),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};