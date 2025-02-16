#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"
#include "rail_desc.h"
#include "spring_desc.h"
#include "instant_warp_desc.h"

#include "make_const_nonconst.h"

#if 0
#include "levels/cg/leveldata.inc.c"
#else
#include "levels/cg/area_1/spline.inc.c"
#include "levels/cg/area_2/spline.inc.c"
#include "levels/cg/area_3/spline.inc.c"
#include "levels/cg/area_4/spline.inc.c"
#endif

static IWDHeader iw_area1 = {
    IWDT_CG_DROP,
};

static IWDirectionAreasDesc iw_area2 = {
    IWDT_NONE,
};

static IWDirectionAreasDesc iw_area3 = {
    { IWDT_DIRECTIONS },
    { .z_low = 4, },
};

static IWDirectionAreasDesc iw_area4 = {
    { IWDT_DIRECTIONS },
    { .z_high = 3 },
};

IWDHeader* iw_descs_cg[] = {
    &iw_area1,
    &iw_area2.header,
    &iw_area3.header,
    &iw_area4.header,
};

#include "levels/cg/rails.inc.c"

#include "levels/cg/visual/header_lvl.inc.h"
#include "levels/cg/visual/model_lvl.inc.c"

#include "levels/cg/flipbook.inc.c"

#include "levels/cg/cg_skybox/model.inc.c"
#include "levels/cg/cg_capsule/model.inc.c"
#include "levels/cg/cg_poison/collision.inc.c"
#include "levels/cg/cg_poison/model.inc.c"
#include "levels/cg/cg_poison_break/model.inc.c"
#include "levels/cg/cg_shutter_left/collision.inc.c"
#include "levels/cg/cg_shutter_left/model.inc.c"
#include "levels/cg/cg_shutter_right/collision.inc.c"
#include "levels/cg/cg_shutter_right/model.inc.c"