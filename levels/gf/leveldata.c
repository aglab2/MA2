#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"
#include "instant_warp_desc.h"
#include "rail_desc.h"
#include "spring_desc.h"

#include "make_const_nonconst.h"

#include "levels/mh/header.inc.h"

static IWDirectionAreasDesc iw_gf_area1 = {
    { IWDT_DIRECTIONS },
    { .x_high = 2, },
};

static IWDirectionAreasDesc iw_gf_area2 = {
    { IWDT_DIRECTIONS },
    { .x_low = 1, .x_high = 3, },
};

static IWDirectionAreasDesc iw_gf_area3 = {
    { IWDT_DIRECTIONS },
    { .x_low = 2, .z_high = 4, },
};

static IWDirectionAreasDesc iw_gf_area4 = {
    { IWDT_DIRECTIONS },
    { .z_low = 3, },
};

IWDHeader* iw_descs_gf[] = {
    &iw_gf_area1.header,
    &iw_gf_area2.header,
    &iw_gf_area3.header,
    &iw_gf_area4.header,
};

#include "levels/gf/visual/model.inc.c"

#include "levels/gf/leveldata.inc.c"

#include "levels/gf/gf_skybox/model.inc.c"