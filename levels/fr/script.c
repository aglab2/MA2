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
#include "levels/fr/header.h"

/* Fast64 begin persistent block [scripts] */
extern const GeoLayout fr_area_visual[];
#define fr_area_1 fr_area_visual
#define fr_area_2 fr_area_visual
#define fr_area_3 fr_area_visual
#define fr_area_4 fr_area_visual
#define fr_area_5 fr_area_visual
#define fr_area_6 fr_area_visual
#define fr_area_7 fr_area_visual
#define fr_area_8 fr_area_visual
#define fr_area_9 fr_area_visual
#define fr_area_10 fr_area_visual
#define fr_area_11 fr_area_visual
#define fr_area_12 fr_area_visual

#include "levels/fr/area_1/collision.inc.c"
#include "levels/fr/area_10/collision.inc.c"
#include "levels/fr/area_11/collision.inc.c"
#include "levels/fr/area_12/collision.inc.c"
#include "levels/fr/area_2/collision.inc.c"
#include "levels/fr/area_3/collision.inc.c"
#include "levels/fr/area_4/collision.inc.c"
#include "levels/fr/area_5/collision.inc.c"
#include "levels/fr/area_6/collision.inc.c"
#include "levels/fr/area_7/collision.inc.c"
#include "levels/fr/area_8/collision.inc.c"
#include "levels/fr/area_9/collision.inc.c"
/* Fast64 end persistent block [scripts] */

const LevelScript level_fr_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _fr_segment_7SegmentRomStart, _fr_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, fr_area_1, 3500, -1213, 1000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x20, LEVEL_CG, 0x01, 0x21, WARP_NO_CHECKPOINT),
		WARP_NODE(0x21, LEVEL_CG, 0x01, 0x20, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, -23994, 12129, -10012),
		TERRAIN(fr_area_1_collision),
		MACRO_OBJECTS(fr_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(10, fr_area_10, 3500, -19137, 17000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x20, LEVEL_CG, 0x01, 0x21, WARP_NO_CHECKPOINT),
		WARP_NODE(0x21, LEVEL_CG, 0x01, 0x20, WARP_NO_CHECKPOINT),
		TERRAIN(fr_area_10_collision),
		MACRO_OBJECTS(fr_area_10_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(11, fr_area_11, 3500, -20732, 13000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x20, LEVEL_CG, 0x01, 0x21, WARP_NO_CHECKPOINT),
		WARP_NODE(0x21, LEVEL_CG, 0x01, 0x20, WARP_NO_CHECKPOINT),
		TERRAIN(fr_area_11_collision),
		MACRO_OBJECTS(fr_area_11_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(12, fr_area_12, 3500, -24352, 9000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x20, LEVEL_CG, 0x01, 0x21, WARP_NO_CHECKPOINT),
		WARP_NODE(0x21, LEVEL_CG, 0x01, 0x20, WARP_NO_CHECKPOINT),
		TERRAIN(fr_area_12_collision),
		MACRO_OBJECTS(fr_area_12_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, fr_area_2, 3500, -4743, 5000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x20, LEVEL_CG, 0x01, 0x21, WARP_NO_CHECKPOINT),
		WARP_NODE(0x21, LEVEL_CG, 0x01, 0x20, WARP_NO_CHECKPOINT),
		TERRAIN(fr_area_2_collision),
		MACRO_OBJECTS(fr_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(3, fr_area_3, 3500, -7762, 5000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x20, LEVEL_CG, 0x01, 0x21, WARP_NO_CHECKPOINT),
		WARP_NODE(0x21, LEVEL_CG, 0x01, 0x20, WARP_NO_CHECKPOINT),
		TERRAIN(fr_area_3_collision),
		MACRO_OBJECTS(fr_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(4, fr_area_4, 7500, -11312, 5000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x20, LEVEL_CG, 0x01, 0x21, WARP_NO_CHECKPOINT),
		WARP_NODE(0x21, LEVEL_CG, 0x01, 0x20, WARP_NO_CHECKPOINT),
		TERRAIN(fr_area_4_collision),
		MACRO_OBJECTS(fr_area_4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(5, fr_area_5, 7500, -12748, 9000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x20, LEVEL_CG, 0x01, 0x21, WARP_NO_CHECKPOINT),
		WARP_NODE(0x21, LEVEL_CG, 0x01, 0x20, WARP_NO_CHECKPOINT),
		TERRAIN(fr_area_5_collision),
		MACRO_OBJECTS(fr_area_5_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(6, fr_area_6, 7500, -14169, 13000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x20, LEVEL_CG, 0x01, 0x21, WARP_NO_CHECKPOINT),
		WARP_NODE(0x21, LEVEL_CG, 0x01, 0x20, WARP_NO_CHECKPOINT),
		TERRAIN(fr_area_6_collision),
		MACRO_OBJECTS(fr_area_6_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(7, fr_area_7, 7500, -13862, 17000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x20, LEVEL_CG, 0x01, 0x21, WARP_NO_CHECKPOINT),
		WARP_NODE(0x21, LEVEL_CG, 0x01, 0x20, WARP_NO_CHECKPOINT),
		TERRAIN(fr_area_7_collision),
		MACRO_OBJECTS(fr_area_7_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(8, fr_area_8, 7500, -15209, 21000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x20, LEVEL_CG, 0x01, 0x21, WARP_NO_CHECKPOINT),
		WARP_NODE(0x21, LEVEL_CG, 0x01, 0x20, WARP_NO_CHECKPOINT),
		TERRAIN(fr_area_8_collision),
		MACRO_OBJECTS(fr_area_8_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(9, fr_area_9, 3500, -16813, 21000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x20, LEVEL_CG, 0x01, 0x21, WARP_NO_CHECKPOINT),
		WARP_NODE(0x21, LEVEL_CG, 0x01, 0x20, WARP_NO_CHECKPOINT),
		TERRAIN(fr_area_9_collision),
		MACRO_OBJECTS(fr_area_9_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -23994, 12129, -10012),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};