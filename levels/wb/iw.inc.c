static IWDirectionAreasDesc iw_wb_area1 = {
    { IWDT_DIRECTIONS },
    { .z_low = 2, },
};

static IWDirectionAreasDesc iw_wb_area2 = {
    { IWDT_DIRECTIONS },
    { .z_high = 1, },
};

IWDHeader* iw_descs_wb[] = {
    &iw_wb_area1.header,
    &iw_wb_area2.header,
};
