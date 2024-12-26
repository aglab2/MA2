#include "batch_list.h"

#include "actors/common1.h"
#include "game/segment2.h"

static const Gfx* sCoinsTextureDls[] = {
    dl_coin_0,
    dl_coin_22_5,
    dl_coin_45,
    dl_coin_67_5,
    dl_coin_90,
};

extern const Gfx breakable_box_seg8_dl_cork_box_init[];
extern const Gfx breakable_box_seg8_dl_cork_box_end[];

extern Gfx burn_smoke_seg4_sub_dl_begin_translucent[];
extern Gfx burn_smoke_seg4_sub_dl_begin_alpha[];
extern const Gfx burn_smoke_seg4_sub_dl_end[];

extern const Gfx dl_shadow_circle_end[];

extern const Gfx mist_dl[];
extern const Gfx mist_dl_end[];

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
    {
        struct Batch* batch = &batchesArr->batches[LAYER_ALPHA_SMOKE];
        batch->startDl = burn_smoke_seg4_sub_dl_begin_alpha;
        batch->endDl = burn_smoke_seg4_sub_dl_end;
    }

    return batchesArr;
}

struct BatchArray* batch_list_objects_alloc_xlu()
{
    struct BatchArray* batchesArr = batch_array_alloc(LAYER_TRANSPARENT_BATCHES_COUNT);
    {
        struct Batch* batch = &batchesArr->batches[LAYER_TRANSPARENT_SMOKE];
        batch->startDl = burn_smoke_seg4_sub_dl_begin_translucent;
        batch->endDl   = burn_smoke_seg4_sub_dl_end;
    }
    {
        struct Batch* batch = &batchesArr->batches[LAYER_TRANSPARENT_MIST];
        batch->startDl = mist_dl;
        batch->endDl   = mist_dl_end;
    }
    return batchesArr;
}

struct BatchArray* batch_list_objects_alloc_xlu_decal()
{
    struct BatchArray* batchesArr = batch_array_alloc(LAYER_TRANSPARENT_DECAL_BATCHES_COUNT);
    {
        struct Batch* batch = &batchesArr->batches[LAYER_TRANSPARENT_DECAL_SHADOW_CIRCLE];
        batch->startDl = dl_shadow_circle;
        batch->endDl   = dl_shadow_circle_end;
    }
    return batchesArr;
}

struct BatchArray* batch_list_objects_alloc_cld()
{
    struct BatchArray* batchesArr = batch_array_alloc(LAYER_CLD_BATCHES_COUNT);
    {
        struct Batch* batch = &batchesArr->batches[LAYER_CLD_SHADOW_CIRCLE];
        batch->startDl = dl_shadow_circle;
        batch->endDl   = dl_shadow_circle_end;
    }
    return batchesArr;
}
