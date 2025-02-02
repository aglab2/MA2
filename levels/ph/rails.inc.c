static const SpringDesc spring_area1[] = {
	ph_area_1_spline_NurbsCurve_Spring,
	ph_area_1_spline_NurbsCurve_Spring_001,
	ph_area_1_spline_NurbsCurve_Spring_002,
	ph_area_1_spline_NurbsCurve_Spring_003,
	ph_area_1_spline_NurbsCurve_Spring_004,
	ph_area_1_spline_NurbsCurve_Spring_005,
	ph_area_1_spline_NurbsCurve_Spring_006,
	ph_area_1_spline_NurbsCurve_Spring_007,
	ph_area_1_spline_NurbsCurve_Spring_008,
	NULL
};

static const RailDesc rails_area1[] = {
	RAIL_TRAJ(ph_area_1_spline_NurbsCurve_StarMove),
	RAIL_TRAJ(ph_area_1_spline_NurbsCurve_StarMove_001),
	RAIL_TRAJ(ph_area_1_spline_NurbsCurve_StarMove_002),
	RAIL_TRAJ(ph_area_1_spline_NurbsCurve_StarMove_003),
	RAIL_TRAJ(ph_area_1_spline_NurbsCurve_StarMove_004),
	RAIL_END
};

const SpringDesc* spring_descs_ph[] = {
	spring_area1,
};

const RailDesc* rail_descs_ph[] = {
	rails_area1,
};

