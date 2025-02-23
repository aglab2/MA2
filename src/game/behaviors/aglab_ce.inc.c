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
        if (sCeTimerDeadline)
            seq_player_play_sequence(0, 0x26, 0);

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

extern const Collision ce_car1_collision[];
extern const Collision ce_car2_collision[];
extern const Collision ce_car3_collision[];
extern const Collision ce_car4_collision[];
extern const Collision ce_car5_collision[];

static const Collision* kCeCarCollisions[] = {
    ce_car1_collision,
    ce_car2_collision,
    ce_car3_collision,
    ce_car4_collision,
    ce_car5_collision,    
};

extern void bhv_speeder_init();
void bhv_ce_car_init()
{
    obj_scale(o, 0.2f);

    int type = random_u16() % 5;
    int model = MODEL_CE_CAR1 + type;
    obj_set_model(o, model);
    obj_set_collision_data(o, kCeCarCollisions[type]);
    o->oDrawingDistance = 20000.f;
    bhv_speeder_init();
}

void bhv_ce_car_move_init()
{
    if (o->oBehParams2ndByte)
        o->oPosX -= 50.f * 50.f;

    o->oObjF4 = spawn_object(o, MODEL_NONE, bhvCeCar);
    o->oObjF4->oFaceAngleYaw = 0;
    o->oObjF4->oPosZ -= 300.f;

    o->oObjF8 = spawn_object(o, MODEL_NONE, bhvCeCar);
    o->oObjF8->oFaceAngleYaw = 0x8000;
    o->oObjF8->oPosZ += 300.f;
}

void bhv_ce_car_move_loop()
{
    int flip = (gGlobalTimer / 100) & 1;
    f32 diff = ((int) (gGlobalTimer % 100) - 50) * 50.f;
    if (flip)
        diff = -diff;

    o->oObjF4->oPosX = o->oPosX + diff;
    o->oObjF8->oPosX = o->oPosX - diff;
    o->oObjF4->oFaceAngleYaw = flip ? -0x4000 : 0x4000;
    o->oObjF8->oFaceAngleYaw = flip ?  0x4000 : -0x4000;
}
