extern const Trajectory lb_area_1_spline_attach_00FCA364_001_1[];
extern const Trajectory lb_area_1_spline_attach_00FCA364_001_2[];
extern const Trajectory lb_area_1_spline_attach_00FCA364_001_3[];
extern const Trajectory lb_area_1_spline_attach_00FCA364_001_4[];

RailDesc lb_rails_area1[] = {
	RAIL_END,
	RAIL_TRAJ(lb_area_1_spline_attach_00FCA364_001_1),
	RAIL_TRAJ(lb_area_1_spline_attach_00FCA364_001_2),
	RAIL_TRAJ(lb_area_1_spline_attach_00FCA364_001_3),
	RAIL_TRAJ(lb_area_1_spline_attach_00FCA364_001_4),
	RAIL_END
};

const RailDesc* rail_descs_lb[] = {
	lb_rails_area1,
};

