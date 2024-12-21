void bhv_gf_vine_loop()
{

}

extern const Collision gf_gake_a_collision[];
extern const Collision gf_gake_b_collision[];
extern const Collision gf_gake_c_collision[];
extern const Collision gf_gake_d_collision[];
extern const Collision gf_gake_e_collision[];
extern const Collision gf_gake_f_collision[];

void bhv_gf_gake_init()
{
    const Collision* collision = NULL;
    switch (o->oBehParams2ndByte)
    {
    case 0:
        collision = gf_gake_a_collision;
        break;
    case 1:
        collision = gf_gake_b_collision;
        break;
    case 2:
        collision = gf_gake_c_collision;
        break;
    case 3:
        collision = gf_gake_d_collision;
        break;
    case 4:
        collision = gf_gake_e_collision;
        break;
    case 5:
        collision = gf_gake_f_collision;
        break;
    }

    obj_set_collision_data(o, collision);
}

void bhv_gf_gake_loop()
{
    if (gMarioStates->pos[0] < 0)
    {
        o->oPosX = o->oHomeX;
        o->oPosY = o->oHomeY;
        o->oPosZ = o->oHomeZ;
    }
    else
    {
        o->oPosY -= 1.f;
        o->oPosY -= 0.6f * o->oBehParams2ndByte;
    }
}
