u8 gTimeFrozen = 0;
static u32 gTimeFrozenTimerLoaded = 0;
static struct Object* gTimeFrozenTimerObj = NULL;

static void cc_freeze()
{
    o->oTimer--;
    o->header.gfx.areaIndex = 2; 
}

static void cc_unfreeze()
{
    o->header.gfx.areaIndex = 1;
}

#define CC_FREEZE() if (gTimeFrozen) { return cc_freeze(); } else { cc_unfreeze(); }

void bhv_cc_timestop_init()
{
    if (gTimeFrozenTimerLoaded == gGlobalTimer)
        return;

    gTimeFrozenTimerLoaded = gGlobalTimer;
    gTimeFrozenTimerObj = o;
}

static void bhv_purple_switch_loop_impl(int timer, int shift, f32 dist, int main);

static inline void cc_timestop_sync_fun(struct Object* obj)
{
    obj->oPrevAction = o->oPrevAction;
    obj->oAction = o->oAction;
    obj->oTimer = o->oTimer;
}

static inline void cc_timestop_sync(void)
{
    cur_obj_foreach(bhvCCTimestop, cc_timestop_sync_fun);
}

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
            cc_timestop_sync();
        }
    }
    else
    {
        gTimeFrozen = 0;
    }

    int preAction = o->oAction;
    bhv_purple_switch_loop_impl(200, 1, 200.f, o == gTimeFrozenTimerObj);
    int postAction = o->oAction;

    if (preAction == 0 && postAction == 1)
    {
        // switch was pressed on, distribute that state to all other switches
        cc_timestop_sync();
    }
}

extern ObjActionFunc sRotatingCwFireBarsActions[];

void bhv_cct_flames_loop()
{
    CC_FREEZE();
    cur_obj_call_action_function(sRotatingCwFireBarsActions);
}

void bhv_lll_rotating_hex_flame_loop(void) {
    CC_FREEZE();
    o->oAnimState++;
    cur_obj_set_pos_relative(o->parentObj, o->oLllRotatingHexFlameRelativePosX, o->oLllRotatingHexFlameRelativePosY, o->oLllRotatingHexFlameRelativePosZ);

    o->oPosY = o->parentObj->oPosY + 100.0f;

    if (o->parentObj->oAction == LLL_FIRE_BAR_ACT_REMOVE_FLAMES) {
        obj_mark_for_deletion(o);
    }
}

void bhv_cct_gate_loop()
{
}

void bhv_cct_platform_big_loop()
{
    CC_FREEZE();
    switch (o->oBehParams2ndByte)
    {
        case 0:
        {                    
            o->oVelX = 30.0f * sins(o->oFaceAngleYaw) * coss(o->oTimer * 423);
            o->oVelZ = 30.0f * coss(o->oFaceAngleYaw) * coss(o->oTimer * 423);

            o->oPosX += o->oVelX;
            o->oPosZ += o->oVelZ;
        }
        break;
        case 1:
        {
            f32 pivotX = o->oHomeX;
            f32 pivotZ = o->oHomeZ;

            o->oPosX = pivotX + 1500.f * sins(o->oTimer * 423);
            o->oPosZ = pivotZ + 1500.f * coss(o->oTimer * 423);
            o->oMoveAngleYaw = o->oFaceAngleYaw = o->oTimer * 423;
        }
        break;
        case 2:
        break;
    }
}

void bhv_cct_platform_loop()
{
    CC_FREEZE();
    o->oVelY = 40.0f * coss(o->oTimer * 223);
    o->oPosY += o->oVelY;
}

extern void grindel_thwomp_act_rising();
extern void grindel_thwomp_act_floating_impl(int rng);
extern void grindel_thwomp_act_falling();
extern void grindel_thwomp_act_land();
extern void grindel_thwomp_act_on_ground_impl(int rng);

void bhv_grindel_thwomp_loop_cc()
{
    CC_FREEZE();

    switch (o->oAction) {
        case 0: grindel_thwomp_act_rising(); break;
        case 1: grindel_thwomp_act_floating_impl(0); break;
        case 2: grindel_thwomp_act_falling(); break;
        case 3: grindel_thwomp_act_land(); break;
        case 4: grindel_thwomp_act_on_ground_impl(0); break;
    }
}

void bhv_snufit_loop_impl(int buff);
void bhv_snufit_loop_cc()
{
    CC_FREEZE();
    bhv_snufit_loop_impl(1);
}

extern void bhv_heave_ho_loop_impl(int);
extern void bhv_heave_ho_loop_frozen(void);
void bhv_heave_ho_loop_cc(void)
{
    if (gTimeFrozen)
    {
        o->oInteractionSubtype = INT_SUBTYPE_NOT_GRABBABLE;
        bhv_heave_ho_loop_frozen();
        return cc_freeze();
    }
    else
    {
        o->oInteractionSubtype = INT_SUBTYPE_NOT_GRABBABLE | INT_SUBTYPE_GRABS_MARIO;
        cc_unfreeze();
        bhv_heave_ho_loop_impl(1);
    }
}

extern void bhv_goomba_triplet_spawner_update_impl(const BehaviorScript* goombaBhv);
void bhv_goomba_triplet_spawner_update_cc(void)
{
    bhv_goomba_triplet_spawner_update_impl(bhvGoombaCC);
}

extern void bhv_coin_formation_loop_impl(const BehaviorScript* coinBhv);
extern const BehaviorScript bhvYellowCoinSpawnedCC[];
void bhv_coin_formation_loop_cc(void) {
    bhv_coin_formation_loop_impl(bhvYellowCoinSpawnedCC);
}

extern void bhv_goomba_update();
extern void bhv_goomba_update_cc()
{
    CC_FREEZE();
    bhv_goomba_update();
    bhv_goomba_update();
}

extern void bhv_coin_formation_spawned_coin_loop(void);
extern void bhv_coin_formation_spawned_coin_loop_cc()
{
    CC_FREEZE();
    bhv_coin_formation_spawned_coin_loop();
}
