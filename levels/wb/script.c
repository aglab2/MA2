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
#include "levels/wb/header.h"

/* Fast64 begin persistent block [scripts] */
#include "levels/wb/area_1/collision.inc.c"
#include "levels/wb/area_2/collision.inc.c"
#define wb_area_2 wb_area_1
static struct LevelConfig cfg = {
	.skybox = &wb_skybox_object_005ED684_mesh,
};
/* Fast64 end persistent block [scripts] */

const LevelScript level_wb_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _wb_segment_7SegmentRomStart, _wb_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	/* Fast64 begin persistent block [level commands] */
	LVL_CONFIG(&cfg),
	/* Fast64 end persistent block [level commands] */

	AREA(1, wb_area_1, 2000, 0, -3000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, -19895, -1600, 29229),
		OBJECT(MODEL_NONE, -19895, -1600, 29229, 0, 0, 0, (0xa << 16), bhvInstantActiveWarp),
		TERRAIN(wb_area_1_collision),
		MACRO_OBJECTS(wb_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, wb_area_2, 2000, 0, -7000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		TERRAIN(wb_area_2_collision),
		MACRO_OBJECTS(wb_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -19895, -1600, 29229),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};