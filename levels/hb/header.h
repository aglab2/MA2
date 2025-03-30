#ifndef HB_HEADER_H
#define HB_HEADER_H

#include "types.h"
#include "game/moving_texture.h"

extern const LevelScript level_hb_entry[];

#define hb_area_1 hb_area_visual
#define hb_area_1_geo hb_area_geo_visual
#include "levels/hb/visual/header_lvlopt.inc.h"
#undef hb_area_1_geo
#undef hb_area_1


#include "levels/hb/header.inc.h"

#include "levels/hb/hb_block/collision_header.h"

#include "levels/hb/hb_block/geo_header.h"

#include "levels/hb/hb_block_break/geo_header.h"

#include "levels/hb/hb_hashira/collision_header.h"

#include "levels/hb/hb_hashira/geo_header.h"

#include "levels/hb/hb_hashira_break/geo_header.h"

#include "levels/hb/hb_vase/geo_header.h"

#include "levels/hb/hb_vase_break/geo_header.h"

#include "levels/hb/hb_wall_break/geo_header.h"

#include "levels/hb/hb_hashira_platform/geo_header.h"

#include "levels/hb/hb_hashira_platform/collision_header.h"

#include "levels/hb/hb_updown/collision_header.h"

#include "levels/hb/hb_updown/geo_header.h"

#include "levels/hb/hb_updown_bright/geo_header.h"

#include "levels/hb/hb_wall/geo_header.h"

#include "levels/hb/hb_skybox/header.h"

#endif
