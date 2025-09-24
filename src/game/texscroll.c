#include "types.h"
#include "include/segment_symbols.h"
#include "memory.h"
#include "engine/math_util.h"
#include "src/engine/behavior_script.h"
#include "tile_scroll.h"
#include "texscroll.h"
#include "sm64.h"

#ifdef TARGET_N64
#define SCROLL_CONDITION(condition) condition
#else
#define SCROLL_CONDITION(condition) 1
#endif


#include "src/game/texscroll/wc_texscroll.inc.c"
#include "src/game/texscroll/group0_texscroll.inc.c"
#include "src/game/texscroll/ph_texscroll.inc.c"
#include "src/game/texscroll/ms_texscroll.inc.c"
#include "src/game/texscroll/hb_texscroll.inc.c"
#include "src/game/texscroll/castle_grounds_texscroll.inc.c"
#include "src/game/texscroll/castle_grounds2_texscroll.inc.c"
#include "src/game/texscroll/aq_texscroll.inc.c"
#include "src/game/texscroll/castle_courtyard_texscroll.inc.c"
#include "src/game/texscroll/ee_texscroll.inc.c"
#include "src/game/texscroll/mhe_texscroll.inc.c"
#include "src/game/texscroll/fr_texscroll.inc.c"
#include "src/game/texscroll/ss2_texscroll.inc.c"
#include "src/game/texscroll/castle_inside_texscroll.inc.c"
#include "src/game/texscroll/end_texscroll.inc.c"
#include "src/game/texscroll/msp_texscroll.inc.c"
#include "src/game/texscroll/fc_texscroll.inc.c"
#include "src/game/texscroll/lb_texscroll.inc.c"
#include "src/game/texscroll/lf_texscroll.inc.c"
#include "src/game/texscroll/gh_texscroll.inc.c"
#include "src/game/texscroll/chao_texscroll.inc.c"
void scroll_textures() {
	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_wc_segment_7SegmentRomStart)) {
		scroll_textures_wc();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x4] == (uintptr_t)_group0_mio0SegmentRomStart)) {
		scroll_textures_group0();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_ph_segment_7SegmentRomStart)) {
		scroll_textures_ph();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_aq_segment_7SegmentRomStart)) {
		scroll_textures_aq();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_castle_grounds_segment_7SegmentRomStart)) {
		scroll_textures_castle_grounds();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_castle_grounds2_segment_7SegmentRomStart)) {
		scroll_textures_castle_grounds2();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_castle_courtyard_segment_7SegmentRomStart)) {
		scroll_textures_castle_courtyard();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_ee_segment_7SegmentRomStart)) {
		scroll_textures_ee();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_mhe_segment_7SegmentRomStart)) {
		scroll_textures_mhe();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_fr_segment_7SegmentRomStart)) {
		scroll_textures_fr();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_ss2_segment_7SegmentRomStart)) {
		scroll_textures_ss2();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_castle_inside_segment_7SegmentRomStart)) {
		scroll_textures_castle_inside();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_end_segment_7SegmentRomStart)) {
		scroll_textures_end();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_msp_segment_7SegmentRomStart)) {
		scroll_textures_msp();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_fc_segment_7SegmentRomStart)) {
		scroll_textures_fc();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_lb_segment_7SegmentRomStart)) {
		scroll_textures_lb();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_lf_segment_7SegmentRomStart)) {
		scroll_textures_lf();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_gh_segment_7SegmentRomStart)) {
		scroll_textures_gh();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_chao_segment_7SegmentRomStart)) {
		scroll_textures_chao();
	}

}
