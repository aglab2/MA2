#include "sm64.h"

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
 
void guTranslate(Mtx* m, float x, float y, float z) {
    memcpy4(m, &kIdentityMatrixS16, 0x38);
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
    AsS16P[28] = x_int;
    AsS16P[29] = y_int;
    AsS16P[30] = z_int;
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
