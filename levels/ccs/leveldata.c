#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"
#include "instant_warp_desc.h"

#include "make_const_nonconst.h"

#if 0
#include "levels/ccs/leveldata.inc.c"
#else
#include "levels/ccs/visual/header_lvlopt.inc.h"
#include "levels/ccs/visual/model_lvlopt.inc.c"
#include "levels/ccs/flipbook.inc.c"
#endif

#include "levels/ccs/ccs_block/collision.inc.c"
#include "levels/ccs/ccs_block/model.inc.c"
#include "levels/ccs/ccs_shutter_left/collision.inc.c"
#include "levels/ccs/ccs_shutter_left/model.inc.c"
#include "levels/ccs/ccs_shutter_right/collision.inc.c"
#include "levels/ccs/ccs_shutter_right/model.inc.c"
#include "levels/ccs/ccs_switch/collision.inc.c"
#include "levels/ccs/ccs_switch/model.inc.c"

static IWDirectionAreasDesc iw_ccs_area1 = {
    { IWDT_DIRECTIONS },
    { .z_low = 2, },
};

static IWDirectionAreasDesc iw_ccs_area2 = {
    { IWDT_DIRECTIONS },
    { .z_high = 1 },
};

const IWDHeader* iw_descs_ccs[] = {
    &iw_ccs_area1.header,
    &iw_ccs_area2.header,
};