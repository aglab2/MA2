#include "flipbook.h"

ALIGNED8 u8 ccr_lk_un1_ci4[] = {
    #include "levels/ccr/kd_lk_un101_0.ci4.inc.c"
    #include "levels/ccr/kd_lk_un101_1.ci4.inc.c"
    #include "levels/ccr/kd_lk_un101_2.ci4.inc.c"
    #include "levels/ccr/kd_lk_un101_3.ci4.inc.c"
    #include "levels/ccr/kd_lk_un101_4.ci4.inc.c"
    #include "levels/ccr/kd_lk_un101_5.ci4.inc.c"
    #include "levels/ccr/kd_lk_un101_6.ci4.inc.c"
    #include "levels/ccr/kd_lk_un101_7.ci4.inc.c"
    #include "levels/ccr/kd_lk_un101_8.ci4.inc.c"
    #include "levels/ccr/kd_lk_un101_9.ci4.inc.c"
    #include "levels/ccr/kd_lk_un101_10.ci4.inc.c"
    #include "levels/ccr/kd_lk_un101_11.ci4.inc.c"
    #include "levels/ccr/kd_lk_un101_12.ci4.inc.c"
    #include "levels/ccr/kd_lk_un101_13.ci4.inc.c"
    #include "levels/ccr/kd_lk_un101_14.ci4.inc.c"
    #include "levels/ccr/kd_lk_un101_15.ci4.inc.c"
};

ALIGNED8 u8 ccr_lk_un1_pal[] = {
    #include "levels/ccr/kd_lk_un101_0.ci4.pal"
    #include "levels/ccr/kd_lk_un101_1.ci4.pal"
    #include "levels/ccr/kd_lk_un101_2.ci4.pal"
    #include "levels/ccr/kd_lk_un101_3.ci4.pal"
    #include "levels/ccr/kd_lk_un101_4.ci4.pal"
    #include "levels/ccr/kd_lk_un101_5.ci4.pal"
    #include "levels/ccr/kd_lk_un101_6.ci4.pal"
    #include "levels/ccr/kd_lk_un101_7.ci4.pal"
    #include "levels/ccr/kd_lk_un101_8.ci4.pal"
    #include "levels/ccr/kd_lk_un101_9.ci4.pal"
    #include "levels/ccr/kd_lk_un101_10.ci4.pal"
    #include "levels/ccr/kd_lk_un101_11.ci4.pal"
    #include "levels/ccr/kd_lk_un101_12.ci4.pal"
    #include "levels/ccr/kd_lk_un101_13.ci4.pal"
    #include "levels/ccr/kd_lk_un101_14.ci4.pal"
    #include "levels/ccr/kd_lk_un101_15.ci4.pal"
};

static struct FlipbookData flipbooks_opaque[] = {
    { LVL_BATCH_LAYER_OPAQUE_CCR_DL_KD_LK_UN101_PAL_RGBA16, .count=15, .frames=2, .ci4s=ccr_lk_un1_ci4, .pals=ccr_lk_un1_pal },
};

static struct FlipbookData flipbooks_xlu[] = {
    // { LVL_BATCH_LAYER_TRANSPARENT_CCR_DL_KD_LK_UN114_PAL_RGBA16, .tileScrollX = 5, },
    { LVL_BATCH_LAYER_TRANSPARENT_CCR_DL_KD_LK_WATER3_RGBA32, .tileScrollY=-1,  },
    { LVL_BATCH_LAYER_TRANSPARENT_CCR_DL_KD_LK_WATER3_RGBA32_1, .tileScrollX=2,  },
    { LVL_BATCH_LAYER_TRANSPARENT_CCR_DL_KD_LK_WATER1_01_PAL_RGBA16, .tileScrollY=-2,  },
    { LVL_BATCH_LAYER_TRANSPARENT_CCR_DL_KD_LK_WATER1_01_PAL_RGBA16_1, .tileScrollY=-2,  },
    { LVL_BATCH_LAYER_TRANSPARENT_CCR_DL_KD_LK_WATER3_RGBA32_2, .tileScrollX=-2,  },
    { LVL_BATCH_LAYER_TRANSPARENT_CCR_DL_KD_LK_WATER3_RGBA32_3, .tileScrollX=-2,  },
};

const struct FlipbookLayer ccr_flipbooks[LAYER_COUNT] = {
    [ LAYER_OPAQUE ]      = FLIPBOOK_LAYER_DECL(flipbooks_opaque),
    [ LAYER_TRANSPARENT ] = FLIPBOOK_LAYER_DECL(flipbooks_xlu),
};
