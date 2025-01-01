const Collision mhe_meteoshut_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(4),
	COL_VERTEX(300, 0, 0),
	COL_VERTEX(300, 800, 0),
	COL_VERTEX(-300, 0, 0),
	COL_VERTEX(-300, 800, 0),
	COL_TRI_INIT(SURFACE_DEFAULT, 2),
	COL_TRI(0, 1, 2),
	COL_TRI(2, 1, 3),
	COL_TRI_STOP(),
	COL_END()
};
