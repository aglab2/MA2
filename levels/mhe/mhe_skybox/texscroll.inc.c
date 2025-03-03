void scroll_gfx_mhe_skybox_mhe_skybox_mesh() {
	Gfx *mat = segmented_to_virtual(mhe_skybox_mhe_skybox_mesh);

	shift_t(mat, 73, PACK_TILESIZE(0, 1));

};

void scroll_mhe_level_dl_mhe_skybox() {
	scroll_gfx_mhe_skybox_mhe_skybox_mesh();
};
