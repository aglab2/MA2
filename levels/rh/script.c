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
#include "levels/rh/header.h"

/* Fast64 begin persistent block [scripts] */
#include "levels/rh/area_1/collision.inc.c"
#include "levels/rh/area_2/collision.inc.c"
#include "levels/rh/area_3/collision.inc.c"
#include "levels/rh/area_4/collision.inc.c"
#include "levels/rh/area_5/collision.inc.c"
#include "levels/rh/area_6/collision.inc.c"
#include "levels/rh/area_7/collision.inc.c"
#define rh_area_2 rh_area_1
#define rh_area_3 rh_area_1
#define rh_area_4 rh_area_1
#define rh_area_5 rh_area_1
#define rh_area_6 rh_area_1
#define rh_area_7 rh_area_1
extern Gfx rh_skybox_rh_skybox_mesh[];
extern const SpringDesc* spring_descs_rh[];
extern const RailDesc* rail_descs_rh[];
extern const IWDHeader* iw_descs_rh[];
static struct LevelConfig cfg = {
	.skybox = rh_skybox_rh_skybox_mesh,
	.iwds = iw_descs_rh,
	.railDesc = rail_descs_rh,
	.springDescs = spring_descs_rh,
};
#define SEQ_LEVEL_GRASS 0x3B
/* Fast64 end persistent block [scripts] */

const LevelScript level_rh_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _rh_segment_7SegmentRomStart, _rh_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	LOAD_MODEL_FROM_GEO(MODEL_RH_HAMMER, rh_hammer_geo),
	LOAD_MODEL_FROM_GEO(MODEL_RH_CONE, rh_cone_geo),
	LOAD_MODEL_FROM_GEO(MODEL_RH_SLANE, rh_slane_geo),
	LOAD_MODEL_FROM_GEO(MODEL_RH_SLANE_BREAK, rh_slane_break_geo),
	/* Fast64 begin persistent block [level commands] */
	LVL_CONFIG(&cfg),
	/* Fast64 end persistent block [level commands] */

	AREA(1, rh_area_1, -1000, -600, -3000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, 9863, 8083, 30009),
		OBJECT(MODEL_CHECKPOINT, -2724, -4200, -14008, 0, -90, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHECKPOINT, -18705, 1280, -14491, 0, -90, 0, 0x00000000, bhvCheckpoint),
		TERRAIN(rh_area_1_collision),
		MACRO_OBJECTS(rh_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, rh_area_2, -5000, -1909, -3000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CHUCKYA, 1, -8028, -17390, 0, -90, 0, 0x00000000, bhvChuckya),
		TERRAIN(rh_area_2_collision),
		MACRO_OBJECTS(rh_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(3, rh_area_3, -5000, -4150, -7000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CHECKPOINT, -16635, 8645, 7276, 0, -180, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_ROCKET_SPAWNER, -16623, 13645, 17814, 0, -180, 0, (1 << 16), bhvRocketSpawner),
		TERRAIN(rh_area_3_collision),
		MACRO_OBJECTS(rh_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(4, rh_area_4, -5000, -5123, -11000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CHECKPOINT, -13276, 81, 1669, 0, -180, 0, 0x00000000, bhvCheckpoint),
		TERRAIN(rh_area_4_collision),
		MACRO_OBJECTS(rh_area_4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(5, rh_area_5, -9000, -5351, -11000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CHECKPOINT, 6277, 2361, -15833, 0, -180, 0, 0x00000000, bhvCheckpoint),
		TERRAIN(rh_area_5_collision),
		MACRO_OBJECTS(rh_area_5_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(6, rh_area_6, -9000, -6293, -15000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		TERRAIN(rh_area_6_collision),
		MACRO_OBJECTS(rh_area_6_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(7, rh_area_7, -9000, -6293, -19000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -9733, -7065, 6940, 0, -90, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -9723, -7065, 9750, 0, -90, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_GOAL, -9734, -6799, 5737, 0, -90, 0, 0x00000000, bhvGoal),
		OBJECT(MODEL_NONE, -9614, -7065, 8770, 0, -90, 0, 0x00000000, bhvGoombaTripletSpawner),
		TERRAIN(rh_area_7_collision),
		MACRO_OBJECTS(rh_area_7_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 9863, 8083, 30009),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};