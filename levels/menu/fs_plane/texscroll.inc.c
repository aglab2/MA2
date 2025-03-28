void scroll_gfx_fs_plane_fs_plane_mesh_layer_1() {
	Gfx *mat = segmented_to_virtual(fs_plane_fs_plane_mesh_layer_1);


	shift_t(mat, 17, PACK_TILESIZE(0, 1));
	shift_s(mat, 22, PACK_TILESIZE(0, 1));

};

void scroll_menu_level_geo_fs_plane() {
	scroll_gfx_fs_plane_fs_plane_mesh_layer_1();
};
