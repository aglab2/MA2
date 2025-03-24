static const SpringDesc spring_area1[] = {
	cg_area_1_spline_NurbsCurve_Spring,
	cg_area_1_spline_NurbsCurve_Spring_001,
	NULL
};

static const RailDesc rails_area1[] = {
	RAIL_TRAJ(cg_area_1_spline_NurbsCurve_Rail),
	RAIL_TRAJ(cg_area_1_spline_NurbsCurve_Rail_001),
	LOOP_TRAJ(cg_area_1_spline_NurbsCurve_Loop_001, loop_desc_cg_area_1_spline_NurbsCurve_Loop_001),
	RAIL_END
};

static const RailDesc rails_area2[] = {
	RAIL_TRAJ(cg_area_2_spline_NurbsCurve_Rail_004),
	RAIL_TRAJ(cg_area_2_spline_NurbsCurve_Rail_005),
	LOOP_TRAJ(cg_area_2_spline_NurbsCurve_Loop, loop_desc_cg_area_2_spline_NurbsCurve_Loop),
	RAIL_END
};

static const SpringDesc spring_area3[] = {
	cg_area_3_spline_NurbsCurve_Spring_003,
	cg_area_3_spline_NurbsCurve_Spring_005,
	cg_area_3_spline_NurbsCurve_Spring_006,
	cg_area_3_spline_NurbsCurve_Spring_007,
	cg_area_3_spline_NurbsCurve_Spring_008,
	cg_area_3_spline_NurbsCurve_Spring_009,
	cg_area_3_spline_NurbsCurve_Spring_010,
	cg_area_3_spline_NurbsCurve_Spring_011,
	cg_area_3_spline_NurbsCurve_Spring_012,
	NULL
};

static const SpringDesc spring_area4[] = {
	cg_area_4_spline_NurbsCurve_Spring_002,
	cg_area_4_spline_NurbsCurve_Spring_004,
	NULL
};

static const RailDesc rails_area4[] = {
	RAIL_TRAJ(cg_area_4_spline_NurbsCurve_Rail_006),
	RAIL_TRAJ(cg_area_4_spline_NurbsCurve_Rail_007),
	RAIL_END
};

const SpringDesc* spring_descs_cg[] = {
	spring_area1,
	NULL,
	spring_area3,
	spring_area4,
};

const RailDesc* rail_descs_cg[] = {
	rails_area1,
	rails_area2,
	NULL,
	rails_area4,
};

