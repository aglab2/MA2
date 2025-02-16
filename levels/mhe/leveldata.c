#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"
#include "rail_desc.h"
#include "spring_desc.h"
#include "flipbook.h"

#include "make_const_nonconst.h"

extern u8 mhe_dl_space64_6_001_ci4[];
extern u8 mhe_dl_space64_6_001_pal_rgba16[];
static Gfx mat_mhe_dl_objLandTable0032_uv_sa2lvl_0_f3d[] = {
	gsSPGeometryMode(G_LIGHTING, 0),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, COMBINED, 0, PRIMITIVE_ALPHA, 0, ENVIRONMENT, 0, SHADE, 0),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsDPSetCycleType(G_CYC_2CYCLE),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_SURF2),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 0, 255, 255, 255, 255),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mhe_dl_space64_6_001_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 15),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, mhe_dl_space64_6_001_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 512),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 4, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 6, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 252),
	gsSPEndDisplayListHint(4),
};

extern u8 mhe_dl_space64_20_001_pal_rgba16[];
extern u8 mhe_dl_space64_20_001_ci4[];
static Gfx mat_mhe_dl_objLandTable0032_uv_sa2lvl_1_f3d[] = {
	gsSPGeometryMode(G_LIGHTING, 0),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, COMBINED, 0, PRIMITIVE_ALPHA, 0, ENVIRONMENT, 0, SHADE, 0),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsDPSetCycleType(G_CYC_2CYCLE),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_SURF2),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 0, 255, 255, 255, 255),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mhe_dl_space64_20_001_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 15),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, mhe_dl_space64_20_001_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 512),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 4, 0, 0, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 252),
	gsSPEndDisplayListHint(4),
};

extern u8 mhe_dl_space32_3_001_pal_rgba16[];
extern u8 mhe_dl_space32_3_001_ci8[];
static Gfx mat_mhe_dl_objLandTable0032_uv_sa2lvl_2_f3d[] = {
	gsSPGeometryMode(G_LIGHTING, 0),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, COMBINED, 0, PRIMITIVE_ALPHA, 0, ENVIRONMENT, 0, SHADE, 0),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsDPSetCycleType(G_CYC_2CYCLE),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_SURF2),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 0, 255, 255, 255, 255),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mhe_dl_space32_3_001_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 167),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 1, mhe_dl_space32_3_001_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 511, 512),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayListHint(4),
};

#define mat_revert_mhe_dl_objLandTable0032_uv_sa2lvl_0_f3d mat_revert_2cycle
#define mat_revert_mhe_dl_objLandTable0032_uv_sa2lvl_1_f3d mat_revert_2cycle
#define mat_revert_mhe_dl_objLandTable0032_uv_sa2lvl_2_f3d mat_revert_2cycle
static Gfx mat_revert_2cycle[] = {
	gsSPGeometryMode(0, G_LIGHTING),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureLUT(G_TT_NONE),
	gsDPSetCycleType(G_CYC_1CYCLE),
	gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
	gsSPEndDisplayListHint(4),
};

#if 0
#include "levels/mhe/leveldata.inc.c"
#else
#include "levels/mhe/header.h"
#include "levels/mhe/area_1/spline.inc.c"
#include "levels/mhe/visual/model_lvl.inc.c"
#include "levels/mhe/rails.inc.c"
#include "levels/mhe/flipbook.inc.c"
#endif

#include "levels/mhe/mhe_skybox/model.inc.c"
#include "levels/mhe/mhe_bigshutter/model.inc.c"
#include "levels/mhe/mhe_bigshutter/collision.inc.c"
#include "levels/mhe/mhe_fireball/model.inc.c"
#include "levels/mhe/mhe_fireball_break/model.inc.c"
#include "levels/mhe/mhe_meteo_a/model.inc.c"
#include "levels/mhe/mhe_meteo_b/model.inc.c"
#include "levels/mhe/mhe_meteo_break_a/model.inc.c"
#include "levels/mhe/mhe_meteobig/model.inc.c"
#include "levels/mhe/mhe_meteobig_break/model.inc.c"
#include "levels/mhe/mhe_meteo_fall/model.inc.c"
#include "levels/mhe/mhe_meteoshut/model.inc.c"
#include "levels/mhe/mhe_meteoshut/collision.inc.c"
#include "levels/mhe/mhe_tank/model.inc.c"
#include "levels/mhe/mhe_tank_break/model.inc.c"
#include "levels/mhe/mhe_meteoshut_break/model.inc.c"