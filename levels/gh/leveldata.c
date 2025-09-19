#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"
#include "spring_desc.h"
#include "rail_desc.h"

#include "make_const_nonconst.h"

#if 0
#include "levels/gh/leveldata.inc.c"
#else
#include "levels/gh/iw.inc.c"
#include "levels/gh/visual/header_lvl.inc.h"
#include "levels/gh/visual/model_lvlopt.inc.c"
#include "levels/gh/area_1/spline.inc.c"
#include "levels/gh/area_2/spline.inc.c"
#include "levels/gh/flipbook.inc.c"
static const LDLDesc loop_desc1 = { 0 };
#define loop_desc_gh_area_2_spline_NurbsCurve_Loop &loop_desc1
#include "levels/gh/rails.inc.c"
#endif

#include "levels/gh/gh_skybox/model.inc.c"
#include "levels/gh/gh_plat/collision.inc.c"
#include "levels/gh/gh_plat/model.inc.c"
#include "levels/gh/gh_fall/collision.inc.c"
#include "levels/gh/gh_fall/model.inc.c"
#include "levels/gh/gh_fall_break/model.inc.c"
#include "levels/gh/gh_batabata/model.inc.c"
#include "levels/gh/gh_beeton/model.inc.c"