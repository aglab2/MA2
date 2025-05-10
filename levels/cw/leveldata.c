#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"
#include "flipbook.h"
#include "instant_warp_desc.h"
#include "spring_desc.h"
#include "rail_desc.h"

#include "make_const_nonconst.h"

static const LDLDesc loop_desc1 = { .angleOffset = -0x4000 };
#define loop_desc_cw_area_6_spline_NurbsCurve_Loop &loop_desc1

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
#include "levels/cw/rails.inc.c"

const SpringLinkDesc spring_links_cw[] = {
    { cw_area_4_spline_NurbsCurve_Spring_003, cw_area_5_spline_NurbsCurve_Spring_002, },
    { NULL, NULL, }
};

#endif

#include "levels/cw/cw_skybox/model.inc.c"
#include "levels/cw/cw_meteolava/model.inc.c"
#include "levels/cw/cw_meteo/model.inc.c"
#include "levels/cw/cw_meteo2/model.inc.c"
#include "levels/cw/cw_meteo2_break/model.inc.c"
#include "levels/cw/cw_meteo_break/model.inc.c"
#include "levels/cw/cw_meteolava_break/model.inc.c"
#include "levels/cw/cw_updown/collision.inc.c"
#include "levels/cw/cw_updown/model.inc.c"
#include "levels/cw/cw_drill_base/model.inc.c"
#include "levels/cw/cw_drill/model.inc.c"