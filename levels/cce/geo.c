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

#include "levels/cce/header.h"

#if 0
#include "levels/cce/geo.inc.c"
#else
#include "levels/cce/visual/geo_lvl.inc.c"
#endif

#include "levels/cce/cce_switch/geo.inc.c"
#include "levels/cce/cce_shutter_right/geo.inc.c"
#include "levels/cce/cce_shutter_left/geo.inc.c"
#include "levels/cce/cce_stepb/geo.inc.c"
#include "levels/cce/cce_step/geo.inc.c"
#include "levels/cce/cce_block/geo.inc.c"
#include "levels/cce/cce_door/geo.inc.c"
#include "levels/cce/cce_doorhit/geo.inc.c"