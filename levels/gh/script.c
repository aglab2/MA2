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
#include "levels/gh/header.h"

/* Fast64 begin persistent block [scripts] */
#include "instant_warp_desc.h"
#include "level_config.h"
extern const GeoLayout gh_area_1[];
extern IWDHeader* iw_descs_gh[];
#define gh_area_1 gh_area_1
#define gh_area_2 gh_area_1
#include "levels/gh/area_1/collision.inc.c"
#include "levels/gh/area_2/collision.inc.c"
extern Gfx gh_skybox_gh_skybox_mesh[];
extern const SpringDesc* spring_descs_gh[];
extern const RailDesc* rail_descs_gh[];
static struct LevelConfig cfg = {
	.iwds = iw_descs_gh,
	.viewRangeMult = 3.f,
	.skybox = gh_skybox_gh_skybox_mesh,
	.springDescs = spring_descs_gh,
	.railDesc = rail_descs_gh,
};
#define SEQ_LEVEL_GRASS 0x4D
/* Fast64 end persistent block [scripts] */

const LevelScript level_gh_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _gh_segment_7SegmentRomStart, _gh_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	LOAD_MODEL_FROM_GEO(MODEL_GH_PLAT, gh_plat_geo),
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_15), 
	/* Fast64 begin persistent block [level commands] */
	LVL_CONFIG(&cfg),
	/* Fast64 end persistent block [level commands] */

	AREA(1, gh_area_1, 0, -174, -900),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, 8, 2145, 8395),
		OBJECT(MODEL_CHUCKYA, -6689, 1045, -17700, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, -7344, 2045, -15835, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_NONE, -7299, 2076, -15261, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -6298, 2144, -11741, 0, -90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -2091, 700, -12392, 0, -91, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -802, 2778, -11394, 0, -90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 690, 2415, -9623, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -6839, 451, -13797, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -7751, 2245, -17000, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -8896, 2445, -17731, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 1892, 2165, -4693, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -17, 2145, 9574, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 32, 2145, 6357, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 9, 2145, 3184, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 423, 2488, -10214, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 17, 2145, 6348, 0, 0, 0, (0xa << 16), bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -2983, 2645, 2838, 0, 0, 0, (0xa << 16), bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -7983, 1045, -18611, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -7649, 2245, -16931, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -6850, 445, -13753, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -4035, 451, -12336, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -4149, 440, -11183, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, 698, 2201, -8206, 0, 0, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -3064, 2572, 773, 0, 0, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -4119, 443, -11800, 0, 0, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_NONE, 8, 2495, 8395, 0, 0, 0, (0xa << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, -3032, 2893, 3455, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -3491, 2893, 3007, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -2923, 2893, -1764, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, 1334, 1693, -1172, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, 761, 1993, -3562, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_STAR, 4, 2506, 10148, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -802, 2855, 4434, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -3406, 3574, 3352, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 908, 1040, -2452, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, 786, 2558, -5109, 0, 0, 0, 0x00000000, bhvHiddenStar),
		OBJECT(MODEL_STAR, -3348, 855, -10999, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -811, 837, -12363, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -6755, 3850, -10991, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -7305, 1036, -13745, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -7179, 488, -18504, 0, 0, 0, 0x00000000, bhvStar),
		TERRAIN(gh_area_1_collision),
		MACRO_OBJECTS(gh_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, gh_area_2, 0, -674, -4900),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BLACK_BOBOMB, -8452, 4245, 2211, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -9896, 4245, 3359, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_CHUCKYA, -17248, -5455, -3051, 0, -180, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, -9671, 4245, 4440, 0, -180, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_NONE, -12129, -3315, -2098, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -15471, -5455, -3043, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -17264, -5455, -2171, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -20133, -5391, -14806, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -19157, -5391, -14806, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -20133, -6200, -16699, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -19157, -6200, -16699, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -20282, -1190, -8784, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -20282, -1999, -10677, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -8537, 6957, -157, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -9697, 4851, 7313, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -8884, 5876, 17363, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -7307, 5745, -122, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -7307, 5745, -1341, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -9757, 7345, -2142, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -7327, 445, -2047, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -15068, -4555, -2109, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -19105, -5555, -6948, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -19105, -5555, -8731, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -19101, -5155, -10669, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -19696, -6659, -19300, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -20301, -1255, -6986, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -20276, -1229, -2787, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -9701, 5445, 9804, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -8880, 5445, 15099, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -9934, 4514, 2210, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -19358, -5182, -3217, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -19565, -5036, -12561, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -21296, -1261, -9393, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -21296, -1261, -10429, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -9325, 8118, 13332, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -9325, 8118, 11878, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_GOAL, -19696, -6659, -20634, 0, -180, 0, 0x00000000, bhvGoal),
		OBJECT(MODEL_NONE, -9757, 7345, -2142, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -7319, 5745, -699, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -9665, 4245, 4000, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -15082, -4555, -2109, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -19128, -5555, -7760, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -19687, -7066, -19266, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -20309, -1255, -6984, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -19138, -1455, -1918, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -9675, 5445, 9499, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -8893, 5445, 15286, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -17746, -5455, -3016, 0, 0, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -20058, -7155, -19944, 0, 0, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -19012, -7155, -20274, 0, 0, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_GH_PLAT, -14107, 1015, -2142, 0, 90, 0, 0x00000000, bhvGhPlat),
		OBJECT(MODEL_GH_PLAT, -15307, 315, -1742, 0, 90, 0, 0x00000000, bhvGhPlat),
		OBJECT(MODEL_GH_PLAT, -16807, -885, -1342, 0, 90, 0, 0x00000000, bhvGhPlat),
		OBJECT(MODEL_STAR, -9346, 8520, 12642, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -10686, 6218, 3302, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -9755, 7345, -2145, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -9247, 6145, 595, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -6728, 1249, -1601, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -15320, 1060, -1766, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -14835, -5192, -3120, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -19390, -4361, -3217, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -19076, -4717, -6166, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -18321, -5515, -10040, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -21272, -994, -9891, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -20281, -922, -2778, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -8909, 4860, 11705, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, -7290, 4247, 1297, 0, 0, 0, 0x00000000, bhvGhWarp),
		OBJECT(MODEL_NONE, -7320, 640, -1300, 0, 0, 0, (1 << 24), bhvGhWarp),
		OBJECT(MODEL_NONE, -8520, 502, -2107, 0, 0, 0, (1 << 16), bhvGhWarp),
		OBJECT(MODEL_NONE, -11106, -3168, -2108, 0, 90, 0, (1 << 24) | (1 << 16), bhvGhWarp),
		OBJECT(MODEL_NONE, -8459, 5787, -2104, 0, 90, 0, (2 << 16), bhvGhWarp),
		OBJECT(MODEL_NONE, -11100, 2148, -2105, 0, 90, 0, (1 << 24) | (2 << 16), bhvGhWarp),
		TERRAIN(gh_area_2_collision),
		MACRO_OBJECTS(gh_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 8, 2145, 8395),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};