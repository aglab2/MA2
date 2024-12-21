void bhv_rocket_init()
{
    o->oGeoRoll = 0;
}

void bhv_rocket_loop()
{
    if (o->oTimer < 20)
    {
        o->oGeoRoll += 0x10;
        return;
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
        o->oPosY += 70.f;
        gMarioStates->pos[0] = o->oPosX;
        gMarioStates->pos[1] = o->oPosY;
        gMarioStates->pos[2] = o->oPosZ;
    }
}

void bhv_rocket_spawner_loop()
{
    switch (o->oAction)
    {
        case 0:
        {
            if (o->oDistanceToMario < 1000.f)
            {
                o->oAction = 1;
                o->parentObj = spawn_object(o, MODEL_ROCKET, bhvRocket);
            }
        }
        break;
        case 1:
        {
            o->oHomeZ = o->oTimer;
            o->parentObj->oPosY += 5.f;
            if (o->oTimer > 20)
            {
                o->oAction = 2;
            }
        }
        break;
        case 2:
        {
            if (o->oHomeZ > 0.f)
            {
                o->oHomeZ -= 1.f;
            }
            else
            {
                o->oHomeZ = 0;
            }
        }
        break;
    }
}
