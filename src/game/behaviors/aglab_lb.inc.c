void bhv_lb_ctl_init()
{
    f32 d;
    o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvBowser, &d);
    gSecondCameraFocus = spawn_object(o, MODEL_STAR, bhvGrandStar);
    gSecondCameraFocus->oPosX = 0;
    gSecondCameraFocus->oPosY = 1050;
    gSecondCameraFocus->oPosZ = -10000;
}

static void lb_pin_bowser()
{
    o->parentObj->oPosX = 0;
    o->parentObj->oPosY = 0;
    o->parentObj->oPosZ = 0;

    if (o->parentObj->oAction != BOWSER_ACT_WALK_TO_MARIO)
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

static void lb_tail_modify()
{
    f32 amount = sins(o->oTimer * 0x163) * 0.00015f;
    lb_vtx_modify(amount, ARRAY_COUNT(lb_tail_tail_mesh_layer_1_vtx_0), lb_tail_tail_mesh_layer_1_vtx_0_COPY, lb_tail_tail_mesh_layer_1_vtx_0);
    lb_vtx_modify(amount, ARRAY_COUNT(lb_tail_tail_mesh_layer_1_vtx_1), lb_tail_tail_mesh_layer_1_vtx_1_COPY, lb_tail_tail_mesh_layer_1_vtx_1);
    lb_vtx_modify(amount, ARRAY_COUNT(lb_tail_tail_mesh_layer_1_vtx_2), lb_tail_tail_mesh_layer_1_vtx_2_COPY, lb_tail_tail_mesh_layer_1_vtx_2);

    lb_coll_modify(amount);
}

#define LB_PHASE0_LENGTH 40
#define LB_PHASE1_LENGTH 300
#define LB_PHASE2_LENGTH 300

extern void set_camera_mode_8_directions(struct Camera *c);
extern void func_8031D690(s32 player, s32 fadeInTime);
void bhv_lb_ctl_loop()
{
    lb_tail_modify();

#if 0
    if (0 == o->oTimer)
    {
        struct Object* tail = spawn_object(o, MODEL_LB_TAIL, bhvLBTail);
        tail->oOpacity = 255;
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
            o->parentObj->hitboxHeight = 1500.f;

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
            o->oAction = 4;
        }
    }
    else if (4 == o->oAction)
    {
        if (0 == o->oTimer)
        {
            for (int i = 0; i < 4; i++)
            {
                struct Object* tail = spawn_object(o, MODEL_LB_TAIL, bhvLBTail);
                tail->oOpacity = 0;
                tail->oMoveAngleYaw = 0x4000 * i;
            }
        }

        if (LB_PHASE1_LENGTH == o->oTimer)
        {
            o->oAction = 5;
        }
    }
    else if (5 == o->oAction)
    {
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
        }
    }
    else if (6 == o->oAction)
    {
    }
    else
    {
    }

    if (o->oAction >= 3)
        lb_pin();
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
    if (o->oTimer <= 64)
        o->oOpacity = CLAMP(o->oTimer * 4, 0, 255);
    if (o->oTimer > LB_PHASE1_LENGTH - 32)
        o->oOpacity = CLAMP((LB_PHASE1_LENGTH - o->oTimer) * 8, 0, 255);

    o->oMoveAngleYaw += 0x100;
    o->oPosX = 1800.f * coss(-o->oMoveAngleYaw);
    o->oPosZ = 1800.f * sins(-o->oMoveAngleYaw);

    if (255 == o->oOpacity)
        load_object_collision_model();
}
