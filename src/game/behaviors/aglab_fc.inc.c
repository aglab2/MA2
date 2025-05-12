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
static int in_tube(const cyl_t* cyl, f32 lim, int len);

static cyl_t sCylVel;

void bhv_fc_grav_loop()
{
    if (gMarioStates->action == ACT_FCGR_WALKING || gMarioStates->action == ACT_FCGR_JUMP)
    {
        return;
    }

    Vec3f x_axis, y_axis, z_axis;
    gen_axis(x_axis, y_axis, z_axis, o->oFaceAngleYaw, o->oFaceAnglePitch);

    cyl_t cyl = to_cyl(gMarioStates[0].pos, &o->oPosVec, x_axis, y_axis, z_axis);

    if (in_tube(&cyl, 800.f, o->oBehParams2ndByte))
    {
        drop_and_set_mario_action(gMarioStates, ACT_FCGR_JUMP, 0);   
        gMarioStates->usedObj = o;
        sCylVel = to_cyl_vec(gMarioStates->vel, x_axis, y_axis, z_axis);
        sCylVel.theta = 0.f;
        sCylVel.r = -sCylVel.r;
        if (sCylVel.r < 0)
            sCylVel.r = 0.f;
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

#define FCGR_CONTINUE 0
#define FCGR_LAND 1
#define FCGR_BREAK 2

int fcgr_spin(struct MarioState *m)
{
    int type = FCGR_CONTINUE;

    // spin around the 'usedObj' object around the axis of the object
    struct Object *obj = m->usedObj;

    Vec3f x_axis, y_axis, z_axis;
    gen_axis(x_axis, y_axis, z_axis, obj->oFaceAngleYaw, obj->oFaceAnglePitch);

    // apply gravity
    int landed = m->action == ACT_FCGR_WALKING;
    if (landed && (m->input & INPUT_A_PRESSED))
    {
        sCylVel.r = 50.f;
    }

    if (landed)
    {
        sCylVel.z = sCylVel.z * 0.2f;
        sCylVel.theta = sCylVel.theta * 0.97f;
        if (obj->oFaceAnglePitch)
        {
            s16 diff = m->intendedYaw - obj->oFaceAngleYaw;
            sCylVel.z += m->intendedMag * coss(diff) * 0.8f;
            sCylVel.theta -= m->intendedMag * sins(diff) * 1.5f;
        }
        else
        {
            sCylVel.z += m->controller->stickY * 0.4f;
            sCylVel.theta += m->controller->stickX * 0.9f;
        }
    }

    f32 rvel = (m->input & INPUT_A_DOWN) ? 1.5f : 4.f;
    sCylVel.r -= rvel;

    // apply position relative to the object
    cyl_t cyl = to_cyl(m->pos, &obj->oPosVec, x_axis, y_axis, z_axis);
    cyl.theta += sCylVel.theta;
    cyl.z += sCylVel.z;
    cyl.r += sCylVel.r;

    if (!obj->oFaceAnglePitch)
    {
        m->faceAngle[0] = 0;
        m->faceAngle[1] = cyl.theta - 0x4000;
        m->faceAngle[2] = 0x4000;
        if (sCylVel.theta < 0)
        {
            m->faceAngle[1] += 0x8000;
            m->faceAngle[2] += 0x8000;
        }
    }
    else
    {
        m->faceAngle[0] = 0;
        m->faceAngle[1] = obj->oFaceAngleYaw;
        m->faceAngle[2] = cyl.theta;
        if (sCylVel.z < 0)
        {
            m->faceAngle[1] += 0x8000;
            m->faceAngle[2] += 0x8000;
        }
    }

    if (cyl.r < 280.f)
    {
        cyl.r = 280.f;
        sCylVel.r = 0.f;
        type = FCGR_LAND;
    }

    if (!in_tube(&cyl, 900.f, obj->oBehParams2ndByte))
    {
        type = FCGR_BREAK;
        if (0 == obj->oFaceAnglePitch)
        {
            m->faceAngle[1] = -0x8000 + cyl.theta;
        }
    }

    to_xyz(m->pos, &obj->oPosVec, x_axis, y_axis, z_axis, cyl);
    to_xyz_vec(m->vel, x_axis, y_axis, z_axis, sCylVel);
    m->slideVelX = m->vel[0];
    m->slideVelZ = m->vel[2];
    m->forwardVel = sqrtf(sqr(m->vel[0]) + sqr(m->vel[2]));

    print_text_fmt_int(20, 20, "0 %d", (int) m->faceAngle[0]); 
    print_text_fmt_int(20, 40, "1 %d", (int)m->faceAngle[1]);
    print_text_fmt_int(20, 60, "2 %d", (int) m->faceAngle[2]);

    return type;
}

static int in_tube(const cyl_t* cyl, f32 lim, int len)
{
    f32 height = 1400.f + 1500.f * len;
    int z_ok = 100.f < cyl->z && cyl->z < height;
    int r_ok = cyl->r < lim;
    return z_ok && r_ok;
}
