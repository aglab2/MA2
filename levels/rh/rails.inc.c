static const SpringDesc spring_area1[] = {
	rh_area_1_spline_Spring_NurbsCurve,
	rh_area_1_spline_Spring_NurbsCurve_001,
	rh_area_1_spline_Spring_NurbsCurve_002,
	rh_area_1_spline_Spring_NurbsCurve_003,
	rh_area_1_spline_Spring_NurbsCurve_012,
	rh_area_1_spline_Spring_NurbsCurve_013,
	rh_area_1_spline_Spring_NurbsCurve_014,
	rh_area_1_spline_Spring_NurbsCurve_015,
	NULL
};

static const RailDesc rails_area1[] = {
	RAIL_TRAJ(rh_area_1_spline_Rail_NurbsCurve),
	RAIL_TRAJ(rh_area_1_spline_Rail_NurbsCurve_001),
	LOOP_TRAJ(rh_area_1_spline_Loop_NurbsCurve, loop_desc_rh_area_1_spline_Loop_NurbsCurve),
	LOOP_TRAJ(rh_area_1_spline_Loop_NurbsCurve_001, loop_desc_rh_area_1_spline_Loop_NurbsCurve_001),
	RAIL_END
};

static const SpringDesc spring_area2[] = {
	rh_area_2_spline_Spring_NurbsCurve_004,
	rh_area_2_spline_Spring_NurbsCurve_005,
	rh_area_2_spline_Spring_NurbsCurve_006,
	rh_area_2_spline_Spring_NurbsCurve_007,
	rh_area_2_spline_Spring_NurbsCurve_008,
	rh_area_2_spline_Spring_NurbsCurve_009,
	rh_area_2_spline_Spring_NurbsCurve_010,
	rh_area_2_spline_Spring_NurbsCurve_011,
	rh_area_2_spline_Spring_NurbsCurve_016,
	rh_area_2_spline_Spring_NurbsCurve_017,
	NULL
};

static const RailDesc rails_area2[] = {
	LOOP_TRAJ(rh_area_2_spline_Loop_NurbsCurve_002, loop_desc_rh_area_2_spline_Loop_NurbsCurve_002),
	RAIL_END
};

static const RailDesc rails_area3[] = {
	LOOP_TRAJ(rh_area_3_spline_Loop_NurbsCurve_007, loop_desc_rh_area_3_spline_Loop_NurbsCurve_007),
	LOOP_TRAJ(rh_area_3_spline_Loop_NurbsCurve_008, loop_desc_rh_area_3_spline_Loop_NurbsCurve_008),
	RAIL_END
};

static const SpringDesc spring_area6[] = {
	rh_area_6_spline_Spring_NurbsCurve_018,
	rh_area_6_spline_Spring_NurbsCurve_019,
	rh_area_6_spline_Spring_NurbsCurve_020,
	NULL
};

static const RailDesc rails_area6[] = {
	LOOP_TRAJ(rh_area_6_spline_Loop_NurbsCurve_003, loop_desc_rh_area_6_spline_Loop_NurbsCurve_003),
	LOOP_TRAJ(rh_area_6_spline_Loop_NurbsCurve_004, loop_desc_rh_area_6_spline_Loop_NurbsCurve_004),
	LOOP_TRAJ(rh_area_6_spline_Loop_NurbsCurve_005, loop_desc_rh_area_6_spline_Loop_NurbsCurve_005),
	LOOP_TRAJ(rh_area_6_spline_Loop_NurbsCurve_006, loop_desc_rh_area_6_spline_Loop_NurbsCurve_006),
	RAIL_END
};

static const SpringDesc spring_area7[] = {
	rh_area_7_spline_Spring_NurbsCurve_021,
	NULL
};

const SpringDesc* spring_descs_rh[] = {
	spring_area1,
	spring_area2,
	NULL,
	NULL,
	NULL,
	spring_area6,
	spring_area7,
};

const RailDesc* rail_descs_rh[] = {
	rails_area1,
	rails_area2,
	rails_area3,
	NULL,
	NULL,
	rails_area6,
	NULL,
};

