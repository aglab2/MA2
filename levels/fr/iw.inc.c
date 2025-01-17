#include "instant_warp_desc.h"

static IWDirectionAreasDesc iw_area1 = {
    IWDT_DIRECTIONS,
    { .z_high = 2, },
};

static IWDirectionAreasDesc iw_area2 = {
    IWDT_DIRECTIONS,
    { .z_low = 1, },
};

static IWDirectionAreasDesc iw_area3 = {
    IWDT_DIRECTIONS,
    { .z_low = 4, },
};

static IWDirectionAreasDesc iw_area4 = {
    IWDT_DIRECTIONS,
    { .z_high = 3 },
};

static IWDirectionAreasDesc iw_area5 = {
    IWDT_DIRECTIONS,
    { .z_high = 3 },
};

static IWDirectionAreasDesc iw_area6 = {
    IWDT_DIRECTIONS,
    { .z_high = 3 },
};

static IWDirectionAreasDesc iw_area7 = {
    IWDT_DIRECTIONS,
    { .z_high = 3 },
};

static IWDirectionAreasDesc iw_area8 = {
    IWDT_DIRECTIONS,
    { .z_high = 3 },
};

static IWDirectionAreasDesc iw_area9 = {
    IWDT_DIRECTIONS,
    { .z_high = 3 },
};

static IWDirectionAreasDesc iw_area10 = {
    IWDT_DIRECTIONS,
    { .z_high = 3 },
};

static IWDirectionAreasDesc iw_area11 = {
    IWDT_DIRECTIONS,
    { .z_high = 3 },
};

IWDHeader* iw_descs_fr[] = {
    &iw_area1.header,
    &iw_area2.header,
    &iw_area3.header,
    &iw_area4.header,
    &iw_area5.header,
    &iw_area6.header,
    &iw_area7.header,
    &iw_area8.header,
    &iw_area9.header,
    &iw_area10.header,
    &iw_area11.header,
};
