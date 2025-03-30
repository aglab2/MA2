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

#include "levels/ms/header.inc.h"
#include "levels/ms/visual/header_lvl.inc.h"

static IWDirectionAreasDesc iw_ms_area1 = {
    { IWDT_DIRECTIONS },
    { .x_high = 2, },
};

static IWDirectionAreasDesc iw_ms_area2 = {
    { IWDT_DIRECTIONS },
    { .x_low = 1, .z_low = 3, },
};

static IWDirectionAreasDesc iw_ms_area3 = {
    { IWDT_DIRECTIONS },
    { .z_high = 2, },
};

IWDHeader* iw_descs_ms[] = {
    &iw_ms_area1.header,
    &iw_ms_area2.header,
    &iw_ms_area3.header,
};

static SpringDesc spring_ms_area1[] = {
    ms_area_1_spline_NurbsCurve_Spring,
    ms_area_1_spline_NurbsCurve_Spring_001,
    ms_area_1_spline_NurbsCurve_Spring_002,
    ms_area_1_spline_NurbsCurve_Spring_003,
    ms_area_1_spline_NurbsCurve_Spring_004,
    ms_area_1_spline_NurbsCurve_Spring_005,
    NULL,
};

static SpringDesc spring_ms_area2[] = {
    ms_area_2_spline_NurbsCurve_Spring_006,
    NULL,
};

const SpringLinkDesc spring_links_ms[] = {
    { ms_area_1_spline_NurbsCurve_Spring_005, ms_area_2_spline_NurbsCurve_Spring_006, },
    { NULL, NULL, }
};

const SpringDesc* spring_descs_ms[] = {
    spring_ms_area1,
    spring_ms_area2,
    NULL,
};

#include "levels/ms/visual/model_lvl.inc.c"

#if 0
#include "levels/ms/leveldata.inc.c"
#else
#include "levels/ms/area_1/spline.inc.c"
#include "levels/ms/area_2/spline.inc.c"
#include "levels/ms/area_3/spline.inc.c"
#endif

#include "levels/ms/ms_skybox/model.inc.c"
#include "levels/ms/ms_buffer/model.inc.c"
#include "levels/ms/ms_buffer_break/model.inc.c"
#include "levels/ms/ms_hammer/model.inc.c"
#include "levels/ms/ms_hammer/collision.inc.c"
#include "levels/ms/ms_slane/collision.inc.c"
#include "levels/ms/ms_slane_break/model.inc.c"
#include "levels/ms/ms_slane/model.inc.c"