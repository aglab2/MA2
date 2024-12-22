#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"
#include "spring_desc.h"

#include "make_const_nonconst.h"

#include "levels/ph/header.inc.h"

static SpringDesc spring_ph_area1[] = {
    ph_area_1_spline_NurbsCurve_Spring,
    ph_area_1_spline_NurbsCurve_Spring_001,
    ph_area_1_spline_NurbsCurve_Spring_002,
    ph_area_1_spline_NurbsCurve_Spring_003,
    ph_area_1_spline_NurbsCurve_Spring_004,
    NULL,
};

const SpringDesc* spring_descs_ph[] = {
    spring_ph_area1,
};

#include "levels/ph/leveldata.inc.c"
#include "levels/ph/ph_skybox/model.inc.c"
#include "levels/ph/ph_drum/model.inc.c"
#include "levels/ph/ph_drum_break/model.inc.c"
#include "levels/ph/ph_ppshed/model.inc.c"
#include "levels/ph/ph_ppshed_break/model.inc.c"
#include "levels/ph/ph_terminal/model.inc.c"
#include "levels/ph/ph_terminal/collision.inc.c"