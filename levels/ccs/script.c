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
#include "levels/ccs/header.h"

/* Fast64 begin persistent block [scripts] */
#include "levels/ccs/area_1/collision.inc.c"
#include "levels/ccs/area_2/collision.inc.c"
#include "level_config.h"
#include "rail_desc.h"
#define ccs_area_2 ccs_area_1
#define SEQ_LEVEL_GRASS 0x00
#define bhvFloorSwitchGrills bhvFloorSwitchHardcodedModel
// TODO: needs to buffed
#define bhvSmallBully bhvSmallChillBullyCC
#define bhvSnufit bhvSnufitCC
#define bhvGoombaTripletSpawner bhvGoombaTripletSpawnerCC
#define bhvCCSpawnUp bhvCCSpawn
#define bhvCoinFormation bhvCoinFormationCC
#define bhvFlyGuy bhvFlyGuyCC
#define bhvEnemyLakitu bhvEnemyLakituCC
#define SEQ_LEVEL_GRASS 0x46
extern const RailDesc* rail_descs_ccs[];
extern const IWDHeader* iw_descs_ccs[];
static struct LevelConfig cfg = {
	.iwds = iw_descs_ccs,
	.railDesc = rail_descs_ccs,
};
/* Fast64 end persistent block [scripts] */

const LevelScript level_ccs_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _ccs_segment_7SegmentRomStart, _ccs_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x05, _group11_yay0SegmentRomStart, _group11_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group11_geoSegmentRomStart, _group11_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group16_yay0SegmentRomStart, _group16_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group16_geoSegmentRomStart, _group16_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_12), 
	JUMP_LINK(script_func_global_17), 
	LOAD_MODEL_FROM_GEO(MODEL_CCS_TIMESTOP, ccs_switch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCS_BLOCK, ccs_block_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCS_SHUTTER_LEFT, ccs_shutter_left_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCS_SHUTTER_RIGHT, ccs_shutter_right_geo), 
	/* Fast64 begin persistent block [level commands] */
	LVL_CONFIG(&cfg),
	/* Fast64 end persistent block [level commands] */

	AREA(1, ccs_area_1, 0, 0, 2000-3000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -5100, -7850, -4900, 0, 143, 0, 0x00000000, bhvCCSMusicSwitch),
		MARIO_POS(0x01, 0, -3, -4310, 19568),
		OBJECT(MODEL_CHILL_BULLY, -5472, -4800, 9006, 0, 0, 0, (2 << 16), bhvSmallBully),
		OBJECT(MODEL_CHILL_BULLY, -4729, -4800, 8976, 0, 0, 0, (2 << 16), bhvSmallBully),
		OBJECT(MODEL_CHILL_BULLY, -5643, -5270, 5968, 0, 0, 0, (2 << 16), bhvSmallBully),
		OBJECT(MODEL_CHILL_BULLY, -4531, -5270, 5957, 0, 0, 0, (2 << 16), bhvSmallBully),
		OBJECT(MODEL_CHILL_BULLY, -4431, -5270, 7180, 0, 0, 0, (2 << 16), bhvSmallBully),
		OBJECT(MODEL_CHILL_BULLY, -5630, -5270, 7131, 0, 0, 0, (2 << 16), bhvSmallBully),
		OBJECT(MODEL_CHECKPOINT, -5118, -5270, 3833, 0, 180, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_NONE, 175, -4665, 13318, 0, 143, 0, (4 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -5108, -8128, -9347, 0, -180, 0, (4 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -2, -4708, 18955, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -5122, -4700, 3315, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 3, -4800, 14147, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 2435, -4800, 12203, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -2931, -4800, 12203, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -5102, -4800, 8987, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -5095, -5270, 6774, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -4462, -4800, 11615, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -5112, -5270, 4398, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -5120, -6550, -12997, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -5081, -6544, -16875, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_ENEMY_LAKITU, -5603, -4446, 10882, 0, 0, 0, 0x00000000, bhvEnemyLakitu),
		OBJECT(MODEL_ENEMY_LAKITU, -4326, -4521, 11323, 0, 0, 0, 0x00000000, bhvEnemyLakitu),
		OBJECT(MODEL_ENEMY_LAKITU, -3962, -4642, 12438, 0, 0, 0, 0x00000000, bhvEnemyLakitu),
		OBJECT(MODEL_ENEMY_LAKITU, -5795, -6042, -13425, 0, 0, 0, 0x00000000, bhvEnemyLakitu),
		OBJECT(MODEL_ENEMY_LAKITU, -4485, -6042, -13425, 0, 0, 0, 0x00000000, bhvEnemyLakitu),
		OBJECT(MODEL_FLYGUY, 8, -4483, 17967, 0, 0, 0, (1 << 16), bhvFlyGuy),
		OBJECT(MODEL_FLYGUY, 4014, -4553, 12202, 0, 0, 0, (2 << 16), bhvFlyGuy),
		OBJECT(MODEL_FLYGUY, 4494, -4553, 11685, 0, 0, 0, 0x00000000, bhvFlyGuy),
		OBJECT(MODEL_FLYGUY, 4494, -4553, 12688, 0, 0, 0, 0x00000000, bhvFlyGuy),
		OBJECT(MODEL_FLYGUY, 4220, -4283, 12199, 0, -180, 0, (2 << 16), bhvFlyGuy),
		OBJECT(MODEL_FLYGUY, 3740, -4283, 12716, 0, -180, 0, 0x00000000, bhvFlyGuy),
		OBJECT(MODEL_FLYGUY, 3740, -4283, 11713, 0, -180, 0, 0x00000000, bhvFlyGuy),
		OBJECT(MODEL_NONE, -5, -4472, 17978, 0, 0, 0, 0x00000000, bhvCcsFlyguyLock),
		OBJECT(MODEL_NONE, 0, -4800, 14192, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -5093, -4800, 8973, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -5096, -6550, -15833, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -5101, -5204, 4977, 0, 0, 0, (2 << 16), bhvCCSLock),
		OBJECT(MODEL_K_PLAT, -5108, -7646, -9332, 0, -180, 0, 0x00000000, bhvKPlat),
		OBJECT(MODEL_K_PLAT, -5108, -7281, -10274, 0, -180, 0, 0x00000000, bhvKPlat),
		OBJECT(MODEL_K_PLAT, -5108, -6897, -11169, 0, -180, 0, 0x00000000, bhvKPlat),
		OBJECT(MODEL_NONE, -1200, -4800, 12196, 0, 90, 0, (1 << 16), bhvShutter),
		OBJECT(MODEL_NONE, 1194, -4800, 12196, 0, -90, 0, 0x00000000, bhvShutter),
		OBJECT(MODEL_NONE, -5102, -6550, -14106, 0, 0, 0, 0x00000000, bhvShutter),
		OBJECT(MODEL_SNUFIT, -4511, -5040, 7373, 0, 0, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, -5564, -5040, 7389, 0, 0, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, -5127, -4519, 8310, 0, 0, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_NONE, -533, 597, 17807, 0, -180, 0, 0x00000000, bhvKSource),
		OBJECT(MODEL_NONE, -4510, -4592, 3223, 0, 0, 0, (6 << 16), bhvCCSpawn),
		OBJECT(MODEL_NONE, -4510, -4603, 8997, 0, 0, 0, (6 << 16), bhvCCSpawn),
		OBJECT(MODEL_STAR, -5106, -4588, 4032, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -5077, -5072, 8278, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -4212, -10651, -3298, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -5119, -9571, -13290, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -5042, -15950, -14957, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -5106, -6329, -16883, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 4432, -4009, 12204, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, 5, -2416, 24240, 0, -180, 0, (0xa << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_PURPLE_SWITCH, 3400, -4800, 12200, 0, 0, 0, 0x00000000, bhvFloorSwitchGrills),
		OBJECT(MODEL_CCS_TIMESTOP, -5101, -4700, 4724, 0, 0, 0, 0x00000000, bhvCCTimestop),
		TERRAIN(ccs_area_1_collision),
		MACRO_OBJECTS(ccs_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, ccs_area_2, 0, -4000, 2000-7000),
		WARP_NODE(0x0A, LEVEL_LB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -5108, 23538, 18407, 0, -180, 0, (4 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -4908, 22296, 15344, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -5242, 20727, 13749, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -13101, 14242, 4120, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -12822, 12849, 1041, 0, 137, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -3035, 8588, -1163, 0, 137, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -283, 5836, -1009, 0, 137, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 5920, 1425, -5319, 0, 88, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 5721, 335, -6978, 0, 109, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 4584, 76, -8464, 0, 130, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -2271, -2935, -14574, 0, 178, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -1876, -3893, -15640, 0, 178, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -2326, -7414, -19156, 0, 178, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -1918, -9434, -21184, 0, 178, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -12151, 14242, 6183, 0, -144, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -4834, 19072, 12117, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -5216, 16638, 9373, 0, -165, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -6848, 12355, -948, 0, 137, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 3202, 162, -8990, 0, 84, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -2009, -1349, -12666, 0, 8, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -9774, 15513, 6983, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -5191, 10744, -906, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 3518, 2238, -1009, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 1130, -294, -8978, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -3440, -12362, -25530, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -6094, -12362, -26046, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -8434, -12362, -25995, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -1422, -1662, -10155, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -9937, 12438, -1008, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -5093, 24667, 18285, 0, 0, 0, 0x00000000, bhvCcsCoinStar),
		TERRAIN(ccs_area_2_collision),
		MACRO_OBJECTS(ccs_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -3, -4310, 19568),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};