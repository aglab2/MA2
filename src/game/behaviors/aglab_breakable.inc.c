void bhv_breakable_loop()
{
    if (0 == o->oAction)
    {
        if (o->oDistanceToMario < 130.f)
        {
            cur_obj_play_sound_2(SOUND_GENERAL_BREAK_BOX);
            o->oAction = 1;
            puffAt(o, 100.f, 10, 0.f);
            obj_set_model(o, o->oBehParams2ndByte);
            if (0 == o->oBehParams2ndByte)
            {
                o->activeFlags = 0;
            }
            else
            {
                o->oTimer = 0;
                o->oVelY = -1.f + random_f32_around_zero(0.1f);
                o->oMoveAngleYaw = random_u16();
                o->oForwardVel = 40.f + random_f32_around_zero(5.f);
            }
        }
    }
}

void bhv_breakable_up_loop()
{
    if (0 == o->oAction)
    {
        Vec3f marioPos;
        vec3_copy(marioPos, gMarioState->pos);
        marioPos[1] -= 160.f;
        Vec3f diff;
        vec3_diff(diff, marioPos, &o->oPosVec);
        f32 dist = vec3_sumsq(diff);

        if (dist < 130.f * 130.f)
        {
            cur_obj_play_sound_2(SOUND_GENERAL_BREAK_BOX);
            o->oAction = 1;
            puffAt(o, 100.f, 10, 160.f);
            obj_set_model(o, o->oBehParams2ndByte);
            if (0 == o->oBehParams2ndByte)
            {
                o->activeFlags = 0;
            }
        }
    }
}
