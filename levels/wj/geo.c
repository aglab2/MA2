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

#include "levels/wj/header.h"

#if 0
#include "levels/wj/geo.inc.c"
#else
#include "levels/wj/visual/geo_lvl.inc.c"
#endif

#include "levels/wj/wj_platform/geo.inc.c"
#include "levels/wj/wj_up_hook/geo.inc.c"
#include "levels/wj/wj_up_vine/geo.inc.c"
#include "levels/wj/wj_side_vine/geo.inc.c"
#include "levels/wj/wj_side_hook/geo.inc.c"