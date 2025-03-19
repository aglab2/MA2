void scroll_gfx_ss2_skybox_fr_skybox_mesh() {
	Gfx *mat = segmented_to_virtual(ss2_skybox_fr_skybox_mesh);

	shift_t(mat, 72, PACK_TILESIZE(0, 1));

};

void scroll_ss2_level_dl_ss2_skybox() {
	scroll_gfx_ss2_skybox_fr_skybox_mesh();
};
