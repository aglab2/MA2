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
#include "levels/lc/header.h"

/* Fast64 begin persistent block [scripts] */
#include "levels/lc/area_1/collision.inc.c"
#include "levels/lc/area_2/collision.inc.c"
#define lc_area_2 lc_area_1
extern IWDHeader* iw_descs_lc[];
static struct LevelConfig cfg = {
	.iwds = iw_descs_lc,
};
#define SEQ_LEVEL_GRASS 0x3c
/* Fast64 end persistent block [scripts] */

const LevelScript level_lc_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _lc_segment_7SegmentRomStart, _lc_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	/* Fast64 begin persistent block [level commands] */
	LVL_CONFIG(&cfg),
	/* Fast64 end persistent block [level commands] */

	AREA(1, lc_area_1, 1200, 0, -2000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, -11995, -350, 18762),
		OBJECT(MODEL_CHECKPOINT, -26016, -7930, 6142, 0, -180, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_CHECKPOINT, 7486, -9180, -3982, 0, 90, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_NONE, -11995, -48, 18762, 0, 0, 0, (0xa << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_SNUFIT, -17570, -6144, 14029, 0, 90, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, -17570, -6144, 12979, 0, 90, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_BOOSTER, -12000, -350, 17498, 0, 0, 0, 0x00000000, bhvBooster),
		OBJECT(MODEL_BOOSTER, -13250, -350, 13499, 0, 90, 0, 0x00000000, bhvBooster),
		OBJECT(MODEL_BOOSTER, -19513, -6430, 13505, 0, 90, 0, 0x00000000, bhvBooster),
		OBJECT(MODEL_BOOSTER, -26000, -6430, 10999, 0, 0, 0, 0x00000000, bhvBooster),
		OBJECT(MODEL_BOOSTER, -10295, -5180, -3009, 0, -90, 0, 0x00000000, bhvBooster),
		OBJECT(MODEL_BOOSTER, 707, -5180, -3996, 0, -90, 0, 0x00000000, bhvBooster),
		OBJECT(MODEL_BOOSTER, 8702, -9180, -3995, 0, -90, 0, 0x00000000, bhvBooster),
		OBJECT(MODEL_STAR, -17929, -350, 13499, 0, 90, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -11312, -63, 14180, 0, 90, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -16205, -6375, 13501, 0, 90, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -26005, -7185, 6406, 0, 90, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -26001, -5949, 7238, 0, 90, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -25109, -6411, 3753, 0, 90, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, -28771, -6104, -523, 0, 90, 0, 0x00000000, bhvHiddenRedCoinStar),
		OBJECT(MODEL_STAR, -21956, -5424, -1492, 0, 90, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -18331, -4905, -1323, 0, 90, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -15731, -5068, -1459, 0, 90, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -3539, -4899, -4956, 0, 90, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 2413, -8846, -3981, 0, 90, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 10401, -2771, -4014, 0, 90, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_WOODEN_SIGNPOST, 15049, -9180, -3981, 0, 90, 0, (1 << 24) | (1 << 16), bhvMessagePanel),
		TERRAIN(lc_area_1_collision),
		MACRO_OBJECTS(lc_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, lc_area_2, 5200, 0, -2000),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		TERRAIN(lc_area_2_collision),
		MACRO_OBJECTS(lc_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -11995, -350, 18762),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};