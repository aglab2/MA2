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
#include "levels/gf/header.h"

/* Fast64 begin persistent block [scripts] */
extern const GeoLayout gf_area_visual[];
#define gf_area_1 gf_area_visual
#define gf_area_2 gf_area_visual
#define gf_area_3 gf_area_visual
#define gf_area_4 gf_area_visual
#define gf_area_5 gf_area_visual
#define gf_area_6 gf_area_visual
#define gf_area_7 gf_area_visual
#define gf_area_8 gf_area_visual
#define gf_area_9 gf_area_visual
#define gf_area_10 gf_area_visual
/* Fast64 end persistent block [scripts] */

const LevelScript level_gf_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _gf_segment_7SegmentRomStart, _gf_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	LOAD_MODEL_FROM_GEO(MODEL_GF_VINE, gf_vine_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GF_GAKE_A, gf_gake_a_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GF_GAKE_B, gf_gake_b_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GF_GAKE_C, gf_gake_c_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GF_GAKE_D, gf_gake_d_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GF_GAKE_E, gf_gake_e_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GF_GAKE_F, gf_gake_f_geo), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, gf_area_1, 1600, -521, 2300),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, -15979, 4600, -23684),
		OBJECT(MODEL_CHECKPOINT, -16351, -3094, -4565, 0, 0, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHECKPOINT, 2245, -3144, 6113, 0, 90, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHECKPOINT, 14242, 1614, 22956, 0, -180, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_GOOMBA, -16184, 4093, -22855, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_RED_COIN, 4528, -2898, 14277, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 4065, -3051, 15312, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 5136, -3021, 15782, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 4734, -3136, 16176, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 4695, -2802, 15075, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3824, -3010, 14353, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 5642, -3012, 16261, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_STAR, -15478, -2136, -6534, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -9772, -6749, 7314, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -15532, -1961, -2507, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -5454, -3827, 6544, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 3928, -2503, 5861, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, 6454, -2942, 16822, 0, 0, 0, 0x00000000, bhvHiddenRedCoinStar),
		OBJECT(MODEL_STAR, 3797, -3396, 13539, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 5151, -854, 13562, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 11190, -171, 14949, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 18851, 56, 23084, 0, 0, 0, 0x00000000, bhvStar),
		TERRAIN(gf_area_1_collision),
		MACRO_OBJECTS(gf_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, gf_area_2, 5600, -1545, 6300),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CHECKPOINT, -9671, 9503, -9689, 0, 0, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_STAR, -17826, 7482, -17062, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -12033, 7408, -13572, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -8840, 7181, -14071, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -8517, 7738, -10849, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -10769, 9598, -12042, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -9886, 10410, -9190, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -9258, 9886, -6741, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -9625, 6481, -891, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 2588, -2139, 11553, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 3096, -4696, 11793, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 11215, -4568, 13276, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 13192, -879, 12446, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_GF_VINE, -3945, -7126, 6452, 0, 0, 0, 0x00000000, bhvGfVine),
		TERRAIN(gf_area_2_collision),
		MACRO_OBJECTS(gf_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(3, gf_area_3, 9600, -980, 6300),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CHECKPOINT, -21037, -8405, 15682, 0, 0, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_RED_COIN, -13668, 9566, 17573, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -12751, 9395, 18377, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -10945, 9226, 19327, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -9146, 8973, 18602, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -7769, 8844, 17295, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -8068, 8735, 15010, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -7679, 8709, 12256, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -8627, 8499, 8800, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -10669, 8174, 9509, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_STAR, -20513, -8040, 15299, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -12324, -10770, 18004, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -14124, 9563, 15179, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, -10930, 8845, 12468, 0, 0, 0, 0x00000000, bhvHiddenRedCoinStar),
		OBJECT(MODEL_STAR, -10834, 10882, 21201, 0, 0, 0, 0x00000000, bhvStar),
		TERRAIN(gf_area_3_collision),
		MACRO_OBJECTS(gf_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(4, gf_area_4, 9600, -980, 10300),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CHECKPOINT, -10887, 803, -16307, 0, 0, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_GF_GAKE_A, 10770, -10197, 7609, 0, 0, 0, 0x00000000, bhvGfGake),
		OBJECT(MODEL_GF_GAKE_B, 10770, -10197, 7609, 0, 0, 0, (1 << 16), bhvGfGake),
		OBJECT(MODEL_GF_GAKE_C, 10770, -10197, 7609, 0, 0, 0, (2 << 16), bhvGfGake),
		OBJECT(MODEL_GF_GAKE_D, 10770, -10197, 7609, 0, 0, 0, (3 << 16), bhvGfGake),
		OBJECT(MODEL_GF_GAKE_E, 10770, -10197, 7609, 0, 0, 0, (4 << 16), bhvGfGake),
		OBJECT(MODEL_GF_GAKE_F, 10770, -10197, 7609, 0, 0, 0, (5 << 16), bhvGfGake),
		OBJECT(MODEL_GOAL, 13980, -8240, 7570, 0, 0, 0, 0x00000000,  bhvGoal),
		OBJECT(MODEL_RED_COIN, -14531, -6630, 1218, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -14433, -7139, 2754, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -14258, -7498, 3823, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -13682, -7931, 5094, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -13017, -8247, 5878, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -11434, -8738, 6864, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -9799, -9048, 7176, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -8537, -9189, 7253, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_STAR, -10905, 3193, -11348, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -10917, -1188, -5939, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, -7036, -9084, 7609, 0, 0, 0, 0x00000000, bhvHiddenRedCoinStar),
		TERRAIN(gf_area_4_collision),
		MACRO_OBJECTS(gf_area_4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -15979, 4600, -23684),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};