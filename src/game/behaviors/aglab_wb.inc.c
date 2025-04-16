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

void bhv_wb_door_init()
{
    obj_set_collision_data(o, o->oBehParams2ndByte ? wb_shuts_collision : wb_shut_collision);
}

void bhv_wb_door_loop()
{

}
