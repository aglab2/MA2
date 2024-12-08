#include <ultra64.h>"
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"
#include "instant_warp_desc.h"

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

static const Trajectory* rail_mh_area1[] = {
    mh_area_1_spline_1089_object_00BE4D68_001,
    mh_area_1_spline_1089_object_00BE4D68_002,
    NULL,
};

static const Trajectory* rail_mh_area3[] = {
    mh_area_3_spline_1088_object_00BC6BA0_002,
    mh_area_3_spline_1088_object_00BC6BA0_003,
    NULL,
};

const Trajectory** rail_descs_mh[] = {
    rail_mh_area1,
    NULL,
    rail_mh_area3,
    NULL,
};

#include "levels/mh/visual/model.inc.c"

#include "levels/mh/leveldata.inc.c"