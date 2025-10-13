#define oMsSlaneFloor oFloatF4

void bhv_ms_slane_init()
{
    struct Surface* floor;
    o->oMsSlaneFloor = 20.f + find_floor(o->oPosX, o->oPosY, o->oPosZ, &floor);
}

void bhv_ms_slane_loop()
{
    if (0 == o->oAction)
    {
        if (gMarioObject->platform == o)
        {
            o->oAction = 1 + o->oBehParams2ndByte;
            obj_set_model(o, MODEL_MS_SLANE_BREAK);
            create_sound_spawner(SOUND_GENERAL_EXPLOSION7);
        }
    }
    else if (1 == o->oAction)
    {
        o->oVelY += 1.f;
        o->oPosY -= o->oVelY;
        if (o->oPosY < o->oMsSlaneFloor)
        {
            o->oPosY = o->oMsSlaneFloor;
            o->oVelY = 0;
        }
    }
    else if (2 == o->oAction)
    {
        o->oFaceAngleRoll += sins(o->oTimer * 0x169) * 0x80;
    }
    else if (3 == o->oAction)
    {
        o->oFaceAngleYaw += 40;
        if (o->oFaceAngleYaw > 0x500)
        {
            o->oFaceAngleYaw = 0x500;
        }
        
        o->oFaceAnglePitch += 20;
        if (o->oFaceAnglePitch > 0x300)
        {
            o->oFaceAnglePitch = 0x300;
        }
    }
    else if (4 == o->oAction)
    {
        o->oFaceAnglePitch += 10;
        if (o->oFaceAnglePitch > 0x800)
        {
            o->oFaceAnglePitch = 0x800;
        }
    }
}

extern const Collision ms_car1_collision[];
extern const Collision ms_car2_collision[];
extern const Collision ms_car3_collision[];
extern const Collision ms_car4_collision[];
extern const Collision ms_car5_collision[];

static const Collision* kMsCarCollisions[] = {
    ms_car1_collision,
    ms_car2_collision,
    ms_car3_collision,
    ms_car4_collision,
};

extern void bhv_speeder_init();
void bhv_ms_car_init()
{
    obj_scale(o, 0.2f);

    int type = random_u16() % 4;
    int model = MODEL_MS_CAR1 + type;
    obj_set_model(o, model);
    obj_set_collision_data(o, kMsCarCollisions[type]);
    o->oDrawingDistance = 20000.f;
    //bhv_speeder_init();
}
