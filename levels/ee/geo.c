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

#include "levels/ee/header.h"

#define ee_area_1 ee_area_visual
#define ee_area_1_geo ee_area_geo_visual
#include "levels/ee/visual/geo_lvl.inc.c"

#if 0
#include "levels/ee/geo.inc.c"
#endif

#include "levels/ee/ee_shutter_left/geo.inc.c"
#include "levels/ee/ee_shutter_right/geo.inc.c"
#include "levels/ee/ee_capsule/geo.inc.c"
#include "levels/ee/ee_capsule_inside/geo.inc.c"
#include "levels/ee/ee_hatch_a/geo.inc.c"
#include "levels/ee/ee_hatch_b/geo.inc.c"
#include "levels/ee/ee_laststep/geo.inc.c"
#include "levels/ee/ee_stepb/geo.inc.c"
#include "levels/ee/ee_tank/geo.inc.c"
#include "levels/ee/ee_tank_break/geo.inc.c"