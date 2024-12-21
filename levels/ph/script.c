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
#include "levels/ph/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ph_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _ph_segment_7SegmentRomStart, _ph_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ph_area_1, 0, 0, 0),
		MARIO_POS(0x01, 0, 4656, -13643, -12571),
		OBJECT(MODEL_CHECKPOINT, 135, -6533, -17266, 0, 0, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHECKPOINT, -39, -1926, -635, 0, 0, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHECKPOINT, 7160, -13000, -7293, 0, -46, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHECKPOINT, 7839, -10000, -5910, 0, -51, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_ROCKET_SPAWNER, -1738, -13613, -3490, 0, 104, 0, 0x00000000, bhvRocketSpawner),
		OBJECT(MODEL_ROCKET_SPAWNER, 3796, -13613, -15903, 0, -16, 0, 0x00000000, bhvRocketSpawner),
		OBJECT(MODEL_STAR, 7380, -11668, -6248, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 7633, -13000, -7743, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 13734, -13613, -2872, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 9223, -7124, 892, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -2081, -7424, -9070, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -34, -1460, 6, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -2057, -11281, 43, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 1014, -12265, -1775, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -588, -8051, 2067, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -48, -5787, -16437, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -584, -10102, -16424, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 563, -12706, -17549, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 9656, -8010, -10057, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 8706, -9791, -6690, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 9441, -9761, -10092, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 11706, -10000, -7541, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 9938, -9811, -11700, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -8125, -6589, 3983, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 340, -8372, -15870, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -1064, -7738, -17265, 0, 0, 0, 0x00000000, bhvStar),
		TERRAIN(ph_area_1_collision),
		MACRO_OBJECTS(ph_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 4656, -13643, -12571),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};