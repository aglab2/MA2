#include "flipbook.h"

ALIGNED8 u8 cce_visuals_ia16[] = {
    #include "levels/cce/dz_cc_64wave0001.ia16.inc.c"
    ,
    #include "levels/cce/dz_cc_64wave0002.ia16.inc.c"
    ,
    #include "levels/cce/dz_cc_64wave0003.ia16.inc.c"
    ,
    #include "levels/cce/dz_cc_64wave0004.ia16.inc.c"
    ,
    #include "levels/cce/dz_cc_64wave0005.ia16.inc.c"
    ,
    #include "levels/cce/dz_cc_64wave0006.ia16.inc.c"
    ,
    #include "levels/cce/dz_cc_64wave0007.ia16.inc.c"
    ,
    #include "levels/cce/dz_cc_64wave0008.ia16.inc.c"
    ,
    #include "levels/cce/dz_cc_64wave0009.ia16.inc.c"
    ,
    #include "levels/cce/dz_cc_64wave0010.ia16.inc.c"
    ,
    #include "levels/cce/dz_cc_64wave0011.ia16.inc.c"
    ,
    #include "levels/cce/dz_cc_64wave0012.ia16.inc.c"
    ,
    #include "levels/cce/dz_cc_64wave0013.ia16.inc.c"
    ,
    #include "levels/cce/dz_cc_64wave0014.ia16.inc.c"
    ,
    #include "levels/cce/dz_cc_64wave0015.ia16.inc.c"
};

ALIGNED8 u8 cce_matrix_ci4[] = {
    #include "levels/cce/miu128_cg0061.ci4.inc.c"
    #include "levels/cce/miu128_cg0062.ci4.inc.c"
    #include "levels/cce/miu128_cg0063.ci4.inc.c"
    #include "levels/cce/miu128_cg0064.ci4.inc.c"
};

ALIGNED8 u8 cce_matrix_pal[] = {
    #include "levels/cce/miu128_cg0061.ci4.pal"
    #include "levels/cce/miu128_cg0062.ci4.pal"
    #include "levels/cce/miu128_cg0063.ci4.pal"
    #include "levels/cce/miu128_cg0064.ci4.pal"
};

ALIGNED8 u8 cce_poisons_ci4[] = {
    #include "levels/cce/tx_ccpoison001.ci4.inc.c"
    #include "levels/cce/tx_ccpoison002.ci4.inc.c"
    #include "levels/cce/tx_ccpoison003.ci4.inc.c"
    #include "levels/cce/tx_ccpoison004.ci4.inc.c"
    #include "levels/cce/tx_ccpoison005.ci4.inc.c"
    #include "levels/cce/tx_ccpoison006.ci4.inc.c"
    #include "levels/cce/tx_ccpoison007.ci4.inc.c"
    #include "levels/cce/tx_ccpoison008.ci4.inc.c"
    #include "levels/cce/tx_ccpoison009.ci4.inc.c"
    #include "levels/cce/tx_ccpoison010.ci4.inc.c"
    #include "levels/cce/tx_ccpoison011.ci4.inc.c"
    #include "levels/cce/tx_ccpoison012.ci4.inc.c"
    #include "levels/cce/tx_ccpoison013.ci4.inc.c"
};

ALIGNED8 u8 cce_poisons_pal[] = {
    #include "levels/cce/tx_ccpoison001.ci4.pal"
    #include "levels/cce/tx_ccpoison002.ci4.pal"
    #include "levels/cce/tx_ccpoison003.ci4.pal"
    #include "levels/cce/tx_ccpoison004.ci4.pal"
    #include "levels/cce/tx_ccpoison005.ci4.pal"
    #include "levels/cce/tx_ccpoison006.ci4.pal"
    #include "levels/cce/tx_ccpoison007.ci4.pal"
    #include "levels/cce/tx_ccpoison008.ci4.pal"
    #include "levels/cce/tx_ccpoison009.ci4.pal"
    #include "levels/cce/tx_ccpoison010.ci4.pal"
    #include "levels/cce/tx_ccpoison011.ci4.pal"
    #include "levels/cce/tx_ccpoison012.ci4.pal"
    #include "levels/cce/tx_ccpoison013.ci4.pal"
};

static struct FlipbookData flipbooks_opaque[] = {
    { LVL_BATCH_LAYER_OPAQUE_CCE_DL_MIU128_CG006_PAL_RGBA16, .count=4, .frames=10, .tileScrollX=-5, .ci4s=cce_matrix_ci4, .pals=cce_matrix_pal },
    { LVL_BATCH_LAYER_OPAQUE_CCE_DL_ET64_1_PAL_RGBA16, .shading = 1 },
    { LVL_BATCH_LAYER_OPAQUE_CCE_DL_TX_CCPOISON001_PAL_RGBA16_COPY  , .count=13, .frames=2, .ci4s=cce_poisons_ci4, .pals=cce_poisons_pal },
};

static struct FlipbookData flipbooks_xlu[] = {
    { LVL_BATCH_LAYER_TRANSPARENT_CCE_DL_DZ_CC_64WAVE0001_001_IA16, .count=4, .frames=15, .tileScrollX=2, .ci4s = cce_visuals_ia16,  },
    { LVL_BATCH_LAYER_TRANSPARENT_CCE_DL_TX_CCPOISON001_PAL_RGBA16  , .count=13, .frames=2, .ci4s=cce_poisons_ci4, .pals=cce_poisons_pal },
};

const struct FlipbookLayer cce_flipbooks[LAYER_COUNT] = {
    [ LAYER_OPAQUE ]      = FLIPBOOK_LAYER_DECL(flipbooks_opaque),
    [ LAYER_TRANSPARENT ] = FLIPBOOK_LAYER_DECL(flipbooks_xlu),
};
