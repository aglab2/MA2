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

void bhv_ss_ctl_loop()
{
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
            cur_obj_hide();
            obj_hide(bowser);
        }
    }
}
