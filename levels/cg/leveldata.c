#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"

#include "make_const_nonconst.h"

#if 0
#include "levels/cg/leveldata.inc.c"
#else
#include "levels/cg/area_1/collision.inc.c"
#include "levels/cg/area_1/spline.inc.c"
#include "levels/cg/area_2/collision.inc.c"
#include "levels/cg/area_2/spline.inc.c"
#include "levels/cg/area_3/collision.inc.c"
#include "levels/cg/area_3/spline.inc.c"
#include "levels/cg/area_4/collision.inc.c"
#include "levels/cg/area_4/spline.inc.c"
#endif

#include "levels/cg/visual/header_lvl.inc.h"
#include "levels/cg/visual/model_lvl.inc.c"

#include "levels/cg/cg_skybox/model.inc.c"
#include "levels/cg/cg_capsule/model.inc.c"
#include "levels/cg/cg_poison/collision.inc.c"
#include "levels/cg/cg_poison/model.inc.c"
#include "levels/cg/cg_poison_break/model.inc.c"
#include "levels/cg/cg_shutter_left/collision.inc.c"
#include "levels/cg/cg_shutter_left/model.inc.c"
#include "levels/cg/cg_shutter_right/collision.inc.c"
#include "levels/cg/cg_shutter_right/model.inc.c"