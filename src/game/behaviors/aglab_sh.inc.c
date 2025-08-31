
#define oShDoorDoors oObjF4

static void obj_unhide(struct Object *obj) {
    obj->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
}

static void obj_hide(struct Object *obj) {
    obj->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
}

void bhv_sh_door_init()
{
    struct Object** objs = &o->oShDoorDoors;
    objs[0] = spawn_object(o, MODEL_SH_LR + o->oBehParams2ndByte, bhvStaticObject);
    objs[1] = spawn_object(o, MODEL_SH_RR + o->oBehParams2ndByte, bhvStaticObject);
}

void bhv_sh_door_loop()
{
    struct Object** objs = &o->oShDoorDoors;
    if (gMarioStates->pos[1] > -1430.f)
    {
        obj_hide(objs[0]);
        obj_hide(objs[1]);
    }
    else
    {
        obj_unhide(objs[0]);
        obj_unhide(objs[1]);
    }

    if (0 == o->oAction)
    {
        if (o->oDistanceToMario < 100.f)
        {
            o->oAction = 1;
        }    
    }
    else
    {
        if (o->oTimer < 30)
        {
            objs[0]->oPosX -= 10.f * coss(o->oFaceAngleYaw);
            objs[0]->oPosZ -= 10.f * sins(o->oFaceAngleYaw);
            objs[1]->oPosX += 10.f * coss(o->oFaceAngleYaw);
            objs[1]->oPosZ += 10.f * sins(o->oFaceAngleYaw);    
        }
        else
        {
            objs[0]->oPosX -= 20.f * sins(o->oFaceAngleYaw);
            objs[0]->oPosZ -= 20.f * coss(o->oFaceAngleYaw);
            objs[1]->oPosX -= 20.f * sins(o->oFaceAngleYaw);
            objs[1]->oPosZ -= 20.f * coss(o->oFaceAngleYaw);    
        }

        if (o->oTimer == 50)
        {
            o->activeFlags = 0;
            objs[0]->activeFlags = 0;
            objs[1]->activeFlags = 0;
        }
    }
}
