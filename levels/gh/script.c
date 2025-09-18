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
#include "levels/gh/header.h"

/* Fast64 begin persistent block [scripts] */
#include "instant_warp_desc.h"
#include "level_config.h"
extern const GeoLayout gh_area_1[];
extern IWDHeader* iw_descs_gh[];
#define gh_area_1 gh_area_1
#define gh_area_2 gh_area_1
#include "levels/gh/area_1/collision.inc.c"
#include "levels/gh/area_2/collision.inc.c"
extern Gfx gh_skybox_gh_skybox_mesh[];
static struct LevelConfig cfg = {
	.iwds = iw_descs_gh,
	.viewRangeMult = 3.f,
	.skybox = gh_skybox_gh_skybox_mesh,
};
#define SEQ_LEVEL_GRASS 0x4D
/* Fast64 end persistent block [scripts] */

const LevelScript level_gh_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _gh_segment_7SegmentRomStart, _gh_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	/* Fast64 begin persistent block [level commands] */
	LVL_CONFIG(&cfg),
	/* Fast64 end persistent block [level commands] */

	AREA(1, gh_area_1, 0, -174, -900),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, 70, 2145, 6428),
		TERRAIN(gh_area_1_collision),
		MACRO_OBJECTS(gh_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, gh_area_2, 0, -674, -4900),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		TERRAIN(gh_area_2_collision),
		MACRO_OBJECTS(gh_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 70, 2145, 6428),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};