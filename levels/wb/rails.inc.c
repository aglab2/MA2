static const SpringDesc spring_area1[] = {
	wb_area_1_spline_Spring_NurbsCurve,
	wb_area_1_spline_Spring_NurbsCurve_001,
	wb_area_1_spline_Spring_NurbsCurve_009,
	wb_area_1_spline_Spring_NurbsCurve_011,
	NULL
};

static const SpringDesc spring_area2[] = {
	wb_area_2_spline_Spring_NurbsCurve_002,
	wb_area_2_spline_Spring_NurbsCurve_003,
	wb_area_2_spline_Spring_NurbsCurve_004,
	wb_area_2_spline_Spring_NurbsCurve_005,
	wb_area_2_spline_Spring_NurbsCurve_006,
	wb_area_2_spline_Spring_NurbsCurve_007,
	wb_area_2_spline_Spring_NurbsCurve_008,
	wb_area_2_spline_Spring_NurbsCurve_010,
	NULL
};

const SpringDesc* spring_descs_wb[] = {
	spring_area1,
	spring_area2,
};

const Trajectory* starmove_trajs_wb[] = {
	wb_area_1_spline_NurbsCurve_StarMove,
};

