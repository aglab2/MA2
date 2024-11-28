extern const Collision ce_hammer_collision[];

void bhv_up_down_init()
{
    o->oTimer = o->oBehParams2ndByte;
    if (gCurrCourseNum == COURSE_CE)
    {
        obj_set_collision_data(o, ce_hammer_collision);
    }
}

void bhv_up_down_loop()
{
    if (o->oTimer == 240)
    {
        o->oTimer = 0;
    }

    if (o->oTimer < 120)
    {
        o->oPosY += 5.0f;
    }
    else
    {
        o->oPosY -= 5.0f;
    }
}
