int succ_within_region()
{
    if (1 == o->oBehParams2ndByte)
        return -4000.f  < gMarioStates->pos[2] && gMarioStates->pos[2] < -500.f   && -15500.f < gMarioStates->pos[0] && gMarioStates->pos[0] < -8300.f;
    if (2 == o->oBehParams2ndByte)
        return -3300.f  < gMarioStates->pos[2] && gMarioStates->pos[2] < -500.f   && -15000.f < gMarioStates->pos[0] && gMarioStates->pos[0] < -18000.f;
    if (3 == o->oBehParams2ndByte)
        return -4000.f  < gMarioStates->pos[2] && gMarioStates->pos[2] < -500.f   && -21000.f < gMarioStates->pos[0] && gMarioStates->pos[0] < -17800.f;
    if (4 == o->oBehParams2ndByte)
        return -18000.f < gMarioStates->pos[0] && gMarioStates->pos[0] < -15000.f && -17500.f < gMarioStates->pos[2] && gMarioStates->pos[2] < -11500.f;
    if (5 == o->oBehParams2ndByte)
        return  15500.f < gMarioStates->pos[0] && gMarioStates->pos[0] <  25000.f &&   6500.f < gMarioStates->pos[2] && gMarioStates->pos[2] < 9500.f;
    if (6 == o->oBehParams2ndByte)
        return -18000.f < gMarioStates->pos[0] && gMarioStates->pos[0] < -15000.f &&   6500.f < gMarioStates->pos[2] && gMarioStates->pos[2] < 9500.f;
    if (7 == o->oBehParams2ndByte)
        return   8000.f < gMarioStates->pos[0] && gMarioStates->pos[0] < 11000.f && -11500.f < gMarioStates->pos[2] && gMarioStates->pos[2] < -4500.f;
    if (8 == o->oBehParams2ndByte)
        return   8000.f < gMarioStates->pos[0] && gMarioStates->pos[0] < 11000.f &&  10000.f < gMarioStates->pos[2] && gMarioStates->pos[2] < 21000.f;

    return 0;
}

void bhv_succ_loop()
{
    if (!succ_within_region())
    {
        return;
    }

    {
        f32 size = 30.f;
        f32 sizeBase = size;
        f32 sizeRange = size / 20.f;
        f32 forwardVelBase = 40.f;
        f32 forwardVelRange = 5.f;
        f32 velYBase = -30.f;
        f32 velYRange = 20.f;
    
        f32 scale = random_float() * (sizeRange * 0.1f) + sizeBase * 0.1f;
        struct Object* particle = spawn_object(o, MODEL_MIST, bhvWhitePuffExplosion);
    
        particle->oBehParams2ndByte = 2;
        particle->oMoveAngleYaw = GET_BPARAM1(o->oBehParams) ? random_u16() : o->oFaceAngleYaw;
        particle->oGravity = 2.52f;
        particle->oDragStrength = 1.0f;
        particle->oForwardVel = random_float() * forwardVelRange + forwardVelBase;
        f32 rangeWide = random_f32_around_zero(500.f);
        f32 rangeShort = random_f32_around_zero(500.f);
        particle->oPosX = o->oPosX + rangeWide * coss(o->oFaceAngleYaw) + rangeShort * sins(o->oFaceAngleYaw);
        particle->oPosY = o->oPosY;
        particle->oPosZ = o->oPosZ + rangeWide * sins(o->oFaceAngleYaw) + rangeShort * coss(o->oFaceAngleYaw);
        particle->oVelY = random_float() * velYRange + velYBase;
    
        obj_scale(particle, scale);
    }

    f32 dx = o->oPosX - gMarioStates->pos[0];
    f32 dz = o->oPosZ - gMarioStates->pos[2];
    f32 dist = sqrtf(dx * dx + dz * dz);
    if (dist > 100.f)
    {
        dx /= dist;
        dz /= dist;

        f32 dist = sqrtf(o->oDistanceToMario);
        f32 mult = 200.f / dist;
        dx *= mult;
        dz *= mult;

        gMarioStates->pos[0] += dx;
        gMarioStates->pos[2] += dz;
    }
}
