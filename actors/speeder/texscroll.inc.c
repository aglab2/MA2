void scroll_gfx_speeder_object_00743C6C_mesh_layer_1() {
	Gfx *mat = segmented_to_virtual(speeder_object_00743C6C_mesh_layer_1);


	shift_t_down(mat, 47, PACK_TILESIZE(0, 7));
	shift_t_down(mat, 57, PACK_TILESIZE(0, 9));

};

void scroll_actor_geo_speeder() {
	scroll_gfx_speeder_object_00743C6C_mesh_layer_1();
};
