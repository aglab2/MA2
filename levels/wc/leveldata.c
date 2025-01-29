#include "game/behavior_data_decl.h"

#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"
#include "spring_desc.h"

#include "levels/wc/visual/header_lvl.inc.h"

const BehaviorScript bhvWCFanSpin[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO),
    BEGIN_LOOP(),
        ADD_INT(oFaceAngleRoll, 0x100),
    END_LOOP(),
};

#include "levels/wc/rails.inc.c"

#if 0
#include "levels/wc/leveldata.inc.c"
#else
#include "levels/wc/area_1/macro.inc.c"
#include "levels/wc/area_1/spline.inc.c"
#endif

#include "levels/wc/visual/model_lvl.inc.c"

#include "levels/wc/wc_box/model.inc.c"
#include "levels/wc/wc_box_break/model.inc.c"
#include "levels/wc/wc_fanbase_bright/model.inc.c"
#include "levels/wc/wc_fanbase_dark/model.inc.c"
#include "levels/wc/wc_fan_bright/model.inc.c"
#include "levels/wc/wc_fan_dark/model.inc.c"
#include "levels/wc/wc_rock/model.inc.c"
#include "levels/wc/wc_rock_break/model.inc.c"
#include "levels/wc/wc_stonehead/model.inc.c"
#include "levels/wc/wc_stonehead_path/model.inc.c"
#include "levels/wc/wc_stonehead/collision.inc.c"