#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"

#include "make_const_nonconst.h"

#if 0
#include "levels/cct/leveldata.inc.c"
#else
#include "levels/cct/visual/header_lvlopt.inc.h"
#include "levels/cct/visual/model_lvlopt.inc.c"
#include "levels/cct/flipbook.inc.c"
#endif

#include "levels/cct/cct_goaldoor/model.inc.c"
#include "levels/cct/cct_goaldoor_breaka/model.inc.c"
#include "levels/cct/cct_goaldoor_breakb/model.inc.c"
#include "levels/cct/cct_goaldoor_breakc/model.inc.c"
#include "levels/cct/cct_goaldoor_break/model.inc.c"
#include "levels/cct/cc_goaldoor_hit/model.inc.c"
#include "levels/cct/cc_goaldoor_hitbreak/model.inc.c"
#include "levels/cct/cct_stepb/collision.inc.c"
#include "levels/cct/cct_stepb/model.inc.c"
#include "levels/cct/cct_step/collision.inc.c"
#include "levels/cct/cct_step/model.inc.c"
#include "levels/cct/cct_shutter_left/collision.inc.c"
#include "levels/cct/cct_shutter_left/model.inc.c"
#include "levels/cct/cct_shutter_right/collision.inc.c"
#include "levels/cct/cct_shutter_right/model.inc.c"
#include "levels/cct/cct_switch/model.inc.c"
#include "levels/cct/cct_blockla/model.inc.c"