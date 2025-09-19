static const SpringDesc spring_area1[] = {
	gh_area_1_spline_NurbsCurve_Spring,
	gh_area_1_spline_NurbsCurve_Spring_001,
	NULL
};

static const RailDesc rails_area2[] = {
	LOOP_TRAJ(gh_area_2_spline_NurbsCurve_Loop, loop_desc_gh_area_2_spline_NurbsCurve_Loop),
	RAIL_END
};

const SpringDesc* spring_descs_gh[] = {
	spring_area1,
	NULL,
};

const RailDesc* rail_descs_gh[] = {
	NULL,
	rails_area2,
};

