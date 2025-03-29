static const RailDesc rails_area3[] = {
	RAIL_TRAJ(ce_area_3_spline_2459_object_00CFC480_001),
	RAIL_TRAJ(ce_area_3_spline_2473_object_00CFEC08_001),
	RAIL_TRAJ(ce_area_3_spline_z_1681_object_00D2405C_001),
	RAIL_TRAJ(ce_area_3_spline_z_1757_object_00CA7120_001),
	RAIL_TRAJ(ce_area_3_spline_z_1757_object_00CA7120_002),
	RAIL_END
};

static const SpringDesc spring_area5[] = {
	ce_area_5_spline_Spring_NurbsCurve,
	ce_area_5_spline_Spring_NurbsCurve_001,
	ce_area_5_spline_Spring_NurbsCurve_002,
	ce_area_5_spline_Spring_NurbsCurve_003,
	ce_area_5_spline_Spring_NurbsCurve_004,
	NULL
};

static const RailDesc rails_area5[] = {
	RAIL_TRAJ(ce_area_5_spline_0969_object_00CD1C78_001),
	RAIL_TRAJ(ce_area_5_spline_2561_object_00D05490_001),
	RAIL_END
};

static const SpringDesc spring_area6[] = {
	ce_area_6_spline_NurbsCurve_Spring,
	NULL
};

static const RailDesc rails_area6[] = {
	RAIL_TRAJ(ce_area_6_spline_0870_object_00D2DB3C_001),
	RAIL_TRAJ(ce_area_6_spline_0969_object_00CD1C78_002),
	RAIL_TRAJ(ce_area_6_spline_2443_object_00D39804_002),
	RAIL_TRAJ(ce_area_6_spline_2480_object_00D39A6C_001),
	LOOP_TRAJ(ce_area_6_spline_NurbsCurve_Loop, loop_desc_ce_area_6_spline_NurbsCurve_Loop),
	RAIL_END
};

static const RailDesc rails_area7[] = {
	RAIL_TRAJ(ce_area_7_spline_2443_object_00D39804_001),
	RAIL_TRAJ(ce_area_7_spline_2449_object_00CFAC10_001),
	RAIL_TRAJ(ce_area_7_spline_2479_object_00D39A34_001),
	RAIL_END
};

const SpringDesc* spring_descs_ce[] = {
	NULL,
	NULL,
	NULL,
	NULL,
	spring_area5,
	spring_area6,
	NULL,
	NULL,
	NULL,
	NULL,
};

const RailDesc* rail_descs_ce[] = {
	NULL,
	NULL,
	rails_area3,
	NULL,
	rails_area5,
	rails_area6,
	rails_area7,
	NULL,
	NULL,
	NULL,
};

