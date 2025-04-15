#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"

#include "make_const_nonconst.h"

#if 0
#include "levels/wb/leveldata.inc.c"
#else
#include "levels/wb/area_1/spline.inc.c"
#include "levels/wb/area_2/spline.inc.c"
#include "levels/wb/visual/header_lvlopt.inc.h"
#include "levels/wb/visual/model_lvlopt.inc.c"
#include "levels/wb/flipbook.inc.c"
#endif

#include "levels/wb/wb_skybox/model.inc.c"
#include "levels/wb/wb_cont/model.inc.c"
#include "levels/wb/wb_cont_break/model.inc.c"
#include "levels/wb/wb_contb/model.inc.c"
#include "levels/wb/wb_contc/model.inc.c"
#include "levels/wb/wb_fig_ai/model.inc.c"
#include "levels/wb/wb_fig_ai2/model.inc.c"
#include "levels/wb/wb_contb/collision.inc.c"
#include "levels/wb/wb_contc/collision.inc.c"
#include "levels/wb/wb_contc_stand/collision.inc.c"
#include "levels/wb/wb_shut/model.inc.c"
#include "levels/wb/wb_shut/collision.inc.c"
#include "levels/wb/wb_shut_break/model.inc.c"
#include "levels/wb/wb_shuts/collision.inc.c"
#include "levels/wb/wb_shuts/model.inc.c"
#include "levels/wb/wb_shuts_break/model.inc.c"