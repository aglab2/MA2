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
    {
        o->activeFlags = 0;
        return;
    }

    drop_and_set_mario_action(gMarioStates, ACT_SLEEPING, 0);

    Vec3f marioPos = { 18.f, 815.f, 9363.f };
    vec3_copy(gMarioStates->pos, marioPos);
    gMarioStates->faceAngle[1] = 0x8000;

    for (int i = 0; i < 3; i++)
    {
        struct Object* fly = spawn_object(o, MODEL_BUTTERFLY, bhvButterfly);
        fly->oPosX = marioPos[0] + (500.f + random_float() * 30.f) * sins(i * 0x10000 / 3);
        fly->oPosY = marioPos[1] + 50.f + (random_float() * 10.f);
        fly->oPosZ = marioPos[2] + (500.f + random_float() * 30.f) * coss(i * 0x10000 / 3);
    }

    gCurrDemoInput = (struct DemoInput *) &aglabGlobalScratch;
}

void bhv_credits_loop()
{
    print_text_fmt_int(20, 20, "%d", o->oTimer);

    gCamera->cutscene = CUTSCENE_CREDITS2;
    if (o->oTimer < 90)
        return;

    if (o->oTimer == 90)
    {
        play_sound(SOUND_PEACH_MARIO2, gGlobalSoundSource);
        set_mario_action(gMarioStates, ACT_WAKING_UP, 0);
    }

    if (o->oTimer == 120)
    {
        play_sound(SOUND_PEACH_DEAR_MARIO, gGlobalSoundSource);
    }

    if (o->oTimer == 130)
    {
        set_mario_action(gMarioStates, ACT_CREDITS_CUTSCENE, 0);
    }

    if (o->oTimer == 180)
    {
        set_mario_action(gMarioStates, ACT_IDLE, 0);
    }

    if (o->oTimer > 180)
    {
        if (o->oTimer > 240)
        {
            gCurrDemoInput->buttonMask = (A_BUTTON >> 8);
            gCurrDemoInput->buttonMask = o->oTimer & 1 ? 0 : (B_BUTTON >> 8);
        }

        gCurrDemoInput->rawStickY = -80;
        gCurrDemoInput->rawStickX = CLAMP(200 - o->oTimer, -80, 0);
    }

    return;

    int alpha = sCreditsAlpha;
    alpha -= 1;
    if (alpha < 0)
        alpha = 0;

    sCreditsAlpha = alpha;

}
