Vtx ss1_dl_Plane_mesh_layer_1_vtx_cull[8] = {
	{{ {-7238, -2500, 6265}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-7238, -2500, 6265}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-7238, -2500, -6265}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-7238, -2500, -6265}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {7238, -2500, 6265}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {7238, -2500, 6265}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {7238, -2500, -6265}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {7238, -2500, -6265}, 0, {0, 0}, {0, 0, 0, 0} }},
};

Vtx ss1_dl_Plane_mesh_layer_1_vtx_0[4] = {
	{{ {-7238, -2500, 6265}, 0, {-16, 1008}, {0, 127, 0, 255} }},
	{{ {7238, -2500, 6265}, 0, {1008, 1008}, {0, 127, 0, 255} }},
	{{ {7238, -2500, -6265}, 0, {1008, -16}, {0, 127, 0, 255} }},
	{{ {-7238, -2500, -6265}, 0, {-16, -16}, {0, 127, 0, 255} }},
};

Gfx ss1_dl_Plane_mesh_layer_1[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(ss1_dl_Plane_mesh_layer_1_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
	gsSPLightColor(LIGHT_1, 0xFFFFFFFF),
	gsSPLightColor(LIGHT_2, 0x7F7F7FFF),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPSetOtherMode(G_SETOTHERMODE_H, 4, 20, G_AD_NOISE | G_CD_MAGICSQ | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_NONE | G_TL_TILE | G_TD_CLAMP | G_TP_PERSP | G_CYC_1CYCLE | G_PM_1PRIMITIVE),
	gsSPSetOtherMode(G_SETOTHERMODE_L, 0, 3, G_AC_NONE | G_ZS_PIXEL),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPVertex(ss1_dl_Plane_mesh_layer_1_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsDPPipeSync(),
	gsSPSetOtherMode(G_SETOTHERMODE_H, 4, 20, G_CD_MAGICSQ | G_AD_DISABLE | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_NONE | G_TL_TILE | G_TD_CLAMP | G_TP_PERSP | G_CYC_1CYCLE | G_PM_1PRIMITIVE),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

