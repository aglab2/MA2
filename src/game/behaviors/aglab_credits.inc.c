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
    gCamera->cutscene = CUTSCENE_CREDITS2;
    if (o->oTimer < 90)
        return;

    if (o->oTimer == 90)
    {
        despawn_all(bhvTree);
        play_sound(SOUND_PEACH_MARIO2, gGlobalSoundSource);
        set_mario_action(gMarioStates, ACT_WAKING_UP, 0);
    }

    if (o->oTimer == 120)
    {
        despawn_all(bhvButterfly);
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

    if (o->oTimer == 190)
    {
        seq_player_play_sequence(0, 0x51, 0);
    }

    if (o->oTimer > 180)
    {
        if (o->oTimer > 240)
        {
            gCurrDemoInput->buttonMask = (A_BUTTON >> 8);
            gCurrDemoInput->buttonMask = o->oTimer & 1 ? 0 : (B_BUTTON >> 8);
        }

        gCurrDemoInput->rawStickY = -80;
        if (o->oTimer < 260)
        {
            gCurrDemoInput->rawStickX = CLAMP(200 - o->oTimer, -80, 0);
        }
        else
        {
            gCurrDemoInput->rawStickX = CLAMP(-260 + o->oTimer - 60, -80, 80);
        }
    }

    if (o->oTimer > 260)
    {
        int a = 255 - (o->oTimer - 260) * 3;
        sCreditsAlpha = CLAMP(a, 0, 255);

        if (sCreditsAlpha < 20)
        {
            gMarioStates->usedObj = o;
            SET_BPARAM2(o->oBehParams, 0xb);
            level_trigger_warp(gMarioStates, WARP_OP_TELEPORT);
            o->activeFlags = 0;
        }
    }
}

extern void bhv_credits_roll_init()
{
    gHudDisplay.flags = HUD_DISPLAY_FLAG_LIVES;
    set_mario_action(gMarioStates, ACT_DISAPPEARED, 0);
    gMarioStates->health = 0x880;
}

typedef struct Credits
{
    u8 alpha;
    u8 x;
    u8 y;
    const char* text;
} credits_t;

static void decay_credits()
{
    for (int i = 0; i < 7; i++)
    {
        credits_t* c = &((credits_t*) aglabGlobalScratch)[i];
        if (c->alpha > 5)
            c->alpha -= 5;
        else
            c->alpha = 0;
    }
}

#include "credits.h"
extern const CreditsEntry* gCredits[];
extern void bhv_credits_roll_loop()
{
    gCamera->cutscene = CUTSCENE_CREDITS3;
    credits_t* credits = (credits_t*) aglabGlobalScratch;

    //print_text_fmt_int(20, 20, "%d", o->oTimer);

    if (0 == o->oAction)
    {
        if (45 < o->oTimer && o->oTimer < 150)
        {
            credits[0].alpha = CLAMP(3 * (o->oTimer - 45), 0, 255);
            credits[0].text = "Visiting is nice, but home is better";
            credits[0].x = 160;
            credits[0].y = 120;
        }
        if (200 == o->oTimer)
        {
            o->oAction = 1;
        }
    }
    else if (1 == o->oAction)
    {
        if (o->oTimer < 220)
        {
            credits[0].alpha = CLAMP(3 * (o->oTimer - 45), 0, 255);
            credits[0].text = "Mario Adventure 2";
            credits[0].x = 160;
            credits[0].y = 130;
        }
        if (125 < o->oTimer && o->oTimer < 220)
        {
            credits[1].alpha = CLAMP(3 * (o->oTimer - 125), 0, 255);
            credits[1].text = "Made by aglab2";
            credits[1].x = 160;
            credits[1].y = 110;
        }

        if (280 == o->oTimer)
        {
            o->oAction = 2;
        }
    }
    else if (2 == o->oAction)
    {
        const CreditsEntry** entries = segmented_to_virtual(gCredits); 
        CreditsEntry* entry = entries[o->oSubAction];
        if (!entry)
        {
            o->oAction = 3;
            return;
        }

        entry = segmented_to_virtual(entry);

        if (o->oTimer < 170)
        {
            int i = 0;
            while (entry->text != NULL)
            {
                credits[i].alpha = CLAMP(3 * o->oTimer, 0, 255);
                credits[i].text = segmented_to_virtual(entry->text);
                credits[i].x = entry->x;
                credits[i].y = entry->y;
                entry++;
                i++;
            }
        }

        if (230 == o->oTimer)
        {
            o->oSubAction++;
            o->oTimer = 0;
        }
    }
    else if (3 == o->oAction)
    {
        {
            credits[0].alpha = CLAMP(3 * (o->oTimer), 0, 255);
            credits[0].text = "Thank you for playing";
            credits[0].x = 160;
            credits[0].y = 130;
        }
        {
            credits[1].alpha = CLAMP(3 * (o->oTimer - 240), 0, 255);
            credits[1].text = "I greatly appreciate it";
            credits[1].x = 160;
            credits[1].y = 110;
        }
    }

    decay_credits();
}

void render_credits()
{
    credits_t* credits = (credits_t*) aglabGlobalScratch;
    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    for (int i = 0; i < 7; i++)
    {
        credits_t* c = &credits[i];
        if (c->text == NULL)
            continue;

        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, c->alpha);
        print_generic_string_aligned(c->x, c->y, c->text, TEXT_ALIGN_CENTER);
    }
    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
}