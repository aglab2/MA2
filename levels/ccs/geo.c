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

#include "levels/ccs/header.h"

#if 0
#include "levels/ccs/geo.inc.c"
#else
#include "levels/ccs/visual/header_lvlopt.inc.h"
#include "levels/ccs/visual/geo_lvl.inc.c"
#endif

#include "levels/ccs/ccs_block/geo.inc.c"
#include "levels/ccs/ccs_shutter_left/geo.inc.c"
#include "levels/ccs/ccs_shutter_right/geo.inc.c"
#include "levels/ccs/ccs_switch/geo.inc.c"