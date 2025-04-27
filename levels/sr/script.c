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
#include "levels/sr/header.h"

/* Fast64 begin persistent block [scripts] */
#include "levels/sr/area_1/collision.inc.c"
#include "levels/sr/area_2/collision.inc.c"
#include "levels/sr/area_3/collision.inc.c"
#define sr_area_2 sr_area_1
#define sr_area_3 sr_area_1
extern Gfx sr_skybox_sr_skybox_mesh[];
extern const RailDesc* rail_descs_sr[];
extern IWDHeader* iw_descs_sr[];
static struct LevelConfig cfg = {
	.skybox = sr_skybox_sr_skybox_mesh,
	.railDesc = &rail_descs_sr,
	.iwds = &iw_descs_sr,
};
/* Fast64 end persistent block [scripts] */

const LevelScript level_sr_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _sr_segment_7SegmentRomStart, _sr_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	LOAD_MODEL_FROM_GEO(MODEL_SR_DRUM, sr_drum_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SR_DRUM_BREAK, sr_drum_break_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SR_PNP, sr_pnp_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SR_PNP_GROUND, sr_pnp_ground_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SR_PNP_LIMIT, sr_pnp_limit_geo), 
	/* Fast64 begin persistent block [level commands] */
	LVL_CONFIG(&cfg),
	/* Fast64 end persistent block [level commands] */

	AREA(1, sr_area_1, -2000, -941, 1500),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, 20410, -1837, 480),
		OBJECT(MODEL_SR_PNP, 19117, -1837, 1964, 0, -32, 0, (200 << 16), bhvSrJump),
		OBJECT(MODEL_NONE, 20121, -1837, 2052, 0, 0, 0, (2 << 24) | (25 << 16), bhvPushOut),
		OBJECT(MODEL_NONE, 14235, 3165, 9573, 0, 0, 0, (2 << 24) | (25 << 16), bhvPushOut),
		OBJECT(MODEL_NONE, 21098, -1835, 994, 0, 0, 0, (6 << 24) | (50 << 16), bhvPushOut),
		OBJECT(MODEL_NONE, 14341, 3164, 9049, 0, 0, 0, (6 << 24) | (50 << 16), bhvPushOut),
		OBJECT(MODEL_NONE, 10475, 1664, 9142, 0, 0, 0, (6 << 24) | (50 << 16), bhvPushOut),
		OBJECT(MODEL_NONE, -12496, -4096, 15587, 0, 0, 0, (6 << 24) | (50 << 16), bhvPushOut),
		TERRAIN(sr_area_1_collision),
		MACRO_OBJECTS(sr_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, sr_area_2, -2000, -2636, 5500),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -14566, 14859, -23625, 0, 0, 0, (2 << 24) | (25 << 16), bhvPushOut),
		OBJECT(MODEL_NONE, -14458, 15420, -24428, 0, 0, 0, (2 << 24) | (25 << 16), bhvPushOut),
		OBJECT(MODEL_NONE, -13981, 15417, -25004, 0, 0, 0, (2 << 24) | (25 << 16), bhvPushOut),
		OBJECT(MODEL_NONE, -1267, 3855, -9999, 0, 0, 0, (6 << 24) | (50 << 16), bhvPushOut),
		OBJECT(MODEL_NONE, -1155, 3855, -11109, 0, 0, 0, (6 << 24) | (50 << 16), bhvPushOut),
		OBJECT(MODEL_NONE, -53, 9322, -9128, 0, 0, 0, (6 << 24) | (50 << 16), bhvPushOut),
		TERRAIN(sr_area_2_collision),
		MACRO_OBJECTS(sr_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(3, sr_area_3, -2000, -4576, 9500),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -4353, 7968, -5502, 0, 0, 0, 0x00000000, bhvFlamethrower),
		OBJECT(MODEL_NONE, -5634, 7968, -6034, 0, -180, 0, 0x00000000, bhvFlamethrower),
		OBJECT(MODEL_NONE, -3517, 5505, -12079, 0, 0, 0, (6 << 24) | (50 << 16), bhvPushOut),
		OBJECT(MODEL_NONE, -3618, 7005, -9790, 0, 0, 0, (6 << 24) | (50 << 16), bhvPushOut),
		OBJECT(MODEL_NONE, -5352, 7905, -6473, 0, 0, 0, (6 << 24) | (50 << 16), bhvPushOut),
		TERRAIN(sr_area_3_collision),
		MACRO_OBJECTS(sr_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 20410, -1837, 480),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};