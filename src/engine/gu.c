#include "gut.h"

#include "math_util.h"

static ALIGNED16 const Mtx kIdentityMatrixS16 = { { { 0x00010000, 0x00000000, 0x00000001, 0x00000000 },
                                                   { 0x00000000, 0x00010000, 0x00000000, 0x00000001 },

                                                   { 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
                                                   { 0x00000000, 0x00000000, 0x00000000, 0x00000000 } } };
 

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

extern u16 guPerspectiveA(Mtx *m, u16 fovy, float aspect, float near, float far, float scale)
{
    const float gscale = 65536.f;
    scale *= gscale;

    bzero4(m, sizeof(kIdentityMatrixS16));
	float cot = coss (fovy/2) / sins (fovy/2);
    
    s16* AsS16P = m;

	f32 mf00 = cot / aspect * scale;
	f32 mf11 = cot * scale;
	f32 mf22 = (near + far) / (near - far) * scale;
	f32 mf23 = -scale;
	f32 mf32 = (2 * near * far) / (near - far) * scale;

    s32 mi00 = (s32)mf00;
    s32 mi11 = (s32)mf11;
    s32 mi22 = (s32)mf22;
    s32 mi23 = (s32)mf23;
    s32 mi32 = (s32)mf32;

    AsS16P[0] = mi00 >> 16;
    AsS16P[5] = mi11 >> 16;
    AsS16P[10] = mi22 >> 16;
    AsS16P[11] = mi23 >> 16;
    AsS16P[14] = mi32 >> 16;

    AsS16P[0+16] = mi00;
    AsS16P[5+16] = mi11;
    AsS16P[10+16] = mi22;
    AsS16P[11+16] = mi23;
    AsS16P[14+16] = mi32;

    u16 perspNorm;
    if (near+far<=2.0f) {
		perspNorm = (u16) 0xFFFF;
    } else {
		perspNorm = (u16) ((2.0f*65536.0f)/(near+far));
		if (perspNorm<=0) 
		    perspNorm = (u16) 0x0001;
    }

    return perspNorm;
}

#if 1
void guOrtho(Mtx *m, float l, float r, float b, float t, float n, float f, float scale)
{
    bzero4(m, sizeof(kIdentityMatrixS16) - 2*4);

    const float gscale = 65536.f;
    scale *= gscale;

	f32 mf00 = 2/(r-l)*scale;
	f32 mf11 = 2/(t-b)*scale;
	f32 mf22 = -2/(f-n)*scale;
	f32 mf30 = -(r+l)/(r-l)*scale;
	f32 mf31 = -(t+b)/(t-b)*scale;
	f32 mf32 = -(f+n)/(f-n)*scale;
	f32 mf33 = scale;

    s32 mi00 = (s32)mf00;
    s32 mi11 = (s32)mf11;
    s32 mi22 = (s32)mf22;
    s32 mi30 = (s32)mf30;
    s32 mi31 = (s32)mf31;
    s32 mi32 = (s32)mf32;
    s32 mi33 = (s32)mf33;

    s16* AsS16P = m;

    AsS16P[0] = mi00 >> 16;
    AsS16P[5] = mi11 >> 16;
    AsS16P[10] = mi22 >> 16;
    AsS16P[12] = mi30 >> 16;
    AsS16P[13] = mi31 >> 16;
    AsS16P[14] = mi32 >> 16;
    AsS16P[15] = mi33 >> 16;

    AsS16P[0+16] = mi00;
    AsS16P[5+16] = mi11;
    AsS16P[10+16] = mi22;
    AsS16P[12+16] = mi30;
    AsS16P[13+16] = mi31;
    AsS16P[14+16] = mi32;
    AsS16P[15+16] = mi33;
}
#endif