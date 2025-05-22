#include "flipbook.h"

static ALIGNED8 u8 fc_anim_ci4[] = {
    #include "levels/fc/miu64_fcanime01.ci4.inc.c"
    #include "levels/fc/miu64_fcanime02.ci4.inc.c"
    #include "levels/fc/miu64_fcanime03.ci4.inc.c"
    #include "levels/fc/miu64_fcanime04.ci4.inc.c"
    #include "levels/fc/miu64_fcanime05.ci4.inc.c"
    #include "levels/fc/miu64_fcanime06.ci4.inc.c"
    #include "levels/fc/miu64_fcanime07.ci4.inc.c"
    #include "levels/fc/miu64_fcanime08.ci4.inc.c"
};

static ALIGNED8 u8 fc_anim_pal[] = {
    #include "levels/fc/miu64_fcanime01.ci4.pal"
    #include "levels/fc/miu64_fcanime02.ci4.pal"
    #include "levels/fc/miu64_fcanime03.ci4.pal"
    #include "levels/fc/miu64_fcanime04.ci4.pal"
    #include "levels/fc/miu64_fcanime05.ci4.pal"
    #include "levels/fc/miu64_fcanime06.ci4.pal"
    #include "levels/fc/miu64_fcanime07.ci4.pal"
    #include "levels/fc/miu64_fcanime08.ci4.pal"
};

static struct FlipbookData flipbooks_opaque[] = {
    { LVL_BATCH_LAYER_OPAQUE_FC_DL_SPACE64_5_PAL_RGBA16, .tileScrollY = -32, },
    { LVL_BATCH_LAYER_OPAQUE_FC_DL_SPACE64_5_PAL_RGBA16_1, .tileScrollY = -32, },
    { LVL_BATCH_LAYER_OPAQUE_FC_DL_MIU64_FCANIME01_PAL_RGBA16, .count = 8, .frames = 2, .ci4s = fc_anim_ci4, .pals = fc_anim_pal },
    /*
    { LVL_BATCH_LAYER_OPAQUE_FR_DL_SPACE64_1_PAL_RGBA16_1, .tileScrollY = -32, },
    { LVL_BATCH_LAYER_OPAQUE_FR_DL_SPACE64_1_PAL_RGBA16_2, .tileScrollY = -32, },
    { LVL_BATCH_LAYER_OPAQUE_FR_DL_SPACE64_1_PAL_RGBA16_3, .tileScrollY = -32, },
    
    { LVL_BATCH_LAYER_OPAQUE_FR_DL_SPACE64_13_PAL_RGBA16, .tileScrollY = -32, },
    { LVL_BATCH_LAYER_OPAQUE_FR_DL_SPACE64_13_PAL_RGBA16_1, .tileScrollY = -32, },
    
    { LVL_BATCH_LAYER_OPAQUE_FR_DL_SPACE64_5_PAL_RGBA16, .tileScrollY = -32, },
    { LVL_BATCH_LAYER_OPAQUE_FR_DL_SPACE64_5_PAL_RGBA16_1, .tileScrollY = -32, },
    
    { LVL_BATCH_LAYER_OPAQUE_FR_DL_SPACE64_12_PAL_RGBA16, .tileScrollY = -32, },
    { LVL_BATCH_LAYER_OPAQUE_FR_DL_SPACE64_12_PAL_RGBA16_1, .tileScrollY = -32, },
    
    { LVL_BATCH_LAYER_OPAQUE_FR_DL_SPACE64_16_PAL_RGBA16, .tileScrollX = -8, },
    
    // { LVL_BATCH_LAYER_OPAQUE_FR_DL_SPACE64_6_PAL_RGBA16, .tileScrollX = -8, },
    { LVL_BATCH_LAYER_OPAQUE_FR_DL_SPACE64_6_PAL_RGBA16_1, .tileScrollY = -8, },
    
    { LVL_BATCH_LAYER_OPAQUE_FR_DL_SPACE64_4_PAL_RGBA16, .tileScrollY = -8, },
    { LVL_BATCH_LAYER_OPAQUE_FR_DL_SPACE64_8_PAL_RGBA16, .tileScrollY = -8, },

    { LVL_BATCH_LAYER_OPAQUE_FR_DL_MIU32_FR001_PAL_RGBA16, .tileScrollY = -8, },

    { LVL_BATCH_LAYER_OPAQUE_FR_DL_SPACE64_20_PAL_RGBA16, .shading = 1 },
    { LVL_BATCH_LAYER_OPAQUE_FR_DL_SPACE32_3_RGBA16, .shading = 1 },

    { LVL_BATCH_LAYER_OPAQUE_FR_DL_SPACE64_2_PAL_RGBA16, .tileScrollY = 8 },
    { LVL_BATCH_LAYER_OPAQUE_FR_DL_SPACE64_2_PAL_RGBA16_1, .tileScrollY = 8 },
     */
};

const struct FlipbookLayer fc_flipbooks[LAYER_COUNT] = {
    [ LAYER_OPAQUE ] = FLIPBOOK_LAYER_DECL(flipbooks_opaque),
};
