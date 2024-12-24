#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"
#include "instant_warp_desc.h"

#include "make_const_nonconst.h"

#include "levels/hb/header.inc.h"

static IWDirectionAreasDesc iw_hb_area1 = {
    { IWDT_DIRECTIONS },
    { .x_low = 2, },
};

static IWDirectionAreasDesc iw_hb_area2 = {
    { IWDT_DIRECTIONS },
    { .x_high = 1, .z_low = 3, },
};

static IWDirectionAreasDesc iw_hb_area3 = {
    { IWDT_DIRECTIONS },
    { .z_high = 2 },
};

IWDHeader* iw_descs_hb[] = {
    &iw_hb_area1.header,
    &iw_hb_area2.header,
    &iw_hb_area3.header,
};

#include "levels/hb/visual/model.inc.c"

#if 0
#include "levels/hb/leveldata.inc.c"
#else
#include "levels/hb/area_1/collision.inc.c"
#include "levels/hb/area_1/macro.inc.c"
#include "levels/hb/area_1/spline.inc.c"
#include "levels/hb/area_2/collision.inc.c"
#include "levels/hb/area_2/macro.inc.c"
#include "levels/hb/area_2/spline.inc.c"
#include "levels/hb/area_3/collision.inc.c"
#include "levels/hb/area_3/macro.inc.c"
#include "levels/hb/area_3/spline.inc.c"
#endif

#include "levels/hb/hb_skybox/model.inc.c"
#include "levels/hb/hb_block/collision.inc.c"
#include "levels/hb/hb_block/model.inc.c"
#include "levels/hb/hb_block_break/model.inc.c"
#include "levels/hb/hb_hashira/collision.inc.c"
#include "levels/hb/hb_hashira/model.inc.c"
#include "levels/hb/hb_hashira_break/model.inc.c"
#include "levels/hb/hb_vase/model.inc.c"
#include "levels/hb/hb_vase_break/model.inc.c"
#include "levels/hb/hb_wall_break/model.inc.c"
#include "levels/hb/hb_hashira_platform/model.inc.c"
#include "levels/hb/hb_hashira_platform/collision.inc.c"
#include "levels/hb/hb_updown/collision.inc.c"
#include "levels/hb/hb_updown/model.inc.c"
#include "levels/hb/hb_updown_bright/model.inc.c"
#include "levels/hb/hb_wall/model.inc.c"