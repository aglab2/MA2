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

Gfx *geo_wb_fig(s32 callContext, UNUSED struct GraphNode *node, Mat4 mtx)
{
    if (GEO_CONTEXT_RENDER == callContext)
    {
        struct GraphNodeGenerated* nodeFn = (struct GraphNodeGenerated*) node;
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        struct GraphNodeBatchsetTranslationRotation *batchNode = (struct GraphNodeBatchsetTranslationRotation *) node->next;
        int angle = obj->oMoveAngleYaw + 0x2345 * nodeFn->parameter;
        batchNode->translation[0] = obj->oForwardVel * sins(angle) * obj->oTimer;
        batchNode->translation[1] = 45.f * obj->oTimer + obj->oVelY * obj->oTimer * obj->oTimer;
        batchNode->translation[2] = obj->oForwardVel * coss(angle) * obj->oTimer;
        batchNode->rotation[0] = 0x124 * obj->oTimer;
        batchNode->rotation[2] = 0x229 * obj->oTimer;

        if (300 == obj->oTimer)
        {
            obj->activeFlags = 0;
        }
    }
    return NULL;
}
