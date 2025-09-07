#define oLfHSTimer oF4
#define oLfSpawnerObjects oObjF4

// !!! These fields will be overwritten by oLfSpawnerObjects !!!
// You can only rely on them during the init sequence.
#define oLfSpawnerBeh oF4
#define oLfSpawnerModel oF8

// And these fields _do_ get preserved, currently I am overwriting oHome
#define oLfSpawnerAmount OBJECT_FIELD_S32(0x37)
#define oLfSpawnerRadius OBJECT_FIELD_F32(0x38)

void bhv_lf_ctl_init()
{
    f32 d;
    o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvBowser, &d);
    obj_scale(o->parentObj, 5.f);
    o->parentObj->hitboxRadius = 1000.f;
    o->parentObj->hitboxHeight = 1300.f;
    gTimeFrozen = 0;
}

#define LF_HEIGHT 3000.f

extern const BehaviorScript bhvLfRingSpawner[];

static void lf_place(f32 x, f32 z, int model, const BehaviorScript* bhv)
{
    struct Object* spwn = spawn_object(o, MODEL_NONE, bhvLfRingSpawner);
    spwn->oPosX = x;
    spwn->oPosY = LF_HEIGHT;
    spwn->oPosZ = z;
    spwn->oFaceAngleYaw = random_u16();
    spwn->oLfSpawnerBeh = (uintptr_t)bhv;
    spwn->oLfSpawnerModel = model;
    spwn->oLfSpawnerAmount = 4;
    spwn->oLfSpawnerRadius = 400.f;
}

static void lf_place_spawners(int health)
{
    int phase = 4 - health;
    switch (phase)
    {
        case 0:
        {
            f32 xstart = random_f32_around_zero(3000.f);
            for (int i = 0; i < 6; i++)
            {
                f32 x = xstart + i * 1800.f;
                while (x > 3000.f) x -= 6000.f;
                f32 z = 15000.f - 2000.f * i;
                lf_place(x, z, MODEL_SNUFIT, bhvSnufitCC);
                x += 3000.f;
                if (x > 3000.f) x -= 6000.f;
                lf_place(x, z, MODEL_SNUFIT, bhvSnufitCC);
            }
        }
        break;
    }
}

void bhv_lf_ctl_loop()
{
    o->parentObj->oPosX = 0;
    o->parentObj->oPosY = -500;
    o->parentObj->oPosZ = 0;
    
    if (o->parentObj->oAction != BOWSER_ACT_WALK_TO_MARIO
     && o->parentObj->oAction != BOWSER_ACT_HIT_MINE
     && o->parentObj->oAction != BOWSER_ACT_HIT_EDGE
     && o->parentObj->oAction != BOWSER_ACT_DEAD)
    {
        o->parentObj->oAction = 0;
    }

    struct MarioState* m = gMarioStates;
    m->pos[0] = CLAMP(m->pos[0], -3000.f, 3000.f);

    int sideSplit = o->parentObj->oHealth & 1;
    int side = sideSplit ? -1 : 1;
    m->faceAngle[1] = sideSplit ? 0 : 0x8000;

    if (0 == o->oAction)
    {
        if (0 == o->oTimer)
        {
            lf_place_spawners(o->parentObj->oHealth);
        }

        o->parentObj->oFaceAngleYaw = sideSplit ? 0x8000 : 0;
        int act = o->parentObj->oAction;
        if (act == BOWSER_ACT_HIT_MINE)
        {
            o->oAction = 1;
            int initAngle = sideSplit ? 0x8000 : 0;
            s8DirModeYawOffset = initAngle;
            gMarioStates->faceAngle[1] = 0x8000 - initAngle;
        }

        if (0 == o->oSubAction)
        {
            if (m->hurtCounter)
            {
                m->invincTimer = 100;
                o->oSubAction = 1;
                o->oLfHSTimer = 64;
            }
        }
        else
        {
            o->oLfHSTimer--;
            m->pos[2] += side * o->oLfHSTimer * 2.f;
            if (o->oLfHSTimer == 0)
            {
                o->oSubAction = 0;
            }
        }
    }
    else
    {
        int angle = CLAMP(o->oTimer * 0x200, 0, 0x8000);
        o->parentObj->oFaceAngleYaw = sideSplit ? angle : (0x8000 - angle);
        m->pos[0] = 0;
        m->pos[2] = side * 160 * o->oTimer;

        if (o->oTimer == 105)
        {
            o->oAction = 0;
        }
    }
}

void bhv_lf_ring_spawner_init()
{
    struct Object** objs = &o->oLfSpawnerObjects;
    f32 radius = o->oLfSpawnerRadius;
    int amount = o->oLfSpawnerAmount;
    int model = o->oLfSpawnerModel;
    const BehaviorScript* bhv = (const BehaviorScript*) o->oLfSpawnerBeh;
    for (int i = 0; i < amount; i++)
    {
        s16 angle = o->oFaceAngleYaw + i * (0x10000 / amount);
        struct Object* snufit = spawn_object(o, model, bhv);
        snufit->oPosX = o->oPosX + radius * sins(angle);
        snufit->oPosY = LF_HEIGHT;
        snufit->oPosZ = o->oPosZ + radius * coss(angle);
        snufit->oDrawingDistance = 20000.f;
        objs[i] = snufit;
    }
}

void bhv_lf_ring_spawner_loop()
{
    struct Object* p = o->parentObj;

    struct Object** objs = &o->oLfSpawnerObjects;
    f32 radius = o->oLfSpawnerRadius;
    int amount = o->oLfSpawnerAmount;
    for (int i = 0; i < amount; i++)
    {
        s16 angle = o->oFaceAngleYaw + i * (0x10000 / amount) + o->oTimer * 0x120;
        struct Object* snufit = objs[i];
        snufit->oHomeX = snufit->oPosX = o->oPosX + radius * sins(angle);
        snufit->oHomeY = snufit->oPosY = LF_HEIGHT;
        snufit->oHomeZ = snufit->oPosZ = o->oPosZ + radius * coss(angle);
    }
}
