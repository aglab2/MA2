// #define OW_LEVEL_COUNT 15
#define OW_LEVEL_COUNT 11

void bhv_ow_ctl_init()
{
    struct Object** objs = (struct Object**) aglabGlobalScratch;
    for (int i = 0; i < OW_LEVEL_COUNT; i++)
    {
        objs[i] = spawn_object(o, MODEL_OW_CE + i, bhvStaticObject);
        struct Object* obj = objs[i];
        obj->oPosX = -585.f;
        obj->oPosY = 0.f;
        obj->oPosZ = 7238.f - 1000 * i;
        obj->oOpacity = 0;
    }
}

void bhv_ow_ctl_loop()
{
    struct Object** objs = (struct Object**) aglabGlobalScratch;
    for (int i = 0; i < OW_LEVEL_COUNT; i++)
    {
        struct Object* obj = objs[i];

        f32 diff = gMarioStates->pos[2] - obj->oPosZ;
        if (absf(diff) > 400)
        {
            if (obj->oOpacity > 0)
            {
                obj->oOpacity -= 17;
            }
        }
        else
        {
            if (obj->oOpacity < 255)
            {
                obj->oOpacity += 17;
            }
        }

        if (0 == obj->oOpacity)
        {
            obj->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
        }
        else
        {
            obj->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
        }
    }
}
