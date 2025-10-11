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
#include "levels/chao/header.h"

/* Fast64 begin persistent block [scripts] */
#include "level_config.h"
#include "levels/chao/area_1/collision.inc.c"
extern Gfx chao_skybox_skybox_mesh[];
static struct LevelConfig cfg = {
	.skybox = chao_skybox_skybox_mesh,
};
#define SEQ_LEVEL_GRASS 0x4E
#define bhvBobombBuddy bhvBobomb
/* Fast64 end persistent block [scripts] */

const LevelScript level_chao_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _chao_segment_7SegmentRomStart, _chao_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x05, _group6_yay0SegmentRomStart, _group6_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group6_geoSegmentRomStart, _group6_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_7), 
	JUMP_LINK(script_func_global_14), 
	/* Fast64 begin persistent block [level commands] */
	LVL_CONFIG(&cfg),
	/* Fast64 end persistent block [level commands] */

	AREA(1, chao_area_1, 0, 0, 0),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BLACK_BOBOMB, -2047, -800, -11404, 0, -91, 0, 0x00000000, bhvBobombBuddy),
		OBJECT(MODEL_BLACK_BOBOMB, 5690, -800, -13104, 0, -91, 0, 0x00000000, bhvBobombBuddy),
		OBJECT(MODEL_BLACK_BOBOMB, 8995, -700, -12649, 0, -91, 0, 0x00000000, bhvBobombBuddy),
		OBJECT(MODEL_BLACK_BOBOMB, 9604, -700, -12626, 0, -91, 0, 0x00000000, bhvBobombBuddy),
		OBJECT(MODEL_BUB, 7051, -698, 2041, 0, 89, 0, 0x00000000, bhvBub),
		OBJECT(MODEL_CHECKPOINT, 9296, 700, 7426, 0, -180, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHECKPOINT, 9296, -700, -13433, 0, 0, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHECKPOINT, 13709, 500, -3399, 0, -91, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHECKPOINT, 5401, -520, 7393, 0, 179, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHUCKYA, 9301, 500, -3485, 0, -91, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, 11903, 500, -3461, 0, -91, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, 5343, -374, -211, 0, -91, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, 3720, 397, -3393, 0, -91, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, 9272, 682, -1136, 0, -91, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, 5656, -520, 6378, 0, -91, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, 4998, -520, 6442, 0, -91, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_NONE, 5, 0, 1715, 0, -91, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 5398, 740, 4211, 0, -91, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 5716, -400, -2375, 0, -91, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 4240, -207, -646, 0, -91, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 2923, 261, -3007, 0, -91, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 6366, 600, -3410, 0, -91, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 9281, 500, -3469, 0, -91, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 12057, 500, -3382, 0, -91, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 9283, 826, 1687, 0, -91, 0, (18 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 13138, 1900, 5141, 0, -91, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -1587, -800, -11325, 0, -91, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 5832, -909, -7090, 0, -91, 0, (18 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 9304, -700, -11638, 0, -91, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 1694, 112, -5957, 0, -112, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 539, -113, -6917, 0, -163, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 1525, -437, -8371, 0, 108, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 2395, -695, -9966, 0, -3, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 9282, 875, 152, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 9293, 612, -1777, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 5402, -240, 644, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 5385, -520, 3398, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 6376, 723, -3950, 0, -91, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 6376, 723, -2857, 0, -91, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 5829, 723, -3403, 0, -1, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 6922, 723, -3403, 0, -1, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 10106, 1015, 1838, 0, -91, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 11505, 2176, 1820, 0, -91, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 12208, 2829, 2181, 0, -91, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_GOOMBA, 5678, -400, -4215, 0, -91, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_NONE, 5455, 740, 4154, 0, -91, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 9360, 740, 4262, 0, -91, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 13218, 1900, 5742, 0, -91, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 2481, -800, -11201, 0, -91, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -1, 386, 487, 0, 0, 0, (0xa << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_MONTY_MOLE, 9330, 740, 4273, 0, -91, 0, 0x00000000, bhvMontyMole),
		OBJECT(MODEL_MONTY_MOLE, 2477, -800, -11219, 0, -91, 0, 0x00000000, bhvMontyMole),
		// OBJECT(MODEL_MONTY_MOLE, 5634, -800, -11352, 0, -91, 0, 0x00000000, bhvMontyMole),
		OBJECT(MODEL_DL_MONTY_MOLE_HOLE, 9294, 763, 3369, 0, -91, 0, 0x00000000, bhvMontyMoleHole),
		OBJECT(MODEL_DL_MONTY_MOLE_HOLE, 9321, 740, 4253, 0, -91, 0, 0x00000000, bhvMontyMoleHole),
		OBJECT(MODEL_DL_MONTY_MOLE_HOLE, 9975, 738, 4232, 0, -91, 0, 0x00000000, bhvMontyMoleHole),
		OBJECT(MODEL_DL_MONTY_MOLE_HOLE, 8536, 740, 4197, 0, -91, 0, 0x00000000, bhvMontyMoleHole),
		OBJECT(MODEL_DL_MONTY_MOLE_HOLE, 9278, 736, 5011, 0, -91, 0, 0x00000000, bhvMontyMoleHole),
		OBJECT(MODEL_DL_MONTY_MOLE_HOLE, 9276, 723, 5843, 0, -91, 0, 0x00000000, bhvMontyMoleHole),
		OBJECT(MODEL_DL_MONTY_MOLE_HOLE, 1077, -800, -11363, 0, -91, 0, 0x00000000, bhvMontyMoleHole),
		OBJECT(MODEL_DL_MONTY_MOLE_HOLE, 2340, -800, -11212, 0, -91, 0, 0x00000000, bhvMontyMoleHole),
		OBJECT(MODEL_DL_MONTY_MOLE_HOLE, 2396, -800, -10200, 0, -91, 0, 0x00000000, bhvMontyMoleHole),
		OBJECT(MODEL_DL_MONTY_MOLE_HOLE, 3551, -800, -11385, 0, -91, 0, 0x00000000, bhvMontyMoleHole),
		OBJECT(MODEL_DL_MONTY_MOLE_HOLE, 4711, -800, -11405, 0, -91, 0, 0x00000000, bhvMontyMoleHole),
		OBJECT(MODEL_DL_MONTY_MOLE_HOLE, 5565, -800, -11451, 0, -91, 0, 0x00000000, bhvMontyMoleHole),
		OBJECT(MODEL_DL_MONTY_MOLE_HOLE, 5694, -800, -12455, 0, -91, 0, 0x00000000, bhvMontyMoleHole),
		OBJECT(MODEL_DL_MONTY_MOLE_HOLE, 5716, -800, -13537, 0, -91, 0, 0x00000000, bhvMontyMoleHole),
		OBJECT(MODEL_RED_COIN, 4600, -418, -1294, 0, -91, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3808, -214, -1342, 0, -91, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3972, -132, -1789, 0, -91, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 4494, -56, -2056, 0, -91, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 4826, 40, -1865, 0, -91, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3383, 62, -2124, 0, -91, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 4276, 224, -2439, 0, -91, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 4177, 374, -2805, 0, -91, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_SKEETER, 5837, -940, -8724, 0, -91, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SKEETER, 5835, -940, -5554, 0, 89, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SKEETER, 5842, -940, -7082, 0, -91, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SKEETER, 6764, -600, 2210, 0, 89, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SKEETER, 2504, -600, 4152, 0, 89, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SNUFIT, 9234, 74, -6403, 0, -91, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, 9432, 355, -5941, 0, -91, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, 9420, -54, -6812, 0, -91, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, 9158, -125, -7570, 0, -91, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, 9458, -210, -8213, 0, -91, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, 9136, -538, -9084, 0, -91, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, 9544, -505, -10048, 0, -91, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_STAR, -3597, -195, -11393, 0, -91, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 750, 173, -5750, 0, -91, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, 4911, 1053, -2552, 0, -91, 0, 0x00000000, bhvHiddenRedCoinStar),
		OBJECT(MODEL_STAR, 9359, 1350, -3388, 0, -91, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 6366, 1055, -3410, 0, -91, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 13208, 3996, 2037, 0, -91, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 13234, 2108, 6962, 0, -91, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 3656, 882, 4180, 0, -91, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 8209, -372, 1782, 0, -91, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 5400, 1191, 2402, 0, -91, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 5723, -833, -4510, 0, -91, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 5699, -582, -14398, 0, -91, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 10858, 988, 4184, 0, -91, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_WOODEN_SIGNPOST, 12249, 1900, 6012, 0, 89, 0, (42 << 24) | (42 << 16), bhvMessagePanel),
		TERRAIN(chao_area_1_collision),
		MACRO_OBJECTS(chao_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};