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

#include "levels/ccr/header.h"

#if 0
#include "levels/ccr/geo.inc.c"
#else
extern Gfx *geo_switch_cc(s32 callContext, struct GraphNode *node, UNUSED void *context);
#include "levels/ccr/visual/geo_lvl.inc.c"
#endif
