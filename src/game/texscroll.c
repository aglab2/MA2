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
#include "src/game/texscroll/aq_texscroll.inc.c"
#include "src/game/texscroll/castle_courtyard_texscroll.inc.c"
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

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_castle_courtyard_segment_7SegmentRomStart)) {
		scroll_textures_castle_courtyard();
	}

#if 0
	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_hb_segment_7SegmentRomStart)) {
		scroll_textures_hb();
	}
#endif
}
