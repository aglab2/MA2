static const SpringDesc spring_area2[] = {
	cw_area_2_spline_NurbsCurve_Spring,
	NULL
};

static const RailDesc rails_area2[] = {
	RAIL_TRAJ(cw_area_2_spline_NurbsCurve_Rail),
	RAIL_END
};

static const RailDesc rails_area3[] = {
	RAIL_TRAJ(cw_area_3_spline_NurbsCurve_001_Rail),
	RAIL_END
};

static const SpringDesc spring_area4[] = {
	cw_area_4_spline_NurbsCurve_Spring_001,
	cw_area_4_spline_NurbsCurve_Spring_003,
	NULL
};

static const SpringDesc spring_area5[] = {
	cw_area_5_spline_NurbsCurve_Spring_002,
	cw_area_5_spline_NurbsCurve_Spring_004,
	cw_area_5_spline_NurbsCurve_Spring_005,
	NULL
};

static const RailDesc rails_area5[] = {
	RAIL_TRAJ(cw_area_5_spline_NurbsCurve_Rail_002),
	RAIL_END
};

static const RailDesc rails_area6[] = {
	RAIL_TRAJ(cw_area_6_spline_NurbsCurve_Rail_001),
	RAIL_TRAJ(cw_area_6_spline_NurbsCurve_Rail_003),
	LOOP_TRAJ(cw_area_6_spline_NurbsCurve_Loop, loop_desc_cw_area_6_spline_NurbsCurve_Loop),
	RAIL_END
};

const SpringDesc* spring_descs_cw[] = {
	NULL,
	spring_area2,
	NULL,
	spring_area4,
	spring_area5,
	NULL,
	NULL,
};

const RailDesc* rail_descs_cw[] = {
	NULL,
	rails_area2,
	rails_area3,
	NULL,
	rails_area5,
	rails_area6,
	NULL,
};

const Trajectory* starmove_trajs_cw[] = {
	cw_area_2_spline_NurbsCurve__StarMove,
	cw_area_2_spline_NurbsCurve_StarMove,
	cw_area_7_spline_0060_object_014980D4_003_StarMove,
};

