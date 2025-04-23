static const RailDesc rails_area1[] = {
	LOOP_TRAJ(wj_area_1_spline_NurbsCurve_Loop, loop_desc_wj_area_1_spline_NurbsCurve_Loop),
	LOOP_TRAJ(wj_area_1_spline_NurbsCurve_VineLoop_005, loop_desc_wj_area_1_spline_NurbsCurve_VineLoop_005),
	RAIL_END
};

static const SpringDesc spring_area2[] = {
	wj_area_2_spline_NurbsCurve_Spring,
	wj_area_2_spline_NurbsCurve_Spring_001,
	wj_area_2_spline_NurbsCurve_Spring_002,
	wj_area_2_spline_NurbsCurve_Spring_003,
	wj_area_2_spline_NurbsCurve_Spring_004,
	NULL
};

static const SpringDesc spring_area3[] = {
	wj_area_3_spline_NurbsCurve_002_Spring,
	NULL
};

static const RailDesc rails_area3[] = {
	LOOP_TRAJ(wj_area_3_spline_NurbsCurve_001_Loop, loop_desc_wj_area_3_spline_NurbsCurve_001_Loop),
	LOOP_TRAJ(wj_area_3_spline_NurbsCurve_Loop_001, loop_desc_wj_area_3_spline_NurbsCurve_Loop_001),
	RAIL_END
};

static const SpringDesc spring_area4[] = {
	wj_area_4_spline_NurbsCurve_001_Spring,
	wj_area_4_spline_NurbsCurve_001_Spring_001,
	wj_area_4_spline_NurbsCurve_001_Spring_002,
	NULL
};

static const RailDesc rails_area4[] = {
	LOOP_TRAJ(wj_area_4_spline_NurbsCurve_VineLoop_001, loop_desc_wj_area_4_spline_NurbsCurve_VineLoop_001),
	RAIL_END
};

static const SpringDesc spring_area5[] = {
	wj_area_5_spline_NurbsCurve_004_Spring,
	wj_area_5_spline_NurbsCurve_005_Spring,
	wj_area_5_spline_NurbsCurve_005_Spring_001,
	wj_area_5_spline_NurbsCurve_006_Spring,
	NULL
};

static const RailDesc rails_area5[] = {
	LOOP_TRAJ(wj_area_5_spline_NurbsCurve_003_Loop, loop_desc_wj_area_5_spline_NurbsCurve_003_Loop),
	LOOP_TRAJ(wj_area_5_spline_NurbsCurve_VineLoop_002, loop_desc_wj_area_5_spline_NurbsCurve_VineLoop_002),
	RAIL_END
};

const SpringDesc* spring_descs_wj[] = {
	NULL,
	spring_area2,
	spring_area3,
	spring_area4,
	spring_area5,
};

const RailDesc* rail_descs_wj[] = {
	rails_area1,
	NULL,
	rails_area3,
	rails_area4,
	rails_area5,
};

