static u8 sCreditsAlpha = 255;
Gfx *geo_update_alpha_compare_credits(s32 callContext, struct GraphNode *node, UNUSED void *context)
{
    Gfx *dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        struct GraphNodeGenerated *currentGraphNode = (struct GraphNodeGenerated *) node;
        s32 parameter = currentGraphNode->parameter;

        s32 objectOpacity = sCreditsAlpha;
        dlStart = alloc_display_list(sizeof(Gfx) * 3);

        Gfx *dlHead = dlStart;

        SET_GRAPH_NODE_LAYER(currentGraphNode->fnNode.node.flags, parameter);
        if (objectOpacity == 0xFF) {
            gDPSetAlphaCompareReal(dlHead++, G_AC_NONE);
        } else {
            gDPSetAlphaCompareReal(dlHead++, G_AC_DITHER);
        }
        gDPSetEnvColor(dlHead++, 255, 255, 255, objectOpacity);
        gSPEndDisplayList(dlHead);
    }

    return dlStart;
}

void bhv_credits_init()
{
    if (!gMarioStates->numStars)
        o->activeFlags = 0;
}

void bhv_credits_loop()
{
    int alpha = sCreditsAlpha;
    alpha -= 1;
    if (alpha < 0)
        alpha = 0;

    sCreditsAlpha = alpha;
}
