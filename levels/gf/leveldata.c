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

#include "levels/gf/header.h"

static IWDirectionAreasDesc iw_gf_area1 = {
    { IWDT_DIRECTIONS },
    { .x_high = 2, },
};

static IWDirectionAreasDesc iw_gf_area2 = {
    { IWDT_DIRECTIONS },
    { .x_low = 1, .x_high = 3, },
};

static IWDirectionAreasDesc iw_gf_area3 = {
    { IWDT_DIRECTIONS },
    { .x_low = 2, .z_high = 4, },
};

static IWDirectionAreasDesc iw_gf_area4 = {
    { IWDT_DIRECTIONS },
    { .z_low = 3, },
};

IWDHeader* iw_descs_gf[] = {
    &iw_gf_area1.header,
    &iw_gf_area2.header,
    &iw_gf_area3.header,
    &iw_gf_area4.header,
};

static const LDLDesc loop_desc1 = { 0 };
static const LDLDesc loop_desc2 = { 0, .dontFlip = 1, .canSnapBackwards = 1 };

#define loop_desc_gf_area_1_spline_NurbsCurve_Loop &loop_desc1
#define loop_desc_gf_area_2_spline_NurbsCurve_Loop_001 &loop_desc1
#define loop_desc_gf_area_2_spline_NurbsCurve_Loop_002 &loop_desc1
#define loop_desc_gf_area_2_spline_NurbsCurve_Loop_003 &loop_desc1
#define loop_desc_gf_area_2_spline_NurbsCurve_VineLoop_005 &loop_desc2
#define loop_desc_gf_area_4_spline_NurbsCurve_Loop_004 &loop_desc1
#define loop_desc_gf_area_4_spline_NurbsCurve_Loop_005 &loop_desc1

#include "levels/gf/rails.inc.c"

#include "levels/gf/flipbook.inc.c"

#include "levels/gf/visual/model_lvlopt.inc.c"

#if 0
#include "levels/gf/leveldata.inc.c"
#else
#include "levels/gf/area_1/spline.inc.c"
#include "levels/gf/area_2/spline.inc.c"
#include "levels/gf/area_3/spline.inc.c"
#include "levels/gf/area_4/spline.inc.c"
#endif

#include "levels/gf/gf_skybox/model.inc.c"
#include "levels/gf/gf_gake_a/model.inc.c"
#include "levels/gf/gf_gake_b/model.inc.c"
#include "levels/gf/gf_gake_c/model.inc.c"
#include "levels/gf/gf_gake_d/model.inc.c"
#include "levels/gf/gf_gake_e/model.inc.c"
#include "levels/gf/gf_gake_f/model.inc.c"
#include "levels/gf/gf_gake_a/collision.inc.c"
#include "levels/gf/gf_gake_b/collision.inc.c"
#include "levels/gf/gf_gake_c/collision.inc.c"
#include "levels/gf/gf_gake_d/collision.inc.c"
#include "levels/gf/gf_gake_e/collision.inc.c"
#include "levels/gf/gf_gake_f/collision.inc.c"
#include "levels/gf/gf_vine/model.inc.c"