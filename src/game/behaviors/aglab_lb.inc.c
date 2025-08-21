#include "rail_desc.h"

#define oLbTailRange oFloatF4
#define oLbTailFlipped oF8
#define oLbTailSpeed oFC
#define oLbTailTimeout o100

#define oLbSparkle oObjF4

void bhv_lb_ctl_init()
{
    f32 d;
    o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvBowser, &d);
    o->oLbSparkle = spawn_object(o, MODEL_LB_SPARKLE, bhvStaticObject);
    o->oLbSparkle->oOpacity = 0;
    o->oLbSparkle->oPosY -= 50.f;
#if 1
    gSecondCameraFocus = spawn_object(o, MODEL_STAR, bhvGrandStar);
    gSecondCameraFocus->oPosX = 0;
    gSecondCameraFocus->oPosY = 1050;
    gSecondCameraFocus->oPosZ = -10000;
#endif
}

static void lb_pin_bowser()
{
    o->parentObj->oPosX = 0;
    o->parentObj->oPosY = 0;
    o->parentObj->oPosZ = 0;

    if (o->parentObj->oAction != BOWSER_ACT_WALK_TO_MARIO
     && o->parentObj->oAction != BOWSER_ACT_HIT_MINE
     && o->parentObj->oAction != BOWSER_ACT_HIT_EDGE)
    {
        s32 angleToMario = obj_angle_to_object(o->parentObj, gMarioObject);
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
    s32 angleToMario = obj_angle_to_object(o->parentObj, gMarioObject);
    for (int i = 0; i < 4; i++)
    {
        struct Object* rail = spawn_object(o, MODEL_LB_RAIL, bhvLBRail);
        rail->oFaceAngleYaw = angleToMario + 0x10000 / 4 * i;
        lb_traj_rotate(i, rail->oFaceAngleYaw);
    }
    lb_rails_activate_switch();
}

#define LB_PHASE0_LENGTH 40
#define LB_PHASE1_LENGTH 300
#define LB_PHASE2_LENGTH 300
#define LB_PHASE3_LENGTH 500

extern void set_camera_mode_8_directions(struct Camera *c);
extern void func_8031D690(s32 player, s32 fadeInTime);
void bhv_lb_ctl_loop()
{
    if (o->oAction >= 3)
        lb_pin();

#if 0
    if (0 == o->oTimer)
        lb_spawn_rails();
#endif

#if 1
    if (0 == o->oTimer && o->oAction == 0)
    {
        seq_player_play_sequence(0, 0x48, 0);
        func_8031D690(0, 60);
        o->oAction = 8;
        return;
    }
#endif

    if (0 == o->oAction)
    {
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
            gSecondCameraFocus->oPosY = 0;
            cur_obj_play_sound_2(SOUND_OBJ_BOWSER_LAUGH);
            o->oAction = 1;

            seq_player_play_sequence(0, 0x48, 0);
            func_8031D690(0, 60);
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

            s8DirModeYawOffset = 0x8000;
   
            set_mario_action(gMarioStates, ACT_THROWN_BACKWARD, 0);

            o->oAction = 2;
        }
    }
    else if (2 == o->oAction)
    {
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
            for (int i = 0; i < 3; i++)
            {
                struct Object* tail = spawn_object(o, MODEL_LB_TAIL, bhvLBTail);
                tail->oLbTailRange = 1800.f;
                tail->oOpacity = 0;
                tail->oLbTailSpeed = 0x100;
                tail->oLbTailTimeout = LB_PHASE1_LENGTH;
                tail->oMoveAngleYaw = 0x10000 / 3 * i;
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
        }
    }
    else if (5 == o->oAction)
    {
        f32 val = coss(o->oTimer * 0x10000 / 80);
        val *= val;
        val *= 500.f;
        val -= 200.f;
        if (val > 220.f)
            val = 220.f;
        if (val < 0.f)
            val = 0.f;

        o->oLbSparkle->oOpacity = val + 32;
        if (0 == (o->oTimer % 40))
        {
            for (int i = 0; i < 6; i++)
            {
                s32 angleToMario = obj_angle_to_object(o->parentObj, gMarioObject);
                struct Object* ball = spawn_object(o, MODEL_LB_BALL, bhvLBBall);
                ball->oForwardVel = 50.f;
                ball->oMoveAngleYaw = angleToMario + 0x10000 / 6 * i;
                ball->oFaceAngleYaw = random_u16();
                ball->oFaceAngleRoll = random_u16();
                obj_scale(ball, 0.1f);
            }
        }
        
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
            
            for (int i = 0; i < 4; i++)
            {
                struct Object* tail = spawn_object(o, MODEL_LB_TAIL, bhvLBTail);
                tail->oLbTailRange = (i&1) ? 3200.f : 1800.f;
                tail->oLbTailFlipped = (i&1);
                tail->oOpacity = 0;
                tail->oLbTailSpeed = 0x90;
                tail->oLbTailTimeout = LB_PHASE3_LENGTH;
                tail->oMoveAngleYaw = 0x10000 / 4 * i + ((i&1) ? 0 : 0x8000);
                tail->oBehParams2ndByte = 1;
            }
        }

#if 0
        int amt = o->oTimer % 64;
        if (amt < 50)
            lb_tail_modify_by(amt / 40.f);
        else
            lb_tail_modify_by((63 - amt) / 12.f * 1.2f);
#endif
        lb_tail_modify_sine();

        if (LB_PHASE3_LENGTH == o->oTimer)
        {
            o->oAction = 8;
        }
    }
    else if (8 == o->oAction)
    {
        o->oLbSparkle->oOpacity = sins(o->oTimer * 0x263) * sins(o->oTimer * 0x263) * 220 + 32;
    }
    else
    {
    }
}

void bhv_lb_ball_loop()
{
    o->oFaceAngleYaw += 0x280;
    o->oFaceAngleRoll += 0x146;
    obj_update_pos_vel_xz();

    if (o->oTimer <= 10)
    {
        o->oOpacity = 20 * o->oTimer;
        obj_scale(o, 0.1f * o->oTimer);
    }
    
    if (o->oTimer > 90)
    {
        o->oOpacity = 20 * (100 - o->oTimer);
        obj_scale(o, 0.1f * (100 - o->oTimer));
    }

    if (o->oTimer == 99)
    {
        obj_mark_for_deletion(o);
    }
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
#if 0
    if (o->oBehParams2ndByte == 1)
    {
        int amt = o->oTimer % 64;
        int speed = 0;
        if (amt < 50)
            speed = 50 - amt;
        else
            speed = -0x140;

        if (o->oLbTailFlipped)
            speed = -speed;

        o->oMoveAngleYaw += speed;
    }
    else
    {
        o->oMoveAngleYaw += 0x100;
    }
#endif

    int flipAngle = o->oLbTailFlipped ? 0x8000 : 0;
    o->oPosX = o->oLbTailRange * coss(flipAngle - o->oMoveAngleYaw);
    o->oPosZ = o->oLbTailRange * sins(flipAngle - o->oMoveAngleYaw);

    if (255 == o->oOpacity)
        load_object_collision_model();
    
    if (amt == o->oTimer)
        o->activeFlags = 0;
}

void bhv_lb_rail_loop()
{
    if (o->oTimer <= 64)
        o->oOpacity = CLAMP(o->oTimer * 4, 0, 255);

    if (o->parentObj->oAction != 6)
    {
        o->oOpacity -= 4;
        if (o->oOpacity < 0)
        {
            o->oOpacity = 0;
            o->activeFlags = 0;
        }
    }
}
