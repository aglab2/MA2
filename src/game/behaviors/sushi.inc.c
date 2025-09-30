// sushi.inc.c

void bhv_sushi_shark_loop(void) {
    o->oPosX = sins(o->oSushiSharkAngleFromHome) * 1700.0f;
    o->oPosZ = coss(o->oSushiSharkAngleFromHome) * 1700.0f;
    o->oPosY = o->oHomeY + sins(o->oSushiSharkAngleFromHome) * 200.0f;

    if (o->oHomeY > -2000.f)
    {    
        o->oSushiSharkAngleFromHome += 0x80;
        o->oMoveAngleYaw = o->oSushiSharkAngleFromHome + 0x4000;
    }
    else
    {
        o->oSushiSharkAngleFromHome -= 0x93;
        o->oMoveAngleYaw = o->oSushiSharkAngleFromHome - 0x4000;
    }

#if 0
    if (gMarioObject->oPosY - waterLevel > -500.0f) {
        if (o->oPosY - waterLevel > -200.0f) {
            spawn_object_with_scale(o, MODEL_WAVE_TRAIL, bhvObjectWaveTrail, 4.0f);
        }
    }
#endif

    if (!(o->oTimer & 0x0F)) {
        cur_obj_play_sound_2(SOUND_OBJ_SUSHI_SHARK_WATER_SOUND);
    }

    o->oInteractStatus = INT_STATUS_NONE;
}
