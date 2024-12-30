#ifndef EE_HEADER_H
#define EE_HEADER_H

#include "types.h"
#include "game/moving_texture.h"

extern const LevelScript level_ee_entry[];

#define ee_area_1 ee_area_visual
#define ee_area_1_geo ee_area_geo_visual
#include "levels/ee/visual/header.inc.h"
#undef ee_area_1_geo
#undef ee_area_1

#include "levels/ee/header.inc.h"
#endif
