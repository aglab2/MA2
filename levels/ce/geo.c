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

#include "levels/ce/header.h"


#if 0
#include "levels/ce/geo.inc.c"
#endif

#define ce_area_1 ce_area_visual
#define ce_area_1_geo ce_area_geo_visual
#include "levels/ce/visual/geo_lvl.inc.c"

#include "levels/ce/ce_hammer/geo.inc.c"