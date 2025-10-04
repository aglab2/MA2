#include <ultra64.h>
#include "sm64.h"
#include "geo_commands.h"

#include "game/level_geo.h"
#include "game/geo_misc.h"
#include "game/camera.h"
#include "game/moving_texture.h"
#include "game/screen_transition.h"
#include "game/paintings.h"

#include "make_const_nonconst.h"

#include "levels/cct/header.h"

#if 0
#include "levels/cct/geo.inc.c"
#else
#include "levels/cct/visual/header_lvlopt.inc.h"
#include "levels/cct/visual/geo_lvl.inc.c"
#endif

#include "levels/cct/cct_goaldoor/geo.inc.c"
#include "levels/cct/cct_goaldoor_breaka/geo.inc.c"
#include "levels/cct/cct_goaldoor_breakb/geo.inc.c"
#include "levels/cct/cct_goaldoor_breakc/geo.inc.c"
#include "levels/cct/cct_goaldoor_break/geo.inc.c"
#include "levels/cct/cc_goaldoor_hit/geo.inc.c"
#include "levels/cct/cc_goaldoor_hitbreak/geo.inc.c"
#include "levels/cct/cct_stepb/geo.inc.c"
#include "levels/cct/cct_step/geo.inc.c"
#include "levels/cct/cct_shutter_left/geo.inc.c"
#include "levels/cct/cct_shutter_right/geo.inc.c"
#include "levels/cct/cct_switch/geo.inc.c"
#include "levels/cct/cct_blockla/geo.inc.c"