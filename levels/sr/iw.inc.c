
static IWDirectionAreasDesc iw_area1 = {
    { IWDT_DIRECTIONS },
    { .z_high = 2, },
};

static IWDirectionAreasDesc iw_area2 = {
    { IWDT_DIRECTIONS },
    { .z_low = 1, .z_high = 3 },
};

static IWDirectionAreasDesc iw_area3 = {
    { IWDT_DIRECTIONS },
    { .z_low = 2 },
};

IWDHeader* iw_descs_sr[] = {
    &iw_area1.header,
    &iw_area2.header,
    &iw_area3.header,
};
