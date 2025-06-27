#include "engine/surface_load.h"

#define oAqLiftActive OBJECT_FIELD_S16(0x1B, 0)
#define oAqLiftReload OBJECT_FIELD_S16(0x1B, 1)
#define oAqLiftSwitches oObjF8

void bhv_aq_ctls_init()
{
    struct Object** objs = &o->oAqLiftSwitches;
    for (int i = 0; i < 3; i++)
        objs[i] = cur_obj_find_object_with_behavior_and_bparam3(bhvFloorSwitchGrills, i);

    objs[0]->oAction = 1;
    o->oAqLiftActive = -1;
    o->oAqLiftReload = 1;
}

static void bhv_aq_ctls_loop()
{
    struct Object** objs = &o->oAqLiftSwitches;
    for (int i = 0; i < 3; i++)
    {
        if (1 == objs[i]->oAction)
        {
            objs[(i + 1) % 3]->oAction = 3;
            objs[(i + 2) % 3]->oAction = 3;
            break;
        }
    }
}

#define SWITCH_ACTIVE(idx) (2 == objs[idx]->oAction)

extern void load_object_static_model();
void bhv_aq_lift_loop()
{
    bhv_aq_ctls_loop();
    if (o->oAqLiftReload && o->oDistanceToMario < 2500.f)
    {
        obj_build_transform_from_pos_and_angle(o, O_POS_INDEX, O_FACE_ANGLE_INDEX);
        load_object_static_model();
        o->oAqLiftReload = 0;
    }

    struct Object** objs = &o->oAqLiftSwitches;
    int wanted_height = 0;
    if (SWITCH_ACTIVE(0))
    {
        o->oPosY = -224.f;
        wanted_height = 0;
    }
    if (SWITCH_ACTIVE(1) || SWITCH_ACTIVE(2))
    {
        o->oPosY = -2324.f;
        wanted_height = 1;
    }

    if (wanted_height != o->oAqLiftActive)
    {
        o->oAqLiftReload = 1;
        o->oAqLiftActive = wanted_height;

        main_pool_pop_state();
        main_pool_push_state();
        load_area_terrain(gCurrentArea->terrainData, gCurrentArea->surfaceRooms);
    }
}

void bhv_aq_water_loop()
{
    struct Object** objs = &o->oAqLiftSwitches;
    f32 height = 0.f;
    if (SWITCH_ACTIVE(0))
    {
        height = 1100.f;
    }
    if (SWITCH_ACTIVE(1))
    {
        height = -950.f;
    }
    if (SWITCH_ACTIVE(2))
    {
        height = -2450.f;
    }
    
    gEnvironmentRegions[12] = gEnvironmentLevels[6] = gEnvironmentRegions[6] = gEnvironmentLevels[0] = o->oPosY = height;
}

#undef SWITCH_ACTIVE
