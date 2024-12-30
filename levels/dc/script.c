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
#include "levels/dc/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_dc_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _dc_segment_7SegmentRomStart, _dc_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, dc_area_1, 0, 0, 0),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x20, LEVEL_DC, 0x01, 0x21, WARP_NO_CHECKPOINT),
		WARP_NODE(0x21, LEVEL_DC, 0x01, 0x20, WARP_NO_CHECKPOINT),
		WARP_NODE(0x22, LEVEL_DC, 0x01, 0x23, WARP_NO_CHECKPOINT),
		WARP_NODE(0x23, LEVEL_DC, 0x01, 0x22, WARP_NO_CHECKPOINT),
		WARP_NODE(0x24, LEVEL_DC, 0x01, 0x25, WARP_NO_CHECKPOINT),
		WARP_NODE(0x25, LEVEL_DC, 0x01, 0x24, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, -46, 9506, -300, 9517),
		OBJECT(MODEL_CHECKPOINT, 2, -1300, 7853, 0, 0, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHECKPOINT, 13985, -300, 6217, 0, 0, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHECKPOINT, -9519, -300, 9524, 0, 44, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHECKPOINT, 9515, -300, -9517, 0, 44, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHECKPOINT, 13994, -300, -106, 0, 89, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_STAR, 8764, 1556, 8762, 0, -46, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 9317, 171, 10080, 0, -46, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 7604, 1186, 7589, 0, -46, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 7348, 453, 6144, 0, -46, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 5447, 1204, 5449, 0, -46, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 1491, 2255, 2, 0, -46, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 21, 159, -3531, 0, -46, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 1992, 1175, -2085, 0, -46, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 1208, 1467, 1173, 0, -46, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -1679, -2520, -307, 0, -46, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -9250, -493, -9261, 0, -46, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -3454, 547, 4058, 0, -46, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -9343, 1038, 9334, 0, -46, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -9109, 943, 7464, 0, -46, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -9794, -1066, 3082, 0, -46, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -6180, 384, 9428, 0, -46, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -2, -771, 7229, 0, -46, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 15095, -106, 4134, 0, -46, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 13765, 129, -3200, 0, -46, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 9801, 1073, -3653, 0, -46, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 8092, 606, -9136, 0, -46, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 9246, 1079, -9251, 0, -46, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 6581, -153, -9793, 0, -46, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 5450, 704, -5473, 0, -46, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -1583, -106, 13312, 0, -46, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 11841, 417, 3897, 0, -46, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -108, 568, 13264, 0, -46, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -2020, -61, 12472, 0, -46, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_THI_WARP_PIPE, 9822, -300, 6480, 0, -46, 0, (0x20 << 16), bhvWarpPipe),
		OBJECT(MODEL_THI_WARP_PIPE, 12956, -300, 4204, 0, -46, 0, (0x21 << 16), bhvWarpPipe),
		OBJECT(MODEL_THI_WARP_PIPE, 12035, -300, -4208, 0, -46, 0, (0x22 << 16), bhvWarpPipe),
		OBJECT(MODEL_THI_WARP_PIPE, 9797, -300, -6482, 0, -46, 0, (0x23 << 16), bhvWarpPipe),
		OBJECT(MODEL_THI_WARP_PIPE, 5, -1300, 8362, 0, -46, 0, (0x24 << 16), bhvWarpPipe),
		OBJECT(MODEL_THI_WARP_PIPE, -1592, 400, 14789, 0, -46, 0, (0x25 << 16), bhvWarpPipe),
		TERRAIN(dc_area_1_collision),
		MACRO_OBJECTS(dc_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -46, 9506, -300, 9517),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};