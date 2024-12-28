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

    if (0 == o->oF4)
    {
        o->oF4 = 1;
        o->oPosY += 100.f;
        for (int i = 0; i < 5; i++)
        {
            parts[i] = spawn_object(o, MODEL_PC_SANDGLASS_ENDS + i, bhvStaticObject);
        }
    }

    const int FlipSpeed = 20;

    switch (o->oAction)
    {
        case 0:
        {
            obj_set_hitbox(o, &sPcSandglassHitbox);
            if (cur_obj_was_attacked_or_ground_pounded()) {
                // obj_explode_and_spawn_coins(46.0f, COIN_TYPE_YELLOW);
                play_sound(SOUND_GENERAL_BREAK_BOX, gGlobalSoundSource);
                o->oAction = 1;
            }
        }
        break;
        case 1:
        {
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
}

void bhv_pc_key_door_loop()
{

}

void bhv_pc_key_enter_init()
{

}

void bhv_pc_key_enter_loop()
{

}

void bhv_pc_move_init()
{

}

void bhv_pc_move_loop()
{

}
