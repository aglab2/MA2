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
#define fr_area_13 fr_area_visual

#include "levels/fr/area_1/collision.inc.c"
#include "levels/fr/area_10/collision.inc.c"
#include "levels/fr/area_11/collision.inc.c"
#include "levels/fr/area_12/collision.inc.c"
#include "levels/fr/area_13/collision.inc.c"
#include "levels/fr/area_2/collision.inc.c"
#include "levels/fr/area_3/collision.inc.c"
#include "levels/fr/area_4/collision.inc.c"
#include "levels/fr/area_5/collision.inc.c"
#include "levels/fr/area_6/collision.inc.c"
#include "levels/fr/area_7/collision.inc.c"
#include "levels/fr/area_8/collision.inc.c"
#include "levels/fr/area_9/collision.inc.c"

#include "levels/fr/iw.inc.c"
#define SEQ_LEVEL_GRASS 0x29
/* Fast64 end persistent block [scripts] */

const LevelScript level_fr_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _fr_segment_7SegmentRomStart, _fr_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, fr_area_1, 3500, -1213, 1000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x20, LEVEL_CG, 0x01, 0x21, WARP_NO_CHECKPOINT),
		WARP_NODE(0x21, LEVEL_CG, 0x01, 0x20, WARP_NO_CHECKPOINT),
		MARIO_POS(1, 0, -24021, 12129, -9975),
		OBJECT(MODEL_BLACK_BOBOMB, 7852, -12880, 16421, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_CHECKPOINT, 7905, -13975, 19274, 0, -180, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHUCKYA, 8671, -2771, -4454, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_NONE, 11023, -5717, 1014, 0, 90, 0, (0 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 9057, -5170, 1953, 0, -180, 0, (0 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 5998, 276, -10878, 0, -180, 0, (0 << 16), bhvCoinFormation),
		OBJECT(MODEL_STAR, 2935, 4643, -17056, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -396, -2467, 1445, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 11014, -5490, 2120, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 7908, -11074, 14011, 0, 0, 0, 0x00000000, bhvStar),
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
		OBJECT(MODEL_BLACK_BOBOMB, -10341, 473, 9795, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -10447, 473, 6404, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_CHUCKYA, -10340, 473, 8094, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_STAR, -10564, 788, 11231, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -9926, -4099, -552, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -13555, -7072, -14998, 0, 0, 0, 0x00000000, bhvStar),
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
		OBJECT(MODEL_BLACK_BOBOMB, -10034, -4133, -6811, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -9462, -4133, -5165, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -9977, -3633, -10217, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -9492, -3133, -11655, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_SPEEDER, -9707, -3133, -11309, 0, 0, 0, 0x00000000, bhvSpeeder),
		OBJECT(MODEL_NONE, -9676, -2333, -16506, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -10597, -2765, -15776, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -8890, -2765, -15776, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_STAR, -15279, -1111, 10685, 0, 0, 0, 0x00000000, bhvStar),
		TERRAIN(fr_area_11_collision),
		MACRO_OBJECTS(fr_area_11_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(12, fr_area_12, 3500, -22749, 9000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x20, LEVEL_CG, 0x01, 0x21, WARP_NO_CHECKPOINT),
		WARP_NODE(0x21, LEVEL_CG, 0x01, 0x20, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -9677, -7599, 16384, 0, 0, 0, 0x00000000, bhvFRDrop),
		TERRAIN(fr_area_12_collision),
		MACRO_OBJECTS(fr_area_12_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(13, fr_area_13, 3500, -25885, 9000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x20, LEVEL_CG, 0x01, 0x21, WARP_NO_CHECKPOINT),
		WARP_NODE(0x21, LEVEL_CG, 0x01, 0x20, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -9441, -6102, -13456, 0, 0, 0, 0x00000000, bhvFRDrop),
		OBJECT(MODEL_GOAL, -9667, -5685, -13569, 0, 0, 0, 0x00000000, bhvGoal),
		TERRAIN(fr_area_13_collision),
		MACRO_OBJECTS(fr_area_13_macro_objs),
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
		OBJECT(MODEL_NONE, 7937, 13510, -16364, 0, -180, 0, (0 << 16), bhvCoinFormation),
		OBJECT(MODEL_STAR, 7961, 13911, -17491, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 9933, 10730, -10506, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 15356, -9082, -657, 0, 0, 0, 0x00000000, bhvStar),
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
		OBJECT(MODEL_RED_COIN, 7446, 13291, -10987, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 5376, 11616, -10153, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 1962, 5191, -4963, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3167, -87, -939, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 7128, -2809, 2525, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 9108, -3363, 3061, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 16517, -11452, -494, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 17906, -13002, -458, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_STAR, 18715, -13132, 358, 0, 0, 0, 0x00000000, bhvHiddenRedCoinStar),
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
		OBJECT(MODEL_CHECKPOINT, -10637, 16367, 4195, 0, -90, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHUCKYA, -340, 8617, 11954, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_NONE, 3265, 8935, 12144, 0, -90, 0, (0 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -11763, 16367, 4206, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_STAR, 3300, 6753, 16331, 0, 0, 0, 0x00000000, bhvStar),
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
		OBJECT(MODEL_CHUCKYA, -7933, -13922, 619, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, -8464, -12873, 4809, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_NONE, -6023, -15371, -3516, 0, -180, 0, (0 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -8006, -14693, -3511, 0, 90, 0, (0 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -4991, -15894, -1505, 0, 90, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_RED_COIN, 2870, 15029, -17889, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3210, 14883, -17329, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 2870, 14216, -14770, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3380, 14563, -16099, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3210, 14364, -15336, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 2870, 13652, -12603, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3380, 13220, -11378, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3380, 13934, -13686, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_STAR, 3143, 13039, -9675, 0, 0, 0, 0x00000000, bhvHiddenRedCoinStar),
		OBJECT(MODEL_STAR, -8010, -13435, -12512, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -5019, -15297, -1517, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -7692, -12378, 8962, 0, 0, 0, 0x00000000, bhvStar),
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
		WARP_NODE(0x20, LEVEL_FR, 7, 0x20, WARP_NO_CHECKPOINT),
		WARP_NODE(0x21, LEVEL_CG, 0x01, 0x20, WARP_NO_CHECKPOINT),
		WARP_NODE(0x30, LEVEL_FR, 6, 0x31, WARP_NO_CHECKPOINT),
		WARP_NODE(0x31, LEVEL_FR, 6, 0x30, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BLACK_BOBOMB, -16585, 181, 10536, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -17726, 181, 11840, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -15611, 1181, 12852, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_SPEEDER, -7997, -6218, -6418, 0, -180, 0, 0x00000000, bhvSpeeder),
		OBJECT(MODEL_SPEEDER, -8651, -8818, 288, 0, -180, 0, 0x00000000, bhvSpeeder),
		OBJECT(MODEL_SPEEDER, -8009, -3758, -12733, 0, -180, 0, 0x00000000, bhvSpeeder),
		OBJECT(MODEL_CHECKPOINT, -8007, -2758, -6848, 0, 0, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHUCKYA, -9402, -7319, 9187, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, -10920, -2819, 7588, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_NONE, -8662, -8796, 6691, 0, -180, 0, (0 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -8701, -7224, 9159, 0, -90, 0, (0 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -8007, -2704, -7610, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_THI_WARP_PIPE, -15382, 1181, 12320, 0, 0, 0, (0x20 << 16), bhvWarpPipe),
		OBJECT(MODEL_STAR, -8003, -2908, -9403, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -8003, -2908, -8982, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -7335, -4501, -6432, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -8668, -7843, -145, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -8647, -5976, 6204, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -8652, -8560, 280, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -8675, -7814, 8630, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, -7335, -5614, -6432, 0, 0, 0, (0x30 << 16), bhvWarp),
		OBJECT(MODEL_NONE, -8003, -3225, -7585, 0, 0, 0, (0x31 << 16), bhvWarpPipe),
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
		WARP_NODE(0x20, LEVEL_FR, 6, 0x20, WARP_NO_CHECKPOINT),
		WARP_NODE(0x21, LEVEL_CG, 0x01, 0x20, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CHECKPOINT, -17224, -11865, 17982, 0, -179, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHUCKYA, -14650, 11106, -11279, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_NONE, -18689, 6121, -23755, 0, -180, 0, (0 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -20197, 6121, -23755, 0, -180, 0, (0 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -17229, -11764, 16743, 0, -90, 0, (0 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -15384, -1535, -27620, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_THI_WARP_PIPE, -16014, 11087, -12947, 0, 0, 0, (0x20 << 16), bhvWarpPipe),
		OBJECT(MODEL_STAR, -17236, -4217, 7555, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -17227, -11676, 15757, 0, 0, 0, 0x00000000, bhvStar),
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
		OBJECT(MODEL_NONE, -17214, -754, -17679, 0, -180, 0, (0 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -15227, -4766, -10778, 0, -180, 0, (0 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -15175, -5163, -4864, 0, -180, 0, (0 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -19323, -5113, -2662, 0, -180, 0, (0 << 16), bhvCoinFormation),
		OBJECT(MODEL_STAR, -19289, -3891, -10481, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -17209, -10399, 3822, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -15202, -11238, 3524, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -19120, -11678, 4246, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -19169, -8029, 6865, 0, 0, 0, 0x00000000, bhvStar),
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
		OBJECT(MODEL_CHECKPOINT, 1054, -1761, 6849, 0, -89, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHUCKYA, 2831, -1761, 7085, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_NONE, 7536, 664, 10842, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 3713, -1704, 6847, 0, -90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 4998, 820, 2734, 0, -90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -10194, -9086, -12291, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -8696, -8371, -12166, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -5769, -6900, -14261, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -10604, -22726, -29463, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -10604, -22726, -32530, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 8359, 2512, 6852, 0, 90, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_ROCKET_SPAWNER, 6100, 779, 2700, 0, 11, 0, (1 << 16), bhvRocketSpawner),
		OBJECT(MODEL_STAR, 16081, 11184, 5795, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 8366, 2669, 6858, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 7523, 823, 11780, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -7836, -8851, -843, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -10182, -10543, -11734, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -4526, -6567, -14251, 0, 0, 0, 0x00000000, bhvStar),
		TERRAIN(fr_area_9_collision),
		MACRO_OBJECTS(fr_area_9_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, -24021, 12129, -9975),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};