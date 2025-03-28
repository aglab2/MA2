void scroll_gfx_ow_plane_ow_plane_mesh_layer_1() {
	Gfx *mat = segmented_to_virtual(ow_plane_ow_plane_mesh_layer_1);


	shift_t(mat, 17, PACK_TILESIZE(0, 1));
	shift_s(mat, 22, PACK_TILESIZE(0, 1));

};

void scroll_castle_inside_level_geo_ow_plane() {
	scroll_gfx_ow_plane_ow_plane_mesh_layer_1();
};
