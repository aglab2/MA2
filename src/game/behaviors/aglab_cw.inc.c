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
