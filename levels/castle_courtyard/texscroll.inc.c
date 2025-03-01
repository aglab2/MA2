void scroll_gfx_castle_courtyard_dl_Shape_IndexedFaceSet_009_Shape_IndexedFaceSet_001_mesh_layer_5() {
	Gfx *mat = segmented_to_virtual(castle_courtyard_dl_Shape_IndexedFaceSet_009_Shape_IndexedFaceSet_001_mesh_layer_5);

	shift_t(mat, 21, PACK_TILESIZE(0, 2));

};

void scroll_gfx_castle_courtyard_dl_Shape_IndexedFaceSet_009_Shape_IndexedFaceSet_002_mesh_layer_5() {
	Gfx *mat = segmented_to_virtual(castle_courtyard_dl_Shape_IndexedFaceSet_009_Shape_IndexedFaceSet_002_mesh_layer_5);

	shift_s_down(mat, 21, PACK_TILESIZE(0, 5));

};

void scroll_castle_courtyard() {
	scroll_gfx_castle_courtyard_dl_Shape_IndexedFaceSet_009_Shape_IndexedFaceSet_001_mesh_layer_5();
	scroll_gfx_castle_courtyard_dl_Shape_IndexedFaceSet_009_Shape_IndexedFaceSet_002_mesh_layer_5();
};
