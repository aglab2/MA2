#include "game/fcgr.h"

typedef struct {
    float r;
    float z;
    s16 theta;
} cyl_t;

static cyl_t to_cyl(const Vec3f point, const Vec3f start, const Vec3f x_axis, const Vec3f y_axis, const Vec3f z_axis);
static cyl_t to_cyl_velocity(Vec3f vel, Vec3f x_axis, Vec3f y_axis, Vec3f z_axis, cyl_t cyl);
static cyl_t to_cyl_vec(const Vec3f rel, const Vec3f x_axis, const Vec3f y_axis, const Vec3f z_axis);
static void to_xyz(Vec3f point, const Vec3f start, const Vec3f x_axis, const Vec3f y_axis, const Vec3f z_axis, cyl_t cyl);
static void to_xyz_vec(Vec3f point, const Vec3f x_axis, const Vec3f y_axis, const Vec3f z_axis, cyl_t cyl);
static void gen_axis(Vec3f x_axis, Vec3f y_axis, Vec3f z_axis, s16 yaw, s16 pitch);
static void gen_axis_point_oriented(Vec3f x_axis_new, Vec3f y_axis_new, const Vec3f x_axis, const Vec3f y_axis, const Vec3f z_axis, const s16 theta);
static int in_tube(const cyl_t* cyl, f32 lim, int len);

static cyl_t sCylVel;
static cyl_t sCylPos;
static s16 sCylArea;
static s16 sZAAngle;
static struct Object* sCylObj;
static f32 sPanYOffset = 0.f;
static u8 sCylFlipped = 0;
#define CYL_FLIPPED_CUTOFF 0x6000

#define IN_TUBE_R 900.f

void bhv_fc_grav_loop()
{
    if (gMarioStates->action == ACT_FCGR_WALKING || gMarioStates->action == ACT_FCGR_JUMP)
    {
        return;
    }

    Vec3f x_axis, y_axis, z_axis;
    gen_axis(x_axis, y_axis, z_axis, o->oFaceAngleYaw, o->oFaceAnglePitch);

    cyl_t cyl = to_cyl(gMarioStates[0].pos, &o->oPosVec, x_axis, y_axis, z_axis);

    if (in_tube(&cyl, IN_TUBE_R, o->oBehParams2ndByte))
    {
        drop_and_set_mario_action(gMarioStates, ACT_FCGR_JUMP, 0);   
        sCylObj = o;
        sCylArea = gCurrAreaIndex;
        sCylFlipped = ABS(cyl.theta) > CYL_FLIPPED_CUTOFF;

        // For velocity conversion, we cannot use generic 'to_cyl' function because
        // angular speed depends on the location of the object, not just the velocity.

        sCylVel = to_cyl_velocity(gMarioStates->vel, x_axis, y_axis, z_axis, cyl);
    }
}

static cyl_t to_cyl_velocity(Vec3f vel, Vec3f x_axis, Vec3f y_axis, Vec3f z_axis, cyl_t cyl)
{
    // We are performing the transformation manually, similarly to the 'to_cyl_vec' function
    cyl_t result;
    Vec3f x_axis_new;
    Vec3f y_axis_new;
    gen_axis_point_oriented(x_axis_new, y_axis_new, x_axis, y_axis, z_axis, cyl.theta);

    // Our choice of x_axis_new and y_axis_new is such that the 'r' value is the distance from the object to the pole...
    result.z = vec3_dot(vel, z_axis);
    result.r = vec3_dot(vel, x_axis_new);
    // ... and the 'theta' is angular speed around the pole projected on 'y_axis_new'
    // mind that angular speed is in radians, so we need to convert it to mario degrees
    result.theta = vec3_dot(vel, y_axis_new) / cyl.r / M_PI * 0x10000;

    return result;
}

static cyl_t to_cyl_vec(const Vec3f rel, const Vec3f x_axis, const Vec3f y_axis, const Vec3f z_axis)
{
    float x = vec3_dot(rel, x_axis);
    float y = vec3_dot(rel, y_axis);
    float z = vec3_dot(rel, z_axis);

    cyl_t result;
    result.r = sqrtf(x*x + y*y);
    result.theta = atan2s(y, x);
    result.z = z;
    return result;
}

static cyl_t to_cyl(const Vec3f point, const Vec3f start, const Vec3f x_axis, const Vec3f y_axis, const Vec3f z_axis)
{
    Vec3f rel;
    vec3_diff(rel, point, start);

    return to_cyl_vec(rel, x_axis, y_axis, z_axis);
}

static void to_xyz_vec(Vec3f point, const Vec3f x_axis, const Vec3f y_axis, const Vec3f z_axis, cyl_t cyl)
{
    Vec3f rel;
    vec3_scale_dest(rel, x_axis, cyl.r * sins(cyl.theta));

    Vec3f tmp;
    vec3_scale_dest(tmp, y_axis, cyl.r * coss(cyl.theta));
    vec3_add(rel, tmp);

    vec3_scale_dest(tmp, z_axis, cyl.z);
    vec3_sum(point, rel, tmp);
}

static void to_xyz(Vec3f point, const Vec3f start, const Vec3f x_axis, const Vec3f y_axis, const Vec3f z_axis, cyl_t cyl)
{
    to_xyz_vec(point, x_axis, y_axis, z_axis, cyl);
    vec3_add(point, start);
}

static void gen_axis(Vec3f x_axis, Vec3f y_axis, Vec3f z_axis, s16 yaw, s16 pitch)
{
    z_axis[0] = sins(yaw) * sins(pitch);
    z_axis[1] = coss(pitch);
    z_axis[2] = coss(yaw) * sins(pitch);

    x_axis[0] = -coss(yaw);
    x_axis[1] = 0.f;
    x_axis[2] = sins(yaw);

    y_axis[0] = -sins(yaw) * coss(pitch);
    y_axis[1] = sins(pitch);
    y_axis[2] = -coss(yaw) * coss(pitch);
}

static void gen_axis_point_oriented(Vec3f x_axis_new, Vec3f y_axis_new, const Vec3f x_axis, const Vec3f y_axis, const Vec3f z_axis, const s16 theta)
{
    {
        cyl_t cyl_flat = { .r = 1.f, .z = 0.f, .theta = theta };
        to_xyz_vec(x_axis_new, x_axis, y_axis, z_axis, cyl_flat);
        vec3_normalize(x_axis_new);
    }
    vec3_cross(y_axis_new, z_axis, x_axis_new);
}

extern f32 find_surface_on_ray(Vec3f orig, Vec3f dir, struct Surface **hit_surface, Vec3f hit_pos, s32 flags);
int fcgr_spin(struct MarioState *m)
{
    if (gCurrAreaIndex != sCylArea)
    {
        sCylObj = NULL;
        sPanYOffset = 0.f;
        return FCGR_BREAK_AIR;
    }

    int type = FCGR_CONTINUE;

    // spin around the 'sCylObj' object around the axis of the object
    struct Object *obj = sCylObj;

    Vec3f x_axis, y_axis, z_axis;
    gen_axis(x_axis, y_axis, z_axis, obj->oFaceAngleYaw, obj->oFaceAnglePitch);

    // apply gravity
    int landed = m->action == ACT_FCGR_WALKING;
    if (landed && (m->input & INPUT_A_PRESSED))
    {
        // this is not exactly sane to give theta to the speed but it will feel better
        sCylVel.r = 50.f + absf(sCylVel.theta) * 0.01f;
    }

    f32 frictionAngular = 0.9f;
    f32 frictionPositional = 0.99f;
    if (landed)
    {
        frictionPositional = (m->input & INPUT_NONZERO_ANALOG) ? 0.95f : 0.2f;
        frictionAngular = (m->input & INPUT_NONZERO_ANALOG) ? 0.94f : 0.1f;
    }

    sCylVel.z = CLAMP(sCylVel.z * frictionPositional, -50.f, 50.f);
    sCylVel.theta = CLAMP(sCylVel.theta * frictionAngular, -0x1000, 0x1000);

    const f32 zAccel = 2.2f;
    const f32 aAccel = 85.f;

    if (landed && (m->input & INPUT_NONZERO_ANALOG))
    {
        if (obj->oFaceAnglePitch)
        {
            s16 diff = m->intendedYaw - obj->oFaceAngleYaw;
            if (sCylFlipped)
                diff = -diff;

            sCylVel.z = approach_f32(sCylVel.z, m->intendedMag * coss(diff) * 2.6f, zAccel, zAccel);
            sCylVel.theta = approach_f32(sCylVel.theta, -m->intendedMag * sins(diff) * 40.f, aAccel, aAccel);
        }
        else
        {
            sCylVel.z = approach_f32(sCylVel.z, m->controller->stickY * 1.f, zAccel, zAccel);
            sCylVel.theta = approach_f32(sCylVel.theta, m->controller->stickX * 18.f, aAccel, aAccel);
        }
    }
    else
    {
        sCylFlipped = ABS(sCylPos.theta) > CYL_FLIPPED_CUTOFF;
    }

    /*
when walking:
	IM 32
	Z 46
	T -1251
    print_text_fmt_int(20, 20, "Z %d", sCylVel.z);
    print_text_fmt_int(20, 40, "T %d", sCylVel.theta);
    print_text_fmt_int(20, 60, "IM %d", m->intendedMag);
    print_text_fmt_int(20, 80, "Y %d", m->controller->stickY);
    print_text_fmt_int(20, 100, "X %d", m->controller->stickX);
    */

    f32 rvel = (m->input & INPUT_A_DOWN) ? 1.f : 4.f;
    sCylVel.r -= rvel;

    // apply position relative to the object
    cyl_t cyl = to_cyl(m->pos, &obj->oPosVec, x_axis, y_axis, z_axis);
    cyl.theta += sCylVel.theta;
    cyl.z += sCylVel.z;
    cyl.r += sCylVel.r;

    if (cyl.r < 280.f)
    {
        cyl.r = 280.f;
        sCylVel.r = 0.f;
        type = FCGR_LAND;
    }

    sCylPos = cyl;
    Vec3f oldPos;
    vec3_copy(oldPos, m->pos);
    Vec3f newPos;
    to_xyz(newPos, &obj->oPosVec, x_axis, y_axis, z_axis, cyl);

    // raycast collision because mario collision engine is completely busted
    int clampWalls = 1;
    if (!m->hurtCounter)
    {
        Vec3f dir;
        vec3_diff(dir, newPos, oldPos);
        struct Surface* hitSurf = NULL;
        Vec3f hitPos;
        // mind that this ray is just an approximation. we live in cylindric coordinate space...
        find_surface_on_ray(oldPos, dir, &hitSurf, hitPos, RAYCAST_FIND_ALL);

        if (hitSurf && hitSurf->type == SURFACE_BURNING)
        {
            clampWalls = 0;
            vec3_copy(newPos, hitPos);
            cyl = to_cyl(newPos, &obj->oPosVec, x_axis, y_axis, z_axis);

            sCylVel.theta = 0;
            sCylVel.z = 0;
            sCylVel.r = 0;

            Vec3f n;
            n[0] = hitSurf->normal.x;
            n[1] = hitSurf->normal.y;
            n[2] = hitSurf->normal.z;

            sCylVel = to_cyl_velocity(n, x_axis, y_axis, z_axis, cyl);
            sCylVel.r = 0.f;
            sCylVel.z *= 50.f;
            s16 mult = o->oFaceAngleYaw ? 30 : -30;
            sCylVel.theta *= mult;
            m->hurtCounter += 4;
            play_sound(SOUND_MARIO_ON_FIRE, m->marioObj->header.gfx.cameraToObject);
        }
    }

    vec3_copy(m->pos, newPos);
    if (clampWalls)
    {
        gCollisionFlags |= COLLISION_FLAG_EXCLUDE_LAVA;
        f32_find_wall_collision(&m->pos[0], &m->pos[1], &m->pos[2], 60.0f, 50.0f);
        gCollisionFlags |= COLLISION_FLAG_EXCLUDE_LAVA;
        f32_find_wall_collision(&m->pos[0], &m->pos[1], &m->pos[2], 30.0f, 24.0f);
    }

    // A reverse of transformation above for velocity
    Vec3f x_axis_new;
    Vec3f y_axis_new;
    gen_axis_point_oriented(x_axis_new, y_axis_new, x_axis, y_axis, z_axis, cyl.theta);

    Vec3f vel_component_a;
    f32 angularVel = cyl.r * sCylVel.theta * M_PI / 0x10000;
    vec3_scale_dest(vel_component_a, y_axis_new, angularVel);

    Vec3f vel_component_z;
    vec3_scale_dest(vel_component_z, z_axis, sCylVel.z);

    Vec3f vel_component_za;
    vec3_sum(vel_component_za, vel_component_a, vel_component_z);

    f32 za_forwardVel = sqrtf(sqr(vel_component_za[0]) + sqr(vel_component_za[2]));
    f32 totalSpeedSqr = sqr(angularVel) + sqr(sCylVel.z);

    if (totalSpeedSqr > 1.f)
    {
        s16 zaAngle = atan2s(angularVel, sCylVel.z);
        sZAAngle = zaAngle;
        if (!obj->oFaceAnglePitch)
        {
            m->faceAngle[0] = -zaAngle;
            m->faceAngle[1] = cyl.theta - 0x4000;
            m->faceAngle[2] = 0x4000;
        }
        else
        {
            s16 lerpAngle = zaAngle;

            f32 lerpAmt0 = coss(lerpAngle);
            f32 lerpAmt2 = sins(lerpAngle);

            s16 angle = cyl.theta;
            int flip = 0;
            if (angle < -0x4000)
            {
                angle += 0x8000;
                flip = 1;
            }
            else if (angle > 0x4000)
            {
                angle -= 0x8000;
                flip = 1;
            }

            m->faceAngle[0] = lerpf(0, angle, lerpAmt0);
            m->faceAngle[1] = zaAngle - 0x4000 + obj->oFaceAngleYaw;
            m->faceAngle[2] = lerpf(0, angle, lerpAmt2);

#if 0
            static int style = 0;
            if (gPlayer1Controller->buttonPressed & L_TRIG)
            {
                style++;
            }

            if (flip)
            {
                if (style & 1)
                    m->faceAngle[0] = -m->faceAngle[0];
                if (style & 2)
                    m->faceAngle[2] = -m->faceAngle[2];
                if (style & 4)
                    m->faceAngle[0] = 0x8000+m->faceAngle[0];
                if (style & 8)
                    m->faceAngle[2] = 0x8000+m->faceAngle[2];
                if (style & 16)
                    m->faceAngle[1] = -m->faceAngle[1];
                if (style & 32)
                    m->faceAngle[1] = 0x8000+m->faceAngle[1];
            }
            print_text_fmt_int(20, 160, "S %d", style % 64);
            print_text_fmt_int(20, 20, "0 %d", m->faceAngle[0]);
            print_text_fmt_int(20, 40, "1 %d", m->faceAngle[1]);
            print_text_fmt_int(20, 60, "2 %d", m->faceAngle[2]);
            
            print_text_fmt_int(20, 80, "CT %d", cyl.theta);
            print_text_fmt_int(20, 100, "CTA %d", angle);
            print_text_fmt_int(20, 120, "LA0 %d", 10000 * lerpAmt0);
            print_text_fmt_int(20, 140, "LA2 %d", 10000 * lerpAmt2);
#else
            if (flip)
            {
                m->faceAngle[0] = -m->faceAngle[0];
                m->faceAngle[2] = 0x8000+m->faceAngle[2];
                m->faceAngle[1] = -m->faceAngle[1];
            }
#endif
        }
    }

    Vec3f vel_component_r;
    vec3_scale_dest(vel_component_r, x_axis_new, sCylVel.r);
    vec3_sum(m->vel, vel_component_r, vel_component_za);

    m->slideVelX = m->vel[0];
    m->slideVelZ = m->vel[2];
    m->forwardVel = sqrtf(sqr(m->vel[0]) + sqr(m->vel[2]));

    if (!in_tube(&cyl, IN_TUBE_R + 100.f, obj->oBehParams2ndByte))
    {
        if (obj->oFaceAnglePitch)
        {
            // If tube is rotated, it can be either still on the tube when cancelling the action,
            // Check for radius to handle that properly.
            type = cyl.r < 300.f ? FCGR_BREAK_LAND : FCGR_BREAK_AIR; 
        }
        else
        {
            // For vertical tube, always consider in the air.
            type = FCGR_BREAK_AIR;
        }
        sCylObj = NULL;
        sPanYOffset = 0.f;
        if (0 == obj->oFaceAnglePitch)
        {
            m->faceAngle[1] = atan2s(m->vel[2], m->vel[0]);
        }
        else
        {
            m->faceAngle[0] = 0;
            // we can inherit the yaw from the tube just fine
            //m->faceAngle[1] = atan2s(m->vel[2], m->vel[0]);
            m->faceAngle[2] = 0;
        }
    }

    m->extraGravityEnabled = 1;

    return type;
}

static int in_tube(const cyl_t* cyl, f32 lim, int len)
{
    f32 height = 1400.f + 1500.f * len;
    int z_ok = 0.f < cyl->z && cyl->z < height;
    int r_ok = cyl->r < lim;
    return z_ok && r_ok;
}

static void rotate_in_xz(Vec3f dst, Vec3f src, s16 yaw) {
    register f32 x = src[0];
    register f32 z = src[2];
    register f32 sy = sins(yaw);
    register f32 cy = coss(yaw);

    dst[0] = z * sy + x * cy;
    dst[1] = src[1];
    dst[2] = z * cy - x * sy;
}

static void rotate_in_yz(Vec3f dst, Vec3f src, s16 pitch) {
    f32 y = src[1];
    f32 z = src[2];
    f32 sp = sins(pitch);
    f32 cp = coss(pitch);

    dst[0] = src[0];
    dst[1] = z * sp + y * cp;
    dst[2] = z * cp - y * sp;
}

int fcgr_angle_overriden(s16 yaw, s16 marioAngle, f32* pan)
{
    if (sCylObj->oFaceAnglePitch)
    {
        pan[1] = 30.f;
        return 0;
        // laying on the ground, can follow the vanilla logic
        int parts = ((int) ((u16) (sCylPos.theta + 0x2000))) / 0x4000;
        {
            pan[0] = -pan[0];
            
            yaw = -yaw;

            Vec3f dir;
            rotate_in_yz(dir, pan, sZAAngle - 0x4000);
            rotate_in_xz(dir, dir, sCylObj->oFaceAngleYaw);
            rotate_in_xz(dir, dir, yaw);

            Vec3f pand = { 0, 0, 0 };
            // rotate_in_xz(pand, pan, sCylObj->oFaceAngleYaw + 0x4000);
            // rotate_in_xz(pand, pand, yaw);

            pan[0] = dir[0] / 2.f - pand[0];
            //approach_f32_asymptotic_bool(&sPanYOffset, -dir[1] / 2.f, 0.025f);
            //pan[1] = sPanYOffset;

            return 0;
        }
    }
    else
    {
        yaw = -yaw;

        Vec3f dir;
        rotate_in_yz(dir, pan, sZAAngle);
        rotate_in_xz(dir, dir, sCylPos.theta + 0x4000);
        rotate_in_xz(dir, dir, yaw);

        Vec3f pand;
        rotate_in_xz(pand, pan, sCylPos.theta);
        rotate_in_xz(pand, pand, yaw);

        pan[0] = -dir[0] / 2.f - pand[0];

        pan[0] *= 0.9f;
        pan[2] *= 0.9f;
        
        approach_f32_asymptotic_bool(&sPanYOffset, dir[1] / 2.f, 0.025f);
        pan[1] = sPanYOffset;
        return 1;
    }
}

int fcgr_override_posYoff(f32* posYOff, f32* focYoff)
{
    if (sCylObj->oFaceAnglePitch)
    {
        f32 mul = coss(sCylPos.theta);
        if (mul > 0)
        {
            *posYOff = lerpf(0.f, -150.f, 1.f - mul);
            *focYoff = -200.f * (1.f - mul);
        }
        else
        {
            *posYOff *= -10.f * (mul - 0.2f);
            *focYoff = -200.f;
        }
    }

    return 0;
}
