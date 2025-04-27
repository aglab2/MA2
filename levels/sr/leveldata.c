#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"
#include "rail_desc.h"
#include "instant_warp_desc.h"
#include "spring_desc.h"

#include "make_const_nonconst.h"

#if 0
#include "levels/sr/leveldata.inc.c"
#else
#include "levels/sr/visual/header_lvlopt.inc.h"
#include "levels/sr/visual/model_lvlopt.inc.c"
#include "levels/sr/area_1/spline.inc.c"
#include "levels/sr/area_2/spline.inc.c"
#include "levels/sr/area_3/spline.inc.c"
#include "levels/sr/rails.inc.c"
#include "levels/sr/iw.inc.c"
#endif

#include "levels/sr/sr_skybox/model.inc.c"
#include "levels/sr/sr_drum/model.inc.c"
#include "levels/sr/sr_drum_break/model.inc.c"
#include "levels/sr/sr_pnp/model.inc.c"
#include "levels/sr/sr_pnp_ground/model.inc.c"
#include "levels/sr/sr_pnp_limit/model.inc.c"