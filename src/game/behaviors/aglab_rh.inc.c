void bhv_rh_slane_init()
{

}

void bhv_rh_slane_loop()
{

}

void bhv_rh_hammer_init()
{
    int id = GET_BPARAM1(o->oBehParams);
    int mask = 1 << id;
    if (aglabGlobalScratch[9] & mask)
    {
        o->oTimer = aglabGlobalScratch[id];
    }
    else
    {
        aglabGlobalScratch[9] |= mask;
        o->oTimer = o->oBehParams2ndByte;
    }
}

void bhv_rh_hammer_loop()
{
    bhv_up_down_loop();

    int id = GET_BPARAM1(o->oBehParams);
    aglabGlobalScratch[id] = o->oTimer;
}
