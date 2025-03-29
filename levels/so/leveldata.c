#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"

#include "make_const_nonconst.h"
#include "instant_warp_desc.h"

#if 0
#include "levels/so/leveldata.inc.c"
#else
#include "levels/so/visual/header_lvl.inc.h"
#include "levels/so/visual/model_lvl.inc.c"
#endif

static IWDirectionAreasDesc iw_area1 = {
    { IWDT_DIRECTIONS },
    { .z_low = 2, },
};

static IWDirectionAreasDesc iw_area2 = {
    { IWDT_DIRECTIONS },
    { .z_high = 1, },
};

IWDHeader* iw_descs_so[] = {
    &iw_area1.header,
    &iw_area2.header,
};

#include "levels/so/so_skybox/model.inc.c"