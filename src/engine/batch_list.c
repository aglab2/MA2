#include "batch_list.h"

#include "actors/common1.h"

static const Gfx* sCoinsTextureDls[] = {
    dl_coin_0,
    dl_coin_22_5,
    dl_coin_45,
    dl_coin_67_5,
    dl_coin_90,
};

extern const Gfx breakable_box_seg8_dl_cork_box_init[];
extern const Gfx breakable_box_seg8_dl_cork_box_end[];

static inline struct BatchArray* batch_array_alloc(int count)
{
    struct BatchArray* batches = main_pool_alloc(sizeof(struct BatchArray) + count * sizeof(struct Batch));
    batches->count = count;
    return batches;
}

struct BatchArray* batch_list_objects_alloc_opaque()
{
    struct BatchArray* batchesArr = batch_array_alloc(LAYER_OPAQUE_BATCHES_COUNT);
    {
        struct Batch* batch = &batchesArr->batches[LAYER_OPAQUE_CORKBOX];
        batch->startDl = breakable_box_seg8_dl_cork_box_init;
        batch->endDl   = breakable_box_seg8_dl_cork_box_end;
    }
    return batchesArr;
}

struct BatchArray* batch_list_objects_alloc_alpha()
{
    struct BatchArray* batchesArr = batch_array_alloc(LAYER_ALPHA_BATCHES_COUNT);
    for (int batchIdx = LAYER_ALPHA_COIN_0; batchIdx <= LAYER_ALPHA_COIN_4; batchIdx++)
    {
        struct Batch* batch = &batchesArr->batches[batchIdx];
        batch->startDl = sCoinsTextureDls[batchIdx - LAYER_ALPHA_BATCHES_BASE];
        batch->endDl = dl_coin_end;
    }

    return batchesArr;
}
