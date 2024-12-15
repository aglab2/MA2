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

#include "levels/mh/header.inc.h"

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

static const LDLDesc loop_mh_desc1 = { 2, 1, 0, 0x4000 };

static const RailDesc rail_mh_area1[] = {
    RAIL_TRAJ(mh_area_1_spline_1089_object_00BE4D68_001),
    RAIL_TRAJ(mh_area_1_spline_1089_object_00BE4D68_002),
    LOOP_TRAJ(mh_area_1_spline_NurbsCurve_Loop, &loop_mh_desc1),
    NULL,
};

static const RailDesc rail_mh_area3[] = {
    RAIL_TRAJ(mh_area_3_spline_1088_object_00BC6BA0_002),
    RAIL_TRAJ(mh_area_3_spline_1088_object_00BC6BA0_003),
    LOOP_TRAJ(mh_area_3_spline_NurbsCurve_Loop_001, &loop_mh_desc1),
    LOOP_TRAJ(mh_area_3_spline_NurbsCurve_Loop_002, &loop_mh_desc1),
    NULL,
};

const RailDesc* rail_descs_mh[] = {
    rail_mh_area1,
    NULL,
    rail_mh_area3,
    NULL,
};

static const SpringDesc spring_mh_area1[] = {
    mh_area_1_spline_NurbsCurve_Spring,
    mh_area_1_spline_NurbsCurve_Spring_001,
    mh_area_1_spline_NurbsCurve_Spring_002,
    mh_area_1_spline_NurbsCurve_Spring_003,
    mh_area_1_spline_NurbsCurve_Spring_004,
    mh_area_1_spline_NurbsCurve_Spring_006,
    mh_area_1_spline_NurbsCurve_Spring_011,
    mh_area_1_spline_NurbsCurve_Spring_012,
    mh_area_1_spline_NurbsCurve_Spring_019,
    NULL,
};

static const SpringDesc spring_mh_area2[] = {
    mh_area_2_spline_NurbsCurve_Spring_005,
    mh_area_2_spline_NurbsCurve_Spring_007,
    mh_area_2_spline_NurbsCurve_Spring_008,
    mh_area_2_spline_NurbsCurve_Spring_017,
    mh_area_2_spline_NurbsCurve_Spring_018,
    mh_area_2_spline_NurbsCurve_Spring_020,
    NULL,
};

static const SpringDesc spring_mh_area3[] = {
    mh_area_3_spline_NurbsCurve_Spring_009,
    mh_area_3_spline_NurbsCurve_Spring_010,
    mh_area_3_spline_NurbsCurve_Spring_021,
    mh_area_3_spline_NurbsCurve_Spring_022,
    mh_area_3_spline_NurbsCurve_Spring_023,
    NULL,
};

static SpringDesc spring_mh_area4[] = {
    mh_area_4_spline_NurbsCurve_Spring_013,
    mh_area_4_spline_NurbsCurve_Spring_014,
    mh_area_4_spline_NurbsCurve_Spring_015,
    mh_area_4_spline_NurbsCurve_Spring_016,
    NULL,
};

const SpringDesc* spring_descs_mh[] = {
    spring_mh_area1,
    spring_mh_area2,
    spring_mh_area3,
    spring_mh_area4,
};

const SpringLinkDesc spring_links_mh[] = {
    { mh_area_1_spline_NurbsCurve_Spring_004, mh_area_2_spline_NurbsCurve_Spring_020, },
    { NULL, NULL, }
};

#include "levels/mh/visual/model.inc.c"

#include "levels/mh/leveldata.inc.c"
#include "levels/mh/mh_skybox/model.inc.c"