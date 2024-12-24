#ifndef HB_HEADER_H
#define HB_HEADER_H

#include "types.h"
#include "game/moving_texture.h"

extern const LevelScript level_hb_entry[];

#define hb_area_1 hb_area_visual
#define hb_area_1_geo hb_area_geo_visual
#include "levels/hb/visual/header.inc.h"
#undef hb_area_1_geo
#undef hb_area_1


#include "levels/hb/header.inc.h"
#include "levels/hb/hb_skybox/geo_header.h"

#endif
