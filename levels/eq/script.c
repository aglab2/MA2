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
#include "levels/eq/header.h"

/* Fast64 begin persistent block [scripts] */
#include "levels/eq/area_1/collision.inc.c"
static struct LevelConfig cfg = {
};
/* Fast64 end persistent block [scripts] */

const LevelScript level_eq_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _eq_segment_7SegmentRomStart, _eq_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(        /*seg*/ 0x05, _group6_yay0SegmentRomStart, _group6_yay0SegmentRomEnd),
    LOAD_RAW(         /*seg*/ 0x0C, _group6_geoSegmentRomStart, _group6_geoSegmentRomEnd),
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
    JUMP_LINK(script_func_global_7),
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_EQ_TREASURE_BLUE, eg_treasure_blue_geo),
	LOAD_MODEL_FROM_GEO(MODEL_EQ_TREASURE_BLUE_BREAK, eg_treasure_blue_break_geo),
	LOAD_MODEL_FROM_GEO(MODEL_EQ_TREASURE_GREEN, eg_treasure_green_geo),
	LOAD_MODEL_FROM_GEO(MODEL_EQ_TREASURE_GREEN_BREAK, eg_treasure_green_break_geo),
	LOAD_MODEL_FROM_GEO(MODEL_EQ_TREASURE_RED, eg_treasure_red_geo),
	LOAD_MODEL_FROM_GEO(MODEL_EQ_TREASURE_RED_BREAK, eg_treasure_red_break_geo),
	LOAD_MODEL_FROM_GEO(MODEL_EQ_COFFIN_BLUE, eq_coffin_blue_geo),
	LOAD_MODEL_FROM_GEO(MODEL_EQ_COFFIN_BLUE_BREAK, eq_coffin_blue_break_geo),
	LOAD_MODEL_FROM_GEO(MODEL_EQ_COFFIN_GREEN, eq_coffin_green_geo),
	LOAD_MODEL_FROM_GEO(MODEL_EQ_COFFIN_GREEN_BREAK, eq_coffin_green_break_geo),
	LOAD_MODEL_FROM_GEO(MODEL_EQ_VASE, eq_vase_geo),
	/* Fast64 begin persistent block [level commands] */
	LVL_CONFIG(&cfg),
	/* Fast64 end persistent block [level commands] */

	AREA(1, eq_area_1, 0, 0, 0),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, 9542, -300, 9491),
		TERRAIN(eq_area_1_collision),
		MACRO_OBJECTS(eq_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 9542, -300, 9491),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};