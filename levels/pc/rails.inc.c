static const SpringDesc spring_area2[] = {
	pc_area_2_spline_NurbsCurve_Spring,
	pc_area_2_spline_NurbsCurve_Spring_001,
	NULL
};

static const SpringDesc spring_area3[] = {
	pc_area_3_spline_NurbsCurve_Spring_002,
	NULL
};

static const RailDesc rails_area3[] = {
	LOOP_TRAJ(pc_area_3_spline_NurbsCurve_Loop, loop_desc_pc_area_3_spline_NurbsCurve_Loop),
	RAIL_END
};

static const SpringDesc spring_area4[] = {
	pc_area_4_spline_NurbsCurve_Spring_003,
	NULL
};

static const RailDesc rails_area4[] = {
	RAIL_TRAJ(pc_area_4_spline_NurbsCurve_Rail),
	RAIL_END
};

static const RailDesc rails_area5[] = {
	RAIL_TRAJ(pc_area_5_spline_NurbsCurve_Rail_001),
	RAIL_TRAJ(pc_area_5_spline_NurbsCurve_Rail_002),
	RAIL_END
};

static const SpringDesc spring_area6[] = {
	pc_area_6_spline_NurbsCurve_Spring_004,
	pc_area_6_spline_NurbsCurve_Spring_010,
	NULL
};

static const RailDesc rails_area6[] = {
	RAIL_TRAJ(pc_area_6_spline_NurbsCurve_Rail_003),
	RAIL_TRAJ(pc_area_6_spline_NurbsCurve_Rail_004),
	RAIL_TRAJ(pc_area_6_spline_NurbsCurve_Rail_005),
	RAIL_TRAJ(pc_area_6_spline_NurbsCurve_Rail_006),
	RAIL_TRAJ(pc_area_6_spline_NurbsCurve_Rail_007),
	RAIL_END
};

static const SpringDesc spring_area7[] = {
	pc_area_7_spline_NurbsCurve_Spring_005,
	pc_area_7_spline_NurbsCurve_Spring_006,
	pc_area_7_spline_NurbsCurve_Spring_008,
	pc_area_7_spline_NurbsCurve_Spring_011,
	NULL
};

static const RailDesc rails_area7[] = {
	RAIL_TRAJ(pc_area_7_spline_NurbsCurve_Rail_008),
	LOOP_TRAJ(pc_area_7_spline_NurbsCurve_Loop_001, loop_desc_pc_area_7_spline_NurbsCurve_Loop_001),
	LOOP_TRAJ(pc_area_7_spline_NurbsCurve_Loop_002, loop_desc_pc_area_7_spline_NurbsCurve_Loop_002),
	RAIL_END
};

static const SpringDesc spring_area8[] = {
	pc_area_8_spline_NurbsCurve_Spring_007,
	pc_area_8_spline_NurbsCurve_Spring_009,
	pc_area_8_spline_NurbsCurve_Spring_012,
	NULL
};

static const RailDesc rails_area8[] = {
	RAIL_TRAJ(pc_area_8_spline_NurbsCurve_Rail_009),
	LOOP_TRAJ(pc_area_8_spline_NurbsCurve_Loop_003, loop_desc_pc_area_8_spline_NurbsCurve_Loop_003),
	LOOP_TRAJ(pc_area_8_spline_NurbsCurve_Loop_004, loop_desc_pc_area_8_spline_NurbsCurve_Loop_004),
	RAIL_END
};

const SpringDesc* spring_descs_pc[] = {
	NULL,
	spring_area2,
	spring_area3,
	spring_area4,
	NULL,
	spring_area6,
	spring_area7,
	spring_area8,
};

const RailDesc* rail_descs_pc[] = {
	NULL,
	NULL,
	rails_area3,
	rails_area4,
	rails_area5,
	rails_area6,
	rails_area7,
	rails_area8,
};

