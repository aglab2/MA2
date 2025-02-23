
void bhv_ow_ctl_init()
{
    struct Object** objs = (struct Object**) aglabGlobalScratch;
    objs[0] = spawn_object(o, MODEL_OW_CE, bhvStaticObject);
    objs[0]->oPosX = -585.f;
    objs[0]->oPosY = 0.f;
    objs[0]->oPosZ = 7238.f;
    objs[0]->oOpacity = 0;
}

void bhv_ow_ctl_loop()
{
    struct Object** objs = (struct Object**) aglabGlobalScratch;
    for (int i = 0; i < 1; i++)
    {
        f32 diff = gMarioStates->pos[2] - objs[i]->oPosZ;
        if (absf(diff) > 700)
        {
            if (objs[0]->oOpacity > 0)
            {
                objs[0]->oOpacity -= 17;
            }
        }
        else
        {
            if (objs[0]->oOpacity < 255)
            {
                objs[0]->oOpacity += 17;
            }
        }

        if (0 == objs[0]->oOpacity)
        {
            objs[0]->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
        }
        else
        {
            objs[0]->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
        }
    }
}
