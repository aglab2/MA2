#ifndef MH_HEADER_H
#define MH_HEADER_H

#include "types.h"
#include "game/moving_texture.h"

extern const LevelScript level_mh_entry[];

#define mh_area_1 mh_area_visual
#define mh_area_1_geo mh_area_geo_visual
#include "levels/mh/visual/header_lvl.inc.h"
#undef mh_area_1_geo
#undef mh_area_1

#include "levels/mh/header.inc.h"

#include "levels/mh/mh_skybox/header.h"

#endif
