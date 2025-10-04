// #define LB_NO_STAR
// #define LB_DEBUG_SHORTCUT_TO_PHASE 14

#define LB_PHASE0_LENGTH 40
#define LB_PHASE1_LENGTH 300
#define LB_PHASE2_LENGTH 300
#define LB_PHASE3_LENGTH 400
#define LB_PHASE4_LENGTH 380
#define LB_PHASE5_LENGTH 400
#define LB_PHASE6_LENGTH 460
#define LB_PHASE7_LENGTH 500

#include "rail_desc.h"

#define oLbTailRange oFloatF4
#define oLbTailFlipped oF8
#define oLbTailSpeed oFC
#define oLbTailTimeout o100

// patterns takes F4 and F8
#define oLbCtlPattern oF4
#define oLbCtlTailTimer oF8
#define oLbCtlWind oObjFC

#define oLbZapHitTimer oF4

#define oLbPlatformRange oF4
#define oLbPlatformSpeed oF8
#define oLbPlatformGrippedFrame oFC

#define oLbCoinPattern oF8
#define oLbCoinSpeed oFC
#define oLbCoinTimeout o100
#define oLbCoinRange oFloat104

void bhv_lb_ctl_init()
{
    gDialogCameraAngleIndex = 1;
    f32 d;
    o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvBowser, &d);
    o->parentObj->oHomeY = -100.f;

#ifndef LB_NO_STAR
    if (gMarioStates->pos[2] > 0)
    {
        gSecondCameraFocus = spawn_object(o, MODEL_STAR, bhvGrandStar);
        gSecondCameraFocus->oPosX = 0;
        gSecondCameraFocus->oPosY = 1050;
        gSecondCameraFocus->oPosZ = -10000;
    }
    else
    {
        gSecondCameraFocus = NULL;
    }
#endif
}

static void lb_pin_bowser()
{
    o->parentObj->oPosX = 0;
    o->parentObj->oPosY = 0;
    o->parentObj->oPosZ = 0;

    if (o->parentObj->oAction != BOWSER_ACT_WALK_TO_MARIO
     && o->parentObj->oAction != BOWSER_ACT_HIT_MINE
     && o->parentObj->oAction != BOWSER_ACT_HIT_EDGE
     && o->parentObj->oAction != BOWSER_ACT_DEAD)
    {
        s32 angleToMario = o->oAngleToMario;
        s16 angleFromMario = abs_angle_diff(o->parentObj->oMoveAngleYaw, angleToMario);
        if (angleFromMario > 0x1000)
        {
            o->parentObj->oAction = BOWSER_ACT_WALK_TO_MARIO;
        }
        else
        {
            o->parentObj->oAction = 0;
        }
    }
}

static void lb_pin_mario()
{
    f32 d = gMarioStates->pos[0] * gMarioStates->pos[0] + gMarioStates->pos[2] * gMarioStates->pos[2];
    if (d > 3400.f * 3400.f)
    {
        d = sqrtf(d);
        gMarioStates->pos[0] /= d;
        gMarioStates->pos[2] /= d;
        gMarioStates->pos[0] *= 3400.f;
        gMarioStates->pos[2] *= 3400.f;
    }

    if (gMarioStates->action == ACT_LAVA_BOOST)
    {
        if (gMarioStates->pos[1] > 900.f)
        {
            gMarioStates->pos[1] = 900.f;
            gMarioStates->vel[1] = 0.f;
        }
    }
}

static void lb_pin()
{
    lb_pin_bowser(); lb_pin_mario();
}

extern const Collision lb_tail_collision[];
extern const Collision lb_tail_collision_COPY[];

extern Vtx lb_tail_tail_mesh_layer_1_vtx_0[41] __attribute__((section(".data")));
extern Vtx lb_tail_tail_mesh_layer_1_vtx_1[17] __attribute__((section(".data")));
extern Vtx lb_tail_tail_mesh_layer_1_vtx_2[66] __attribute__((section(".data")));

extern Vtx lb_tail_tail_mesh_layer_1_vtx_0_COPY[41] __attribute__((section(".data")));
extern Vtx lb_tail_tail_mesh_layer_1_vtx_1_COPY[17] __attribute__((section(".data")));
extern Vtx lb_tail_tail_mesh_layer_1_vtx_2_COPY[66] __attribute__((section(".data")));

static void lb_vtx_modify(f32 amount, int count, Vtx* c, Vtx* t)
{
    c = segmented_to_virtual(c);
    t = segmented_to_virtual(t);
    for (int i = 0; i < count; i++)
    {
        Vtx* vt = &t[i];
        Vtx* vc = &c[i];
        int off = 450 + vc->v.ob[0];
        vt->v.ob[2] = vc->v.ob[2] + amount * off * off;
    }
}

static void lb_coll_modify(f32 amount)
{
    Collision* t = segmented_to_virtual(lb_tail_collision      + 2);
    Collision* c = segmented_to_virtual(lb_tail_collision_COPY + 2);
    for (int i = 0; i < 74; i++)
    {
        Collision* vt = t + 3*i;
        Collision* vc = c + 3*i;
        int off = 450 + vc[0];
        vt[2] = vc[2] + amount * off * off;
    }
}

static void lb_tail_modify_by(f32 amount)
{
    amount *= 0.00015f;
    lb_vtx_modify(amount, ARRAY_COUNT(lb_tail_tail_mesh_layer_1_vtx_0), lb_tail_tail_mesh_layer_1_vtx_0_COPY, lb_tail_tail_mesh_layer_1_vtx_0);
    lb_vtx_modify(amount, ARRAY_COUNT(lb_tail_tail_mesh_layer_1_vtx_1), lb_tail_tail_mesh_layer_1_vtx_1_COPY, lb_tail_tail_mesh_layer_1_vtx_1);
    lb_vtx_modify(amount, ARRAY_COUNT(lb_tail_tail_mesh_layer_1_vtx_2), lb_tail_tail_mesh_layer_1_vtx_2_COPY, lb_tail_tail_mesh_layer_1_vtx_2);

    lb_coll_modify(amount);
}

static void lb_tail_modify_sine()
{
    return lb_tail_modify_by(sins(o->oTimer * 0x163));
}

extern const Trajectory lb_area_1_spline_attach_00FCA364_001_1[];
extern const Trajectory lb_area_1_spline_attach_00FCA364_001_2[];
extern const Trajectory lb_area_1_spline_attach_00FCA364_001_3[];
extern const Trajectory lb_area_1_spline_attach_00FCA364_001_4[];
extern const Trajectory lb_area_1_spline_attach_00FCA364_001_C[];
__attribute__((noinline))
static void lb_traj_rotate(int num, s16 angle)
{
    static const Trajectory* kTrajs[] = {
        lb_area_1_spline_attach_00FCA364_001_1,
        lb_area_1_spline_attach_00FCA364_001_2,
        lb_area_1_spline_attach_00FCA364_001_3,
        lb_area_1_spline_attach_00FCA364_001_4,
    };

    Trajectory* t = segmented_to_virtual(kTrajs[num]);
    const Trajectory* c = segmented_to_virtual(lb_area_1_spline_attach_00FCA364_001_C);
    while (-1 != *t)
    {
        t[1] = c[1] * coss(angle) + c[3] * sins(angle);
        // t[2] = c[2];
        t[3] = c[3] * coss(angle) - c[1] * sins(angle);
        t += 4;
        c += 4;
    }
}

extern RailDesc lb_rails_area1[];
static void lb_rails_activate_switch(void)
{
    // This works because there are exactly 4 rails available
    // The first rail is a stop marker, then rest 4.
    // We perform swapping of the first and last rails to activate all 4 at once
    RailDesc* rails = segmented_to_virtual(lb_rails_area1);
    RailDesc* first = &rails[0];
    RailDesc* last  = &rails[4];

    RailDesc tmp = *first;
    *first = *last;
    *last = tmp;
}

static void lb_spawn_rails(void)
{
    s32 angleToMario = o->oAngleToMario;
    for (int i = 0; i < 4; i++)
    {
        struct Object* rail = spawn_object(o, MODEL_LB_RAIL, bhvLBRail);
        rail->oFaceAngleYaw = angleToMario + 0x10000 / 4 * i;
        lb_traj_rotate(i, rail->oFaceAngleYaw);
    }
    lb_rails_activate_switch();
}

extern const BehaviorScript bhvLbStand[];
static void lb_spawn_upp(int vel, s16 angle)
{
    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            struct Object* bubble = spawn_object(o, MODEL_LB_STAND, bhvLbStand);
            bubble->oLbPlatformRange = 1300.f;
            bubble->oPosY = 350.f + 450.f * j;
            bubble->oMoveAngleYaw = angle + 0x10000 / 8 * i + 0x10000 / 16 * j;
            bubble->oLbPlatformSpeed = vel * (j&1 ? -1 : 1);
        }   
    }
}

extern const BehaviorScript bhvLBBallAim[];
static void lb_patterns(int timeMod, int count)
{        
    s8* patterns = (u8*) &o->oLbCtlPattern;
    for (int k = 0; k < count; k++)
    {
        s8 pattern = patterns[k];
        if (timeMod == 1+5*k)
        {
            int model = pattern < 0 ? MODEL_LB_SPARKLE : MODEL_LB_SPARKLE2;
            struct Object* sparkle = spawn_object(o, model, bhvLbSparkle);
            cur_obj_play_sound_1(SOUND_AIR_AMP_BUZZ);
            sparkle->oPosY = 50.f;
            sparkle->oBehParams2ndByte = 1;
        }
        if (timeMod == 60+20*k)
        {
            // for (int i = 0; i < 6; i++)
            int i = 0;
            {
                s32 angleToMario = o->oAngleToMario;
                struct Object* ball = spawn_object(o, MODEL_LB_BALL, bhvLBBallAim);
                ball->oFaceAngleYaw = random_u16();
                ball->oFaceAngleRoll = random_u16();
                ball->oBehParams2ndByte = 0x10000 / 6 * i;
                ball->oPosY = 400.f + pattern * 400.f;
                obj_scale(ball, 0.1f);
            }
        }
    }
}

extern void fail_warp_set_safe_pos(f32* pos, s16 angle, int areaIndex, int levelNum);
extern void disable_background_sound();
extern const BehaviorScript bhvCoinFormationLB[];
extern void set_camera_mode_8_directions(struct Camera *c);
extern void func_8031D690(s32 player, s32 fadeInTime);
extern const BehaviorScript bhvLBWind[];
extern const BehaviorScript bhvLbBowserBomb[];

extern u8 gExtraGuides;
extern const char* gExtraText;

static int can_lb_warp(int warpId)
{
    if (warpId != 0xe)
        return 1;

    if (gMarioStates->numStars == 999)
        return 0;
    else
        return 1;
}

static void handle_lb_warp(f32 wsx, f32 wsy, f32 wsz, int warpId, const char* text)
{
    f32 warpSpot[] = { wsx, wsy, wsz };
    if ((gGlobalTimer & 7) == 0)
    {
        struct Object* sparkle = spawn_object(o, MODEL_SPARKLES, bhvCoinSparklesSpawner);
        sparkle->oPosX = warpSpot[0];
        sparkle->oPosY = warpSpot[1];
        sparkle->oPosZ = warpSpot[2];
    }

    f32 dx = gMarioStates->pos[0] - warpSpot[0];
    f32 dy = gMarioStates->pos[1] - warpSpot[1];
    f32 dz = gMarioStates->pos[2] - warpSpot[2];
    f32 d = dx*dx + dy*dy + dz*dz;
    if (d < 1000.f * 1000.f)
    {
        if (gExtraGuides < 20)
            gExtraGuides += 2;
        
        gExtraText = text;
    }

    if (can_lb_warp(warpId) && d < 40.f * 40.f)
    {
        gMarioStates->usedObj = o;
        SET_BPARAM2(o->oBehParams, warpId);
        level_trigger_warp(gMarioStates, WARP_OP_WARP_DOOR);
        drop_and_set_mario_action(gMarioStates, ACT_DISAPPEARED, 0);
    }
}

static void show_lb_warps()
{
    handle_lb_warp(-2689.f, 100.f, 0.f, 0xc, "In a level full of lush vegetation, a traveller may\nfind a level referencing Sonic legacy near the safe spot.\n\nUse this warp to travel back to Hero story.");
    handle_lb_warp( 2689.f, 100.f, 0.f, 0xd, "Seeking in a course filled with robots, a pilgrim\nmay find a suspicious door leading to the land of heavens.\n\nUse this warp to travel back to Dark story.");
    handle_lb_warp( 0.f, 20.f, -2900.f, 0xe, "The final reward awaits\nthe player that has 99.9%% completion.");
}

void bhv_lb_ctl_loop()
{
    if (o->oAction >= 3 && o->oAction <= 14)
        lb_pin();
    if (o->oAction == 14 || o->oAction == 15)
        lb_pin_bowser();
    if (o->oAction == 16)
        lb_pin_mario();

#if 0
    if (0 == o->oTimer)
        lb_spawn_rails();
#endif

#ifdef LB_DEBUG_SHORTCUT_TO_PHASE
    if (0 == o->oTimer && o->oAction == 0)
    {
        obj_scale(o->parentObj, 5.f);
        o->parentObj->hitboxRadius = 1000.f;
        o->parentObj->hitboxHeight = 1300.f;
        seq_player_play_sequence(0, 0x48, 0);
        func_8031D690(0, 60);
        o->oAction = LB_DEBUG_SHORTCUT_TO_PHASE;
        return;
    }
#endif

    if (0 == o->oAction)
    {
        if (gCamera->cutscene == 0)
        {
            show_lb_warps();
        }

        o->parentObj->oPosX = 0;
        o->parentObj->oPosY = -1000;
        o->parentObj->oPosZ = 0;

        if (gMarioStates->pos[2] < -11500.f)
        {
            o->parentObj->oPosX = 0;
            o->parentObj->oPosY = 1050;
            o->parentObj->oPosZ = -12000;

            gMarioStates->pos[1] = 1100.f;
            gMarioStates->faceAngle[1] = 0;
            gMarioStates->forwardVel = 200.f;
            gMarioStates->vel[0] = 0.f;
            gMarioStates->vel[1] = 50.f;
            gMarioStates->vel[2] = 0.f;
            set_mario_action(gMarioStates, ACT_THROWN_BACKWARD, 0);
            if (gSecondCameraFocus)
            {
                gSecondCameraFocus->activeFlags = 0;
                gSecondCameraFocus = NULL;
            }
            cur_obj_play_sound_2(SOUND_OBJ_BOWSER_LAUGH);
            o->oAction = 1;

            seq_player_play_sequence(0, 0x48, 0);
            func_8031D690(0, 60);
            
            Vec3f pos;
            pos[0] = gMarioStates->pos[0];
            pos[1] = gMarioStates->pos[1];
            pos[2] = -11000.f;
            fail_warp_set_safe_pos(pos, 0x8000, 1, LEVEL_LB);
        }

        if (gMarioStates->pos[2] > 5000.f)
        {
            o->oAction = 1000;
            gMarioStates->usedObj = o;
            SET_BPARAM2(o->oBehParams, 0xb);
            level_trigger_warp(gMarioStates, WARP_OP_WARP_DOOR);
        }
    }
    else if (1 == o->oAction)
    {
        if (gMarioStates->pos[1] < 101.f)
        {
            gMarioStates->vel[1] = -gMarioStates->vel[1];
            gMarioStates->forwardVel = 130.f;

            o->parentObj->oPosX = 0;
            o->parentObj->oPosY = 0;
            o->parentObj->oPosZ = 0;
            o->parentObj->oMoveAngleYaw = 0x8000;
            obj_scale(o->parentObj, 0.1f);
            o->parentObj->oAction = BOWSER_ACT_SPIT_FIRE_INTO_SKY;
            cur_obj_play_sound_2(SOUND_OBJ2_BOWSER_ROAR);

            o->parentObj->hitboxRadius = 1000.f;
            o->parentObj->hitboxHeight = 1300.f;
            o->parentObj->hurtboxRadius = 900.f;
            o->parentObj->hurtboxHeight = 1200.f;

            s8DirModeYawOffset = 0x8000;
   
            set_mario_action(gMarioStates, ACT_THROWN_BACKWARD, 0);

            o->oAction = 2;
        }
    }
    else if (2 == o->oAction)
    {
        if (o->oTimer < 25)
        {
            int negative = gMarioStates->pos[0] < 0;
            gMarioStates->pos[0] += negative ? -15.f : 15.f;
            gMarioStates->pos[0] = CLAMP(gMarioStates->pos[0] , -400.f, 400.f);
            gMarioStates->health = 0x880;
        }

        obj_scale(o->parentObj, 0.1f * o->oTimer);
        if (50 == o->oTimer)
        {
            o->oAction = 3;
        }
    }
    else if (3 == o->oAction)
    {
        if (LB_PHASE0_LENGTH == o->oTimer)
        {
            lb_tail_modify_sine();
            o->oAction = 4;
            s16 angle = random_u16();
            for (int i = 0; i < 3; i++)
            {
                struct Object* tail = spawn_object(o, MODEL_LB_TAIL, bhvLBTail);
                tail->oLbTailRange = 1800.f;
                tail->oOpacity = 0;
                tail->oLbTailSpeed = 0x100;
                tail->oLbTailTimeout = LB_PHASE1_LENGTH;
                tail->oMoveAngleYaw = angle + 0x10000 / 3 * i;
                tail->oBehParams2ndByte = 0;
            }
        }
    }
    else if (4 == o->oAction)
    {
        lb_tail_modify_sine();
        if (LB_PHASE1_LENGTH == o->oTimer)
        {
            o->oAction = 5;
            s8* patterns = (u8*) &o->oLbCtlPattern;
            for (int i = 0; i < 4; i++)
            {
                patterns[i + 1] = -1;
            }

            for (int i = 0; i < 2; i++)
            {
                int which = random_u16() % 4;
                patterns[which + 1] = 1;
            }
        }
    }
    else if (5 == o->oAction)
    {
#if 0
        int timeMod = o->oTimer % 40;
#if 0
        if (20 == timeMod && LB_PHASE2_LENGTH != o->oTimer)
        {
            struct Object* sparkle = spawn_object(o, MODEL_LB_SPARKLE, bhvLbSparkle);
            sparkle->oPosY = 50.f;
            sparkle->oBehParams2ndByte = 0;
        }
#endif
        if (39 == timeMod)
        {
            for (int i = 0; i < 6; i++)
            {
                s32 angleToMario = o->oAngleToMario;
                struct Object* ball = spawn_object(o, MODEL_LB_BALL, bhvLBBall);
                ball->oForwardVel = 50.f;
                ball->oMoveAngleYaw = angleToMario + 0x10000 / 6 * i;
                ball->oFaceAngleYaw = random_u16();
                ball->oFaceAngleRoll = random_u16();
                obj_scale(ball, 0.1f);
            }
        }
#else
        s8* patterns = (u8*) &o->oLbCtlPattern;
        int patternId = o->oTimer / 80;
        int timeMod = o->oTimer % 80;
        if (0 == timeMod)
        {
            patterns[0] = patterns[1 + patternId];
        }

        lb_patterns(timeMod, 1);
#endif

        if (LB_PHASE2_LENGTH == o->oTimer)
        {
            o->oAction = 6;
            lb_spawn_rails();
        }
    }
    else if (6 == o->oAction)
    {
        if (o->oTimer < 2)
            o->parentObj->oAction = BOWSER_ACT_HIT_EDGE;

        if (o->parentObj->oAction != BOWSER_ACT_HIT_EDGE)
        {
            o->oAction = 7;
            lb_rails_activate_switch();
        }
    }
    else if (7 == o->oAction)
    {
        if (0 == o->oTimer)
        {
            gMarioStates->vel[1] = 50.f;
            gMarioStates->forwardVel = -100.f;
        }

        if (50 == o->oTimer)
        {
            s16 angle = random_u16();
            for (int i = 0; i < 4; i++)
            {
                struct Object* tail = spawn_object(o, MODEL_LB_TAIL, bhvLBTail);
                tail->oLbTailRange = (i&1) ? 3200.f : 1800.f;
                tail->oLbTailFlipped = (i&1);
                tail->oOpacity = 0;
                tail->oLbTailSpeed = 0x90;
                tail->oLbTailTimeout = LB_PHASE3_LENGTH - 30;
                tail->oMoveAngleYaw = angle + 0x10000 / 4 * i + ((i&1) ? 0 : 0x8000);
                tail->oBehParams2ndByte = 0;
            }
            {
                struct Object* coins = spawn_object(o, MODEL_NONE, bhvCoinFormationLB);
                coins->oLbCoinPattern = (1 << 1)  | (1 << 2)
                                    | (1 << 4)  | (1 << 5)
                                    | (1 << 7)  | (1 << 8)
                                    | (1 << 10) | (1 << 11);
                coins->oMoveAngleYaw = angle;
                coins->oLbCoinSpeed = 0x90;
                coins->oLbCoinTimeout = LB_PHASE3_LENGTH - 30;
            }
        }

        lb_tail_modify_sine();

        if (LB_PHASE3_LENGTH == o->oTimer)
        {
            o->oAction = 8;
        }
    }
    else if (8 == o->oAction)
    {
        s8* patterns = (u8*) &o->oLbCtlPattern;
        int timeMod = o->oTimer % 130;
        if (0 == timeMod)
        {
            int which = random_u16() % 3;
            for (int i = 0; i < 3; i++)
            {
                patterns[i] = (i == which) ? -1 : 1;
            }
        }

        lb_patterns(timeMod, 3);
        if (LB_PHASE4_LENGTH == o->oTimer)
        {
            o->oAction = 9;
            lb_spawn_rails();
        }
    }
    else if (9 == o->oAction)
    {
        if (o->oTimer < 2)
            o->parentObj->oAction = BOWSER_ACT_HIT_EDGE;

        if (o->parentObj->oAction != BOWSER_ACT_HIT_EDGE)
        {
            o->oAction = 10;
            lb_rails_activate_switch();
        }
    }
    else if (10 == o->oAction)
    {
        if (0 == o->oTimer)
        {
            gMarioStates->vel[1] = 50.f;
            gMarioStates->forwardVel = -100.f;
        }

        if (50 == o->oTimer)
        {
            s16 angle = random_u16();
            for (int i = 0; i < 6; i++)
            {
                struct Object* tail = spawn_object(o, MODEL_LB_TAIL, bhvLBTail);
                tail->oLbTailRange = (i&1) ? 3200.f : 1800.f;
                tail->oLbTailFlipped = (i&1);
                tail->oOpacity = 0;
                tail->oLbTailSpeed = 0x60;
                tail->oLbTailTimeout = LB_PHASE5_LENGTH - 30;
                tail->oMoveAngleYaw = angle + 0x10000 / 6 * i + ((i&1) ? 0 : 0x8000);
                tail->oBehParams2ndByte = 1;
            }
            {
                struct Object* coins = spawn_object(o, MODEL_NONE, bhvCoinFormationLB);
                coins->oLbCoinPattern = (1 << 0)
                                      | (1 << 2)
                                      | (1 << 4)
                                      | (1 << 6)
                                      | (1 << 8)
                                      | (1 << 10);
                coins->oMoveAngleYaw = angle;
                coins->oLbCoinSpeed = 0x60;
                coins->oLbCoinTimeout = LB_PHASE5_LENGTH - 30;
            }
        }

        lb_tail_modify_sine();

        if (LB_PHASE5_LENGTH == o->oTimer)
        {
            o->oAction = 11;
        }
    }
    else if (11 == o->oAction)
    {
        s8* patterns = (u8*) &o->oLbCtlPattern;
        int timeMod = o->oTimer % 165;
        if (0 == timeMod)
        {
            int which1 = random_u16() % 5;
            int which2 = (which1 + 2 + (random_u16() & 1)) % 5;
            for (int i = 0; i < 5; i++)
            {
                patterns[i] = (i == which1 || i == which2) ? -1 : 1;
            }
        }

        lb_patterns(timeMod, 5);
        if (LB_PHASE6_LENGTH == o->oTimer)
        {
            o->oAction = 12;
            s16 angle = random_u16();
            lb_spawn_upp(0x50, angle);
            {
                struct Object* coins = spawn_object(o, MODEL_NONE, bhvCoinFormationLB);
                coins->oLbCoinPattern = 0;
                coins->oMoveAngleYaw = angle;
                coins->oLbCoinSpeed = 0x50;
                coins->oLbCoinTimeout = 50;
            }
        }
    }
    else if (12 == o->oAction)
    {
        if (o->oTimer < 2)
            o->parentObj->oAction = BOWSER_ACT_HIT_EDGE;

        if (o->parentObj->oAction != BOWSER_ACT_HIT_EDGE)
        {
            o->oAction = 13;
        }
    }
    else if (13 == o->oAction)
    {
        if (0 == o->oTimer)
        {
            gMarioStates->vel[1] = 50.f;
            gMarioStates->forwardVel = -100.f;
        }

        if (50 == o->oTimer)
        {
            s16 angle = random_u16();
            for (int i = 0; i < 2; i++)
            {
                struct Object* tail = spawn_object(o, MODEL_LB_TAIL, bhvLBTail);
                tail->oLbTailRange = (i&1) ? 3200.f : 1800.f;
                tail->oLbTailFlipped = (i&1);
                tail->oOpacity = 0;
                tail->oLbTailSpeed = 0x100;
                tail->oLbTailTimeout = LB_PHASE7_LENGTH - 30;
                tail->oMoveAngleYaw = angle + 0x10000 / 2 * i + ((i&1) ? 0 : 0x8000);
                tail->oBehParams2ndByte = 1;
            }
            {
                struct Object* coins = spawn_object(o, MODEL_NONE, bhvCoinFormationLB);
                coins->oLbCoinPattern = ~0;
                coins->oMoveAngleYaw = angle;
                coins->oLbCoinSpeed = 0;
                coins->oLbCoinTimeout = LB_PHASE7_LENGTH - 30;
            }
        }

        lb_tail_modify_sine();

        if (o->oTimer > 80)
        {
            s8* patterns = (u8*) &o->oLbCtlPattern;
            int timeMod = o->oTimer % 85;
            if (0 == timeMod)
            {
                for (int i = 0; i < 1; i++)
                {
                    patterns[i] = 1;
                }
            }

            lb_patterns(timeMod, 1);
        }

        if (LB_PHASE7_LENGTH == o->oTimer)
        {
            o->oAction = 14;
            lb_spawn_upp(0x70, random_u16());
        }
    }
    else if (14 == o->oAction)
    {
        if (o->oTimer < 2)
            o->parentObj->oAction = BOWSER_ACT_HIT_EDGE;

        if (o->parentObj->oAction != BOWSER_ACT_HIT_EDGE)
        {
            o->parentObj->oHealth = 1;
            o->oAction = 15;
        }
    }
    else if (15 == o->oAction)
    {
        if (o->oTimer < 50)
        {
            gMarioStates->pos[0] = 0;
            gMarioStates->pos[1] = 1400.f + o->oTimer * 32;
            gMarioStates->pos[2] = o->oTimer * 170;
            gMarioStates->vel[0] = 0;
            gMarioStates->vel[1] = 0;
            gMarioStates->vel[2] = 0;
            gMarioStates->faceAngle[1] = 0x8000;
            s8DirModeYawOffset = 0;
        }
        if (o->oTimer == 50)
        {
            struct Object* wind = spawn_object(o, MODEL_NONE, bhvLBWind);

            for (int i = 0; i < 3; i++)
            {
                int amount = 8 + 2*i;
                for (int j = 0; j < amount; j++)
                {
                    struct Object* bomb = spawn_object(o, MODEL_BOWSER_BOMB, bhvLbBowserBomb);
                    bomb->oLbPlatformRange = 2000.f + 2000.f * i;
                    bomb->oMoveAngleYaw = 0x10000 / amount * j;
                    bomb->oPosX = bomb->oLbPlatformRange * sins(bomb->oMoveAngleYaw);
                    bomb->oPosY = 2950.f;
                    bomb->oPosZ = bomb->oLbPlatformRange * coss(bomb->oMoveAngleYaw);
                    bomb->oLbPlatformSpeed = 0x10 * (i + 1) * (i&1 ? 1 : -1);
                    obj_scale(bomb, 0);
                }
            }
        }

        if (o->oTimer > 100)
        {
            if (o->parentObj->oAction == BOWSER_ACT_DEAD)
            {
                o->oAction = 16;
                o->parentObj->hitboxRadius = 100.f;
                o->parentObj->hitboxHeight = 300.f;
                seq_player_fade_out(SEQ_PLAYER_LEVEL, 1);
            }
        }
    }
    else if (16 == o->oAction)
    {
        gMarioStates->health = 0x880;
        if (o->oTimer < 40)
        {
            obj_scale(o->parentObj, 0.1f * (50 - o->oTimer));
            // o->parentObj->oPosX -= 60.f;
        }

        if (o->oTimer == 40)
        {
            gSecondCameraFocus = spawn_object(o, MODEL_STAR, bhvGrandStar);
            vec3_copy(&gSecondCameraFocus->oPosVec, &o->parentObj->oPosVec);
            gSecondCameraFocus->oBehParams2ndByte = 1;
        }

        if (gMarioStates->action == ACT_STAR_DANCE_EXIT)
        {
            o->oAction = 17;
        }
    }
    else if (17 == o->oAction)
    {
        Vec3f camDir;
        vec3_diff(camDir, gLakituState.goalPos, gLakituState.goalFocus);
        s16 camAngle = atan2s(camDir[2], camDir[0]);
        f32 r = sqrtf(camDir[2]*camDir[2] + camDir[0]*camDir[0]);
        camAngle = approach_angle(camAngle, 0, 0x200);
        gLakituState.goalPos[0] = gLakituState.goalFocus[0] + r * sins(camAngle);
        gLakituState.goalPos[2] = gLakituState.goalFocus[2] + r * coss(camAngle);
        gLakituState.yaw = camAngle;
        gLakituState.nextYaw = camAngle;

        if (o->oTimer == 60)
        {
            o->parentObj->oAction = BOWSER_ACT_CHARGE_MARIO;
        }

        f32 diffBowser[3];
        diffBowser[0] = o->parentObj->oPosX - gMarioStates->pos[0];
        diffBowser[1] = o->parentObj->oPosY - gMarioStates->pos[1];
        diffBowser[2] = o->parentObj->oPosZ - gMarioStates->pos[2];
        f32 distBowser = vec3_sumsq(diffBowser);
        if (distBowser < 400.f * 400.f)
        {
            gMarioStates->usedObj = o;
            SET_BPARAM2(o->oBehParams, 0xa);
            level_trigger_warp(gMarioStates, WARP_OP_TELEPORT);
            disable_background_sound();
        }
    }
}

static void bhv_lb_ball_common()
{
    if (0 == o->oLbZapHitTimer)
    {
        int canDamage = 1;
        o->oFaceAngleYaw += 0x280;
        o->oFaceAngleRoll += 0x146;

        if (o->oTimer <= 10)
        {
            o->oOpacity = 20 * o->oTimer;
            obj_scale(o, 0.1f * o->oTimer);
            canDamage = 0;
        }
        
        if (o->oTimer > 90)
        {
            o->oOpacity = 20 * (100 - o->oTimer);
            obj_scale(o, 0.1f * (100 - o->oTimer));
            canDamage = 0;
        }

        if (o->oTimer == 99)
        {
            o->activeFlags = 0;
        }

        if (canDamage)
        {
            Vec3f marioPos;
            vec3_copy(marioPos, gMarioStates->pos);
            marioPos[1] += 40.f;
            Vec3f diff;
            vec3_diff(diff, &o->oPosVec, marioPos);
            f32 len = vec3_sumsq(diff);
            if (len < 320.f * 320.f)
            {
                gMarioStates->health -= 0x100;
                o->oLbZapHitTimer = 1;
            }
        }
    }
    else
    {
        cur_obj_play_sound_1(SOUND_AIR_BOBOMB_LIT_FUSE);
        o->oOpacity = 20 * (5 - o->oLbZapHitTimer);
        obj_scale(o, 0.1f * (5 - o->oLbZapHitTimer));
        if (o->oLbZapHitTimer == 5)
        {
            o->activeFlags = 0;
        }
        o->oLbZapHitTimer++;
    }
}

void bhv_lb_ball_loop()
{
    obj_update_pos_vel_xz();
    return bhv_lb_ball_common();
}

void bhv_lb_ball_aim_loop()
{
    s32 angle = atan2s(gMarioObject->oPosZ, gMarioObject->oPosX);
    angle += o->oBehParams2ndByte;
    o->oPosX = o->oTimer * 50.f * sins(angle);
    o->oPosZ = o->oTimer * 50.f * coss(angle);

    return bhv_lb_ball_common();
}

void bhv_lb_tail_init()
{
    o->oDrawingDistance = 20000.f;
}

void bhv_lb_tail_loop()
{
    int amt = o->oLbTailTimeout;
    if (o->oTimer <= 64)
        o->oOpacity = CLAMP(o->oTimer * 4, 0, 255);
    if (o->oTimer > amt - 32)
        o->oOpacity = CLAMP((amt - o->oTimer) * 8, 0, 255);

    o->oMoveAngleYaw += o->oLbTailSpeed;
    int flipAngle = o->oLbTailFlipped ? 0x8000 : 0;
    f32 range = o->oLbTailRange;
    if (o->oBehParams2ndByte)
    {
        range += sins(gGlobalTimer * 0x223) * 300.f;
    }

    o->oPosX = range * coss(flipAngle - o->oMoveAngleYaw);
    o->oPosZ = range * sins(flipAngle - o->oMoveAngleYaw);

    if (255 == o->oOpacity)
        load_object_collision_model();
    
    if (amt == o->oTimer)
        o->activeFlags = 0;
}

void bhv_lb_rail_loop()
{
    if (o->oTimer <= 64)
        o->oOpacity = CLAMP(o->oTimer * 4, 0, 255);

    if (o->parentObj->oAction != 6
     && o->parentObj->oAction != 9)
    {
        o->oOpacity -= 4;
        if (o->oOpacity < 0)
        {
            o->oOpacity = 0;
            o->activeFlags = 0;
        }
    }
}

void bhv_lb_sparkle_loop()
{
    o->oTimer += o->oBehParams2ndByte;
    f32 xzScale = 0.5f + o->oTimer * 0.05f;
    f32 yscale = 3.f / xzScale / xzScale;
    obj_scale_xyz(o, xzScale * 0.5f, yscale * 0.5f, xzScale * 0.5f);
    if (o->oTimer < 32)
        o->oOpacity = o->oTimer * 200 / 32;

    if (o->oTimer > 200 - 32)
        o->oOpacity = (200 - o->oTimer) * 200 / 32;

    if (200 < o->oTimer)
        o->activeFlags = 0;
}

void bhv_lb_stand_loop()
{
    if (0 == o->oAction)
    {
        if (o->oTimer <= 64)
        {
            f32 scale = CLAMP(o->oTimer*2, 1, 100);
            obj_scale(o, scale / 64.f);
        }

        o->oMoveAngleYaw += o->oLbPlatformSpeed;
        f32 range = o->oLbPlatformRange;
        o->oPosX = range * sins(o->oMoveAngleYaw);
        o->oPosZ = range * coss(o->oMoveAngleYaw);

        if (gMarioObject->platform == o)
        {
            gMarioStates->pos[0] = o->oPosX;
            gMarioStates->pos[2] = o->oPosZ;
            if (o->oLbPlatformGrippedFrame < o->oTimer - 10)
            {
                gMarioStates->vel[0] = 0;
                gMarioStates->vel[1] = -1.f;
                gMarioStates->vel[2] = 0;
            }

            o->oLbPlatformGrippedFrame = o->oTimer;
        }

        if (o->parentObj->oAction != 12 && o->parentObj->oAction != 14)
        {
            o->oAction = 1;
        }
    }
    else
    {
        f32 scale = CLAMP(32 - o->oTimer, 1, 32);
        obj_scale(o, scale / 32.f);
        if (o->oTimer == 32)
        {
            o->activeFlags = 0;
        }
    }
}

void bhv_lb_wind_loop()
{
    if (o->parentObj->oAction == 16)
        o->activeFlags = 0;

    f32 d = gMarioStates->pos[0] * gMarioStates->pos[0] + gMarioStates->pos[2] * gMarioStates->pos[2];
    if (d < 700.f * 700.f)
        return;

    if (gMarioStates->health >= 0x100)
        load_object_collision_model();
}

void bhv_lb_bowser_bomb_loop()
{
    if (o->oTimer < 32)
    {
        obj_scale(o, (1 + o->oTimer) / 32.f);
    }

    f32 range = o->oLbPlatformRange;
    o->oMoveAngleYaw += o->oLbPlatformSpeed;
    o->oPosX = range * coss(o->oMoveAngleYaw);
    o->oPosZ = range * sins(o->oMoveAngleYaw);
    
    set_object_visibility(o, 30000);
}

extern void bhv_coin_formation_spawned_coin_loop(void);
void bhv_coin_formation_spawned_coin_loop_lb()
{
    f32 range = o->oLbCoinRange;
    o->oMoveAngleYaw += o->oLbCoinSpeed;
    o->oPosX = range * sins(o->oMoveAngleYaw);
    o->oPosZ = range * coss(o->oMoveAngleYaw);
    if (o->oTimer < 32)
    {
        o->oPosY += o->oVelY;
    }
    o->oFloorHeight = 100.f;

    int timeout = o->parentObj->oLbCoinTimeout - 30;
    if (o->oTimer > timeout)
    {
        o->oPosY += o->oTimer - timeout;
    }

    return bhv_coin_formation_spawned_coin_loop();
}

extern const BehaviorScript bhvYellowCoinSpawnedLB[];

static void spawn_lb_coin_pattern(int mask, int amount, f32 range, f32 vel)
{
    for (int i = 0; i < amount; i++)
    {
        if (!(mask & (1 << i)))
            continue;

        struct Object *newCoin = spawn_object(o, MODEL_YELLOW_COIN, bhvYellowCoinSpawnedLB);
        int angle = o->oMoveAngleYaw + 0x10000/amount * i;
        newCoin->oMoveAngleYaw = angle;
        newCoin->oPosX = range * sins(angle);
        newCoin->oPosY = 0;
        newCoin->oPosZ = range * coss(angle);
        newCoin->oVelY = vel;

        newCoin->oLbCoinSpeed = o->oLbCoinSpeed;
        newCoin->oLbCoinRange = range;
    }
}

void bhv_coin_formation_init_lb()
{
    int mask = o->oLbCoinPattern;
    if (0 == mask)
    {
        spawn_lb_coin_pattern(~0, 8, 1300.f, 13.f);
    }
    else
    {
        spawn_lb_coin_pattern(mask, 12, 2500.f, 4.f);
    }
}

void bhv_coin_formation_loop_lb()
{
    if (o->parentObj->oAction == 12)
    {
        o->oLbCoinTimeout++;
    }

    if (o->oTimer == o->oLbCoinTimeout)
    {
        o->oAction = COIN_FORMATION_ACT_DEACTIVATE;
    }

    if (o->oTimer == o->oLbCoinTimeout + 1)
    {
        o->activeFlags = 0;
    }
}
