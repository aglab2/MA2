// Flame

// 0x030172E0
static const Vtx flame_seg3_vertex_030172E0[] = {
    {{{   -25,    -25,      0}, 0, {     0,    992}, {0x00, 0x00, 0x00, 0x00}}},
    {{{    25,    -25,      0}, 0, {   992,    992}, {0x00, 0x00, 0x00, 0x00}}},
    {{{    25,     25,      0}, 0, {   992,      0}, {0x00, 0x00, 0x00, 0x00}}},
    {{{   -25,     25,      0}, 0, {     0,      0}, {0x00, 0x00, 0x00, 0x00}}},
};

static const Gfx flame_v2_common[] = {
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
	gsDPSetCombineLERP(0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0),
    gsDPSetPrimColor(0, 0, 255, 255, 255, 200),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 128),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_32b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

const Gfx flame_v2_dl_revert[] = {
	gsSPSetGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
	gsSPEndDisplayList(),
};

ALIGNED8 static const Texture red01[] = {
#include "actors/flame/dz_dc_hi_red01.rgba32.inc.c"
};

ALIGNED8 static const Texture red02[] = {
#include "actors/flame/dz_dc_hi_red02.rgba32.inc.c"
};

ALIGNED8 static const Texture red03[] = {
#include "actors/flame/dz_dc_hi_red03.rgba32.inc.c"
};

ALIGNED8 static const Texture red04[] = {
#include "actors/flame/dz_dc_hi_red04.rgba32.inc.c"
};

ALIGNED8 static const Texture red05[] = {
#include "actors/flame/dz_dc_hi_red05.rgba32.inc.c"
};

ALIGNED8 static const Texture red06[] = {
#include "actors/flame/dz_dc_hi_red06.rgba32.inc.c"
};

ALIGNED8 static const Texture red07[] = {
#include "actors/flame/dz_dc_hi_red07.rgba32.inc.c"
};

ALIGNED8 static const Texture red08[] = {
#include "actors/flame/dz_dc_hi_red08.rgba32.inc.c"
};

ALIGNED8 static const Texture red09[] = {
#include "actors/flame/dz_dc_hi_red09.rgba32.inc.c"
};

ALIGNED8 static const Texture red10[] = {
#include "actors/flame/dz_dc_hi_red10.rgba32.inc.c"
};

ALIGNED8 static const Texture red11[] = {
#include "actors/flame/dz_dc_hi_red11.rgba32.inc.c"
};

ALIGNED8 static const Texture red12[] = {
#include "actors/flame/dz_dc_hi_red12.rgba32.inc.c"
};

ALIGNED8 static const Texture red13[] = {
#include "actors/flame/dz_dc_hi_red13.rgba32.inc.c"
};

ALIGNED8 static const Texture red14[] = {
#include "actors/flame/dz_dc_hi_red14.rgba32.inc.c"
};

ALIGNED8 static const Texture red15[] = {
#include "actors/flame/dz_dc_hi_red15.rgba32.inc.c"
};

ALIGNED8 static const Texture red16[] = {
#include "actors/flame/dz_dc_hi_red16.rgba32.inc.c"
};
    
const Gfx flame_v2_dl_red01[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, red01),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_red02[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, red02),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_red03[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, red03),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_red04[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, red04),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_red05[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, red05),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_red06[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, red06),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_red07[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, red07),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_red08[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, red08),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_red09[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, red09),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_red10[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, red10),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_red11[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, red11),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_red12[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, red12),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_red13[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, red13),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_red14[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, red14),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_red15[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, red15),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_red16[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, red16),
    gsSPBranchList(flame_v2_common),
};

ALIGNED8 static const Texture blue01[] = {
#include "actors/flame/dz_dc_hi_blue01.rgba32.inc.c"
};

ALIGNED8 static const Texture blue02[] = {
#include "actors/flame/dz_dc_hi_blue02.rgba32.inc.c"
};

ALIGNED8 static const Texture blue03[] = {
#include "actors/flame/dz_dc_hi_blue03.rgba32.inc.c"
};

ALIGNED8 static const Texture blue04[] = {
#include "actors/flame/dz_dc_hi_blue04.rgba32.inc.c"
};

ALIGNED8 static const Texture blue05[] = {
#include "actors/flame/dz_dc_hi_blue05.rgba32.inc.c"
};

ALIGNED8 static const Texture blue06[] = {
#include "actors/flame/dz_dc_hi_blue06.rgba32.inc.c"
};

ALIGNED8 static const Texture blue07[] = {
#include "actors/flame/dz_dc_hi_blue07.rgba32.inc.c"
};

ALIGNED8 static const Texture blue08[] = {
#include "actors/flame/dz_dc_hi_blue08.rgba32.inc.c"
};

ALIGNED8 static const Texture blue09[] = {
#include "actors/flame/dz_dc_hi_blue09.rgba32.inc.c"
};

ALIGNED8 static const Texture blue10[] = {
#include "actors/flame/dz_dc_hi_blue10.rgba32.inc.c"
};

ALIGNED8 static const Texture blue11[] = {
#include "actors/flame/dz_dc_hi_blue11.rgba32.inc.c"
};

ALIGNED8 static const Texture blue12[] = {
#include "actors/flame/dz_dc_hi_blue12.rgba32.inc.c"
};

ALIGNED8 static const Texture blue13[] = {
#include "actors/flame/dz_dc_hi_blue13.rgba32.inc.c"
};

ALIGNED8 static const Texture blue14[] = {
#include "actors/flame/dz_dc_hi_blue14.rgba32.inc.c"
};

ALIGNED8 static const Texture blue15[] = {
#include "actors/flame/dz_dc_hi_blue15.rgba32.inc.c"
};

ALIGNED8 static const Texture blue16[] = {
#include "actors/flame/dz_dc_hi_blue16.rgba32.inc.c"
};
    
const Gfx flame_v2_dl_blue01[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, blue01),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_blue02[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, blue02),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_blue03[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, blue03),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_blue04[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, blue04),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_blue05[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, blue05),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_blue06[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, blue06),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_blue07[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, blue07),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_blue08[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, blue08),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_blue09[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, blue09),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_blue10[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, blue10),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_blue11[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, blue11),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_blue12[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, blue12),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_blue13[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, blue13),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_blue14[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, blue14),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_blue15[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, blue15),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_blue16[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, blue16),
    gsSPBranchList(flame_v2_common),
};

ALIGNED8 static const Texture green01[] = {
#include "actors/flame/dz_eq_hi_green01.rgba32.inc.c"
};

ALIGNED8 static const Texture green02[] = {
#include "actors/flame/dz_eq_hi_green02.rgba32.inc.c"
};

ALIGNED8 static const Texture green03[] = {
#include "actors/flame/dz_eq_hi_green03.rgba32.inc.c"
};

ALIGNED8 static const Texture green04[] = {
#include "actors/flame/dz_eq_hi_green04.rgba32.inc.c"
};

ALIGNED8 static const Texture green05[] = {
#include "actors/flame/dz_eq_hi_green05.rgba32.inc.c"
};

ALIGNED8 static const Texture green06[] = {
#include "actors/flame/dz_eq_hi_green06.rgba32.inc.c"
};

ALIGNED8 static const Texture green07[] = {
#include "actors/flame/dz_eq_hi_green07.rgba32.inc.c"
};

ALIGNED8 static const Texture green08[] = {
#include "actors/flame/dz_eq_hi_green08.rgba32.inc.c"
};

ALIGNED8 static const Texture green09[] = {
#include "actors/flame/dz_eq_hi_green09.rgba32.inc.c"
};

ALIGNED8 static const Texture green10[] = {
#include "actors/flame/dz_eq_hi_green10.rgba32.inc.c"
};

ALIGNED8 static const Texture green11[] = {
#include "actors/flame/dz_eq_hi_green11.rgba32.inc.c"
};

ALIGNED8 static const Texture green12[] = {
#include "actors/flame/dz_eq_hi_green12.rgba32.inc.c"
};

ALIGNED8 static const Texture green13[] = {
#include "actors/flame/dz_eq_hi_green13.rgba32.inc.c"
};

ALIGNED8 static const Texture green14[] = {
#include "actors/flame/dz_eq_hi_green14.rgba32.inc.c"
};

ALIGNED8 static const Texture green15[] = {
#include "actors/flame/dz_eq_hi_green15.rgba32.inc.c"
};

ALIGNED8 static const Texture green16[] = {
#include "actors/flame/dz_eq_hi_green16.rgba32.inc.c"
};
    
const Gfx flame_v2_dl_green01[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, green01),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_green02[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, green02),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_green03[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, green03),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_green04[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, green04),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_green05[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, green05),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_green06[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, green06),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_green07[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, green07),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_green08[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, green08),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_green09[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, green09),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_green10[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, green10),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_green11[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, green11),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_green12[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, green12),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_green13[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, green13),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_green14[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, green14),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_green15[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, green15),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_green16[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, green16),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_seg3_dl_draw[] = {
    gsSPVertex(flame_seg3_vertex_030172E0, 4, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSPEndDisplayList(),
};
