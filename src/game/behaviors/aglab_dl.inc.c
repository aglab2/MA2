void bhv_dl_shell_loop()
{
    f32 d;
    struct Object* shell = cur_obj_find_nearest_object_with_behavior(bhvKoopaShellUnderwater, &d);
    if (!shell)
    {
        spawn_object(o, MODEL_KOOPA_SHELL, bhvKoopaShellUnderwater);
    }
}

void bhv_dl_flow_loop()
{
}
