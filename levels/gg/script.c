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
#include "levels/gg/header.h"

/* Fast64 begin persistent block [scripts] */
#include "game/area.h"
#include "level_config.h"
#define SEQ_LEVEL_GRASS 0x52
extern Gfx gg_skybox_object_00888FE4_mesh[];
static struct LevelConfig cfg = {
	.skybox = gg_skybox_object_00888FE4_mesh,
};
/* Fast64 end persistent block [scripts] */

extern s32 lvl_gg(s16 initOrUpdate, UNUSED s32 unused);
const LevelScript level_gg_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _gg_segment_7SegmentRomStart, _gg_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	/* Fast64 begin persistent block [level commands] */
	LVL_CONFIG(&cfg),
	/* Fast64 end persistent block [level commands] */

	AREA(1, gg_area_1, 0, 0, 0),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 0, 0, 400, 435, -180, 0, (0xa << 16), bhvSpinAirborneWarp),
		OBJECT(MODEL_STAR, 0, -148, 8, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, 0, -148, 8, 0, -180, 0, 0x00000000, bhvGG),
		TERRAIN(gg_area_1_collision),
		MACRO_OBJECTS(gg_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, gg_area_2, 0, 0, 0),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		TERRAIN(gg_area_2_collision),
		MACRO_OBJECTS(gg_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		OBJECT(MODEL_NONE, 0, 0, 400, 435, -180, 0, (0xa << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, 0, -148, 8, 0, -180, 0, 0x00000000, bhvGG2),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(2, 0, 0, 0, 0),

	BLACKOUT(/*active*/ FALSE),
	CALL(0, lvl_gg),
    SLEEP(/*frames*/ 120),

	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};