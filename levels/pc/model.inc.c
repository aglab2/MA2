Vtx pc_dl_a1_mesh_layer_1_vtx_0[24] = {
	{{ {-20000, 13339, 20000}, 0, {-16, 1008}, {0, 129, 0, 255} }},
	{{ {-20000, 13339, -20000}, 0, {-16, -16}, {0, 129, 0, 255} }},
	{{ {20000, 13339, -20000}, 0, {1008, -16}, {0, 129, 0, 255} }},
	{{ {20000, 13339, 20000}, 0, {1008, 1008}, {0, 129, 0, 255} }},
	{{ {-20000, -13339, 20000}, 0, {-16, 1008}, {0, 127, 0, 255} }},
	{{ {20000, -13339, 20000}, 0, {1008, 1008}, {0, 127, 0, 255} }},
	{{ {20000, -13339, -20000}, 0, {1008, -16}, {0, 127, 0, 255} }},
	{{ {-20000, -13339, -20000}, 0, {-16, -16}, {0, 127, 0, 255} }},
	{{ {20000, 13339, 20000}, 0, {1008, 1008}, {129, 0, 0, 255} }},
	{{ {20000, 13339, -20000}, 0, {1008, -16}, {129, 0, 0, 255} }},
	{{ {20000, -13339, -20000}, 0, {1008, -16}, {129, 0, 0, 255} }},
	{{ {20000, -13339, 20000}, 0, {1008, 1008}, {129, 0, 0, 255} }},
	{{ {-20000, 13339, -20000}, 0, {-16, -16}, {127, 0, 0, 255} }},
	{{ {-20000, 13339, 20000}, 0, {-16, 1008}, {127, 0, 0, 255} }},
	{{ {-20000, -13339, 20000}, 0, {-16, 1008}, {127, 0, 0, 255} }},
	{{ {-20000, -13339, -20000}, 0, {-16, -16}, {127, 0, 0, 255} }},
	{{ {20000, 13339, -20000}, 0, {1008, -16}, {0, 0, 127, 255} }},
	{{ {-20000, 13339, -20000}, 0, {-16, -16}, {0, 0, 127, 255} }},
	{{ {-20000, -13339, -20000}, 0, {-16, -16}, {0, 0, 127, 255} }},
	{{ {20000, -13339, -20000}, 0, {1008, -16}, {0, 0, 127, 255} }},
	{{ {-20000, 13339, 20000}, 0, {-16, 1008}, {0, 0, 129, 255} }},
	{{ {20000, 13339, 20000}, 0, {1008, 1008}, {0, 0, 129, 255} }},
	{{ {20000, -13339, 20000}, 0, {1008, 1008}, {0, 0, 129, 255} }},
	{{ {-20000, -13339, 20000}, 0, {-16, 1008}, {0, 0, 129, 255} }},
};

Gfx pc_dl_a1_mesh_layer_1_tri_0[] = {
	gsSPVertex(pc_dl_a1_mesh_layer_1_vtx_0 + 0, 24, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
	gsSPEndDisplayList(),
};

Gfx mat_pc_dl_f3dlite_material[] = {
	gsSPLightColor(LIGHT_1, 0x515151FF),
	gsSPLightColor(LIGHT_2, 0x242424FF),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_pc_dl_f3dlite_material[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx pc_dl_a1_mesh_layer_1[] = {
	gsSPDisplayList(mat_pc_dl_f3dlite_material),
	gsSPDisplayList(pc_dl_a1_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_pc_dl_f3dlite_material),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

