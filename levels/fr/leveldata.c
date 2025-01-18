#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"
#include "rail_desc.h"

#include "make_const_nonconst.h"

#include "levels/fr/visual/header_lvl.inc.h"
#include "levels/fr/visual/model_lvl.inc.c"

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