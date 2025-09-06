#define oLfHSTimer oF4

void bhv_lf_ctl_init()
{
    f32 d;
    o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvBowser, &d);
    obj_scale(o->parentObj, 5.f);
    o->parentObj->hitboxRadius = 1000.f;
    o->parentObj->hitboxHeight = 1300.f;
}

#define LF_HEIGHT 3000.f

static void spawn_snufit_circle()
{
    f32 radius = 500.f;
    for (int i = 0; i < 8; i++)
    {
        f32 angle = i * (0x10000 / 7);
        struct Object* snufit = spawn_object(o, MODEL_SNUFIT, bhvSnufit);
        snufit->oPosX = 0.f + radius * sins(angle);
        snufit->oPosY = LF_HEIGHT;
        snufit->oPosZ = 15000.f + radius * coss(angle);
        snufit->oDrawingDistance = 20000.f;
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
            spawn_snufit_circle();
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
