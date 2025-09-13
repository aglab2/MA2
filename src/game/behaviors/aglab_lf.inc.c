#define LF_INIT_PHASE lf_phase_balls

#define oLfHSTimer oF4
#define oLfSpawnerObjects oObjF4

// !!! These fields will be overwritten by oLfSpawnerObjects !!!
// You can only rely on them during the init sequence.
#define oLfSpawnerBeh oF4
#define oLfSpawnerModel os16F8

// And these fields _do_ get preserved, currently I am overwriting oHome
#define oLfSpawnerAmount OBJECT_FIELD_S32(0x37)
#define oLfSpawnerRadius OBJECT_FIELD_F32(0x38)
#define oLfSpawnerPattern OBJECT_FIELD_S32(0x39)

enum
{
    LF_PATTERN_CIRCLE,
    LF_PATTERN_LINE,
};

#define LF_HEIGHT 3000.f

extern const BehaviorScript bhvLfRingSpawner[];
static void lf_place(f32 x, f32 z, int model, const BehaviorScript* bhv, int pattern, f32 angleMult)
{
    struct Object* spwn = spawn_object(o, MODEL_NONE, bhvLfRingSpawner);
    spwn->oPosX = x;
    spwn->oPosY = LF_HEIGHT;
    spwn->oPosZ = z;
    spwn->oFaceAngleYaw = 0x4000 + random_u16() * angleMult;
    spwn->oLfSpawnerBeh = (uintptr_t)bhv;
    spwn->oLfSpawnerModel = model;
    spwn->oLfSpawnerAmount = 4;
    spwn->oLfSpawnerRadius = 400.f;
    spwn->oLfSpawnerPattern = pattern;
}

static void lf_phase_mr_blizzard()
{
    f32 xstart = random_f32_around_zero(3000.f);
    for (int i = 0; i < 6; i++)
    {
        f32 x = xstart + i * 1800.f;
        while (x > 3000.f) x -= 6000.f;
        f32 z = 15000.f - 2000.f * i;
        lf_place(x, z, MODEL_MR_BLIZZARD, bhvMrBlizzard, LF_PATTERN_CIRCLE, 1.f);
        x += 3000.f;
        if (x > 3000.f) x -= 6000.f;
        lf_place(x, z, MODEL_MR_BLIZZARD, bhvMrBlizzard, LF_PATTERN_CIRCLE, 1.f);
    }
}

static void lf_place2(f32 x, f32 z, int model, const BehaviorScript* bhv, int pattern, int angle)
{
    struct Object* spwn = spawn_object(o, MODEL_NONE, bhvLfRingSpawner);
    spwn->oPosX = x;
    spwn->oPosY = LF_HEIGHT;
    spwn->oPosZ = z;
    spwn->oMoveAngleYaw = spwn->oFaceAngleYaw = angle;
    spwn->oLfSpawnerBeh = (uintptr_t)bhv;
    spwn->oLfSpawnerModel = model;
    spwn->oLfSpawnerAmount = 4;
    spwn->oLfSpawnerRadius = 400.f;
    spwn->oLfSpawnerPattern = pattern;
}

static void lf_phase_snufit_circles()
{
    f32 xstart = random_f32_around_zero(3000.f);
    for (int i = 0; i < 6; i++)
    {
        f32 x = xstart + i * 1800.f;
        while (x > 3000.f) x -= 6000.f;
        f32 z = 15000.f - 2000.f * i;
        lf_place(x, z, MODEL_SNUFIT, bhvSnufitCC, LF_PATTERN_CIRCLE, 1.f);
        x += 3000.f;
        if (x > 3000.f) x -= 6000.f;
        lf_place(x, z, MODEL_SNUFIT, bhvSnufitCC, LF_PATTERN_CIRCLE, 1.f);
    }
}

static void lf_phase_snufit_lines()
{
    f32 xstart = random_f32_around_zero(3000.f);
    for (int i = 0; i < 6; i++)
    {
        f32 x = xstart + i * 1800.f;
        while (x > 3000.f) x -= 6000.f;
        f32 z = 15000.f - 2000.f * i;
        lf_place(x, -z, MODEL_SNUFIT, bhvSnufitCC, LF_PATTERN_LINE, 0.f);
        x += 3000.f;
        if (x > 3000.f) x -= 6000.f;
        lf_place(x, -z, MODEL_SNUFIT, bhvSnufitCC, LF_PATTERN_LINE, 0.f);
    }
}

static void lf_phase_spindrift()
{
    f32 xstart = random_f32_around_zero(3000.f);
    for (int i = 0; i < 6; i++)
    {
        f32 x = xstart + i * 1800.f;
        while (x > 3000.f) x -= 6000.f;
        f32 z = 15000.f - 2000.f * i;
        lf_place2(x, -z, MODEL_SPINDRIFT, bhvSpindrift, LF_PATTERN_LINE, 0xc000);
        x += 3000.f;
        if (x > 3000.f) x -= 6000.f;
        lf_place2(x, -z, MODEL_SPINDRIFT, bhvSpindrift, LF_PATTERN_LINE, 0xc000);
    }
}

extern const BehaviorScript bhvLfLazer[];
static void lf_phase_lazer()
{
    for (int i = 0; i < 6; i++)
    {
        f32 z = 15000.f - 2000.f * i;
        int side = (i & 1) ? -1 : 1;
        struct Object* spwn = spawn_object(o, MODEL_LF_LAZER, bhvLfLazer);
        spwn->oPosX = side * 3500.f;
        spwn->oPosY = LF_HEIGHT;
        spwn->oPosZ = z;
        spwn->oMoveAngleYaw = spwn->oFaceAngleYaw = 0;
    }
}

extern const BehaviorScript bhvLfBalls[];
static void lf_phase_balls()
{
    struct Object* bowser = o->parentObj;
    for (int layer = 0; layer < 7; layer++)
    {
        f32 radius = 3500.f - ABS(layer - 3) * 350.f;
        int amount = 9 + (layer & 1);
        for (int i = 0; i < amount; i++)
        {
            s16 angle = i * (0x6000 / amount) + (layer & 1) * (0x6000 / (2 * amount)) - 0x3000 + 0x8000;
            struct Object* spwn = spawn_object(bowser, MODEL_LF_PELLET, bhvLfBalls);
            //spwn->oPosX = bowser->oPosX + radius * sins(angle);
            //spwn->oPosY = LF_HEIGHT + (layer - 3) * 700.f - 2000.f;
            //spwn->oPosZ = bowser->oPosZ + radius * coss(angle);

            spwn->oPosX = spwn->oHomeX = bowser->oPosX;
            spwn->oPosY = spwn->oHomeY = LF_HEIGHT - 2000.f;
            spwn->oPosZ = spwn->oHomeZ = bowser->oPosZ;
            
            spwn->oSnufitPelletLfTargetPosX = radius * sins(angle);
            spwn->oSnufitPelletLfTargetPosY = (layer - 3) * 700.f;
            spwn->oSnufitPelletLfTargetPosZ = radius * coss(angle);

            spwn->oMoveAngleYaw = spwn->oFaceAngleYaw = angle + 0x8000;
            spwn->oDrawingDistance = 20000.f;
        }
    }
}

static void lf_place_spawners(int health)
{
    int phase = 4 - health;
    switch (phase)
    {
        case 0:
            lf_phase_mr_blizzard();
        break;
        case 1:
            lf_phase_spindrift();
        break;
        case 2:
            lf_phase_snufit_circles();
        break;
        case 3:
            lf_phase_snufit_lines();
        break;
        case 4:
            lf_phase_lazer();
        break;
        case 5:
            lf_phase_balls();
        break;
        case 6:
            lf_phase_snufit_circles();
            lf_phase_lazer();
        break;
    }
}

void bhv_lf_ctl_init()
{
    LF_INIT_PHASE();
    f32 d;
    o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvBowser, &d);
    obj_scale(o->parentObj, 5.f);
    o->parentObj->hitboxRadius = 1000.f;
    o->parentObj->hitboxHeight = 1300.f;
    gTimeFrozen = 0;
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
        if (o->oTimer > 30)
        {
            m->pos[1] = (m->pos[1] - 3000.f) * 0.9f + 3000.f;
        }
        m->pos[2] = side * 250 * o->oTimer;

        if (70 == o->oTimer)
        {
            lf_place_spawners(o->parentObj->oHealth);
        }

        if (80 == o->oTimer)
        {
            o->oAction = 0;
        }
    }
}

static void lf_scale(struct Object* obj, f32 scale)
{
    obj_scale(obj, scale);
    obj->oSnufitExtraScale = scale;
}

static void lf_mul_scale(struct Object* obj, f32 scale)
{
    f32 s = obj->oSnufitExtraScale * scale;
    lf_scale(obj, s);
}

void bhv_lf_ring_spawner_init()
{
    struct Object** objs = &o->oLfSpawnerObjects;
    f32 radius = o->oLfSpawnerRadius;
    int amount = o->oLfSpawnerAmount;
    int model = o->oLfSpawnerModel;
    int pattern = o->oLfSpawnerPattern;
    const BehaviorScript* bhv = (const BehaviorScript*) o->oLfSpawnerBeh;

    if (LF_PATTERN_CIRCLE == pattern)
    {
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

    if (LF_PATTERN_LINE == pattern)
    {
        for (int i = 0; i < amount; i++)
        {
            s16 angle = o->oFaceAngleYaw;
            struct Object* snufit = spawn_object(o, model, bhv);
            int loc = i - (amount / 2);
            snufit->oHomeX = snufit->oPosX = o->oPosX + loc * radius * sins(angle);
            snufit->oHomeY = snufit->oPosY = LF_HEIGHT;
            snufit->oHomeZ = snufit->oPosZ = o->oPosZ + loc * radius * coss(angle);
            snufit->oDrawingDistance = 20000.f;
            objs[i] = snufit;
        }
    }

    for (int i = 0; i < amount; i++)
    {
        lf_scale(objs[i], 0.1f);
    }
}

static inline void lf_wrap(f32* val, f32 min, f32 max)
{
    if (*val < min) *val = max - (min - *val);
    if (*val > max) *val = min + (*val - max);
}

extern void despawn_all(const BehaviorScript* behavior);
void bhv_lf_ring_spawner_loop()
{
    struct Object** objs = &o->oLfSpawnerObjects;

    struct Object* p = o->parentObj;
    if (o->oTimer > 30)
    {
        int despawn = 0;
        if (1 == p->oAction)
        {
            despawn = 1;
        }

        if (despawn)
        {
            despawn_all(bhvMrBlizzardSnowball);
            for (int i = 0; i < o->oLfSpawnerAmount; i++)
            {
                objs[i]->activeFlags = 0;
            }
            o->activeFlags = 0;
            return;
        }
    }

    f32 radius = o->oLfSpawnerRadius;
    int amount = o->oLfSpawnerAmount;
    int pattern = o->oLfSpawnerPattern;
    if (LF_PATTERN_CIRCLE == pattern)
    {
        for (int i = 0; i < amount; i++)
        {
            s16 angle = o->oFaceAngleYaw + i * (0x10000 / amount) + o->oTimer * 0x120;
            struct Object* snufit = objs[i];
            snufit->oHomeX = snufit->oPosX = o->oPosX + radius * sins(angle);
            snufit->oHomeY = snufit->oPosY = LF_HEIGHT;
            snufit->oHomeZ = snufit->oPosZ = o->oPosZ + radius * coss(angle);

            lf_scale(snufit, 1.f);
        }
    }

    if (LF_PATTERN_LINE == pattern)
    {
        for (int i = 0; i < amount; i++)
        {
            s16 angle = o->oFaceAngleYaw;

            struct Object* snufit = objs[i];
            snufit->oHomeX += 40.f * sins(angle);
            snufit->oHomeZ += 40.f * coss(angle);
            lf_wrap(&snufit->oHomeX, -4000.f, 4000.f);
            lf_wrap(&snufit->oHomeZ, -16000.f, -1000.f);
            snufit->oPosX = snufit->oHomeX;
            snufit->oPosZ = snufit->oHomeZ;

            snufit->oPosY = snufit->oHomeY = LF_HEIGHT;

            f32 scale = 1.f;
            f32 ax = ABS(snufit->oPosX);
            f32 az = ABS(snufit->oPosZ + 8000.f);

            f32 axclamp = (1000.f - CLAMP(ax - 3000.f, 0.f, 1000.f)) / 1000.f;
            f32 azclamp = (1000.f - CLAMP(az - 7000.f, 0.f, 1000.f)) / 1000.f;
            scale *= axclamp;
            scale *= azclamp;

            lf_scale(snufit, scale);
        }
    }

    if (o->oTimer <= 30)
    {
        for (int i = 0; i < amount; i++)
        {
            lf_mul_scale(objs[i], ((1 + o->oTimer) / 30.f));
        }
    }
}

void bhv_lf_lazer_loop()
{
    obj_scale(o, 0.6f);
    o->oDrawingDistance = 20000.f;
    int angle = 0xA00 * sins(o->oTimer * 0x175);
    if (o->oPosX < 0)
        angle += 0x8000;

    o->oMoveAngleYaw = o->oFaceAngleYaw = angle;

    struct Object* p = o->parentObj;
    if (o->oTimer >= 30)
    {
        int despawn = 0;
        if (1 == p->oAction)
        {
            despawn = 1;
        }

        if (despawn)
        {
            o->activeFlags = 0;
        }
    }
    else
    {
        obj_scale(o, 0.6f * ((1 + o->oTimer) / 30.f));
    }
}

void bhv_lf_balls_init()
{
    o->oSnufitPelletRange = 30000.f;
    o->oAction = 2;
    obj_scale(o, 0.1f);
    o->oFaceAngleRoll = random_u16();
    o->oFaceAngleYaw = random_u16();
    
}

extern struct ObjectHitbox sSnufitBulletHitbox;
extern s32 obj_check_attacks(struct ObjectHitbox *hitbox, s32 attackedMarioAction);
extern void obj_die_if_health_non_positive(void);
void bhv_lf_balls_loop()
{
    o->oFaceAngleRoll += 0x234;
    o->oFaceAngleYaw += 0x126;

    if (o->oAction == 2)
    {
        if (o->oTimer < 30)
        {
            f32 scale = ((1 + o->oTimer) / 30.f);
            obj_scale(o, 0.1f * scale);
            o->oPosX = o->oHomeX + o->oSnufitPelletLfTargetPosX * scale;
            o->oPosY = o->oHomeY + o->oSnufitPelletLfTargetPosY * scale;
            o->oPosZ = o->oHomeZ + o->oSnufitPelletLfTargetPosZ * scale;
        }

        obj_check_attacks(&sSnufitBulletHitbox, 3);
        if (o->oAction == 3 || (o->oMoveFlags & (OBJ_MOVE_MASK_ON_GROUND | OBJ_MOVE_HIT_WALL))) {
            o->oDeathSound = -1;
            obj_die_if_health_non_positive();
            return;
        }
        return;
    }
    
    bhv_snufit_balls_loop();
}
