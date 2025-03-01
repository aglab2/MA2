void bhv_pl_cage_loop()
{
    if (0 == o->oAction)
    {
        int active = 0;
        switch (o->oBehParams2ndByte)
        {
            case 0:
                active = count_objects_with_behavior(bhvGoomba) <= 1;
                break;
            case 1:
                {
                    struct Object* eye = cur_obj_nearest_object_with_behavior(bhvMrI);
                    if (eye)
                    {
                        active = eye->oAction >= MR_I_BODY_ACT_SPIN_DEATH;
                    }
                    else
                    {
                        active = 0;
                    }
                }
                break;
            case 2:
                active = 0 == count_objects_with_behavior(bhvScuttlebug);
                break;
            case 3:
                active = 0 == count_objects_with_behavior(bhvFlyGuy);
                break;
            case 4:
                active = 0 == count_objects_with_behavior(bhvChuckya);
                break;
            case 5:
                active = 3 > count_objects_with_behavior(bhvSnufit);
                break;
            case 6:
                active = 2 > count_objects_with_behavior(bhvSnufit);
                break;
            case 7:
                active = 1 > count_objects_with_behavior(bhvSnufit);
                break;
            case 8:
                active = 0 == count_objects_with_behavior(bhvBoo);
                break;
            case 9:
                active = 0 == count_objects_with_behavior(bhvBobomb);
                break;
            case 10:
                active = 0 == count_objects_with_behavior(bhvFlyingBookend);
                break;
            case 11:
                active = 0 == count_objects_with_behavior(bhvGoomba);
                break;
            case 12:
                active = 0 == count_objects_with_behavior(bhvSwoop);
                break;
        }

        if (active)
        {
            o->oAction = 1;
        }
    }
    else
    {
        if (o->oTimer < 30)
        {
            cur_obj_play_sound_2(SOUND_ENV_ELEVATOR3);
            if (o->behavior == segmented_to_virtual(bhvPLCage2))
            {
                o->oPosX += 14.f * sins(o->oFaceAngleYaw);
                o->oPosZ += 14.f * coss(o->oFaceAngleYaw);
            }
            else
            {
                o->oPosY += 15.f;
            }
        }
    }
}

void bhv_pl_elv_loop()
{
    if (gMarioObject->platform == o)
    {
        if (o->oPosY < 6300.f)
        {
            cur_obj_play_sound_2(SOUND_ENV_ELEVATOR2);
            o->oPosY += 40.0f;
            o->oPosX -= 25.f;
        }

        o->oAction = 150;
    }
    else
    {
        if (o->oAction)
            o->oAction--;

        if (0 == o->oAction)
        {
            o->oPosX = o->oHomeX;
            o->oPosY = o->oHomeY;
            o->oPosZ = o->oHomeZ;
        }
    }
}

void bhv_pl_lift_loop()
{
    switch (o->oAction)
    {
        case 0:
        {
            if (gMarioObject->platform == o)
            {
                o->oAction = 1;
            }
        }
        break;
        case 1:
        {
            if (15 * o->oBehParams2ndByte == o->oTimer)
            {
                o->oAction = 2;
                return;
            }
            cur_obj_play_sound_2(SOUND_ENV_ELEVATOR1);
            o->oPosY += 18.f;
        }
        break;
        case 2:
        {
            if (o->oTimer == 100)
                o->oAction = 3;
        }
        break;
        case 3:
        {
            if (5 * o->oBehParams2ndByte == o->oTimer)
            {
                o->oAction = 0;
                return;
            }
            cur_obj_play_sound_2(SOUND_ENV_ELEVATOR1);
            o->oPosY -= 54.f;
        }
    };
}
