extern void set_gravity(u32 grav);
void bhv_gravflip_loop()
{
    if (o->oDistanceToMario < 100.f)
    {
        set_gravity(!o->oBehParams2ndByte);
    }
}
