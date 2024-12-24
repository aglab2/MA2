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

#include "levels/hb/header.h"

#if 0
#include "levels/hb/geo.inc.c"
#endif

#define hb_area_1 hb_area_visual
#define hb_area_1_geo hb_area_geo_visual
#include "levels/hb/visual/geo.inc.c"

#include "levels/hb/hb_skybox/geo.inc.c"