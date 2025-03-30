#ifndef GF_HEADER_H
#define GF_HEADER_H

#include "types.h"
#include "game/moving_texture.h"

extern const LevelScript level_gf_entry[];

#define gf_area_1 gf_area_visual
#define gf_area_1_geo gf_area_geo_visual
#include "levels/gf/visual/header_lvl.inc.h"
#undef gf_area_1_geo
#undef gf_area_1

#include "levels/gf/header.inc.h"

#include "levels/gf/gf_gake_a/geo_header.h"

#include "levels/gf/gf_gake_b/geo_header.h"

#include "levels/gf/gf_gake_c/geo_header.h"

#include "levels/gf/gf_gake_d/geo_header.h"

#include "levels/gf/gf_gake_e/geo_header.h"

#include "levels/gf/gf_gake_f/geo_header.h"

#include "levels/gf/gf_gake_a/collision_header.h"

#include "levels/gf/gf_gake_b/collision_header.h"

#include "levels/gf/gf_gake_c/collision_header.h"

#include "levels/gf/gf_gake_d/collision_header.h"

#include "levels/gf/gf_gake_e/collision_header.h"

#include "levels/gf/gf_gake_f/collision_header.h"

#include "levels/gf/gf_vine/geo_header.h"

#include "levels/gf/gf_skybox/header.h"

#endif
