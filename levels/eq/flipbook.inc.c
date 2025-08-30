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

static struct FlipbookData flipbooks_opa[] = {
    { LVL_BATCH_LAYER_OPAQUE_EQ_DL_KD_EQ_OTHER5_PAL_RGBA16, .tileScrollX = 8, },
};

static struct FlipbookData flipbooks_opadec[] = {
    { LVL_BATCH_LAYER_TRANSPARENT_DECAL_EQ_DL_DZ_EQ_TRI_IA16, .shading = 1, },
};

static struct FlipbookData flipbooks_xlu[] = {
    { LVL_BATCH_LAYER_TRANSPARENT_EQ_DL_KD_EQ_WATER01_PAL_RGBA16, .ci4s = water_ci4, .pals = water_pal, .tileScrollX = 1 },
    { LVL_BATCH_LAYER_TRANSPARENT_EQ_DL_KD_EQ_HASIRA92_PAL_RGBA16, .shading = 1000, },
};

const struct FlipbookLayer eq_flipbooks[LAYER_COUNT] = {
    [ LAYER_OPAQUE ] = FLIPBOOK_LAYER_DECL(flipbooks_opa),
    [ LAYER_TRANSPARENT_DECAL ] = FLIPBOOK_LAYER_DECL(flipbooks_opadec),
    [ LAYER_TRANSPARENT ] = FLIPBOOK_LAYER_DECL(flipbooks_xlu),
};
