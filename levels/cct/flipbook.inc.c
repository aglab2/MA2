#include "flipbook.h"

ALIGNED8 u8 cct_visuals_ia16[] = {
    #include "levels/cct/dz_cc_64wave0001.ia16.inc.c"
    ,
    #include "levels/cct/dz_cc_64wave0002.ia16.inc.c"
    ,
    #include "levels/cct/dz_cc_64wave0003.ia16.inc.c"
    ,
    #include "levels/cct/dz_cc_64wave0004.ia16.inc.c"
    ,
    #include "levels/cct/dz_cc_64wave0005.ia16.inc.c"
    ,
    #include "levels/cct/dz_cc_64wave0006.ia16.inc.c"
    ,
    #include "levels/cct/dz_cc_64wave0007.ia16.inc.c"
    ,
    #include "levels/cct/dz_cc_64wave0008.ia16.inc.c"
    ,
    #include "levels/cct/dz_cc_64wave0009.ia16.inc.c"
    ,
    #include "levels/cct/dz_cc_64wave0010.ia16.inc.c"
    ,
    #include "levels/cct/dz_cc_64wave0011.ia16.inc.c"
    ,
    #include "levels/cct/dz_cc_64wave0012.ia16.inc.c"
    ,
    #include "levels/cct/dz_cc_64wave0013.ia16.inc.c"
    ,
    #include "levels/cct/dz_cc_64wave0014.ia16.inc.c"
    ,
    #include "levels/cct/dz_cc_64wave0015.ia16.inc.c"
};

ALIGNED8 u8 cct_matrix_ci4[] = {
    #include "levels/cct/miu128_cg0061.ci4.inc.c"
    #include "levels/cct/miu128_cg0062.ci4.inc.c"
    #include "levels/cct/miu128_cg0063.ci4.inc.c"
    #include "levels/cct/miu128_cg0064.ci4.inc.c"
};

ALIGNED8 u8 cct_matrix_pal[] = {
    #include "levels/cct/miu128_cg0061.ci4.pal"
    #include "levels/cct/miu128_cg0062.ci4.pal"
    #include "levels/cct/miu128_cg0063.ci4.pal"
    #include "levels/cct/miu128_cg0064.ci4.pal"
};

static struct FlipbookData flipbooks_opaque[] = {
    { LVL_BATCH_LAYER_OPAQUE_CCT_DL_MIU128_CG006_PAL_RGBA16, .count=4, .frames=10, .tileScrollX=-5, .ci4s=cct_matrix_ci4, .pals=cct_matrix_pal },
};

static struct FlipbookData flipbooks_xlu[] = {
    { LVL_BATCH_LAYER_TRANSPARENT_CCT_DL_DZ_CC_64WAVE0001_001_IA16, .count=4, .frames=15, .tileScrollX=2, .ci4s = cct_visuals_ia16,  },
};

const struct FlipbookLayer cct_flipbooks[LAYER_COUNT] = {
    [ LAYER_OPAQUE ]      = FLIPBOOK_LAYER_DECL(flipbooks_opaque),
    [ LAYER_TRANSPARENT ] = FLIPBOOK_LAYER_DECL(flipbooks_xlu),
};
