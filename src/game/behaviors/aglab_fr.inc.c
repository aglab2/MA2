void bhv_fr_drop()
{
    if (0 < o->oTimer && o->oTimer < 5)
    {
        gMarioStates->pos[1] = gMarioStates->floorHeight;
        set_mario_action(gMarioStates, ACT_BUTT_SLIDE, 0);
    }
}
