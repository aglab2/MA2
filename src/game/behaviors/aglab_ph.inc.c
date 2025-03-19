#define oPhTerminalStars oObjF4

extern struct Object *cur_obj_find_object_with_behavior_and_bparam3(const BehaviorScript *behavior, int val);
extern s32 obj_face_yaw_approach(s16 targetYaw, s16 deltaYaw);

void bhv_ph_terminal_init()
{
    struct Object** objs = &o->oObjF4;
    for (int i = 0; i < 4; i++)
        objs[i] = cur_obj_find_object_with_behavior_and_bparam3(bhvStar, i + 2);

    objs[4] = cur_obj_find_object_with_behavior_and_bparam3(bhvFloorSwitchGrills, 1);
    objs[5] = cur_obj_find_object_with_behavior_and_bparam3(bhvFloorSwitchGrills, 2);
    o->oFaceAngleYaw = 0x6000 + 0x5555;
}

void bhv_ph_terminal_loop()
{
    struct Object** objs = &o->oObjF4;
    if (o->oTimer > 0)
    {
        for (int i = 0; i < 4; i++)
        {
            SET_BPARAM3(objs[i]->oBehParams, 0);
        }
    }

    s16 target = 0x6000 + 0x5555;
    if (objs[4]->oAction == 1)
    {
        objs[5]->oAction = 3;
    }
    if (objs[5]->oAction == 1)
    {
        objs[4]->oAction = 3;
    }

    if (objs[4]->oAction == 2)
    {
        target -= 0x10000 / 3;
        SET_BPARAM3(objs[1]->oBehParams, 1);
    }
    else if (objs[5]->oAction == 2)
    {
        target += 0x10000 / 3;
        SET_BPARAM3(objs[2]->oBehParams, 1);
        SET_BPARAM3(objs[3]->oBehParams, 1);
    }
    else
    {
        SET_BPARAM3(objs[0]->oBehParams, 1);
    }

    obj_face_yaw_approach(target, 0x100);

    if (gMarioStates->action != ACT_FLYING && gMarioStates->action != ACT_SOFT_BONK && gMarioStates->action != ACT_BACKWARD_AIR_KB && gMarioStates->pos[1] < -14400.f)
    {
        set_mario_action(gMarioStates, ACT_FLYING, 0);
        gMarioStates->angleVel[0] = 0x800;
        gMarioStates->forwardVel = 80.f;
    }
}
