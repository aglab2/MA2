#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"
#include "instant_warp_desc.h"
#include "rail_desc.h"

#include "make_const_nonconst.h"

#include "levels/ce/header.inc.h"

#include "levels/ce/iw.inc.c"

static const RailDesc rail_ce_area3[] = {
    RAIL_TRAJ(ce_area_3_spline_2459_object_00CFC480_001),
    RAIL_TRAJ(ce_area_3_spline_2473_object_00CFEC08_001),
    RAIL_TRAJ(ce_area_3_spline_z_1681_object_00D2405C_001),
    RAIL_TRAJ(ce_area_3_spline_z_1757_object_00CA7120_001),
    RAIL_TRAJ(ce_area_3_spline_z_1757_object_00CA7120_002),
    RAIL_END,
};

static const RailDesc rail_ce_area4[] = {
    RAIL_END,
};

static const RailDesc rail_ce_area5[] = {
    RAIL_TRAJ(ce_area_5_spline_2561_object_00D05490_001),
    RAIL_END,
};

static const LDLDesc loop_desc1 = { 0 };
static const RailDesc rail_ce_area6[] = {
    RAIL_TRAJ(ce_area_6_spline_2443_object_00D39804_002),
    RAIL_TRAJ(ce_area_6_spline_2480_object_00D39A6C_001),
    RAIL_TRAJ(ce_area_6_spline_0870_object_00D2DB3C_001),
    LOOP_TRAJ(ce_area_6_spline_NurbsCurve_Loop, &loop_desc1),
    RAIL_END,
};

static const RailDesc rail_ce_area7[] = {
    RAIL_TRAJ(ce_area_7_spline_2443_object_00D39804_001),
    RAIL_TRAJ(ce_area_7_spline_2449_object_00CFAC10_001),
    RAIL_TRAJ(ce_area_7_spline_2479_object_00D39A34_001),
    RAIL_END,
};

const RailDesc* rail_descs_ce[] = {
    NULL,
    NULL,
    rail_ce_area3,
    rail_ce_area4,
    rail_ce_area5,
    rail_ce_area6,
    rail_ce_area7,
    NULL,
    NULL,
    NULL,
};

#include "levels/ce/visual/header_lvl.inc.h"
#include "levels/ce/visual/model_lvl.inc.c"
#if 0
#include "levels/ce/leveldata.inc.c"
#else
#include "levels/ce/area_1/spline.inc.c"
#include "levels/ce/area_10/spline.inc.c"
#include "levels/ce/area_2/spline.inc.c"
#include "levels/ce/area_3/spline.inc.c"
#include "levels/ce/area_4/spline.inc.c"
#include "levels/ce/area_5/spline.inc.c"
#include "levels/ce/area_6/spline.inc.c"
#include "levels/ce/area_7/spline.inc.c"
#include "levels/ce/area_8/spline.inc.c"
#include "levels/ce/area_9/spline.inc.c"
#endif

#include "levels/ce/ce_hammer/model.inc.c"
#include "levels/ce/ce_hammer/collision.inc.c"

#include "levels/ce/ce_skybox/model.inc.c"