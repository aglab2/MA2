#ifndef PC_HEADER_H
#define PC_HEADER_H

#include "types.h"
#include "game/moving_texture.h"

extern const LevelScript level_pc_entry[];

#define pc_area_1 pc_area_visual
#define pc_area_1_geo pc_area_geo_visual
#include "levels/pc/visual/header.inc.h"
#undef pc_area_1_geo
#undef pc_area_1

#include "levels/pc/header.inc.h"
#endif
