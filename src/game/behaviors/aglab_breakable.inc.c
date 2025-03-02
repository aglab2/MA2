void bhv_breakable_loop()
{
    if (0 == o->oAction)
    {
        if (o->oDistanceToMario < 130.f)
        {
            cur_obj_play_sound_2(SOUND_GENERAL_BREAK_BOX);
            o->oAction = 1;
            puffAt(o, 100.f, 10, 0.f);
            obj_set_model(o, o->oBehParams2ndByte);
        }
    }
}
