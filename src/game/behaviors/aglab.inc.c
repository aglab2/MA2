extern const Collision ce_hammer_collision[];
extern const Collision ms_hammer_collision[];
extern const Collision lc_step_collision[];
extern const Collision cw_updown_collision[];

static const Collision *const k_hammer_collisions[] = {
    [ LEVEL_CE ] = ce_hammer_collision,
    [ LEVEL_MS ] = ms_hammer_collision,
    [ LEVEL_LC ] = lc_step_collision,
    [ LEVEL_CW ] = cw_updown_collision,
};

void bhv_up_down_init()
{
    o->oTimer = o->oBehParams2ndByte;
    obj_set_collision_data(o, k_hammer_collisions[gCurrLevelNum]);
}

void bhv_up_down_loop()
{
    f32 vel = 5.f;
    if (gCurrCourseNum == COURSE_CW)
    {
        o->oDrawingDistance = 10000.f;
        vel = 15.f;
    }
    if (o->oTimer == 240)
    {
        o->oTimer = 0;
    }

    if (o->oTimer < 120)
    {
        o->oPosY += vel;
    }
    else
    {
        o->oPosY -= vel;
    }
}

void bhv_push_out_loop()
{
    struct ObjectHitbox hitbox = {
        /* interactType:      */ INTERACT_PUSH_OUT,
        /* downOffset:        */  20,
        /* damageOrCoinValue: */   0,
        /* health:            */   1,
        /* numLootCoins:      */   0,
        /* radius:            */ GET_BPARAM1(o->oBehParams) * 10,
        /* height:            */ GET_BPARAM2(o->oBehParams) * 10,
        /* hurtboxRadius:     */ GET_BPARAM1(o->oBehParams) * 10,
        /* hurtboxHeight:     */ GET_BPARAM2(o->oBehParams) * 10,
    };
    
    obj_set_hitbox(o, &hitbox);
    o->oInteractStatus = 0;
}

void bhv_flame_init()
{
    obj_scale(o, 4.5f);
    if (gCurrCourseNum == COURSE_AQ)
    {
        obj_scale(o, 2.5f);
    }
    if (gCurrCourseNum == COURSE_PC)
    {
        obj_scale(o, 10.f);
    }
    if (gCurrCourseNum == COURSE_SO)
    {
        obj_scale(o, 4.f);
    }
}

void bhv_flame_init2()
{
    obj_scale(o, 12.f);
}
