void bhv_lf_ctl_init()
{
    f32 d;
    o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvBowser, &d);
    obj_scale(o->parentObj, 5.f);
}

void bhv_lf_ctl_loop()
{
    o->parentObj->oFaceAngleYaw = 0;
    o->parentObj->oPosX = 0;
    o->parentObj->oPosY = -500;
    o->parentObj->oPosZ = 0;
}
