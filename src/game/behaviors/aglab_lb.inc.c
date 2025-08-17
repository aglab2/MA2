void bhv_lb_ctl_init()
{
    f32 d;
    o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvBowser, &d);
    gSecondCameraFocus = spawn_object(o, MODEL_STAR, bhvGrandStar);
    gSecondCameraFocus->oPosX = 0;
    gSecondCameraFocus->oPosY = 1050;
    gSecondCameraFocus->oPosZ = -10000;
}

static void lb_pin_bowser()
{
    o->parentObj->oPosX = 0;
    o->parentObj->oPosY = 0;
    o->parentObj->oPosZ = 0;

    if (o->parentObj->oAction != BOWSER_ACT_WALK_TO_MARIO)
    {
        s32 angleToMario = obj_angle_to_object(o->parentObj, gMarioObject);
        s16 angleFromMario = abs_angle_diff(o->parentObj->oMoveAngleYaw, angleToMario);
        if (angleFromMario > 0x1000)
        {
            o->parentObj->oAction = BOWSER_ACT_WALK_TO_MARIO;
        }
        else
        {
            o->parentObj->oAction = 0;
        }
    }
}

static void lb_pin_mario()
{
    f32 d = gMarioStates->pos[0] * gMarioStates->pos[0] + gMarioStates->pos[2] * gMarioStates->pos[2];
    if (d > 3400.f * 3400.f)
    {
        d = sqrtf(d);
        gMarioStates->pos[0] /= d;
        gMarioStates->pos[2] /= d;
        gMarioStates->pos[0] *= 3400.f;
        gMarioStates->pos[2] *= 3400.f;
    }
}

extern void set_camera_mode_8_directions(struct Camera *c);
extern void func_8031D690(s32 player, s32 fadeInTime);
void bhv_lb_ctl_loop()
{
    if (0 == o->oAction)
    {
        o->parentObj->oPosX = 0;
        o->parentObj->oPosY = -1000;
        o->parentObj->oPosZ = 0;

        if (gMarioStates->pos[2] < -11500.f)
        {
            o->parentObj->oPosX = 0;
            o->parentObj->oPosY = 1050;
            o->parentObj->oPosZ = -12000;

            gMarioStates->pos[1] = 1100.f;
            gMarioStates->faceAngle[1] = 0;
            gMarioStates->forwardVel = 200.f;
            gMarioStates->vel[0] = 0.f;
            gMarioStates->vel[1] = 50.f;
            gMarioStates->vel[2] = 0.f;
            set_mario_action(gMarioStates, ACT_THROWN_BACKWARD, 0);
            gSecondCameraFocus->oPosY = 0;
            cur_obj_play_sound_2(SOUND_OBJ_BOWSER_LAUGH);
            o->oAction = 1;

            seq_player_play_sequence(0, 0x48, 0);
            func_8031D690(0, 60);
        }
    }
    else if (1 == o->oAction)
    {
        if (gMarioStates->pos[1] < 101.f)
        {
            gMarioStates->vel[1] = -gMarioStates->vel[1];
            gMarioStates->forwardVel = 130.f;

            o->parentObj->oPosX = 0;
            o->parentObj->oPosY = 0;
            o->parentObj->oPosZ = 0;
            o->parentObj->oMoveAngleYaw = 0x8000;
            obj_scale(o->parentObj, 0.1f);
            o->parentObj->oAction = BOWSER_ACT_SPIT_FIRE_INTO_SKY;
            cur_obj_play_sound_2(SOUND_OBJ2_BOWSER_ROAR);

            o->parentObj->hitboxRadius = 500.f;
            o->parentObj->hitboxHeight = 1500.f;

            s8DirModeYawOffset = 0x8000;
   
            set_mario_action(gMarioStates, ACT_THROWN_BACKWARD, 0);

            o->oAction = 2;
        }
    }
    else if (2 == o->oAction)
    {
        obj_scale(o->parentObj, 0.1f * o->oTimer);
        if (50 == o->oTimer)
        {
            o->oAction = 3;
        }
    }
    else
    {
        lb_pin_bowser();
        lb_pin_mario();

#if 0
        if (0 == (o->oTimer % 40))
        {
            for (int i = 0; i < 6; i++)
            {
                s32 angleToMario = obj_angle_to_object(o->parentObj, gMarioObject);
                struct Object* ball = spawn_object(o, MODEL_LB_BALL, bhvLBBall);
                ball->oForwardVel = 50.f;
                ball->oMoveAngleYaw = angleToMario + 0x10000 / 6 * i;
                ball->oFaceAngleYaw = random_u16();
                ball->oFaceAngleRoll = random_u16();
                obj_scale(ball, 0.1f);
            }
        }
#else
        if (0 == o->oTimer)
        {
            for (int i = 0; i < 4; i++)
            {
                struct Object* tail = spawn_object(o, MODEL_LB_TAIL, bhvLBTail);
                tail->oOpacity = 0;
                tail->oMoveAngleYaw = 0x4000 * i;
            }
        }
#endif 
    }
}

void bhv_lb_ball_loop()
{
    o->oFaceAngleYaw += 0x280;
    o->oFaceAngleRoll += 0x146;
    obj_update_pos_vel_xz();

    if (o->oTimer <= 10)
    {
        o->oOpacity = 20 * o->oTimer;
        obj_scale(o, 0.1f * o->oTimer);
    }
    
    if (o->oTimer > 90)
    {
        o->oOpacity = 20 * (100 - o->oTimer);
        obj_scale(o, 0.1f * (100 - o->oTimer));
    }

    if (o->oTimer == 99)
    {
        obj_mark_for_deletion(o);
    }
}

void bhv_lb_tail_init()
{
    o->oDrawingDistance = 20000.f;
}

void bhv_lb_tail_loop()
{
    o->oOpacity = CLAMP(o->oTimer, 0, 255);
    o->oMoveAngleYaw += 0x100;
    o->oPosX = 1600.f * coss(-o->oMoveAngleYaw);
    o->oPosZ = 1600.f * sins(-o->oMoveAngleYaw);
}
