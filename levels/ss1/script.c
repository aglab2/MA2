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
#include "levels/ss1/header.h"

/* Fast64 begin persistent block [scripts] */
#include "level_config.h"
#define SEQ_LEVEL_GRASS 0x45
static struct LevelConfig cfg = {
};
/* Fast64 end persistent block [scripts] */

const LevelScript level_ss1_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _ss1_segment_7SegmentRomStart, _ss1_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x06, _group12_yay0SegmentRomStart, _group12_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group12_geoSegmentRomStart, _group12_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_13), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_SS1_SPACE, ss1_space_geo),
	LOAD_MODEL_FROM_GEO(MODEL_SS1_BOO, ss1_boo_geo),
	LOAD_MODEL_FROM_GEO(MODEL_SS1_SHADOW, ss1_shadow_geo),
	LOAD_MODEL_FROM_GEO(MODEL_SS1_BOO_BOO, ss1_booboo_geo),
	LOAD_MODEL_FROM_GEO(MODEL_SS1_FLY, ss1_fly_geo),
	LOAD_MODEL_FROM_GEO(MODEL_SS1_GOLEM, ss1_golem_geo),
	LOAD_MODEL_FROM_GEO(MODEL_SS1_GOLEM_GEO, ss1_golem_go_geo),
	/* Fast64 begin persistent block [level commands] */
	LVL_CONFIG(&cfg),
	/* Fast64 end persistent block [level commands] */

	AREA(1, ss1_area_1, 0, 0, 0),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_END, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_END, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BOWSER, 4416, 0, -4, 0, -90, 0, 0x00000000, bhvBowser),
		OBJECT(MODEL_SS1_SPACE, 0, 0, 0, 0, 0, 0, 0x00000000, bhvSSCtl),
		OBJECT(MODEL_NONE, 3021, 280, 4, 0, 90, 0, (0xa << 16), bhvInstantActiveWarp),
		TERRAIN(ss1_area_1_collision),
		MACRO_OBJECTS(ss1_area_1_macro_objs),
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