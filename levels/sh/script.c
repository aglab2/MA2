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
#include "levels/sh/header.h"

/* Fast64 begin persistent block [scripts] */
#include "levels/sh/area_1/collision.inc.c"
static struct LevelConfig cfg = {
};
#define SEQ_LEVEL_GRASS 0x3E
/* Fast64 end persistent block [scripts] */

const LevelScript level_sh_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _sh_segment_7SegmentRomStart, _sh_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	/* Fast64 begin persistent block [level commands] */
	LVL_CONFIG(&cfg),
	/* Fast64 end persistent block [level commands] */

	AREA(1, sh_area_1, 0, 0, 0),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 89, -5022, -5730, 2030),
		OBJECT(MODEL_NONE, -1984, -8910, 2010, 0, -86, 0, (0xa << 16), bhvInstantActiveWarp),
		TERRAIN(sh_area_1_collision),
		MACRO_OBJECTS(sh_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 89, -5022, -5730, 2030),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};