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

static void puffAt(struct Object* obj, float size, int numParticles)
{
    f32 sizeBase = size;
    f32 sizeRange = size / 20.f;
    f32 forwardVelBase = 40.f;
    f32 forwardVelRange = 5.f;
    f32 velYBase = 30.f;
    f32 velYRange = 20.f;

    if ((gPrevFrameObjectCount > (OBJECT_POOL_CAPACITY - 90)) && numParticles > 10) {
        numParticles = 10;
    }

    if (gPrevFrameObjectCount > (OBJECT_POOL_CAPACITY - 30)) {
        numParticles = 0;
    }

    for (int i = 0; i < numParticles; i++) {
        f32 scale = random_float() * (sizeRange * 0.1f) + sizeBase * 0.1f;
        struct Object* particle = spawn_object(obj, MODEL_MIST, bhvWhitePuffExplosion);

        particle->oBehParams2ndByte = 2;
        particle->oMoveAngleYaw = random_u16();
        particle->oGravity = 2.52f;
        particle->oDragStrength = 1.0f;
        particle->oForwardVel = random_float() * forwardVelRange + forwardVelBase;
        particle->oPosX = obj->oPosX;
        particle->oPosY = obj->oPosY;
        particle->oPosZ = obj->oPosZ;
        particle->oVelX = 0.f;
        particle->oVelY = random_float() * velYRange + velYBase;
        particle->oVelZ = 0.f;

        obj_scale(particle, scale);
    }
}

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
        o->oHomeX = 0;
        o->oHomeY = 0;
        o->oHomeZ = 0;
        if (o->oDistanceToMario < 400.f)
        {
            cur_obj_play_sound_2(SOUND_GENERAL_POUND_ROCK);
            puffAt(o, 100.f, 10);
            o->oAction = 1;
            obj_set_model(o, MODEL_WC_ROCK_BREAK);
        }
    }
    else
    {
        o->oHomeX += 10.f / o->header.gfx.scale[0];
        o->oHomeY += 10.f / o->header.gfx.scale[0];
        o->oHomeZ += 14.f / o->header.gfx.scale[0];
        obj_scale(o, 1.f - o->oTimer / 70.f);
        if (50 == o->oTimer)
        {
            obj_mark_for_deletion(o);
        }
    }
}
