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

void bhv_cw_lads_loop()
{

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
        print_text_fmt_int(20, 20, "C %d", (int) o->oStarMoveCurPoint);
        if (o->oStarMoveCurPoint < 4*49)
        {
            bhv_starmove_loop_impl(250.f - o->oStarMoveCurPoint);
        }
    }

    o->parentObj->oPosX = o->oPosX;
    o->parentObj->oPosY = o->oPosY;
    o->parentObj->oPosZ = o->oPosZ;
}
