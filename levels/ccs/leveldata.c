#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"

#include "make_const_nonconst.h"

#if 0
#include "levels/ccs/leveldata.inc.c"
#else
#include "levels/ccs/visual/header_lvlopt.inc.h"
#include "levels/ccs/visual/model_lvlopt.inc.c"
#endif

#include "levels/ccs/ccs_block/collision.inc.c"
#include "levels/ccs/ccs_block/model.inc.c"
#include "levels/ccs/ccs_shutter_left/collision.inc.c"
#include "levels/ccs/ccs_shutter_left/model.inc.c"
#include "levels/ccs/ccs_shutter_right/collision.inc.c"
#include "levels/ccs/ccs_shutter_right/model.inc.c"
#include "levels/ccs/ccs_switch/collision.inc.c"
#include "levels/ccs/ccs_switch/model.inc.c"