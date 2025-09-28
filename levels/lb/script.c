#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"
#include "level_config.h"
#include "rail_desc.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "make_const_nonconst.h"
#include "levels/lb/header.h"

/* Fast64 begin persistent block [scripts] */
extern const RailDesc* rail_descs_lb[];
static struct LevelConfig cfg = {
	.railDesc = (void*) rail_descs_lb,
};
#define SEQ_LEVEL_GRASS 0
/* Fast64 end persistent block [scripts] */

const LevelScript level_lb_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _lb_segment_7SegmentRomStart, _lb_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x06, _group12_yay0SegmentRomStart, _group12_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group12_geoSegmentRomStart, _group12_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_13), 
	LOAD_MODEL_FROM_GEO(MODEL_LB_RAIL, lb_rail_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LB_BALL, lb_ball_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LB_STAND, lb_stand_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LB_TAIL, lb_tail_geo),
	LOAD_MODEL_FROM_GEO(MODEL_LB_SPARKLE, lb_sparkle_geo),
	LOAD_MODEL_FROM_GEO(MODEL_LB_SPARKLE2, lb_sparkle2_geo),
	/* Fast64 begin persistent block [level commands] */
	LVL_CONFIG(&cfg),
	/* Fast64 end persistent block [level commands] */

	AREA(1, lb_area_1, 0, 0, 0),
		WARP_NODE(0x0A, LEVEL_LF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_END, 2, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, -690, 487, 2433),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, 0, 0, 0x00000000, bhvLBCtl),
		OBJECT(MODEL_NONE, -521, 487, 2717, 0, 180, 0, (0xa << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_BOWSER, -110, -856, 29, 0, 0, 0, 0x00000000, bhvBowser),
		TERRAIN(lb_area_1_collision),
		MACRO_OBJECTS(lb_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -690, 487, 2433),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};