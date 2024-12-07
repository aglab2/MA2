void bhv_pl_cage_loop()
{

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
