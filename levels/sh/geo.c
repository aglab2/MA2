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

#include "levels/sh/header.h"

#if 0
#include "levels/sh/geo.inc.c"
#else
#include "levels/sh/visual/geo_lvl.inc.c"
#endif

#include "levels/sh/sh_bombe/geo.inc.c"
#include "levels/sh/sh_bombe_break/geo.inc.c"
#include "levels/sh/sh_fun/geo.inc.c"
#include "levels/sh/sh_lb/geo.inc.c"
#include "levels/sh/sh_lr/geo.inc.c"
#include "levels/sh/sh_ly/geo.inc.c"
#include "levels/sh/sh_rb/geo.inc.c"
#include "levels/sh/sh_rr/geo.inc.c"
#include "levels/sh/sh_ry/geo.inc.c"
#include "levels/sh/sh_tank/geo.inc.c"
#include "levels/sh/sh_tank_break/geo.inc.c"