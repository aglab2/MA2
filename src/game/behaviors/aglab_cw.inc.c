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
