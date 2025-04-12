#include "flipbook.h"

static ALIGNED8 u8 water_ci4[] = {
    #include "levels/eq/kd_eq_water01.ci4.inc.c"
    #include "levels/eq/kd_eq_water02.ci4.inc.c"
    #include "levels/eq/kd_eq_water03.ci4.inc.c"
    #include "levels/eq/kd_eq_water04.ci4.inc.c"
    #include "levels/eq/kd_eq_water05.ci4.inc.c"
    #include "levels/eq/kd_eq_water06.ci4.inc.c"
    #include "levels/eq/kd_eq_water07.ci4.inc.c"
    #include "levels/eq/kd_eq_water08.ci4.inc.c"
    #include "levels/eq/kd_eq_water09.ci4.inc.c"
    #include "levels/eq/kd_eq_water10.ci4.inc.c"
    #include "levels/eq/kd_eq_water11.ci4.inc.c"
    #include "levels/eq/kd_eq_water12.ci4.inc.c"
    #include "levels/eq/kd_eq_water13.ci4.inc.c"
    #include "levels/eq/kd_eq_water14.ci4.inc.c"
};

static ALIGNED8 u8 water_pal[] = {
    #include "levels/eq/kd_eq_water01.ci4.pal"
    #include "levels/eq/kd_eq_water02.ci4.pal"
    #include "levels/eq/kd_eq_water03.ci4.pal"
    #include "levels/eq/kd_eq_water04.ci4.pal"
    #include "levels/eq/kd_eq_water05.ci4.pal"
    #include "levels/eq/kd_eq_water06.ci4.pal"
    #include "levels/eq/kd_eq_water07.ci4.pal"
    #include "levels/eq/kd_eq_water08.ci4.pal"
    #include "levels/eq/kd_eq_water09.ci4.pal"
    #include "levels/eq/kd_eq_water10.ci4.pal"
    #include "levels/eq/kd_eq_water11.ci4.pal"
    #include "levels/eq/kd_eq_water12.ci4.pal"
    #include "levels/eq/kd_eq_water13.ci4.pal"
    #include "levels/eq/kd_eq_water14.ci4.pal"
};

static struct FlipbookData flipbooks_opadec[] = {
    { LVL_BATCH_LAYER_OPAQUE_DECAL_EQ_DL_DZ_EQ_TRI_PAL_RGBA16, .shading = 1, },
};

const struct FlipbookLayer eq_flipbooks[LAYER_COUNT] = {
    [ LAYER_OPAQUE_DECAL ] = FLIPBOOK_LAYER_DECL(flipbooks_opadec),
};
