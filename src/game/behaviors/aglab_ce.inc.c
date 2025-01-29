#define sCeTimerDeadline (*((u32*) &aglabGlobalScratch[0]))
#define sCeTimerLine ((char*) &aglabGlobalScratch[1])

static void ce_timer_print()
{
    if (sCeTimerDeadline < gGlobalTimer)
        return;

    int diff = sCeTimerDeadline - gGlobalTimer;
    int sec = diff / 30;
    int ms = diff % 30;

    sprintf(sCeTimerLine, "%d:%02d", sec, ms);
    print_text_aligned(160, 20, sCeTimerLine, TEXT_ALIGN_CENTER);
}

void bhv_ce_timer_loop()
{
    if (0 == o->oTimer && gMarioStates->pos[1] > o->oPosY)
    {
        sCeTimerDeadline = 0;
    }
    else if (0 == sCeTimerDeadline)
    {
        if (gMarioStates->pos[1] < o->oPosY && gMarioStates->pos[2] > 3000.f)
        {
            sCeTimerDeadline = gGlobalTimer + 60 * 30;
        }
    }

    ce_timer_print();
}

void bhv_ce_timer_star_loop()
{
    ce_timer_print();
}
