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


/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/ce/header.h"

/* Fast64 begin persistent block [scripts] */
extern const GeoLayout ce_area_visual[];
#define ce_area_1 ce_area_visual
#define ce_area_2 ce_area_visual
#define ce_area_3 ce_area_visual
#define ce_area_4 ce_area_visual
#define ce_area_5 ce_area_visual
#define ce_area_6 ce_area_visual
#define ce_area_7 ce_area_visual
#define ce_area_8 ce_area_visual
#define ce_area_9 ce_area_visual
#define ce_area_10 ce_area_visual
/* Fast64 end persistent block [scripts] */

const LevelScript level_ce_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _ce_segment_7SegmentRomStart, _ce_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ce_area_visual, 0, -1236, 1000),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CHECKPOINT, -11, -7639, 22045, 0, 0, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_NONE, 328, 5143, 1652, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -354, 3336, 4317, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 317, 996, 7768, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -388, -1359, 11242, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 60, 10475, -5520, 0, 0, 0, (0xa << 16), bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 53, 10480, -5519),
		TERRAIN(ce_area_1_collision),
		MACRO_OBJECTS(ce_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(10, ce_area_10, 4000, -21902, 17000),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_GOAL, -497, -2076, -9534, 0, 0, 0, (8 << 24), bhvGoal),
		TERRAIN(ce_area_10_collision),
		MACRO_OBJECTS(ce_area_10_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, ce_area_2, 0, -3498, 5000),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CHECKPOINT, -11, 14982, -17955, 0, 0, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHECKPOINT, -17605, -10368, 9897, 0, 0, 0, (1 << 24), bhvCheckpoint),
		OBJECT(MODEL_NONE, -17588, -6834, 2900, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -17609, -12037, 13185, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_RED_COIN, -479, 12968, -14580, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 14, 9643, -9176, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 503, 6666, -5287, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -942, 5184, -874, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -3015, 3754, -1692, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -5438, 2876, -1078, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -8184, 1530, -1486, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -12234, -2498, -1359, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, -17512, -4991, -1222, 0, 0, 0, 0x00000000, bhvHiddenRedCoinStar),
		TERRAIN(ce_area_2_collision),
		MACRO_OBJECTS(ce_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, ce_area_3, 0, -6071, 9000),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BREAKABLE_BOX, -15786, 1242, -5533, 0, 0, 0, (1 << 24), bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -12967, -1820, 4428, 0, 0, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -15064, 2255, -6716, 0, 0, 0, (1 << 24), bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -15064, 2255, -6916, 0, 0, 0, (1 << 24), bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -15502, 2816, -7915, 0, 0, 0, (1 << 24), bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -15502, 3016, -7915, 0, 0, 0, (1 << 24), bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -15502, 3016, -8115, 0, 0, 0, (1 << 24), bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -15013, 3585, -9052, 0, 0, 0, (1 << 24), bhvBreakableBox),
		OBJECT(MODEL_CHECKPOINT, -15531, -1890, 3793, 0, 0, 0, (2 << 24), bhvCheckpoint),
		OBJECT(MODEL_NONE, -15527, -1890, 3794, 0, 0, 0, (2 << 24), bhvCoinFormation),
		OBJECT(MODEL_NONE, -9395, -1390, 4256, 0, 0, 0, 0x00000000, bhvCoinFormationSpawn),
		OBJECT(MODEL_NONE, -7096, -2730, 7066, 0, 0, 0, (0 << 24) | (2 << 16), bhvCoinFormationSpawn),
		OBJECT(MODEL_NONE, -7115, -1990, 10498, 0, 0, 0, (0 << 24) | (2 << 16), bhvCoinFormationSpawn),
		OBJECT(MODEL_NONE, -13745, -1890, 3928, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -10922, -1388, 3666, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -15388, 112, -3996, 0, 0, 0, (1 << 24), bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -15385, 4068, -9776, 0, 0, 0, 0x00000000, bhvHiddenStar),
		OBJECT(MODEL_SNUFIT, -7115, -1707, 10498, 0, 0, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, -12659, -1099, 4064, 0, 0, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_STAR, -14905, -864, 2018, 0, 0, 0, (3 << 24), bhvStar),
		OBJECT(MODEL_STAR, -12967, -1820, 4428, 0, 0, 0, (4 << 24), bhvStar),
		OBJECT(MODEL_STAR, -7732, -966, 3848, 0, 0, 0, (5 << 24), bhvStar),
		OBJECT(MODEL_STAR, -6516, -1612, 7031, 0, 0, 0, (6 << 24), bhvStar),
		OBJECT(MODEL_STAR, -1952, -2224, 10147, 0, 0, 0, (7 << 24), bhvStar),
		OBJECT(MODEL_STAR, 2259, -3938, 10144, 0, 0, 0, (8 << 24), bhvStar),
		OBJECT(MODEL_STAR, 3753, -3652, 10150, 0, 0, 0, (9 << 24), bhvStar),
		OBJECT(MODEL_NONE, 3536, -3990, 7168, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_SNUFIT, 3536, -3729, 7168, 0, 0, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_STAR, 3753, -3538, 8360, 0, 0, 0, (10 << 24), bhvStar),
		TERRAIN(ce_area_3_collision),
		MACRO_OBJECTS(ce_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(4, ce_area_4, 0, -7740, 5000),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CHECKPOINT, 3221, 12702, 40755, 0, 0, 0, (3 << 24), bhvCheckpoint),
		TERRAIN(ce_area_4_collision),
		MACRO_OBJECTS(ce_area_4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(5, ce_area_5, 4000, -9601, 5000),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BREAKABLE_BOX, 17248, -11307, -6391, 0, 0, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, 17248, -11307, -5000, 0, 0, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_CHECKPOINT, -8551, 10960, 13757, 0, 0, 0, (4 << 24), bhvCheckpoint),
		OBJECT(MODEL_STAR, -11634, 10859, 13289, 0, 0, 0, (11 << 24), bhvStar),
		OBJECT(MODEL_STAR, -16414, 8770, 13746, 0, 0, 0, (12 << 24), bhvStar),
		OBJECT(MODEL_STAR, 8077, -3614, 2585, 0, 0, 0, (13 << 24), bhvStar),
		OBJECT(MODEL_STAR, 19735, -10525, -6064, 0, 0, 0, (14 << 24), bhvStar),
		OBJECT(MODEL_STAR, 17248, -11307, -6391, 0, 0, 0, (15 << 24), bhvStar),
		OBJECT(MODEL_STAR, 19211, -11468, -2343, 0, 0, 0, (16 << 24), bhvStar),
		TERRAIN(ce_area_5_collision),
		MACRO_OBJECTS(ce_area_5_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(6, ce_area_6, 8000, -12556, 5000),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BREAKABLE_BOX, -3409, -19151, 10612, 0, 0, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_CHECKPOINT, -14517, 15168, -364, 0, 0, 0, (5 << 24), bhvCheckpoint),
		OBJECT(MODEL_CHECKPOINT, -3416, -18990, 11427, 0, 0, 0, (6 << 24), bhvCheckpoint),
		OBJECT(MODEL_NONE, -16192, 16301, -377, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -3404, -19990, 6742, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -3435, -17715, 12841, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -8769, -18990, 12193, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -12837, 14829, 743, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -9711, 13311, -2198, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -12376, 14610, 1776, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -12910, 14877, -2698, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -9771, 12837, -2565, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -10377, 13359, 2252, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -5790, 11359, 2700, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -3979, 11192, 1249, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -6303, 11903, -3639, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -9156, 12567, 289, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -15203, 15731, 539, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_SNUFIT, -9761, 12911, -1656, 0, 0, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, -11239, 13962, 1195, 0, 0, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, -12741, 15155, -3102, 0, 0, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_NONE, -4885, 11781, -822, 0, 0, 0, (17 << 24), bhvHiddenRedCoinStar),
		OBJECT(MODEL_STAR, -2897, -5565, 5593, 0, 0, 0, (18 << 24), bhvStar),
		OBJECT(MODEL_STAR, -3406, -20207, 11087, 0, 0, 0, (19 << 24), bhvStar),
		OBJECT(MODEL_STAR, -3435, -17563, 12841, 0, 0, 0, (20 << 24), bhvStar),
		TERRAIN(ce_area_6_collision),
		MACRO_OBJECTS(ce_area_6_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(7, ce_area_7, 8000, -15682, 9000),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CHECKPOINT, -15600, -2328, 1334, 0, 0, 0, (7 << 24), bhvCheckpoint),
		OBJECT(MODEL_NONE, -15996, -2330, 534, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -15635, -3330, -1963, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -15635, -3330, -1963, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_SNUFIT, -15996, -1950, 534, 0, 0, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_STAR, -15024, -2506, -2912, 0, 0, 0, (21 << 24), bhvStar),
		TERRAIN(ce_area_7_collision),
		MACRO_OBJECTS(ce_area_7_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(8, ce_area_8, 8000, -17675, 13000),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		TERRAIN(ce_area_8_collision),
		MACRO_OBJECTS(ce_area_8_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(9, ce_area_9, 8000, -20396, 17000),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		TERRAIN(ce_area_9_collision),
		MACRO_OBJECTS(ce_area_9_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 53, 10480, -5519),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
