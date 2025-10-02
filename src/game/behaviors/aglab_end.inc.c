void bhv_end_block_init()
{
    gEndLevel = gLastCompletedCourseNum;

    reset_globals();
    if (gMarioStates->numStars < 400)
    {
        load_object_static_model();
    }
    else
    {
        o->activeFlags = 0;
    }
}
