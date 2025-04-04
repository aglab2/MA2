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
#include "levels/so/header.h"

/* Fast64 begin persistent block [scripts] */
#include "levels/so/area_1/collision.inc.c"
#include "levels/so/area_2/collision.inc.c"
#define so_area_2 so_area_1
extern Gfx so_skybox_so_skybox_mesh[];
extern IWDHeader* iw_descs_so[];
static struct LevelConfig cfg = {
	.skybox = so_skybox_so_skybox_mesh,
	.iwds = iw_descs_so,
};
#define SEQ_LEVEL_GRASS 0x3A
/* Fast64 end persistent block [scripts] */

const LevelScript level_so_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _so_segment_7SegmentRomStart, _so_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0x05, _group5_yay0SegmentRomStart, _group5_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group5_geoSegmentRomStart, _group5_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_6), 
	LOAD_MODEL_FROM_GEO(MODEL_SO_ASHIBA, hb_ashiba_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SO_ASHIBA2, hb_ashiba2_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SO_ASHIBA3, hb_ashiba3_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SO_ASHIBAF, hb_ashibaf_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SO_ASHIBAF2, hb_ashibaf2_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SO_ASHIBAF3, hb_ashibaf3_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SO_HAKO, so_hako_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SO_HAKO_BREAK, so_hako_break_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SO_KAITEN, so_kaiten_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SO_PILLAR, so_pillar_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SO_PILLAR_BASE, so_pillar_base_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SO_PILLAR_BREAK, so_pillar_break_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SO_TSUBO, so_tsubo_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SO_TSUBO_BREAK, so_tsubo_break_geo), 
	/* Fast64 begin persistent block [level commands] */
	LVL_CONFIG(&cfg),
	/* Fast64 end persistent block [level commands] */

	AREA(1, so_area_1, 1500, 0, -100),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, -14987, 300, -549),
		OBJECT(MODEL_NONE, -14981, 400, -7378, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -14980, 400, -1377, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -11691, 300, -4400, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_RED_FLAME, -15694, 1161, 432, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, -14365, 1160, 435, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, -16514, 494, -7402, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame2),
		OBJECT(MODEL_RED_FLAME, -13493, 494, -7403, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame2),
		OBJECT(MODEL_RED_FLAME, -14280, 1159, -12347, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, -15702, 1161, -12351, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, -15700, 1162, -13171, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, -14279, 1161, -13169, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, -12854, 660, -18500, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, -9046, 793, -18292, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, -9516, 1206, -18283, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, -9809, 737, -18272, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, -10241, 1225, -18295, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame),
		OBJECT(MODEL_NONE, -14969, 300, -6994, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -15045, 800, -12610, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -9733, 300, -18904, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_SO_HAKO, -12763, 0, -19434, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvBreakable),
		OBJECT(MODEL_SO_HAKO, -13028, 0, -19434, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvBreakable),
		OBJECT(MODEL_SO_HAKO, -6840, -600, -20495, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvBreakable),
		OBJECT(MODEL_SO_PILLAR, -8213, 500, -19500, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvSoPillar),
		OBJECT(MODEL_SO_PILLAR, -8673, -400, -20241, 0, 90, 0, (MODEL_SO_HAKO_BREAK << 16), bhvSoPillar),
		OBJECT(MODEL_SO_PILLAR, -14962, 700, -13721, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvSoPillar),
		OBJECT(MODEL_NONE, -9185, 300, -18893, 0, 0, 0, 0x00000000, bhvPokey),
		OBJECT(MODEL_NONE, -12375, 300, -4416, 0, 0, 0, 0x00000000, bhvPokey),
		OBJECT(MODEL_SO_KAITEN, -14993, 0, -4415, 0, 0, 0, 0x00000000, bhvSoHako),
		TERRAIN(so_area_1_collision),
		MACRO_OBJECTS(so_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, so_area_2, 1500, 0, -4100),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BOOSTER, 19613, 300, 562, 0, 0, 0, 0x00000000, bhvBooster),
		OBJECT(MODEL_BOOSTER, 19613, 300, -1538, 0, 0, 0, 0x00000000, bhvBooster),
		OBJECT(MODEL_RED_FLAME, -5185, 1238, 6935, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, -671, 1239, 6969, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, 2248, 473, -1006, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame2),
		OBJECT(MODEL_RED_FLAME, 2251, 477, 1978, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame2),
		OBJECT(MODEL_RED_FLAME, 6268, 1238, -984, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, 13551, 889, -403, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, 13555, 1291, 54, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, 13551, 826, 346, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, 13557, 1296, 775, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, 13564, 876, 3781, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, 19669, 75, -6890, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame2),
		OBJECT(MODEL_RED_FLAME, 19652, 75, -10019, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame2),
		OBJECT(MODEL_RED_FLAME, 19670, 79, -12873, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame2),
		OBJECT(MODEL_RED_FLAME, 18639, 779, -15983, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, 18653, 376, -16792, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, 18638, 137, -17807, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, 18659, -233, -18740, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, 20558, 766, -15994, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, 20556, 362, -16807, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, 20558, 112, -17815, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, 20551, -233, -18737, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, 13912, 2100, -21546, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvFlame2),
		OBJECT(MODEL_NONE, -7674, 800, -5742, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 12982, 300, 170, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 19593, -1000, -19151, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_SO_HAKO, 12338, 300, 1088, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvBreakable),
		OBJECT(MODEL_SO_HAKO, 13399, 300, 4823, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvBreakable),
		OBJECT(MODEL_SO_HAKO, 13399, 300, 5117, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvBreakable),
		OBJECT(MODEL_SO_HAKO, 20350, -1000, -19371, 0, 0, 0, (MODEL_SO_HAKO_BREAK << 16), bhvBreakable),
		OBJECT(MODEL_SO_PILLAR, 18730, -400, -20057, 0, 90, 0, (MODEL_SO_HAKO_BREAK << 16), bhvSoPillar),
		OBJECT(MODEL_SO_PILLAR, 15155, 0, -20576, 0, 90, 0, (MODEL_SO_HAKO_BREAK << 16), bhvSoPillar),
		OBJECT(MODEL_SO_PILLAR, 15259, -800, -19454, 0, 90, 0, (MODEL_SO_HAKO_BREAK << 16), bhvSoPillar),
		OBJECT(MODEL_NONE, 19477, -400, -16922, 0, 0, 0, 0x00000000, bhvPokey),
		OBJECT(MODEL_NONE, 11608, -600, -883, 0, 0, 0, 0x00000000, bhvPokey),
		OBJECT(MODEL_NONE, 12145, 0, 4990, 0, 0, 0, 0x00000000, bhvPokey),
		OBJECT(MODEL_SO_KAITEN, -710, 0, -669, 0, 0, 0, 0x00000000, bhvSoHako),
		OBJECT(MODEL_SO_KAITEN, 19590, 0, 3215, 0, 0, 0, 0x00000000, bhvSoHako),
		TERRAIN(so_area_2_collision),
		MACRO_OBJECTS(so_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -14987, 300, -549),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};