static void obj_unhide(struct Object *obj) {
    obj->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
}

static void obj_hide(struct Object *obj) {
    obj->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
}

void bhv_ss_ctl_init()
{
    f32 d;
    o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvBowser, &d);
    o->oOpacity = 255;
}

extern const Collision ss1_space_collision[];
extern const Collision ss1_boo_collision[];
extern const Collision ss1_fly_collision[];
extern const Collision ss1_golem_collision[];

#define oSSCtlSpecial oObjF4
#define oSSCtlLastRadius oFloatF8
#define oSSCtlInitAngle oFC
#define oSSCtlAwaitTiming o100

extern s16 s8DirModeYawOffset;

extern const BehaviorScript bhvSS1Golem[];
extern s32 approach_f32_ptr(f32 *px, f32 target, f32 delta);
void bhv_ss_ctl_loop()
{
    o->oCollisionDistance = 30000.0f;
    struct Object* bowser = o->parentObj;
    if (0 == o->oAction)
    {
        if (bowser->oHealth == 6)
        {
            o->oAction = 1;
        }
        o->oSSCtlAwaitTiming = 0;
    }
    else if (1 == o->oAction)
    {
        int opacity = 255 - 4 * o->oTimer;
        if (opacity < 0)
        {
            opacity = 0;
        }

        o->oOpacity = bowser->oOpacity = opacity;
        if (0 == opacity)
        {
            obj_set_collision_data(o, ss1_boo_collision);
            obj_set_model(o, MODEL_SS1_BOO);
            o->oAction = 2;
            gMarioStates->pos[0] = 600.f;
            gMarioStates->pos[2] = 0.f;
        }
    }
    else if (2 == o->oAction)
    {
        aglabGlobalScratch[0] = 1;
        int opacity = 8 * o->oTimer;
        if (opacity > 255)
        {
            opacity = 255;
        }
        o->oOpacity = opacity;
        bowser->oOpacity = 0; 
        
        if (gMarioStates->pos[0] < -600.f)
            gMarioStates->pos[0] = -600.f;

        if (255 == opacity)
        {
            o->oAction = 3;
            obj_scale(bowser, 1.5f);
        }
    }
    else if (3 == o->oAction)
    {
        // move bowser around the center which is at (2000, 0, 0)
        if (!o->oSubAction)
        {
            o->oSSCtlLastRadius = 2000.f + 500.f * sins(o->oTimer * 223);
        }
        else
        {
            approach_f32_ptr(&o->oSSCtlLastRadius, 2000.f, 10.f); 
        }

        f32 r = o->oSSCtlLastRadius;
        f32 x = 2000.f - r * coss(o->oTimer * 323);
        f32 z =    0.f - r * sins(o->oTimer * 323);

        bowser->oOpacity = o->oSubAction ? 255 : 0;
        bowser->oPosX = x;
        bowser->oPosY = 0.f;
        bowser->oPosZ = z;
        bowser->oMoveAngleYaw = 0x8000-o->oTimer * 323;

        // if (gMarioStates->action == ACT_GROUND_POUND || gMarioStates->action == ACT_GROUND_POUND_LAND)
        // {
        // }

        if (0 == o->oSubAction)
        {
            f32 dx = gMarioStates->pos[0] - bowser->oPosX;
            f32 dz = gMarioStates->pos[2] - bowser->oPosZ;
            f32 d = dx * dx + dz * dz;
            o->oSSCtlAwaitTiming++;
            if (d < 60000.f)
            {
                if (o->oSSCtlAwaitTiming < 100)
                {
                    o->oTimer--;
                    obj_scale(bowser, 1.4f + 0.1f * sins(gGlobalTimer * 11234));
                }
                else
                {
                    o->oSSCtlAwaitTiming = 100;
                }

                if (gMarioStates->action == ACT_GROUND_POUND_LAND)
                {
                    bowser->oInteractStatus = INT_STATUS_NONE;
                    obj_scale(bowser, 1.f);
                    bowser->oAction = 7; // run
                    bowser->oTimer = 0;
                    o->oSubAction = 1;
                }
            }
            else
            {
                o->oSSCtlAwaitTiming -= 5;
                if (o->oSSCtlAwaitTiming < 0)
                {
                    o->oSSCtlAwaitTiming = 0;
                }
            }
        }

        if (16 == bowser->oAction)
        {
            o->oAction = 4;
        }
    }
    else if (4 == o->oAction)
    {
        bowser->oInteractStatus = -1;
        if (3 == bowser->oAction)
        {
            o->oAction = 5;
            o->oSSCtlSpecial = spawn_object(o, MODEL_SS1_SHADOW, bhvStaticObject);
            o->oSSCtlSpecial->oPosX = 0;
            o->oSSCtlSpecial->oPosY = 0;
            o->oSSCtlSpecial->oPosZ = 0;
            o->oSSCtlInitAngle = atan2s(gMarioStates->pos[2], gMarioStates->pos[0]);
            o->oSSCtlAwaitTiming = 0;
            bowser->oInteractStatus = 0;
        }
    }
    else if (5 == o->oAction)
    {
        f32 spd = o->oSubAction ? 223 : 123;
        f32 r = 1400.f;
        f32 x = 2000.f + r * sins(o->oSSCtlInitAngle + o->oTimer * spd);
        f32 y = 500.f + 200.f * sins(o->oTimer * 523);
        f32 z =    0.f + r * coss(o->oSSCtlInitAngle + o->oTimer * spd);

        if (0 == o->oSubAction)
        {
            bowser->oPosX = 2000.f;
            bowser->oPosY = 0;
            bowser->oPosZ = 0;
            bowser->oOpacity = 0;

            o->oSSCtlSpecial->oPosX = x;
            o->oSSCtlSpecial->oPosY = y;
            o->oSSCtlSpecial->oPosZ = z;
            o->oSSCtlSpecial->oFaceAngleYaw = o->oSSCtlInitAngle + o->oTimer * 123 + 0x4000;
            o->oSSCtlSpecial->oFaceAnglePitch = 0;
            o->oSSCtlSpecial->oFaceAngleRoll = 0; 

            o->oSSCtlAwaitTiming++;
            f32 dx = gMarioStates->pos[0] - o->oSSCtlSpecial->oPosX;
            f32 dy = gMarioStates->pos[1] - o->oSSCtlSpecial->oPosY;
            f32 dz = gMarioStates->pos[2] - o->oSSCtlSpecial->oPosZ;
            f32 d = dx * dx + dy * dy + dz * dz;
            if (d < 60000.f)
            {
                if (gMarioStates->action == ACT_JUMP_KICK || gMarioStates->action == ACT_MOVE_PUNCHING)
                {
                    bowser->oInteractStatus = INT_STATUS_NONE;
                    bowser->oAction = 7; // run
                    bowser->oTimer = 0;
                    bowser->oPosX = x * 1.1f;
                    bowser->oPosY = y;
                    bowser->oPosZ = z * 1.1f;
                    bowser->oOpacity = 255;
                    o->oSSCtlInitAngle = o->oSSCtlInitAngle + o->oTimer * 123;
                    o->oTimer = 0;
                    o->oSubAction = 1;
                    obj_set_model(o->oSSCtlSpecial, MODEL_SS1_BOO_BOO);
                    o->oSSCtlSpecial->oPosX = 2000.f;
                    o->oSSCtlSpecial->oPosY = -800.f;
                    o->oSSCtlSpecial->oPosZ = 0;
                    o->oSSCtlSpecial->oOpacity = 0;
                    o->oSSCtlSpecial->oFaceAngleRoll = 0x4000;
                    o->oSSCtlSpecial->oFaceAnglePitch = 0x4000;
                    obj_scale(o->oSSCtlSpecial, 1.5f);
                }
                else
                {
                    if (o->oSSCtlAwaitTiming < 100)
                    {
                        o->oTimer--;
                        obj_scale(o->oSSCtlSpecial, 1.f + 0.1f * sins(gGlobalTimer * 11234));
                    }
                    else
                    {
                        o->oSSCtlAwaitTiming = 100;
                    }
                }
            }
            else
            {
                obj_scale(o->oSSCtlSpecial, 1.f);
                o->oSSCtlAwaitTiming -= 5;
                if (o->oSSCtlAwaitTiming < 0)
                {
                    o->oSSCtlAwaitTiming = 0;
                }
            }
        }
        else
        {
            bowser->oPosX = x * 1.1f;
            bowser->oPosZ = z * 1.1f;
            bowser->oMoveAngleYaw = o->oSSCtlInitAngle + o->oTimer * 223 + 0x4000;
            if (16 == bowser->oAction)
            {
                o->oAction = 6;
            }
        }
    }
    else if (6 == o->oAction)
    {
        if (3 == bowser->oAction)
        {
            o->oAction = 7;
        }
    }
    else if (7 == o->oAction)
    {
        bowser->oInteractStatus = -1;
        f32 dx = gMarioStates->pos[0] - 2000.f;
        f32 dz = gMarioStates->pos[2];

        int opacity = 255 - 8 * o->oTimer;
        if (opacity < 0)
        {
            opacity = 0;
        }

        o->oOpacity = bowser->oOpacity = opacity;
        o->oSSCtlSpecial->oOpacity = 255 - 5 * o->oTimer;
        o->oSSCtlSpecial->oFaceAngleYaw = 0x8000 + atan2s(dz, dx);

        if (0 == o->oSSCtlSpecial->oOpacity)
        {
            o->oAction = 8;
            obj_set_model(o, MODEL_SS1_FLY);
            bowser->oAction = 8; // spit fire in the air
            bowser->oMoveAngleYaw = -0x4000;
            o->oSSCtlSpecial->activeFlags = 0;
            obj_set_collision_data(o, ss1_fly_collision);
            s8DirModeYawOffset = -0x4000;
        }
    }
    else if (8 == o->oAction)
    {
        int opacity = 8*o->oTimer;
        if (opacity > 255)
        {
            opacity = 255;
        }

        bowser->oOpacity = o->oOpacity = opacity;
        bowser->oPosX = 1000.f;
        bowser->oPosY = 0;
        bowser->oPosZ = 0;
        bowser->oInteractStatus = 0;

        gMarioStates->pos[0] = -1000.f;
        gMarioStates->pos[1] = 0;
        gMarioStates->pos[2] = 0;

        if (255 == opacity)
        {
            o->oAction = 9;
        }
    }
    else if (9 == o->oAction)
    {
        if (BOWSER_ACT_HIT_MINE == bowser->oAction)
        {
            if (0 == o->oSubAction)
            {
                o->oTimer = 0;
                o->oSubAction = 1;
            }

            bowser->oOpacity -= 10;
            if (bowser->oOpacity < 0)
            {
                bowser->oOpacity = 0;
                bowser->oPosX = 0;
                bowser->oPosY = 700.f;
                bowser->oPosZ = 0;
            }
        }

        if (o->oTimer == 40 && o->oSubAction)
        {
            bowser->oAction = BOWSER_ACT_CHARGE_MARIO;
            o->oAction = 10;
        }
    }
    else if (10 == o->oAction)
    {
        bowser->oOpacity = 255;
        bowser->oPosX = 0;
        bowser->oPosY = 700.f;
        bowser->oPosZ = 800.f * sins(gGlobalTimer * 234);
        bowser->oMoveAngleYaw = 0x8000 * (coss(gGlobalTimer * 234) < 0);
        if (bowser->oAction != BOWSER_ACT_CHARGE_MARIO)
        {
            o->oAction = 11;
            bowser->oInteractStatus = -1;
        }
    }
    else if (11 == o->oAction)
    {
        int opacity = 255 - 8 * o->oTimer;
        if (opacity < 0)
        {
            opacity = 0;
        }
        
        o->oOpacity = bowser->oOpacity = opacity;
        if (0 == opacity)
        {
            obj_set_model(o, MODEL_SS1_GOLEM);
            bowser->oAction = BOWSER_ACT_DEFAULT;
            bowser->oMoveAngleYaw = 0x8000;
            bowser->oInteractStatus = 0;
            bowser->oPosX = 0.9f * 16.f;
            bowser->oPosY = 0.9f * -3.f;
            bowser->oPosZ = 0.9f * 1974.f;
            obj_set_collision_data(o, ss1_golem_collision);
            s8DirModeYawOffset = 0x8000;
            o->oAction = 12;
            load_object_static_model();
        }
        else
        {
            load_object_collision_model();
        }
    }
    else if (12 == o->oAction)
    {
        int opacity = 8*o->oTimer;
        if (opacity > 255)
        {
            opacity = 255;
        }

        bowser->oOpacity = o->oOpacity = opacity;

        gMarioStates->pos[0] = 0.9f * -43.f;
        gMarioStates->pos[1] = 0.9f * 176.f;
        gMarioStates->pos[2] = 0.9f * -2016.f;

        if (opacity == 255)
        {
            o->oAction = 13;
        }
    }
    else if (13 == o->oAction)
    {
        if (BOWSER_ACT_HIT_MINE == bowser->oAction)
        {
            gMarioStates->pos[0] = 0.9f * 16.f;
            gMarioStates->pos[1] = 0.9f * -3.f;
            gMarioStates->pos[2] = 0.9f * 1974.f;

            if (0 == o->oSubAction)
            {
                o->oTimer = 0;
                o->oSubAction = 1;
                o->oSSCtlSpecial = spawn_object(o, MODEL_SS1_GOLEM_GEO, bhvSS1Golem);
                o->oSSCtlSpecial->oPosY = -1400.f;
                // o->oSSCtlSpecial->oFaceAngleYaw = 0x8000;
            }

            bowser->oOpacity -= 10;
            if (bowser->oOpacity < 0)
            {
                bowser->oOpacity = 0;
                bowser->oPosX = 0;
                bowser->oPosY = 2500.f;
                bowser->oPosZ = 0;
                bowser->oAction = BOWSER_ACT_DANCE;
                o->oAction = 14;
            }
            o->oSSCtlSpecial->oOpacity = 255 - bowser->oOpacity;
        }
    }
    else
    {
        bowser->oOpacity = 255;
        bowser->oPosX = 0;
        bowser->oPosZ = 0;
    }

    if (o->oAction <= 10)
        load_object_collision_model();

    print_text_fmt_int(20, 20, "A %d", bowser->oHealth);
}
