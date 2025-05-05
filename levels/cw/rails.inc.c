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

const SpringDesc* spring_descs_cw[] = {
	NULL,
	spring_area2,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
};

const RailDesc* rail_descs_cw[] = {
	NULL,
	rails_area2,
	rails_area3,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
};

const Trajectory* starmove_trajs_cw[] = {
	cw_area_2_spline_NurbsCurve__StarMove,
};

