// heave_ho.inc.c

s16 sHeaveHoTimings[][2] = {
    {  30, 0 },
    {  42, 1 },
    {  52, 0 },
    {  64, 1 },
    {  74, 0 },
    {  86, 1 },
    {  96, 0 },
    { 108, 1 },
    { 118, 0 },
    {  -1, 0 },
};

void bhv_heave_ho_throw_mario_loop(void) {
    o->oParentRelativePosX = 200.0f;
    o->oParentRelativePosY = -50.0f;
    o->oParentRelativePosZ = 0.0f;

    o->oMoveAngleYaw = o->parentObj->oMoveAngleYaw;
    switch (o->parentObj->oHeaveHoThrowState) {
        case 0:
            break;
        case 1:
            break;
        case 2:
            cur_obj_play_sound_2(SOUND_OBJ_HEAVEHO_TOSSED);
            gMarioObject->oInteractStatus |= INT_STATUS_MARIO_THROWN_BY_OBJ;
            gMarioStates[0].forwardVel = -45.0f;
            gMarioStates[0].vel[1] = 95.0f;
            o->parentObj->oHeaveHoThrowState = 0;
            break;
    }
}

static void heave_ho_act_1(int buffed) {
    s32 i = 0;

    o->oForwardVel = 0.0f;
    cur_obj_reverse_animation();

    while (TRUE) {
        if (buffed || sHeaveHoTimings[i][0] == -1) {
            o->oAction = 2;
            break;
        }

        if (o->oTimer < sHeaveHoTimings[i][0]) {
            cur_obj_init_animation_with_accel_and_sound(2, sHeaveHoTimings[i][1]);
            break;
        }

        i++;
    }
}

static void heave_ho_act_2(int buffed) {
    if (cur_obj_lateral_dist_from_mario_to_home() > 1000.0f) {
        o->oAngleToMario = cur_obj_angle_to_home();
    }

    if (buffed)
    {
        o->oHeaveHoTimedSpeed = 2.f;
    }
    else
    {
        if (o->oTimer > 150) {
            o->oHeaveHoTimedSpeed = (302 - o->oTimer) / 152.0f;
            if (o->oHeaveHoTimedSpeed < 0.1f) {
                o->oHeaveHoTimedSpeed = 0.1f;
                o->oAction = 1;
            }
        } else {
            o->oHeaveHoTimedSpeed = 1.0f;
        }
    }

    cur_obj_init_animation_with_accel_and_sound(0, o->oHeaveHoTimedSpeed);

    o->oForwardVel = o->oHeaveHoTimedSpeed * 10.0f;
    s16 angleVel = o->oHeaveHoTimedSpeed * 0x400;
    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, angleVel);
}

static void heave_ho_act_3(void) {
    o->oForwardVel = 0.0f;

    if (o->oTimer == 0) {
        o->oHeaveHoThrowState = 2;
    }

    if (o->oTimer == 1) {
        cur_obj_init_animation_with_accel_and_sound(1, 1.0f);
        o->numCollidedObjs = 20;
    }

    if (cur_obj_check_if_near_animation_end()) {
        o->oAction = 1;
    }
}

static void heave_ho_act_0(void) {
    cur_obj_set_pos_to_home();

    if (find_water_level(o->oPosX, o->oPosZ) < o->oPosY && o->oDistanceToMario < 4000.0f) {
        cur_obj_become_tangible();
        cur_obj_unhide();
        o->oAction = 1;
    } else {
        cur_obj_become_intangible();
        cur_obj_hide();
    }
}

ObjActionFunc sHeaveHoActions[] = {
    heave_ho_act_0,
    heave_ho_act_1,
    heave_ho_act_2,
    heave_ho_act_3,
};

void heave_ho_move(int buffed) {
    cur_obj_update_floor_and_walls();
    switch (o->oAction) {
        case 0:
            heave_ho_act_0();
            break;
        case 1:
            heave_ho_act_1(buffed);
            break;
        case 2:
            heave_ho_act_2(buffed);
            break;
        case 3:
            heave_ho_act_3();
            break;
    }
    cur_obj_move_standard(-78);

    if (o->oMoveFlags & OBJ_MOVE_MASK_IN_WATER) {
        o->oGraphYOffset = -15.0f;
    } else {
        o->oGraphYOffset = 0.0f;
    }

    if (o->oForwardVel > 3.0f) {
        cur_obj_play_sound_1(SOUND_AIR_HEAVEHO_MOVE);
    }

    if (o->oAction != 0 && o->oMoveFlags & OBJ_MOVE_MASK_IN_WATER) {
        o->oAction = 0;
    }

    if (o->oInteractStatus & INT_STATUS_GRABBED_MARIO) {
        o->oInteractStatus = INT_STATUS_NONE;
        o->oHeaveHoThrowState = 1;
        o->oAction = 3;
    }
}

void heave_ho_move_frozen()
{
    switch (o->oAction) {
        case 0:
            heave_ho_act_0();
            break;
        case 1:
            // heave_ho_act_1(buffed);
            break;
        case 2:
            // heave_ho_act_2(buffed);
            break;
        case 3:
            // heave_ho_act_3();
            break;
    }
}

void bhv_heave_ho_loop_frozen(void) {
    cur_obj_scale(2.0f);

    switch (o->oHeldState) {
        case HELD_FREE:
            heave_ho_move_frozen();
            break;
        case HELD_HELD:
            cur_obj_unrender_set_action_and_anim(0, 0);
            break;
        case HELD_THROWN:
            cur_obj_get_dropped();
            break;
        case HELD_DROPPED:
            cur_obj_get_dropped();
            break;
    }

    o->oInteractStatus = INT_STATUS_NONE;
}

void bhv_heave_ho_loop_impl(int buffed) {
    cur_obj_scale(2.0f);

    switch (o->oHeldState) {
        case HELD_FREE:
            heave_ho_move(buffed);
            break;
        case HELD_HELD:
            cur_obj_unrender_set_action_and_anim(0, 0);
            break;
        case HELD_THROWN:
            cur_obj_get_dropped();
            break;
        case HELD_DROPPED:
            cur_obj_get_dropped();
            break;
    }

    o->oInteractStatus = INT_STATUS_NONE;
}

void bhv_heave_ho_loop(void)
{
    bhv_heave_ho_loop_impl(0);
}