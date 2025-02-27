#include "game/fail_warp.h"

static struct ObjectHitbox sCheckpointGoalInteract = {
    /* interactType:      */ INTERACT_STAR_OR_KEY,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 80,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_checkpoint_init()
{
    u8 starId = GET_BPARAM1(o->oBehParams);
    obj_set_hitbox(o, &sCheckpointGoalInteract);
    u64 currentLevelStarFlags = save_file_get_star_flags((gCurrSaveFileNum - 1), COURSE_NUM_TO_INDEX(gCurrCourseNum));
#if 0
    if (0) { 
#else
    if (currentLevelStarFlags & (1ULL << starId)) {
#endif
        o->oInteractStatus = INT_STATUS_INTERACTED;
        o->oGeoRoll = 0;
        o->oOpacity = 255;
    }
    else
    {
        o->oGeoRoll = 0x4000;
        o->oOpacity = 0;
    }
}

extern s8 gDialogCameraAngleIndex;
void bhv_checkpoint_loop()
{
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        if (0 != o->oGeoRoll)
        {
            o->oGeoRoll -= 0x200;
            o->oOpacity = 255 - o->oGeoRoll * 255 / 0x4000;
        }
    }

    if (o->oDistanceToMario < 100.0f) {
        sSafeWarpId = GET_BPARAM2(o->oBehParams);
        gDialogCameraAngleIndex = 1 + 0xef - sSafeWarpId;
    }
}

void bhv_goal_init()
{
    obj_set_hitbox(o, &sCheckpointGoalInteract);
}

void bhv_goal_loop()
{
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        o->activeFlags = 0;
    }
}
