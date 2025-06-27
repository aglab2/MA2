#pragma once

#include "rail_desc.h"
#include "spring_desc.h"
#include "instant_warp_desc.h"

struct LevelConfig
{
    f32 viewRangeMult;
    const RailDesc** railDesc;
    const Gfx* skybox;
    const SpringDesc** springDescs;
    const SpringLinkDesc* springLinks;
    const IWDHeader** iwds;
};
