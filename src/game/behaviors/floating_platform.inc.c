// floating_platform.inc.c

#define oFloatingPlatformYMax OBJECT_FIELD_F32(0x1F)
#define oFloatingPlatformYMin OBJECT_FIELD_F32(0x1E)

f32 floating_platform_find_home_y(void) {
    struct Surface *floor;
    f32 waterLevel  = find_water_level(o->oPosX, o->oPosZ);
    f32 floorHeight = find_floor(o->oPosX, o->oPosY, o->oPosZ, &floor);

    if (waterLevel > floorHeight + o->oFloatingPlatformHeightOffset) {
        o->oFloatingPlatformIsOnFloor = FALSE;
        return (waterLevel + o->oFloatingPlatformHeightOffset);
    } else {
        o->oFloatingPlatformIsOnFloor = TRUE;
        return (floorHeight + o->oFloatingPlatformHeightOffset);
    }
}

void floating_platform_act_move_to_home(void) {
    if (gMarioObject->platform == o) {
        f32 dx = gMarioObject->header.gfx.pos[0] - o->oPosX;
        f32 dz = gMarioObject->header.gfx.pos[2] - o->oPosZ;
        f32 cy = coss(-o->oMoveAngleYaw);
        f32 sy = sins(-o->oMoveAngleYaw);
        o->oFaceAnglePitch = ((dz * cy) + (dx * sy)) * 2;
        o->oFaceAngleRoll = -((dx * cy) + (dz * sy)) * 2;
        o->oVelY -= 1.0f;
        if (o->oVelY < 0.0f) {
            o->oVelY = 0.0f;
        }

        o->oFloatingPlatformMarioWeightWobbleOffset += o->oVelY;
        if (o->oFloatingPlatformMarioWeightWobbleOffset > 90.0f) {
            o->oFloatingPlatformMarioWeightWobbleOffset = 90.0f;
        }
    } else {
        o->oFaceAnglePitch /= 2;
        o->oFaceAngleRoll /= 2;
        o->oFloatingPlatformMarioWeightWobbleOffset -= 5.0f;

        o->oVelY = 10.0f;

        if (o->oFloatingPlatformMarioWeightWobbleOffset < 0.0f) {
            o->oFloatingPlatformMarioWeightWobbleOffset = 0.0f;
        }
    }

    o->oPosY = o->oHomeY - 64.0f - o->oFloatingPlatformMarioWeightWobbleOffset
               + sins(o->oFloatingPlatformWaterSurfaceWobbleOffset * 0x800) * 10.0f;

    if (o->oFloatingPlatformYMax < o->oPosY) {
        o->oPosY = o->oFloatingPlatformYMax;
    }
    if (o->oFloatingPlatformYMin > o->oPosY) {
        o->oPosY = o->oFloatingPlatformYMin;
    }

    o->oFloatingPlatformWaterSurfaceWobbleOffset++;

    if (o->oFloatingPlatformWaterSurfaceWobbleOffset == 32) {
        o->oFloatingPlatformWaterSurfaceWobbleOffset = 0;
    }
}

void bhv_floating_platform_init(void) {
    struct Surface *surf;
    o->oFloatingPlatformYMax = find_ceil (o->oPosX + 200.f, o->oPosY, o->oPosZ + 200.f, &surf);
    o->oFloatingPlatformYMin = find_floor(o->oPosX + 200.f, o->oPosY, o->oPosZ + 200.f, &surf);
}

void bhv_floating_platform_loop(void) {
    o->oHomeY = floating_platform_find_home_y();

    // o->oAction = o->oFloatingPlatformIsOnFloor;
    if (o->oFloatingPlatformIsOnFloor) {
        o->oPosY = o->oHomeY;
    } else {
        floating_platform_act_move_to_home();
    }
}
