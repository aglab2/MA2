static void bhv_purple_switch_loop_impl(int timer);
void bhv_cc_timestop_loop()
{
    bhv_purple_switch_loop_impl(200);
}

extern ObjActionFunc sRotatingCwFireBarsActions[];
void bhv_cct_flames_loop()
{
    cur_obj_call_action_function(sRotatingCwFireBarsActions);
}

extern void bhv_cct_gate_loop()
{
    // -
}

extern void bhv_cct_platform_big_loop()
{
    o->oPosX = o->oHomeX + 400.0f * coss(o->oFaceAngleYaw) * coss(o->oTimer * 123);
    o->oPosZ = o->oHomeZ + 400.0f * sins(o->oFaceAngleYaw) * coss(o->oTimer * 123);
}

extern void bhv_cct_platform_loop()
{
    o->oPosY = o->oHomeY + 10.0f * sins(o->oTimer * 153);
}
