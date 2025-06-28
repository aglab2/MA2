#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"

#include "make_const_nonconst.h"

#if 0
#include "levels/cce/leveldata.inc.c"
#else
#include "levels/cce/visual/header_lvlopt.inc.h"
#include "levels/cce/visual/model_lvlopt.inc.c"
#endif

#include "levels/cce/cce_switch/model.inc.c"
#include "levels/cce/cce_shutter_right/collision.inc.c"
#include "levels/cce/cce_shutter_right/model.inc.c"
#include "levels/cce/cce_shutter_left/collision.inc.c"
#include "levels/cce/cce_shutter_left/model.inc.c"
#include "levels/cce/cce_stepb/collision.inc.c"
#include "levels/cce/cce_stepb/model.inc.c"
#include "levels/cce/cce_step/collision.inc.c"
#include "levels/cce/cce_step/model.inc.c"
#include "levels/cce/cce_block/collision.inc.c"
#include "levels/cce/cce_block/model.inc.c"
#include "levels/cce/cce_door/model.inc.c"
#include "levels/cce/cce_doorhit/model.inc.c"
#include "levels/cce/flipbook.inc.c"
