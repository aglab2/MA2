#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"
#include "rail_desc.h"

#include "make_const_nonconst.h"


#include "levels/lb/leveldata.inc.c"
#include "levels/lb/lb_rail/model.inc.c"
#include "levels/lb/lb_ball/model.inc.c"
#include "levels/lb/lb_stand/model.inc.c"
#include "levels/lb/lb_tail/model.inc.c"
#include "levels/lb/lb_tail/collision.inc.c"
#include "levels/lb/rails.inc.c"

#include "levels/lb/lb_sparkle/model.inc.c"
#include "levels/lb/lb_sparkle2/model.inc.c"
#include "levels/lb/lb_stand/collision.inc.c"
#include "levels/lb/lb_wind/collision.inc.c"

const char gLbText0[] = R"(In a level full of lush vegetation, a traveller may
find a course referencing Sonic legacy near the safe spot.

Use this warp to travel back to Hero story.)";

const char gLbText1[] = R"(Seeking in a course filled with robots, a pilgrim may
find a suspicious door. Carry heavenly token to unlock it.

Use this warp to travel back to Dark story.)";

const char gLbText2[] = R"(The final reward awaits
the player that has 99.9%% completion.)";
