extern void obj_update_gfx_pos_and_angle(struct Object* obj);
void bhv_speeder_init()
{
    struct Surface* floor = NULL;
    if (gCurrCourseNum != COURSE_CG && FLOOR_LOWER_LIMIT != find_floor(o->oPosX, o->oPosY + 20.f, o->oPosZ, &floor))
        o->oFaceAnglePitch = atan2s(sqrtf(sqr(floor->normal.x) + sqr(floor->normal.z)), floor->normal.y) - 0x4000;

    obj_update_gfx_pos_and_angle(o);
}

void bhv_speeder_loop()
{
    if (o->oDistanceToMario < 100.f)
    {
        gMarioStates->forwardVel = 200.f;
        gMarioStates->faceAngle[1] = 0x8000 + o->oFaceAngleYaw;
        gMarioStates->forwardVelOverrideDeadline = gGlobalTimer + 200/8;
        set_mario_action(gMarioStates, ACT_WALKING, 0);
        cur_obj_play_sound_1(SOUND_ARG_LOAD(SOUND_BANK_ENV, 0x05, 0x00, SOUND_NO_VOLUME_LOSS | SOUND_CONSTANT_FREQUENCY));
    }
}
