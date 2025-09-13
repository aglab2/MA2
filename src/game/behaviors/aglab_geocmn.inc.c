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
