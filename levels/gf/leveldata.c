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

#include "levels/gf/header.inc.h"

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

static const LDLDesc loop_desc1 = { 2, 1, 0, 0x4000 };

static const RailDesc rail_gf_area1[] = {
    LOOP_TRAJ(gf_area_1_spline_NurbsCurve_Loop, &loop_desc1),
    RAIL_TRAJ(gf_area_1_spline_NurbsCurve_Rail),
    RAIL_TRAJ(gf_area_1_spline_NurbsCurve_Rail_001),
    RAIL_TRAJ(gf_area_1_spline_NurbsCurve_Rail_006),
    RAIL_TRAJ(gf_area_1_spline_NurbsCurve_Rail_007),
    RAIL_TRAJ(gf_area_1_spline_NurbsCurve_Rail_008),
    NULL,
};

static const RailDesc rail_gf_area2[] = {
    LOOP_TRAJ(gf_area_2_spline_NurbsCurve_Loop_001, &loop_desc1),
    LOOP_TRAJ(gf_area_2_spline_NurbsCurve_Loop_002, &loop_desc1),
    LOOP_TRAJ(gf_area_2_spline_NurbsCurve_Loop_003, &loop_desc1),
    RAIL_TRAJ(gf_area_2_spline_NurbsCurve_Rail_002),
    RAIL_TRAJ(gf_area_2_spline_NurbsCurve_Rail_003),
    RAIL_TRAJ(gf_area_2_spline_NurbsCurve_Rail_004),
    RAIL_TRAJ(gf_area_2_spline_NurbsCurve_Rail_005),
    RAIL_TRAJ(gf_area_2_spline_NurbsCurve_Rail_009),
    NULL,
};

static const RailDesc rail_gf_area3[] = {
    NULL,
};

static const RailDesc rail_gf_area4[] = {
    NULL,
};

const RailDesc* rail_descs_gf[] = {
    rail_gf_area1,
    rail_gf_area2,
    rail_gf_area3,
    rail_gf_area4,
};

static SpringDesc spring_gf_area1[] = {
    gf_area_1_spline_NurbsCurve_Spring,
    gf_area_1_spline_NurbsCurve_Spring_001,
    gf_area_1_spline_NurbsCurve_Spring_002,
    gf_area_1_spline_NurbsCurve_Spring_003,
    gf_area_1_spline_NurbsCurve_Spring_004,
    gf_area_1_spline_NurbsCurve_Spring_005,
    gf_area_1_spline_NurbsCurve_Spring_015,
    NULL,
};

static SpringDesc spring_gf_area2[] = {
    gf_area_2_spline_NurbsCurve_Spring_006,
    gf_area_2_spline_NurbsCurve_Spring_007,
    gf_area_2_spline_NurbsCurve_Spring_008,
    gf_area_2_spline_NurbsCurve_Spring_009,
    NULL,
};

static SpringDesc spring_gf_area3[] = {
    gf_area_3_spline_NurbsCurve_Spring_010,
    gf_area_3_spline_NurbsCurve_Spring_011,
    gf_area_3_spline_NurbsCurve_Spring_012,
    gf_area_3_spline_NurbsCurve_Spring_013,
    gf_area_3_spline_NurbsCurve_Spring_014,
    NULL,
};

static SpringDesc spring_gf_area4[] = {
    NULL,
};

const SpringDesc* spring_descs_gf[] = {
    spring_gf_area1,
    spring_gf_area2,
    spring_gf_area3,
    spring_gf_area4,
};

#include "levels/gf/visual/model.inc.c"

#include "levels/gf/leveldata.inc.c"

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