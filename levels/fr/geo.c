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

#include "levels/fr/header.h"

#if 0
#include "levels/fr/geo.inc.c"
#endif

#define fr_area_1 fr_area_visual
#define fr_area_1_geo fr_area_geo_visual
#include "levels/fr/visual/geo_lvl.inc.c"
