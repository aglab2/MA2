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
#include "levels/ccr/header.h"

/* Fast64 begin persistent block [scripts] */
#include "levels/ccr/area_1/collision.inc.c"
#include "level_config.h"
extern const SpringDesc* spring_descs_ccr[];
static struct LevelConfig cfg = {
	.springDescs = spring_descs_ccr,
};
#define SEQ_LEVEL_GRASS 0x44
/* Fast64 end persistent block [scripts] */

const LevelScript level_ccr_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _ccr_segment_7SegmentRomStart, _ccr_segment_7SegmentRomEnd), 
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
	LOAD_MODEL_FROM_GEO(MODEL_CCR_TIMESTOP, ccr_switch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCR_BLOCK, ccr_block_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCR_SWITCH, ccr_switch_p1_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCR_SWITCH2, ccr_switch_p2_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCR_CAPSULE, ccr_capsule_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCR_PLATFORM, ccr_step_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCR_CAPSULE_OPEN, ccr_capopen_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCR_CAPSULE_ANIM, ccr_capsule_anim_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCR_RISING, ccr_rising_geo), 
	/* Fast64 begin persistent block [level commands] */
	LVL_CONFIG(&cfg),
	#define bhvClamShell bhvClamShellCC
	#define bhvSkeeter bhvSkeeterCC
	#define bhvSnufit bhvSnufitCC
	/* Fast64 end persistent block [level commands] */

	AREA(1, ccr_area_1, 0, 0, 0),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, 0, 863, 988),
		OBJECT(MODEL_NONE, 0, 91, -2446, 0, -180, 0, 0x00000000, bhvCCRBlock),
		OBJECT(MODEL_CCR_CAPSULE, 0, 0, 0, 0, 0, 0, 0x00000000, bhvCCRCapsule),
		OBJECT(MODEL_NONE, -501, 867, 831, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_WOODEN_SIGNPOST, 1, 200, 1109, 0, 0, 0, (3 << 24) | (3 << 16), bhvMessagePanel),
		OBJECT(MODEL_CLAM_SHELL, 2086, 0, 73, 0, 0, 0, 0x00000000, bhvClamShell),
		OBJECT(MODEL_CLAM_SHELL, -2086, 0, -39, 0, -180, 0, 0x00000000, bhvClamShell),
		OBJECT(MODEL_NONE, -1, 300, -3351, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 14, -1200, -6996, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -7, 3917, -1265, 0, 0, 0, (20 << 16), bhvCoinFormation),
		OBJECT(MODEL_CCR_PLATFORM, 6, -1530, -5499, 0, 0, 0, 0x00000000, bhvCCRPlatform),
		OBJECT(MODEL_SKEETER, -929, 200, -364, 0, 0, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SKEETER, 688, 200, -461, 0, 0, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SKEETER, -1606, 50, 1358, 0, 0, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SKEETER, 1554, 50, 1427, 0, 0, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SNUFIT, 630, -1006, -9158, 0, 0, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, -630, -1006, -9158, 0, 0, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, -630, -1006, -7943, 0, 0, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, 635, -1006, -7943, 0, 0, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, -1, -255, -9828, 0, 0, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_NONE, -3, -952, -8388, 0, 0, 0, (16 << 16), bhvCCSpawn),
		OBJECT(MODEL_NONE, 580, -1700, -4950, 0, 0, 0, (14 << 16), bhvCCSpawn),
		OBJECT(MODEL_NONE, -502, -1700, -4950, 0, 0, 0, (15 << 16), bhvCCSpawn),
		OBJECT(MODEL_NONE, 580, -1700, -6050, 0, 0, 0, (15 << 16), bhvCCSpawn),
		OBJECT(MODEL_NONE, -502, -1700, -6050, 0, 0, 0, (14 << 16), bhvCCSpawn),
		OBJECT(MODEL_STAR, 0, 1301, 0, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -3, -1468, 2102, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -6365, 548, 3, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 0, 3559, 0, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -2357, 3108, 4, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 819, 1500, 793, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -3, 2098, -2452, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -26, -263, -7678, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 2082, 0, 73, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_CCR_SWITCH, 0, 300, 0, 0, 0, 0, 0x00000000, bhvCCRSwitch),
		OBJECT(MODEL_CCR_TIMESTOP, -813, 4400, 809, 0, 0, 0, 0x00000000, bhvCCTimestop),
		OBJECT(MODEL_CCR_TIMESTOP, 7, -600, -8892, 0, 0, 0, 0x00000000, bhvCCTimestop),
		OBJECT(MODEL_CCR_TIMESTOP, -4, -1504, -6500, 90, 0, 0, 0x00000000, bhvCCTimestop),
		OBJECT(MODEL_PURPLE_SWITCH, 7, -600, -9598, 0, 0, 0, 0x00000000, bhvFloorSwitchGrills),
		TERRAIN(ccr_area_1_collision),
		MACRO_OBJECTS(ccr_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 863, 988),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};