Gfx *geo_gh_flowers(s32 callContext, UNUSED struct GraphNode *node, Mat4 mtx)
{
    if (callContext == GEO_CONTEXT_RENDER) {
        struct GraphNodeBatchsetTranslationRotation *transNode = (struct GraphNodeBatchsetTranslationRotation *) node->next;
        transNode->rotation[2] = gGlobalTimer * 0x8000 / 150;
    }
    return NULL;

}

void bhv_gh_plat_loop()
{
    o->oPosX += 4.f * sins(o->oTimer * 0x2000 / 15);
}

extern const Trajectory gh_area_2_spline_0131_object_012A8F7C_001_StarMove[];
extern const Trajectory gh_area_2_spline_0131_object_012A8F7C_001_StarMove_001[];
extern const Trajectory gh_area_2_spline_0131_object_012A8F7C_001_StarMove_002[];

static const Trajectory* sGhTrajectories[] = {
    gh_area_2_spline_0131_object_012A8F7C_001_StarMove_002,
    gh_area_2_spline_0131_object_012A8F7C_001_StarMove_001,
    gh_area_2_spline_0131_object_012A8F7C_001_StarMove,
};

#define oGhProgressIndex oF4
#define oGhProgressAmount oFloatF8

void bhv_gh_warp_loop()
{
    int isEntrance = !GET_BPARAM1(o->oBehParams);
    int conn = o->oBehParams2ndByte;

    if (isEntrance)
    {
        if (0 == o->oAction)
        {
            if (o->oDistanceToMario < 200.f)
            {
                o->oAction = 1;
                o->oGhProgressIndex = 0;
                o->oGhProgressAmount = 0.f;
                drop_and_set_mario_action(gMarioStates, ACT_DISAPPEARED, 0);
                o->parentObj = spawn_object(o, MODEL_AMP, bhvStaticObject);
                s8DirModeYawOffset = o->oFaceAngleYaw + 0x4000;
            }
        }
        else
        {
            const Trajectory* traj = segmented_to_virtual(sGhTrajectories[conn]);
            {
                Vec3f trajCurPoint = {traj[o->oGhProgressIndex + 1], traj[o->oGhProgressIndex + 2], traj[o->oGhProgressIndex + 3]};
                Vec3f trajNextPoint = {traj[o->oGhProgressIndex + 4 + 1], traj[o->oGhProgressIndex + 4 + 2], traj[o->oGhProgressIndex + 4 + 3]};
                Vec3f trajDirection;
                vec3f_diff(trajDirection, trajNextPoint, trajCurPoint);

                f32 dirMag = vec3_mag(trajDirection);
                f32 velocity = 100.f;
                f32 movAmt = velocity / dirMag;

                o->oGhProgressAmount += movAmt;
                while (o->oGhProgressAmount >= 1.f)
                {
                    if (traj[o->oGhProgressIndex + 8] == -1)
                    {
                        struct Object* target = cur_obj_find_object_with_behavior_and_bparam2(bhvGhWarp, conn);
                        gMarioStates->pos[0] = target->oPosX;
                        gMarioStates->pos[1] = target->oPosY;
                        gMarioStates->pos[2] = target->oPosZ;
                        gMarioStates->faceAngle[1] = target->oFaceAngleYaw;
                        drop_and_set_mario_action(gMarioStates, ACT_EMERGE_FROM_PIPE, 0);
                        gMarioStates->actionTimer = 10;
                        o->oAction = 0;
                        o->parentObj->activeFlags = 0;
                        return;
                    }
                    else
                    {
                        o->oGhProgressAmount = o->oGhProgressAmount - 1.f;
                        o->oGhProgressIndex += 4;
                    }
                }
            }
            {
                Vec3f trajCurPoint = {traj[o->oGhProgressIndex + 1], traj[o->oGhProgressIndex + 2], traj[o->oGhProgressIndex + 3]};
                Vec3f trajNextPoint = {traj[o->oGhProgressIndex + 4 + 1], traj[o->oGhProgressIndex + 4 + 2], traj[o->oGhProgressIndex + 4 + 3]};
                Vec3f trajDirection;
                vec3f_diff(trajDirection, trajNextPoint, trajCurPoint);
                o->parentObj->oPosX = gMarioStates->pos[0] = trajCurPoint[0] + (trajDirection[0] * o->oGhProgressAmount);
                o->parentObj->oPosY = gMarioStates->pos[1] = trajCurPoint[1] + (trajDirection[1] * o->oGhProgressAmount);
                o->parentObj->oPosZ = gMarioStates->pos[2] = trajCurPoint[2] + (trajDirection[2] * o->oGhProgressAmount);
            }
        }
    }
}
