static IWDirectionAreasDesc iw_wj_area1 = {
    { IWDT_DIRECTIONS },
    { .x_high = 2, },
};

static IWDirectionAreasDesc iw_wj_area2 = {
    { IWDT_DIRECTIONS },
    { .x_low = 1, .z_low = 3, },
};

static IWDirectionAreasDesc iw_wj_area3 = {
    { IWDT_DIRECTIONS },
    { .x_high = 4, .z_high = 2, },
};

static IWDirectionAreasDesc iw_wj_area4 = {
    { IWDT_DIRECTIONS },
    { .x_low = 3, .z_low = 5, },
};

static IWDirectionAreasDesc iw_wj_area5 = {
    { IWDT_DIRECTIONS },
    { .z_high = 4, },
};

IWDHeader* iw_descs_wj[] = {
    &iw_wj_area1.header,
    &iw_wj_area2.header,
    &iw_wj_area3.header,
    &iw_wj_area4.header,
    &iw_wj_area5.header,
};
