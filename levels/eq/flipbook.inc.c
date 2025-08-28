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
    { LVL_BATCH_LAYER_TRANSPARENT_DECAL_EQ_DL_DZ_EQ_TRI_IA16, .shading = 1, },
    { LVL_BATCH_LAYER_TRANSPARENT_DECAL_EQ_DL_DZ_EQ_TRI_IA16_1, .shading = 1, },
};

static struct FlipbookData flipbooks_xlu[] = {
    { LVL_BATCH_LAYER_ALPHA_EQ_DL_KD_EQ_AMI1_001_PAL_RGBA16, .ci4s = water_ci4, .pals = water_pal },
};

const struct FlipbookLayer eq_flipbooks[LAYER_COUNT] = {
    [ LAYER_OPAQUE_DECAL ] = FLIPBOOK_LAYER_DECL(flipbooks_opadec),
    [ LAYER_TRANSPARENT ] = FLIPBOOK_LAYER_DECL(flipbooks_xlu),
};
