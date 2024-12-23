extern const Collision ce_hammer_collision[];
extern const Collision ms_hammer_collision[];

static const Collision *const k_hammer_collisions[] = {
    [ LEVEL_CE ] = ce_hammer_collision,
    [ LEVEL_MS ] = ms_hammer_collision,
};

void bhv_up_down_init()
{
    o->oTimer = o->oBehParams2ndByte;
    obj_set_collision_data(o, k_hammer_collisions[gCurrLevelNum]);
}

void bhv_up_down_loop()
{
    if (o->oTimer == 240)
    {
        o->oTimer = 0;
    }

    if (o->oTimer < 120)
    {
        o->oPosY += 5.0f;
    }
    else
    {
        o->oPosY -= 5.0f;
    }
}
