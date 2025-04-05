#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"

#include "make_const_nonconst.h"
#include "instant_warp_desc.h"
#include "rail_desc.h"
#include "spring_desc.h"

static IWDirectionAreasDesc iw_rh_area1 = {
    { IWDT_DIRECTIONS },
    { .z_low = 2, },
};

static IWDirectionAreasDesc iw_rh_area2 = {
    { IWDT_DIRECTIONS },
    { .z_low = 2, },
};

static IWDirectionAreasDesc iw_rh_area3 = {
    { IWDT_DIRECTIONS },
    { .z_low = 2, },
};

static IWDirectionAreasDesc iw_rh_area4 = {
    { IWDT_DIRECTIONS },
    { .z_low = 2, },
};

static IWDirectionAreasDesc iw_rh_area5 = {
    { IWDT_DIRECTIONS },
    { .z_low = 2, },
};

static IWDirectionAreasDesc iw_rh_area6 = {
    { IWDT_DIRECTIONS },
    { .z_low = 2, },
};

static IWDirectionAreasDesc iw_rh_area7 = {
    { IWDT_DIRECTIONS },
    { .z_low = 2, },
};

const IWDHeader* iw_descs_rh[] = {
    &iw_rh_area1.header,
    &iw_rh_area2.header,
    &iw_rh_area3.header,
    &iw_rh_area4.header,
    &iw_rh_area5.header,
    &iw_rh_area6.header,
    &iw_rh_area7.header,
};

#include "levels/rh/header.h"

static const LDLDesc loop_desc1 = { 0 };
#define loop_desc_rh_area_1_spline_Loop_NurbsCurve &loop_desc1
#define loop_desc_rh_area_1_spline_Loop_NurbsCurve_001 &loop_desc1
#define loop_desc_rh_area_2_spline_Loop_NurbsCurve_002 &loop_desc1
#define loop_desc_rh_area_6_spline_Loop_NurbsCurve_003 &loop_desc1
#define loop_desc_rh_area_6_spline_Loop_NurbsCurve_004 &loop_desc1
#define loop_desc_rh_area_6_spline_Loop_NurbsCurve_005 &loop_desc1
#define loop_desc_rh_area_6_spline_Loop_NurbsCurve_006 &loop_desc1

#include "levels/rh/rails.inc.c"

#if 0
#include "levels/rh/leveldata.inc.c"
#else
#include "levels/rh/area_1/spline.inc.c"
#include "levels/rh/area_2/spline.inc.c"
#include "levels/rh/area_3/spline.inc.c"
#include "levels/rh/area_4/spline.inc.c"
#include "levels/rh/area_5/spline.inc.c"
#include "levels/rh/area_6/spline.inc.c"
#include "levels/rh/area_7/spline.inc.c"
#include "levels/rh/visual/header_lvl.inc.h"
#include "levels/rh/visual/model_lvl.inc.c"
#endif

#include "levels/rh/rh_skybox/model.inc.c"