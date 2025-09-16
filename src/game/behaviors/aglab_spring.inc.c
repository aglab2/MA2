#include "spring_desc.h"

#define DEBUG_QUANT

const SpringDesc** gSpringDescs;
const SpringLinkDesc* gSpringLinks;

// Curve is a singleton to ensure that 2 springs wont try to pull mario at the same time
static s16 sSpringBezierLevelNum = 0;
const s16* sSpringBezier = NULL;
static int sSpringTimer = 0;

#define oSpringBezier OBJECT_FIELD_VPTR(0x1B)
#define oSpringQuant OBJECT_FIELD_F32(0x1C)

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

static void calculate_quant()
{
    // I am not taking integrals here for bezier curve but approximation will be good enough
    f32 bezierLength = 0;
    for (int i = 0; i < 3; i++)
    {
        Vec3f diff;
        diff[0] = sSpringBezier[5 + 4*i] - sSpringBezier[1 + 4*i];
        diff[1] = sSpringBezier[6 + 4*i] - sSpringBezier[2 + 4*i];
        diff[2] = sSpringBezier[7 + 4*i] - sSpringBezier[3 + 4*i];
        bezierLength += sqrtf(diff[0] * diff[0] + diff[1] * diff[1] + diff[2] * diff[2]);
    }

    o->oSpringQuant = (bezierLength < 2000.f ? 70.f : 140.f) / bezierLength;
}

void bhv_spring_init()
{
    if (sSpringBezier == o->oSpringBezier)
    {
        o->oAction = 1;
        o->oTimer = sSpringTimer;
        calculate_quant();
    }
    o->oDrawingDistance = 10000.f;
    o->oCollisionDistance = 10000.f;
}

extern u8 gIsGravityFlipped;
void bhv_spring_loop()
{
    if (0 == o->oAction)
    {
        if (o->oDistanceToMario < 200.f)
        {
            o->oAction = 1;
            gMarioStates->pos[0] = o->oPosX;
            gMarioStates->pos[1] = o->oPosY;
            if (gIsGravityFlipped)
                 gMarioStates->pos[1] = 9000.f - gMarioStates->pos[1];

            gMarioStates->pos[2] = o->oPosZ;
            gMarioStates->faceAngle[1] = o->oFaceAnglePitch < 0 ? o->oFaceAngleYaw - 0x8000 : o->oFaceAngleYaw;
            set_mario_action(gMarioStates, ACT_JUMP, 0);
            gMarioStates->squishTimer = 0;
            sSpringBezier = (s16*)o->oSpringBezier;
            calculate_quant();
        }
    }
    else
    {
        if (o->oTimer < 5)
        {
            // do this for a couple frames to ensure that mario is being in the jump animation
            gMarioStates->squishTimer = 0;
            gMarioStates->faceAngle[1] = o->oFaceAnglePitch < 0 ? o->oFaceAngleYaw - 0x8000 : o->oFaceAngleYaw;
            set_mario_action(gMarioStates, ACT_JUMP, 0);
        }

        f32 quant = o->oSpringQuant;
        sSpringTimer = o->oTimer;
        f32 t = (f32)o->oTimer * quant;
        s16* bezier = (s16*)o->oSpringBezier;
        if (bezier != sSpringBezier)
        {
            // other spring has taken over, reset
            o->oAction = 0;
            return;
        }
        
        if (t + quant > 1.f || gMarioStates->action != ACT_JUMP)
        {
            // either action was cancelled or we reached the end of the curve
            // Technically we dont have to overwrite bezier check but be careful
            sSpringBezier = NULL;
            o->oAction = 0;
            return;
        }

        Vec3f end;
        bezierInterp(bezier, gMarioStates->pos, t);
        bezierInterp(bezier, end, t + quant);
        gMarioStates->vel[0] = (end[0] - gMarioStates->pos[0]);
        gMarioStates->vel[1] = (end[1] - gMarioStates->pos[1]);
        gMarioStates->vel[2] = (end[2] - gMarioStates->pos[2]);
        gMarioStates->forwardVel = sqrtf(gMarioStates->vel[0] * gMarioStates->vel[0] + gMarioStates->vel[2] * gMarioStates->vel[2]);
        gMarioStates->extraGravityEnabled = 1;

        if (gIsGravityFlipped)
        {
            gMarioStates->vel[1] = -gMarioStates->vel[1];
            gMarioStates->pos[1] = 9000.f - gMarioStates->pos[1];
        }
    }
}

static void spring_transition_area()
{
    if (!sSpringBezier)
        return;

    const SpringLinkDesc* descs = gSpringLinks;
    if (!descs)
    {
        sSpringBezier = NULL;
        return;
    }

    while (descs->from)
    {
        if (segmented_to_virtual(descs->from) == sSpringBezier)
        {
            sSpringBezier = segmented_to_virtual(descs->to);
            return;
        }
        descs++;
    }

    sSpringBezier = NULL;
}

static void spring_spawn()
{
    const SpringDesc** areaDescs = gSpringDescs;
    if (!areaDescs)
        return;

    const SpringDesc* descs = areaDescs[gCurrAreaIndex - 1];
    if (!descs)
        return;

    descs = segmented_to_virtual(descs);
    while (descs->bezier)
    {
        s16* bezier = (s16*)segmented_to_virtual(descs->bezier);

        struct Object* spring = create_object(bhvSpring);
        spring->header.gfx.areaIndex = gCurrAreaIndex;
        spring->header.gfx.activeAreaIndex = gCurrAreaIndex;
        geo_obj_init((struct GraphNodeObject *) &spring->header.gfx, gLoadedGraphNodes[MODEL_SPRING], gVec3fZero, gVec3sZero);

        spring->oPosX = bezier[1];
        spring->oPosY = bezier[2];
        spring->oPosZ = bezier[3];

        Vec3f diff;
        diff[0] = bezier[5] - bezier[1];
        diff[1] = bezier[6] - bezier[2];
        diff[2] = bezier[7] - bezier[3];

        spring->oFaceAnglePitch = atan2s(sqrtf(diff[0] * diff[0] + diff[2] * diff[2]), diff[1]);
        spring->oFaceAngleYaw = atan2s(diff[2], diff[0]);
        if (spring->oFaceAnglePitch < 0)
            spring->oFaceAngleYaw = 0x8000 + spring->oFaceAngleYaw;

        spring->oSpringBezier = bezier;
        if (sSpringBezier == spring->oSpringBezier)
        {
            spring->oAction = 1;
            spring->oTimer = sSpringTimer;
            // calculate_quant();
        }

        descs++;
    }
}

void springs_init()
{
    if (sSpringBezierLevelNum != gCurrLevelNum)
    {
        sSpringBezierLevelNum = gCurrLevelNum;
        sSpringBezier = NULL;
    }

    spring_transition_area();
    spring_spawn();
}

int on_spring()
{
    return !!sSpringBezier;
}
