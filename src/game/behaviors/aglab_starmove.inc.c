extern const Trajectory* starmove_trajs_ph;
static const Trajectory** k_starmove_trajectories[] = 
{
    [ LEVEL_PH ] = starmove_trajs_ph,
};

#define oStarMoveTraj OBJECT_FIELD_VPTR(0x1B)
#define oStarMoveCurPoint oF8
#define oStarMoveProgress oFC

void bhv_starmove_init()
{
    const Trajectory** trajs = segmented_to_virtual(k_starmove_trajectories[gCurrLevelNum]);
    o->oStarMoveTraj = segmented_to_virtual(trajs[GET_BPARAM3(o->oBehParams) - 1]);
    f32 d;
}

void bhv_starmove_loop()
{
    const Trajectory* traj = o->oStarMoveTraj;
    // Advance along the zipline
    {
        Vec3f trajCurPoint = {traj[o->oStarMoveCurPoint + 1], traj[o->oStarMoveCurPoint + 2], traj[o->oStarMoveCurPoint + 3]};
        Vec3f trajNextPoint = {traj[o->oStarMoveCurPoint + 4 + 1], traj[o->oStarMoveCurPoint + 4 + 2], traj[o->oStarMoveCurPoint + 4 + 3]};
        Vec3f trajDirection;
        vec3f_diff(trajDirection, trajNextPoint, trajCurPoint);

#if 0
        print_text_fmt_int(20, 100, "X %d", (int) trajDirection[0]);
        print_text_fmt_int(20, 120, "Z %d", (int) trajDirection[2]);
#endif

        f32 dirMag = vec3_mag(trajDirection);
        f32 velocity = 20.f;
        f32 movAmt = velocity / dirMag;

        o->oStarMoveProgress += movAmt;
        if (o->oStarMoveProgress >= 1.f)
        {
            if (traj[o->oStarMoveCurPoint + 8] == -1)
            {
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
