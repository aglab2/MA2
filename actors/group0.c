#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "geo_commands.h"

#include "make_const_nonconst.h"

// Note: This bin does not use bin IDs, unlike the other segmented bins.
#include "mario/model.inc.c"

#include "bubble/model.inc.c"

#include "walk_smoke/model.inc.c"

#include "burn_smoke/model.inc.c"

#include "small_water_splash/model.inc.c"

#include "water_wave/model.inc.c"

#include "sparkle/model.inc.c"

#include "water_splash/model.inc.c"

#include "white_particle_small/model.inc.c"

#include "sparkle_animation/model.inc.c"

#ifdef S2DEX_TEXT_ENGINE
#include "src/s2d_engine/s2d_config.h"
#include FONT_C_FILE
#endif

#include "checkpoint/model.inc.c"
#include "goal/model.inc.c"
#include "box_wood/model.inc.c"
#include "box_wood/collision.inc.c"
#include "speeder/collision.inc.c"
#include "speeder/model.inc.c"
#include "spring/model.inc.c"
#include "ramp/collision.inc.c"
#include "ramp/model.inc.c"
#include "rocket/model.inc.c"
#include "rocket_launcher/model.inc.c"
#include "rocket_launcher/collision.inc.c"
#include "purple_switch/model.inc.c"
#include "purple_switch/collision.inc.c"
