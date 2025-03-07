#include "gut.h"

#include "math_util.h"

static ALIGNED16 const Mtx kIdentityMatrixS16 = { { { 0x00010000, 0x00000000, 0x00000001, 0x00000000 },
                                                   { 0x00000000, 0x00010000, 0x00000000, 0x00000001 },

                                                   { 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
                                                   { 0x00000000, 0x00000000, 0x00000000, 0x00000000 } } };
 

// requires 4 bytes alignment and an n that is a multiple of 8!
static ALWAYS_INLINE void memcpy4(void* dst, void* src, int n)
{
    unsigned int* dst_u32 = (unsigned int*)dst;
    unsigned int* src_u32 = (unsigned int*)src;
    unsigned int* end_u32 = ((unsigned int*)src) + (n / 4); // compiler optimizes the div out
 
    while (end_u32 != src_u32) {
        *dst_u32 = *src_u32;
        dst_u32++;
        src_u32++;
        n -= 4;
    }
}
 
/*
[ 1, 0, 0, 0 ]
[ 0, 1, 0, 0 ]
[ 0, 0, 1, 0 ]
[ x, y, z, 1 ]
*/
void guTranslate(Mtx* m, float x, float y, float z) {
    memcpy4(m, &kIdentityMatrixS16, sizeof(kIdentityMatrixS16) - 2 * 4);
    const float scale = 65536.f;
    s16* AsS16P = m;
    float x_scaled = x * scale;
    float y_scaled = y * scale;
    float z_scaled = z * scale;
    s32 x_int = (s32)x_scaled;
    s32 y_int = (s32)y_scaled;
    s32 z_int = (s32)z_scaled;
 
    AsS16P[12] = x_int >> 16;
    AsS16P[13] = y_int >> 16;
    AsS16P[14] = z_int >> 16;

    AsS16P[16+12] = x_int;
    AsS16P[16+13] = y_int;
    AsS16P[16+14] = z_int;

    // because copy on memcpy4 was not done completely
    AsS16P[16+15] = 0;
}

static ALWAYS_INLINE void bzero4(void* dst, int n)
{
    unsigned int* dst_u32 = (unsigned int*)dst;
    unsigned int* end_u32 = ((unsigned int*)dst) + (n / 4); // compiler optimizes the div out
 
    while (end_u32 != dst_u32) {
        *dst_u32 = 0;
        dst_u32++;
        n -= 4;
    }
}

/*
[ x, 0, 0, 0 ]
[ 0, y, 0, 0 ]
[ 0, 0, z, 0 ]
[ 0, 0, 0, 1 ]
*/
void guScale(Mtx* m, float x, float y, float z)
{
    bzero4(m, sizeof(kIdentityMatrixS16));
    const float scale = 65536.f;
    s16* AsS16P = m;
    float x_scaled = x * scale;
    float y_scaled = y * scale;
    float z_scaled = z * scale;
    s32 x_int = (s32)x_scaled;
    s32 y_int = (s32)y_scaled;
    s32 z_int = (s32)z_scaled;

    AsS16P[0] = x_int >> 16;
    AsS16P[5] = y_int >> 16;
    AsS16P[10] = z_int >> 16;
    AsS16P[15] = 1;

    AsS16P[16] = x_int;
    AsS16P[21] = y_int;
    AsS16P[26] = z_int;
}

/*
[ 1, 0, 0, 0 ]
[ 0, c, s, 0 ]
[ 0,-s, c, 0 ]
[ 0, 0, 0, 1 ]
*/

void guRotateX(Mtx* m, u16 a)
{
    memcpy4(m, &kIdentityMatrixS16, sizeof(kIdentityMatrixS16));
    const float scale = 65536.f;
    s16* AsS16P = m;
    f32 s = sins(a);
    f32 c = coss(a);

    f32 s_scaled = s * scale;
    f32 c_scaled = c * scale;

    s32 s_int = (s32)s_scaled;
    s32 c_int = (s32)c_scaled;

    AsS16P[5] = c_int >> 16;
    AsS16P[6] = s_int >> 16;
    AsS16P[9] = -s_int >> 16;
    AsS16P[10] = c_int >> 16;

    AsS16P[5+16] = c_int;
    AsS16P[6+16] = s_int;
    AsS16P[9+16] = -s_int;
    AsS16P[10+16] = c_int;
}

/*
[ c, 0,-s, 0 ]
[ 0, 1, 0, 0 ]
[ s, 0, c, 0 ]
[ 0, 0, 0, 1 ]
*/
void guRotateY(Mtx* m, u16 a)
{
    memcpy4(m, &kIdentityMatrixS16, sizeof(kIdentityMatrixS16));
    const float scale = 65536.f;
    s16* AsS16P = m;
    f32 s = sins(a);
    f32 c = coss(a);

    f32 s_scaled = s * scale;
    f32 c_scaled = c * scale;

    s32 s_int = (s32)s_scaled;
    s32 c_int = (s32)c_scaled;

    AsS16P[0] = c_int >> 16;
    AsS16P[2] = -s_int >> 16;
    AsS16P[8] = s_int >> 16;
    AsS16P[10] = c_int >> 16;

    AsS16P[0+16] = c_int;
    AsS16P[2+16] = -s_int;
    AsS16P[8+16] = s_int;
    AsS16P[10+16] = c_int;
}

void guRotateYF(float mf[4][4], u16 a)
{
    bzero4(mf, 4*4*4 - 4);
    f32 s = sins(a);
    f32 c = coss(a);

    mf[0][0] = c;
    mf[2][2] = c;
    mf[0][2] = -s;
    mf[2][0] = s;
    mf[1][1] = 1.f;
    mf[3][3] = 1.f;
}

/*
[ c, s, 0, 0 ]
[-s, c, 0, 0 ]
[ 0, 0, 1, 0 ]
[ 0, 0, 0, 1 ]
*/
void guRotateZ(Mtx* m, u16 a)
{
    memcpy4(((u32*)m) + 1, ((u32*) &kIdentityMatrixS16) + 1, sizeof(kIdentityMatrixS16) - 4);
    const float scale = 65536.f;
    s16* AsS16P = m;
    f32 s = sins(a);
    f32 c = coss(a);

    f32 s_scaled = s * scale;
    f32 c_scaled = c * scale;

    s32 s_int = (s32)s_scaled;
    s32 c_int = (s32)c_scaled;

    AsS16P[0] = c_int >> 16;
    AsS16P[1] = s_int >> 16;
    AsS16P[4] = -s_int >> 16;
    AsS16P[5] = c_int >> 16;

    AsS16P[0+16] = c_int;
    AsS16P[1+16] = s_int;
    AsS16P[4+16] = -s_int;
    AsS16P[5+16] = c_int;
}
