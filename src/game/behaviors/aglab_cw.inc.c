void bhv_cw_breakable_init()
{
    int rnd = random_u16() % 3;
    obj_set_model(o, MODEL_CW_METEO + 2 * rnd);
    o->oBehParams2ndByte = MODEL_CW_METEO_BREAK + 2 * rnd;
}
