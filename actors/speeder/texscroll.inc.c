void scroll_speeder_object_00743C6C_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 6;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(speeder_object_00743C6C_mesh_layer_1_vtx_1);

	deltaY = (int)(0.72999999523162842 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_speeder_object_00743C6C_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 10;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(speeder_object_00743C6C_mesh_layer_1_vtx_2);

	deltaY = (int)(0.6399999856948853 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_actor_geo_speeder() {
	scroll_speeder_object_00743C6C_mesh_layer_1_vtx_1();
	scroll_speeder_object_00743C6C_mesh_layer_1_vtx_2();
};
