// Flame

// 0x030172E0
static const Vtx flame_seg3_vertex_030172E0[] = {
    {{{   -25,    -25,      0}, 0, {     0,    992}, {0x00, 0x00, 0x00, 0x00}}},
    {{{    25,    -25,      0}, 0, {   992,    992}, {0x00, 0x00, 0x00, 0x00}}},
    {{{    25,     25,      0}, 0, {   992,      0}, {0x00, 0x00, 0x00, 0x00}}},
    {{{   -25,     25,      0}, 0, {     0,      0}, {0x00, 0x00, 0x00, 0x00}}},
};

// 0x03017320
ALIGNED8 static const Texture flame_seg3_texture_03017320[] = {
#include "actors/flame/flame_0.ia16.inc.c"
};

// 0x03017B20
ALIGNED8 static const Texture flame_seg3_texture_03017B20[] = {
#include "actors/flame/flame_1.ia16.inc.c"
};

// 0x03018320
ALIGNED8 static const Texture flame_seg3_texture_03018320[] = {
#include "actors/flame/flame_2.ia16.inc.c"
};

// 0x03018B20
ALIGNED8 static const Texture flame_seg3_texture_03018B20[] = {
#include "actors/flame/flame_3.ia16.inc.c"
};

// 0x03019320
ALIGNED8 static const Texture flame_seg3_texture_03019320[] = {
#include "actors/flame/flame_4.ia16.inc.c"
};

// 0x03019B20
ALIGNED8 static const Texture flame_seg3_texture_03019B20[] = {
#include "actors/flame/flame_5.ia16.inc.c"
};

// 0x0301A320
ALIGNED8 static const Texture flame_seg3_texture_0301A320[] = {
#include "actors/flame/flame_6.ia16.inc.c"
};

// 0x0301AB20
ALIGNED8 static const Texture flame_seg3_texture_0301AB20[] = {
#include "actors/flame/flame_7.ia16.inc.c"
};

ALIGNED8 static const Texture m_torch01[] = {
#include "actors/flame/m_torch01.rgba16.inc.c"
};

ALIGNED8 static const Texture m_torch02[] = {
#include "actors/flame/m_torch02.rgba16.inc.c"
};

ALIGNED8 static const Texture m_torch03[] = {
#include "actors/flame/m_torch03.rgba16.inc.c"
};

ALIGNED8 static const Texture m_torch04[] = {
#include "actors/flame/m_torch04.rgba16.inc.c"
};

ALIGNED8 static const Texture m_torch05[] = {
#include "actors/flame/m_torch05.rgba16.inc.c"
};

ALIGNED8 static const Texture m_torch06[] = {
#include "actors/flame/m_torch06.rgba16.inc.c"
};

ALIGNED8 static const Texture m_torch07[] = {
#include "actors/flame/m_torch07.rgba16.inc.c"
};

ALIGNED8 static const Texture m_torch08[] = {
#include "actors/flame/m_torch08.rgba16.inc.c"
};

ALIGNED8 static const Texture m_torch09[] = {
#include "actors/flame/m_torch09.rgba16.inc.c"
};

ALIGNED8 static const Texture m_torch10[] = {
#include "actors/flame/m_torch10.rgba16.inc.c"
};

ALIGNED8 static const Texture m_torch11[] = {
#include "actors/flame/m_torch11.rgba16.inc.c"
};

ALIGNED8 static const Texture m_torch12[] = {
#include "actors/flame/m_torch12.rgba16.inc.c"
};

ALIGNED8 static const Texture m_torch13[] = {
#include "actors/flame/m_torch13.rgba16.inc.c"
};

ALIGNED8 static const Texture m_torch14[] = {
#include "actors/flame/m_torch14.rgba16.inc.c"
};

ALIGNED8 static const Texture m_torch15[] = {
#include "actors/flame/m_torch15.rgba16.inc.c"
};

ALIGNED8 static const Texture m_torch16[] = {
#include "actors/flame/m_torch16.rgba16.inc.c"
};

static const Gfx flame_v2_common[] = {
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsDPSetCombineMode(G_CC_FADEA, G_CC_FADEA),
    gsDPSetEnvColor(255, 255, 255, 200),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 0, 255, 255, 255, 255),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

const Gfx flame_v2_dl_render01[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, m_torch01),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_render02[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, m_torch02),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_render03[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, m_torch03),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_render04[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, m_torch04),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_render05[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, m_torch05),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_render06[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, m_torch06),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_render07[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, m_torch07),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_render08[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, m_torch08),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_render09[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, m_torch09),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_render10[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, m_torch10),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_render11[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, m_torch11),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_render12[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, m_torch12),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_render13[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, m_torch13),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_render14[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, m_torch14),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_render15[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, m_torch15),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_render16[] = {
	gsDPPipeSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, m_torch16),
    gsSPBranchList(flame_v2_common),
};

const Gfx flame_v2_dl_revert[] = {
	gsSPGeometryMode(0, G_LIGHTING),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

const Gfx flame_seg3_dl_draw[] = {
    gsSPVertex(flame_seg3_vertex_030172E0, 4, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSPEndDisplayList(),
};

const Gfx flame_seg3_dl_end[] = {
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsSPSetGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsDPSetEnvColor(255, 255, 255, 255),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPEndDisplayList(),
};

// 0x0301B320 - 0x0301B3B0
const Gfx flame_seg3_dl_0301B320[] = {
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsDPSetEnvColor(255, 50, 0, 200),
    gsDPSetCombineMode(G_CC_FADEA, G_CC_FADEA),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPEndDisplayList(),
};

// 0x0301B3B0 - 0x0301B3C8
const Gfx flame_seg3_dl_0301B3B0[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, flame_seg3_texture_03017320),
    gsSPBranchList(flame_seg3_dl_0301B320),
};

// 0x0301B3C8 - 0x0301B3E0
const Gfx flame_seg3_dl_0301B3C8[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, flame_seg3_texture_03017B20),
    gsSPBranchList(flame_seg3_dl_0301B320),
};

// 0x0301B3E0 - 0x0301B3F8
const Gfx flame_seg3_dl_0301B3E0[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, flame_seg3_texture_03018320),
    gsSPBranchList(flame_seg3_dl_0301B320),
};

// 0x0301B3F8 - 0x0301B410
const Gfx flame_seg3_dl_0301B3F8[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, flame_seg3_texture_03018B20),
    gsSPBranchList(flame_seg3_dl_0301B320),
};

// 0x0301B410 - 0x0301B428
const Gfx flame_seg3_dl_0301B410[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, flame_seg3_texture_03019320),
    gsSPBranchList(flame_seg3_dl_0301B320),
};

// 0x0301B428 - 0x0301B440
const Gfx flame_seg3_dl_0301B428[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, flame_seg3_texture_03019B20),
    gsSPBranchList(flame_seg3_dl_0301B320),
};

// 0x0301B440 - 0x0301B458
const Gfx flame_seg3_dl_0301B440[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, flame_seg3_texture_0301A320),
    gsSPBranchList(flame_seg3_dl_0301B320),
};

// 0x0301B458 - 0x0301B470
const Gfx flame_seg3_dl_0301B458[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, flame_seg3_texture_0301AB20),
    gsSPBranchList(flame_seg3_dl_0301B320),
};
