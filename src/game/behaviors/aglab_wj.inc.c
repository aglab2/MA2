void bhv_wj_side_init()
{

}

void bhv_wj_side_loop()
{

}

void bhv_wj_up_init()
{
    spawn_object(o, MODEL_WJ_PLATFORM, bhvStaticObject);
    o->oPosY += 2100.f;
    o->oHomeY += 2100.f;
    spawn_object(o, MODEL_WJ_UP_HOOK, bhvStaticObject);
}

void bhv_wj_up_loop()
{
    if (0 == o->oAction)
    {
        Vec3f diff;
        vec3_diff(diff, gMarioStates->pos, &o->oPosVec);
        diff[1] += 2100.f;
        f32 dist = diff[0] * diff[0] + diff[1] * diff[1] + diff[2] * diff[2];
        if (dist < 2000.f)
        {
            o->oAction = 1;
            set_mario_action(gMarioStates, ACT_JUMP, 0);
        }
    }
    else
    {
        if (o->oTimer < 20)
        {
            o->oPosY = o->oHomeY + 100.f * o->oTimer;
            gMarioStates->pos[0] = o->oPosX;
            gMarioStates->pos[1] = o->oPosY - 2100.f;
            gMarioStates->pos[2] = o->oPosZ;
            gMarioStates->vel[0] = 0.f;
            gMarioStates->vel[1] = 100.f;
            gMarioStates->vel[2] = 0.f;
            gMarioStates->faceAngle[1] = o->oFaceAngleYaw + 0x4000;
            gMarioStates->forwardVel = 0.f;
        }
        else
        {
            o->oAction = 0;
            o->oPosX = o->oHomeX;
            o->oPosY = o->oHomeY;
            o->oPosZ = o->oHomeZ;
            gMarioStates->vel[1] = 100.f;
            set_mario_action(gMarioStates, ACT_DIVE, 0);
        }
    }
}
