void scroll_gfx_end_dl_fs_plane_mesh_layer_1() {
	Gfx *mat = segmented_to_virtual(end_dl_fs_plane_mesh_layer_1);


	shift_t(mat, 13, PACK_TILESIZE(0, 1));
	shift_s(mat, 18, PACK_TILESIZE(0, 1));

};

void scroll_end() {
	scroll_gfx_end_dl_fs_plane_mesh_layer_1();
};
