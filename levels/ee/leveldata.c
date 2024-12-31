#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"
#include "instant_warp_desc.h"
#include "spring_desc.h"

#include "make_const_nonconst.h"

#include "levels/ee/visual/model.inc.c"

static IWDirectionAreasDesc iw_ee_area1 = {
    { IWDT_DIRECTIONS },
    { .z_low = 2, },
};

static IWDirectionAreasDesc iw_ee_area2 = {
    { IWDT_DIRECTIONS },
    { .z_high = 1, .x_low = 3, },
};

static IWDirectionAreasDesc iw_ee_area3 = {
    { IWDT_DIRECTIONS },
    { .x_high = 2, .z_low = 4 },
};

static IWDirectionAreasDesc iw_ee_area4 = {
    { IWDT_DIRECTIONS },
    { .z_high = 3, .x_high = 5 },
};

static IWDirectionAreasDesc iw_ee_area5 = {
    { IWDT_DIRECTIONS },
    { .x_low = 4 },
};

IWDHeader* iw_descs_ee[] = {
    &iw_ee_area1.header,
    &iw_ee_area2.header,
    &iw_ee_area3.header,
    &iw_ee_area4.header,
    &iw_ee_area5.header,
};

static SpringDesc spring_ee_area1[] = {
    NULL,
};

static SpringDesc spring_ee_area2[] = {
    NULL,
};

const SpringLinkDesc spring_links_ee[] = {
    { NULL, NULL, }
};

const SpringDesc* spring_descs_ee[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

#if 1
#include "levels/ee/area_1/collision.inc.c"
#include "levels/ee/area_2/collision.inc.c"
#include "levels/ee/area_3/collision.inc.c"
#include "levels/ee/area_4/collision.inc.c"
#include "levels/ee/area_5/collision.inc.c"
#else
#include "levels/ee/leveldata.inc.c"
#endif

#include "levels/ee/ee_shutter_dynamite/collision.inc.c"
#include "levels/ee/ee_shutter_left/model.inc.c"
#include "levels/ee/ee_shutter_right/model.inc.c"
#include "levels/ee/ee_shutter_left/collision.inc.c"
#include "levels/ee/ee_shutter_right/collision.inc.c"
#include "levels/ee/ee_capsule/model.inc.c"
#include "levels/ee/ee_capsule_inside/model.inc.c"
#include "levels/ee/ee_hatch_a/model.inc.c"
#include "levels/ee/ee_hatch_a/collision.inc.c"
#include "levels/ee/ee_hatch_b/model.inc.c"
#include "levels/ee/ee_hatch_b/collision.inc.c"
#include "levels/ee/ee_laststep/collision.inc.c"
#include "levels/ee/ee_laststep/model.inc.c"
#include "levels/ee/ee_step/collision.inc.c"
#include "levels/ee/ee_stepb/model.inc.c"
#include "levels/ee/ee_stepb/collision.inc.c"
#include "levels/ee/ee_tank/model.inc.c"
#include "levels/ee/ee_tank_break/model.inc.c"