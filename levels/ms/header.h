#ifndef MS_HEADER_H
#define MS_HEADER_H

#include "types.h"
#include "game/moving_texture.h"

extern const LevelScript level_ms_entry[];

#define ms_area_1 ms_area_visual
#define ms_area_1_geo ms_area_geo_visual
#include "levels/ms/visual/header.inc.h"
#undef ms_area_1_geo
#undef ms_area_1

#include "levels/ms/header.inc.h"
#include "levels/ms/ms_skybox/geo_header.h"

#include "levels/ms/ms_buffer/geo_header.h"

#include "levels/ms/ms_buffer_break/geo_header.h"

#include "levels/ms/ms_hammer/geo_header.h"

#include "levels/ms/ms_hammer/collision_header.h"

#include "levels/ms/ms_slane/collision_header.h"

#include "levels/ms/ms_slane_break/geo_header.h"

#include "levels/ms/ms_slane/geo_header.h"

#endif
