#include "batch_list.h"

#include "actors/common1.h"
#include "game/segment2.h"

extern const Gfx breakable_box_seg8_dl_cork_box_init[];
extern const Gfx breakable_box_seg8_dl_cork_box_end[];

extern Gfx burn_smoke_seg4_sub_dl_begin_translucent[];
extern Gfx burn_smoke_seg4_sub_dl_begin_alpha[];
extern const Gfx burn_smoke_seg4_sub_dl_end[];

extern const Gfx dl_shadow_circle_end[];

extern const Gfx mist_dl[];
extern const Gfx mist_dl_end[];

static inline struct BatchArray* batch_array_alloc(int count, const struct BatchDisplayLists* dls)
{
    struct BatchArray* batches = main_pool_alloc(sizeof(struct BatchArray) + count * sizeof(struct DisplayListLinks));
    batches->count = count;
    batches->batchDLs = dls;
    return batches;
}

struct BatchArray* batch_list_objects_alloc_opaque()
{
    static const struct BatchDisplayLists Batches[] = {
        [ LAYER_OPAQUE_CORKBOX ] = { breakable_box_seg8_dl_cork_box_init, breakable_box_seg8_dl_cork_box_end },
    };
    STATIC_ASSERT(LAYER_OPAQUE_BATCHES_COUNT == sizeof(Batches) / sizeof(*Batches), "Mismatch");

    return batch_array_alloc(LAYER_OPAQUE_BATCHES_COUNT, Batches);
}

struct BatchArray* batch_list_objects_alloc_alpha()
{
    static const struct BatchDisplayLists Batches[] = {
        [ LAYER_ALPHA_COINS_FIRST + 0 ] = { dl_coin_0, dl_coin_end },
        [ LAYER_ALPHA_COINS_FIRST + 1 ] = { dl_coin_22_5, dl_coin_end },
        [ LAYER_ALPHA_COINS_FIRST + 2 ] = { dl_coin_45, dl_coin_end },
        [ LAYER_ALPHA_COINS_FIRST + 3 ] = { dl_coin_67_5, dl_coin_end },
        [ LAYER_ALPHA_COINS_FIRST + 4 ] = { dl_coin_90, dl_coin_end },
        [ LAYER_ALPHA_SMOKE ] = { burn_smoke_seg4_sub_dl_begin_alpha, burn_smoke_seg4_sub_dl_end },
    };
    STATIC_ASSERT(LAYER_ALPHA_BATCHES_COUNT == sizeof(Batches) / sizeof(*Batches), "Mismatch");

    return batch_array_alloc(LAYER_ALPHA_BATCHES_COUNT, Batches);
}

struct BatchArray* batch_list_objects_alloc_xlu()
{
    static const struct BatchDisplayLists Batches[] = {
        [ LAYER_TRANSPARENT_SMOKE ] = { burn_smoke_seg4_sub_dl_begin_translucent, burn_smoke_seg4_sub_dl_end },
        [ LAYER_TRANSPARENT_MIST ] = { mist_dl, mist_dl_end },
        [ LAYER_TRANSPARENT_RED_FLAMES_FIRST + 0 ] = { flame_seg3_dl_0301B3B0, flame_seg3_dl_end },
        [ LAYER_TRANSPARENT_RED_FLAMES_FIRST + 1 ] = { flame_seg3_dl_0301B3C8, flame_seg3_dl_end },
        [ LAYER_TRANSPARENT_RED_FLAMES_FIRST + 2 ] = { flame_seg3_dl_0301B3E0, flame_seg3_dl_end },
        [ LAYER_TRANSPARENT_RED_FLAMES_FIRST + 3 ] = { flame_seg3_dl_0301B3F8, flame_seg3_dl_end },
        [ LAYER_TRANSPARENT_RED_FLAMES_FIRST + 4 ] = { flame_seg3_dl_0301B410, flame_seg3_dl_end },
        [ LAYER_TRANSPARENT_RED_FLAMES_FIRST + 5 ] = { flame_seg3_dl_0301B428, flame_seg3_dl_end },
        [ LAYER_TRANSPARENT_RED_FLAMES_FIRST + 6 ] = { flame_seg3_dl_0301B440, flame_seg3_dl_end },
        [ LAYER_TRANSPARENT_RED_FLAMES_FIRST + 7 ] = { flame_seg3_dl_0301B458, flame_seg3_dl_end },
        [ LAYER_TRANSPARENT_BLUE_FLAMES_FIRST + 0 ] = { flame_seg3_dl_0301B500, flame_seg3_dl_end },
        [ LAYER_TRANSPARENT_BLUE_FLAMES_FIRST + 1 ] = { flame_seg3_dl_0301B518, flame_seg3_dl_end },
        [ LAYER_TRANSPARENT_BLUE_FLAMES_FIRST + 2 ] = { flame_seg3_dl_0301B530, flame_seg3_dl_end },
        [ LAYER_TRANSPARENT_BLUE_FLAMES_FIRST + 3 ] = { flame_seg3_dl_0301B548, flame_seg3_dl_end },
        [ LAYER_TRANSPARENT_BLUE_FLAMES_FIRST + 4 ] = { flame_seg3_dl_0301B560, flame_seg3_dl_end },
        [ LAYER_TRANSPARENT_BLUE_FLAMES_FIRST + 5 ] = { flame_seg3_dl_0301B578, flame_seg3_dl_end },
        [ LAYER_TRANSPARENT_BLUE_FLAMES_FIRST + 6 ] = { flame_seg3_dl_0301B590, flame_seg3_dl_end },
        [ LAYER_TRANSPARENT_BLUE_FLAMES_FIRST + 7 ] = { flame_seg3_dl_0301B5A8, flame_seg3_dl_end },
    };
    STATIC_ASSERT(LAYER_TRANSPARENT_BATCHES_COUNT == sizeof(Batches) / sizeof(*Batches), "Mismatch");

    return batch_array_alloc(LAYER_TRANSPARENT_BATCHES_COUNT, Batches);
}

struct BatchArray* batch_list_objects_alloc_xlu_decal()
{
    static const struct BatchDisplayLists Batches[] = {
        [ LAYER_TRANSPARENT_DECAL_SHADOW_CIRCLE ] = { dl_shadow_circle, dl_shadow_circle_end },
    };
    STATIC_ASSERT(LAYER_TRANSPARENT_DECAL_BATCHES_COUNT == sizeof(Batches) / sizeof(*Batches), "Mismatch");
    return batch_array_alloc(LAYER_TRANSPARENT_DECAL_BATCHES_COUNT, Batches);
}

struct BatchArray* batch_list_objects_alloc_cld()
{
    static const struct BatchDisplayLists Batches[] = {
        [ LAYER_CLD_SHADOW_CIRCLE ] = { dl_shadow_circle, dl_shadow_circle_end },
    };
    STATIC_ASSERT(LAYER_CLD_BATCHES_COUNT == sizeof(Batches) / sizeof(*Batches), "Mismatch");
    return batch_array_alloc(LAYER_CLD_BATCHES_COUNT, Batches);
}
