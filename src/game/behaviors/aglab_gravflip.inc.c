extern void set_gravity(u32 grav);
void bhv_gravflip_loop()
{
    f32 dst = GET_BPARAM1(o->oBehParams) ? 1000.f : 100.f;
    if (o->oDistanceToMario < dst)
    {
        if (gIsGravityFlipped == !!o->oBehParams2ndByte)
        {
            gMarioStates->pos[0] = o->oPosX;
            gMarioStates->pos[1] = o->oPosY;
            gMarioStates->pos[2] = o->oPosZ;
            gMarioStates->vel[0] = 0;
            gMarioStates->vel[1] = 0;
            gMarioStates->vel[2] = 0;
        }
        set_gravity(!o->oBehParams2ndByte);
    }
}
