#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"
#include "rail_desc.h"

#include "make_const_nonconst.h"

#if 0
#include "levels/dl/leveldata.inc.c"
#else
#include "levels/dl/visual/header_lvl.inc.h"
#include "levels/dl/area_1/spline.inc.c"
#include "levels/dl/visual/model_lvl.inc.c"
#endif

#include "levels/dl/dl_skybox/model.inc.c"
#include "levels/dl/dl_vase/model.inc.c"
#include "levels/dl/dl_vase_break/model.inc.c"
#include "levels/dl/dl_crate/model.inc.c"
#include "levels/dl/dl_crate_dark/model.inc.c"
#include "levels/dl/dl_crate_break/model.inc.c"
#include "levels/dl/dl_cratedark_break/model.inc.c"

static const LDLDesc loop_desc = { 0, 0 };
#define loop_desc_dl_area_1_spline_NurbsCurve_Loop &loop_desc
#define loop_desc_dl_area_1_spline_NurbsCurve_Loop_001 &loop_desc
#define loop_desc_dl_area_1_spline_NurbsCurve_Loop_002 &loop_desc
#define loop_desc_dl_area_1_spline_NurbsCurve_Loop_003 &loop_desc
#define loop_desc_dl_area_1_spline_NurbsCurve_Loop_004 &loop_desc
#define loop_desc_dl_area_1_spline_NurbsCurve_Loop_005 &loop_desc
#define loop_desc_dl_area_1_spline_NurbsCurve_Loop_006 &loop_desc
#define loop_desc_dl_area_1_spline_NurbsCurve_Loop_007 &loop_desc

#include "levels/dl/rails.inc.c"
