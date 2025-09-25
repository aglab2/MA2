#include "levels/chao/visual/header.inc.h"

void scroll_gfx_mat_chao_dl_objLandTableRace_sa2blvl_0_f3d_layer5() {
	Gfx *mat = segmented_to_virtual(mat_chao_dl_objLandTableRace_sa2blvl_0_f3d_layer5);


	shift_s(mat, 12, PACK_TILESIZE(0, 1));
	shift_t(mat, 14, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_chao_dl_objLandTableRace_sa2blvl_3_f3d_layer5() {
	Gfx *mat = segmented_to_virtual(mat_chao_dl_objLandTableRace_sa2blvl_3_f3d_layer5);


	shift_t(mat, 12, PACK_TILESIZE(0, 1));
	shift_t(mat, 14, PACK_TILESIZE(0, 2));

};

void scroll_gfx_mat_chao_dl_Waterfalls3_sa2mdl_0_f3d() {
	Gfx *mat = segmented_to_virtual(mat_chao_dl_Waterfalls1_sa2mdl_0_f3d);

	shift_t(mat, 10, PACK_TILESIZE(0, 1));

};

void scroll_chao_visual() {
	scroll_gfx_mat_chao_dl_objLandTableRace_sa2blvl_0_f3d_layer5();
	scroll_gfx_mat_chao_dl_objLandTableRace_sa2blvl_3_f3d_layer5();
	scroll_gfx_mat_chao_dl_Waterfalls3_sa2mdl_0_f3d();
};
