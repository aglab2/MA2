#include <ultra64.h>"
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"
#include "instant_warp_desc.h"

#include "make_const_nonconst.h"

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

#include "levels/ce/visual/model.inc.c"
#include "levels/ce/leveldata.inc.c"
