static IWDirectionAreasDesc iw_area1 = {
    { IWDT_DIRECTIONS },
    { .x_high = 2, },
};

static IWDirectionAreasDesc iw_area2 = {
    { IWDT_DIRECTIONS },
    { .z_high = 3, .x_low = 1, },
};

static IWDirectionAreasDesc iw_area3 = {
    { IWDT_DIRECTIONS },
    { .z_high = 4, .z_low = 2, },
};

static IWDirectionFullAreasDesc iw_area4 = {
    { IWDT_FULL_DIRECTIONS },
    { .y_high = 5, .z_high = 6, .z_low = 3, .y_value = 9000.f },
};

static IWDirectionFullAreasDesc iw_area5 = {
    { IWDT_FULL_DIRECTIONS },
    { .y_low = 4, .z_high = 6, .z_low = 3, .y_value = -11000.f },
};

static IWDirectionAreasDesc iw_area6 = {
    { IWDT_DIRECTIONS },
    { .z_high = 7, .z_low = 5, },
};

static IWDirectionAreasDesc iw_area7 = {
    { IWDT_DIRECTIONS },
    { .z_low = 6, }
};

const IWDHeader* iw_descs_cw[] = {
    &iw_area1.header,
    &iw_area2.header,
    &iw_area3.header,
    &iw_area4.header,
    &iw_area5.header,
    &iw_area6.header,
    &iw_area7.header,
};
