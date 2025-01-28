#include "instant_warp_desc.h"

static IWDirectionAreasDesc iw_area1 = {
    IWDT_DIRECTIONS,
    { .z_high = 2, },
};

static IWDHeader iw_area2 = {
    IWDT_CG_DROP
};

static IWDirectionAreasDesc iw_area3 = {
    IWDT_DIRECTIONS,
    { .x_high = 4, },
};

static IWDirectionAreasDesc iw_area4 = {
    IWDT_DIRECTIONS,
    { .x_low = 3, .z_high = 5, },
};

static IWDirectionAreasDesc iw_area5 = {
    IWDT_DIRECTIONS,
    { .z_low = 4, .z_high = 6, },
};

static IWDirectionAreasDesc iw_area6 = {
    IWDT_DIRECTIONS,
    { .z_low = 5, .z_high = 7, },
};

static IWDirectionAreasDesc iw_area7 = {
    IWDT_DIRECTIONS,
    { .z_low = 6, .z_high = 8, },
};

static IWDirectionAreasDesc iw_area8 = {
    IWDT_DIRECTIONS,
    { .z_low = 7, .x_low = 9, },
};

static IWDirectionAreasDesc iw_area9 = {
    IWDT_DIRECTIONS,
    { .x_high = 8, .z_low = 10, },
};

static IWDirectionAreasDesc iw_area10 = {
    IWDT_DIRECTIONS,
    { .z_high = 9, .z_low = 11, },
};

static IWDirectionAreasDesc iw_area11 = {
    IWDT_DIRECTIONS,
    { .z_high = 10, .z_low = 12, },
};

static IWDHeader iw_area12 = {
    IWDT_CG_DROP
};

IWDHeader* iw_descs_fr[] = {
    &iw_area1.header,
    &iw_area2,
    &iw_area3.header,
    &iw_area4.header,
    &iw_area5.header,
    &iw_area6.header,
    &iw_area7.header,
    &iw_area8.header,
    &iw_area9.header,
    &iw_area10.header,
    &iw_area11.header,
    &iw_area12,
    NULL,
};
