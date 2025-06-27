#include "level_table.h"
#include "config.h"
#include "rail_desc.h"
#include "spring_desc.h"
#include "instant_warp_desc.h"

struct LevelConfigA
{
    f32 viewRangeMult;
    const RailDesc** railDesc;
    const Gfx* skybox;
    const SpringDesc** springDescs;
    const SpringLinkDesc* springLinks;
    const IWDHeader** iwds;
};
