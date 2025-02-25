void scroll_gfx_aq_water_aq_water_mesh_layer_5() {
	Gfx *mat = segmented_to_virtual(aq_water_aq_water_mesh_layer_5);

	shift_t(mat, 21, PACK_TILESIZE(0, 3));

};

void scroll_aq_level_geo_aq_water() {
	scroll_gfx_aq_water_aq_water_mesh_layer_5();
};
