#include "flipbook.h"

static ALIGNED8 u8 mizu_ci4[] = {
    #include "levels/dl/kd_dl_mizu_001.ci4.inc.c"
    #include "levels/dl/kd_dl_mizu_002.ci4.inc.c"
    #include "levels/dl/kd_dl_mizu_003.ci4.inc.c"
    #include "levels/dl/kd_dl_mizu_004.ci4.inc.c"
    #include "levels/dl/kd_dl_mizu_005.ci4.inc.c"
    #include "levels/dl/kd_dl_mizu_006.ci4.inc.c"
    #include "levels/dl/kd_dl_mizu_007.ci4.inc.c"
    #include "levels/dl/kd_dl_mizu_008.ci4.inc.c"
    #include "levels/dl/kd_dl_mizu_009.ci4.inc.c"
    #include "levels/dl/kd_dl_mizu_010.ci4.inc.c"
    #include "levels/dl/kd_dl_mizu_011.ci4.inc.c"
    #include "levels/dl/kd_dl_mizu_012.ci4.inc.c"
    #include "levels/dl/kd_dl_mizu_013.ci4.inc.c"
    #include "levels/dl/kd_dl_mizu_014.ci4.inc.c"
};

static ALIGNED8 u8 mizu_pal[] = {
    #include "levels/dl/kd_dl_mizu_001.ci4.pal"
    #include "levels/dl/kd_dl_mizu_002.ci4.pal"
    #include "levels/dl/kd_dl_mizu_003.ci4.pal"
    #include "levels/dl/kd_dl_mizu_004.ci4.pal"
    #include "levels/dl/kd_dl_mizu_005.ci4.pal"
    #include "levels/dl/kd_dl_mizu_006.ci4.pal"
    #include "levels/dl/kd_dl_mizu_007.ci4.pal"
    #include "levels/dl/kd_dl_mizu_008.ci4.pal"
    #include "levels/dl/kd_dl_mizu_009.ci4.pal"
    #include "levels/dl/kd_dl_mizu_010.ci4.pal"
    #include "levels/dl/kd_dl_mizu_011.ci4.pal"
    #include "levels/dl/kd_dl_mizu_012.ci4.pal"
    #include "levels/dl/kd_dl_mizu_013.ci4.pal"
    #include "levels/dl/kd_dl_mizu_014.ci4.pal"
};

static ALIGNED8 u8 mizu2[] = {
    #include "levels/dl/kd_dl_mizu2_001.rgba32.inc.c"
    ,
    #include "levels/dl/kd_dl_mizu2_002.rgba32.inc.c"
    ,
    #include "levels/dl/kd_dl_mizu2_003.rgba32.inc.c"
    ,
    #include "levels/dl/kd_dl_mizu2_004.rgba32.inc.c"
    ,
    #include "levels/dl/kd_dl_mizu2_005.rgba32.inc.c"
    ,
    #include "levels/dl/kd_dl_mizu2_006.rgba32.inc.c"
    ,
    #include "levels/dl/kd_dl_mizu2_007.rgba32.inc.c"
    ,
    #include "levels/dl/kd_dl_mizu2_008.rgba32.inc.c"
    ,
    #include "levels/dl/kd_dl_mizu2_009.rgba32.inc.c"
    ,
    #include "levels/dl/kd_dl_mizu2_010.rgba32.inc.c"
    ,
    #include "levels/dl/kd_dl_mizu2_011.rgba32.inc.c"
    ,
    #include "levels/dl/kd_dl_mizu2_012.rgba32.inc.c"
    ,
    #include "levels/dl/kd_dl_mizu2_013.rgba32.inc.c"
    ,
    #include "levels/dl/kd_dl_mizu2_014.rgba32.inc.c"
};

static ALIGNED8 u8 water[] = {
    #include "levels/dl/dz_dl_water256a.rgba32.inc.c"
    ,
    #include "levels/dl/dz_dl_water256b.rgba32.inc.c"
    ,
    #include "levels/dl/dz_dl_water256c.rgba32.inc.c"
    ,
    #include "levels/dl/dz_dl_water256d.rgba32.inc.c"
};

static struct FlipbookData flipbooks_xlu[] = {
    { LVL_BATCH_LAYER_TRANSPARENT_DL_DL_KD_DL_MIZU_001_PAL_RGBA16, 14, 2, .ci4s=mizu_ci4, .pals=mizu_pal, },
    { LVL_BATCH_LAYER_TRANSPARENT_DL_DL_KD_DL_MIZU_001_PAL_RGBA16_1, 14, 2, .ci4s=mizu_ci4, .pals=mizu_pal, },
    { LVL_BATCH_LAYER_TRANSPARENT_DL_DL_KD_DL_MIZU2_001_RGBA32, 14, 8, .ci4s=mizu2, .tileScrollY = 1  },
    { LVL_BATCH_LAYER_TRANSPARENT_DL_DL_DZ_DL_WATER256A_RGBA32, 4, 4, .ci4s=water, .tileScrollX = 2 },
};

const struct FlipbookLayer dl_flipbooks[LAYER_COUNT] = {
    [ LAYER_TRANSPARENT ] = FLIPBOOK_LAYER_DECL(flipbooks_xlu),
};
