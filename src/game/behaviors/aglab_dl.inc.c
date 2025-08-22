void bhv_dl_shell_loop()
{
    f32 d;
    struct Object* shell = cur_obj_find_nearest_object_with_behavior(bhvKoopaShellUnderwater, &d);
    if (!shell)
    {
        spawn_object(o, MODEL_KOOPA_SHELL, bhvKoopaShellUnderwater);
    }
}

extern const BehaviorScript bhvCCKBubble[];
void bhv_dl_flow_loop()
{
    int half = 0;
    if (0 == (o->oTimer % 16))
    {
        struct Object* bubble = spawn_object(o, MODEL_BUBBLE, bhvCCKBubble);
        bubble->oPosX += (2000.f + 60.f * 30.f) * sins(o->oFaceAngleYaw) / (half ? 2.f : 1.f);
        bubble->oPosZ += (2000.f + 60.f * 30.f) * coss(o->oFaceAngleYaw) / (half ? 2.f : 1.f);

        bubble->oPosX += random_f32_around_zero(500.f) * coss(o->oFaceAngleYaw);
        bubble->oPosZ += random_f32_around_zero(500.f) * sins(o->oFaceAngleYaw);

        bubble->oVelX = -60.f * sins(o->oFaceAngleYaw);
        bubble->oVelZ = -60.f * coss(o->oFaceAngleYaw);

        bubble->oPosY += 700.f * random_float();

        bubble->oBehParams2ndByte = o->oBehParams2ndByte;
    }

    f32 dx = gMarioStates->pos[0] - o->oPosX;
    f32 dy = gMarioStates->pos[1] - o->oPosY;
    f32 dz = gMarioStates->pos[2] - o->oPosZ;
    {
        f32 z = 2300.f / (half ? 2.f : 1.f);
        if (!gMarioStates->heldObj && ABS(dz) < z && ABS(dx) < 500.f && (-100.f <= dy && dy <= 700.f))
        {
            f32 zd = 2000.f / (half ? 2.f : 1.f);
            f32 vel = 60.f - CLAMP(ABS(dz) - zd, 0.f, 300.f / (half ? 2.f : 1.f)) / (5.f / (half ? 2.f : 1.f));
            gMarioStates->pos[0] -= vel * sins(o->oFaceAngleYaw);
            gMarioStates->pos[2] -= vel * coss(o->oFaceAngleYaw);
        }
    }
}
