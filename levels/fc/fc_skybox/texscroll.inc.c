void scroll_gfx_fc_skybox_fc_space_mesh() {
	Gfx *mat = segmented_to_virtual(fc_skybox_fc_space_mesh);

	shift_t(mat, 73, PACK_TILESIZE(0, 1));

};

void scroll_fc_level_dl_fc_skybox() {
	scroll_gfx_fc_skybox_fc_space_mesh();
};
