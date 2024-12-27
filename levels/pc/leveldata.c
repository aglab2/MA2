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

#include "levels/pc/header.inc.h"

static IWDirectionAreasDesc iw_pc_area1 = {
    { IWDT_DIRECTIONS },
    { .z_low = 2, },
};

static IWDirectionAreasDesc iw_pc_area2 = {
    { IWDT_DIRECTIONS },
    { .z_high = 1, .x_low = 3, },
};

static IWDirectionAreasDesc iw_pc_area3 = {
    { IWDT_DIRECTIONS },
    { .x_high = 2, .z_low = 4, },
};

static IWDirectionAreasDesc iw_pc_area4 = {
    { IWDT_DIRECTIONS },
    { .z_high = 3, .z_low = 5, },
};

static IWDirectionAreasDesc iw_pc_area5 = {
    { IWDT_DIRECTIONS },
    { .z_high = 4, .z_low = 6, },
};

static IWDirectionAreasDesc iw_pc_area6 = {
    { IWDT_DIRECTIONS },
    { .z_high = 5, .z_low = 7, },
};

static IWDirectionAreasDesc iw_pc_area7 = {
    { IWDT_DIRECTIONS },
    { .z_high = 6, .x_high = 8, },
};

static IWDirectionAreasDesc iw_pc_area8 = {
    { IWDT_DIRECTIONS },
    { .x_low = 6, },
};

IWDHeader* iw_descs_pc[] = {
    &iw_pc_area1.header,
    &iw_pc_area2.header,
    &iw_pc_area3.header,
    &iw_pc_area4.header,
    &iw_pc_area5.header,
    &iw_pc_area6.header,
    &iw_pc_area7.header,
    &iw_pc_area8.header,
};

static const LDLDesc loop_desc1 = { 2, 1, 0, 1, 0x4000 };

static const RailDesc rail_pc_area1[] = {
    // LOOP_TRAJ(pc_area_1_spline_NurbsCurve_Loop, &loop_desc1),
};

const RailDesc* rail_descs_pc[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

const SpringDesc* spring_descs_pc[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

#include "levels/pc/visual/model.inc.c"

#if 0
#include "levels/pc/leveldata.inc.c"
#endif
#include "levels/pc/area_1/collision.inc.c"
#include "levels/pc/area_1/macro.inc.c"
#include "levels/pc/area_1/spline.inc.c"
#include "levels/pc/area_2/collision.inc.c"
#include "levels/pc/area_2/macro.inc.c"
#include "levels/pc/area_2/spline.inc.c"
#include "levels/pc/area_3/collision.inc.c"
#include "levels/pc/area_3/macro.inc.c"
#include "levels/pc/area_3/spline.inc.c"
#include "levels/pc/area_4/collision.inc.c"
#include "levels/pc/area_4/macro.inc.c"
#include "levels/pc/area_4/spline.inc.c"
#include "levels/pc/area_5/collision.inc.c"
#include "levels/pc/area_5/macro.inc.c"
#include "levels/pc/area_5/spline.inc.c"
#include "levels/pc/area_6/collision.inc.c"
#include "levels/pc/area_6/macro.inc.c"
#include "levels/pc/area_6/spline.inc.c"
#include "levels/pc/area_7/collision.inc.c"
#include "levels/pc/area_7/macro.inc.c"
#include "levels/pc/area_7/spline.inc.c"
#include "levels/pc/area_8/collision.inc.c"
#include "levels/pc/area_8/macro.inc.c"
#include "levels/pc/area_8/spline.inc.c"

#include "levels/pc/pc_door_b/collision.inc.c"
#include "levels/pc/pc_door_b/model.inc.c"
#include "levels/pc/pc_door_g/collision.inc.c"
#include "levels/pc/pc_door_g/model.inc.c"
#include "levels/pc/pc_door_n/collision.inc.c"
#include "levels/pc/pc_door_n/model.inc.c"
#include "levels/pc/pc_door_r/collision.inc.c"
#include "levels/pc/pc_door_r/model.inc.c"
#include "levels/pc/pc_block/model.inc.c"
#include "levels/pc/pc_block/collision.inc.c"
#include "levels/pc/pc_key_blue/model.inc.c"
#include "levels/pc/pc_key_green/model.inc.c"
#include "levels/pc/pc_keydoor_blue/model.inc.c"
#include "levels/pc/pc_keydoor_green/model.inc.c"
#include "levels/pc/pc_windmill/model.inc.c"
#include "levels/pc/pc_windmill/collision.inc.c"
#include "levels/pc/pc_walltype/model.inc.c"
#include "levels/pc/pc_walltype/collision.inc.c"
#include "levels/pc/pc_sandglass_ends/model.inc.c"
#include "levels/pc/pc_sandglass_glass/model.inc.c"
#include "levels/pc/pc_sandglass_sand/model.inc.c"
#include "levels/pc/pc_sandglass_sandf/model.inc.c"
#include "levels/pc/pc_sandglass_spring/model.inc.c"