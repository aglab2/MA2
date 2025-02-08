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
#include "levels/hb/visual/geo_lvl.inc.c"

#include "levels/hb/hb_skybox/geo.inc.c"
#include "levels/hb/hb_block/geo.inc.c"
#include "levels/hb/hb_block_break/geo.inc.c"
#include "levels/hb/hb_hashira/geo.inc.c"
#include "levels/hb/hb_hashira_break/geo.inc.c"
#include "levels/hb/hb_vase/geo.inc.c"
#include "levels/hb/hb_vase_break/geo.inc.c"
#include "levels/hb/hb_wall_break/geo.inc.c"
#include "levels/hb/hb_hashira_platform/geo.inc.c"
#include "levels/hb/hb_updown/geo.inc.c"
#include "levels/hb/hb_updown_bright/geo.inc.c"
#include "levels/hb/hb_wall/geo.inc.c"