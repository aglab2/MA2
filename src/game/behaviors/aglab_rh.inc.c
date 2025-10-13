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
            create_sound_spawner(SOUND_GENERAL_EXPLOSION7);
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

struct RhHammerBackup
{
    s16 timer;
    s16 y;
};

void bhv_rh_hammer_init()
{
    struct RhHammerBackup* rhBackup = (struct RhHammerBackup*) aglabGlobalScratch;

    const f32 A3Y = -4150.f*10.f;
    const f32 A4Y = -5123.f*10.f;

    int id = GET_BPARAM1(o->oBehParams);
    int mask = 1 << id;
    if (aglabGlobalScratch[0xf] & mask)
    {
        o->oTimer = rhBackup[id].timer;
        o->oPosY = rhBackup[id].y;
        if (gCurrAreaIndex == 3)
        {
            o->oPosY -= A3Y - A4Y;
        }
        else
        {
            gMarioStates->extraGravityEnabled = 1;
            o->oPosY -= A4Y - A3Y;
        }
    }
    else
    {
        aglabGlobalScratch[0xf] |= mask;
        o->oTimer = o->oBehParams2ndByte;
    }
}

void bhv_rh_hammer_loop()
{
    struct RhHammerBackup* rhBackup = (struct RhHammerBackup*) aglabGlobalScratch;

    bhv_up_down_loop();

    int id = GET_BPARAM1(o->oBehParams);
    rhBackup[id].timer = o->oTimer;
    rhBackup[id].y = o->oPosY;
    o->oDrawingDistance = 10000.f;
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
