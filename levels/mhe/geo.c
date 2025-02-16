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

#include "levels/mhe/header.h"

#if 0
#include "levels/mhe/geo.inc.c"
#else
#include "levels/mhe/visual/geo_lvl.inc.c"
#endif

#include "levels/mhe/mhe_bigshutter/geo.inc.c"
#include "levels/mhe/mhe_fireball/geo.inc.c"
#include "levels/mhe/mhe_fireball_break/geo.inc.c"
#include "levels/mhe/mhe_meteo_a/geo.inc.c"
#include "levels/mhe/mhe_meteo_b/geo.inc.c"
#include "levels/mhe/mhe_meteo_break_a/geo.inc.c"
#include "levels/mhe/mhe_meteobig/geo.inc.c"
#include "levels/mhe/mhe_meteobig_break/geo.inc.c"
#include "levels/mhe/mhe_meteo_fall/geo.inc.c"
#include "levels/mhe/mhe_meteoshut/geo.inc.c"
#include "levels/mhe/mhe_tank/geo.inc.c"
#include "levels/mhe/mhe_tank_break/geo.inc.c"
#include "levels/mhe/mhe_meteoshut_break/geo.inc.c"