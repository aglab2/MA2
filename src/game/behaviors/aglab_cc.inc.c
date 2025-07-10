#include "engine/math_util.h"

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
{ }

static void bhv_purple_switch_loop_impl(int timer, int shift, f32 dist, int main);

static inline void cc_timestop_sync_fun(struct Object* obj)
{
    obj->oPrevAction = o->oPrevAction;
    obj->oAction = o->oAction;
    obj->oTimer = o->oTimer;
}

static inline void cc_timestop_sync(void)
{
    gTimeFrozenTimerObj = o;
    cur_obj_foreach(bhvCCTimestop, cc_timestop_sync_fun);
}

int cc_switch_mario_nearby()
{
    Vec3f marioPos;
    vec3f_copy(marioPos, gMarioObject->header.gfx.pos);
    marioPos[1] += 40.f;

    Vec3f objPos;
    vec3f_copy(objPos, o->header.gfx.pos);

    Vec3f shift = { 0.f, 40.f, 0.f };
    rotate_in_yz(shift, shift, o->oFaceAnglePitch);
    rotate_in_xz(shift, shift, o->oFaceAngleRoll);

    vec3_add(objPos, shift);

    vec3_sub(objPos, marioPos);
    f32 dist = vec3_mag(objPos);
    return dist < 200.f; 
}

void bhv_cc_timestop_loop()
{
    o->oBehParams2ndByte = 2;

    // pin the ticking when mario is close.
    // this causes timer to stop ticking and refreshes the timer to 0.
    if (o->oAction > 1)
    {
        if (cc_switch_mario_nearby())
        {
            o->oTimer = 0;
            cc_timestop_sync();
        }
    }

    int preAction = o->oAction;
    int time = GET_BPARAM1(o->oBehParams);
    bhv_purple_switch_loop_impl(time ?: 200, 1, 200.f, o == gTimeFrozenTimerObj);
    int postAction = o->oAction;

    if (preAction == 0 && postAction == 1)
    {
        // switch was pressed on, distribute that state to all other switches
        cc_timestop_sync();
    }

    if (o == gTimeFrozenTimerObj)
    {
        if (o->oAction > 1)
        {
            gTimeFrozen = 1;
        }
        else
        {
            gTimeFrozen = 0;
        }
    }
    else
    {
        if (o->oAction && !gTimeFrozen)
        {
            o->oAction = 0;
        }
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
    if (o->oAction)
    {
        o->oHomeY += o->oTimer;
        return;
    }

    if (gMarioStates->action != ACT_JUMP_KICK && gMarioStates->action != ACT_MOVE_PUNCHING)
        return;

    if (!(gMarioStates->particleFlags & PARTICLE_TRIANGLE))
        return;

    f32 x = gMarioStates->pos[0] - o->oPosX;
    if (absf(x) > 300.f)
        return;

    f32 z = gMarioStates->pos[2] - o->oPosZ;
    if (0 > z || z > 100.f)
        return;

    f32 y = gMarioStates->pos[1] - o->oPosY;
    if (0 > y || y > 500.f)
        return;

    if (0 == o->oSubAction)
        obj_set_model(o, MODEL_CCT_GATE_HIT);
    o->oSubAction++;
    
    if (2 == o->oSubAction)
    {
        o->oBehParams2ndByte = 0xa;
        SET_BPARAM2(o->oBehParams, 0xa);
        gMarioStates->usedObj = o;
        level_trigger_warp(gMarioStates, WARP_OP_SPIN_SHRINK);
        o->oAction = 1;
    }
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
    o->oVelY = 2.0f * coss(o->oTimer * 223);
    o->oPosY += o->oVelY;
}

extern void grindel_thwomp_act_rising_impl(int normal);
extern void grindel_thwomp_act_floating_impl(int rng);
extern void grindel_thwomp_act_falling_impl(int normal);
extern void grindel_thwomp_act_land(void);
extern void grindel_thwomp_act_on_ground_impl(int rng);

void bhv_grindel_thwomp_loop_cc()
{
    CC_FREEZE();

    switch (o->oAction) {
        case 0: grindel_thwomp_act_rising_impl(0); break;
        case 1: grindel_thwomp_act_floating_impl(0); break;
        case 2: grindel_thwomp_act_falling_impl(0); break;
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

void bhv_cce_platform_fast_drop_loop()
{

}

#define oCCESpawnBlocks oObjF4
#define oCCEBlocksMask oF8

static struct Object* cc_spawn_block(int bparam, int* pidx)
{
    int idx = *pidx;
    *pidx = idx + 1;
    struct Object** blocks = &o->oCCESpawnBlocks;
    struct Object* block = spawn_object(o, MODEL_CCE_BLOCK, bhvCCSpawnBlock);
    block->oBehParams2ndByte = bparam;
    blocks[idx] = block;

    return block;
}

extern const BehaviorScript bhvCCSpawnBlock[];
void bhv_cce_spawn_block_init()
{
    struct Object** blocks = &o->oCCESpawnBlocks;
    int bparam = o->oBehParams2ndByte;
    int amountSpawned = 0;
    const f32 baseVel = 13.f;

    switch (bparam)
    {
        case 0:
            {
                struct Object* block = cc_spawn_block(bparam, &amountSpawned);
                block->oVelY = baseVel;
                block->oCCEBlocksMask = 127;
            }
            break;
        case 1:
            {
                struct Object* block = cc_spawn_block(bparam, &amountSpawned);
                block->oVelY = -baseVel;
                block->oFaceAngleRoll = 0x8000;
                block->oCCEBlocksMask = 127;
            }
            break;

        case 2:
            for (int i = 0; i < 2; i++)
            {
                struct Object* block = cc_spawn_block(bparam, &amountSpawned);
                block->oVelZ = baseVel;
                if (i)
                {
                    block->oPosZ += baseVel * 128;
                    block->oTimer = 128;
                }
                block->oFaceAngleRoll = 0x4000;
                block->oFaceAngleYaw = 0x4000;
                block->oCCEBlocksMask = 255;
            }
            break;
        case 3:
            for (int i = 0; i < 2; i++)
            {
                struct Object* block = cc_spawn_block(bparam, &amountSpawned);
                block->oVelZ = -baseVel;
                if (i)
                {
                    block->oPosZ -= baseVel * 128;
                    block->oTimer = 128;
                }
                block->oFaceAngleRoll = 0x4000;
                block->oFaceAngleYaw = 0xC000;
                block->oCCEBlocksMask = 255;
            }
            break;

        case 5:
            for (int i = 0; i < 2; i++)
            {
                struct Object* block = cc_spawn_block(bparam, &amountSpawned);
                block->oVelY = baseVel;
                block->oPosY += baseVel * 256 * i;
                block->oTimer = 256 * i;
                block->oCCEBlocksMask = 511;
            }
            break;
        case 4:
            for (int i = 0; i < 2; i++)
            {
                struct Object* block = cc_spawn_block(bparam, &amountSpawned);
                block->oVelY = baseVel;
                block->oPosY += baseVel * (128 + 256 * i);
                block->oTimer = (128 + 256 * i);
                block->oCCEBlocksMask = 511;
            }
            break;

        case 6:
            for (int i = 0; i < 2; i++)
            {
                struct Object* block = cc_spawn_block(bparam, &amountSpawned);
                block->oVelX = -baseVel;
                if (i)
                {
                    block->oPosX -= baseVel * 128;
                    block->oTimer = 128;
                }
                block->oFaceAngleRoll = 0x4000;
                block->oFaceAngleYaw = 0;
                block->oCCEBlocksMask = 255;
            }
            break;
        case 7:
            for (int i = 0; i < 2; i++)
            {
                struct Object* block = cc_spawn_block(bparam, &amountSpawned);
                block->oVelX = baseVel;
                if (i)
                {
                    block->oPosX += baseVel * 128;
                    block->oTimer = 128;
                }
                block->oFaceAngleRoll = 0x4000;
                block->oFaceAngleYaw = 0x8000;
                block->oCCEBlocksMask = 255;
            }
            break;
        
        case 8:
            {
                struct Object* block = cc_spawn_block(bparam, &amountSpawned);
                block->oVelX = -baseVel * sins(o->oFaceAngleYaw);
                block->oVelZ = -baseVel * coss(o->oFaceAngleYaw);
                block->oTimer = 64;
                block->oPosX += 64 * block->oVelX;
                block->oPosZ += 64 * block->oVelZ;
                block->oFaceAngleRoll = 0x4000;
                block->oFaceAngleYaw = -0x4000 + o->oFaceAngleYaw;
                block->oCCEBlocksMask = 127;
            }
            break;

        case 9:
            {
                struct Object* block = cc_spawn_block(bparam, &amountSpawned);
                block->oVelX = -baseVel * sins(o->oFaceAngleYaw);
                block->oVelZ = -baseVel * coss(o->oFaceAngleYaw);
                block->oFaceAngleRoll = 0x4000;
                block->oFaceAngleYaw = -0x4000 + o->oFaceAngleYaw;
                block->oCCEBlocksMask = 127;
            }
            break;
        
        case 10:
        case 13:
            for (int i = 0; i < 2; i++)
            {
                struct Object* block = cc_spawn_block(bparam, &amountSpawned);
                block->oVelY = -baseVel;
                if (i)
                {
                    block->oPosY -= baseVel * 128;
                    block->oTimer = 128;
                }
                block->oFaceAngleRoll = 0x8000;
                block->oCCEBlocksMask = 255;
            }
            break;

        case 11:
            for (int i = 0; i < 4; i++)
            {
                struct Object* block = cc_spawn_block(bparam, &amountSpawned);
                block->oVelX = baseVel;
                block->oPosX += i * baseVel * 128;
                block->oTimer = i * 128;
                block->oFaceAngleRoll = 0x4000;
                block->oFaceAngleYaw = 0x8000;
                block->oCCEBlocksMask = 511;
            }
            break;

        case 12:
            {
                struct Object* block = cc_spawn_block(bparam, &amountSpawned);
                block->oVelY = baseVel;
                block->oCCEBlocksMask = 127;
                block->oTimer = 64;
                block->oPosY += 64 * baseVel;
            }
            break;

        case 14:
            for (int i = 0; i < 2; i++)
            {
                struct Object* block = cc_spawn_block(bparam, &amountSpawned);
                block->oVelY = baseVel;
                if (i)
                {
                    block->oPosY += baseVel * 128;
                    block->oTimer = 128;
                }
                block->oCCEBlocksMask = 255;
            }
            break;

        case 15:
            for (int i = 0; i < 2; i++)
            {
                struct Object* block = cc_spawn_block(bparam, &amountSpawned);
                block->oVelY = baseVel;
                block->oTimer = 64 + i * 128;
                block->oPosY += block->oVelY * block->oTimer;
                block->oCCEBlocksMask = 255;
            }
            break;
        
        case 16:
            {
                struct Object* block = cc_spawn_block(bparam, &amountSpawned);
                block->oVelZ = baseVel * 3.f;
                obj_scale(block, 1.5f);
                block->oFaceAngleRoll = 0x4000;
                block->oFaceAngleYaw = 0x4000;
                block->oCCEBlocksMask = 127;
            }
            break;
    }

    for (int i = 0; i < amountSpawned; i++)
    {
        struct Object* block = blocks[i];
        f32 switchTimeV = 13.f;
        Vec3f vel;
        vec3_scale_dest(vel, &block->oVelVec, switchTimeV);
        vec3_sub(&block->oPosVec, vel);
    }

    o->oAction = 0;
    o->activeFlags = 0;
}

extern const Collision cce_block_collision[];
extern const Collision ccr_block_collision[];
void bhv_cce_block_init()
{
    if (gCurrLevelNum == LEVEL_CCE)
        obj_set_collision_data(o, cce_block_collision);
    if (gCurrLevelNum == LEVEL_CCR)
        obj_set_collision_data(o, ccr_block_collision);
}

void bhv_cce_block_loop()
{
    CC_FREEZE();
    f32 amt = 100 * sins(o->oTimer * 0x800);
    o->oOpacity = 150 + amt;
    o->oDamageOrCoinValue = 150 - amt;

    const int switchTime = o->oCCEBlocksMask;
    if (switchTime == (o->oTimer & switchTime))
    {
        Vec3f vel;
        vec3_scale_dest(vel, &o->oVelVec, switchTime);
        vec3_sub(&o->oPosVec, vel);
    }
    else
    {
        o->oPosX += o->oVelX;
        o->oPosY += o->oVelY;
        o->oPosZ += o->oVelZ;
    }
}

void bhv_chain_chomp_update_cc()
{
    if (o->oAction)
    {
        CC_FREEZE();
    }

    bhv_chain_chomp_update();
    bhv_chain_chomp_update();
}

void bhv_bobomb_loop_cc()
{
    CC_FREEZE();
    bhv_bobomb_loop();
    bhv_bobomb_loop();
}

void bhv_koopa_update_cc()
{
    CC_FREEZE();
    bhv_koopa_update();
    bhv_koopa_update();
}

void bhv_whomp_loop_cc()
{
    CC_FREEZE();
    bhv_whomp_loop();
    o->oTimer++;
    bhv_whomp_loop();
}

extern const BehaviorScript bhvCCRSwitchP2[];
void bhv_ccr_switch_init()
{
    o->parentObj = spawn_object(o, MODEL_CCR_SWITCH2, bhvCCRSwitchP2);
}

void bhv_ccr_switch2_loop()
{
    o->oDrawingDistance = 10000.f;
    o->oDistanceToMario = 0.f;
}

void bhv_ccr_capsule_init()
{
    f32 d;
    o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvFloorSwitchGrills, &d);
}

extern Gfx mat_ccr_dl_WallSweep1_sa2mdl_0_f3d[];
extern const Collision ccr_capopen_collision[];
void bhv_ccr_capsule_loop()
{
    o->oDrawingDistance = 10000.f;
    o->oDistanceToMario = 0.f;
    if (0 == o->oAction)
    {
        // if (10 == o->oTimer)
        if (0 != o->parentObj->oAction)
        {
            cur_obj_set_model(MODEL_CCR_CAPSULE_ANIM);
            gCamera->cutscene = CUTSCENE_CCR_1;
            o->oAction = 1;
            enable_time_stop_including_mario();
            return;
        }

        f32 yMax = 990.f;
        f32 yMin = 300.f;

        f32 rMax = 230.f;
        f32 rMin = 350.f;

        if (yMin <= gMarioStates->pos[1] && gMarioStates->pos[1] <= yMax)
        {
            f32 y = gMarioStates->pos[1] - yMin;
            f32 r = rMin + (rMax - rMin) * (y / (yMax - yMin));

            f32 d = gMarioStates->pos[0] * gMarioStates->pos[0] + gMarioStates->pos[2] * gMarioStates->pos[2];
            if (d < r * r)
            {
                f32 angle = atan2s(gMarioStates->pos[2], gMarioStates->pos[0]);
                gMarioStates->pos[0] = r * sins(angle);
                gMarioStates->pos[2] = r * coss(angle);
            }
        }

        load_object_collision_model();
    }
    else if (1 == o->oAction)
    {
        gCamera->cutscene = CUTSCENE_CCR_1;
        aglabGlobalScratch[0] = o->oTimer - 10;
        if (10 == o->oTimer)
        {
            u8* ptr = (u8*) segmented_to_virtual(mat_ccr_dl_WallSweep1_sa2mdl_0_f3d);
            ptr[10*8+7] = 0;
        }

        if (110 == o->oTimer)
        {
            o->oDrawingDistance = 2000.f;
            o->oAction = 2;
            cur_obj_set_model(MODEL_CCR_CAPSULE_OPEN);
            obj_set_collision_data(o, ccr_capopen_collision);
            load_object_static_model();
            reset_camera(gCamera);
            disable_time_stop_including_mario();
        }
    }
}

void bhv_ccr_water_lock_loop()
{
    if (gTimeFrozen)
        return;

    if (gMarioStates->pos[1] > 2800.f)
        return;

    f32 dx = gMarioStates->pos[0];
    if (absf(dx) > 300.f)
        return;

    f32 dz = gMarioStates->pos[2] + 2450.f;
    if (absf(dz) > 100.f)
        return;

    if (dz < 0)
        gMarioStates->pos[2] = -2450.f - 100.f;
    else
        gMarioStates->pos[2] = -2450.f + 100.f;
}

extern void bhv_clam_loop_impl(int buff);
void bhv_clam_cc_loop()
{
    CC_FREEZE();
    bhv_clam_loop_impl(1);
}

extern void bhv_skeeter_update_impl(int buff);
void bhv_skeeter_cc_update()
{
    CC_FREEZE();
    bhv_skeeter_update_impl(1);
    bhv_skeeter_update_impl(1);
}

void bhv_snufit_balls_loop_cc()
{
    CC_FREEZE();
    bhv_snufit_balls_loop();
}

Gfx *geo_ccr_anim(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx)
{
    if (callContext == GEO_CONTEXT_RENDER) {
        struct GraphNodeTranslationRotation *transNode = (struct GraphNodeTranslationRotation *) node->next;
        transNode->rotation[2] = -CLAMP(aglabGlobalScratch[0], 0, 80) * 0x8000 / 150; // 30 frames for full rotation
    }

    return NULL;
}
