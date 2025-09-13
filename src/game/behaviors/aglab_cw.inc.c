void bhv_cw_breakable_init()
{
    int rnd = random_u16() % 3;
    obj_set_model(o, MODEL_CW_METEO + 2 * rnd);
    o->oBehParams2ndByte = MODEL_CW_METEO_BREAK + 2 * rnd;
    o->oMoveAngleRoll = (random_u16() % 0x100) + 0x80;
    o->oMoveAnglePitch = (random_u16() % 0x100) + 0x90;
    o->oFaceAngleRoll = random_u16();
    o->oFaceAnglePitch = random_u16();
}

void bhv_cw_breakable_loop()
{
    o->oFaceAngleRoll += o->oMoveAngleRoll;
    o->oFaceAnglePitch += o->oMoveAnglePitch;
}

#define oCwLadsDespawn oF4

extern const BehaviorScript bhvCWLad[];

void bhv_cw_lads_init()
{
    o->oFaceAngleYaw += 0x8000;
}

void bhv_cw_lads_loop()
{
    if (o->oDistanceToMario < 10000.f)
    {
        if (2 != o->oCwLadsDespawn)
        {
            spawn_object_relative(0, -600, 0, 0, o, MODEL_CW_LAD, bhvCWLad);
            spawn_object_relative(0, 600, 0, 0, o, MODEL_CW_LAD, bhvCWLad);
            spawn_object_relative(0, 0, 300, 0, o, MODEL_CW_LAD, bhvCWLad);
            o->oCwLadsDespawn = 2;
        }
    }

    if (o->oDistanceToMario > 15000.f)
    {
        o->oCwLadsDespawn = 1;
    }
}

void bhv_cw_lad_init()
{
    o->oDrawingDistance = 10000.f;
}

void bhv_cw_lad_loop()
{
    struct Object* parent = o->parentObj;
    if (parent->oCwLadsDespawn == 1)
    {
        o->activeFlags = 0;
    }

    o->oPosY += sins(o->oTimer * 0x345) * 5.f;
    bhv_breakable_loop();
}

#define oStarMoveTraj OBJECT_FIELD_VPTR(0x1B)
#define oStarMoveCurPoint oF8
#define oStarMoveProgress oFloatFC

#define oCwStarMoveTraj OBJECT_FIELD_VPTR(0x1B)

static void bhv_starmove_loop_impl(f32 velocity);
extern const Trajectory cw_area_2_spline_NurbsCurve_StarMove[];
void bhv_cw_star_move_init()
{
    f32 d;
    o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvStar, &d);
    const Trajectory* traj = segmented_to_virtual(cw_area_2_spline_NurbsCurve_StarMove);
    o->oStarMoveTraj = traj;

    o->oPosX = traj[1];
    o->oPosY = traj[2];
    o->oPosZ = traj[3];
}

void bhv_cw_star_move_loop()
{
    const Trajectory *traj = (const Trajectory *) o->oF4;
    if (o->oAction == 0)
    {
        if (gMarioStates->pos[2] > -4000.f)
        {
            o->oAction = 1;
        }
    }
    else
    {
        if (o->oStarMoveCurPoint < 4*49)
        {
            bhv_starmove_loop_impl(150.f - o->oStarMoveCurPoint / 4);
        }
    }

    o->parentObj->oPosX = o->oPosX;
    o->parentObj->oPosY = o->oPosY;
    o->parentObj->oPosZ = o->oPosZ;

    if (o->parentObj->activeFlags == 0)
    {
        o->activeFlags = 0;
    }
}

Gfx *geo_cw_lad_rotate(s32 callContext, struct GraphNode *node, UNUSED s32 context)
{
    if (callContext == GEO_CONTEXT_RENDER) {
        // struct Object *obj = (struct Object *) gCurGraphNodeObject;
        struct GraphNodeGenerated *fnNode = (struct GraphNodeGenerated *) node;
        int param = fnNode->parameter;
        struct GraphNodeBatchsetTranslationRotation *transNode = (struct GraphNodeBatchsetTranslationRotation *) node->next;
        transNode->rotation[1] = !param ? 0x8000 : 0;
        transNode->rotation[2] = gGlobalTimer * 0x234;
    }
    return NULL;
}

struct cw_loc
{
    f32 progress;
    int amt;
};

static struct cw_loc get_cw_loc(f32 z, const Trajectory* traj)
{
    z += 3000.f;
    int i = 1;
    while (traj[4*(i+1)] != -1 && traj[4*i + 3] < z)
    {
        i++;
    }

    f32 dz = traj[4*i + 3] - z;
    f32 dt = traj[4*i + 3] - traj[4*(i-1) + 3];
    return (struct cw_loc) { 1.f - dz / dt, i };
}

#define CW_MAX_Z (*(f32*) aglabGlobalScratch)

extern const Trajectory cw_area_7_spline_0060_object_014980D4_003_StarMove[];
Gfx *geo_cw_ending(s32 callContext, struct GraphNode *node, UNUSED s32 context)
{
    if (callContext == GEO_CONTEXT_RENDER) {
        const Trajectory* traj = (const Trajectory*) segmented_to_virtual(cw_area_7_spline_0060_object_014980D4_003_StarMove);
        // struct Object *obj = (struct Object *) gCurGraphNodeObject;
        struct GraphNodeGenerated *fnNode = (struct GraphNodeGenerated *) node;
        int param = fnNode->parameter;
        struct LightGraphLvlNodeTranslationRotation *transNode = (struct LightGraphLvlNodeTranslationRotation *) node->next;

        int hasZ = 0;
        f32 mz;

        if (gCurrAreaIndex == 7)
        {
            mz = gMarioStates->pos[2];
            hasZ = 1;
        }
        else if (gCurrAreaIndex == 6)
        {
            mz = gMarioStates->pos[2] - 40000.f;
            hasZ = 1;
        }
        else
        {
            hasZ = 0;
        }

        if (!hasZ)
            return NULL;

    
        if (mz > CW_MAX_Z)
            CW_MAX_Z = mz;

        mz = CW_MAX_Z;

        int angle = 0;
        struct cw_loc loc = get_cw_loc(mz, traj);
        f32 progress = loc.progress;
        int amt = loc.amt;
        if (progress > 1.f) // after curve?
        {
            progress = 1.f;
            angle = 0;
        }
        else
        {
            if (progress < 0.f) // before curve?
            {
                progress = 0.f;
                mz = traj[3];
            }
            // magic constant is referring to the last point z value
            // aligned to be 0 in the end of the curve for smooth clamping
            angle = (mz - 25779.f) * 0x8;
        }

        f32 x = traj[4*(amt-1) + 1] + (traj[4*amt + 1] - traj[4*(amt-1) + 1]) * progress;
        f32 y = traj[4*(amt-1) + 2] + (traj[4*amt + 2] - traj[4*(amt-1) + 2]) * progress;
        f32 z = traj[4*(amt-1) + 3] + (traj[4*amt + 3] - traj[4*(amt-1) + 3]) * progress;

        // magic constants are area offset relative to global
        transNode->x = 50000.f  + x;
        transNode->y = 34870.f  + y  - 10.f;
        transNode->z = 160000.f + z;

        if (0 != param)
            transNode->rotation[2] = 0;
        else
            transNode->rotation[2] = angle;
    }
    return NULL;
}

#define CW_RANGE_RANDO 30.f
#define CW_RANGE_MOVEMENT 20.f
static inline void cw_reds_randomize(struct Object* obj)
{
    obj->oFaceAngleYaw = random_u16();
    f32 amt = random_f32_around_zero(CW_RANGE_RANDO);
    obj->oPosX += amt * sins(obj->oFaceAngleYaw);
    obj->oPosZ += amt * coss(obj->oFaceAngleYaw);
}

void bhv_cw_rot_ctl_init()
{
    CW_MAX_Z = -60000.f;
    cur_obj_foreach(bhvRedCoin, cw_reds_randomize);
}

static inline void cw_reds_move(struct Object* obj)
{
    obj->oPosX += CW_RANGE_MOVEMENT * sins(obj->oFaceAngleYaw) * sins(o->oTimer * 0x234);
    obj->oPosZ += CW_RANGE_MOVEMENT * coss(obj->oFaceAngleYaw) * sins(o->oTimer * 0x234);
}

void bhv_cw_rot_ctl_loop()
{
    cur_obj_foreach(bhvRedCoin, cw_reds_move);
}
