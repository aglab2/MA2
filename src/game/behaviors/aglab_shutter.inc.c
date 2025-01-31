#define oShutterLeft oObjF4
#define oShutterRight oObjF8
#define oShutterInitialize oFC

struct ShutterConfig
{
    int modelBase;
    const void* collisionLeft;
    const void* collisionRight;
};

extern const Collision cg_shutter_left_collision[];
extern const Collision cg_shutter_right_collision[];

static const struct ShutterConfig* get_shutter_config()
{
    if (gCurrLevelNum == LEVEL_CG)
    {
        static struct ShutterConfig config = { MODEL_CG_SHUTTER_BASE, cg_shutter_left_collision, cg_shutter_right_collision };
        return &config;
    }

    return NULL;
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
        if (o->oDistanceToMario < 500.f)
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
            o->oShutterLeft->oPosX -= 4 * 2.f;
            o->oShutterRight->oPosX += 4 * 7.f;
        }
        else
        {
            o->oShutterLeft->oOpacity = 255;
        }
    }
}
