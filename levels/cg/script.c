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
#include "levels/cg/header.h"

/* Fast64 begin persistent block [scripts] */
extern const GeoLayout cg_area_visual[];
#define cg_area_1 cg_area_visual
#define cg_area_2 cg_area_visual
#define cg_area_3 cg_area_visual
#define cg_area_4 cg_area_visual
#define cg_area_5 cg_area_visual
#define cg_area_6 cg_area_visual
#define cg_area_7 cg_area_visual
#define cg_area_8 cg_area_visual
#define cg_area_9 cg_area_visual
#define cg_area_10 cg_area_visual
/* Fast64 end persistent block [scripts] */

const LevelScript level_cg_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _cg_segment_7SegmentRomStart, _cg_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	LOAD_MODEL_FROM_GEO(MODEL_CG_SHUTTER_LEFT, cg_shutter_left_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CG_SHUTTER_RIGHT, cg_shutter_right_geo), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, cg_area_1, -2000, 89, -2000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x20, LEVEL_CG, 0x01, 0x21, WARP_NO_CHECKPOINT),
		WARP_NODE(0x21, LEVEL_CG, 0x01, 0x20, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, 20011, -1186, 23988),
		OBJECT(MODEL_NONE, 11712, -2285, 15986, 0, 0, 0, 0x00000000, bhvGravFlip),
		OBJECT(MODEL_NONE, 5789, -686, 15964, 0, 0, 0, (1 << 16), bhvGravFlip),
		OBJECT(MODEL_NONE, -13716, 1615, 14497, 0, 0, 0, 0x00000000, bhvGravFlip),
		OBJECT(MODEL_NONE, -18295, 4934, 5721, 0, 0, 0, (1 << 16), bhvGravFlip),
		OBJECT(MODEL_NONE, -19833, 1145, 6438, 0, 0, 0, 0x00000000, bhvGravFlip),
		OBJECT(MODEL_NONE, -19911, 2144, 6457, 0, 0, 0, (1 << 16), bhvGravFlip),
		OBJECT(MODEL_NONE, -804, 4057, 15980, 0, 90, 0, (10 << 24) | (0x20 << 16), bhvWarp),
		OBJECT(MODEL_THI_WARP_PIPE, -6617, 545, 14499, 0, -90, 0, (0x21 << 16), bhvWarpPipe),
		OBJECT(MODEL_NONE, 20004, -1186, 21222, 0, 0, 0, 0x00000000, bhvShutter),
		OBJECT(MODEL_STAR, -17139, -718, 6450, 0, 0, 0, 0x00000000, bhvStar),
		TERRAIN(cg_area_1_collision),
		MACRO_OBJECTS(cg_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, cg_area_2, -6000, -957, -2000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x22, LEVEL_CG, 3, 0x23, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_THI_WARP_PIPE, -358, -2712, -12029, 0, 0, 0, (0x22 << 16), bhvWarpPipe),
		TERRAIN(cg_area_2_collision),
		MACRO_OBJECTS(cg_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(3, cg_area_3, -10000, -998, -2000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x23, LEVEL_CG, 2, 0x22, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 7966, -692, -18054, 0, 0, 0, 0x00000000, bhvGravFlip),
		OBJECT(MODEL_NONE, 8759, 1817, -18064, 0, 0, 0, (1 << 16), bhvGravFlip),
		OBJECT(MODEL_NONE, 2994, -286, -9039, 0, 0, 0, 0x00000000, bhvGravFlip),
		OBJECT(MODEL_NONE, 16944, 1034, -18042, 0, 0, 0, 0x00000000, bhvGravFlip),
		OBJECT(MODEL_NONE, 16945, 1100, -18047, 0, 0, 0, (0x23 << 16), bhvWarp),
		TERRAIN(cg_area_3_collision),
		MACRO_OBJECTS(cg_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(4, cg_area_4, -10000, -998, -6000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x24, LEVEL_CG, 0x01, 0x25, WARP_NO_CHECKPOINT),
		WARP_NODE(0x25, LEVEL_CG, 0x01, 0x24, WARP_NO_CHECKPOINT),
		WARP_NODE(0x26, LEVEL_CG, 4, 0x27, WARP_NO_CHECKPOINT),
		WARP_NODE(0x27, LEVEL_CG, 4, 0x26, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 2895, -2939, 7300, 0, 0, 0, (1 << 16), bhvGravFlip),
		OBJECT(MODEL_THI_WARP_PIPE, 2883, -3536, 4615, 0, 0, 0, (0x24 << 16), bhvWarpPipe),
		OBJECT(MODEL_THI_WARP_PIPE, -2530, -3536, 4672, 0, 0, 0, (0x25 << 16), bhvWarpPipe),
		OBJECT(MODEL_NONE, -9492, -6396, 16226, 0, 0, 0, (0x26 << 16), bhvWarp),
		OBJECT(MODEL_THI_WARP_PIPE, -9506, -686, 16279, 0, 0, 0, (0x27 << 16), bhvWarpPipe),
		TERRAIN(cg_area_4_collision),
		MACRO_OBJECTS(cg_area_4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 20011, -1186, 23988),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};