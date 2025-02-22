#include "game/print.h"

#define sCeTimerDeadline (*((u32*) &aglabGlobalScratch[0]))
#define sCeTimerLine ((char*) &aglabGlobalScratch[1])

static void ce_timer_print()
{
    if (sCeTimerDeadline < gGlobalTimer)
        return;

    int diff = sCeTimerDeadline - gGlobalTimer;
    int sec = diff / 30;
    int ms = diff % 30;

    sprintf(sCeTimerLine, "%d %02d", sec, ms);
    print_text_aligned(160, 20, sCeTimerLine, TEXT_ALIGN_CENTER);
}

extern void seq_player_play_sequence(u8 player, u8 seqId, u16 arg2);

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
            seq_player_play_sequence(0, 0x33, 0);
            sCeTimerDeadline = gGlobalTimer + 60 * 30;
        }
    }

    ce_timer_print();
}

void bhv_ce_timer_star_loop()
{
    ce_timer_print();
    if (gMarioStates->pos[1] < o->oPosY && gCurrAreaIndex == 10)
    {
        spawn_star(o, o->oPosX, o->oPosY, o->oPosZ);
        o->activeFlags = 0;
        sCeTimerDeadline = 0;
    }
}
