#include <PR/ultratypes.h>
#include "types.h"
#include "game/area.h"
#include "game/level_update.h"
#include "engine/math_util.h"

extern const Trajectory** rail_descs_ce[];
static const Trajectory*** kRails[] = {
    [ LEVEL_CE ] = rail_descs_ce,
};

#define MAX_ZIPLINE_DISTANCE 50000.f

static f32 sZiplineProgress = 0;
static f32 sPosX;
static f32 sPosY;
static f32 sPosZ;
static int sZiplineCurPoint = 0;
static f32 sForwardVel = 0;
static s16 sFaceAngleYaw;
static u8 sCancelTimeout = 0;

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

static const Trajectory* sTrajectory;
static int handle_trajectory_cancel(const Trajectory* traj, int it)
{
    Vec3f Q = { gMarioStates->pos[0], gMarioStates->pos[1], gMarioStates->pos[2] };
    f32 minDist = 2000.f;
    Vec3f closestPoint = {0, 0, 0};
    f32 minT = 0;
    int minPoint = 0;
    
    for (int i = 0; i < 2; i++)
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
    }

#if 0
    print_text_fmt_int(20 + 40*it, 20, "%d", (int) minDist);
    print_text_fmt_int(20 + 40*it, 40, "X %d", (int) sPosX);
    print_text_fmt_int(20 + 40*it, 60, "Y %d", (int) sPosY);
    print_text_fmt_int(20 + 40*it, 80, "Z %d", (int) sPosZ);
    
    print_text_fmt_int(20 + 40*it, 140, "X %d", (int) gMarioStates->pos[0]);
    print_text_fmt_int(20 + 40*it, 160, "Y %d", (int) gMarioStates->pos[1]);
    print_text_fmt_int(20 + 40*it, 180, "Z %d", (int) gMarioStates->pos[2]);
#endif

    if (minDist < 30.f)
    {
        sPosX = closestPoint[0];
        sPosY = closestPoint[1];
        sPosZ = closestPoint[2];
        sZiplineProgress = minT;
        sZiplineCurPoint = minPoint;
        sForwardVel = 30.f;
        sTrajectory = traj;
        sCancelTimeout = 30;
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

    if (gCurrLevelNum > sizeof(kRails) / sizeof(kRails[0]))
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

    print_text_fmt_int(20, 20, "%d", it);
    return 0;
}

int zipline_step()
{
    const Trajectory* traj = sTrajectory;
    // Advance along the zipline
    {
        Vec3f trajCurPoint = {traj[sZiplineCurPoint + 1], traj[sZiplineCurPoint + 2], traj[sZiplineCurPoint + 3]};
        Vec3f trajNextPoint = {traj[sZiplineCurPoint + 4 + 1], traj[sZiplineCurPoint + 4 + 2], traj[sZiplineCurPoint + 4 + 3]};
        Vec3f trajDirection;
        vec3f_diff(trajDirection, trajNextPoint, trajCurPoint);
        sFaceAngleYaw = atan2s(trajDirection[2], trajDirection[0]);
        gMarioStates->faceAngle[1] = sFaceAngleYaw;

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
            f32 dot = xdir * xspd + zdir * zspd;

            sForwardVel *= 0.95f;
            sForwardVel += dot / 12.0f;
            sForwardVel = CLAMP(sForwardVel, 0.f, 40.f);

#if 0
            if (sForwardVel < 1.f)
            {
                cur_obj_become_intangible();
                gMarioObject->oInteractStatus |= INT_STATUS_MARIO_DROP_FROM_HOOT;
            }
            cur_obj_play_sound_1(SOUND_ENV_ELEVATOR1);
#endif

        }

        f32 movAmt = sForwardVel / dirMag;

        sZiplineProgress += movAmt;
        if (sZiplineProgress >= 1.f)
        {
            if (traj[sZiplineCurPoint + 8] == -1)
            {
#if 0
                cur_obj_become_intangible();
                gMarioObject->oInteractStatus |= INT_STATUS_MARIO_DROP_FROM_HOOT;
#endif
                return 1;
            }
            else
            {
                sZiplineProgress = sZiplineProgress - 1.f;
                sZiplineCurPoint += 4;
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
