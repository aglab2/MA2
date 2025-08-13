#include "flipbook.h"

ALIGNED8 u8 ccs_lk_un1_ci4[] = {
    #include "levels/ccs/kd_lk_un101_0.ci4.inc.c"
    #include "levels/ccs/kd_lk_un101_1.ci4.inc.c"
    #include "levels/ccs/kd_lk_un101_2.ci4.inc.c"
    #include "levels/ccs/kd_lk_un101_3.ci4.inc.c"
    #include "levels/ccs/kd_lk_un101_4.ci4.inc.c"
    #include "levels/ccs/kd_lk_un101_5.ci4.inc.c"
    #include "levels/ccs/kd_lk_un101_6.ci4.inc.c"
    #include "levels/ccs/kd_lk_un101_7.ci4.inc.c"
    #include "levels/ccs/kd_lk_un101_8.ci4.inc.c"
    #include "levels/ccs/kd_lk_un101_9.ci4.inc.c"
    #include "levels/ccs/kd_lk_un101_10.ci4.inc.c"
    #include "levels/ccs/kd_lk_un101_11.ci4.inc.c"
    #include "levels/ccs/kd_lk_un101_12.ci4.inc.c"
    #include "levels/ccs/kd_lk_un101_13.ci4.inc.c"
    #include "levels/ccs/kd_lk_un101_14.ci4.inc.c"
    #include "levels/ccs/kd_lk_un101_15.ci4.inc.c"
};

ALIGNED8 u8 ccs_lk_un1_pal[] = {
    #include "levels/ccs/kd_lk_un101_0.ci4.pal"
    #include "levels/ccs/kd_lk_un101_1.ci4.pal"
    #include "levels/ccs/kd_lk_un101_2.ci4.pal"
    #include "levels/ccs/kd_lk_un101_3.ci4.pal"
    #include "levels/ccs/kd_lk_un101_4.ci4.pal"
    #include "levels/ccs/kd_lk_un101_5.ci4.pal"
    #include "levels/ccs/kd_lk_un101_6.ci4.pal"
    #include "levels/ccs/kd_lk_un101_7.ci4.pal"
    #include "levels/ccs/kd_lk_un101_8.ci4.pal"
    #include "levels/ccs/kd_lk_un101_9.ci4.pal"
    #include "levels/ccs/kd_lk_un101_10.ci4.pal"
    #include "levels/ccs/kd_lk_un101_11.ci4.pal"
    #include "levels/ccs/kd_lk_un101_12.ci4.pal"
    #include "levels/ccs/kd_lk_un101_13.ci4.pal"
    #include "levels/ccs/kd_lk_un101_14.ci4.pal"
    #include "levels/ccs/kd_lk_un101_15.ci4.pal"
};

ALIGNED8 u8 ccs_lk_un114_rgba32[] = {
    #include "levels/ccs/kd_lk_un114_0.rgba32.inc.c"
    ,
    #include "levels/ccs/kd_lk_un114_1.rgba32.inc.c"
    ,
    #include "levels/ccs/kd_lk_un114_2.rgba32.inc.c"
    ,
    #include "levels/ccs/kd_lk_un114_3.rgba32.inc.c"
    ,
    #include "levels/ccs/kd_lk_un114_4.rgba32.inc.c"
    ,
    #include "levels/ccs/kd_lk_un114_5.rgba32.inc.c"
    ,
    #include "levels/ccs/kd_lk_un114_6.rgba32.inc.c"
    ,
    #include "levels/ccs/kd_lk_un114_7.rgba32.inc.c"
    ,
    #include "levels/ccs/kd_lk_un114_8.rgba32.inc.c"
    ,
    #include "levels/ccs/kd_lk_un114_9.rgba32.inc.c"
    ,
    #include "levels/ccs/kd_lk_un114_10.rgba32.inc.c"
    ,
    #include "levels/ccs/kd_lk_un114_11.rgba32.inc.c"
    ,
    #include "levels/ccs/kd_lk_un114_12.rgba32.inc.c"
    ,
    #include "levels/ccs/kd_lk_un114_13.rgba32.inc.c"
    ,
    #include "levels/ccs/kd_lk_un114_14.rgba32.inc.c"
    ,
    #include "levels/ccs/kd_lk_un114_15.rgba32.inc.c"
};

ALIGNED8 u8 ccs_ls_gc801_rgba16[] = {
    #include "levels/ccs/kd_ls_gc801_0.rgba16.inc.c"
    ,
    #include "levels/ccs/kd_ls_gc801_1.rgba16.inc.c"
    ,
    #include "levels/ccs/kd_ls_gc801_2.rgba16.inc.c"
    ,
    #include "levels/ccs/kd_ls_gc801_3.rgba16.inc.c"
    ,
    #include "levels/ccs/kd_ls_gc801_4.rgba16.inc.c"
    ,
    #include "levels/ccs/kd_ls_gc801_5.rgba16.inc.c"
    ,
    #include "levels/ccs/kd_ls_gc801_6.rgba16.inc.c"
    ,
    #include "levels/ccs/kd_ls_gc801_7.rgba16.inc.c"
    ,
    #include "levels/ccs/kd_ls_gc801_8.rgba16.inc.c"
    ,
    #include "levels/ccs/kd_ls_gc801_9.rgba16.inc.c"
    ,
    #include "levels/ccs/kd_ls_gc801_10.rgba16.inc.c"
    ,
    #include "levels/ccs/kd_ls_gc801_11.rgba16.inc.c"
    ,
    #include "levels/ccs/kd_ls_gc801_12.rgba16.inc.c"
    ,
    #include "levels/ccs/kd_ls_gc801_13.rgba16.inc.c"
    ,
    #include "levels/ccs/kd_ls_gc801_14.rgba16.inc.c"
    ,
    #include "levels/ccs/kd_ls_gc801_15.rgba16.inc.c"
};

static struct FlipbookData flipbooks_opaque[] = {
    { LVL_BATCH_LAYER_OPAQUE_CCS_DL_KD_LK_UN101_PAL_RGBA16, .count=15, .frames=2, .ci4s=ccs_lk_un1_ci4, .pals=ccs_lk_un1_pal },
    { LVL_BATCH_LAYER_OPAQUE_CCS_DL_KD_LK_UN101_PAL_RGBA16_1, .count=15, .frames=2, .ci4s=ccs_lk_un1_ci4, .pals=ccs_lk_un1_pal },
};

static struct FlipbookData flipbooks_xlu[] = {
    { LVL_BATCH_LAYER_TRANSPARENT_CCS_DL_KD_LK_WATER1_01_PAL_RGBA16, .tileScrollX=2,  },
    { LVL_BATCH_LAYER_TRANSPARENT_CCS_DL_KD_LS_WATER1_001_PAL_RGBA16, .tileScrollX=2,  },
    { LVL_BATCH_LAYER_TRANSPARENT_CCS_DL_KD_LK_WATER1_01_PAL_RGBA16_1, .tileScrollY=2,  },
    { LVL_BATCH_LAYER_TRANSPARENT_CCS_DL_KD_LS_WATER1_001_PAL_RGBA16_1, .tileScrollX=2,  },
    { LVL_BATCH_LAYER_TRANSPARENT_CCS_DL_KD_LS_WATER1_001_PAL_RGBA16_2, .tileScrollX=2,  },

    { LVL_BATCH_LAYER_TRANSPARENT_CCS_DL_KD_LK_UN114_RGBA32, .ci4s = ccs_lk_un114_rgba32, .count=16, .frames=2,  },
    { LVL_BATCH_LAYER_TRANSPARENT_CCS_DL_KD_LK_UN114_RGBA32_1, .ci4s = ccs_lk_un114_rgba32, .count=16, .frames=2,  },

    { LVL_BATCH_LAYER_TRANSPARENT_CCS_DL_TILE_0_0_RGBA16, .ci4s = ccs_ls_gc801_rgba16, .count = 16, .frames = 2, },
};

const struct FlipbookLayer ccs_flipbooks[LAYER_COUNT] = {
    [ LAYER_OPAQUE ]      = FLIPBOOK_LAYER_DECL(flipbooks_opaque),
    [ LAYER_TRANSPARENT ] = FLIPBOOK_LAYER_DECL(flipbooks_xlu),
};
