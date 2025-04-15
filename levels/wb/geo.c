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

#include "levels/wb/header.h"

#if 0
#include "levels/wb/geo.inc.c"
#else
#include "levels/wb/visual/geo_lvl.inc.c"
#endif

#include "levels/wb/wb_cont/geo.inc.c"
#include "levels/wb/wb_cont_break/geo.inc.c"
#include "levels/wb/wb_contb/geo.inc.c"
#include "levels/wb/wb_contc/geo.inc.c"
#include "levels/wb/wb_fig_ai/geo.inc.c"
#include "levels/wb/wb_fig_ai2/geo.inc.c"
#include "levels/wb/wb_shut/geo.inc.c"
#include "levels/wb/wb_shut_break/geo.inc.c"
#include "levels/wb/wb_shuts/geo.inc.c"
#include "levels/wb/wb_shuts_break/geo.inc.c"