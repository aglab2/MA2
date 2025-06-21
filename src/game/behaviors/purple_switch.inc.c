
/**
 * Behavior for bhvFloorSwitchHardcodedModel, bhvFloorSwitchGrills, and
 * bhvFloorSwitchAnimatesObject.
 *
 * This controls the purple switches that Mario can step on to affect parts of
 * the environment.
 */

static int purple_on_switch(int shift, f32 dist)
{
    if (shift)
    {
        return lateral_dist_between_objects(o, gMarioObject) < dist;
    }
    else
    {
        return gMarioObject->platform == o;
    }
}

static void bhv_purple_switch_loop_impl(int timer, int shift, f32 dist, int main) {
    int yawSpeed = 0x100 << shift;
    int yawAccel = 0x40 << shift;
    int homeSpeed = 5 << shift;

    switch (o->oAction) {
        /**
         * Set the switch's model and scale. If Mario is standing near the
         * switch's middle section, transition to the pressed state.
         */
        case PURPLE_SWITCH_ACT_IDLE:
            o->oGeoYaw += yawSpeed;
            o->oHomeY = 0;
            o->oOpacity = 255;
            if (purple_on_switch(shift, dist)) {
                o->oAction = PURPLE_SWITCH_ACT_PRESSED;
            }
            break;

        /**
         * Collapse the switch downward, play a sound, and shake the screen.
         * Immediately transition to the ticking state.
         */
        case PURPLE_SWITCH_ACT_PRESSED:
           o->oHomeY = -o->oTimer * homeSpeed;
           o->oGeoYaw += yawSpeed - o->oTimer * yawAccel;
           o->oOpacity = 0xff - o->oTimer * 0x30;
            if (o->oTimer == 3) {
                cur_obj_play_sound_2(SOUND_GENERAL2_PURPLE_SWITCH);
                o->oAction = PURPLE_SWITCH_ACT_TICKING;
                cur_obj_shake_screen(SHAKE_POS_SMALL);
#if ENABLE_RUMBLE
                queue_rumble_data(5, 80);
#endif
            }
            break;

        /**
         * Play a continuous ticking sound that gets faster when time is almost
         * up. When time is up, move to a waiting-while-pressed state.
         */
        case PURPLE_SWITCH_ACT_TICKING:       
            o->oHomeY = -3 * homeSpeed;
            if (o->oBehParams2ndByte != 0) {
                if (o->oBehParams2ndByte == 1 && gMarioObject->platform != o) {
                    o->oAction++;
                } else {
                    if (o->oTimer < timer - 40) {
                        if (o->oTimer)
                        {
                            if (main) play_sound(SOUND_GENERAL2_SWITCH_TICK_FAST, gGlobalSoundSource);
                        }

                        int timeDiff = o->oTimer + 5;
                        int zerod = (timeDiff % 16) > 8;
                        o->oOpacity = zerod ? 0xff : (0xff - 3 * 0x30);
                    } else {
                        int timeDiff = o->oTimer - (timer - 40);
                        int zerod = (timeDiff % 5) > 2;
                        o->oOpacity = zerod ? 0xff : (0xff - 3 * 0x30);
                        if (main) play_sound(SOUND_GENERAL2_SWITCH_TICK_SLOW, gGlobalSoundSource);
                    }
                    if (o->oTimer > timer) {
                        o->oAction = PURPLE_SWITCH_ACT_WAIT_FOR_MARIO_TO_GET_OFF;
                    }
                }
            }
            break;

        /**
         * Make the switch look unpressed again, and transition back to the
         * idle state.
         */
        case PURPLE_SWITCH_ACT_UNPRESSED:
            o->oHomeY = -3 * homeSpeed + o->oTimer * homeSpeed;
            o->oGeoYaw += yawAccel + o->oTimer * yawAccel;
            o->oOpacity = 0xff - 4 * 0x30 + o->oTimer * 0x30; 
            if (o->oTimer == 3) {
                o->oAction = PURPLE_SWITCH_ACT_IDLE;
            }
            break;

        /**
         * Mario is standing on the switch, but time has expired. Wait for
         * him to get off the switch, and when he does so, transition to the
         * unpressed state.
         */
        case PURPLE_SWITCH_ACT_WAIT_FOR_MARIO_TO_GET_OFF:
            if (!cur_obj_is_mario_on_platform()) {
                o->oAction = PURPLE_SWITCH_ACT_UNPRESSED;
            }
            break;
    }
}

void bhv_purple_switch_loop(void) {
    bhv_purple_switch_loop_impl(400, 0, 150.f, 1);
}
