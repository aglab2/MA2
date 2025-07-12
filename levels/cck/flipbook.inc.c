#include "flipbook.h"

ALIGNED8 u8 cck_lk_un1_ci4[] = {
    #include "levels/cck/kd_lk_un207_0.ci4.inc.c"
    #include "levels/cck/kd_lk_un207_1.ci4.inc.c"
    #include "levels/cck/kd_lk_un207_2.ci4.inc.c"
    #include "levels/cck/kd_lk_un207_3.ci4.inc.c"
    #include "levels/cck/kd_lk_un207_4.ci4.inc.c"
    #include "levels/cck/kd_lk_un207_5.ci4.inc.c"
    #include "levels/cck/kd_lk_un207_6.ci4.inc.c"
    #include "levels/cck/kd_lk_un207_7.ci4.inc.c"
    #include "levels/cck/kd_lk_un207_8.ci4.inc.c"
    #include "levels/cck/kd_lk_un207_9.ci4.inc.c"
    #include "levels/cck/kd_lk_un207_10.ci4.inc.c"
    #include "levels/cck/kd_lk_un207_11.ci4.inc.c"
    #include "levels/cck/kd_lk_un207_12.ci4.inc.c"
    #include "levels/cck/kd_lk_un207_13.ci4.inc.c"
    #include "levels/cck/kd_lk_un207_14.ci4.inc.c"
    #include "levels/cck/kd_lk_un207_15.ci4.inc.c"
};

ALIGNED8 u8 cck_lk_un1_pal[] = {
    #include "levels/cck/kd_lk_un207_0.ci4.pal"
    #include "levels/cck/kd_lk_un207_1.ci4.pal"
    #include "levels/cck/kd_lk_un207_2.ci4.pal"
    #include "levels/cck/kd_lk_un207_3.ci4.pal"
    #include "levels/cck/kd_lk_un207_4.ci4.pal"
    #include "levels/cck/kd_lk_un207_5.ci4.pal"
    #include "levels/cck/kd_lk_un207_6.ci4.pal"
    #include "levels/cck/kd_lk_un207_7.ci4.pal"
    #include "levels/cck/kd_lk_un207_8.ci4.pal"
    #include "levels/cck/kd_lk_un207_9.ci4.pal"
    #include "levels/cck/kd_lk_un207_10.ci4.pal"
    #include "levels/cck/kd_lk_un207_11.ci4.pal"
    #include "levels/cck/kd_lk_un207_12.ci4.pal"
    #include "levels/cck/kd_lk_un207_13.ci4.pal"
    #include "levels/cck/kd_lk_un207_14.ci4.pal"
    #include "levels/cck/kd_lk_un207_15.ci4.pal"
};

ALIGNED8 u8 cck_lk_un114_rgba32[] = {
    #include "levels/cck/kd_lk_un114_0.rgba32.inc.c"
    ,
    #include "levels/cck/kd_lk_un114_1.rgba32.inc.c"
    ,
    #include "levels/cck/kd_lk_un114_2.rgba32.inc.c"
    ,
    #include "levels/cck/kd_lk_un114_3.rgba32.inc.c"
    ,
    #include "levels/cck/kd_lk_un114_4.rgba32.inc.c"
    ,
    #include "levels/cck/kd_lk_un114_5.rgba32.inc.c"
    ,
    #include "levels/cck/kd_lk_un114_6.rgba32.inc.c"
    ,
    #include "levels/cck/kd_lk_un114_7.rgba32.inc.c"
    ,
    #include "levels/cck/kd_lk_un114_8.rgba32.inc.c"
    ,
    #include "levels/cck/kd_lk_un114_9.rgba32.inc.c"
    ,
    #include "levels/cck/kd_lk_un114_10.rgba32.inc.c"
    ,
    #include "levels/cck/kd_lk_un114_11.rgba32.inc.c"
    ,
    #include "levels/cck/kd_lk_un114_12.rgba32.inc.c"
    ,
    #include "levels/cck/kd_lk_un114_13.rgba32.inc.c"
    ,
    #include "levels/cck/kd_lk_un114_14.rgba32.inc.c"
    ,
    #include "levels/cck/kd_lk_un114_15.rgba32.inc.c"
};

static struct FlipbookData flipbooks_opaque[] = {
    { LVL_BATCH_LAYER_OPAQUE_CCK_DL_KD_LK_UN207_PAL_RGBA16, .count=15, .frames=2, .ci4s=cck_lk_un1_ci4, .pals=cck_lk_un1_pal },
};

static struct FlipbookData flipbooks_xlu[] = {
    // { LVL_BATCH_LAYER_TRANSPARENT_CCR_DL_KD_LK_UN114_PAL_RGBA16, .tileScrollX = 5, },
    { LVL_BATCH_LAYER_TRANSPARENT_CCK_DL_KD_LK_WATER1_01_PAL_RGBA16, .tileScrollX=2,  },

    { LVL_BATCH_LAYER_TRANSPARENT_CCK_DL_KD_LK_UN114_PAL_RGBA16, .ci4s = cck_lk_un114_rgba32, .count=15, .frames=2,  },
    { LVL_BATCH_LAYER_TRANSPARENT_CCK_DL_KD_LK_UN114_PAL_RGBA16_1, .ci4s = cck_lk_un114_rgba32, .count=15, .frames=2,  },
};

const struct FlipbookLayer cck_flipbooks[LAYER_COUNT] = {
    [ LAYER_OPAQUE ]      = FLIPBOOK_LAYER_DECL(flipbooks_opaque),
    [ LAYER_TRANSPARENT ] = FLIPBOOK_LAYER_DECL(flipbooks_xlu),
};
