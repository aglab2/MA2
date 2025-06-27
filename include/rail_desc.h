#pragma once

// Loop Deloop will perform a loop around the given point
// Rail code is reused for this while calculating the midpoint of the loop
// From midpoint, angles are calculated to mario's angle
typedef struct
{
    // offset that will be added to mario face angle during the progression
    s16 angleOffset;
    u8 dontFlip;
    u8 canSnapBackwards;
} LDLDesc;

typedef struct _RailDesc
{
    const Trajectory* rail;
    // If !loop, will be NULL
    LDLDesc* loop;
} RailDesc;

#define RAIL_TRAJ(tr) { tr, NULL }
#define LOOP_TRAJ(tr, l) { tr, l }
#define RAIL_END { NULL, NULL }
