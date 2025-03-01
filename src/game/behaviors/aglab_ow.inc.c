#define OW_LEVEL_COUNT 15

extern const Trajectory* sTrajectory;
extern const s16* sSpringBezier;

extern const BehaviorScript bhvOwVisual[];
extern const BehaviorScript bhvOwLock[];
extern const BehaviorScript bhvOwNumber[];

const int gLevelWithHardModes = 1 << (LEVEL_CE - LEVEL_CE)
                              | 1 << (LEVEL_PL - LEVEL_CE)
                              | 1 << (LEVEL_MH - LEVEL_CE)
                              | 1 << (LEVEL_GF - LEVEL_CE)
                              | 1 << (LEVEL_MS - LEVEL_CE)
                              | 1 << (LEVEL_HB - LEVEL_CE)
                              | 1 << (LEVEL_PC - LEVEL_CE)
                              | 1 << (LEVEL_EE - LEVEL_CE)
                              | 1 << (LEVEL_CG - LEVEL_CE)
                              | 1 << (LEVEL_FR - LEVEL_CE)
                              ;

extern u8 gIsHardMode;
void bhv_ow_ctl_init()
{
    int off = 0x80;
    for (int i = 0; i < OW_LEVEL_COUNT; i++)
    {
        int withExtraMode = gLevelWithHardModes & (1 << i);

        {
            struct Object* obj = spawn_object(o, MODEL_OW_CE + i, bhvOwVisual);
            obj->oPosX = -585.f;
            obj->oPosY = 0.f;
            obj->oPosZ = 7238.f - 1000.f * i;
        }
        {
            struct Object* obj = spawn_object(o, MODEL_OW_LOCK, bhvOwLock);
            obj->oPosX = -585.f;
            obj->oPosY = 0.f;
            obj->oPosZ = 7238.f - 1000.f * i - 600.f;
            if (!withExtraMode)
            {
                obj->oBehParams2ndByte = off++;
                SET_BPARAM1(obj->oBehParams, 0);
            }
            else
            {
                obj->oBehParams2ndByte = i;
                SET_BPARAM1(obj->oBehParams, 0);
            }
        }
#if 0
        if (withExtraMode)
        {
            struct Object* obj = spawn_object(o, MODEL_OW_LOCK, bhvOwLock);
            obj->oPosX = -585.f - 400.f;
            obj->oPosY = 0.f;
            obj->oPosZ = 7238.f - 1000.f * i;
            obj->oFaceAngleYaw = 0x4000;
            obj->oBehParams2ndByte = i;
            SET_BPARAM1(obj->oBehParams, 1);
        }
#endif
    }

    sSpringBezier = NULL;
    sTrajectory = NULL;
#if 0
    gIsHardMode = 0;

    level_control_timer(TIMER_CONTROL_STOP);
    level_control_timer(TIMER_CONTROL_HIDE);
#endif
}

void bhv_ow_ctl_loop()
{
}

static void hide_if_invisible()
{
    if (0 == o->oOpacity)
    {
        o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
    }
    else
    {
        o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
    }
}

void bhv_ow_visual_loop()
{
    f32 diff = gMarioStates->pos[2] - o->oPosZ;
    if (absf(diff) > 400)
    {
        if (o->oOpacity > 0)
        {
            o->oOpacity -= 17;
        }
    }
    else
    {
        if (o->oOpacity < 255)
        {
            o->oOpacity += 17;
        }
    }

    hide_if_invisible();
}

void bhv_ow_lock_loop()
{
    bhv_ow_visual_loop();
    if (0 == o->oTimer)
    {
        if (0x80 & o->oBehParams2ndByte)
        {
            int starRequirement = 0;
            switch(o->oBehParams2ndByte)
            {
                case 0x80:
                    starRequirement = 10;
                    break;
                case 0x81:
                    starRequirement = 30;
                    break;
                case 0x82:
                    starRequirement = 60;
                    break;
                case 0x83:
                    starRequirement = 100;
                    break;
                case 0x84:
                    starRequirement = 150;
                    break;
            }

            if (gMarioStates->numStars >= starRequirement)
            {
                o->activeFlags = 0;
            }
            else
            {
                int len = 1;
                starRequirement = 100;
                int test = starRequirement / 10;
                while (test)
                {
                    len++;
                    test /= 10;
                }
                
                int shift = len * 110 / 2;
                {
                    struct Object* obj = spawn_object_relative(ORANGE_NUMBER_0 + 10, shift, 280, 32, o, MODEL_OW_NUMBER, bhvOwNumber);
                    obj_scale(obj, 2.f);
                    shift -= 110;
                }
    
                test = starRequirement / 10;
                while (test)
                {
                    struct Object* obj = spawn_object_relative(ORANGE_NUMBER_0 + (test % 10), shift, 280, 32, o, MODEL_OW_NUMBER, bhvOwNumber);
                    obj_scale(obj, 2.f);
                    test /= 10;
                    shift -= 110;
                }    
            }
        }
        else
        {
            if ((1ULL << 63) && save_file_get_star_flags(gCurrSaveFileNum - 1, o->oBehParams2ndByte))
            {
                o->activeFlags = 0;
            }
            else
            {
                if (0 == GET_BPARAM1(o->oBehParams))
                {
                    struct Object* obj = spawn_object_relative(0, 0, 380, 32, o, MODEL_OW_CLEAR, bhvOwNumber);
                    obj_scale(obj, 1.5f);    
                }
            }
        }
    }

    load_object_collision_model();
}

void bhv_ow_number_loop(void)
{
    o->oAnimState = o->oBehParams2ndByte;
    o->oOpacity = o->parentObj->oOpacity;
    hide_if_invisible();
}

extern Gfx bob_dl_Shape_IndexedFaceSet_065_mesh_layer_1[];
extern Gfx bob_dl_Shape_IndexedFaceSet_065_mesh_layer_4[];
void bhv_bob_fakeout_loop()
{
    if (0 == o->oAction)
    {
        if (1000.f < o->oDistanceToMario && o->oDistanceToMario < 3000.f)
        {
            o->oAction = 1;
        }    
    }
    else
    {
        if (100 == o->oTimer)
        {
            gMarioStates->usedObj = o;
            SET_BPARAM2(o->oBehParams, 0xa);
            level_trigger_warp(gMarioStates, WARP_OP_TELEPORT);
        }

        {
            u8* ptr = segmented_to_virtual(bob_dl_Shape_IndexedFaceSet_065_mesh_layer_1);
            ptr[0x50 + 7] = 255 - 2 * o->oTimer;
        }
        {
            u8* ptr = segmented_to_virtual(bob_dl_Shape_IndexedFaceSet_065_mesh_layer_4);
            ptr[0x50+ 7] = 255 - 2 * o->oTimer;
        }    
    }
}
