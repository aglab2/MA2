void scroll_gfx_lf_skybox_lf_space_mesh() {
	Gfx *mat = segmented_to_virtual(lf_skybox_lf_space_mesh);

	shift_s(mat, 45, PACK_TILESIZE(0, 1));

};

void scroll_lf_level_dl_lf_skybox() {
	scroll_gfx_lf_skybox_lf_space_mesh();
};
