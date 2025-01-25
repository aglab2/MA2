#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"
#include "rail_desc.h"
#include "spring_desc.h"

#include "make_const_nonconst.h"

#include "levels/fr/visual/header_lvl.inc.h"
#include "levels/fr/visual/model_lvl.inc.c"

LDLDesc __debug__loop_desc = {  0, 1, 0, 1, 0x4000 };
static const LDLDesc loop_desc1 = { 2, 1, 0, 1, 0x4000 };
static const LDLDesc loop_desc2 = { 1, 2, 0, 1, 0xC000 };
static const LDLDesc loop_desc3 = { 1, 0, 0, -1, 0xC000 };

#define loop_desc_fr_area_8_spline_Loop_0186_object_012479FC_001 &__debug__loop_desc
#define loop_desc_fr_area_9_spline_Loop_0129_object_0124232C_001 &loop_desc1
#define loop_desc_fr_area_6_spline_Loop_28_ini_003 &loop_desc1
#define loop_desc_fr_area_6_spline_Loop_28_ini_002 &loop_desc1
#define loop_desc_fr_area_6_spline_Loop_28_ini_001 &loop_desc1
#define loop_desc_fr_area_6_spline_Loop_28_ini &loop_desc3
#define loop_desc_fr_area_1_spline_Loop_0502_object_01243CBC_001 &loop_desc1
#define loop_desc_fr_area_4_spline_Loop_0381_object_0123429C_001 &loop_desc2
#define loop_desc_fr_area_6_spline_Loop_28_ini_004 &loop_desc1

#include "levels/fr/header.inc.h"
#include "levels/fr/rails.inc.c"
#include "levels/fr/iw.inc.c"

#if 0
#include "levels/fr/leveldata.inc.c"
#else
#include "levels/fr/area_1/spline.inc.c"
#include "levels/fr/area_10/spline.inc.c"
#include "levels/fr/area_11/spline.inc.c"
#include "levels/fr/area_12/spline.inc.c"
#include "levels/fr/area_2/spline.inc.c"
#include "levels/fr/area_3/spline.inc.c"
#include "levels/fr/area_4/spline.inc.c"
#include "levels/fr/area_5/spline.inc.c"
#include "levels/fr/area_6/spline.inc.c"
#include "levels/fr/area_7/spline.inc.c"
#include "levels/fr/area_8/spline.inc.c"
#include "levels/fr/area_9/spline.inc.c"
#endif

#if 0
#include "levels/fr/area_1/collision.inc.c"
#include "levels/fr/area_10/collision.inc.c"
#include "levels/fr/area_11/collision.inc.c"
#include "levels/fr/area_12/collision.inc.c"
#include "levels/fr/area_2/collision.inc.c"
#include "levels/fr/area_3/collision.inc.c"
#include "levels/fr/area_4/collision.inc.c"
#include "levels/fr/area_5/collision.inc.c"
#include "levels/fr/area_6/collision.inc.c"
#include "levels/fr/area_7/collision.inc.c"
#include "levels/fr/area_8/collision.inc.c"
#include "levels/fr/area_9/collision.inc.c"
#endif

#include "levels/fr/fr_skybox/model.inc.c"