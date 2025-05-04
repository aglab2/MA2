#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"
#include "flipbook.h"
#include "instant_warp_desc.h"
#include "spring_desc.h"

#include "make_const_nonconst.h"

#if 0
#include "levels/cw/leveldata.inc.c"
#else
#include "levels/cw/visual/header_lvlopt.inc.h"
#include "levels/cw/visual/model_lvlopt.inc.c"
#include "levels/cw/flipbook.inc.c"
#include "levels/cw/iw.inc.c"
#include "levels/cw/area_1/spline.inc.c"
#include "levels/cw/area_2/spline.inc.c"
#include "levels/cw/area_3/spline.inc.c"
#include "levels/cw/area_4/spline.inc.c"
#include "levels/cw/area_5/spline.inc.c"
#include "levels/cw/area_6/spline.inc.c"
#include "levels/cw/area_7/spline.inc.c"
#include "levels/cw/area_8/spline.inc.c"
#include "levels/cw/area_9/spline.inc.c"
#include "levels/cw/rails.inc.c"
#endif

#include "levels/cw/cw_skybox/model.inc.c"