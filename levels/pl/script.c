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
#include "levels/pl/header.h"

/* Fast64 begin persistent block [scripts] */
extern const BehaviorScript bhvPLRoll[];
/* Fast64 end persistent block [scripts] */

const LevelScript level_pl_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x7, _pl_segment_7SegmentRomStart, _pl_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_PL_ELV, pl_elv_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PL_ROLL, pl_roll_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PL_CAGE, pl_cage_geo), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, pl_area_1, -2000, 0, 0),
		MARIO_POS(0x01, 0, 374, 2370, -6176),
		OBJECT(MODEL_BLACK_BOBOMB, 8148, 2370, 591, 0, 90, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_CHECKPOINT, 17101, -30, 41, 0, -90, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHECKPOINT, 7789, 2370, 389, 0, 90, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHECKPOINT, 297, 2370, -6155, 0, 0, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHECKPOINT, -11470, 6300, -1250, 0, 0, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHECKPOINT, -19155, 8700, -2404, 0, 0, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_PL_ELV, -1737, 2370, -6156, 0, 0, 0, 0x00000000, bhvPLElv),
		OBJECT(MODEL_PL_ROLL, -2129, 2117, -7039, 0, 0, 0, 0x00000000, bhvPLRoll),
		OBJECT(MODEL_PL_ROLL, -2129, 2117, -5275, 0, 0, 0, 0x00000000, bhvPLRoll),
		OBJECT(MODEL_PL_CAGE, 20085, -30, 25, 0, 90, 0, 0x00000000, bhvPLCage),
		OBJECT(MODEL_PL_CAGE, 7467, 2370, 395, 0, 90, 0, (1 << 16), bhvPLCage),
		OBJECT(MODEL_PL_CAGE, 4318, 3070, -1873, 0, 0, 0, (2 << 16), bhvPLCage),
		OBJECT(MODEL_PL_CAGE, 3047, 2370, -6151, 0, 0, 0, (3 << 16), bhvPLCage),
		OBJECT(MODEL_PL_CAGE, -5387, 6300, -6156, 0, 90, 0, (4 << 16), bhvPLCage),
		OBJECT(MODEL_PL_CAGE, -7061, 6300, -5645, 0, 157, 0, (5 << 16), bhvPLCage),
		OBJECT(MODEL_PL_CAGE, -7053, 6300, -3671, 0, 3, 0, (6 << 16), bhvPLCage),
		OBJECT(MODEL_PL_CAGE, -8737, 6300, -2753, 0, 90, 0, (7 << 16), bhvPLCage),
		OBJECT(MODEL_PL_CAGE, -19274, 8700, -2405, 0, 0, 0, (8 << 16), bhvPLCage),
		OBJECT(MODEL_PL_CAGE, -24433, 9400, -4686, 0, 0, 0, (9 << 16), bhvPLCage),
		OBJECT(MODEL_PL_CAGE, -24440, 9400, -9745, 0, 0, 0, (10 << 16), bhvPLCage),
		OBJECT(MODEL_PL_CAGE, 21059, -30, -1051, 0, 0, 0, (11 << 16), bhvPLCage),
		OBJECT(MODEL_GOAL, -24442, 9611, -10890, 0, 0, 0, 0x00000000, bhvGoal),
		OBJECT(MODEL_GOOMBA, 20490, -30, 494, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 20347, -30, -311, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 21091, -30, -700, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 21091, -30, 2156, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_NONE, 21119, 176, 40, 0, 0, 0, (0xa << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_MR_I, 8094, 2419, 390, 0, 90, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_RED_COIN, -13029, 8084, 1599, 0, 90, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -12972, 8084, 3669, 0, 90, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -13664, 8084, 3704, 0, 90, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -16561, 9184, 2086, 0, 90, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -18362, 9184, 2091, 0, 90, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -18941, 9284, 2099, 0, 90, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -18961, 9284, -316, 0, 90, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -18332, 9184, -306, 0, 90, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, -18351, 9462, -1512, 0, 90, 0, 0x00000000, bhvHiddenRedCoinStar),
		OBJECT(MODEL_SCUTTLEBUG, 5023, 2370, -1294, 0, 0, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, 4156, 2370, -859, 0, 0, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_CHUCKYA, 3770, 2770, -4977, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, 4656, 2370, -4361, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, 3686, 2370, -6041, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_SCUTTLEBUG, 4247, 2370, 87, 0, 0, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_SNUFIT, 3458, 2665, -5502, 0, 0, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, 3741, 2634, -6402, 0, 0, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, 4617, 2557, -5718, 0, 0, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_STAR, 21048, 230, -2073, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 15317, 816, -31, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 12618, 1267, 4065, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 12618, 1814, 4065, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 8401, 2607, 4993, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 7585, 2337, -450, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 4754, 3317, 673, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 3421, 2468, -4464, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -432, 3118, -6136, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -11573, 8133, -1187, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -13024, 8200, 1155, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -18362, 9263, -301, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -23388, 9846, -4466, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -27982, 9616, -11604, 0, 0, 0, 0x00000000, bhvStar),
		TERRAIN(pl_area_1_collision),
		MACRO_OBJECTS(pl_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 374, 2370, -6176),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};