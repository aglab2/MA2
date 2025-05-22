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
#include "levels/fc/header.h"

/* Fast64 begin persistent block [scripts] */
#include "levels/fc/area_1/collision.inc.c"
#include "levels/fc/area_2/collision.inc.c"
#include "levels/fc/area_3/collision.inc.c"
#include "levels/fc/area_4/collision.inc.c"
#include "levels/fc/area_5/collision.inc.c"
#include "levels/fc/area_6/collision.inc.c"
#include "levels/fc/area_7/collision.inc.c"
#include "levels/fc/area_8/collision.inc.c"
#include "levels/fc/area_9/collision.inc.c"
#define fc_area_2 fc_area_1
#define fc_area_3 fc_area_1
#define fc_area_4 fc_area_1
#define fc_area_5 fc_area_1
#define fc_area_6 fc_area_1
#define fc_area_7 fc_area_1
#define fc_area_8 fc_area_1
#define fc_area_9 fc_area_1
#define SEQ_LEVEL_GRASS 0x42
extern Gfx fc_skybox_fc_space_mesh[];
extern const IWDHeader* iw_descs_fc[];
extern const RailDesc* rail_descs_fc[];
extern const SpringDesc* spring_descs_fc[];
static struct LevelConfig cfg = {
	.skybox = fc_skybox_fc_space_mesh,
	.viewRangeMult = 3.5f,
	.iwds = iw_descs_fc,
	.railDesc = rail_descs_fc,
	.springDescs = spring_descs_fc,
};
/* Fast64 end persistent block [scripts] */

const LevelScript level_fc_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _fc_segment_7SegmentRomStart, _fc_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	/* Fast64 begin persistent block [level commands] */
	LVL_CONFIG(&cfg),
	/* Fast64 end persistent block [level commands] */

	AREA(1, fc_area_1, 0, -1645, 2000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 170, 1429, 17235, -19938),
		OBJECT(MODEL_STAR, 1508, -79730, 79207, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 10677, -10742, -8264, 0, 174, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, 1429, 17641, -19938, 0, 174, 0, (0xa << 16), bhvInstantActiveWarp),
		TERRAIN(fc_area_1_collision),
		MACRO_OBJECTS(fc_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, fc_area_2, 4000, -3949, 2000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BOOSTER, -4049, -5759, 15666, 0, 0, 0, 0x00000000, bhvBooster),
		OBJECT(MODEL_CHECKPOINT, -8066, -8259, 12064, 0, 0, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHECKPOINT, -1000, -2759, 33953, 0, 90, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHECKPOINT, 3646, 3241, 41089, 0, 0, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHUCKYA, -8047, -8259, 7819, 0, 90, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_NONE, -10831, -1209, 2662, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -8073, -959, 2756, 0, 90, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -8064, -1344, 4600, 0, 90, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -8064, -4585, 6306, 0, 90, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -8060, -8259, 10322, 0, 90, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -8115, -6759, 14795, 0, 90, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -5977, -6259, 15754, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -3028, -6259, 14822, 0, -90, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -4076, -5759, 26816, 0, -90, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -4034, -4259, 31788, 0, -90, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -4120, -5759, 17662, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -8104, -8259, 12761, 0, 0, 0, 0x00000000, bhvFCGrav),
		OBJECT(MODEL_STAR, -8042, -7693, 7824, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -8102, -7146, 13638, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -2978, -5901, 13491, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -4093, -4975, 17065, 0, 0, 0, 0x00000000, bhvStar),
		TERRAIN(fc_area_2_collision),
		MACRO_OBJECTS(fc_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(3, fc_area_3, 4000, -3949, 6000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 847, -1339, -3626, 0, 0, -37, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 2102, -72, -2351, 0, 0, -71, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -4060, -6044, -18494, 90, 0, 0, (1 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, 610, -1756, -5931, 90, 0, 0, (1 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, 1717, -254, -4024, 90, 0, 0, (1 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, -4077, -5524, -10451, 0, 0, 0, 0x00000000, bhvFCGrav),
		OBJECT(MODEL_NONE, -4055, -3900, -6052, 0, 0, 0, 0x00000000, bhvFCGrav),
		OBJECT(MODEL_NONE, 3654, -135, -2303, 0, 0, 0, (1 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, 1717, -3024, 6880, 90, 0, 0, (1 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, 2866, -3024, 10406, 90, 0, 0, (1 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, 3662, -11966, 12857, 90, 0, 0, (1 << 16), bhvFCGrav),
		OBJECT(MODEL_RED_COIN, 887, -1514, -5281, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 377, -2019, -3685, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 1563, 122, -3483, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 1438, -659, -1394, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3532, -36, -2680, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3935, 1352, -2084, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3886, 2510, -2597, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -190, -2304, -5806, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_STAR, -4065, -6677, -16208, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -4065, -6041, -15382, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -4459, -4091, -5673, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 621, -1767, -6103, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, 3636, 3598, -1194, 0, 0, 0, 0x00000000, bhvHiddenRedCoinStar),
		TERRAIN(fc_area_3_collision),
		MACRO_OBJECTS(fc_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(4, fc_area_4, 4000, -3949, 10000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 3812, -14669, 4856, 0, 0, 0, (1 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, 2392, -12383, 7620, 0, 0, 0, (2 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, 235, -9444, 9006, 0, 0, 0, (3 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, -638, -4107, 11443, 0, 0, 0, (3 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, -3699, -285, 13321, 0, 0, 0, (1 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, -2235, -766, 17838, 0, 0, 0, (1 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, -1440, 1011, 20620, 0, 0, 0, (1 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, -3684, 3087, 20649, 0, 0, 0, (1 << 16), bhvFCGrav),
		TERRAIN(fc_area_4_collision),
		MACRO_OBJECTS(fc_area_4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(5, fc_area_5, 4000, -4424, 14000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		TERRAIN(fc_area_5_collision),
		MACRO_OBJECTS(fc_area_5_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(6, fc_area_6, 4000, -6536, 18000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -4617, -3207, -4808, 0, 0, 0, (1 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, -6458, -3207, -4808, 0, 0, 0, (1 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, -4617, -3207, -8808, 0, 0, 0, (1 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, -6458, -3207, -8808, 0, 0, 0, (1 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, -4617, -3207, -6808, 0, 0, 0, (1 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, -6458, -3207, -6808, 0, 0, 0, (1 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, -14377, 3747, -88, 80, 0, 0, (3 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, -16378, 4220, -85, 100, 0, 0, (3 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, -18454, 2176, -101, 85, 0, 0, (3 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, -15306, 964, -64, 104, 0, 0, (3 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, -17515, -566, -68, 76, 0, 0, (3 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, -18873, -3677, -68, 76, 0, 0, (3 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, -14203, -3400, -106, 88, 0, 0, (3 << 16), bhvFCGrav),
		TERRAIN(fc_area_6_collision),
		MACRO_OBJECTS(fc_area_6_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(7, fc_area_7, 0, -7796, 18000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 1493, -7242, -8243, 90, 0, 0, (1 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, 1494, -8364, -7652, 90, 0, 180, (1 << 16), bhvFCGrav),
		TERRAIN(fc_area_7_collision),
		MACRO_OBJECTS(fc_area_7_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(8, fc_area_8, 0, -9526, 14000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 2649, -1946, -1078, 90, 0, 90, (1 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, 4146, -3244, 740, 90, 0, 90, (2 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, 1144, -690, -2753, 90, 0, 90, 0x00000000, bhvFCGrav),
		TERRAIN(fc_area_8_collision),
		MACRO_OBJECTS(fc_area_8_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(9, fc_area_9, 0, -9526, 10000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 1354, -4587, -2261, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 1461, 5408, 7311, 90, 0, 1, (2 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, -207, 6817, 4502, 90, 0, 1, (2 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, 3253, 6817, 4502, 90, 0, 1, (2 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, 1516, 3582, 1566, 90, 0, 1, (2 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, 1516, 8319, 1566, 90, 0, 1, (2 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, 1516, -673, -786, 0, 0, 0, (1 << 16), bhvFCGrav),
		OBJECT(MODEL_NONE, 1516, -4113, -785, 0, 0, 0, (1 << 16), bhvFCGrav),
		OBJECT(MODEL_GOAL, 1377, -4187, -3073, 0, 0, 0, 0x00000000, bhvGoal),
		TERRAIN(fc_area_9_collision),
		MACRO_OBJECTS(fc_area_9_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 170, 1429, 17235, -19938),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};