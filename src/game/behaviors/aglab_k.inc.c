#define oKSourceDetached oAction

#define oKSparkAttachObj oObjF4
#define oKSparkAttachPrevObj oObjF8
#define oKSparkAttachmentRate oFloatFC

extern const BehaviorScript bhvKSpark[];
void bhv_k_source_init()
{
    o->parentObj = spawn_object(o, MODEL_K_SPARK, bhvKSpark);
    o->parentObj->oKSparkAttachObj = o;
    o->parentObj->oKSparkAttachPrevObj = o;
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
