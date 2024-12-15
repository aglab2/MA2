#ifndef GF_HEADER_H
#define GF_HEADER_H

#include "types.h"
#include "game/moving_texture.h"

extern const LevelScript level_gf_entry[];

#define gf_area_1 gf_area_visual
#define gf_area_1_geo gf_area_geo_visual
#include "levels/gf/visual/header.inc.h"
#undef gf_area_1_geo
#undef gf_area_1

#include "levels/gf/header.inc.h"
#include "levels/gf/gf_skybox/geo_header.h"

#endif
