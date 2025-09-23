#define oKSourceDetached oAction

#define oKSparkAttachObj oObjF4
#define oKSparkAttachPrevObj oObjF8
#define oKSparkAttachmentRate oFloatFC

u8 sSparkRefill = 1;

extern const BehaviorScript bhvKSpark[];
void bhv_k_source_init()
{
    o->parentObj = spawn_object(o, MODEL_K_SPARK, bhvKSpark);
    if (sSparkRefill)
    {
        o->oKSourceDetached = 1;
        o->parentObj->oKSparkAttachPrevObj = gMarioObject;
        o->parentObj->oKSparkAttachObj = gMarioObject;
        o->parentObj->oKSparkAttachmentRate = 0.f;
        o->parentObj->oAction = 1;
        sSparkRefill = 0;
    }
    else
    {
        o->parentObj->oKSparkAttachObj = o;
        o->parentObj->oKSparkAttachPrevObj = o;
    }
}

void bhv_k_source_loop()
{
    if (o->oKSourceDetached)
        return;

    if (gMarioObject->platform == o)
    {
        o->oKSourceDetached = 1;
        o->parentObj->oKSparkAttachPrevObj = o;
        o->parentObj->oKSparkAttachObj = gMarioObject;
        o->parentObj->oKSparkAttachmentRate = 1.f;
        o->parentObj->oAction = 1;
    }
}

void bhv_k_spark_loop()
{
    o->oKSparkAttachmentRate -= 0.1f;
    if (o->oKSparkAttachmentRate < 0.f)
        o->oKSparkAttachmentRate = 0.f;

    Vec3f attachPoint;
    attachPoint[0] = lerpf(o->oKSparkAttachObj->oPosX, o->oKSparkAttachPrevObj->oPosX, o->oKSparkAttachmentRate);
    attachPoint[1] = lerpf(o->oKSparkAttachObj->oPosY, o->oKSparkAttachPrevObj->oPosY, o->oKSparkAttachmentRate);
    attachPoint[2] = lerpf(o->oKSparkAttachObj->oPosZ, o->oKSparkAttachPrevObj->oPosZ, o->oKSparkAttachmentRate);

    o->oPosX = attachPoint[0] + 120.f * sins(gGlobalTimer * 1200);
    o->oPosY = attachPoint[1] + 70.f;
    o->oPosZ = attachPoint[2] + 120.f * coss(gGlobalTimer * 1200);

    o->oAnimState++;
}

void bhv_k_door_init()
{
    f32 d;
    o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvKSpark, &d);
    o->oOpacity = 255;
}

void bhv_k_door_loop()
{
    if (0 == o->oAction && o->parentObj->oAction)
    {
        f32 dx = o->oPosX - gMarioStates->pos[0];
        f32 dy = o->oPosY - gMarioStates->pos[1];
        f32 dz = o->oPosZ - gMarioStates->pos[2];
        f32 dist = sqr(dx) + sqr(dy) + sqr(dz);

        if (dist < 500.f * 500.f)
        {
            o->oAction = 1;

            o->parentObj->oKSparkAttachPrevObj = gMarioObject;
            o->parentObj->oKSparkAttachObj = o;
            o->parentObj->oKSparkAttachmentRate = 1.f;
            o->parentObj->oAction = 2;
        }
        load_object_collision_model();
    }
    else if (1 == o->oAction)
    {
        if (0 == o->parentObj->oKSparkAttachmentRate)
        {
            o->oOpacity = 0;
            if (o->oAction != 2)
            {
                o->parentObj->oOpacity = 255;
                o->parentObj->oKSparkAttachObj = o;
                o->parentObj->oKSparkAttachPrevObj = o;
                o->parentObj->oAction = 2;
                o->oAction = 2;
            }
        }
        else
        {
            o->parentObj->oOpacity = o->oOpacity = 255 - 255 * o->parentObj->oKSparkAttachmentRate;
        }
    }
}

void bhv_k_plat_init()
{
    bhv_k_door_init();
    o->oOpacity = 20;
}

static void k_plat_propagate_fun(struct Object* obj)
{
    obj->oOpacity = o->oOpacity;
    obj->oAction = o->oAction;
}

void bhv_k_plat_loop()
{
    if (0 == o->oAction && 1 == o->parentObj->oAction)
    {
        f32 dx = o->oPosX - gMarioStates->pos[0];
        f32 dy = o->oPosY - gMarioStates->pos[1];
        f32 dz = o->oPosZ - gMarioStates->pos[2];
        f32 dist = sqr(dx) + sqr(dy) + sqr(dz);

        if (dist < 500.f * 500.f)
        {
            o->oAction = 1;

            o->parentObj->oKSparkAttachPrevObj = gMarioObject;
            o->parentObj->oKSparkAttachObj = o;
            o->parentObj->oKSparkAttachmentRate = 1.f;
            o->parentObj->oAction = 2;
        }
    }
    else if (o->oAction == 1)
    {
        if (0 == o->parentObj->oKSparkAttachmentRate)
        {
            o->oOpacity = 255;
            o->parentObj->oOpacity = 255;
            o->parentObj->oKSparkAttachObj = o;
            o->parentObj->oKSparkAttachPrevObj = o;
            o->oAction = 2;
            cur_obj_foreach(bhvKPlat, k_plat_propagate_fun);
        }
        else
        {
            o->parentObj->oOpacity = 255 - 255 * o->parentObj->oKSparkAttachmentRate;
            o->oOpacity = 20 + 235 * (1.f - o->parentObj->oKSparkAttachmentRate);
            cur_obj_foreach(bhvKPlat, k_plat_propagate_fun);
        }
        load_object_collision_model();
    }
    else
    {
        load_object_collision_model();
    }
}
