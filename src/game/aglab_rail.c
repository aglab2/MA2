#include <PR/ultratypes.h>
#include "types.h"
#include "game/area.h"
#include "game/game_init.h"
#include "game/level_update.h"
#include "rail_desc.h"
#include "engine/math_util.h"

const Trajectory* sTrajectory;
static const LDLDesc* sLoopDesc;
static Vec3f sTrajectoryMiddle;
static s16 sZiplineCurPoint = 0;
static s16 sZiplineSegmentCount;
static s16 sZiplineLoopYaw;
static s16 sLoopFaceAngle;
static f32 sZiplineProgress = 0;
static f32 sPosX;
static f32 sPosY;
static f32 sPosZ;
static f32 sForwardVelLimit = 0;
static f32 sForwardVel = 0;
static u32 sCancelDeadline = 0;
static u8 sCancelTimeout = 0;
static u8 sAngleFlipped = 0;
static u8 sTrajectoryArea = 0;
const RailDesc** gRailDesc;

static inline float point_to_segment_distance(Vec3f Q, Vec3f P1, Vec3f P2, Vec3f closest_point) {
    Vec3f P1P2;
    vec3f_diff(P1P2, P2, P1);
    Vec3f P1Q;
    vec3f_diff(P1Q, Q, P1);

    float P1P2_dot_P1P2 = vec3_dot(P1P2, P1P2);
    float t = vec3_dot(P1Q, P1P2) / P1P2_dot_P1P2;

    if (t < 0) {
        vec3f_copy(closest_point, P1);
        return 0.f;
    } else if (t > 1) {
        vec3f_copy(closest_point, P2);
        return 1.f;
    } else {
        closest_point[0] = P1[0] + t * P1P2[0];
        closest_point[1] = P1[1] + t * P1P2[1];
        closest_point[2] = P1[2] + t * P1P2[2];
        return t;
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

    sZiplineSegmentCount = idx;
    sTrajectoryMiddle[0] = (maxPoint[0] + minPoint[0]) / 2;
    sTrajectoryMiddle[1] = (maxPoint[1] + minPoint[1]) / 2;
    sTrajectoryMiddle[2] = (maxPoint[2] + minPoint[2]) / 2;
}

static f32 traj_length(const s16* traj)
{
    f32 length = 0;
    while (-1 != traj[4])
    {
        Vec3s diff;
        vec3_diff(diff, traj + 1, traj + 5);
        traj += 4;
        length += vec3_mag(diff);
    }

    return length;
}

static int facing_same_way(s32 xDiff, s32 zDiff)
{
    return xDiff * gMarioStates->vel[0] + zDiff * gMarioStates->vel[2] < 0;
}

extern void print_text_fmt_int(int x, int y, const char* fmt, int value);
extern u8 gIsGravityFlipped;
static int handle_trajectory_cancel(const Trajectory* traj, const LDLDesc* loop, int it)
{
    (void) it;
    if (sCancelDeadline > gGlobalTimer && traj == sTrajectory && sTrajectoryArea == gCurrAreaIndex)
    {
        return 0;
    }

    Vec3f Q = { gMarioStates->pos[0], gIsGravityFlipped ? 9000.f - (40.f + gMarioStates->pos[1]) : (40.f + gMarioStates->pos[1]), gMarioStates->pos[2] };
    loop = loop ? segmented_to_virtual(loop) : NULL;
    f32 minDist = (loop && loop->dontFlip) ? (500.f * 500.f) : (90.f * 90.f);
    f32 DBGminDist = 100000000000.f;
    Vec3f closestPoint = {0, 0, 0};
    f32 minT = 0;
    int minPoint = -1;
    int i = 0;

    while (-1 != traj[i*4 + 4])
    {
        Vec3f trajCurPoint = {traj[i*4 + 1], traj[i*4 + 2], traj[i*4 + 3]};
        Vec3f trajNextPoint = {traj[i*4 + 5], traj[i*4 + 6], traj[i*4 + 7]};

        Vec3f tmpClosestPoint;
        f32 tmpT = point_to_segment_distance(Q, trajCurPoint, trajNextPoint, tmpClosestPoint);
        Vec3f diff;
        vec3_diff(diff, Q, tmpClosestPoint);
        float tmpDist = diff[0] * diff[0] + diff[1] * diff[1] + diff[2] * diff[2];
        if (tmpDist < minDist)
        {
            minDist = tmpDist;
            minT = tmpT;
            minPoint = i * 4;
            vec3f_copy(closestPoint, tmpClosestPoint);
        }
        if (tmpDist < DBGminDist)
        {
            DBGminDist = tmpDist;
        }
        i++;
    }

    // print_text_fmt_int(20, 20 + 20*it, "%d", (int) (DBGminDist));
#if 0
    print_text_fmt_int(20, 20 + 20*it, "%d", (int) minDist);
    print_text_fmt_int(20 + 50*it, 40, "X %d", (int) sPosX);
    print_text_fmt_int(20 + 50*it, 60, "Y %d", (int) sPosY);
    print_text_fmt_int(20 + 50*it, 80, "Z %d", (int) sPosZ);
    
    print_text_fmt_int(20 + 50*it, 140, "X %d", (int) gMarioStates->pos[0]);
    print_text_fmt_int(20 + 50*it, 160, "Y %d", (int) gMarioStates->pos[1]);
    print_text_fmt_int(20 + 50*it, 180, "Z %d", (int) gMarioStates->pos[2]);
#endif

    if (minPoint >= 0)
    {
        sPosX = closestPoint[0];
        sPosY = closestPoint[1];
        sPosZ = closestPoint[2];
        sZiplineProgress = minT;
        sZiplineCurPoint = minPoint;

        // For loop it is necessary to find where trajectory direction is.
        // The issue is that sometimes the closest point on the trajectory to Mario is
        // on the exactly vertical line, so for angle estimations it is necessary to
        // find the next segment on the trajectory.
        s16 yaw;
        {
            int go_back = 0;
            int point = sZiplineCurPoint;
            int xDiff, zDiff;
            do
            {
                s32 xCurr = traj[point + 1];
                s32 zCurr = traj[point + 3];
    
                s32 xNext = traj[point + 5];
                s32 zNext = traj[point + 7];

                xDiff = xNext - xCurr;
                zDiff = zNext - zCurr;
                if (xDiff || zDiff)
                {
                    break;
                }

                if (!go_back)
                {
                    // try advance forwards but mind that we can be at the end of the trajectory
                    point += 4;
                    if (traj[point + 4] == -1)
                    {
                        // try to advance backwards
                        // I am assume that trajectory is sane not entirely vertical
                        point -= 8;
                        go_back = 1;
                    }
                }
                else
                {
                    point -= 4;
                }
            }
            while (1);

            if (loop && !loop->canSnapBackwards && facing_same_way(xDiff, zDiff))
            {
                // Do not allow to use loop in the opposite direction, probably will cause some weird stuff
                return 0;
            }

            yaw = atan2s(zDiff, xDiff);
        }

        {
            Vec3s trajCurPoint = {traj[sZiplineCurPoint + 1], traj[sZiplineCurPoint + 2], traj[sZiplineCurPoint + 3]};
            Vec3s trajNextPoint = {traj[sZiplineCurPoint + 4 + 1], traj[sZiplineCurPoint + 4 + 2], traj[sZiplineCurPoint + 4 + 3]};
            Vec3f trajDirection;
            vec3f_diff(trajDirection, trajNextPoint, trajCurPoint);
            f32 dirMag = vec3_mag(trajDirection);
            trajDirection[0] /= dirMag;
            trajDirection[1] /= dirMag;
            trajDirection[2] /= dirMag;
    
            sForwardVel = trajDirection[0] * gMarioStates->vel[0] + trajDirection[1] * gMarioStates->vel[1] + trajDirection[2] * gMarioStates->vel[2];
            sForwardVelLimit = 55.f + CLAMP(traj_length(traj) / 400.f, 30.f, 120.f);    
        }

        sTrajectory = traj;
        sLoopDesc = loop;
        sTrajectoryArea = gCurrAreaIndex;
        sAngleFlipped = abs_angle_diff(gMarioStates->faceAngle[1], yaw) > 0x4000;
        sCancelTimeout = sLoopDesc ? 30 : 4;
        if (sLoopDesc)
        {
            sAngleFlipped = 0;
            sZiplineLoopYaw = gMarioStates->faceAngle[1] = sLoopFaceAngle = yaw;
            calculate_trajectory_middle();
        }

        return 1;
    }
    else
    {
        return 0;
    }
}

extern int on_spring();
int zipline_cancel()
{
    if (on_spring())
        return 0;

    if (gMarioStates->action == ACT_RAIL_GRIND)
        return 0;

    if (sCancelTimeout)
    {
        sCancelDeadline = gGlobalTimer + sCancelTimeout;
        sCancelTimeout = 0;
    }

    const RailDesc** areaTrajectories = gRailDesc;
    if (!areaTrajectories)
        return 0;

    const RailDesc* trajectories = areaTrajectories[gCurrAreaIndex - 1];
    if (!trajectories)
        return 0;

    trajectories = segmented_to_virtual(trajectories);
    int it = 0;
    while (trajectories->rail)
    {
        const Trajectory* traj = segmented_to_virtual(trajectories->rail);
        const LDLDesc* loop = trajectories->loop;
        if (handle_trajectory_cancel(traj, loop, it++))
            return 1;

        trajectories++;
    }

#if 0
    print_text_fmt_int(20, 20, "%d", it);
#endif
    return 0;
}

static void prepare_mario_for_zipline_drop_rail(Vec3f trajDirection)
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
    gMarioStates->slideVelX = gMarioStates->vel[0];
    gMarioStates->slideVelZ = gMarioStates->vel[2];

    s16 angle = atan2s(trajDirection[2], trajDirection[0]);
    if (abs_angle_diff(gMarioStates->faceAngle[1], angle) > 0x4000)
    {
        gMarioStates->forwardVel = -gMarioStates->forwardVel;
    }
}

static void prepare_mario_for_zipline_drop_loop(Vec3f trajDirection)
{
    f32 mag = sqrtf(trajDirection[0] * trajDirection[0] + trajDirection[1] * trajDirection[1] + trajDirection[2] * trajDirection[2]);
    trajDirection[0] /= mag;
    trajDirection[1] /= mag;
    trajDirection[2] /= mag;
    trajDirection[0] *= sForwardVel;
    trajDirection[1] *= sForwardVel;
    trajDirection[2] *= sForwardVel;

    gMarioStates->vel[0] = trajDirection[0];
    gMarioStates->vel[1] = trajDirection[1];
    gMarioStates->vel[2] = trajDirection[2];
    gMarioStates->forwardVel = sqrtf(gMarioStates->vel[0] * gMarioStates->vel[0] + gMarioStates->vel[2] * gMarioStates->vel[2]);
    gMarioStates->slideVelX = gMarioStates->vel[0];
    gMarioStates->slideVelZ = gMarioStates->vel[2];
    
    s16 angle = atan2s(trajDirection[2], trajDirection[0]);
    if (abs_angle_diff(gMarioStates->faceAngle[1], angle) > 0x4000)
    {
        gMarioStates->forwardVel = -gMarioStates->forwardVel;
    }
}

int zipline_step(int exSpeed)
{
    f32 exSpeedBoost = sForwardVel * (exSpeed ? (100 - exSpeed * exSpeed) / 2000.f : 0);
    sForwardVel += exSpeedBoost;
    f32 velLimit = sForwardVelLimit + absf(exSpeedBoost);

    gMarioStates->extraAirAction = 1;
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
        Vec3s trajCurPoint = {traj[sZiplineCurPoint + 1], traj[sZiplineCurPoint + 2], traj[sZiplineCurPoint + 3]};
        Vec3s trajNextPoint = {traj[sZiplineCurPoint + 4 + 1], traj[sZiplineCurPoint + 4 + 2], traj[sZiplineCurPoint + 4 + 3]};
        Vec3f trajDirection;
        vec3f_diff(trajDirection, trajNextPoint, trajCurPoint);
        if (gCurrCourseNum == COURSE_CW && !sLoopDesc)
        {
            trajDirection[1] = 0.f;
        }

#if 0
        print_text_fmt_int(20, 100, "X %d", (int) trajDirection[0]);
        print_text_fmt_int(20, 120, "Z %d", (int) trajDirection[2]);
#endif

        s16* pfaceAngle = (sLoopDesc && !sLoopDesc->dontFlip) ? &sLoopFaceAngle : &gMarioStates->faceAngle[1];
        // adjust face angle to the zipline
        if (absf(trajDirection[0] > 0.1f) || absf(trajDirection[2]) > 0.1f)
        {
            *pfaceAngle = atan2s(trajDirection[2], trajDirection[0]);
            if (sAngleFlipped)
            {
                *pfaceAngle += 0x8000;
            }
        }

        if (sLoopDesc && !sLoopDesc->dontFlip)
        {
            // adjust rotation angle from the center
#if 0
            Vec3f loopDiff;
            vec3f_diff(loopDiff, gMarioStates->pos, sTrajectoryMiddle);
            if (gIsGravityFlipped)
                loopDiff[1] = 9000.f - loopDiff[1];

            gMarioStates->faceAngle[sLoopDesc->m0] = sLoopDesc->angleOffset + sLoopDesc->mult * atan2s(loopDiff[sLoopDesc->c0], loopDiff[sLoopDesc->c1]);
#else
            if (sLoopDesc->angleOffset)
                gMarioStates->faceAngle[1] = sZiplineLoopYaw + sLoopDesc->angleOffset * (1 + sZiplineCurPoint) / sZiplineSegmentCount;

            if (abs_angle_diff(gMarioState->faceAngle[1], sLoopFaceAngle) < 0x4000)
                gMarioStates->faceAngle[0] = atan2s(trajDirection[1], sqrtf(trajDirection[0] * trajDirection[0] + trajDirection[2] * trajDirection[2])) - 0x4000;
            else
                gMarioStates->faceAngle[0] = atan2s(sqrtf(trajDirection[0] * trajDirection[0] + trajDirection[2] * trajDirection[2]), trajDirection[1]) + 0x8000;
#endif
        }
        else
        {
            gMarioStates->faceAngle[0] = 0;
            gMarioStates->faceAngle[2] = 0;
        }

        f32 dirMag = vec3_mag(trajDirection);
        // Calculate velocity
        {
            // print_text_fmt_int(20, 20, "L %d", (int) sForwardVelLimit);
            // print_text_fmt_int(20, 40, "V %d", (int) sForwardVel);
            if (sLoopDesc)
            {
                sForwardVel += 5.f;
                sForwardVel = CLAMP(sForwardVel, 0.f, velLimit);
            }
            else
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

                sForwardVel *= 0.97f;
                sForwardVel += dot / 12.0f;
                int grav = trajDirection[1] / dirMag * 5.f;
                if (gIsGravityFlipped)
                    grav = -grav;

                sForwardVel -= grav;
                sForwardVel = CLAMP(sForwardVel, -velLimit, velLimit);
            }

#if 0
            print_text_fmt_int(20, 20, "%d", (int) sForwardVel);
#endif

#if 0
            if (sForwardVel < 1.f)
            {
                cur_obj_become_intangible();
                gMarioObject->oInteractStatus |= INT_STATUS_MARIO_DROP_FROM_HOOT;
            }
            cur_obj_play_sound_1(SOUND_ENV_ELEVATOR1);
#endif

        }

        if (sLoopDesc)
            prepare_mario_for_zipline_drop_loop(trajDirection);
        else
            prepare_mario_for_zipline_drop_rail(trajDirection);

        f32 movAmt = sForwardVel / dirMag;

        f32 preProgress = sZiplineProgress;
        sZiplineProgress += movAmt;

#if 0
        print_text_fmt_int(20, 20, "CP %d", (int) sZiplineCurPoint);
        print_text_fmt_int(20, 40, "PR %d", (int) (1000.f * sZiplineProgress));
#endif

        if (sZiplineProgress >= 1.f)
        {
            if (traj[sZiplineCurPoint + 8] == -1)
            {
#if 0
                // print_text_fmt_int(20, 20, "0 %d", (int) gMarioStates->faceAngle[0]);
                // print_text_fmt_int(20, 40, "1 %d", (int) gMarioStates->faceAngle[1]);
                // print_text_fmt_int(20, 60, "2 %d", (int) gMarioStates->faceAngle[2]);
                if (sLoopDesc)
                {
                    if (abs_angle_diff(gMarioStates->faceAngle[0], 0x8000) < 0x2000)
                    {
                        gMarioStates->faceAngle[0] = 0;
                        gMarioStates->faceAngle[1] = -gMarioStates->faceAngle[1];
                        gMarioStates->faceAngle[2] = 0;
                    }
                }
#endif

                vec3_copy(gMarioStates->pos, traj + sZiplineCurPoint + 4 + 1);
                zipline_cancel();
                return 1;
            }
            else
            {
                f32 consumedProgress = 1.f - preProgress;
                f32 consumedMag = consumedProgress * dirMag;
                f32 remainingVel = sForwardVel - consumedMag;
                
                sZiplineCurPoint += 4;
                {
                    // now calculate the velocity for the next point using the same principle
                    // this assume vel isn't too big to skip multiple points
                    Vec3s trajCurrPoint = { traj[sZiplineCurPoint + 1], traj[sZiplineCurPoint + 2], traj[sZiplineCurPoint + 3] };
                    Vec3s trajNextPoint = { traj[sZiplineCurPoint + 5], traj[sZiplineCurPoint + 6], traj[sZiplineCurPoint + 7] };

                    Vec3f trajDirection;
                    vec3f_diff(trajDirection, trajNextPoint, trajCurrPoint);
                    f32 dirMag2 = vec3_mag(trajDirection);

                    sZiplineProgress = remainingVel / dirMag2;
                }
            }
        }
        if (sZiplineProgress < 0.f)
        {
            if (0 == sZiplineCurPoint)
            {
                vec3_copy(gMarioStates->pos, traj + 1);
                zipline_cancel();
                return 1;
            }
            else
            {
                f32 consumedProgress = preProgress;
                f32 consumedMag = consumedProgress * dirMag;
                f32 remainingVel = -sForwardVel - consumedMag;
                
                sZiplineCurPoint -= 4;
                {
                    // now calculate the velocity for the next point using the same principle
                    // this assume vel isn't too big to skip multiple points
                    Vec3s trajCurrPoint = { traj[sZiplineCurPoint + 1]    , traj[sZiplineCurPoint + 2]    , traj[sZiplineCurPoint + 3    ] };
                    Vec3s trajNextPoint = { traj[sZiplineCurPoint + 1 - 4], traj[sZiplineCurPoint + 2 - 4], traj[sZiplineCurPoint + 3 - 4] };

                    Vec3f trajDirection;
                    vec3f_diff(trajDirection, trajNextPoint, trajCurrPoint);
                    f32 dirMag2 = vec3_mag(trajDirection);

                    sZiplineProgress = 1.f - remainingVel / dirMag2;
                }
            }
        }
    }
    {
        Vec3s trajCurPoint = {traj[sZiplineCurPoint + 1], traj[sZiplineCurPoint + 2], traj[sZiplineCurPoint + 3]};
        Vec3s trajNextPoint = {traj[sZiplineCurPoint + 4 + 1], traj[sZiplineCurPoint + 4 + 2], traj[sZiplineCurPoint + 4 + 3]};
        Vec3f trajDirection;
        vec3f_diff(trajDirection, trajNextPoint, trajCurPoint);
        sPosX = trajCurPoint[0] + (trajDirection[0] * sZiplineProgress);
        sPosY = trajCurPoint[1] + (trajDirection[1] * sZiplineProgress);
        sPosZ = trajCurPoint[2] + (trajDirection[2] * sZiplineProgress);
        gMarioStates->pos[0] = sPosX;
        gMarioStates->pos[1] = sPosY;
        if (gIsGravityFlipped)
            gMarioStates->pos[1] = 9000.f - gMarioStates->pos[1];

        gMarioStates->pos[2] = sPosZ;
    }

    return 0;
}

int zipline_on_loop()
{
    return sLoopDesc != NULL;
}
