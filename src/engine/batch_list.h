#pragma once

#include "sm64.h"
#include "engine/graph_node.h"

struct BatchArray* batch_list_objects_alloc_opaque();
struct BatchArray* batch_list_objects_alloc_alpha();
struct BatchArray* batch_list_objects_alloc_xlu();
struct BatchArray* batch_list_objects_alloc_xlu_decal();
struct BatchArray* batch_list_objects_alloc_cld();

static inline struct BatchArray* batch_list_objects_alloc(enum RenderLayers layer)
{
    switch (layer)
    {
        case LAYER_ALPHA:
            return batch_list_objects_alloc_alpha();
        case LAYER_OPAQUE:
            return batch_list_objects_alloc_opaque();
        case LAYER_TRANSPARENT:
            return batch_list_objects_alloc_xlu();
        case LAYER_TRANSPARENT_DECAL:
            return batch_list_objects_alloc_xlu_decal();
        case LAYER_CLD:
            return batch_list_objects_alloc_cld();
        default:
            return 0;
    }
}
