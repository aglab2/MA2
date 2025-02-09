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

#include "levels/pc/header.h"

#if 0
#include "levels/pc/geo.inc.c"
#endif

#define pc_area_1 pc_area_visual
#define pc_area_1_geo pc_area_geo_visual
#include "levels/pc/visual/geo_lvl.inc.c"

#include "levels/pc/pc_door_b/geo.inc.c"
#include "levels/pc/pc_door_g/geo.inc.c"
#include "levels/pc/pc_door_n/geo.inc.c"
#include "levels/pc/pc_door_r/geo.inc.c"
#include "levels/pc/pc_block/geo.inc.c"
#include "levels/pc/pc_key_blue/geo.inc.c"
#include "levels/pc/pc_key_green/geo.inc.c"
#include "levels/pc/pc_keydoor_blue/geo.inc.c"
#include "levels/pc/pc_keydoor_green/geo.inc.c"
#include "levels/pc/pc_windmill/geo.inc.c"
#include "levels/pc/pc_walltype/geo.inc.c"
#include "levels/pc/pc_sandglass_ends/geo.inc.c"
#include "levels/pc/pc_sandglass_glass/geo.inc.c"
#include "levels/pc/pc_sandglass_sand/geo.inc.c"
#include "levels/pc/pc_sandglass_sandf/geo.inc.c"
#include "levels/pc/pc_sandglass_spring/geo.inc.c"
#include "levels/pc/pc_move/geo.inc.c"