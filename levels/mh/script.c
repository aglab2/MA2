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
#include "levels/mh/header.h"

/* Fast64 begin persistent block [scripts] */
extern const GeoLayout mh_area_visual[];
#define mh_area_1 mh_area_visual
#define mh_area_2 mh_area_visual
#define mh_area_3 mh_area_visual
#define mh_area_4 mh_area_visual
#define mh_area_5 mh_area_visual
#define mh_area_6 mh_area_visual
#define mh_area_7 mh_area_visual
#define mh_area_8 mh_area_visual
#define mh_area_9 mh_area_visual
#define mh_area_10 mh_area_visual
#include "levels/mh/area_1/collision.inc.c"
#include "levels/mh/area_2/collision.inc.c"
#include "levels/mh/area_3/collision.inc.c"
#include "levels/mh/area_4/collision.inc.c"
/* Fast64 end persistent block [scripts] */

const LevelScript level_mh_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _mh_segment_7SegmentRomStart, _mh_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_18), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, mh_area_1, 2000, 0, -900),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, -180, -19988, 1658, 8042),
		OBJECT(MODEL_CHECKPOINT, -8451, -1490, -12508, 0, 90, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_NONE, -20001, 63, 5640, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -20009, -1076, -3837, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -18503, -1378, -7748, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -15194, -2628, -12528, 0, -90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -6899, -1546, -12527, 0, -90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -18455, -1052, -8824, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -8754, -723, -12535, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_SNUFIT, 1602, -1905, -14994, 0, -180, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, 1602, -2092, -16278, 0, -180, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, 1602, -2269, -17640, 0, -180, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_NONE, -20018, -211, 3290, 0, -180, 0, 0x00000000, bhvSpringCtl),
		OBJECT(MODEL_STAR, -20001, 800, 4033, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -19021, -166, -6740, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -18481, -1161, -8832, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -7937, -892, -12543, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -3105, -1963, -12575, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 111, -1303, -13482, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 1648, -1888, -16292, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 234, -2, -24339, 0, -180, 0, 0x00000000, bhvStar),
		TERRAIN(mh_area_1_collision),
		MACRO_OBJECTS(mh_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, mh_area_2, 2000, 0, -4900),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_SPEEDER, 641, -1600, 3615, 0, 0, 0, 0x00000000, bhvSpeeder),
		OBJECT(MODEL_SPEEDER, 641, -1600, 763, 0, 0, 0, 0x00000000, bhvSpeeder),
		OBJECT(MODEL_SPEEDER, 639, -1600, -3652, 0, 0, 0, 0x00000000, bhvSpeeder),
		OBJECT(MODEL_SPEEDER, 672, -1598, -7927, 0, 0, 0, 0x00000000, bhvSpeeder),
		OBJECT(MODEL_SPEEDER, 2447, -1600, -2815, 0, 17, 0, 0x00000000, bhvSpeeder),
		OBJECT(MODEL_CHECKPOINT, 658, -1600, 4341, 0, -180, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_NONE, 1015, -2200, 14445, 0, -180, 0, 0x00000000, bhvSpringCtl),
		OBJECT(MODEL_STAR, 258, 605, 14798, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -1472, -710, 1362, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 2223, -1634, 2015, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 2133, -579, 3161, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 3516, -798, -8944, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -1408, -741, -6986, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -2925, -1373, -15054, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 647, -2436, -10859, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -886, -1541, -3158, 0, -180, 0, 0x00000000, bhvStar),
		TERRAIN(mh_area_2_collision),
		MACRO_OBJECTS(mh_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(3, mh_area_3, 2000, 0, -8900),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CHECKPOINT, 15669, 1530, 16162, 0, 0, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_NONE, 4260, -200, 18547, 0, -180, 0, 0x00000000, bhvSpringCtl),
		OBJECT(MODEL_STAR, 3941, -387, 18595, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 6822, -1051, 17797, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 12894, -178, 18056, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 13311, 1372, 18001, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 16427, 788, 8905, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 17219, -526, 3766, 0, -180, 0, 0x00000000, bhvStar),
		TERRAIN(mh_area_3_collision),
		MACRO_OBJECTS(mh_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(4, mh_area_4, 6000, 916, -8900),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_MH, 4, 12, WARP_NO_CHECKPOINT),
		WARP_NODE(12, LEVEL_MH, 4, 11, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CHECKPOINT, -12919, -11848, -3390, 0, 90, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_GOAL, 27994, -10283, -13695, 0, -180, 0, (1 << 16), bhvGoal),
		OBJECT(MODEL_THI_WARP_PIPE, -10864, -9467, -14691, 0, -180, 0, (11 << 16), bhvWarpPipe),
		OBJECT(MODEL_NONE, -6970, 14111, -13120, 0, -180, 0, (12 << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, -16505, -11895, -4911, 0, -180, 0, 0x00000000, bhvSpringCtl),
		OBJECT(MODEL_STAR, -18388, -9733, -4865, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -9917, -11333, -13900, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -10811, -9670, -14713, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -9343, -6767, -13144, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -9319, -9155, -11588, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -12744, -6469, -11352, 0, -180, 0, 0x00000000, bhvStar),
		TERRAIN(mh_area_4_collision),
		MACRO_OBJECTS(mh_area_4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, -19988, 1658, 8042),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};