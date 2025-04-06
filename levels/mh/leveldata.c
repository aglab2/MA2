#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"
#include "instant_warp_desc.h"
#include "rail_desc.h"
#include "spring_desc.h"

#include "make_const_nonconst.h"

#include "levels/mh/visual/header_lvlopt.inc.h"
#include "levels/mh/header.h"

static IWDirectionAreasDesc iw_mh_area1 = {
    { IWDT_DIRECTIONS },
    { .z_low = 2, },
};

static IWDirectionAreasDesc iw_mh_area2 = {
    { IWDT_DIRECTIONS },
    { .z_high = 1, .z_low = 3, },
};

static IWDirectionAreasDesc iw_mh_area3 = {
    { IWDT_DIRECTIONS },
    { .z_high = 2, .x_high = 4, },
};

static IWDirectionAreasDesc iw_mh_area4 = {
    { IWDT_DIRECTIONS },
    { .x_low = 3, },
};

IWDHeader* iw_descs_mh[] = {
    &iw_mh_area1.header,
    &iw_mh_area2.header,
    &iw_mh_area3.header,
    &iw_mh_area4.header,
};

static const LDLDesc loop_desc = { 0 };

#define loop_desc_mh_area_1_spline_NurbsCurve_Loop &loop_desc
#define loop_desc_mh_area_3_spline_NurbsCurve_Loop_001 &loop_desc
#define loop_desc_mh_area_3_spline_NurbsCurve_Loop_002 &loop_desc
#define loop_desc_mh_area_4_spline_Loop_NurbsCurve &loop_desc

#include "rails.inc.c"

const SpringLinkDesc spring_links_mh[] = {
    { mh_area_1_spline_NurbsCurve_Spring_004, mh_area_2_spline_NurbsCurve_Spring_020, },
    { NULL, NULL, }
};

#if 0
#include "levels/mh/leveldata.inc.c"
#else
#include "levels/mh/area_1/spline.inc.c"
#include "levels/mh/area_2/spline.inc.c"
#include "levels/mh/area_3/spline.inc.c"
#include "levels/mh/area_4/spline.inc.c"
#endif

#include "levels/mh/visual/model_lvlopt.inc.c"
#include "levels/mh/flipbook.inc.c"

#include "levels/mh/mh_skybox/model.inc.c"
