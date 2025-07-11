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
        o->oOpacity = bowser->oOpacity = opacity;
        
        if (gMarioStates->pos[0] < -600.f)
            gMarioStates->pos[0] = -600.f;
    }
}
