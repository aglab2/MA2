Gfx *geo_gh_flowers(s32 callContext, UNUSED struct GraphNode *node, Mat4 mtx)
{
    if (callContext == GEO_CONTEXT_RENDER) {
        struct GraphNodeBatchsetTranslationRotation *transNode = (struct GraphNodeBatchsetTranslationRotation *) node->next;
        transNode->rotation[2] = gGlobalTimer * 0x8000 / 150;
    }
    return NULL;

}

void bhv_gh_plat_loop()
{
    o->oPosX += 300.f * sins(o->oTimer * 0x800 / 15) * 300.f;
}

void bhv_gh_warp_loop()
{
    int isEntrance = GET_BPARAM1(o->oBehParams);
    int conn = o->oBehParams2ndByte;

    if (isEntrance)
    {
        if (0 == o->oAction)
        {
            if (o->oDistanceToMario < 100.f)
            {
                o->oAction = 1;
                drop_and_set_mario_action(gMarioStates, ACT_DISAPPEARED, 0);
            }
        }
        else
        {
            struct Object* target = cur_obj_find_object_with_behavior_and_bparam2(bhvGhWarp, conn);
            gMarioStates->pos[0] = target->oPosX;
            gMarioStates->pos[1] = target->oPosY;
            gMarioStates->pos[2] = target->oPosZ;
            gMarioStates->faceAngle[1] = target->oFaceAngleYaw;
            drop_and_set_mario_action(gMarioStates, ACT_EMERGE_FROM_PIPE, 0);
        }
    }
}
