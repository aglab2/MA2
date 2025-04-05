extern const BehaviorScript bhvSoPillarBase[];

void bhv_so_pillar_init()
{
    o->parentObj = spawn_object(o, MODEL_SO_PILLAR_BASE, bhvSoPillarBase);
    o->oHomeY = o->oPosY;
    o->oPosY += 700.f;
    o->oDrawingDistance = 10000.f;
}

void bhv_so_pillar_loop()
{
    if (o->parentObj)
        return;

    if (0 == o->oAction)
    {
        o->oVelY -= 2.f;
        o->oPosY += o->oVelY;
        if (o->oPosY < o->oHomeY)
        {
            o->oPosY = o->oHomeY;
            o->oHomeY += 400.f;
            o->oVelY = -o->oVelY;
            o->oAction = 1;
            create_sound_spawner(SOUND_GENERAL2_BOBOMB_EXPLOSION);
        }
    }
    else if (1 == o->oAction)
    {
        o->oVelY -= 2.f;
        o->oPosY += o->oVelY;
        o->oFaceAnglePitch += 0x180;
        if (o->oVelY < 0 && o->oPosY < o->oHomeY)
        {
            o->oAction = 2;
            o->oVelY = 0.f;
            o->oPosY = o->oHomeY;
            o->oFaceAnglePitch = 0x4000;
            create_sound_spawner(SOUND_GENERAL2_BOBOMB_EXPLOSION);
        }
    }
}

void bhv_so_hako_init()
{
    o->parentObj = spawn_object(o, MODEL_RED_FLAME, bhvFlame2);
    o->parentObj->oPosY += 350.f;
    o->oDrawingDistance = 10000.f;
}

extern const Collision hb_ashiba_collision[];
extern const Collision hb_ashiba2_collision[];
extern const Collision hb_ashiba3_collision[];

static const Collision* kSoMoveCollisions[] = {
    hb_ashiba_collision,
    hb_ashiba2_collision,
    hb_ashiba3_collision,
};

void bhv_so_hako_loop()
{
    o->oMoveAngleYaw += 0x49;
}

void bhv_so_move_init()
{
    obj_set_collision_data(o, kSoMoveCollisions[o->oBehParams2ndByte]);
    o->oDrawingDistance = 3000.f;
}

void bhv_so_move_loop()
{
    const f32 VelMult = 6.f;
    const int TurnTimer = 25;
    const int MoveTimer = 150;
    f32 vel;

    // move back and forth on a sinewave pattern where middle segment is straight and edges are sinewaved
    if (o->oTimer < TurnTimer)
    {
        vel = VelMult * sins(o->oTimer * (0x4000 / TurnTimer));
    }
    else if (o->oTimer < (MoveTimer + TurnTimer))
    {
        vel = VelMult;
    }
    else if (o->oTimer < (MoveTimer + 3 * TurnTimer))
    {
        vel = VelMult * sins((0x4000 / TurnTimer) * (o->oTimer - MoveTimer));
    }
    else if (o->oTimer < (2 * MoveTimer + 3 * TurnTimer))
    {
        vel = -VelMult;
    }
    else if (o->oTimer < (2 * MoveTimer + 4 * TurnTimer))
    {
        vel = VelMult * sins((0x4000 / TurnTimer) * (o->oTimer - 2*MoveTimer));
    }
    else
    {
        o->oTimer = 0;
    }

    o->oVelX = vel * sins(o->oMoveAngleYaw);
    o->oVelZ = vel * coss(o->oMoveAngleYaw);
    o->oVelY = sins(0x10000 / (2*MoveTimer + 4*TurnTimer) * 5 * o->oTimer) * 0.1f;

    o->oPosX += o->oVelX;
    o->oPosY += o->oVelY;
    o->oPosZ += o->oVelZ;
}

struct ObjectHitbox sSoSupportHitbox = {
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

#define oSoPillarBaseSwitch oObjF4

void bhv_so_pillarbase_init()
{
    o->oDrawingDistance = 10000.f;
    f32 d;
    o->oSoPillarBaseSwitch = cur_obj_find_nearest_object_with_behavior(bhvFloorSwitchGrills, &d);
}

void bhv_so_pillarbase_loop()
{
    obj_set_hitbox(o, &sSoSupportHitbox);
    if (cur_obj_was_attacked_or_ground_pounded() || (o->oSoPillarBaseSwitch && o->oSoPillarBaseSwitch->oAction > 1)) {
        obj_explode_and_spawn_coins(46.0f, COIN_TYPE_YELLOW);
        create_sound_spawner(SOUND_GENERAL_BREAK_BOX);
        if (o->parentObj)
            o->parentObj->parentObj = NULL;
    }
}
