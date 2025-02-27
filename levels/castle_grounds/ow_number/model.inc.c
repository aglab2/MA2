ALIGNED8 static const Texture texture_hud_char_0[] = {
#include "textures/segment2/segment2.00000.rgba16.inc.c"
};

ALIGNED8 static const Texture texture_hud_char_1[] = {
#include "textures/segment2/segment2.00200.rgba16.inc.c"
};

ALIGNED8 static const Texture texture_hud_char_2[] = {
#include "textures/segment2/segment2.00400.rgba16.inc.c"
};

ALIGNED8 static const Texture texture_hud_char_3[] = {
#include "textures/segment2/segment2.00600.rgba16.inc.c"
};

ALIGNED8 static const Texture texture_hud_char_4[] = {
#include "textures/segment2/segment2.00800.rgba16.inc.c"
};

ALIGNED8 static const Texture texture_hud_char_5[] = {
#include "textures/segment2/segment2.00A00.rgba16.inc.c"
};

ALIGNED8 static const Texture texture_hud_char_6[] = {
#include "textures/segment2/segment2.00C00.rgba16.inc.c"
};

ALIGNED8 static const Texture texture_hud_char_7[] = {
#include "textures/segment2/segment2.00E00.rgba16.inc.c"
};

ALIGNED8 static const Texture texture_hud_char_8[] = {
#include "textures/segment2/segment2.01000.rgba16.inc.c"
};

ALIGNED8 static const Texture texture_hud_char_9[] = {
#include "textures/segment2/segment2.01200.rgba16.inc.c"
};

ALIGNED8 static const Texture texture_hud_char_percent[] = {
#include "textures/segment2/segment2.percent.rgba16.inc.c"
};

ALIGNED8 static const Texture texture_hud_char_C[] = {
#include "textures/segment2/segment2.01800.rgba16.inc.c"
};

ALIGNED8 static const Texture texture_hud_char_L[] = {
#include "textures/segment2/segment2.02A00.rgba16.inc.c"
};

ALIGNED8 static const Texture texture_hud_char_E[] = {
#include "textures/segment2/segment2.01C00.rgba16.inc.c"
};

ALIGNED8 static const Texture texture_hud_char_A[] = {
#include "textures/segment2/segment2.01400.rgba16.inc.c"
};

ALIGNED8 static const Texture texture_hud_char_R[] = {
#include "textures/segment2/segment2.03600.rgba16.inc.c"
};

ALIGNED8 static const Texture texture_hud_char_O[] = {
#include "textures/segment2/segment2.03000.rgba16.inc.c"
};

ALIGNED8 static const Texture texture_hud_char_U[] = {
#include "textures/segment2/segment2.03C00.rgba16.inc.c"
};

ALIGNED8 static const Texture texture_hud_char_S[] = {
#include "textures/segment2/segment2.03800.rgba16.inc.c"
};
    
// 0x0200EFF0 - 0x0200F038
const Gfx ow_dl_billboard_num_begin[] = {
    gsDPPipeSync(),
    gsDPSetTextureFilter(G_TF_POINT),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, (G_TX_WRAP | G_TX_NOMIRROR), G_TX_NOMASK, G_TX_NOLOD, (G_TX_WRAP | G_TX_NOMIRROR), G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 4, G_TX_NOLOD, G_TX_CLAMP, 4, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, ((16 - 1) << G_TEXTURE_IMAGE_FRAC), ((16 - 1) << G_TEXTURE_IMAGE_FRAC)),
    gsSPEndDisplayList(),
};

static const Vtx vertex_billboard_num[] = {
    {{{   -32,    -32,      0}, 0, {     0,  32<<5}, {0xff, 0xff, 0xff, 0xff}}},
    {{{    32,    -32,      0}, 0, { 32<<5,  32<<5}, {0xff, 0xff, 0xff, 0xff}}},
    {{{    32,     32,      0}, 0, { 32<<5,      0}, {0xff, 0xff, 0xff, 0xff}}},
    {{{   -32,     32,      0}, 0, {     0,      0}, {0xff, 0xff, 0xff, 0xff}}},
};

extern const Gfx ow_dl_billboard_num_end[] = {
    gsSPVertex(vertex_billboard_num, 4, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPEndDisplayList(),
};

const Gfx ow_dl_billboard_num_0[] = {
    gsSPDisplayList(ow_dl_billboard_num_begin),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_hud_char_0),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, ((16 * 16) - 1), CALC_DXT(16, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(ow_dl_billboard_num_end),
    gsDPSetAlphaCompareReal(G_AC_NONE),
    gsSPEndDisplayList(),
};

const Gfx ow_dl_billboard_num_1[] = {
    gsSPDisplayList(ow_dl_billboard_num_begin),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_hud_char_1),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, ((16 * 16) - 1), CALC_DXT(16, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(ow_dl_billboard_num_end),
    gsDPSetAlphaCompareReal(G_AC_NONE),
    gsSPEndDisplayList(),
};

const Gfx ow_dl_billboard_num_2[] = {
    gsSPDisplayList(ow_dl_billboard_num_begin),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_hud_char_2),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, ((16 * 16) - 1), CALC_DXT(16, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(ow_dl_billboard_num_end),
    gsDPSetAlphaCompareReal(G_AC_NONE),
    gsSPEndDisplayList(),
};

const Gfx ow_dl_billboard_num_3[] = {
    gsSPDisplayList(ow_dl_billboard_num_begin),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_hud_char_3),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, ((16 * 16) - 1), CALC_DXT(16, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(ow_dl_billboard_num_end),
    gsDPSetAlphaCompareReal(G_AC_NONE),
    gsSPEndDisplayList(),
};

const Gfx ow_dl_billboard_num_4[] = {
    gsSPDisplayList(ow_dl_billboard_num_begin),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_hud_char_4),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, ((16 * 16) - 1), CALC_DXT(16, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(ow_dl_billboard_num_end),
    gsDPSetAlphaCompareReal(G_AC_NONE),
    gsSPEndDisplayList(),
};

const Gfx ow_dl_billboard_num_5[] = {
    gsSPDisplayList(ow_dl_billboard_num_begin),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_hud_char_5),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, ((16 * 16) - 1), CALC_DXT(16, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(ow_dl_billboard_num_end),
    gsDPSetAlphaCompareReal(G_AC_NONE),
    gsSPEndDisplayList(),
};

const Gfx ow_dl_billboard_num_6[] = {
    gsSPDisplayList(ow_dl_billboard_num_begin),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_hud_char_6),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, ((16 * 16) - 1), CALC_DXT(16, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(ow_dl_billboard_num_end),
    gsDPSetAlphaCompareReal(G_AC_NONE),
    gsSPEndDisplayList(),
};

const Gfx ow_dl_billboard_num_7[] = {
    gsSPDisplayList(ow_dl_billboard_num_begin),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_hud_char_7),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, ((16 * 16) - 1), CALC_DXT(16, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(ow_dl_billboard_num_end),
    gsDPSetAlphaCompareReal(G_AC_NONE),
    gsSPEndDisplayList(),
};

const Gfx ow_dl_billboard_num_8[] = {
    gsSPDisplayList(ow_dl_billboard_num_begin),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_hud_char_8),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, ((16 * 16) - 1), CALC_DXT(16, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(ow_dl_billboard_num_end),
    gsDPSetAlphaCompareReal(G_AC_NONE),
    gsSPEndDisplayList(),
};

const Gfx ow_dl_billboard_num_9[] = {
    gsSPDisplayList(ow_dl_billboard_num_begin),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_hud_char_9),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, ((16 * 16) - 1), CALC_DXT(16, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(ow_dl_billboard_num_end),
    gsDPSetAlphaCompareReal(G_AC_NONE),
    gsSPEndDisplayList(),
};

const Gfx ow_dl_billboard_num_percent[] = {
    gsSPDisplayList(ow_dl_billboard_num_begin),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_hud_char_percent),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, ((16 * 16) - 1), CALC_DXT(16, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(ow_dl_billboard_num_end),
    gsDPSetAlphaCompareReal(G_AC_NONE),
    gsSPEndDisplayList(),
};

const Gfx ow_dl_billboard_num_C[] = {
    gsSPDisplayList(ow_dl_billboard_num_begin),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_hud_char_C),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, ((16 * 16) - 1), CALC_DXT(16, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(ow_dl_billboard_num_end),
    gsSPEndDisplayList(),
};

const Gfx ow_dl_billboard_num_L[] = {
    gsSPDisplayList(ow_dl_billboard_num_begin),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_hud_char_L),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, ((16 * 16) - 1), CALC_DXT(16, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(ow_dl_billboard_num_end),
    gsSPEndDisplayList(),
};

const Gfx ow_dl_billboard_num_E[] = {
    gsSPDisplayList(ow_dl_billboard_num_begin),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_hud_char_E),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, ((16 * 16) - 1), CALC_DXT(16, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(ow_dl_billboard_num_end),
    gsSPEndDisplayList(),
};

const Gfx ow_dl_billboard_num_A[] = {
    gsSPDisplayList(ow_dl_billboard_num_begin),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_hud_char_A),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, ((16 * 16) - 1), CALC_DXT(16, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(ow_dl_billboard_num_end),
    gsSPEndDisplayList(),
};

const Gfx ow_dl_billboard_num_R[] = {
    gsSPDisplayList(ow_dl_billboard_num_begin),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_hud_char_R),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, ((16 * 16) - 1), CALC_DXT(16, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(ow_dl_billboard_num_end),
    gsSPEndDisplayList(),
};

const Gfx ow_dl_billboard_num_O[] = {
    gsSPDisplayList(ow_dl_billboard_num_begin),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_hud_char_O),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, ((16 * 16) - 1), CALC_DXT(16, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(ow_dl_billboard_num_end),
    gsSPEndDisplayList(),
};

const Gfx ow_dl_billboard_num_U[] = {
    gsSPDisplayList(ow_dl_billboard_num_begin),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_hud_char_U),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, ((16 * 16) - 1), CALC_DXT(16, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(ow_dl_billboard_num_end),
    gsSPEndDisplayList(),
};

const Gfx ow_dl_billboard_num_S[] = {
    gsSPDisplayList(ow_dl_billboard_num_begin),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_hud_char_S),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, ((16 * 16) - 1), CALC_DXT(16, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(ow_dl_billboard_num_end),
    gsSPEndDisplayList(),
};
