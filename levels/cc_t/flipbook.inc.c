#include "flipbook.h"

ALIGNED8 u8 cc_t_visuals_ia16[] = {
    #include "levels/cc_t/dz_cc_64wave0001.ia16.inc.c"
    #include "levels/cc_t/dz_cc_64wave0002.ia16.inc.c"
    #include "levels/cc_t/dz_cc_64wave0003.ia16.inc.c"
    #include "levels/cc_t/dz_cc_64wave0004.ia16.inc.c"
    #include "levels/cc_t/dz_cc_64wave0005.ia16.inc.c"
    #include "levels/cc_t/dz_cc_64wave0006.ia16.inc.c"
    #include "levels/cc_t/dz_cc_64wave0007.ia16.inc.c"
    #include "levels/cc_t/dz_cc_64wave0008.ia16.inc.c"
    #include "levels/cc_t/dz_cc_64wave0009.ia16.inc.c"
    #include "levels/cc_t/dz_cc_64wave0010.ia16.inc.c"
    #include "levels/cc_t/dz_cc_64wave0011.ia16.inc.c"
    #include "levels/cc_t/dz_cc_64wave0012.ia16.inc.c"
    #include "levels/cc_t/dz_cc_64wave0013.ia16.inc.c"
    #include "levels/cc_t/dz_cc_64wave0014.ia16.inc.c"
    #include "levels/cc_t/dz_cc_64wave0015.ia16.inc.c"
};

ALIGNED8 u8 cc_t_matrix_ci4[] = {
    #include "levels/cc_t/miu128_cg0061.ci4.inc.c"
    #include "levels/cc_t/miu128_cg0062.ci4.inc.c"
    #include "levels/cc_t/miu128_cg0063.ci4.inc.c"
    #include "levels/cc_t/miu128_cg0064.ci4.inc.c"
};

ALIGNED8 u8 cc_t_matrix_pal[] = {
    #include "levels/cc_t/miu128_cg0061.ci4.inc.c"
    #include "levels/cc_t/miu128_cg0062.ci4.inc.c"
    #include "levels/cc_t/miu128_cg0063.ci4.inc.c"
    #include "levels/cc_t/miu128_cg0064.ci4.inc.c"
};

static struct FlipbookData flipbooks_opaque[] = {
    { LVL_BATCH_LAYER_OPAQUE_CC_T_DL_MIU128_CG006_PAL_RGBA16, .count=4, .frames=10, .tileScrollX=-5, .ci4s=cc_t_matrix_ci4, .pals=cc_t_matrix_pal },
};

const struct FlipbookLayer cc_t_flipbooks[LAYER_COUNT] = {
    [ LAYER_OPAQUE ] = FLIPBOOK_LAYER_DECL(flipbooks_opaque),
};
