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

#include "levels/gf/header.h"

#include "levels/gf/geo.inc.c"

#define gf_area_1 gf_area_visual
#define gf_area_1_geo gf_area_geo_visual
#include "levels/gf/visual/geo.inc.c"

#include "levels/gf/gf_skybox/geo.inc.c"
#include "levels/gf/gf_gake_a/geo.inc.c"
#include "levels/gf/gf_gake_b/geo.inc.c"
#include "levels/gf/gf_gake_c/geo.inc.c"
#include "levels/gf/gf_gake_d/geo.inc.c"
#include "levels/gf/gf_gake_e/geo.inc.c"
#include "levels/gf/gf_gake_f/geo.inc.c"