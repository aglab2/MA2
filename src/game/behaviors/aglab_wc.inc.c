struct ObjectHitbox sWCStoneHeadBoxHitbox = {
    /* interactType:      */ INTERACT_NONE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 1,
    /* numLootCoins:      */ 0,
    /* radius:            */ 200,
    /* height:            */ 400,
    /* hurtboxRadius:     */ 200,
    /* hurtboxHeight:     */ 400,
};

#define oWCStoneHeadAmountPushed oF4

void bhv_wc_stonehead_loop(void) {
    obj_set_hitbox(o, &sWCStoneHeadBoxHitbox);
    o->oForwardVel = 0.0f;

    if (o->oWCStoneHeadAmountPushed == 100)
        return;

    if (obj_check_if_collided_with_object(o, gMarioObject) && gMarioStates[0].flags & MARIO_PUSHING) {
        s16 angleToMario = obj_angle_to_object(o, gMarioObject);
        if (abs_angle_diff(angleToMario, gMarioObject->oMoveAngleYaw) > 0x4000 && abs_angle_diff(0x8000, gMarioObject->oMoveAngleYaw) < 0x4000) {
            o->oMoveAngleYaw = (s16)((gMarioObject->oMoveAngleYaw + 0x2000) & 0xc000);
            if (check_if_moving_over_floor(8.0f, 150.0f)) {
                o->oForwardVel = 4.0f;
                cur_obj_play_sound_1(SOUND_ENV_METAL_BOX_PUSH);
                o->oWCStoneHeadAmountPushed++;
            }
        }
    }

    cur_obj_move_using_fvel_and_gravity();
}

void bhv_wc_rock_loop()
{
    if (0 == o->oAction)
    {
        if (o->oDistanceToMario < 100.f)
        {
            o->oAction = 1;
            obj_set_model(o, MODEL_WC_ROCK_BREAK);
        }
    }
    else
    {

    }
}

void bhv_wc_box_loop()
{
    if (0 == o->oAction)
    {
        if (o->oDistanceToMario < 40.f)
        {
            o->oAction = 1;
            obj_set_model(o, MODEL_WC_BOX_BROKEN);
        }
    }
}
