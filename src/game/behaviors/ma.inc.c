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

extern s8 gDialogCameraAngleIndex;

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
        o->oOpacity = 255;
    }
    else
    {
        o->oOpacity = 0;
    }

    if (gDialogCameraAngleIndex == 1 + 0xef - GET_BPARAM2(o->oBehParams))
    {
        o->oGeoRoll = 0;
        o->oInteractStatus = INT_STATUS_INTERACTED;
    }
    else
    {
        o->oGeoRoll = 0x4000;
    }
}

void bhv_checkpoint_loop()
{
    if (o->oAction)
    {
        if (0 != o->oGeoRoll)
        {
            o->oGeoRoll -= 0x200;
            if (255 != o->oOpacity)
                o->oOpacity = 255 - o->oGeoRoll * 255 / 0x4000;
        }
        else
        {
            if (gDialogCameraAngleIndex != 1 + 0xef - GET_BPARAM2(o->oBehParams))
            {
                o->oAction = 0;
                o->oGeoRoll = 0x4000;
                o->oInteractStatus = 0;
            }
        }
    }
    else
    {
        if (o->oInteractStatus & INT_STATUS_INTERACTED)
        {
            sSafeWarpId = GET_BPARAM2(o->oBehParams);
            gDialogCameraAngleIndex = 1 + 0xef - sSafeWarpId;
            o->oAction = 1;
        }
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
