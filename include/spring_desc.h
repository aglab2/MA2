#pragma once

typedef struct
{
    const Trajectory* bezier;
} SpringDesc;

typedef struct
{
    const Trajectory* from;
    const Trajectory* to;
} SpringLinkDesc;
