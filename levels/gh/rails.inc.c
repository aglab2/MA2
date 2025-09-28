static const SpringDesc spring_area1[] = {
	gh_area_1_spline_NurbsCurve_Spring,
	gh_area_1_spline_NurbsCurve_Spring_002,
	NULL
};

static const SpringDesc spring_area2[] = {
	gh_area_2_spline_NurbsCurve_Spring_001,
	NULL
};

static const RailDesc rails_area2[] = {
	LOOP_TRAJ(gh_area_2_spline_NurbsCurve_Loop, loop_desc_gh_area_2_spline_NurbsCurve_Loop),
	RAIL_END
};

const SpringDesc* spring_descs_gh[] = {
	spring_area1,
	spring_area2,
};

const RailDesc* rail_descs_gh[] = {
	NULL,
	rails_area2,
};

const Trajectory* starmove_trajs_gh[] = {
	gh_area_2_spline_0131_object_012A8F7C_001_StarMove,
	gh_area_2_spline_0131_object_012A8F7C_001_StarMove_001,
	gh_area_2_spline_0131_object_012A8F7C_001_StarMove_002,
};

