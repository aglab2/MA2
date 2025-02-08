extern Gfx mat_hb_dl_Quicksand2_sa2mdl_0_f3d[];
void scroll_gfx_mat_hb_dl_Quicksand5_sa2mdl_0_f3d() {
	Gfx *mat = segmented_to_virtual(mat_hb_dl_Quicksand2_sa2mdl_0_f3d);

	shift_t(mat, 13, PACK_TILESIZE(0, 1));

};

void scroll_hb() {
	scroll_gfx_mat_hb_dl_Quicksand5_sa2mdl_0_f3d();
};
