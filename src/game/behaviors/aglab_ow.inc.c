#define OW_LEVEL_COUNT 15

extern const Trajectory* sTrajectory;
extern const s16* sSpringBezier;

extern const BehaviorScript bhvOwVisual[];
extern const BehaviorScript bhvOwLock[];

const int gLevelWithHardModes = 1 << (LEVEL_CE - LEVEL_CE)
                              | 1 << (LEVEL_PL - LEVEL_CE)
                              | 1 << (LEVEL_MH - LEVEL_CE)
                              | 1 << (LEVEL_GF - LEVEL_CE)
                              | 1 << (LEVEL_MS - LEVEL_CE)
                              | 1 << (LEVEL_HB - LEVEL_CE)
                              | 1 << (LEVEL_PC - LEVEL_CE)
                              | 1 << (LEVEL_EE - LEVEL_CE)
                              | 1 << (LEVEL_CG - LEVEL_CE)
                              | 1 << (LEVEL_FR - LEVEL_CE)
                              ;

void bhv_ow_ctl_init()
{
    int off = 0x80;
    for (int i = 0; i < OW_LEVEL_COUNT; i++)
    {
        int withExtraMode = gLevelWithHardModes & (1 << i);

        {
            struct Object* obj = spawn_object(o, MODEL_OW_CE + i, bhvOwVisual);
            obj->oPosX = -585.f;
            obj->oPosY = 0.f;
            obj->oPosZ = 7238.f - 1000.f * i;
        }
        {
            struct Object* obj = spawn_object(o, MODEL_OW_LOCK, bhvOwLock);
            obj->oPosX = -585.f;
            obj->oPosY = 0.f;
            obj->oPosZ = 7238.f - 1000.f * i - 400.f;
            if (withExtraMode)
            {
                obj->oBehParams2ndByte = off++;
            }
            else
            {
                obj->oBehParams2ndByte = i;
            }
        }
        if (withExtraMode)
        {
            struct Object* obj = spawn_object(o, MODEL_OW_LOCK, bhvOwLock);
            obj->oPosX = -585.f - 400.f;
            obj->oPosY = 0.f;
            obj->oPosZ = 7238.f - 1000.f * i;
            obj->oFaceAngleYaw = 0x4000;
            obj->oBehParams2ndByte = i;
        }
    }

    sSpringBezier = NULL;
    sTrajectory = NULL;
}

void bhv_ow_ctl_loop()
{
}

void bhv_ow_visual_loop()
{
    f32 diff = gMarioStates->pos[2] - o->oPosZ;
    if (absf(diff) > 400)
    {
        if (o->oOpacity > 0)
        {
            o->oOpacity -= 17;
        }
    }
    else
    {
        if (o->oOpacity < 255)
        {
            o->oOpacity += 17;
        }
    }

    if (0 == o->oOpacity)
    {
        o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
    }
    else
    {
        o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
    }
}

void bhv_ow_lock_loop()
{
    bhv_ow_visual_loop();
    load_object_collision_model();
}
