#define oShutterLeft oObjF4
#define oShutterRight oObjF8
#define oShutterInitialize oFC
#define oShutterSwitch oObj100

struct ShutterConfig
{
    int modelBase;
    const void* collisionLeft;
    const void* collisionRight;
};

extern const Collision cg_shutter_left_collision[];
extern const Collision cg_shutter_right_collision[];

extern const Collision ee_shutter_left_collision[];
extern const Collision ee_shutter_right_collision[];

static const struct ShutterConfig* get_shutter_config()
{
    if (gCurrLevelNum == LEVEL_CG)
    {
        static struct ShutterConfig config = { MODEL_CG_SHUTTER_BASE, cg_shutter_left_collision, cg_shutter_right_collision };
        return &config;
    }
    if (gCurrLevelNum == LEVEL_EE)
    {
        static struct ShutterConfig config = { MODEL_EE_SHUTTER_BASE, ee_shutter_left_collision, ee_shutter_right_collision };
        return &config;    
    }

    return NULL;
}

static int shutter_can_open()
{
    if (0 == o->oBehParams2ndByte)
    {
        return o->oDistanceToMario < 500.f;
    }
    else if (1 == o->oBehParams2ndByte)
    {
        return o->oShutterSwitch->oAction != 0;
    }
    else
    {
        return 0;
    }
}

void bhv_shutter_init()
{
    f32 d;
    o->oShutterSwitch = cur_obj_find_nearest_object_with_behavior(bhvFloorSwitchHardcodedModel, &d);
}

void bhv_shutter_loop()
{
    const struct ShutterConfig* cfg = get_shutter_config();
    if (0 == o->oShutterInitialize)
    {
        o->oShutterLeft  = spawn_object(o, cfg->modelBase + 0, bhvCollision);
        obj_set_collision_data(o->oShutterLeft, cfg->collisionLeft);
        o->oShutterRight = spawn_object(o, cfg->modelBase + 1, bhvCollision);
        obj_set_collision_data(o->oShutterRight, cfg->collisionRight);
        o->oShutterLeft->oOpacity = 0;
        o->oShutterInitialize = 1;
    }

    if (0 == o->oAction)
    {
        if (shutter_can_open())
        {
            o->oAction = 1;
        }
    }
    else
    {
        const int period = 30;
        if (o->oTimer < period)
        {
            o->oShutterLeft->oOpacity = o->oTimer * 255 / period;
            o->oShutterLeft->oPosX -= 4 * 2.f * coss(-o->oFaceAngleYaw);
            o->oShutterLeft->oPosZ -= 4 * 2.f * sins(-o->oFaceAngleYaw);
            o->oShutterRight->oPosX += 4 * 7.f * coss(-o->oFaceAngleYaw);
            o->oShutterRight->oPosZ += 4 * 7.f * sins(-o->oFaceAngleYaw);
        }
        else
        {
            o->oShutterLeft->oOpacity = 255;
        }
    }
}
