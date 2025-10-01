void bhv_end_block_init()
{
    aglabGlobalScratch[0] = gLastCompletedCourseNum;

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
