#define oPlatformSupport oObjF4

void bhv_hb_platform_init()
{
    struct Surface* pfloor;
    o->oHomeY = find_floor(o->oPosX, o->oPosY + 200.f, o->oPosZ, &pfloor);

    f32 dist;
    o->oPlatformSupport = cur_obj_find_nearest_object_with_behavior(bhvHbSupport, &dist);
    if (o->oPlatformSupport && dist < 1200.f)
    {
        // -
    }
    else
    {
        o->oPlatformSupport = NULL;
    }
}

void bhv_hb_platform_loop()
{
    if (o->oPlatformSupport && 0 == o->oPlatformSupport->activeFlags)
    {
        o->oPlatformSupport = NULL;
    }

    f32 ty = o->oHomeY + (o->oPlatformSupport ? 500.f : 0.f);
    if (ty < o->oPosY)
    {
        o->oVelY--;
        o->oPosY += o->oVelY;
    }
    else
    {
        o->oPosY = ty;
        o->oVelY = 0.f;
    }
}

void bhv_hb_up_down_loop()
{
    o->oVelY = sins((o->oBehParams2ndByte ? 1 : -1) * o->oTimer * 0x145) * 10.0f;
    o->oPosY += o->oVelY;
}

struct ObjectHitbox sHbSupportHitbox = {
    /* interactType:      */ INTERACT_BREAKABLE,
    /* downOffset:        */  20,
    /* damageOrCoinValue: */   0,
    /* health:            */   1,
    /* numLootCoins:      */   0,
    /* radius:            */ 400,
    /* height:            */ 600,
    /* hurtboxRadius:     */ 1,
    /* hurtboxHeight:     */ 1,
};

void bhv_hb_support_init()
{
    f32 dist;
    o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvHbSupport, &dist);
    if (dist > 1200.f)
    {
        o->parentObj = NULL;
    }
    o->oInteractStatus = 0;
}

void bhv_hb_support_loop()
{
    obj_set_hitbox(o, &sHbSupportHitbox);
    if (cur_obj_was_attacked_or_ground_pounded()) {
        obj_explode_and_spawn_coins(46.0f, COIN_TYPE_YELLOW);
        create_sound_spawner(SOUND_GENERAL_BREAK_BOX);
        if (o->parentObj)
            o->parentObj->oPlatformSupport = NULL;
    }
}
