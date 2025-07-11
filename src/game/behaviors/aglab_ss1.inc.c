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

#define oSSCtlSpecial oObjF4
#define oSSCtlLastRadius oFloatF8

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
            o->oSSCtlLastRadius = 2000.f + 500.f * sins(o->oTimer * 223);

        f32 r = o->oSSCtlLastRadius;
        f32 x = 2000.f + r * coss(o->oTimer * 323);
        f32 z =    0.f + r * sins(o->oTimer * 323);

        bowser->oOpacity = o->oSubAction ? 255 : 0;
        bowser->oPosX = x;
        bowser->oPosY = 0.f;
        bowser->oPosZ = z;
        bowser->oMoveAngleYaw = -o->oTimer * 323;

        if (gMarioStates->action == ACT_GROUND_POUND || gMarioStates->action == ACT_GROUND_POUND_LAND)
        {
            f32 dx = gMarioStates->pos[0] - bowser->oPosX;
            f32 dz = gMarioStates->pos[2] - bowser->oPosZ;
            f32 d = dx * dx + dz * dz;
            if (d < 60000.f)
            {
                o->oTimer--;
                obj_scale(bowser, 1.4f + 0.1f * sins(gGlobalTimer * 11234));
                if (gMarioStates->action == ACT_GROUND_POUND_LAND)
                {
                    bowser->oInteractStatus = INT_STATUS_NONE;
                    obj_scale(bowser, 1.f);
                    bowser->oAction = 7; // run
                    bowser->oTimer = 0;
                    o->oSubAction = 1;
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
        if (3 == bowser->oAction)
        {
            o->oAction = 5;
        }
    }
    else if (5 == o->oAction)
    {
        bowser->oPosX = 0;
        bowser->oPosY = 0;
        bowser->oPosZ = 0;

        
    }
}
