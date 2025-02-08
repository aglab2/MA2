#ifndef PC_HEADER_H
#define PC_HEADER_H

#include "types.h"
#include "game/moving_texture.h"

extern const LevelScript level_pc_entry[];

#define pc_area_1 pc_area_visual
#define pc_area_1_geo pc_area_geo_visual
#include "levels/pc/visual/header_lvl.inc.h"
#undef pc_area_1_geo
#undef pc_area_1

#include "levels/pc/header.inc.h"
#include "levels/pc/pc_door_b/collision_header.h"

#include "levels/pc/pc_door_b/geo_header.h"

#include "levels/pc/pc_door_g/collision_header.h"

#include "levels/pc/pc_door_g/geo_header.h"

#include "levels/pc/pc_door_n/collision_header.h"

#include "levels/pc/pc_door_n/geo_header.h"

#include "levels/pc/pc_door_r/collision_header.h"

#include "levels/pc/pc_door_r/geo_header.h"

#include "levels/pc/pc_block/geo_header.h"

#include "levels/pc/pc_block/collision_header.h"

#include "levels/pc/pc_key_blue/geo_header.h"

#include "levels/pc/pc_key_green/geo_header.h"

#include "levels/pc/pc_keydoor_blue/geo_header.h"

#include "levels/pc/pc_keydoor_green/geo_header.h"

#include "levels/pc/pc_windmill/geo_header.h"

#include "levels/pc/pc_windmill/collision_header.h"

#include "levels/pc/pc_walltype/geo_header.h"

#include "levels/pc/pc_walltype/collision_header.h"

#include "levels/pc/pc_sandglass_ends/geo_header.h"

#include "levels/pc/pc_sandglass_glass/geo_header.h"

#include "levels/pc/pc_sandglass_sand/geo_header.h"

#include "levels/pc/pc_sandglass_sandf/geo_header.h"

#include "levels/pc/pc_sandglass_spring/geo_header.h"

#include "levels/pc/pc_keydoor_blue/collision_header.h"

#endif
