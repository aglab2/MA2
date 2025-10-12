Gfx *geo_lvlbatch_rotate(s32 callContext, struct GraphNode *node, UNUSED s32 context)
{
    if (callContext == GEO_CONTEXT_RENDER) {
        struct GraphNodeGenerated *fnNode = (struct GraphNodeGenerated *) node;
        int param = fnNode->parameter;
        struct LightGraphLvlNodeTranslationRotation *transNode = (struct LightGraphLvlNodeTranslationRotation *) node->next;
        transNode->rotation[2] += param;
    }
    return NULL;
}

Gfx *geo_lvlbatch_rotate2(s32 callContext, struct GraphNode *node, UNUSED s32 context)
{
    if (callContext == GEO_CONTEXT_RENDER) {
        struct GraphNodeGenerated *fnNode = (struct GraphNodeGenerated *) node;
        int param = fnNode->parameter;
        struct LightGraphLvlNodeTranslationRotation *transNode = (struct LightGraphLvlNodeTranslationRotation *) node->next;
        transNode->rotation[1] += param;
    }
    return NULL;
}

Gfx *geo_lvlbatch_rotate3(s32 callContext, struct GraphNode *node, UNUSED s32 context)
{
    if (callContext == GEO_CONTEXT_RENDER) {
        struct GraphNodeGenerated *fnNode = (struct GraphNodeGenerated *) node;
        int param = fnNode->parameter;
        struct GraphNodeBatchsetTranslationRotation *transNode = (struct GraphNodeBatchsetTranslationRotation *) node->next;
        transNode->rotation[0] += param;
    }
    return NULL;
}

Gfx *geo_lvlbatch_rotate4(s32 callContext, struct GraphNode *node, UNUSED s32 context)
{
    if (callContext == GEO_CONTEXT_RENDER) {
        struct GraphNodeGenerated *fnNode = (struct GraphNodeGenerated *) node;
        int param = fnNode->parameter;
        struct GraphNodeBatchsetTranslationRotation *transNode = (struct GraphNodeBatchsetTranslationRotation *) node->next;
        transNode->rotation[2] += param;
    }
    return NULL;
}

Gfx *geo_lvlbatch_rotate_pc(s32 callContext, struct GraphNode *node, UNUSED s32 context)
{
    if (callContext == GEO_CONTEXT_RENDER) {
        struct GraphNodeGenerated *fnNode = (struct GraphNodeGenerated *) node;
        struct LightGraphLvlNodeTranslationRotation *transNode = (struct LightGraphLvlNodeTranslationRotation *) node->next;
        transNode->rotation[0] = sins(gGlobalTimer * 0x123) * 1000;
    }
    return NULL;
}