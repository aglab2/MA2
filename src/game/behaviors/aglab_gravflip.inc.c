extern void set_gravity(u32 grav);
void bhv_gravflip_loop()
{
    if (0 == o->oAction)
    {
        f32 dst = GET_BPARAM1(o->oBehParams) ? 1000.f : 100.f;
        if (o->oDistanceToMario < dst)
        {
            if (gIsGravityFlipped == !!o->oBehParams2ndByte)
            {
                o->oAction = 1;
                set_gravity(!o->oBehParams2ndByte);
            }
        }
    }
    else
    {
        gMarioStates->pos[0] = o->oPosX;
        gMarioStates->pos[2] = o->oPosZ;
        gMarioStates->vel[0] = 0;
        gMarioStates->vel[2] = 0;
        if (30 == o->oTimer || gMarioStates->floorHeight == gMarioStates->pos[1] || gCurrAreaIndex == 1)
        {
            o->oAction = 0;
        }
    }
}
