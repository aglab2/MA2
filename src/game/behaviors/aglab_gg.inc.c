
extern u8 gFinaleNotes;
static void gg_check(Vec3f loc, const char* note)
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
        return;

    int notesVal = gFinaleNotes + 20;
    if (notesVal > 255)
        notesVal = 255;
    
    gFinaleNotes = notesVal;
    gExtraText = note;
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

    gg_check(notePos0, segmented_to_virtual(sLines[0]));
    gg_check(notePos1, segmented_to_virtual(sLines[1]));
    gg_check(notePos2, segmented_to_virtual(sLines[2]));
    gg_check(notePos3, segmented_to_virtual(sLines[3]));
}
