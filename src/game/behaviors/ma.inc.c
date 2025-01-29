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
}

void bhv_checkpoint_loop()
{
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        // o->oInteractStatus = INT_STATUS_NONE;
    }
}

void bhv_goal_loop()
{

}
