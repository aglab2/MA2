extern int on_spring();
void bhv_fr_drop()
{
    // if (0 < o->oTimer && o->oTimer < 5)
    if (o->oTimer > 0 && gMarioStates->floor && gMarioStates->floor->type == SURFACE_VERY_SLIPPERY && !on_spring())
    {
        gMarioStates->pos[1] = gMarioStates->floorHeight;
        set_mario_action(gMarioStates, ACT_BUTT_SLIDE, 0);
    }
}
