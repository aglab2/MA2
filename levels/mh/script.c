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
#include "levels/mh/header.h"

/* Fast64 begin persistent block [scripts] */
extern const GeoLayout mh_area_visual[];
#define mh_area_1 mh_area_visual
#define mh_area_2 mh_area_visual
#define mh_area_3 mh_area_visual
#define mh_area_4 mh_area_visual
#define mh_area_5 mh_area_visual
#define mh_area_6 mh_area_visual
#define mh_area_7 mh_area_visual
#define mh_area_8 mh_area_visual
#define mh_area_9 mh_area_visual
#define mh_area_10 mh_area_visual
#include "levels/mh/area_1/collision.inc.c"
#include "levels/mh/area_2/collision.inc.c"
#include "levels/mh/area_3/collision.inc.c"
#include "levels/mh/area_4/collision.inc.c"
#include "level_config.h"
#define SEQ_LEVEL_GRASS 0x2d

extern const RailDesc* rail_descs_mh[];
extern const SpringDesc* spring_descs_mh[];
extern const SpringLinkDesc spring_links_mh[];
extern IWDHeader* iw_descs_mh[];
static struct LevelConfig cfg = {
	.railDesc = rail_descs_mh,
	.skybox = mh_skybox_mh_skybox_mesh,
	.springDescs = spring_descs_mh,
	.springLinks = spring_links_mh,
	.iwds = iw_descs_mh,
};
/* Fast64 end persistent block [scripts] */

const LevelScript level_mh_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _mh_segment_7SegmentRomStart, _mh_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_14), 
	/* Fast64 begin persistent block [level commands] */
	LVL_CONFIG(&cfg),
	/* Fast64 end persistent block [level commands] */

	AREA(1, mh_area_1, 2000, 0, -900),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, -180, -19988, 1658, 8042),
		OBJECT(MODEL_BLACK_BOBOMB, -5017, -2995, -12720, 0, -180, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -3496, -2995, -12297, 0, -180, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 89, -2495, -13329, 0, -180, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 3275, -2095, -13748, 0, -180, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 1287, -2095, -13319, 0, -180, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -18408, -1490, -8112, 0, -180, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -1194, -2490, -13517, 0, -180, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_CHECKPOINT, -8451, -1490, -12508, 0, 90, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_NONE, -20001, 63, 5640, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -20009, -1076, -3837, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -18503, -1378, -7748, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -15194, -2628, -12528, 0, -90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -6899, -1546, -12527, 0, -90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -18455, -1052, -8824, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -8754, -723, -12535, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -3712, -2187, -12524, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -598, -2044, -13542, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 1671, -2020, -13524, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 1260, -2605, -19806, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -19988, 1658, 8042, 0, -180, 0, (0xa << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_RED_COIN, -18625, -1337, -6477, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -18308, -1450, -7248, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -18662, -1450, -8322, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -18242, -1450, -9463, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -18738, -1384, -10577, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -18559, -1499, -11655, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -17144, -1957, -12805, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -16010, -2520, -12860, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_SNUFIT, 1602, -2064, -14994, 0, -180, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, 1602, -2251, -16278, 0, -180, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, 1602, -2428, -17640, 0, -180, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_NONE, -20018, -211, 3290, 0, -180, 0, 0x00000000, bhvSpringCtl),
		OBJECT(MODEL_STAR, -20001, 800, 4033, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -19021, -871, -6740, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -18481, -1161, -8832, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -7937, -892, -12543, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -3105, -1963, -12575, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 111, -1303, -13482, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 1648, -1888, -16292, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, -15199, -2531, -12525, 0, -180, 0, 0x00000000, bhvHiddenRedCoinStar),
		TERRAIN(mh_area_1_collision),
		MACRO_OBJECTS(mh_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, mh_area_2, 2000, 0, -4900),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BLACK_BOBOMB, -1269, -1700, -2590, 0, -180, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 3430, -1600, 96, 0, -180, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 3202, -1700, -6295, 0, -180, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -587, -1700, -8763, 0, -180, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -1406, -870, -7835, 0, -180, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_SPEEDER, 641, -1600, 3615, 0, 0, 0, 0x00000000, bhvSpeeder),
		OBJECT(MODEL_SPEEDER, 641, -1600, 763, 0, 0, 0, 0x00000000, bhvSpeeder),
		OBJECT(MODEL_SPEEDER, 639, -1600, -3652, 0, 0, 0, 0x00000000, bhvSpeeder),
		OBJECT(MODEL_SPEEDER, 672, -1598, -7927, 0, 0, 0, 0x00000000, bhvSpeeder),
		OBJECT(MODEL_SPEEDER, 2447, -1600, -2815, 0, -163, 0, 0x00000000, bhvSpeeder),
		OBJECT(MODEL_SPEEDER, 641, -1600, 4807, 0, -180, 0, 0x00000000, bhvSpeeder),
		OBJECT(MODEL_SPEEDER, 641, -1600, 8690, 0, 0, 0, 0x00000000, bhvSpeeder),
		OBJECT(MODEL_SPEEDER, 3323, -1598, 1111, 0, 17, 0, 0x00000000, bhvSpeeder),
		OBJECT(MODEL_RED_COIN, 641, -1542, 3615, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 639, -1542, -3652, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 672, -1540, -7927, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 2447, -1542, -2815, 0, 17, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 641, -1542, 763, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 641, -1542, 4807, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 641, -1542, 8690, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3323, -1540, 1111, 0, -163, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BREAKABLE_BOX, 2021, -1113, 2333, 0, -180, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_CHECKPOINT, 658, -1600, 4341, 0, -180, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHECKPOINT, 667, -2640, -17242, 0, -180, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_NONE, 665, -2628, -18729, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 656, -1465, 6882, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 2865, -1211, -702, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 605, -2200, 15590, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 735, -1600, -964, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 735, -1600, 2301, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -985, -1600, -175, 0, -90, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -985, -1600, -1634, 0, -90, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 1544, -1600, -6140, 0, -90, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 258, -1916, 14798, 0, -180, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 258, -442, 14798, 0, -180, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 260, -23, 15660, 0, -180, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_SKEETER, 1430, -1600, -8646, 0, -180, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SKEETER, -1387, -440, -6827, 0, -180, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SKEETER, 256, -1600, 8280, 0, -180, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SKEETER, 2448, -1600, -1287, 0, -180, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SKEETER, -1010, -1600, -1632, 0, -180, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SKEETER, 1561, -1600, -5580, 0, -180, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_NONE, 1015, -2200, 14445, 0, -180, 0, 0x00000000, bhvSpringCtl),
		OBJECT(MODEL_STAR, 258, 605, 14798, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -1472, -710, 1362, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 2133, -579, 3161, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 3516, -798, -8944, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -1408, -741, -6986, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -2925, -1373, -15054, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 647, -2436, -10859, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -886, -1541, -3158, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, 1769, -1346, -5873, 0, -180, 0, 0x00000000, bhvHiddenRedCoinStar),
		TERRAIN(mh_area_2_collision),
		MACRO_OBJECTS(mh_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(3, mh_area_3, 2000, 0, -8900),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BLACK_BOBOMB, 15847, 1525, 17412, 0, -180, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 17399, -2235, 4309, 0, -180, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 17041, -2235, 2648, 0, -180, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 3038, -2090, 18217, 0, -180, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 3663, -2090, 17649, 0, -180, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 12495, -2250, 18108, 0, -180, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_CHECKPOINT, 15669, 1530, 16162, 0, -180, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_NONE, 2818, -2088, 17924, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 15657, 1532, 16899, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 15659, 1226, 15194, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 15758, -91, 13684, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 17219, -1167, 6215, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 15654, 2214, 18072, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 13160, -1942, 18101, 0, -180, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 13311, -531, 18101, 0, -180, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 15647, 22, 18220, 0, -180, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 15647, 1359, 18072, 0, -180, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 17221, -1957, 3319, 0, -180, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 17221, -480, 3319, 0, -180, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_SKEETER, 17368, -735, 7668, 0, -180, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SKEETER, 17039, -1495, -2092, 0, -180, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_NONE, 4260, -200, 18547, 0, -180, 0, 0x00000000, bhvSpringCtl),
		OBJECT(MODEL_STAR, 3941, -387, 18595, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 6822, -1051, 17797, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 13311, 1372, 18001, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 15875, -511, 8857, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 17219, -526, 3766, 0, -180, 0, 0x00000000, bhvStar),
		TERRAIN(mh_area_3_collision),
		MACRO_OBJECTS(mh_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(4, mh_area_4, 6000, 916, -8900),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_MH, 4, 12, WARP_NO_CHECKPOINT),
		WARP_NODE(12, LEVEL_MH, 4, 11, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BLACK_BOBOMB, -12553, -10967, -14613, 0, -180, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -9361, -9467, -11545, 0, -180, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -12226, -8538, -11183, 0, -180, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -12367, -10967, -9901, 0, -180, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -9428, -7967, -14593, 0, -180, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -12611, -10968, -11697, 0, -180, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -9344, -10968, -11709, 0, -180, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -9361, -10968, -14487, 0, -180, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -12359, -9468, -14486, 0, -180, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_CHECKPOINT, -12919, -11848, -3390, 0, 90, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_NONE, -12424, -10869, -13178, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -9318, -10869, -13178, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -10994, -9668, -11577, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -12446, -8547, -13178, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -10883, -7843, -14317, 0, -180, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_GOAL, 27994, -10691, -13695, 0, -180, 0, (1 << 16), bhvGoal),
		OBJECT(MODEL_NONE, -6466, 10049, -13145, 0, 90, 0, 0x00000000, bhvMHMusic),
		OBJECT(MODEL_THI_WARP_PIPE, -10864, -9467, -14691, 0, -180, 0, (11 << 16), bhvWarpPipe),
		OBJECT(MODEL_NONE, -6466, 10049, -13145, 0, 90, 0, (12 << 16), bhvWarp),
		OBJECT(MODEL_RED_COIN, -2024, 5878, -13235, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -261, 4060, -13955, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 1253, 2611, -14419, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 6561, -2716, -14607, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 9483, -5692, -14651, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 12016, -8163, -15214, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3670, 146, -14970, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 14457, -10604, -15172, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_SKEETER, 28085, -10858, -13673, 0, -180, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_NONE, -16505, -11895, -4911, 0, -180, 0, 0x00000000, bhvSpringCtl),
		OBJECT(MODEL_STAR, -9917, -11333, -13900, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -10811, -9670, -14713, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -9343, -6767, -13144, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -9319, -9155, -11588, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -12744, -6469, -11352, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, 18029, -11329, -15144, 0, -180, 0, 0x00000000, bhvHiddenRedCoinStar),
		TERRAIN(mh_area_4_collision),
		MACRO_OBJECTS(mh_area_4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(4, -180, -11171, -9468, -14733),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};