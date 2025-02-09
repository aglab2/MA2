#define oPcSandglassParts oObjF8
#define oPcSandglassInitialized oF4

static struct ObjectHitbox sPcSandglassHitbox = {
    /* interactType:      */ INTERACT_PUSH_BOUNCE,
    /* downOffset:        */  20,
    /* damageOrCoinValue: */   0,
    /* health:            */   1,
    /* numLootCoins:      */   0,
    /* radius:            */ 100,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 100,
    /* hurtboxHeight:     */ 100,
};

void bhv_pc_sandglass_loop()
{
    struct Object** parts = &o->oObjF4;

    if (NULL == *parts)
    {
        o->oPosY += 100.f;
        for (int i = 0; i < 5; i++)
        {
            parts[i] = spawn_object(o, MODEL_PC_SANDGLASS_ENDS + i, bhvStaticObject);
        }
    }

    const int FlipSpeed = 20;
    obj_set_hitbox(o, &sPcSandglassHitbox);
    switch (o->oAction)
    {
        case 0:
        {
            o->oInteractionSubtype = 0;
            if (cur_obj_was_attacked_or_ground_pounded()) {
                // obj_explode_and_spawn_coins(46.0f, COIN_TYPE_YELLOW);
                play_sound(SOUND_GENERAL_BREAK_BOX, gGlobalSoundSource);
                o->oAction = 1;
            }
        }
        break;
        case 1:
        {
            o->oInteractionSubtype = INT_SUBTYPE_PUSH_ONLY;
            o->oPosY = 100.f + o->oHomeY + 2 * o->oTimer * (FlipSpeed - o->oTimer);
            o->oFaceAnglePitch = o->oTimer * 0x8000 / FlipSpeed;
            if (FlipSpeed == o->oTimer)
            {
                o->oAction = 2;
            }
        }
        break;
        case 2:
        {                    
            if (o->oTimer < 360) {
                play_sound(SOUND_GENERAL2_SWITCH_TICK_FAST, gGlobalSoundSource);
            } else {
                play_sound(SOUND_GENERAL2_SWITCH_TICK_SLOW, gGlobalSoundSource);
            }
            if (o->oTimer > 400) {
                o->oAction = 3;
            }
        }
        break;
        case 3:
        {
            o->oPosY = 100.f + o->oHomeY + 2 * o->oTimer * (FlipSpeed - o->oTimer);
            o->oFaceAnglePitch = 0x8000 + o->oTimer * 0x8000 / FlipSpeed;
            if (o->oTimer == FlipSpeed)
            {
                o->oAction = 0;
            }
        }
        break;
    }

    for (int i = 0; i < 5; i++)
    {
        parts[i]->oPosX = o->oPosX;
        parts[i]->oPosZ = o->oPosZ;
        parts[i]->oPosY = o->oPosY;
        parts[i]->oFaceAnglePitch = o->oFaceAnglePitch;
        parts[i]->oFaceAngleRoll = o->oFaceAngleRoll;
        parts[i]->oFaceAngleYaw = o->oFaceAngleYaw;
    }
    o->oInteractStatus = 0;
}

void bhv_pc_sandglass_global_loop()
{
    bhv_pc_sandglass_loop();
}

void bhv_pc_key_enter_init()
{
    f32 v;
    o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvPcKeyDoor, &v);
}

void bhv_pc_key_enter_loop()
{
    if (0 == o->oAction)
    {
        if (o->oDistanceToMario < 100.f && gMarioStates->heldObj)
        {
            gMarioStates->heldObj->activeFlags = 0;
            o->oAction = 1;
            obj_set_model(o, obj_get_model_id(gMarioStates->heldObj));
            
            mario_drop_held_object(gMarioStates);
            set_mario_action(gMarioStates, ACT_WALKING, 0);
        }
    }
    else
    {
        o->parentObj->oPosY += 10.f;
        if (o->oTimer == 60)
        {
            o->oAction = 0;
        }
    }
}

#define PC_SANDGLASS_PROGRESS_MAX (360 + 40 * 5)

void bhv_pc_move_init()
{
    o->parentObj = cur_obj_nearest_object_with_behavior(bhvPcSandglass);
    switch (o->oBehParams2ndByte)
    {
        case 0:
        break;
        case 1:
            o->oFaceAnglePitch = 0x4000;
            o->oFaceAngleYaw = 0x4000;
            o->oPosX -= PC_SANDGLASS_PROGRESS_MAX;
        break;
        case 2:
            o->oFaceAnglePitch = 0x4000;
        break;
    }
}

#define PC_SANDGLASS_ACTIVE (o->parentObj->oAction == 2)

static inline int pc_sandglass_progress(void)
{
    int time = o->parentObj->oTimer;
    if (time < 360) {
        return time;
    } else {
        return 360 + (time - 360) * 5;
    }
}

static void pc_sandglass_modify_coord(f32* coord, f32 home, f32 mult)
{
    switch (o->parentObj->oAction)
    {
        case 0:
        {
            *coord = home;
        }
        break;
        case 1:
        {
            *coord = home + mult * o->parentObj->oTimer * (PC_SANDGLASS_PROGRESS_MAX / 20);
        }
        break;
        case 2:
        {
            *coord = home + mult * (PC_SANDGLASS_PROGRESS_MAX - pc_sandglass_progress());
        }
        break;
        case 3:
        {
            *coord = home;
        }
        break;
    }
}

void bhv_pc_move_loop()
{
    switch (o->oBehParams2ndByte)
    {
        case 0:
        pc_sandglass_modify_coord(&o->oPosY, o->oHomeY, 1.f);
        break;
        case 1:
        pc_sandglass_modify_coord(&o->oPosX, o->oHomeX, 1.f);
        break;
        case 2:
        pc_sandglass_modify_coord(&o->oPosZ, o->oHomeZ, -1.f);
        break;
    }
}

void bhv_pc_move2_init()
{

}

void bhv_pc_move2_loop()
{
    o->oPosY = o->oHomeY + 100.f * sins(o->oTimer * 0x156);
}
