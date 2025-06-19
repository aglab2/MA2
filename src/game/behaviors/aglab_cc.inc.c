u8 gTimeFrozen = 0;
static u32 gTimeFrozenTimerLoaded = 0;
static struct Object* gTimeFrozenTimerObj = NULL;

void bhv_cc_timestop_init()
{
    if (gTimeFrozenTimerLoaded == gGlobalTimer)
        return;

    gTimeFrozenTimerLoaded = gGlobalTimer;
    gTimeFrozenTimerObj = o;
}

static void bhv_purple_switch_loop_impl(int timer, int shift);
void bhv_cc_timestop_loop()
{
    o->oBehParams2ndByte = 2;

    // pin the ticking when mario is close.
    // this causes timer to stop ticking and refreshes the timer to 0.
    if (o->oAction > 1)
    {
        gTimeFrozen = 1;
        if (o->oDistanceToMario < 200.f)
        {
            o->oTimer = 0;
        }
        print_text_fmt_int(20, 20, "%d", (int) o->oDistanceToMario);
    }
    else
    {
        gTimeFrozen = 0;
    }
    bhv_purple_switch_loop_impl(200, 1);
}

extern ObjActionFunc sRotatingCwFireBarsActions[];

void bhv_cct_flames_loop()
{
    cur_obj_call_action_function(sRotatingCwFireBarsActions);
}

extern void bhv_cct_gate_loop()
{
    // -
}

extern void bhv_cct_platform_big_loop()
{
    o->oPosX = o->oHomeX + 400.0f * coss(o->oFaceAngleYaw) * coss(o->oTimer * 123);
    o->oPosZ = o->oHomeZ + 400.0f * sins(o->oFaceAngleYaw) * coss(o->oTimer * 123);
}

extern void bhv_cct_platform_loop()
{
    o->oPosY = o->oHomeY + 10.0f * sins(o->oTimer * 153);
}
