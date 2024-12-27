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
#include "levels/pc/header.h"

/* Fast64 begin persistent block [scripts] */
extern const GeoLayout pc_area_visual[];
#define pc_area_1 pc_area_visual
#define pc_area_2 pc_area_visual
#define pc_area_3 pc_area_visual
#define pc_area_4 pc_area_visual
#define pc_area_5 pc_area_visual
#define pc_area_6 pc_area_visual
#define pc_area_7 pc_area_visual
#define pc_area_8 pc_area_visual
#define pc_area_9 pc_area_visual
#define pc_area_10 pc_area_visual
/* Fast64 end persistent block [scripts] */

const LevelScript level_pc_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _pc_segment_7SegmentRomStart, _pc_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	LOAD_MODEL_FROM_GEO(MODEL_PC_BLOCK, pc_block_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PC_DOOR_B, pc_door_b_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PC_DOOR_G, pc_door_g_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PC_DOOR_R, pc_door_r_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PC_DOOR_N, pc_door_n_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PC_KEY_BLUE, pc_key_blue_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PC_KEY_GREEN, pc_key_green_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PC_KEYDOOR_BLUE, pc_keydoor_blue_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PC_KEYDOOR_GREEN, pc_keydoor_green_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PC_WALLTYPE, pc_walltype_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PC_WINDMILL, pc_windmill_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PC_SANDGLASS_ENDS, pc_sandglass_ends_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PC_SANDGLASS_GLASS, pc_sandglass_glass_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PC_SANDGLASS_SAND, pc_sandglass_sand_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PC_SANDGLASS_SANDF, pc_sandglass_sandf_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PC_SANDGLASS_SPRING, pc_sandglass_spring_geo), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, pc_area_1, 1000, -726, -1000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, -10005, 8926, 10007),
		OBJECT(MODEL_NONE, -9762, 7263, 9122, 0, 0, 0, 0x00000000, bhvPcSandglass),
		TERRAIN(pc_area_1_collision),
		MACRO_OBJECTS(pc_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, pc_area_2, 1000, -1608, -5000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		TERRAIN(pc_area_2_collision),
		MACRO_OBJECTS(pc_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(3, pc_area_3, -3000, -1608, -5000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		TERRAIN(pc_area_3_collision),
		MACRO_OBJECTS(pc_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(4, pc_area_4, -3000, -1608, -9000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		TERRAIN(pc_area_4_collision),
		MACRO_OBJECTS(pc_area_4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(5, pc_area_5, -3000, -2488, -13000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		TERRAIN(pc_area_5_collision),
		MACRO_OBJECTS(pc_area_5_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(6, pc_area_6, -3000, -3632, -17000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		TERRAIN(pc_area_6_collision),
		MACRO_OBJECTS(pc_area_6_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(7, pc_area_7, -3000, -3632, -21000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		TERRAIN(pc_area_7_collision),
		MACRO_OBJECTS(pc_area_7_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(8, pc_area_8, 1000, -3632, -21000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		TERRAIN(pc_area_8_collision),
		MACRO_OBJECTS(pc_area_8_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -10005, 8926, 10007),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};