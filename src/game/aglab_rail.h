#pragma once

#include "types.h"

int zipline_cancel();

typedef int (*rail_valid_fn)(void* ctx, f32 cx, f32 cy, f32 cz);

// Mind that 'range' accepted here must be squared
int do_zipline_cancel(f32 range, rail_valid_fn fn, void* ctx, f32* closestPoint);
int zipline_step(int exSpeed, s16* extraTilt, int holdZ);
int zipline_on_loop();

// normalized vector that is perpendicular to the zipline direction matching Mario's tilt
typedef struct {
    Vec2f v;
} zipline_tilt_t;

int zipline_get_tilt(zipline_tilt_t* tilt);
