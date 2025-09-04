static const SpringDesc spring_area1[] = {
	sr_area_1_spline_NurbsCurve_001_Spring,
	sr_area_1_spline_NurbsCurve_001_Spring_001,
	sr_area_1_spline_NurbsCurve_Spring,
	sr_area_1_spline_NurbsCurve_Spring_001,
	sr_area_1_spline_NurbsCurve_Spring_002,
	NULL
};

static const RailDesc rails_area1[] = {
	RAIL_TRAJ(sr_area_1_spline_0106_object_00AE1A04_001_Rail),
	RAIL_TRAJ(sr_area_1_spline_0106_object_00AE1A04_002_Rail),
	RAIL_TRAJ(sr_area_1_spline_0122_object_00ADD624_001_Rail),
	RAIL_TRAJ(sr_area_1_spline_0133_object_00ADA25C_001_Rail),
	RAIL_TRAJ(sr_area_1_spline_NurbsCurve_001_Rail),
	RAIL_TRAJ(sr_area_1_spline_NurbsCurve_Rail),
	RAIL_TRAJ(sr_area_1_spline_NurbsCurve_Rail_001),
	RAIL_TRAJ(sr_area_1_spline_NurbsCurve_Rail_002),
	RAIL_TRAJ(sr_area_1_spline_NurbsCurve_Rail_003),
	RAIL_TRAJ(sr_area_1_spline_NurbsCurve_Rail_004),
	RAIL_END
};

static const SpringDesc spring_area2[] = {
	sr_area_2_spline_NurbsCurve_Spring_004,
	NULL
};

static const RailDesc rails_area2[] = {
	RAIL_TRAJ(sr_area_2_spline_0061_object_00AFC50C_001),
	RAIL_TRAJ(sr_area_2_spline_0065_object_00AF8344_002),
	RAIL_TRAJ(sr_area_2_spline_0078_object_00AF103C_001_Rail),
	RAIL_TRAJ(sr_area_2_spline_0078_object_00AF103C_001_Rail_001),
	RAIL_TRAJ(sr_area_2_spline_0080_object_00AF037C_002_Rail),
	RAIL_TRAJ(sr_area_2_spline_0107_object_00ADF904_001_Rail),
	RAIL_TRAJ(sr_area_2_spline_NurbsCurve_001_Rail_001),
	RAIL_TRAJ(sr_area_2_spline_NurbsCurve_Rail_005),
	RAIL_END
};

static const SpringDesc spring_area3[] = {
	sr_area_3_spline_NurbsCurve_Spring_003,
	sr_area_3_spline_NurbsCurve_Spring_006,
	NULL
};

static const RailDesc rails_area3[] = {
	RAIL_TRAJ(sr_area_3_spline_0023_object_00B048AC_001_Rail),
	RAIL_TRAJ(sr_area_3_spline_0027_object_00B0210C_001_Rail),
	RAIL_TRAJ(sr_area_3_spline_NurbsCurve_001_Rail_002),
	RAIL_TRAJ(sr_area_3_spline_NurbsCurve_Rail_006),
	RAIL_END
};

const SpringDesc* spring_descs_sr[] = {
	spring_area1,
	spring_area2,
	spring_area3,
};

const RailDesc* rail_descs_sr[] = {
	rails_area1,
	rails_area2,
	rails_area3,
};

