extern const Trajectory gf_area_2_spline_NurbsCurve_VineLoop_005[];
extern const Trajectory wj_area_1_spline_NurbsCurve_VineLoop_005[];

static const Trajectory* getVineTraj(void)
{
    if (gCurrCourseNum == COURSE_GF)
    {
        return gf_area_2_spline_NurbsCurve_VineLoop_005;
    }
    else
    {
        return wj_area_1_spline_NurbsCurve_VineLoop_005;
    }
}

extern const Trajectory* sTrajectory;
void bhv_gf_vine_loop()
{
    if (0 == o->oAction)
    {
        s16* traj = segmented_to_virtual(getVineTraj());
        f32 x, y, z;
        if (gMarioStates->action == ACT_RAIL_GRIND && sTrajectory == traj)
        {
            o->oSubAction = 1;
            x = gMarioStates->pos[0];
            y = gMarioStates->pos[1];
            z = gMarioStates->pos[2];
        }
        else
        {
            if (1 == o->oSubAction)
            {
                o->oAction = 1;
            }

            x = traj[1];
            y = traj[2];
            z = traj[3];

            f32 dx = x - gMarioStates->pos[0];
            f32 dy = y - gMarioStates->pos[1];
            f32 dz = z - gMarioStates->pos[2];
            f32 dist = dx * dx + dy * dy + dz * dz;
            if (dist < 100.f * 100.f)
            {
                set_mario_action(gMarioStates, ACT_JUMP, 0);
            }
        }

        o->oPosY = y;
        f32 dx = x - o->oPosX;
        f32 dz = z - o->oPosZ;
        f32 dist = sqrtf(dx * dx + dz * dz);

        obj_scale(o, dist / 1500.f);
        o->oFaceAngleYaw = atan2s(dz, dx) - 0x4000;
    }
    else
    {
        if (30 == o->oTimer)
        {
            o->oSubAction = 0;
            o->oAction = 0;
        }
    }
}

extern const Collision gf_gake_a_collision[];
extern const Collision gf_gake_b_collision[];
extern const Collision gf_gake_c_collision[];
extern const Collision gf_gake_d_collision[];
extern const Collision gf_gake_e_collision[];
extern const Collision gf_gake_f_collision[];

void bhv_gf_gake_init()
{
    const Collision* collision = NULL;
    switch (o->oBehParams2ndByte)
    {
    case 0:
        collision = gf_gake_a_collision;
        break;
    case 1:
        collision = gf_gake_b_collision;
        break;
    case 2:
        collision = gf_gake_c_collision;
        break;
    case 3:
        collision = gf_gake_d_collision;
        break;
    case 4:
        collision = gf_gake_e_collision;
        break;
    case 5:
        collision = gf_gake_f_collision;
        break;
    }

    obj_set_collision_data(o, collision);
}

void bhv_gf_gake_loop()
{
    if (gMarioStates->pos[0] < 0)
    {
        o->oPosX = o->oHomeX;
        o->oPosY = o->oHomeY;
        o->oPosZ = o->oHomeZ;
    }
    else
    {
        o->oPosY -= 1.f;
        o->oPosY -= 0.6f * o->oBehParams2ndByte;
    }
}
