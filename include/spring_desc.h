#pragma once

typedef struct _SpringDesc
{
    const Trajectory* bezier;
} SpringDesc;

typedef struct _SpringLinkDesc
{
    const Trajectory* from;
    const Trajectory* to;
} SpringLinkDesc;
