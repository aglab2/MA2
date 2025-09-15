#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"
#include "instant_warp_desc.h"
#include "flipbook.h"
#include "rail_desc.h"
#include "spring_desc.h"

#include "make_const_nonconst.h"

#if 0
#include "levels/fc/leveldata.inc.c"
#else
static const LDLDesc loop_desc1 = { 0 };
static const LDLDesc loop_desc2 = { -0x4000 };
#define loop_desc_fc_area_2_spline_0167_object_0143E7FC_001_Loop &loop_desc1
#define loop_desc_fc_area_7_spline_0051_object_01445834_001_Loop &loop_desc2
#define loop_desc_fc_area_6_spline_NurbsCurve_Loop &loop_desc1

#include "levels/fc/visual/header_lvlopt.inc.h"
#include "levels/fc/visual/model_lvlopt.inc.c"
#include "levels/fc/flipbook.inc.c"
#include "levels/fc/iw.inc.c"
#include "levels/fc/area_1/spline.inc.c"
#include "levels/fc/area_2/spline.inc.c"
#include "levels/fc/area_3/spline.inc.c"
#include "levels/fc/area_4/spline.inc.c"
#include "levels/fc/area_5/spline.inc.c"
#include "levels/fc/area_6/spline.inc.c"
#include "levels/fc/area_7/spline.inc.c"
#include "levels/fc/area_8/spline.inc.c"
#include "levels/fc/area_9/spline.inc.c"
#include "levels/fc/rails.inc.c"
#endif

#include "levels/fc/fc_skybox/model.inc.c"
#include "levels/fc/fc_meteof/model.inc.c"
#include "levels/fc/fc_meteob/model.inc.c"
#include "levels/fc/fc_meteoc/model.inc.c"
#include "levels/fc/fc_meteof_break/model.inc.c"