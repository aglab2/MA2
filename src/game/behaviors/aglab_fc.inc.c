#include "game/fcgr.h"

typedef struct {
    float r;
    float z;
    s16 theta;
} cyl_t;

static cyl_t to_cyl(const Vec3f point, const Vec3f start, const Vec3f x_axis, const Vec3f y_axis, const Vec3f z_axis);
static cyl_t to_cyl_vec(const Vec3f rel, const Vec3f x_axis, const Vec3f y_axis, const Vec3f z_axis);
static void to_xyz(Vec3f point, const Vec3f start, const Vec3f x_axis, const Vec3f y_axis, const Vec3f z_axis, cyl_t cyl);
static void to_xyz_vec(Vec3f point, const Vec3f x_axis, const Vec3f y_axis, const Vec3f z_axis, cyl_t cyl);
static void gen_axis(Vec3f x_axis, Vec3f y_axis, Vec3f z_axis, s16 yaw, s16 pitch);
static void gen_axis_point_oriented(Vec3f x_axis_new, Vec3f y_axis_new, const Vec3f x_axis, const Vec3f y_axis, const Vec3f z_axis, const s16 theta);
static int in_tube(const cyl_t* cyl, f32 lim, int len);

static cyl_t sCylVel;
static s16 sCylArea;

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
        gMarioStates->usedObj = o;
        sCylArea = gCurrAreaIndex;

        // For velocity conversion, we cannot use generic 'to_cyl' function because
        // angular speed depends on the location of the object, not just the velocity.

        // We are performing the transformation manually, similarly to the 'to_cyl_vec' function

        Vec3f x_axis_new;
        Vec3f y_axis_new;
        gen_axis_point_oriented(x_axis_new, y_axis_new, x_axis, y_axis, z_axis, cyl.theta);

        // Our choice of x_axis_new and y_axis_new is such that the 'r' value is the distance from the object to the pole...
        sCylVel.z = vec3_dot(gMarioStates->vel, z_axis);
        sCylVel.r = vec3_dot(gMarioStates->vel, x_axis_new);
        // ... and the 'theta' is angular speed around the pole projected on 'y_axis_new'
        // mind that angular speed is in radians, so we need to convert it to mario degrees
        sCylVel.theta = vec3_dot(gMarioStates->vel, y_axis_new) / cyl.r / M_PI * 0x10000;
    }
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

int fcgr_spin(struct MarioState *m)
{
    if (gCurrAreaIndex != sCylArea)
    {
        m->usedObj = NULL;
        return FCGR_BREAK_AIR;
    }

    int type = FCGR_CONTINUE;

    // spin around the 'usedObj' object around the axis of the object
    struct Object *obj = m->usedObj;

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
    if (landed)
    {
        if (obj->oFaceAnglePitch)
        {
            s16 diff = m->intendedYaw - obj->oFaceAngleYaw;
            sCylVel.z += m->intendedMag * coss(diff) * 0.05f * 1.5f;
            sCylVel.theta -= m->intendedMag * sins(diff) * 0.8f * 3.f;
        }
        else
        {
            sCylVel.z += m->controller->stickY * 0.04f;
            sCylVel.theta += m->controller->stickX * 1.f;
        }
    }

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

    to_xyz(m->pos, &obj->oPosVec, x_axis, y_axis, z_axis, cyl);

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
    s16 zaAngle = atan2s(angularVel, sCylVel.z);

    if (!obj->oFaceAnglePitch)
    {
        m->faceAngle[0] = 0;
        if (za_forwardVel < 0.1f)
            m->faceAngle[1] = cyl.theta - 0x4000;
        else
            m->faceAngle[1] = atan2s(vel_component_za[2], vel_component_za[0]);
        
        f32 mult = sCylVel.theta < 0 ? 0.5f : -0.5f;
        if (za_forwardVel < 0.1f && absf(vel_component_za[1]) < 0.1f)
            m->faceAngle[2] = 0x4000 + mult * atan2s(za_forwardVel, vel_component_za[1]);
        else
            m->faceAngle[2] = 0x4000;

        if (sCylVel.theta < 0)
        {
            m->faceAngle[2] += 0x8000;
        }
    }
    else
    {
        int parts = ((int) ((u16) (cyl.theta + 0x2000))) / 0x4000;
        int mult = obj->oFaceAngleYaw ? -1 : 1;
        switch (parts)
        {
            case 0:
            {
                m->faceAngle[0] = cyl.theta;
                m->faceAngle[1] = zaAngle - 0x4000 + obj->oFaceAngleYaw;
                m->faceAngle[2] = 0;
            }
            break;
            case 1:
            {
                m->faceAngle[0] = -mult * zaAngle + 0x4000;
                m->faceAngle[1] = -obj->oFaceAngleYaw;
                m->faceAngle[2] = 0x4000;
            }
            break;
            case 2:
            {
                m->faceAngle[0] = cyl.theta;
                m->faceAngle[1] = -zaAngle - 0x4000 + obj->oFaceAngleYaw;
                m->faceAngle[2] = 0;
            }
            break;
            case 3:
            {
                m->faceAngle[0] = -mult * zaAngle - 0x4000;
                m->faceAngle[1] = obj->oFaceAngleYaw;
                m->faceAngle[2] = -0x4000;
            }
            break;
        }
    }

    Vec3f vel_component_r;
    vec3_scale_dest(vel_component_r, x_axis_new, sCylVel.r);
    vec3_sum(m->vel, vel_component_r, vel_component_za);

    m->slideVelX = m->vel[0];
    m->slideVelZ = m->vel[2];
    m->forwardVel = sqrtf(sqr(m->vel[0]) + sqr(m->vel[2]));

    print_text_fmt_int(20, 20, "0 %d", (int) m->vel[0]);
    print_text_fmt_int(20, 40, "1 %d", (int) m->vel[1]);
    print_text_fmt_int(20, 60, "2 %d", (int) m->vel[2]);

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
        m->usedObj = NULL;
        if (0 == obj->oFaceAnglePitch)
        {
            m->faceAngle[1] = atan2s(m->vel[2], m->vel[0]);
        }
        else
        {
            m->faceAngle[0] = 0;
            m->faceAngle[1] = atan2s(m->vel[2], m->vel[0]);
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
