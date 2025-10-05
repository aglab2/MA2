#define oKSourceDetached oAction

#define oKSparkAttachObj oObjF4
#define oKSparkAttachPrevObj oObjF8
#define oKSparkAttachmentRate oFloatFC

u8 sSparkRefill = LEVEL_CCK;

extern const BehaviorScript bhvKSpark[];
void bhv_k_source_init()
{
    struct Object* spark;
    spark = o->parentObj = spawn_object(o, MODEL_K_SPARK, bhvKSpark);
    // this cumbersome logic is needed to allow dying after grabbing the spark but not entering the next phase
    if (sSparkRefill == gCurrLevelNum || sSparkRefill == gCurrLevelNum - 1)
    {
        sSparkRefill = gCurrLevelNum;
        spark->oKSparkAttachPrevObj = gMarioObject;
        spark->oKSparkAttachObj = gMarioObject;
        spark->oKSparkAttachmentRate = 0.f;
        spark->oAction = 1;
    }
    else
    {
        spark->oKSparkAttachObj = o;
        spark->oKSparkAttachPrevObj = o;
    }
}

void bhv_k_source_loop()
{
    if (o->oKSourceDetached)
        return;

    if (gMarioObject->platform == o)
    {
        o->oKSourceDetached = 1;
        struct Object* spark = o->parentObj;
        spark->oKSparkAttachPrevObj = o;
        spark->oKSparkAttachObj = gMarioObject;
        spark->oKSparkAttachmentRate = 1.f;
        spark->oAction = 1;
        int cc = COURSE_CCE <= gCurrCourseNum && gCurrCourseNum < COURSE_CCS;
        if (cc)
            sSparkRefill = gCurrLevelNum;
        else
            sSparkRefill = 0;
    }
}

void bhv_k_spark_init()
{
    o->oOpacity = 255;
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

    if (gCurrLevelNum == LEVEL_DL)
        obj_scale(o, 0.9f);
}

void bhv_k_door_loop()
{
    struct Object* spark = o->parentObj;
    // Checks for spark->oAction might be a bit too much because I do not think source and be put
    // _that_ close to the door or plat but it is safer this way.
    if (0 == o->oAction)
    {
        if (spark->oAction && o->oDistanceToMario < 500.f)
        {
            o->oAction = 1;

            spark->oKSparkAttachPrevObj = gMarioObject;
            spark->oKSparkAttachObj = o;
            spark->oKSparkAttachmentRate = 1.f;
            spark->oAction = 2;
        }
        load_object_collision_model();
    }
    else if (1 == o->oAction)
    {
        if (0 == spark->oKSparkAttachmentRate)
        {
            o->oOpacity = 0;
            if (o->oAction != 2)
            {
                int cc = COURSE_CCT <= gCurrCourseNum && gCurrCourseNum <= COURSE_CCS;
                if (cc)
                {
                    spark->oOpacity = 255;
                    struct Object* source = spark->parentObj;
                    spark->oKSparkAttachObj = source;
                    spark->oKSparkAttachPrevObj = source;
                    spark->oAction = 0;
                }
                else
                {
                    spark->oOpacity = 0;
                    spark->oKSparkAttachObj = o;
                    spark->oKSparkAttachPrevObj = o;
                }

                cur_obj_hide();
                o->oAction = 2;
            }
        }
        else
        {
            spark->oOpacity = o->oOpacity = 255 * spark->oKSparkAttachmentRate;
        }
    }
}

void bhv_k_plat_init()
{
    bhv_k_door_init();
    o->oOpacity = 30;
}

static void k_plat_propagate_fun(struct Object* obj)
{
    obj->oOpacity = o->oOpacity;
    obj->oAction = 2;
}

void bhv_k_plat_loop()
{
    struct Object* spark = o->parentObj;
    if (0 == o->oAction)
    {
        if (1 == spark->oAction && o->oDistanceToMario < 700.f)
        {
            o->oAction = 1;

            spark->oKSparkAttachPrevObj = gMarioObject;
            spark->oKSparkAttachObj = o;
            spark->oKSparkAttachmentRate = 1.f;
            spark->oAction = 2;
        }
    }
    else if (o->oAction == 1)
    {
        if (0 == spark->oKSparkAttachmentRate)
        {
            int cc = COURSE_CCT <= gCurrCourseNum && gCurrCourseNum <= COURSE_CCS;
            o->oOpacity = 255;
            if (cc)
            {
                spark->oOpacity = 255;
                struct Object* source = spark->parentObj;
                spark->oKSparkAttachObj = source;
                spark->oKSparkAttachPrevObj = source;
                spark->oAction = 0;
            }
            else
            {
                spark->oOpacity = 0;
                spark->oKSparkAttachObj = o;
                spark->oKSparkAttachPrevObj = o;
            }

            o->oAction = 2;
            cur_obj_foreach(bhvKPlat, k_plat_propagate_fun);
        }
        else
        {
            spark->oOpacity = 255 - 255 * spark->oKSparkAttachmentRate;
            o->oOpacity = 30 + 225 * (1.f - spark->oKSparkAttachmentRate);
            cur_obj_foreach(bhvKPlat, k_plat_propagate_fun);
        }
        load_object_collision_model();
    }
    else
    {
        load_object_collision_model();
    }
}
