static const SpringDesc spring_area1[] = {
	cg_area_1_spline_NurbsCurve_Spring,
	cg_area_1_spline_NurbsCurve_Spring_001,
	NULL
};

static const RailDesc rails_area1[] = {
	RAIL_TRAJ(cg_area_1_spline_NurbsCurve_Rail),
	RAIL_TRAJ(cg_area_1_spline_NurbsCurve_Rail_001),
	RAIL_END
};

static const RailDesc rails_area2[] = {
	RAIL_TRAJ(cg_area_2_spline_NurbsCurve_Rail_002),
	RAIL_TRAJ(cg_area_2_spline_NurbsCurve_Rail_003),
	RAIL_TRAJ(cg_area_2_spline_NurbsCurve_Rail_004),
	RAIL_TRAJ(cg_area_2_spline_NurbsCurve_Rail_005),
	RAIL_END
};

static const SpringDesc spring_area3[] = {
	cg_area_3_spline_NurbsCurve_Spring_002,
	NULL
};

const SpringDesc* spring_descs_cg[] = {
	spring_area1,
	NULL,
	spring_area3,
	NULL,
};

const RailDesc* rail_descs_cg[] = {
	rails_area1,
	rails_area2,
	NULL,
	NULL,
};

