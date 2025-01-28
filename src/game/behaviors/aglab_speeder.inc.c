void bhv_speeder_loop()
{
    if (o->oDistanceToMario < 100.f)
    {
        gMarioStates->forwardVel = 200.f;
        gMarioStates->faceAngle[1] = 0x8000 + o->oFaceAngleYaw;
        gMarioStates->forwardVelOverrideDeadline = gGlobalTimer + 200/8;
        set_mario_action(gMarioStates, ACT_WALKING, 0);
    }
}
