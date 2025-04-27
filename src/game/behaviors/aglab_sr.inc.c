static struct ObjectHitbox sSrJumpHitbox = {
    /* interactType:      */ INTERACT_PUSH_BOUNCE,
    /* downOffset:        */  20,
    /* damageOrCoinValue: */   0,
    /* health:            */   1,
    /* numLootCoins:      */   0,
    /* radius:            */ 100,
    /* height:            */ 200,
    /* hurtboxRadius:     */ 100,
    /* hurtboxHeight:     */ 200,
};

#define oSrJumpMinY oFloatF4
#define oSrJumpMaxY oFloatF8

void bhv_sr_jump_init()
{
    spawn_object(o, MODEL_SR_PNP_GROUND, bhvStaticObject);
    struct Object* top = spawn_object(o, MODEL_SR_PNP_LIMIT, bhvStaticObject);
    o->oSrJumpMinY = o->oPosY;
    o->oSrJumpMaxY = top->oPosY = o->oPosY + o->oBehParams2ndByte * 10.0f;
    o->oVelY = 0;
}

void bhv_sr_jump_loop()
{
    obj_set_hitbox(o, &sSrJumpHitbox);
    if (0 == o->oAction && o->oInteractStatus)
    {
        // o->oAction = o->oInteractStatus;
        // o->oVelY = -gMarioStates->vel[1] * 0.8f;
        o->oVelY = 50.f;
        gMarioStates->vel[1] = 70.f;
    }
    else
    {
    }

    if (o->oVelY > -40.f)
        o->oVelY -= 2.f;

    o->oInteractStatus = 0;
    o->oPosY += o->oVelY;
    o->oGeoYaw += o->oVelY * 100;

    if (o->oPosY < o->oSrJumpMinY)
    {
        o->oPosY = o->oSrJumpMinY;
        o->oAction = 0;
        o->oVelY = 0.f;
    }

    if (o->oPosY > o->oSrJumpMaxY)
    {
        o->oPosY = o->oSrJumpMaxY;
    }
}
