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

#include "levels/cg/header.h"

#if 0
#include "levels/cg/geo.inc.c"
#endif

#define cg_area_1 cg_area_visual
#define cg_area_1_geo cg_area_geo_visual
#include "levels/cg/visual/geo.inc.c"
