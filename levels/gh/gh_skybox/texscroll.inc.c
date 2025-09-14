void scroll_gfx_gh_skybox_gh_skybox_mesh() {
	Gfx *mat = segmented_to_virtual(gh_skybox_gh_skybox_mesh);


	shift_t(mat, 305, PACK_TILESIZE(0, 2));
	shift_t(mat, 346, PACK_TILESIZE(0, 2));

};

void scroll_gh_level_dl_gh_skybox() {
	scroll_gfx_gh_skybox_gh_skybox_mesh();
};
