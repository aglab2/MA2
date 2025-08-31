void bhv_wj_side_init()
{
    spawn_object(o, MODEL_WJ_PLATFORM, bhvStaticObject);
    o->oPosX += 4100.f * coss(o->oFaceAngleYaw);
    o->oPosY += 50.f;
    o->oPosZ += 4100.f * sins(o->oFaceAngleYaw);

    struct Object* hook = spawn_object(o, MODEL_WJ_SIDE_HOOK, bhvStaticObject);
}

void bhv_wj_side_loop()
{
    if (0 == o->oAction)
    {
        Vec3f diff;
        vec3_diff(diff, gMarioStates->pos, &o->oPosVec);
        diff[0] += 4100.f * coss(o->oFaceAngleYaw);
        diff[2] += 4100.f * sins(o->oFaceAngleYaw);
        f32 dist = diff[0] * diff[0] + diff[1] * diff[1] + diff[2] * diff[2];
        if (dist < 4000.f)
        {
            o->oAction = 1;
            set_mario_action(gMarioStates, ACT_JUMP, 0);
        }
    }
    else
    {
        if (o->oTimer < 20)
        {
            o->oPosX = o->oHomeX + o->oTimer * 200.f * coss(o->oFaceAngleYaw);
            o->oPosY = o->oHomeY + 30.f * o->oTimer;
            o->oPosZ = o->oHomeZ + o->oTimer * 200.f * sins(o->oFaceAngleYaw);
            gMarioStates->pos[0] = o->oPosX - 4100.f * coss(o->oFaceAngleYaw);
            gMarioStates->pos[1] = o->oPosY;
            gMarioStates->pos[2] = o->oPosZ - 4100.f * sins(o->oFaceAngleYaw);
            gMarioStates->vel[0] = 200.f * coss(o->oFaceAngleYaw);
            gMarioStates->vel[1] = 30.f;
            gMarioStates->vel[2] = 200.f * sins(o->oFaceAngleYaw);
            gMarioStates->forwardVel = 200.f;
            gMarioStates->faceAngle[1] = o->oFaceAngleYaw + 0x4000;
            gMarioStates->forwardVel = 0.f;
            gMarioStates->extraGravityEnabled = 1;
        }
        else
        {
            o->oAction = 0;
            o->oPosX = o->oHomeX;
            o->oPosY = o->oHomeY;
            o->oPosZ = o->oHomeZ;
            gMarioStates->vel[0] = 200.f * coss(o->oFaceAngleYaw);
            gMarioStates->vel[1] = 50.f;
            gMarioStates->vel[2] = 200.f * sins(o->oFaceAngleYaw);
            gMarioStates->forwardVel = 200.f;
        }
    }
}

void bhv_wj_up_init()
{
    spawn_object(o, MODEL_WJ_PLATFORM, bhvStaticObject);
    o->oPosY += 2100.f;
    struct Object* hook = spawn_object(o, MODEL_WJ_UP_HOOK, bhvStaticObject);
    if (gCurrAreaIndex != 1)
        hook->oFaceAngleYaw += 0x4000;
}

void bhv_wj_up_loop()
{
    if (0 == o->oAction)
    {
        Vec3f diff;
        vec3_diff(diff, gMarioStates->pos, &o->oPosVec);
        diff[1] += 2100.f;
        f32 dist = diff[0] * diff[0] + diff[1] * diff[1] + diff[2] * diff[2];
        if (dist < 4000.f)
        {
            o->oAction = 1;
            set_mario_action(gMarioStates, ACT_JUMP, 0);
        }
    }
    else
    {
        int time = (gCurrAreaIndex == 1 ? 20 : 40);
        if (o->oTimer < time)
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
            gMarioStates->extraGravityEnabled = 1;
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
