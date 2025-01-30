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

#include "levels/mh/header.h"

#if 0
#include "levels/mh/geo.inc.c"
#endif

#define mh_area_1 mh_area_visual
#define mh_area_1_geo mh_area_geo_visual
#include "levels/mh/visual/geo_lvl.inc.c"
