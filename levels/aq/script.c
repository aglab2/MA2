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
#include "levels/aq/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_aq_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _aq_segment_7SegmentRomStart, _aq_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x05, _group3_yay0SegmentRomStart, _group3_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group3_geoSegmentRomStart, _group3_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_4), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_AQ_MILKIN_DOOR, aq_milkin_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_AQ_DRMCN, aq_drmcn_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_AQ_DRMCN_BREAK, aq_drmcn_break_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_AQ_MILATTI, aq_milatti_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_AQ_MILIFT, aq_milift_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_AQ_MITRUCK, aq_mitruck_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_AQ_MITRUCK_BREAK, aq_mitruck_break_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_AQ_PIC, aq_pic_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_AQ_UKIASIBA, aq_ukiasiba_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_AQ_WATER, aq_water_geo), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, aq_area_1, 0, 0, 0),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, 48, 1643, -2170),
		OBJECT(MODEL_AQ_MILKIN_DOOR, 920, -2500, 1808, 0, 0, 0, 0x00000000, bhvBreakable),
		OBJECT(MODEL_AQ_MILKIN_DOOR, -1814, -2500, 791, 0, 0, 0, 0x00000000, bhvBreakable),
		OBJECT(MODEL_AQ_MILKIN_DOOR, -1421, -2500, -1813, 0, 0, 0, 0x00000000, bhvBreakable),
		OBJECT(MODEL_AQ_DRMCN, 756, -800, 2578, 0, 0, 0, (MODEL_AQ_DRMCN_BREAK << 16), bhvBreakable),
		OBJECT(MODEL_AQ_DRMCN, 342, -800, 2485, 0, 0, 0, (MODEL_AQ_DRMCN_BREAK << 16), bhvBreakable),
		OBJECT(MODEL_AQ_DRMCN, 1305, -800, 2530, 0, 0, 0, (MODEL_AQ_DRMCN_BREAK << 16), bhvBreakable),
		OBJECT(MODEL_AQ_DRMCN, 1763, -800, 2616, 0, 0, 0, (MODEL_AQ_DRMCN_BREAK << 16), bhvBreakable),
		OBJECT(MODEL_AQ_UKIASIBA, 1735, -2175, 1757, 0, 0, 0, (MODEL_AQ_DRMCN_BREAK << 16), bhvWdwSquareFloatingPlatform),
		OBJECT(MODEL_AQ_UKIASIBA, -2464, -200, -2448, 0, 0, 0, (MODEL_AQ_DRMCN_BREAK << 16), bhvWdwSquareFloatingPlatform),
		OBJECT(MODEL_AQ_UKIASIBA, 3253, -1500, -3139, 0, 0, 0, (MODEL_AQ_DRMCN_BREAK << 16), bhvWdwSquareFloatingPlatform),
		OBJECT(MODEL_AQ_UKIASIBA, 3267, -1463, -5629, 0, 0, 0, (MODEL_AQ_DRMCN_BREAK << 16), bhvWdwSquareFloatingPlatform),
		OBJECT(MODEL_PURPLE_SWITCH, -234, 1003, -4262, 0, 0, 0, 0x00000000, bhvFloorSwitchGrills),
		OBJECT(MODEL_PURPLE_SWITCH, 259, 1003, -4262, 0, 0, 0, (1 << 8), bhvFloorSwitchGrills),
		OBJECT(MODEL_PURPLE_SWITCH, 1045, 3103, 986, 0, -44, 0, (2 << 8), bhvFloorSwitchGrills),
		OBJECT(MODEL_AQ_MILIFT, 0, -244, 0, 0, 0, 0, 0x00000000, bhvAqLift),
		OBJECT(MODEL_AQ_MITRUCK, 1682, -2500, 262, 0, -22, 0, (MODEL_AQ_MITRUCK_BREAK << 16), bhvBreakable),
		OBJECT(MODEL_AQ_MITRUCK, 3204, -850, -1562, 0, 14, 0, (MODEL_AQ_MITRUCK_BREAK << 16), bhvBreakable),
		OBJECT(MODEL_AQ_MITRUCK, 1658, -2446, -2517, 0, -17, 0, (MODEL_AQ_MITRUCK_BREAK << 16), bhvBreakable),
		OBJECT(MODEL_AQ_MITRUCK, 3253, -1500, -3736, 0, 6, 0, (MODEL_AQ_MITRUCK_BREAK << 16), bhvBreakable),
		OBJECT(MODEL_AQ_WATER, 0, -286, 0, 0, 0, 0, 0x00000000, bhvAqWater),
		TERRAIN(aq_area_1_collision),
		MACRO_OBJECTS(aq_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 48, 1643, -2170),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};