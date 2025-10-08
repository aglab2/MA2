#include "game/fail_warp.h"

static struct ObjectHitbox sCheckpointInteract = {
    /* interactType:      */ INTERACT_STAR_OR_KEY,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 140,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

extern s8 gDialogCameraAngleIndex;
static s8 sCheckpointActive = -1;

extern u8 sCheckpointIds;
static int toDialogId(int bparam2)
{
    int id = 1 + 0xef - bparam2;
    // this is referring to extra course checkpoint
    if (bparam2 == 0xe2)
        id = 64 - sCheckpointIds;

    int cc = COURSE_CCT <= gCurrCourseNum && gCurrCourseNum <= COURSE_CCS;
    if (cc)
    {
        id += 2 * (gCurrCourseNum - COURSE_CCT);
    }

    return id;
}

void bhv_checkpoint_init()
{
    u8 starId = GET_BPARAM1(o->oBehParams);
    obj_set_hitbox(o, &sCheckpointInteract);
    u64 currentLevelStarFlags = save_file_get_star_flags((gCurrSaveFileNum - 1), COURSE_NUM_TO_INDEX(gCurrCourseNum));
#if 0
    if (0) { 
#else
    if (currentLevelStarFlags & (1ULL << starId)) {
#endif
        o->oOpacity = 255;
        if (gDialogCameraAngleIndex == toDialogId(GET_BPARAM2(o->oBehParams)))
        {
            o->oGeoRoll = 0;
            o->oInteractStatus = INT_STATUS_INTERACTED;
            sCheckpointActive = gDialogCameraAngleIndex;
        }
        else
        {
            o->oGeoRoll = 0x4000;
        }
    }
    else
    {
        o->oGeoRoll = 0x4000;
        o->oOpacity = 0;
    }

    o->oDrawingDistance = 10000.0f;
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
            if (sCheckpointActive != toDialogId(GET_BPARAM2(o->oBehParams)))
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
            sCheckpointActive = toDialogId(sSafeWarpId);
            gDialogCameraAngleIndex = sCheckpointActive;
            o->oAction = 1;
        }
    }
}

static struct ObjectHitbox sGoalInteract = {
    /* interactType:      */ INTERACT_STAR_OR_KEY,
    /* downOffset:        */ 200,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 250,
    /* height:            */ 500,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_goal_init()
{
    obj_set_hitbox(o, &sGoalInteract);
}

void bhv_goal_loop()
{
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        o->activeFlags = 0;
    }


    o->oFaceAngleYaw += 0x180;
}
