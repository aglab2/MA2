
#define oShDoorDoors oObjF4

void bhv_sh_door_init()
{
    struct Object** objs = &o->oShDoorDoors;
    objs[0] = spawn_object(o, MODEL_SH_LR + o->oBehParams2ndByte, bhvStaticObject);
    objs[1] = spawn_object(o, MODEL_SH_RR + o->oBehParams2ndByte, bhvStaticObject);
}

void bhv_sh_door_loop()
{
    struct Object** objs = &o->oShDoorDoors;
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
