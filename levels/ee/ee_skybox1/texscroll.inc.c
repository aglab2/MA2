void scroll_gfx_mat_ee_skybox1_TransparentSpace_sa2mdl_0_f3d_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ee_skybox1_TransparentSpace_sa2mdl_0_f3d_layer1);

	shift_t(mat, 15, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_ee_skybox1_TransparentSpace_sa2mdl_1_f3d_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ee_skybox1_TransparentSpace_sa2mdl_1_f3d_layer1);

	shift_t(mat, 17, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_ee_skybox1_TransparentSpace_sa2mdl_2_f3d_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ee_skybox1_TransparentSpace_sa2mdl_2_f3d_layer1);

	shift_t(mat, 15, PACK_TILESIZE(0, 1));

};

void scroll_ee_level_dl_ee_skybox1() {
	scroll_gfx_mat_ee_skybox1_TransparentSpace_sa2mdl_0_f3d_layer1();
	scroll_gfx_mat_ee_skybox1_TransparentSpace_sa2mdl_1_f3d_layer1();
	scroll_gfx_mat_ee_skybox1_TransparentSpace_sa2mdl_2_f3d_layer1();
};
