void bhv_rh_slane_init()
{
    o->oHomeY = find_floor_height(o->oPosX, o->oPosY - 100.f, o->oPosZ);
}

void bhv_rh_slane_loop()
{
    if (0 == o->oAction)
    {
        if (gMarioObject->platform == o)
        {
            o->oAction = 1;
            cur_obj_set_model(MODEL_RH_SLANE_BREAK);
        }
    }
    else if (1 == o->oAction)
    {
        o->oPosY -= o->oTimer;
        if (o->oPosY < o->oHomeY)
        {
            o->oPosY = o->oHomeY;
            o->oAction = 2;
        }
    }
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

#define oRhExplosionsLocs oF4

struct RhLoc
{
    Vec3f pos;
};

void bhv_rh_explosions_init()
{
    struct RhLoc *loc = (struct RhLoc*) &o->oRhExplosionsLocs;
    if (0 == o->oBehParams2ndByte)
    {
        for (int i = 0; i < 5; i++)
        {
            loc[i].pos[0] = o->oPosX + random_f32_around_zero(1000.f);
            loc[i].pos[2] = o->oPosZ + random_f32_around_zero(1000.f);
            loc[i].pos[1] = find_floor_height(loc[i].pos[0], o->oPosY + 300.f, loc[i].pos[2]);
        }
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            loc[i].pos[0] = o->oPosX + (100.f * (i - 2)) * sins(o->oFaceAngleYaw);
            loc[i].pos[2] = o->oPosZ + (100.f * (i - 2)) * coss(o->oFaceAngleYaw);
            loc[i].pos[1] = find_floor_height(loc[i].pos[0], o->oPosY + 300.f, loc[i].pos[2]);
        }
    }
}

void bhv_rh_explosions_loop()
{
    struct RhLoc *loc = (struct RhLoc*) &o->oRhExplosionsLocs;
    if (0 == o->oAction)
    {
        if (o->oDistanceToMario < 1500.f)
            o->oAction = 1;

        if (0 == (o->oTimer % 5))
        {
            int i = (o->oTimer / 5) % 5;
            struct Object *sparkles = spawn_object(o, MODEL_SPARKLES, bhvCoinSparklesSpawner);
            sparkles->oPosX = loc[i].pos[0];
            sparkles->oPosY = loc[i].pos[1];
            sparkles->oPosZ = loc[i].pos[2];
        }
    }
    else
    {
        if (0 == (o->oTimer % 3))
        {
            int i = o->oTimer / 3;
            struct Object *explosion = spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
            explosion->oPosX = loc[i].pos[0];
            explosion->oPosY = loc[i].pos[1] + 50.f;
            explosion->oPosZ = loc[i].pos[2];

            if (4 == i)
                o->activeFlags = 0;
        }
    }
}
