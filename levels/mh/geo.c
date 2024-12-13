#include <ultra64.h>
#include "sm64.h"
#include "geo_commands.h"

#include "game/level_geo.h"
#include "game/geo_misc.h"
#include "game/camera.h"
#include "game/moving_texture.h"
#include "game/screen_transition.h"
#include "game/paintings.h"

#include "make_const_nonconst.h"

#include "levels/mh/header.h"

#include "levels/mh/geo.inc.c"

#define mh_area_1 mh_area_visual
#define mh_area_1_geo mh_area_geo_visual
#undef GEO_TRANSLATE_NODE_WITH_DL
#define GEO_TRANSLATE_NODE_WITH_DL GEO_LVL_TRANSLATE_NODE_WITH_DL
#undef GEO_TRANSLATE_ROTATE_WITH_DL
#define GEO_TRANSLATE_ROTATE_WITH_DL GEO_LVL_TRANSLATE_ROTATE_WITH_DL
#include "levels/mh/visual/geo.inc.c"

#include "levels/mh/mh_skybox/geo.inc.c"