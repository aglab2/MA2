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
    }
}

void bhv_lb_ball_loop()
{

}