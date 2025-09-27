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
    o->oDrawingDistance = 10000.f;
}

void bhv_wb_door_check_break_loop()
{
    struct Surface* surf = gMarioStates->wall;
    if (!surf)
        return;

    if (surf->object != o->parentObj)
        return;

    int action = gMarioStates->action;
    if (action == ACT_JUMP_KICK || action == ACT_PUNCHING || action == ACT_MOVE_PUNCHING || action == ACT_JUMP_KICK || action == ACT_MOVE_PUNCHING)
    {
        puffAt(o, 100.f, 10, 0.f);
        create_sound_spawner(SOUND_GENERAL_BREAK_BOX);
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
    }
    return NULL;
}

extern u8 gHasEmulator;
void bhv_wb_breakable_init()
{
    if (!gHasEmulator && GET_BPARAM1(o->oBehParams))
    {
        o->activeFlags = 0;
    }
}

void bhv_wb_breakable_loop()
{
    if (0 == o->oAction)
    {
        if (o->oDistanceToMario < 130.f)
        {
            cur_obj_play_sound_2(SOUND_GENERAL_BREAK_BOX);
            o->oAction = 1;
            puffAt(o, 100.f, 10, 0.f);
            obj_set_model(o, o->oBehParams2ndByte);
            if (0 == o->oBehParams2ndByte)
            {
                o->activeFlags = 0;
            }
            else
            {
                o->oTimer = 0;
                o->oVelY = -1.f + random_f32_around_zero(0.1f);
                o->oMoveAngleYaw = random_u16();
                o->oForwardVel = 40.f + random_f32_around_zero(5.f);
            }
        }
    }
    else
    {
        if (300 == o->oTimer)
        {
            o->activeFlags = 0;
        }
    }
}

#define oWbSparkTraj OBJECT_FIELD_CVPTR(0x1B)
#define oWbSparkTrajIndex oF8

static void wb_spark_reset()
{
    const Trajectory* traj = o->oWbSparkTraj;
    o->oWbSparkTrajIndex = 0;
    o->oVelY = 0;
    o->oForwardVel = 0;

    Vec3f prev;
    prev[0] = traj[1];
    prev[1] = traj[2];
    prev[2] = traj[3];
    Vec3f curr;
    curr[0] = traj[1];
    curr[1] = traj[2];
    curr[2] = traj[3];
    
    Vec3f diff;
    vec3_diff(diff, curr, prev);

    o->oMoveAngleYaw = atan2s(diff[2], diff[0]);
    o->oPosX = prev[0];
    o->oPosY = prev[1];
    o->oPosZ = prev[2];
}

extern const Trajectory wb_area_1_spline_NurbsCurve_StarMove[];
void bhv_wb_spark_init()
{
    o->oOpacity = 255;
    o->oWbSparkTraj = segmented_to_virtual(wb_area_1_spline_NurbsCurve_StarMove);
    wb_spark_reset();
}

void bhv_wb_spark_loop()
{
    o->oAnimState++;
    if (0 == o->oAction)
    {
        const Trajectory* traj = o->oWbSparkTraj;
        if (0 == o->oWbSparkTrajIndex)
        {
            if (o->oDistanceToMario < 200.f)
            {
                o->oWbSparkTrajIndex = 4;
                o->oTimer = 0;
            }
        }
        else
        {
            Vec3f curr;
            curr[0] = traj[o->oWbSparkTrajIndex + 1];
            curr[1] = traj[o->oWbSparkTrajIndex + 2];
            curr[2] = traj[o->oWbSparkTrajIndex + 3];
            
            Vec3f diff;
            vec3_diff(diff, curr, &o->oPosVec);
            f32 dlen = diff[0] * diff[0] + diff[1] * diff[1] + diff[2] * diff[2];

            s16 yaw = atan2s(diff[2], diff[0]);
            o->oMoveAngleYaw = approach_angle(o->oMoveAngleYaw, yaw, 0x200);

            f32 velLim = CLAMP(dlen / 10000.f, 0, 28);
            f32 vel = CLAMP(o->oTimer, 0, velLim);
            o->oForwardVel = vel;

            o->oVelX = o->oForwardVel * sins(o->oMoveAngleYaw);
            o->oVelZ = o->oForwardVel * coss(o->oMoveAngleYaw);
            o->oVelY = diff[1] / 100.f;

            o->oPosX += o->oVelX;
            o->oPosY += o->oVelY;
            o->oPosZ += o->oVelZ;

            if (dlen < 300.f * 300.f)
            {
                o->oWbSparkTrajIndex += 4;
            }
            
            if (o->oDistanceToMario > 900.f)
            {
                o->oAction = 1;
            }
        }
    }
    else
    {
        play_sound(SOUND_MOVING_LAVA_BURN, o->header.gfx.cameraToObject);
        spawn_object(o, MODEL_BURN_SMOKE, bhvBlackSmokeBowser);
        o->oPosY -= o->oTimer;
        if (30 == o->oTimer)
        {
            o->oAction = 0;
            wb_spark_reset();
        }
    }
}

void bhv_wb_move_spring_init()
{
    f32 d;
    o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvSpring, &d);
    bhv_wb_move_init();
}

void bhv_wb_move_spring_loop()
{
    bhv_wb_move_loop();
    o->parentObj->oPosX = o->oPosX;
    o->parentObj->oPosY = o->oPosY + 20.f;
    o->parentObj->oPosZ = o->oPosZ;
}

void bhv_wb_door_chao_init()
{
    obj_set_collision_data(o, o->oBehParams2ndByte ? wb_shuts_collision : wb_shut_collision);
    f32 d;
    o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvWbChao, &d);
    if (gDialogCameraAngleIndex == 6)
    {
        o->activeFlags = 0;
    }
}

void bhv_wb_door_chao_loop()
{
    o->oDrawingDistance = 10000.f;
    f32 dx = o->parentObj->oPosX - o->oPosX;
    f32 dy = o->parentObj->oPosY - o->oPosY;
    f32 dz = o->parentObj->oPosZ - o->oPosZ;
    f32 dist = dx * dx + dy * dy + dz * dz;
    if (dist < 600.f * 600.f)
    {
        cur_obj_play_sound_2(SOUND_GENERAL_BREAK_BOX);
        puffAt(o, 100.f, 10, 0.f);
        o->activeFlags = 0;
        o->parentObj->activeFlags = 0;
    }
}
