void bhv_rocket_init()
{
    o->oGeoRoll = 0x500 * 20;
}

void bhv_rocket_loop()
{
    if (o->oTimer < 20)
    {
        if (0 == o->oAction)
            o->oGeoRoll -= 0x500;

        return;
    }

    if (0 == o->oAction)
    {
        if (o->oDistanceToMario < 100.f)
        {
            o->oAction = 1;
            struct MarioState* m = gMarioStates;
            mario_stop_riding_and_holding(m);

            o->oInteractStatus = TRUE; //! Note: Not a flag, treated as a TRUE/FALSE statement
            m->interactObj = o;
            m->usedObj     = o;

            update_mario_sound_and_camera(m);
            set_mario_action(m, ACT_RIDING_HOOT, 0);
        }
    }
    else
    {
        if (0 == o->oBehParams2ndByte)
        {
            o->oPosY += 70.f;
        }
        else
        {
            if (gCurrCourseNum == COURSE_RH)
            {
                o->oPosX -= 100.f * coss(o->oFaceAngleYaw);
                o->oPosZ -= 100.f * sins(o->oFaceAngleYaw);
            }
            else
            {
                o->oPosX -= 100.f * coss(o->oFaceAngleYaw-0x4000);
                o->oPosZ -= 100.f * sins(o->oFaceAngleYaw-0x4000);            
            }
        }

        puffAt(o, 10.f, 1, 50.f);
        if (0 == (o->oTimer % 4))
        {
            cur_obj_play_sound_1(SOUND_OBJ_FLAME_BLOWN);
        }
        
        if (o->oTimer > 110)
        {
            int act = 0 == o->oBehParams2ndByte ? ACT_FLYING : ACT_VERTICAL_WIND;
            set_mario_action(gMarioStates, act, 0);
            o->parentObj->oAction = 0;
            o->activeFlags = 0;
        }
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
                o->parentObj->oBehParams2ndByte = o->oBehParams2ndByte;
                o->parentObj->oFaceAngleYaw += 0x8000;
                if (o->oBehParams2ndByte)
                {
                    o->parentObj->oFaceAngleRoll -= 0x4000;
                }

                cur_obj_play_sound_1(SOUND_OBJ_CANNON_RISE);
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
