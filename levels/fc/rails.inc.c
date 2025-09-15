static const RailDesc rails_area1[] = {
	RAIL_TRAJ(fc_area_1_spline_0176_object_0143C314_001_Rail),
	RAIL_END
};

static const RailDesc rails_area2[] = {
	RAIL_TRAJ(fc_area_2_spline_0167_object_0143E7FC_002_Rail),
	RAIL_TRAJ(fc_area_2_spline_0167_object_0143E7FC_003_Rail),
	LOOP_TRAJ(fc_area_2_spline_0167_object_0143E7FC_001_Loop, loop_desc_fc_area_2_spline_0167_object_0143E7FC_001_Loop),
	RAIL_END
};

static const SpringDesc spring_area4[] = {
	fc_area_4_spline_NurbsCurve_Spring_005,
	fc_area_4_spline_NurbsCurve_Spring_006,
	NULL
};

static const RailDesc rails_area4[] = {
	RAIL_TRAJ(fc_area_4_spline_0120_object_0143FCBC_001_Rail),
	RAIL_END
};

static const RailDesc rails_area5[] = {
	RAIL_TRAJ(fc_area_5_spline_0072_object_01448964_001_Rail),
	RAIL_TRAJ(fc_area_5_spline_0073_object_01441884_001_Rail_001),
	RAIL_TRAJ(fc_area_5_spline_0078_object_014403C4_001_Rail),
	RAIL_TRAJ(fc_area_5_spline_0106_object_014482D4_001_Rail),
	RAIL_END
};

static const SpringDesc spring_area6[] = {
	fc_area_6_spline_NurbsCurve_Spring,
	NULL
};

static const RailDesc rails_area6[] = {
	RAIL_TRAJ(fc_area_6_spline_0072_object_01448964_002_Rail),
	RAIL_TRAJ(fc_area_6_spline_0073_object_01441884_001_Rail),
	RAIL_TRAJ(fc_area_6_spline_0074_object_01440DDC_001_Rail),
	LOOP_TRAJ(fc_area_6_spline_NurbsCurve_Loop, loop_desc_fc_area_6_spline_NurbsCurve_Loop),
	RAIL_END
};

static const RailDesc rails_area7[] = {
	RAIL_TRAJ(fc_area_7_spline_0042_object_01446BC4_001_Rail_001),
	RAIL_TRAJ(fc_area_7_spline_0053_object_01443A64_001_Rail_001),
	RAIL_TRAJ(fc_area_7_spline_0057_object_01448C04_001_Rail),
	LOOP_TRAJ(fc_area_7_spline_0051_object_01445834_001_Loop, loop_desc_fc_area_7_spline_0051_object_01445834_001_Loop),
	RAIL_END
};

static const SpringDesc spring_area8[] = {
	fc_area_8_spline_NurbsCurve_Spring_001,
	fc_area_8_spline_NurbsCurve_Spring_002,
	fc_area_8_spline_NurbsCurve_Spring_003,
	NULL
};

static const RailDesc rails_area8[] = {
	RAIL_TRAJ(fc_area_8_spline_0015_object_01447104_001_Rail),
	RAIL_TRAJ(fc_area_8_spline_0042_object_01446BC4_001_Rail),
	RAIL_TRAJ(fc_area_8_spline_0053_object_01443A64_001_Rail),
	RAIL_END
};

static const SpringDesc spring_area9[] = {
	fc_area_9_spline_NurbsCurve_Spring_007,
	NULL
};

const SpringDesc* spring_descs_fc[] = {
	NULL,
	NULL,
	NULL,
	spring_area4,
	NULL,
	spring_area6,
	NULL,
	spring_area8,
	spring_area9,
};

const RailDesc* rail_descs_fc[] = {
	rails_area1,
	rails_area2,
	NULL,
	rails_area4,
	rails_area5,
	rails_area6,
	rails_area7,
	rails_area8,
	NULL,
};

