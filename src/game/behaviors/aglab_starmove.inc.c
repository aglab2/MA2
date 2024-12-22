extern const Trajectory* starmove_trajs_ph[];
static const Trajectory** k_starmove_trajectories[] = 
{
    [ LEVEL_PH ] = starmove_trajs_ph,
};

#define oStarMoveTraj OBJECT_FIELD_VPTR(0x1B)
#define oStarMoveCurPoint oF8
#define oStarMoveProgress oFloatFC

static void bhv_starmove_init()
{
    const Trajectory** trajs = segmented_to_virtual(k_starmove_trajectories[gCurrLevelNum]);
    o->oStarMoveTraj = segmented_to_virtual(trajs[GET_BPARAM3(o->oBehParams) - 1]);
}

static void bhv_starmove_loop()
{
    const Trajectory* traj = o->oStarMoveTraj;
    // Advance along the zipline
    {
        Vec3f trajCurPoint = {traj[o->oStarMoveCurPoint + 1], traj[o->oStarMoveCurPoint + 2], traj[o->oStarMoveCurPoint + 3]};
        Vec3f trajNextPoint = {traj[o->oStarMoveCurPoint + 4 + 1], traj[o->oStarMoveCurPoint + 4 + 2], traj[o->oStarMoveCurPoint + 4 + 3]};
        Vec3f trajDirection;
        vec3f_diff(trajDirection, trajNextPoint, trajCurPoint);

        f32 dirMag = vec3_mag(trajDirection);
        f32 velocity = 40.f;
        f32 movAmt = velocity / dirMag;

        o->oStarMoveProgress += movAmt;
        
#if 0
        print_text_fmt_int(20, 20 + 40 * GET_BPARAM3(o->oBehParams), "X %d", (int) trajDirection[0]);
        print_text_fmt_int(20, 40 + 40 * GET_BPARAM3(o->oBehParams), "Z %d", (int) trajDirection[2]);
        print_text_fmt_int(120, 40 + 40 * GET_BPARAM3(o->oBehParams), "P %d", (int) (o->oStarMoveProgress * 1000));
        print_text_fmt_int(120, 20 + 40 * GET_BPARAM3(o->oBehParams), "T %d", (int) (o->oStarMoveCurPoint));
        print_text_fmt_int(220, 20 + 40 * GET_BPARAM3(o->oBehParams), "D %d", (int) (dirMag));
        print_text_fmt_int(220, 40 + 40 * GET_BPARAM3(o->oBehParams), "M %d", (int) (movAmt * 1000));
#endif

        if (o->oStarMoveProgress >= 1.f)
        {
            if (traj[o->oStarMoveCurPoint + 8] == -1)
            {
                o->oStarMoveProgress = o->oStarMoveProgress - 1.f;
                o->oStarMoveCurPoint = 0;
            }
            else
            {
                o->oStarMoveProgress = o->oStarMoveProgress - 1.f;
                o->oStarMoveCurPoint += 4;
            }
        }
    }
    {
        Vec3f trajCurPoint = {traj[o->oStarMoveCurPoint + 1], traj[o->oStarMoveCurPoint + 2], traj[o->oStarMoveCurPoint + 3]};
        Vec3f trajNextPoint = {traj[o->oStarMoveCurPoint + 4 + 1], traj[o->oStarMoveCurPoint + 4 + 2], traj[o->oStarMoveCurPoint + 4 + 3]};
        Vec3f trajDirection;
        vec3f_diff(trajDirection, trajNextPoint, trajCurPoint);
        o->oPosX = trajCurPoint[0] + (trajDirection[0] * o->oStarMoveProgress);
        o->oPosY = trajCurPoint[1] + (trajDirection[1] * o->oStarMoveProgress);
        o->oPosZ = trajCurPoint[2] + (trajDirection[2] * o->oStarMoveProgress);
    }
}
