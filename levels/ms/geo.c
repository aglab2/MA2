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

#include "levels/ms/header.h"

#if 0
#include "levels/ms/geo.inc.c"
#endif

#define ms_area_1 ms_area_visual
#define ms_area_1_geo ms_area_geo_visual
#include "levels/ms/visual/geo_lvl.inc.c"

#include "levels/ms/ms_buffer/geo.inc.c"
#include "levels/ms/ms_buffer_break/geo.inc.c"
#include "levels/ms/ms_hammer/geo.inc.c"
#include "levels/ms/ms_slane_break/geo.inc.c"
#include "levels/ms/ms_slane/geo.inc.c"