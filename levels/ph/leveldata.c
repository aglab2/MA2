#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"
#include "spring_desc.h"
#include "rail_desc.h"

#include "make_const_nonconst.h"

#include "levels/ph/visual/header_lvl.inc.h"
#include "levels/ph/rails.inc.c"

#if 0
#include "levels/ph/leveldata.inc.c"
#else
#include "levels/ph/area_1/spline.inc.c"
#include "levels/ph/visual/model_lvl.inc.c"
#endif

#include "levels/ph/ph_skybox/model.inc.c"
#include "levels/ph/ph_drum/model.inc.c"
#include "levels/ph/ph_drum_break/model.inc.c"
#include "levels/ph/ph_ppshed/model.inc.c"
#include "levels/ph/ph_ppshed_break/model.inc.c"
#include "levels/ph/ph_terminal/model.inc.c"
#include "levels/ph/ph_terminal/collision.inc.c"