#define oGGHasShown oF4

extern u8 gFinaleNotes;
extern const char* gExtraText2;
static int gg_check(Vec3f loc, const char* note, int i)
{
    if ((o->oTimer & 7) == 0)
    {
        struct Object* spark = spawn_object(o, MODEL_SPARKLES, bhvCoinSparklesSpawner);
        spark->oPosX = loc[0];
        spark->oPosY = loc[1];
        spark->oPosZ = loc[2];
    }

    Vec3f diff;
    vec3_diff(diff, gMarioStates->pos, loc);
    f32 d = vec3_sumsq(diff);
    if (d > 100.f * 100.f)
        return 0;

    int notesVal = gFinaleNotes + 20;
    if (notesVal > 255)
        notesVal = 255;
 
    char* tmpLine = (char*) aglabGlobalScratch;
    sprintf(tmpLine, "Note %d/4", i + 1);
        
    gFinaleNotes = notesVal;
    gExtraText = tmpLine;
    gExtraText2 = note;

    return 1;
}

extern const char gGGNote0[];
extern const char gGGNote1[];
extern const char gGGNote2[];
extern const char gGGNote3[];
static const char* sLines[] = { gGGNote0, gGGNote1, gGGNote2, gGGNote3 };

void bhv_gg_loop()
{
    f32 d;
    struct Object* star = cur_obj_find_nearest_object_with_behavior(bhvStar, &d);
    if (star)
        return;

    const Vec3f notePos0 = { -1200, -500, -982 };
    const Vec3f notePos1 = { -700,  -500, -1612 };
    const Vec3f notePos2 = {  700,  -500, -1612 };
    const Vec3f notePos3 = {  1200, -500, -982 };

    int shown = 0;
    shown |= gg_check(notePos0, segmented_to_virtual(sLines[0]), 0);
    shown |= gg_check(notePos1, segmented_to_virtual(sLines[1]), 1);
    shown |= gg_check(notePos2, segmented_to_virtual(sLines[2]), 2);
    shown |= gg_check(notePos3, segmented_to_virtual(sLines[3]), 3);

    if (shown && !o->oGGHasShown)
    {
        o->oGGHasShown = 1;
        struct Object* pipe = spawn_object(o, MODEL_THI_WARP_PIPE, bhvWarpPipe);
        pipe->oPosX = 0.f;
        pipe->oPosY = -500.f;
        pipe->oPosZ = 0.f;
        SET_BPARAM2(pipe->oBehParams, 0x0B);
        pipe->oBehParams2ndByte = 0xb;
    }
}

extern s16 gRolls;
extern const char gRollsStr[];
extern const char gClearText[];
void bhv_gg2_loop()
{
    if (o->oTimer < 2560)
    {
        gFinaleNotes = 0;
        gRolls = o->oTimer;
        gCamera->cutscene = CUTSCENE_CREDITS4;
        gExtraText = segmented_to_virtual(gRollsStr);
    }
    else
    {
        if (gExtraGuides < 20)
            gExtraGuides += 2;

        gExtraText = segmented_to_virtual(gClearText);
    }
}

Gfx* geo_credits_castle_move(s32 callContext, struct GraphNode* node, UNUSED void* context)
{
    if (callContext == GEO_CONTEXT_RENDER) {
        struct GraphNodeGenerated *fnNode = (struct GraphNodeGenerated *) node;
        int param = fnNode->parameter;
        struct GraphNodeTranslationRotation *transNode = (struct GraphNodeTranslationRotation *) node->next;
        transNode->rotation[1] += param;
        transNode->translation[1] += param / 5;
    }
    return NULL;
}
