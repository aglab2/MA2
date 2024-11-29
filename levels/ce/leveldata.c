#include <ultra64.h>"
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"
#include "instant_warp_desc.h"

#include "make_const_nonconst.h"

#include "levels/ce/header.inc.h"

static IWDirectionAreasDesc iw_ce_area1 = {
    { IWDT_DIRECTIONS },
    { .z_high = 2, },
};

static IWDirectionAreasDesc iw_ce_area2 = {
    { IWDT_DIRECTIONS },
    { .z_low = 1, .z_high = 3, },
};

static IWDirectionUpDownDirectionsAreasDesc iw_ce_area3 = {
    { IWDT_UP_DOWN_DIRECTIONS },
    {
        { .z_low = 2, },
        { .z_low = 4, },
    }
};

static IWDirectionAreasDesc iw_ce_area4 = {
    { IWDT_DIRECTIONS },
    { .z_high = 3, .x_high = 5, },
};

static IWDirectionAreasDesc iw_ce_area5 = {
    { IWDT_DIRECTIONS },
    { .x_low = 4, .x_high = 6, },
};

static IWDirectionAreasDesc iw_ce_area6 = {
    { IWDT_DIRECTIONS },
    { .x_low = 5, .z_high = 7, },
};

static IWDirectionAreasDesc iw_ce_area7 = {
    { IWDT_DIRECTIONS },
    { .z_low = 6, .z_high = 8, },
};

static IWDirectionAreasDesc iw_ce_area8 = {
    { IWDT_DIRECTIONS },
    { .z_low = 7, .z_high = 9, },
};

static IWDirectionAreasDesc iw_ce_area9 = {
    { IWDT_DIRECTIONS },
    { .z_low = 8, .x_low = 10, },
};

static IWDirectionAreasDesc iw_ce_area10 = {
    { IWDT_DIRECTIONS },
    { .x_high = 9, },
};

IWDHeader* iw_descs_ce[] = {
    &iw_ce_area1.header,
    &iw_ce_area2.header,
    &iw_ce_area3.header,
    &iw_ce_area4.header,
    &iw_ce_area5.header,
    &iw_ce_area6.header,
    &iw_ce_area7.header,
    &iw_ce_area8.header,
    &iw_ce_area9.header,
    &iw_ce_area10.header,
};

static const Trajectory* rail_ce_area3[] = {
    ce_area_3_spline_2459_object_00CFC480_001,
    ce_area_3_spline_2473_object_00CFEC08_001,
    ce_area_3_spline_z_1681_object_00D2405C_001,
    ce_area_3_spline_z_1757_object_00CA7120_001,
    ce_area_3_spline_z_1757_object_00CA7120_002,
    NULL,
};

static const Trajectory* rail_ce_area4[] = {
    NULL,
};

static const Trajectory* rail_ce_area5[] = {
    ce_area_5_spline_2561_object_00D05490_001,
    NULL,
};

static const Trajectory* rail_ce_area6[] = {
    ce_area_6_spline_2443_object_00D39804_002,
    ce_area_6_spline_2480_object_00D39A6C_001,
    ce_area_6_spline_0870_object_00D2DB3C_001,
    NULL,
};

static const Trajectory* rail_ce_area7[] = {
    ce_area_7_spline_2443_object_00D39804_001,
    ce_area_7_spline_2449_object_00CFAC10_001,
    ce_area_7_spline_2479_object_00D39A34_001,
    NULL,
};

const Trajectory** rail_descs_ce[] = {
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

#include "levels/ce/visual/model.inc.c"
#include "levels/ce/leveldata.inc.c"

#include "levels/ce/ce_hammer/model.inc.c"
#include "levels/ce/ce_hammer/collision.inc.c"

#include "levels/ce/ce_skybox/model.inc.c"