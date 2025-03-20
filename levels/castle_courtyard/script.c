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

#include "actors/common1.h"
#include "make_const_nonconst.h"
#include "levels/castle_courtyard/header.h"

/* Fast64 begin persistent block [scripts] */
#define SEQ_LEVEL_GRASS 0
/* Fast64 end persistent block [scripts] */

const LevelScript level_castle_courtyard_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _castle_courtyard_segment_7SegmentRomStart, _castle_courtyard_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group10_yay0SegmentRomStart, _group10_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group10_geoSegmentRomStart, _group10_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_11), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_METAL_DOOR, metal_door_geo), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, castle_courtyard_area_1, 0, 0, 0),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_COURTYARD, 0x01, 0xf0, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_COURTYARD, 0x01, 0xf1, WARP_NO_CHECKPOINT),
		WARP_NODE(0, LEVEL_CASTLE, 0x01, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(1, LEVEL_CASTLE, 0x01, 1, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, 18, 815, 9363),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -1257, 1358, 17148, 0, -180, 0, (0 << 16), bhvDoorWarp),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -1414, 1358, 17149, 0, 0, 0, (1 << 16), bhvDoorWarp),
		OBJECT(MODEL_CASTLE_METAL_DOOR, -4611, 44, 16938, 0, -132, 0, (0 << 16), bhvDoorWarp),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, 132, 947, 11071, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, 859, 1164, 11843, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, 4902, 991, 16285, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, 5451, 824, 13688, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, 3911, 884, 13666, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, 4614, 815, 12039, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, 4868, 1042, 10337, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, 3241, 985, 9466, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, -474, 1263, 11972, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, -6937, 1323, 20120, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, -7879, 1351, 18618, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, -7222, 1162, 17443, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, -7842, 1073, 16022, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, -7542, 994, 14696, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, -1939, 1147, 11298, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_WOODEN_SIGNPOST, -30, 815, 10080, 0, -180, 0, (16 << 24) | (16 << 16), bhvMessagePanel),
		OBJECT(MODEL_YOSHI, -1201, 3728, 19558, 0, 0, 0, 0x00000000, bhvYoshi),
		TERRAIN(castle_courtyard_area_1_collision),
		MACRO_OBJECTS(castle_courtyard_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 18, 815, 9363),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};