#include "game/behavior_data_decl.h"

#include <ultra64.h>"
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"

#include "make_const_nonconst.h"

const BehaviorScript bhvPLRoll[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO),
    BEGIN_LOOP(),
        ADD_INT(oFaceAngleRoll, 0x100),
    END_LOOP(),
};

#include "levels/pl/leveldata.inc.c"
#include "levels/pl/pl_bombe/model.inc.c"
#include "levels/pl/pl_bombe_break/model.inc.c"
#include "levels/pl/pl_bombe_breakb/model.inc.c"
#include "levels/pl/pl_bridge/model.inc.c"
#include "levels/pl/pl_cage/model.inc.c"
#include "levels/pl/pl_cageb/model.inc.c"
#include "levels/pl/pl_elv/model.inc.c"
#include "levels/pl/pl_searchlight_bottom/model.inc.c"
#include "levels/pl/pl_searchlight/model.inc.c"
#include "levels/pl/pl_siren/model.inc.c"
#include "levels/pl/pl_siren_spin/model.inc.c"
#include "levels/pl/pl_tank/model.inc.c"
#include "levels/pl/pl_tank_breaka/model.inc.c"
#include "levels/pl/pl_wall/model.inc.c"
#include "levels/pl/pl_bridge/collision.inc.c"
#include "levels/pl/pl_elv/collision.inc.c"
#include "levels/pl/pl_mlift/collision.inc.c"
#include "levels/pl/pl_mlift/model.inc.c"
#include "levels/pl/pl_roll/model.inc.c"