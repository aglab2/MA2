void scroll_gfx_msp_skybox_ms_skybox_mesh() {
	Gfx *mat = segmented_to_virtual(msp_skybox_ms_skybox_mesh);

	shift_t(mat, 73, PACK_TILESIZE(0, 1));

};

void scroll_msp_level_dl_msp_skybox() {
	scroll_gfx_msp_skybox_ms_skybox_mesh();
};
