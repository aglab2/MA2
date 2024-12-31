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
#include "levels/ee/ee_shutter_dynamite/collision_header.h"

#include "levels/ee/ee_shutter_left/geo_header.h"

#include "levels/ee/ee_shutter_right/geo_header.h"

#include "levels/ee/ee_shutter_left/collision_header.h"

#include "levels/ee/ee_shutter_right/collision_header.h"

#include "levels/ee/ee_capsule/geo_header.h"

#include "levels/ee/ee_capsule_inside/geo_header.h"

#include "levels/ee/ee_hatch_a/geo_header.h"

#include "levels/ee/ee_hatch_a/collision_header.h"

#include "levels/ee/ee_hatch_b/geo_header.h"

#include "levels/ee/ee_hatch_b/collision_header.h"

#include "levels/ee/ee_laststep/collision_header.h"

#include "levels/ee/ee_laststep/geo_header.h"

#include "levels/ee/ee_step/collision_header.h"

#include "levels/ee/ee_stepb/geo_header.h"

#include "levels/ee/ee_stepb/collision_header.h"

#include "levels/ee/ee_tank/geo_header.h"

#include "levels/ee/ee_tank_break/geo_header.h"

#endif
