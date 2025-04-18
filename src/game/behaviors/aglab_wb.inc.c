extern const Collision wb_ont_collision[];
extern const Collision wb_contb_collision[];
extern const Collision wb_contc_collision[];
extern const Collision wb_contc_stand_collision[];

static const Collision* kWbCollisions[] = {
    wb_ont_collision,
    wb_contb_collision,
    wb_contc_collision,
};

void bhv_wb_move_init()
{
    obj_set_collision_data(o, kWbCollisions[o->oBehParams2ndByte]);
}

void bhv_wb_move_loop()
{
    o->oForwardVel = 10.f * ((o->oTimer / 64) % 2 ? 2.f : -2.f);

    o->oPosX += o->oForwardVel * coss(o->oMoveAngleYaw);
    o->oPosZ += o->oForwardVel * sins(o->oMoveAngleYaw);
}

extern const Collision wb_shut_collision[];
extern const Collision wb_shuts_collision[];

extern const BehaviorScript bhvWbDoorCheckBreak[];

void bhv_wb_door_init()
{
    obj_set_collision_data(o, o->oBehParams2ndByte ? wb_shuts_collision : wb_shut_collision);
    o->parentObj = spawn_object(o, 0, bhvWbDoorCheckBreak);
}

void bhv_wb_door_loop()
{

}

void bhv_wb_door_check_break_loop()
{
    struct Surface* surf = gMarioStates->wall;
    if (!surf)
        return;

    if (surf->object != o->parentObj)
        return;

    if (gMarioStates->action == ACT_JUMP_KICK)
    {
        o->parentObj->activeFlags = 0;
        o->activeFlags = 0;
        spawn_object(o, o->oBehParams2ndByte ? MODEL_WB_SHUTS_BREAK : MODEL_WB_SHUT_BREAK, bhvStaticObject);
    }
}
