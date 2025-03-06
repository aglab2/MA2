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
#include "levels/ig/header.h"

/* Fast64 begin persistent block [scripts] */
#include "levels/ig/area_1/collision.inc.c"
#include "levels/ig/area_2/collision.inc.c"
extern const GeoLayout ig_area_1[];
#define ig_area_2 ig_area_1
/* Fast64 end persistent block [scripts] */

const LevelScript level_ig_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _ig_segment_7SegmentRomStart, _ig_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_IG_BOMB, ig_bombe_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_IG_BOMB_BREAK, ig_bomb_break_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_IG_LIFT, ig_lift_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_IG_SHELF, ig_shelt_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_IG_SIREN, ig_siren_geo), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ig_area_1, 2000, -674, -900),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, -19979, 4827, 9006),
		OBJECT(MODEL_BLACK_BOBOMB, -14014, 4045, 3014, 0, 90, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -13420, 4045, 2369, 0, 90, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -12556, 4045, 2599, 0, 90, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -12129, 4045, 3426, 0, 90, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -9168, 4045, 2532, 0, 90, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -8574, 4045, 2724, 0, 90, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -7710, 4045, 2117, 0, 90, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -7283, 4045, 2944, 0, 90, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_IG_BOMB, -11872, 4045, 3401, 0, 90, 0, (MODEL_IG_BOMB_BREAK << 16), bhvBreakable),
		OBJECT(MODEL_IG_BOMB, -12063, 4045, 3543, 0, 10, 0, (MODEL_IG_BOMB_BREAK << 16), bhvBreakable),
		OBJECT(MODEL_IG_BOMB, -13753, 4045, 2231, 0, 10, 0, (MODEL_IG_BOMB_BREAK << 16), bhvBreakable),
		OBJECT(MODEL_IG_BOMB, -13836, 4045, 2426, 0, 10, 0, (MODEL_IG_BOMB_BREAK << 16), bhvBreakable),
		OBJECT(MODEL_IG_BOMB, -14006, 4045, 2598, 0, 10, 0, (MODEL_IG_BOMB_BREAK << 16), bhvBreakable),
		OBJECT(MODEL_IG_BOMB, -13774, 4045, 2701, 0, 10, 0, (MODEL_IG_BOMB_BREAK << 16), bhvBreakable),
		OBJECT(MODEL_IG_BOMB, -8359, 4045, 1744, 0, 10, 0, (MODEL_IG_BOMB_BREAK << 16), bhvBreakable),
		OBJECT(MODEL_IG_BOMB, -8735, 4045, 1748, 0, 10, 0, (MODEL_IG_BOMB_BREAK << 16), bhvBreakable),
		OBJECT(MODEL_IG_BOMB, -8801, 4045, 1927, 0, 10, 0, (MODEL_IG_BOMB_BREAK << 16), bhvBreakable),
		OBJECT(MODEL_BOOSTER, -18808, 4045, 8998, 0, -90, 0, 0x00000000, bhvBooster),
		OBJECT(MODEL_BOOSTER, -13905, 4045, 5474, 0, 0, 0, 0x00000000, bhvBooster),
		OBJECT(MODEL_BOOSTER, -7345, 4045, 977, 0, 0, 0, 0x00000000, bhvBooster),
		OBJECT(MODEL_BOOSTER, 357, 115, -1267, 0, -90, 0, 0x00000000, bhvBooster),
		OBJECT(MODEL_CHUCKYA, -14814, 4045, 9006, 0, 90, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, -7292, 4045, 1965, 0, 90, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_NONE, -18071, 4045, 9004, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -15962, 4045, 9004, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -13902, 4045, 7131, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -13896, 4045, 5011, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -10832, 4745, 2608, 0, -90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -7352, 4045, 234, 0, -90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -6331, 4065, -1275, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 976, 207, -1272, 0, -90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -19649, 4045, 8990, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -7697, 4045, 2351, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -5066, 4045, -1283, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 3895, 115, -1266, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -11939, 4503, 2528, 0, -180, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -4493, 4134, -573, 0, -180, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -4493, 4134, -1978, 0, -180, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 3845, 115, -1273, 0, -180, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -19979, 4827, 9006, 0, 0, 0, (0xa << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_IG_SHELF, -13906, 4045, 5850, 0, -180, 0, 0x00000000, bhvIgShelf),
		OBJECT(MODEL_IG_SHELF, -9543, 4745, 2619, 0, -90, 0, 0x00000000, bhvIgShelf),
		OBJECT(MODEL_IG_SHELF, -7353, 4045, 1512, 0, -180, 0, 0x00000000, bhvIgShelf),
		OBJECT(MODEL_IG_SHELF, 3903, 115, -279, 0, -180, 0, 0x00000000, bhvIgShelf),
		OBJECT(MODEL_SNUFIT, -16833, 4291, 8704, 0, 90, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, -16833, 4291, 9306, 0, 90, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, -9062, 4324, 1968, 0, 90, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, -8017, 4258, 2014, 0, 90, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, -7168, 4313, -87, 0, 90, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, -7524, 4313, -85, 0, 90, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_STAR, -14112, 4315, 2305, 0, 10, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -20009, 5045, 8994, 0, 10, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -12712, 4627, 3508, 0, 10, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -8520, 4863, 2677, 0, 10, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -5254, 4681, -510, 0, 10, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -808, 846, -1282, 0, 10, 0, 0x00000000, bhvStar),
		TERRAIN(ig_area_1_collision),
		MACRO_OBJECTS(ig_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, ig_area_2, 6000, -1287, -900),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		TERRAIN(ig_area_2_collision),
		MACRO_OBJECTS(ig_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -19979, 4827, 9006),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};