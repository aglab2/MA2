static const SpringDesc spring_area1[] = {
	gf_area_1_spline_NurbsCurve_Spring,
	gf_area_1_spline_NurbsCurve_Spring_001,
	gf_area_1_spline_NurbsCurve_Spring_002,
	gf_area_1_spline_NurbsCurve_Spring_003,
	gf_area_1_spline_NurbsCurve_Spring_004,
	gf_area_1_spline_NurbsCurve_Spring_005,
	gf_area_1_spline_NurbsCurve_Spring_015,
	NULL
};

static const RailDesc rails_area1[] = {
	RAIL_TRAJ(gf_area_1_spline_NurbsCurve_Rail),
	RAIL_TRAJ(gf_area_1_spline_NurbsCurve_Rail_001),
	RAIL_TRAJ(gf_area_1_spline_NurbsCurve_Rail_006),
	RAIL_TRAJ(gf_area_1_spline_NurbsCurve_Rail_007),
	RAIL_TRAJ(gf_area_1_spline_NurbsCurve_Rail_008),
	LOOP_TRAJ(gf_area_1_spline_NurbsCurve_Loop, loop_desc_gf_area_1_spline_NurbsCurve_Loop),
	RAIL_END
};

static const SpringDesc spring_area2[] = {
	gf_area_2_spline_NurbsCurve_Spring_006,
	gf_area_2_spline_NurbsCurve_Spring_007,
	gf_area_2_spline_NurbsCurve_Spring_008,
	gf_area_2_spline_NurbsCurve_Spring_009,
	NULL
};

static const RailDesc rails_area2[] = {
	RAIL_TRAJ(gf_area_2_spline_NurbsCurve_Rail_002),
	RAIL_TRAJ(gf_area_2_spline_NurbsCurve_Rail_003),
	RAIL_TRAJ(gf_area_2_spline_NurbsCurve_Rail_004),
	RAIL_TRAJ(gf_area_2_spline_NurbsCurve_Rail_009),
	LOOP_TRAJ(gf_area_2_spline_NurbsCurve_Loop_001, loop_desc_gf_area_2_spline_NurbsCurve_Loop_001),
	LOOP_TRAJ(gf_area_2_spline_NurbsCurve_Loop_002, loop_desc_gf_area_2_spline_NurbsCurve_Loop_002),
	LOOP_TRAJ(gf_area_2_spline_NurbsCurve_Loop_003, loop_desc_gf_area_2_spline_NurbsCurve_Loop_003),
	LOOP_TRAJ(gf_area_2_spline_NurbsCurve_VineLoop_005, loop_desc_gf_area_2_spline_NurbsCurve_VineLoop_005),
	RAIL_END
};

static const SpringDesc spring_area3[] = {
	gf_area_3_spline_NurbsCurve_Spring_010,
	gf_area_3_spline_NurbsCurve_Spring_011,
	gf_area_3_spline_NurbsCurve_Spring_012,
	gf_area_3_spline_NurbsCurve_Spring_013,
	gf_area_3_spline_NurbsCurve_Spring_014,
	NULL
};

static const SpringDesc spring_area4[] = {
	gf_area_4_spline_NurbsCurve_Spring_016,
	NULL
};

static const RailDesc rails_area4[] = {
	LOOP_TRAJ(gf_area_4_spline_NurbsCurve_Loop_004, loop_desc_gf_area_4_spline_NurbsCurve_Loop_004),
	LOOP_TRAJ(gf_area_4_spline_NurbsCurve_Loop_005, loop_desc_gf_area_4_spline_NurbsCurve_Loop_005),
	RAIL_END
};

const SpringDesc* spring_descs_gf[] = {
	spring_area1,
	spring_area2,
	spring_area3,
	spring_area4,
};

const RailDesc* rail_descs_gf[] = {
	rails_area1,
	rails_area2,
	NULL,
	rails_area4,
};

