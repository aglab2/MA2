#include "spring_desc.h"

extern const SpringDesc* spring_descs_mh[];
static const SpringDesc** kSpringDescs[] = {
    [ LEVEL_MH ] = spring_descs_mh,
};

#define oSpringBezier OBJECT_FIELD_VPTR(0x1B)

static void bezierInterp(s16* curve, Vec3f result, f32 t)
{
    s16* p0 = curve + 1;
    s16* p1 = curve + 5;
    s16* p2 = curve + 9;
    s16* p3 = curve + 13;

    f32 nt = 1.f - t;

    f32 b0 = nt * nt * nt;
    f32 b1 = 3.f * t * nt * nt;
    f32 b2 = 3.f * t * t * nt;
    f32 b3 = t * t * t;

    result[0] = b0 * p0[0] + b1 * p1[0] + b2 * p2[0] + b3 * p3[0];
    result[1] = b0 * p0[1] + b1 * p1[1] + b2 * p2[1] + b3 * p3[1];
    result[2] = b0 * p0[2] + b1 * p1[2] + b2 * p2[2] + b3 * p3[2];
}

// Curve is a singleton to ensure that 2 springs wont try to pull mario at the same time
static const s16* sSpringBezier = NULL;

void bhv_spring_loop()
{
    if (0 == o->oAction)
    {
        if (o->oDistanceToMario < 100.f)
        {
            o->oAction = 1;
            gMarioStates->pos[0] = o->oPosX;
            gMarioStates->pos[1] = o->oPosY;
            gMarioStates->pos[2] = o->oPosZ;
            set_mario_action(gMarioStates, ACT_JUMP, 0);
            sSpringBezier = (s16*)o->oSpringBezier;
        }
    }
    else
    {
        f32 quant = 1.f / 60.f;
        f32 t = (f32)o->oTimer * quant;
        s16* bezier = (s16*)o->oSpringBezier;
        if (bezier != sSpringBezier)
        {
            // other spring has taken over, reset
            o->oAction = 0;
            return;
        }

        if (t > 1.f || gMarioStates->action != ACT_JUMP)
        {
            // either action was cancelled or we reached the end of the curve
            // set up mario velocity roughly based on the curve
            o->oAction = 0;
            Vec3f start;
            Vec3f end;
            bezierInterp(bezier, start, t);
            bezierInterp(bezier, end, t + quant);
            gMarioStates->vel[0] = (end[0] - start[0]);
            gMarioStates->vel[1] = (end[1] - start[1]);
            gMarioStates->vel[2] = (end[2] - start[2]);
            // Technically we dont have to overwrite bezier check but be careful
            sSpringBezier = NULL;
            return;
        }

        bezierInterp(bezier, gMarioStates->pos, t);
    }
}

void bhv_spring_ctl_init()
{
    sSpringBezier = NULL;
}

void bhv_spring_ctl_loop()
{
    if (0 != o->oTimer)
        return;

    if (gCurrLevelNum >= (int) (sizeof(kSpringDescs) / sizeof(kSpringDescs[0])))
        return;

    const SpringDesc** areaDescs = kSpringDescs[gCurrLevelNum];
    if (!areaDescs)
        return;

    areaDescs = segmented_to_virtual(areaDescs);
    const SpringDesc* descs = areaDescs[gCurrAreaIndex - 1];
    if (!descs)
        return;

    descs = segmented_to_virtual(descs);
    while (descs->bezier)
    {
        s16* bezier = (s16*)segmented_to_virtual(descs->bezier);

        struct Object* spring = spawn_object(o, MODEL_SPRING, bhvSpring);
        spring->oPosX = bezier[1];
        spring->oPosY = bezier[2];
        spring->oPosZ = bezier[3];

        Vec3f diff;
        diff[0] = bezier[5] - bezier[1];
        diff[1] = bezier[6] - bezier[2];
        diff[2] = bezier[7] - bezier[3];

        spring->oFaceAnglePitch = atan2s(sqrtf(diff[0] * diff[0] + diff[2] * diff[2]), diff[1]);
        spring->oFaceAngleYaw = atan2s(diff[2], diff[0]);
        spring->oSpringBezier = bezier;

        descs++;
    }
}
