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
#include "levels/cck/header.h"

/* Fast64 begin persistent block [scripts] */
#include "levels/cck/area_1/collision.inc.c"
#include "level_config.h"
static struct LevelConfig cfg = { };
#define SEQ_LEVEL_GRASS 0x44
#define MODEL_CCK_SWITCH_P1 MODEL_CCK_SWITCH
#define bhvFish bhvFishSpawner
#define bhvCoinFormation bhvCoinFormationCC
#define bhvClamShell bhvClamShellCC
#define bhvSkeeter bhvSkeeterCC
#define bhvSnufit bhvSnufitCC
/* Fast64 end persistent block [scripts] */

const LevelScript level_cck_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _cck_segment_7SegmentRomStart, _cck_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x05, _group4_yay0SegmentRomStart, _group4_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group4_geoSegmentRomStart, _group4_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_5), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_CCK_TIMESTOP, cck_switch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCK_BLOCK, cck_block_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCK_SWITCH, cck_switch_p1_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCK_SWITCH2, cck_switch_p2_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCK_DOOR_L, ccr_doorl_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCK_DOOR_R, ccr_doorr_geo), 
	/* Fast64 begin persistent block [level commands] */
	LVL_CONFIG(&cfg),
	/* Fast64 end persistent block [level commands] */

	AREA(1, cck_area_1, 0, 0, 0),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, 0, 6700, 0),
		OBJECT(MODEL_BUB, 796, 3595, -798, 0, 135, 0, 0x00000000, bhvBub),
		OBJECT(MODEL_BUB, 851, 2319, 1189, 0, 135, 0, 0x00000000, bhvBub),
		OBJECT(MODEL_BUB, 74, 1110, -1345, 0, 135, 0, 0x00000000, bhvBub),
		OBJECT(MODEL_BUB, 184, -279, -5473, 0, 135, 0, 0x00000000, bhvBub),
		OBJECT(MODEL_BUB, -210, 3916, 1290, 0, 135, 0, 0x00000000, bhvBub),
		OBJECT(MODEL_FISH, -19, 3768, -7931, 0, 135, 0, 0x00000000, bhvFish),
		OBJECT(MODEL_FISH, 4516, -627, -17368, 0, 135, 0, 0x00000000, bhvFish),
		OBJECT(MODEL_CLAM_SHELL, -1426, 0, -1510, 0, -135, 0, 0x00000000, bhvClamShell),
		OBJECT(MODEL_CLAM_SHELL, 1519, 0, -1426, 0, 135, 0, 0x00000000, bhvClamShell),
		OBJECT(MODEL_CLAM_SHELL, 1437, 0, 1506, 0, 45, 0, 0x00000000, bhvClamShell),
		OBJECT(MODEL_CLAM_SHELL, -1525, 0, 1412, 0, -45, 0, 0x00000000, bhvClamShell),
		OBJECT(MODEL_NONE, -29, 2850, -2022, 0, -180, 0, (20 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -12, 302, -2080, 0, 0, 0, (4 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 0, 6300, 2302, 0, 0, 0, (20 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -17, -1000, -7986, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -2070, 550, -40, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 2082, 0, 47, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -14, 3450, -8292, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -5, 6600, -1894, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 1, 6300, 1602, 0, 90, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 3080, -1050, -17345, 0, -90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -2, -1700, -5492, 0, 90, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 4, 300, -7, 0, 90, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -7, 2850, -4595, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -798, 4647, 801, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 611, 3087, -6941, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -623, 3087, -6933, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 0, 6600, -2450, 0, 0, 0, 0x00000000, bhvCCKDoor),
		OBJECT(MODEL_FISH, 0, 1380, -36, 0, 0, 0, 0x00000000, bhvFish),
		OBJECT(MODEL_FISH, -17, -251, -8435, 0, 135, 0, 0x00000000, bhvFish),
		OBJECT(MODEL_FISH, 0, 3576, -36, 0, 0, 0, 0x00000000, bhvFish),
		OBJECT(MODEL_NONE, 2, 6300, 3010, 0, 0, 0, 0x00000000, bhvCCKGate),
		OBJECT(MODEL_NONE, -2, 2850, -2527, 0, -180, 0, (1 << 16), bhvCCKGate),
		OBJECT(MODEL_SKEETER, 1, 6300, 3366, 0, -180, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SKEETER, -709, 6300, -1646, 0, -180, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SKEETER, 748, 6300, -1650, 0, -180, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SNUFIT, -794, -262, -9146, 0, -180, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, 750, -262, -9146, 0, -180, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, -839, 3739, -8451, 0, -180, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, 756, 3739, -8451, 0, -180, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, 3001, -786, -16574, 0, -180, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, 3001, -786, -18249, 0, -180, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_NONE, 0, 3550, -11000, 0, -180, 0, 0x00000000, bhvCCKCurrent),
		OBJECT(MODEL_NONE, 0, -950, -16000, 0, -180, 0, (1 << 16), bhvCCKCurrent),
		OBJECT(MODEL_NONE, 1350, -950, -17350, 0, -180, 0, (2 << 16), bhvCCKCurrent),
		OBJECT(MODEL_STAR, -5, 8269, -848, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -3, 6122, 4003, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 8, 6368, -1239, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 805, 1415, 798, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -8, 391, 13, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -14, -660, 2091, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -1, -245, -9735, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -44, 4355, -6773, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 8, 7284, 2825, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 5, 4228, -14086, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -38, -1287, -13488, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 2566, -1581, -17976, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_PURPLE_SWITCH, -5, 7900, -848, 0, 0, 0, 0x00000000, bhvFloorSwitchGrills),
		OBJECT(MODEL_CCK_SWITCH_P1, 4402, -1750, -17359, 0, 0, 0, 0x00000000, bhvCCKSwitch),
		OBJECT(MODEL_CC_TIMESTOP, -798, 4483, 801, 0, 0, 0, 0x00000000, bhvCCTimestop),
		OBJECT(MODEL_CC_TIMESTOP, 1, 3450, -7778, 0, 0, 0, 0x00000000, bhvCCTimestop),
		OBJECT(MODEL_CC_TIMESTOP, -38, -1450, -13963, 0, 0, 0, 0x00000000, bhvCCTimestop),
		TERRAIN(cck_area_1_collision),
		MACRO_OBJECTS(cck_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 6700, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};