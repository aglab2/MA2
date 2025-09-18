Gfx *geo_gh_flowers(s32 callContext, UNUSED struct GraphNode *node, Mat4 mtx)
{
    if (callContext == GEO_CONTEXT_RENDER) {
        struct GraphNodeBatchsetTranslationRotation *transNode = (struct GraphNodeBatchsetTranslationRotation *) node->next;
        transNode->rotation[2] = gGlobalTimer * 0x8000 / 150;
    }
    return NULL;

}
