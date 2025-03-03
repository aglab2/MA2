#include "flipbook.h"

ALIGNED8 u8 ee_matrixs_ci4[] = {
    #include "levels/ee/tx_light001.ci4.inc.c"
    #include "levels/ee/tx_light002.ci4.inc.c"
    #include "levels/ee/tx_light003.ci4.inc.c"
    #include "levels/ee/tx_light004.ci4.inc.c"
    #include "levels/ee/tx_light005.ci4.inc.c"
};

ALIGNED8 u8 ee_matrixs_pal[] = {
    #include "levels/ee/tx_light001.ci4.pal"
    #include "levels/ee/tx_light002.ci4.pal"
    #include "levels/ee/tx_light003.ci4.pal"
    #include "levels/ee/tx_light004.ci4.pal"
    #include "levels/ee/tx_light005.ci4.pal"
};

ALIGNED8 u8 ee_poisons_ci4[] = {
    #include "levels/ee/tx_poison001.ci4.inc.c"
    #include "levels/ee/tx_poison002.ci4.inc.c"
    #include "levels/ee/tx_poison003.ci4.inc.c"
    #include "levels/ee/tx_poison004.ci4.inc.c"
    #include "levels/ee/tx_poison005.ci4.inc.c"
    #include "levels/ee/tx_poison006.ci4.inc.c"
    #include "levels/ee/tx_poison007.ci4.inc.c"
    #include "levels/ee/tx_poison008.ci4.inc.c"
    #include "levels/ee/tx_poison009.ci4.inc.c"
    #include "levels/ee/tx_poison010.ci4.inc.c"
    #include "levels/ee/tx_poison011.ci4.inc.c"
    #include "levels/ee/tx_poison012.ci4.inc.c"
    #include "levels/ee/tx_poison013.ci4.inc.c"
};

ALIGNED8 u8 ee_poisons_pal[] = {
    #include "levels/ee/tx_poison001.ci4.pal"
    #include "levels/ee/tx_poison002.ci4.pal"
    #include "levels/ee/tx_poison003.ci4.pal"
    #include "levels/ee/tx_poison004.ci4.pal"
    #include "levels/ee/tx_poison005.ci4.pal"
    #include "levels/ee/tx_poison006.ci4.pal"
    #include "levels/ee/tx_poison007.ci4.pal"
    #include "levels/ee/tx_poison008.ci4.pal"
    #include "levels/ee/tx_poison009.ci4.pal"
    #include "levels/ee/tx_poison010.ci4.pal"
    #include "levels/ee/tx_poison011.ci4.pal"
    #include "levels/ee/tx_poison012.ci4.pal"
    #include "levels/ee/tx_poison013.ci4.pal"
};

static struct FlipbookData flipbooks_opaque[] = {
    { LVL_BATCH_LAYER_OPAQUE_EE_DL_TX_LIGHT001_PAL_RGBA16, 5, 10, -2, 0, 0, ee_matrixs_ci4, ee_matrixs_pal },
    { LVL_BATCH_LAYER_OPAQUE_EE_DL_SPACENBG64_PAL_RGBA16, .tileScrollX = 1, }
};

static struct FlipbookData flipbooks_xlu[] = {
    { LVL_BATCH_LAYER_TRANSPARENT_EE_DL_TX_POISON001_PAL_RGBA16, 13, 2, 0, 0, 0, ee_poisons_ci4, ee_poisons_pal },
};

const struct FlipbookLayer ee_flipbooks[LAYER_COUNT] = {
    [ LAYER_OPAQUE ] = FLIPBOOK_LAYER_DECL(flipbooks_opaque),
    [ LAYER_TRANSPARENT ] = FLIPBOOK_LAYER_DECL(flipbooks_xlu),
};
