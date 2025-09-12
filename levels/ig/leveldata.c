#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"
#include "instant_warp_desc.h"
#include "spring_desc.h"

#include "make_const_nonconst.h"

#include "levels/ig/visual/header_lvl.inc.h"

static IWDirectionAreasDesc iw_area1 = {
    { IWDT_DIRECTIONS },
    { .x_high = 2, },
};

static IWDirectionAreasDesc iw_area2 = {
    { IWDT_DIRECTIONS },
    { .x_low = 1, },
};

IWDHeader* iw_descs_ig[] = {
    &iw_area1.header,
    &iw_area2.header,
};

#if 0
#include "levels/ig/leveldata.inc.c"
#else
#include "levels/ig/area_1/spline.inc.c"
#include "levels/ig/area_2/spline.inc.c"
#include "levels/ig/visual/model_lvlopt.inc.c"
#include "levels/ig/rails.inc.c"
#endif

#include "levels/ig/ig_bombe/model.inc.c"
#include "levels/ig/ig_bomb_break/model.inc.c"
#include "levels/ig/ig_lift/model.inc.c"
#include "levels/ig/ig_lift/collision.inc.c"
#include "levels/ig/ig_shelt/model.inc.c"
#include "levels/ig/ig_siren/model.inc.c"
#include "levels/ig/ig_shelt/collision.inc.c"
#include "levels/ig/ig_sdoor/collision.inc.c"
#include "levels/ig/ig_sdoor/model.inc.c"