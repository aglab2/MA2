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

#include "levels/castle_grounds2/header.h"


extern Gfx *geo_update_alpha_compare(s32 callContext, struct GraphNode *node, UNUSED void *context);
#include "levels/castle_grounds2/geo.inc.c"
#include "levels/castle_grounds2/ow2_lock/geo.inc.c"
#include "levels/castle_grounds2/ow2_number/geo.inc.c"

#include "levels/castle_grounds2/ow2_ig/geo.inc.c"
#include "levels/castle_grounds2/ow2_dl/geo.inc.c"
#include "levels/castle_grounds2/ow2_so/geo.inc.c"
#include "levels/castle_grounds2/ow2_rh/geo.inc.c"
#include "levels/castle_grounds2/ow2_eq/geo.inc.c"
#include "levels/castle_grounds2/ow2_lc/geo.inc.c"
#include "levels/castle_grounds2/ow2_wb/geo.inc.c"
#include "levels/castle_grounds2/ow2_sh/geo.inc.c"
#include "levels/castle_grounds2/ow2_wj/geo.inc.c"
#include "levels/castle_grounds2/ow2_sr/geo.inc.c"
#include "levels/castle_grounds2/ow2_ms/geo.inc.c"
#include "levels/castle_grounds2/ow2_cw/geo.inc.c"