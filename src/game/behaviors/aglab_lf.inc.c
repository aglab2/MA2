void bhv_lf_ctl_init()
{
    f32 d;
    o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvBowser, &d);
    obj_scale(o->parentObj, 5.f);
    o->parentObj->hitboxRadius = 1000.f;
    o->parentObj->hitboxHeight = 1300.f;
}

void bhv_lf_ctl_loop()
{
    o->parentObj->oPosX = 0;
    o->parentObj->oPosY = -500;
    o->parentObj->oPosZ = 0;
    
    if (o->parentObj->oAction != BOWSER_ACT_WALK_TO_MARIO
     && o->parentObj->oAction != BOWSER_ACT_HIT_MINE
     && o->parentObj->oAction != BOWSER_ACT_HIT_EDGE
     && o->parentObj->oAction != BOWSER_ACT_DEAD)
    {
        o->parentObj->oAction = 0;
    }

    gMarioStates->pos[0] = CLAMP(gMarioStates->pos[0], -3000.f, 3000.f);

    int sideSplit = o->parentObj->oHealth & 1;
    if (0 == o->oAction)
    {
        o->parentObj->oFaceAngleYaw = sideSplit ? 0x8000 : 0;
        int act = o->parentObj->oAction;
        if (act == BOWSER_ACT_HIT_MINE)
        {
            o->oAction = 1;
            int initAngle = sideSplit ? 0x8000 : 0;
            s8DirModeYawOffset = initAngle;
            gMarioStates->faceAngle[1] = 0x8000 - initAngle;
        }
    }
    else
    {
        int side = sideSplit ? -1 : 1;
        int angle = CLAMP(o->oTimer * 0x200, 0, 0x8000);
        o->parentObj->oFaceAngleYaw = sideSplit ? angle : (0x8000 - angle);
        gMarioStates->pos[0] = 0;
        gMarioStates->pos[2] = side * 160 * o->oTimer;

        if (o->oTimer == 105)
        {
            o->oAction = 0;
        }
    }
}
