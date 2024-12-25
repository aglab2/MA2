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

#include "levels/pc/header.h"


#include "levels/pc/geo.inc.c"

#define pc_area_1 pc_area_visual
#define pc_area_1_geo pc_area_geo_visual
#include "levels/pc/visual/geo.inc.c"
