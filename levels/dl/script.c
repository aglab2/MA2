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
#include "levels/dl/header.h"

/* Fast64 begin persistent block [scripts] */
#include "levels/dl/area_1/collision.inc.c"
extern Gfx dl_skybox_skybox_mesh[];
static struct LevelConfig cfg = {
	.skybox = dl_skybox_skybox_mesh,
};
#define SEQ_LEVEL_GRASS 0x37
/* Fast64 end persistent block [scripts] */

const LevelScript level_dl_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _dl_segment_7SegmentRomStart, _dl_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x05, _group5_yay0SegmentRomStart, _group5_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group5_geoSegmentRomStart, _group5_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_6), 
	JUMP_LINK(script_func_global_14), 
	/* Fast64 begin persistent block [level commands] */
	LVL_CONFIG(&cfg),
	/* Fast64 end persistent block [level commands] */

	AREA(1, dl_area_1, 0, 0, 0),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x10, LEVEL_DL, 0x01, 0x12, WARP_NO_CHECKPOINT),
		WARP_NODE(0x11, LEVEL_DL, 0x01, 0x13, WARP_NO_CHECKPOINT),
		WARP_NODE(0x12, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x13, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 1967, -511, -686, 0, 0, 0, (100 << 24) | (0x10 << 16), bhvWarp),
		OBJECT(MODEL_NONE, 1994, -344, 14470, 0, 0, 0, (100 << 24) | (0x11 << 16), bhvWarp),
		OBJECT(MODEL_NONE, 1967, -54, -686, 0, 0, 0, (0x13 << 16), bhvSwimmingWarp),
		OBJECT(MODEL_NONE, 1994, -136, 14470, 0, 0, 0, (0x12 << 16), bhvSwimmingWarp),
		TERRAIN(dl_area_1_collision),
		MACRO_OBJECTS(dl_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};