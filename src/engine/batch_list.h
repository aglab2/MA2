#pragma once

#include "sm64.h"
#include "engine/graph_node.h"

struct BatchArray* batch_list_objects_alloc_opaque();
struct BatchArray* batch_list_objects_alloc_alpha();

static inline struct BatchArray* batch_list_objects_alloc(enum RenderLayers layer)
{
    switch (layer)
    {
        case LAYER_ALPHA:
            return batch_list_objects_alloc_alpha();
        default:
            return 0;
    }
}
