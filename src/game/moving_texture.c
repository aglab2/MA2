#include <ultra64.h>

#include "sm64.h"
#include "moving_texture.h"
#include "area.h"
#include "camera.h"
#include "rendering_graph_node.h"
#include "engine/math_util.h"
#include "memory.h"
#include "save_file.h"
#include "segment2.h"
#include "engine/surface_collision.h"
#include "geo_misc.h"
#include "rendering_graph_node.h"
#include "object_list_processor.h"

/// The height at which Mario entered the last painting. Used for Wet-Dry World only.
float gPaintingMarioYEntry = 0.0f;

/// Variable to ensure the initial Wet-Dry World water level is set only once
s32 gWdwWaterLevelSet = FALSE;

/**
 * Sets the initial water level in Wet-Dry World based on how high Mario
 * jumped into the painting.
 */
Gfx *geo_wdw_set_initial_water_level(s32 callContext, UNUSED struct GraphNode *node, UNUSED Mat4 mtx) {
    s32 i;
    s16 wdwWaterHeight;

    // Why was this global variable needed when they could just check for GEO_CONTEXT_AREA_LOAD?
    if (callContext != GEO_CONTEXT_RENDER) {
        gWdwWaterLevelSet = FALSE;
    } else if (callContext == GEO_CONTEXT_RENDER && gEnvironmentRegions != NULL
               && !gWdwWaterLevelSet) {
        if (gPaintingMarioYEntry <= 1382.4f) {
            wdwWaterHeight = 31;
        } else if (gPaintingMarioYEntry >= 1600.0f) {
            wdwWaterHeight = 2816;
        } else {
            wdwWaterHeight = 1024;
        }
        for (i = 0; i < *gEnvironmentRegions; i++) {
            gEnvironmentRegions[i * 6 + 6] = wdwWaterHeight;
        }
        gWdwWaterLevelSet = TRUE;
    }
    return NULL;
}
