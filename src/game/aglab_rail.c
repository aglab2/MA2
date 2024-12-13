#include <PR/ultratypes.h>
#include "types.h"
#include "game/area.h"
#include "game/level_update.h"
#include "engine/math_util.h"

extern const Trajectory** rail_descs_ce[];
extern const Trajectory** rail_descs_mh[];
static const Trajectory*** kRails[] = {
    [ LEVEL_CE ] = rail_descs_ce,
    [ LEVEL_MH ] = rail_descs_mh,
};

#define MAX_ZIPLINE_DISTANCE 50000.f

static const Trajectory* sTrajectory;
// TODO: Enable this only for loops
static Vec3f sTrajectoryMiddle;
static f32 sZiplineProgress = 0;
static f32 sPosX;
static f32 sPosY;
static f32 sPosZ;
static int sZiplineCurPoint = 0;
static f32 sForwardVel = 0;
static u8 sCancelTimeout = 0;
static u8 sAngleFlipped = 0;
static u8 sTrajectoryArea = 0;

static inline float point_to_segment_distance(Vec3f Q, Vec3f P1, Vec3f P2, Vec3f closest_point, float* ot) {
    Vec3f P1P2;
    vec3f_diff(P1P2, P2, P1);
    Vec3f P1Q;
    vec3f_diff(P1Q, Q, P1);

    float P1P2_dot_P1P2 = vec3_dot(P1P2, P1P2);
    float t = vec3_dot(P1Q, P1P2) / P1P2_dot_P1P2;

    if (t < 0) {
        vec3f_copy(closest_point, P1);
        return MAX_ZIPLINE_DISTANCE;
    } else if (t > 1) {
        vec3f_copy(closest_point, P2);
        return MAX_ZIPLINE_DISTANCE;
    } else {
        closest_point[0] = P1[0] + t * P1P2[0];
        closest_point[1] = P1[1] + t * P1P2[1];
        closest_point[2] = P1[2] + t * P1P2[2];
        float d;
        vec3f_get_dist(Q, closest_point, &d);
        *ot = t;
        return d;
    }
}

static void calculate_trajectory_middle()
{
    Vec3f maxPoint = { sTrajectory[1], sTrajectory[2], sTrajectory[3] };
    Vec3f minPoint = { sTrajectory[1], sTrajectory[2], sTrajectory[3] };
    int idx = 0;
    while (-1 != sTrajectory[idx + 4])
    {
        const Vec3f curPoint = { sTrajectory[idx + 1], sTrajectory[idx + 2], sTrajectory[idx + 3] };
        for (int i = 0; i < 3; i++)
        {
            if (curPoint[i] > maxPoint[i])
                maxPoint[i] = curPoint[i];
            if (curPoint[i] < minPoint[i])
                minPoint[i] = curPoint[i];
        }
        idx += 4;
    }

    sTrajectoryMiddle[0] = (maxPoint[0] + minPoint[0]) / 2;
    sTrajectoryMiddle[1] = (maxPoint[1] + minPoint[1]) / 2;
    sTrajectoryMiddle[2] = (maxPoint[2] + minPoint[2]) / 2;
}

static int handle_trajectory_cancel(const Trajectory* traj, int it)
{
    Vec3f Q = { gMarioStates->pos[0], gMarioStates->pos[1], gMarioStates->pos[2] };
    f32 minDist = 2000.f;
    Vec3f closestPoint = {0, 0, 0};
    f32 minT = 0;
    int minPoint = 0;
    int i = 0;

    while (-1 != traj[i*4 + 4])
    {
        Vec3f trajCurPoint = {traj[i*4 + 1], traj[i*4 + 2], traj[i*4 + 3]};
        Vec3f trajNextPoint = {traj[i*4 + 5], traj[i*4 + 6], traj[i*4 + 7]};

        Vec3f tmpClosestPoint;
        f32 tmpT = 0;
        float tmpDist = point_to_segment_distance(Q, trajCurPoint, trajNextPoint, tmpClosestPoint, &tmpT);
        if (tmpDist < minDist)
        {
            minDist = tmpDist;
            minT = tmpT;
            minPoint = i * 4;
            vec3f_copy(closestPoint, tmpClosestPoint);
        }
        i++;
    }

#if 0
    print_text_fmt_int(20 + 50*it, 20, "%d", (int) minDist);
    print_text_fmt_int(20 + 50*it, 40, "X %d", (int) sPosX);
    print_text_fmt_int(20 + 50*it, 60, "Y %d", (int) sPosY);
    print_text_fmt_int(20 + 50*it, 80, "Z %d", (int) sPosZ);
    
    print_text_fmt_int(20 + 50*it, 140, "X %d", (int) gMarioStates->pos[0]);
    print_text_fmt_int(20 + 50*it, 160, "Y %d", (int) gMarioStates->pos[1]);
    print_text_fmt_int(20 + 50*it, 180, "Z %d", (int) gMarioStates->pos[2]);
#endif

    if (minDist < 60.f)
    {
        sPosX = closestPoint[0];
        sPosY = closestPoint[1];
        sPosZ = closestPoint[2];
        sZiplineProgress = minT;
        sZiplineCurPoint = minPoint;
        
        Vec3f trajCurPoint = {traj[sZiplineCurPoint + 1], traj[sZiplineCurPoint + 2], traj[sZiplineCurPoint + 3]};
        Vec3f trajNextPoint = {traj[sZiplineCurPoint + 4 + 1], traj[sZiplineCurPoint + 4 + 2], traj[sZiplineCurPoint + 4 + 3]};
        Vec3f trajDirection;
        vec3f_diff(trajDirection, trajNextPoint, trajCurPoint);
        f32 dirMag = vec3_mag(trajDirection);
        trajDirection[0] /= dirMag;
        trajDirection[1] /= dirMag;
        trajDirection[2] /= dirMag;
        sForwardVel = trajDirection[0] * gMarioStates->vel[0] + trajDirection[1] * gMarioStates->vel[1] + trajDirection[2] * gMarioStates->vel[2];
        sTrajectory = traj;
        sTrajectoryArea = gCurrAreaIndex;
        s16 yaw = atan2s(trajDirection[2], trajDirection[0]);
        sAngleFlipped = abs_angle_diff(gMarioStates->faceAngle[1], yaw) > 0x4000;
        sCancelTimeout = 4;
        calculate_trajectory_middle();
        return 1;
    }
    else
    {
        return 0;
    }
}

int zipline_cancel()
{
    if (sCancelTimeout)
    {
        sCancelTimeout--;
        return 0;
    }

    if (gMarioStates->action == ACT_RAIL_GRIND)
        return 0;

    if (gCurrLevelNum >= sizeof(kRails) / sizeof(kRails[0]))
        return 0;

    const Trajectory*** areaTrajectories = kRails[gCurrLevelNum];
    if (!areaTrajectories)
        return 0;

    areaTrajectories = segmented_to_virtual(areaTrajectories);
    const Trajectory** trajectories = areaTrajectories[gCurrAreaIndex - 1];
    if (!trajectories)
        return 0;

    trajectories = segmented_to_virtual(trajectories);
    int it = 0;
    while (*trajectories)
    {
        const Trajectory* traj = segmented_to_virtual(*trajectories);
        if (handle_trajectory_cancel(traj, it++))
            return 1;

        trajectories++;
    }

#if 0
    print_text_fmt_int(20, 20, "%d", it);
#endif
    return 0;
}

static void prepare_mario_for_zipline_drop(Vec3f trajDirection)
{
#if 0
                cur_obj_become_intangible();
                gMarioObject->oInteractStatus |= INT_STATUS_MARIO_DROP_FROM_HOOT;
#endif

    f32 mag = sqrtf(trajDirection[0] * trajDirection[0] + trajDirection[2] * trajDirection[2]);
    trajDirection[0] /= mag;
    trajDirection[2] /= mag;
    trajDirection[0] *= sForwardVel;
    trajDirection[2] *= sForwardVel;

    gMarioStates->vel[0] = trajDirection[0];
    gMarioStates->vel[1] = 0;
    gMarioStates->vel[2] = trajDirection[2];
    gMarioStates->forwardVel = sqrtf(gMarioStates->vel[0] * gMarioStates->vel[0] + gMarioStates->vel[2] * gMarioStates->vel[2]);
    
    s16 angle = atan2s(trajDirection[2], trajDirection[0]);
    if (abs_angle_diff(gMarioStates->faceAngle[1], angle) > 0x4000)
    {
        gMarioStates->forwardVel = -gMarioStates->forwardVel;
    }
}

int zipline_step()
{
    if (sTrajectoryArea != gCurrAreaIndex)
    {
        f32 fv = sForwardVel;
        if (!zipline_cancel())
            return 1;

        sForwardVel = fv;
    }

    const Trajectory* traj = sTrajectory;
    // Advance along the zipline
    {
        Vec3f trajCurPoint = {traj[sZiplineCurPoint + 1], traj[sZiplineCurPoint + 2], traj[sZiplineCurPoint + 3]};
        Vec3f trajNextPoint = {traj[sZiplineCurPoint + 4 + 1], traj[sZiplineCurPoint + 4 + 2], traj[sZiplineCurPoint + 4 + 3]};
        Vec3f trajDirection;
        vec3f_diff(trajDirection, trajNextPoint, trajCurPoint);
        print_text_fmt_int(20, 100, "X %d", (int) trajDirection[0]);
        print_text_fmt_int(20, 120, "Z %d", (int) trajDirection[2]);
        #if 0
        if (absf(trajDirection[0] > 10.f) && absf(trajDirection[2]) > 10.f)
        {
            gMarioStates->faceAngle[1] = atan2s(trajDirection[2], trajDirection[0]);
            if (sAngleFlipped)
            {
                gMarioStates->faceAngle[1] += 0x8000;
            }
        }
        #endif

        {
            Vec3f loopDiff;
            vec3f_diff(loopDiff, gMarioStates->pos, sTrajectoryMiddle);
            gMarioStates->faceAngle[0] = 0x4000 + atan2s(loopDiff[2], loopDiff[1]);
            print_text_fmt_int(20, 20, "0 %d", (int) gMarioStates->faceAngle[0]);
            print_text_fmt_int(20, 40, "1 %d", (int) gMarioStates->faceAngle[1]);
        }

        f32 dirMag = vec3_mag(trajDirection);
        // Calculate velocity
        {
            f32 xdir = trajDirection[0];
            f32 zdir = trajDirection[2];
            f32 szmag = sqrtf(xdir * xdir + zdir * zdir);
            xdir /= szmag;
            zdir /= szmag;

            f32 xspd = gMarioState->intendedMag * sins(gMarioState->intendedYaw);
            f32 zspd = gMarioState->intendedMag * coss(gMarioState->intendedYaw);
            if (abs_angle_diff(gMarioState->faceAngle[1], gMarioState->intendedYaw) > 0x4000)
            {
                xspd /= 5.f;
                zspd /= 5.f;
            }
            f32 dot = xdir * xspd + zdir * zspd;

#ifndef test
            sForwardVel += 5.f;
#else
            sForwardVel *= 0.95f;
            sForwardVel += dot / 12.0f;
            sForwardVel -= trajDirection[1] / dirMag * 5.f;
#endif
            sForwardVel = CLAMP(sForwardVel, -100.f, 100.f);

            // print_text_fmt_int(20, 20, "%d", (int) sForwardVel);

#if 0
            if (sForwardVel < 1.f)
            {
                cur_obj_become_intangible();
                gMarioObject->oInteractStatus |= INT_STATUS_MARIO_DROP_FROM_HOOT;
            }
            cur_obj_play_sound_1(SOUND_ENV_ELEVATOR1);
#endif

        }

        prepare_mario_for_zipline_drop(trajDirection);
        f32 movAmt = sForwardVel / dirMag;

        sZiplineProgress += movAmt;
        if (sZiplineProgress >= 1.f)
        {
            if (traj[sZiplineCurPoint + 8] == -1)
            {
                return 1;
            }
            else
            {
                sZiplineProgress = sZiplineProgress - 1.f;
                sZiplineCurPoint += 4;
            }
        }
        if (sZiplineProgress < 0.f)
        {
            if (0 == sZiplineCurPoint)
            {
                return 1;
            }
            else
            {
                sZiplineProgress = 1.f + sZiplineProgress;
                sZiplineCurPoint -= 4;
            }
        }
    }
    {
        Vec3f trajCurPoint = {traj[sZiplineCurPoint + 1], traj[sZiplineCurPoint + 2], traj[sZiplineCurPoint + 3]};
        Vec3f trajNextPoint = {traj[sZiplineCurPoint + 4 + 1], traj[sZiplineCurPoint + 4 + 2], traj[sZiplineCurPoint + 4 + 3]};
        Vec3f trajDirection;
        vec3f_diff(trajDirection, trajNextPoint, trajCurPoint);
        sPosX = trajCurPoint[0] + (trajDirection[0] * sZiplineProgress);
        sPosY = trajCurPoint[1] + (trajDirection[1] * sZiplineProgress);
        sPosZ = trajCurPoint[2] + (trajDirection[2] * sZiplineProgress);
        gMarioStates->pos[0] = sPosX;
        gMarioStates->pos[1] = sPosY;
        gMarioStates->pos[2] = sPosZ;
    }

    return 0;
}
