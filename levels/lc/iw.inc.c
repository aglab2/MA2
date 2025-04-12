static IWDirectionAreasDesc iw_lc_area1 = {
    { IWDT_DIRECTIONS },
    { .x_high = 2, },
};

static IWDirectionAreasDesc iw_lc_area2 = {
    { IWDT_DIRECTIONS },
    { .x_low = 1, },
};

IWDHeader* iw_descs_lc[] = {
    &iw_lc_area1.header,
    &iw_lc_area2.header,
};
