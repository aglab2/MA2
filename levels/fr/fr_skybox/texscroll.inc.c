void scroll_gfx_fr_skybox_fr_skybox_mesh() {
	Gfx *mat = segmented_to_virtual(fr_skybox_fr_skybox_mesh);

	shift_t(mat, 72, PACK_TILESIZE(0, 1));

};

void scroll_fr_level_dl_fr_skybox() {
	scroll_gfx_fr_skybox_fr_skybox_mesh();
};
