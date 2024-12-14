void scroll_ramp_ramp_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 12;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ramp_ramp_mesh_layer_1_vtx_3);

	deltaY = (int)(0.3700000047683716 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_gfx_ramp_ramp_mesh_layer_1() {
	Gfx *mat = segmented_to_virtual(ramp_ramp_mesh_layer_1);

	shift_t(mat, 49, PACK_TILESIZE(0, 1));

};

void scroll_actor_geo_ramp() {
	scroll_ramp_ramp_mesh_layer_1_vtx_3();
	scroll_gfx_ramp_ramp_mesh_layer_1();
};
