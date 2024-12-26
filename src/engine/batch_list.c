#include "batch_list.h"

#include "actors/common1.h"

static const Gfx* sCoinsTextureDls[] = {
    dl_coin_0,
    dl_coin_22_5,
    dl_coin_45,
    dl_coin_67_5,
    dl_coin_90,
};

static inline struct BatchArray* batch_array_alloc(int count)
{
    struct BatchArray* batches = main_pool_alloc(sizeof(struct BatchArray) + count * sizeof(struct Batch));
    batches->count = count;
    return batches;
}

struct BatchArray* batch_list_objects_alloc_opaque()
{
    struct BatchArray* batches = batch_array_alloc(LAYER_OPAQUE_BATCHES_COUNT);
    return batches;
}

struct BatchArray* batch_list_objects_alloc_alpha()
{
    struct BatchArray* batches = batch_array_alloc(LAYER_ALPHA_BATCHES_COUNT);
    for (int batchIdx = LAYER_ALPHA_COIN_0; batchIdx <= LAYER_ALPHA_COIN_4; batchIdx++)
    {
        struct Batch* batch = &batches->batches[batchIdx];
        batch->startDl = sCoinsTextureDls[batchIdx - LAYER_ALPHA_BATCHES_BASE];
        batch->endDl = dl_coin_end;
    }

    return batches;
}
