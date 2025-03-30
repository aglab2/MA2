#ifndef CG_HEADER_H
#define CG_HEADER_H

#include "types.h"
#include "game/moving_texture.h"

extern const LevelScript level_cg_entry[];

#define cg_area_1 cg_area_visual
#define cg_area_1_geo cg_area_geo_visual
#include "levels/cg/visual/header_lvlopt.inc.h"
#undef cg_area_1_geo
#undef cg_area_1

#include "levels/cg/header.inc.h"

#include "levels/cg/cg_capsule/geo_header.h"

#include "levels/cg/cg_poison/collision_header.h"

#include "levels/cg/cg_poison/geo_header.h"

#include "levels/cg/cg_poison_break/geo_header.h"

#include "levels/cg/cg_shutter_left/collision_header.h"

#include "levels/cg/cg_shutter_left/geo_header.h"

#include "levels/cg/cg_shutter_right/collision_header.h"

#include "levels/cg/cg_shutter_right/geo_header.h"

#include "levels/cg/cg_skybox/header.h"

#endif
