void bhv_ss_ctl_init()
{
    f32 d;
    o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvBowser, &d);
}

void bhv_ss_ctl_loop()
{
    struct Object* bowser = o->parentObj;
    if (bowser->oAction == 1)
    {
    }
}
