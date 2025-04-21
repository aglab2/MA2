#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"
#include "instant_warp_desc.h"
#include "rail_desc.h"
#include "spring_desc.h"

#include "make_const_nonconst.h"

static const LDLDesc loop_desc1 = { };
static const LDLDesc loop_desc2 = { 0, .dontFlip = 1, .canSnapBackwards = 1 };
#define loop_desc_wj_area_1_spline_NurbsCurve_Loop &loop_desc1
#define loop_desc_wj_area_3_spline_NurbsCurve_001_Loop &loop_desc1
#define loop_desc_wj_area_5_spline_NurbsCurve_003_Loop &loop_desc1
#define loop_desc_wj_area_1_spline_NurbsCurve_VineLoop_005 &loop_desc2
#define loop_desc_wj_area_4_spline_NurbsCurve_VineLoop_001 &loop_desc2
#define loop_desc_wj_area_5_spline_NurbsCurve_VineLoop_002 &loop_desc2

#if 0
#include "levels/wj/leveldata.inc.c"
#else
#include "levels/wj/area_1/spline.inc.c"
#include "levels/wj/area_2/spline.inc.c"
#include "levels/wj/area_3/spline.inc.c"
#include "levels/wj/area_4/spline.inc.c"
#include "levels/wj/area_5/spline.inc.c"
#include "levels/wj/visual/header_lvlopt.inc.h"
#include "levels/wj/visual/model_lvlopt.inc.c"
#include "levels/wj/iw.inc.c"
#include "levels/wj/rails.inc.c"
#endif

#include "levels/wj/wj_skybox/model.inc.c"
#include "levels/wj/wj_platform/model.inc.c"
#include "levels/wj/wj_up_hook/model.inc.c"
#include "levels/wj/wj_up_vine/model.inc.c"
#include "levels/wj/wj_side_vine/model.inc.c"
#include "levels/wj/wj_side_hook/model.inc.c"
#include "levels/wj/wj_vine/model.inc.c"