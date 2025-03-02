static const SpringDesc spring_area1[] = {
	mh_area_1_spline_NurbsCurve_Spring,
	mh_area_1_spline_NurbsCurve_Spring_001,
	mh_area_1_spline_NurbsCurve_Spring_002,
	mh_area_1_spline_NurbsCurve_Spring_003,
	mh_area_1_spline_NurbsCurve_Spring_004,
	mh_area_1_spline_NurbsCurve_Spring_006,
	mh_area_1_spline_NurbsCurve_Spring_011,
	mh_area_1_spline_NurbsCurve_Spring_012,
	mh_area_1_spline_NurbsCurve_Spring_019,
	NULL
};

static const RailDesc rails_area1[] = {
	RAIL_TRAJ(mh_area_1_spline_1089_object_00BE4D68_001),
	RAIL_TRAJ(mh_area_1_spline_1089_object_00BE4D68_002),
	LOOP_TRAJ(mh_area_1_spline_NurbsCurve_Loop, loop_desc_mh_area_1_spline_NurbsCurve_Loop),
	RAIL_END
};

static const SpringDesc spring_area2[] = {
	mh_area_2_spline_NurbsCurve_Spring_005,
	mh_area_2_spline_NurbsCurve_Spring_007,
	mh_area_2_spline_NurbsCurve_Spring_008,
	mh_area_2_spline_NurbsCurve_Spring_017,
	mh_area_2_spline_NurbsCurve_Spring_018,
	mh_area_2_spline_NurbsCurve_Spring_020,
	NULL
};

static const SpringDesc spring_area3[] = {
	mh_area_3_spline_NurbsCurve_Spring_009,
	mh_area_3_spline_NurbsCurve_Spring_010,
	mh_area_3_spline_NurbsCurve_Spring_021,
	mh_area_3_spline_NurbsCurve_Spring_022,
	mh_area_3_spline_NurbsCurve_Spring_023,
	mh_area_3_spline_NurbsCurve_Spring_024,
	mh_area_3_spline_NurbsCurve_Spring_025,
	NULL
};

static const RailDesc rails_area3[] = {
	RAIL_TRAJ(mh_area_3_spline_1088_object_00BC6BA0_002),
	RAIL_TRAJ(mh_area_3_spline_1088_object_00BC6BA0_003),
	LOOP_TRAJ(mh_area_3_spline_NurbsCurve_Loop_001, loop_desc_mh_area_3_spline_NurbsCurve_Loop_001),
	LOOP_TRAJ(mh_area_3_spline_NurbsCurve_Loop_002, loop_desc_mh_area_3_spline_NurbsCurve_Loop_002),
	RAIL_END
};

static const SpringDesc spring_area4[] = {
	mh_area_4_spline_NurbsCurve_Spring_013,
	mh_area_4_spline_NurbsCurve_Spring_014,
	mh_area_4_spline_NurbsCurve_Spring_015,
	mh_area_4_spline_NurbsCurve_Spring_016,
	mh_area_4_spline_Spring_NurbsCurve,
	NULL
};

static const RailDesc rails_area4[] = {
	LOOP_TRAJ(mh_area_4_spline_Loop_NurbsCurve, loop_desc_mh_area_4_spline_Loop_NurbsCurve),
	RAIL_END
};

const SpringDesc* spring_descs_mh[] = {
	spring_area1,
	spring_area2,
	spring_area3,
	spring_area4,
};

const RailDesc* rail_descs_mh[] = {
	rails_area1,
	NULL,
	rails_area3,
	rails_area4,
};

