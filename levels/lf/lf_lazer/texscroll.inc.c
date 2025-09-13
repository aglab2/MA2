void scroll_gfx_lf_lazer_001_object_0130597C_mesh_layer_5() {
	Gfx *mat = segmented_to_virtual(lf_lazer_001_object_0130597C_mesh_layer_5);

	shift_s(mat, 18, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 18, PACK_TILESIZE(0, 3));

};

void scroll_gfx_lf_lazer_002_object_01305504_mesh_layer_5() {
	Gfx *mat = segmented_to_virtual(lf_lazer_002_object_01305504_mesh_layer_5);

	shift_s(mat, 18, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 18, PACK_TILESIZE(0, 3));

};

void scroll_lf_level_geo_lf_lazer() {
	scroll_gfx_lf_lazer_001_object_0130597C_mesh_layer_5();
	scroll_gfx_lf_lazer_002_object_01305504_mesh_layer_5();
};
