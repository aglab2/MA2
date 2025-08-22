#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"

#include "make_const_nonconst.h"
#include "instant_warp_desc.h"
#include "spring_desc.h"

#if 0
#include "levels/so/leveldata.inc.c"
#else
#include "levels/so/visual/header_lvl.inc.h"
#include "levels/so/visual/model_lvlopt.inc.c"
#include "levels/so/area_1/spline.inc.c"
#include "levels/so/area_2/spline.inc.c"
#endif

static IWDirectionAreasDesc iw_area1 = {
    { IWDT_DIRECTIONS },
    { .z_low = 2, },
};

static IWDirectionAreasDesc iw_area2 = {
    { IWDT_DIRECTIONS },
    { .z_high = 1, },
};

IWDHeader* iw_descs_so[] = {
    &iw_area1.header,
    &iw_area2.header,
};

#include "levels/so/header.h"
#include "levels/so/rails.inc.c"
#include "levels/so/flipbook.inc.c"

#include "levels/so/so_skybox/model.inc.c"
#include "levels/so/hb_ashiba/model.inc.c"
#include "levels/so/hb_ashiba/collision.inc.c"
#include "levels/so/hb_ashiba2/model.inc.c"
#include "levels/so/hb_ashiba2/collision.inc.c"
#include "levels/so/hb_ashiba3/model.inc.c"
#include "levels/so/hb_ashibaf/model.inc.c"
#include "levels/so/hb_ashibaf2/model.inc.c"
#include "levels/so/hb_ashibaf3/model.inc.c"
#include "levels/so/so_hako/model.inc.c"
#include "levels/so/so_hako_break/model.inc.c"
#include "levels/so/so_kaiten/model.inc.c"
#include "levels/so/so_kaiten/collision.inc.c"
#include "levels/so/so_pillar/model.inc.c"
#include "levels/so/so_pillar/collision.inc.c"
#include "levels/so/so_tsubo/model.inc.c"
#include "levels/so/so_tsubo_break/model.inc.c"
#include "levels/so/so_pillar_base/model.inc.c"
#include "levels/so/so_pillar_base/collision.inc.c"
#include "levels/so/so_pillar_break/model.inc.c"
#include "levels/so/hb_ashiba3/collision.inc.c"