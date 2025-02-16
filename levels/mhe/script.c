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
#include "levels/mhe/header.h"

/* Fast64 begin persistent block [scripts] */
#include "levels/mhe/area_1/collision.inc.c"
/* Fast64 end persistent block [scripts] */

const LevelScript level_mhe_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _mhe_segment_7SegmentRomStart, _mhe_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	LOAD_MODEL_FROM_GEO(MODEL_MHE_FIREBALL, mhe_fireball_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MHE_FIREBALL_BREAK, mhe_fireball_break_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MHE_TANK, mhe_tank_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MHE_TANK_BREAK, mhe_tank_break_geo), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, mhe_area_1, 0, 0, 0),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, 39, -12500, 11136),
		OBJECT(MODEL_CHECKPOINT, -5, -12000, -9838, 0, 0, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHECKPOINT, 49, 3250, 3914, 0, 0, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHECKPOINT, -23, -5300, 1408, 0, 0, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_NONE, 1938, -11400, -590, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, 1924, -11400, 608, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -5, -11400, 1903, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -1944, -11400, 583, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -1905, -11400, -613, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_MHE_FIREBALL, -2822, 3520, 366, 0, 0, 0, (MODEL_MHE_FIREBALL_BREAK << 16), bhvBreakable),
		OBJECT(MODEL_ROCKET_SPAWNER, -62, -15053, 82, 0, 0, 0, 0x00000000, bhvRocketSpawner),
		OBJECT(MODEL_ROCKET_SPAWNER, 14, 3250, -4203, 0, 0, 0, 0x00000000, bhvRocketSpawner),
		OBJECT(MODEL_ROCKET_SPAWNER, 337, -8221, -444, 0, 0, 0, 0x00000000, bhvRocketSpawner),
		OBJECT(MODEL_ROCKET_SPAWNER, -1803, -10400, 8, 0, 0, 0, 0x00000000, bhvRocketSpawner),
		OBJECT(MODEL_ROCKET_SPAWNER, 9, -1750, 3202, 0, 0, 0, 0x00000000, bhvRocketSpawner),
		OBJECT(MODEL_ROCKET_SPAWNER, 4284, 12342, -185, 0, 0, 0, 0x00000000, bhvRocketSpawner),
		OBJECT(MODEL_ROCKET_SPAWNER, 2045, 7924, -4463, 0, 0, 0, 0x00000000, bhvRocketSpawner),
		OBJECT(MODEL_STAR, 749, -11821, 10906, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 1417, -12756, 4993, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -11334, -12207, 1284, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -10796, -10621, -3526, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -4353, -12284, -9650, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -3378, -10724, -7199, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 3674, -12754, -10091, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 9780, -12796, -3243, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 10744, -11827, 2856, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 5041, -12536, -798, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 5150, -11246, -853, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, 3958, -11075, -853, 0, 0, 0, 0x00000000, bhvHiddenStar),
		OBJECT(MODEL_STAR, -85, -14636, -415, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 31, 3555, 4901, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -1213, 3377, -3816, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -3028, -2866, 2447, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -1427, -8590, 870, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 1289, -6032, -1674, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 3362, 18261, -3461, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -2992, -2721, 3152, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -2822, 3520, 366, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -57, -3965, -3195, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 30, -5122, -1934, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 1898, 8243, -4407, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 4313, 12748, -243, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 1173, 753, 33, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 1149, 2503, -3295, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 1105, -10986, 611, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_MHE_TANK, 507, 3250, 5011, 0, 0, 0, (MODEL_MHE_TANK_BREAK << 16), bhvBreakable),
		OBJECT(MODEL_MHE_TANK, 19, 3250, 5011, 0, 0, 0, (MODEL_MHE_TANK_BREAK << 16), bhvBreakable),
		OBJECT(MODEL_MHE_TANK, -560, 3250, 5011, 0, 0, 0, (MODEL_MHE_TANK_BREAK << 16), bhvBreakable),
		TERRAIN(mhe_area_1_collision),
		MACRO_OBJECTS(mhe_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 39, -12500, 11136),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};