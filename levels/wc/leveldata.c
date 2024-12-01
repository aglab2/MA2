#include "game/behavior_data_decl.h"

#include <ultra64.h>"
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"

const BehaviorScript bhvWCFanSpin[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO),
    BEGIN_LOOP(),
        ADD_INT(oFaceAngleYaw, 0x100),
    END_LOOP(),
};

#include "levels/wc/leveldata.inc.c"

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