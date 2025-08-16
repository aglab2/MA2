#define oIgShelfFlags oF8

Gfx *geo_ig_update(s32 callContext, struct GraphNode *node, UNUSED void *context)
{
    Gfx* result = NULL;
    struct GraphNodeGenerated *graphNode = (struct GraphNodeGenerated *) node;
    int param = graphNode->parameter;
    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        int flags = obj->oIgShelfFlags;
        int disabled = param & flags;

        Gfx* gfx = alloc_display_list(2 * sizeof(Gfx));
        result = gfx;
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, disabled ? 0 : 200);
        gSPEndDisplayList(gfx);
    }
    else
    {
        SET_GRAPH_NODE_LAYER(node->flags, param & 0x7f);
    }

    return result;
}

struct IgLoc
{
    f32 x, z;
};

struct IgLoc2
{
    Vec3f pos;
};

#if 1
extern const BehaviorScript bhvTest[];
static void IG_spawn_test_particle(struct Object* part, f32 x, f32 y, f32 z)
{
    struct Object* p = spawn_object(part, MODEL_STAR, bhvTest);
    p->oPosX = x;
    p->oPosY = y + 10.f;
    p->oPosZ = z;
}
#else
static void IG_spawn_test_particle(struct Object* part, f32 x, f32 y, f32 z)
{
    // -- 
}
#endif

void bhv_test_loop()
{
    if (o->oTimer)
    {
        o->activeFlags = 0;
    }
}

void bhv_ig_shelf_loop()
{
    if (0 == o->oAction)
    {
        load_object_collision_model();

        struct IgLoc locs[] = {
            { -160, 100 },
            {  160, 100 },
        };

        for (int i = 0; i < 2; i++)
        {
            struct IgLoc* loc = &locs[i];
            int x = loc->x;
            int z = loc->z;
            loc->x = x * coss( o->oFaceAngleYaw) + z * sins( o->oFaceAngleYaw);
            loc->z = x * sins(-o->oFaceAngleYaw) + z * coss( o->oFaceAngleYaw);
        }

        struct IgLoc2 locs2[] = {
            { locs[0].x, 0, locs[0].z },
            { locs[1].x, 0, locs[1].z },
            { locs[0].x, 360, locs[0].z },
            { locs[1].x, 360, locs[1].z },
        };

        for (int i = 0; i < 4; i++)
        {
            struct IgLoc2* loc = &locs2[i];
            Vec3f opos;
            vec3_sum(opos, loc->pos, &o->oPosVec);
            Vec3f d;
            vec3_diff(d, opos, &gMarioObject->oPosVec);

            IG_spawn_test_particle(o, opos[0], opos[1], opos[2]);

            f32 l = vec3_mag(d);

            if (l < 100.f)
            {
                int flag = 1 << (8 + i);
                if (!(o->oIgShelfFlags & flag))
                {
                    cur_obj_play_sound_2(SOUND_GENERAL2_ROTATING_BLOCK_CLICK);
                    o->oIgShelfFlags |= flag;
                }
            }
        }

        if (0xf00 == (o->oIgShelfFlags & 0xf00))
        {
            o->oVelY = 20.f;
            o->oForwardVel = -30.f;
            o->oAction = 1;
            cur_obj_play_sound_2(SOUND_OBJ_BULLY_EXPLODE_UNUSED);
        }
    }
    else
    {
        o->oVelY -= 1;
        o->oFaceAnglePitch += 0x200;
        o->oPosY += o->oVelY;
        obj_update_pos_vel_xz();
    }
}
