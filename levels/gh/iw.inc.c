#include "instant_warp_desc.h"

static IWDirectionAreasDesc iw_area1 = {
    IWDT_DIRECTIONS,
    { .z_low = 2, },
};

static IWDirectionAreasDesc iw_area2 = {
    IWDT_DIRECTIONS,
    { .z_high = 1, },
};

IWDHeader* iw_descs_gh[] = {
    &iw_area1.header,
    &iw_area2.header,
    NULL,
};
