#include "flipbook.h"

static ALIGNED8 u8 waters_ci4[] = {
    #include "levels/gh/greenhillwt128_0.ci4.inc.c"
    #include "levels/gh/greenhillwt128_1.ci4.inc.c"
    #include "levels/gh/greenhillwt128_2.ci4.inc.c"
    #include "levels/gh/greenhillwt128_3.ci4.inc.c"
    #include "levels/gh/greenhillwt128_4.ci4.inc.c"
};

static ALIGNED8 u8 waters_pal[] = {
    #include "levels/gh/greenhillwt128_0.ci4.pal"
    #include "levels/gh/greenhillwt128_1.ci4.pal"
    #include "levels/gh/greenhillwt128_2.ci4.pal"
    #include "levels/gh/greenhillwt128_3.ci4.pal"
    #include "levels/gh/greenhillwt128_4.ci4.pal"
};

static struct FlipbookData flipbooks_opa[] = {
    { LVL_BATCH_LAYER_OPAQUE_GH_DL_GREENHILLWT128_0_PAL_RGBA16, 5, 3, 0, 0, 0, waters_ci4, waters_pal },
};

const struct FlipbookLayer gh_flipbooks[LAYER_COUNT] = {
    [ LAYER_OPAQUE ] = FLIPBOOK_LAYER_DECL(flipbooks_opa),
};
