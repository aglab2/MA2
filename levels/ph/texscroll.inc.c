void scroll_ph_dl_object_0128B5BC_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 17;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ph_dl_object_0128B5BC_mesh_layer_5_vtx_0);

	deltaY = (int)(0.019999999552965164 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ph_dl_object_0128B80C_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 17;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ph_dl_object_0128B80C_mesh_layer_5_vtx_0);

	deltaX = (int)(0.11999999731779099 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ph() {
	scroll_ph_dl_object_0128B5BC_mesh_layer_5_vtx_0();
	scroll_ph_dl_object_0128B80C_mesh_layer_5_vtx_0();
};
