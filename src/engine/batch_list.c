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

extern const Gfx flame_v2_dl_red01[];
extern const Gfx flame_v2_dl_red02[];
extern const Gfx flame_v2_dl_red03[];
extern const Gfx flame_v2_dl_red04[];
extern const Gfx flame_v2_dl_red05[];
extern const Gfx flame_v2_dl_red06[];
extern const Gfx flame_v2_dl_red07[];
extern const Gfx flame_v2_dl_red08[];
extern const Gfx flame_v2_dl_red09[];
extern const Gfx flame_v2_dl_red10[];
extern const Gfx flame_v2_dl_red11[];
extern const Gfx flame_v2_dl_red12[];
extern const Gfx flame_v2_dl_red13[];
extern const Gfx flame_v2_dl_red14[];
extern const Gfx flame_v2_dl_red15[];
extern const Gfx flame_v2_dl_red16[];

extern const Gfx flame_v2_dl_blue01[];
extern const Gfx flame_v2_dl_blue02[];
extern const Gfx flame_v2_dl_blue03[];
extern const Gfx flame_v2_dl_blue04[];
extern const Gfx flame_v2_dl_blue05[];
extern const Gfx flame_v2_dl_blue06[];
extern const Gfx flame_v2_dl_blue07[];
extern const Gfx flame_v2_dl_blue08[];
extern const Gfx flame_v2_dl_blue09[];
extern const Gfx flame_v2_dl_blue10[];
extern const Gfx flame_v2_dl_blue11[];
extern const Gfx flame_v2_dl_blue12[];
extern const Gfx flame_v2_dl_blue13[];
extern const Gfx flame_v2_dl_blue14[];
extern const Gfx flame_v2_dl_blue15[];
extern const Gfx flame_v2_dl_blue16[];

extern const Gfx flame_v2_dl_green01[];
extern const Gfx flame_v2_dl_green02[];
extern const Gfx flame_v2_dl_green03[];
extern const Gfx flame_v2_dl_green04[];
extern const Gfx flame_v2_dl_green05[];
extern const Gfx flame_v2_dl_green06[];
extern const Gfx flame_v2_dl_green07[];
extern const Gfx flame_v2_dl_green08[];
extern const Gfx flame_v2_dl_green09[];
extern const Gfx flame_v2_dl_green10[];
extern const Gfx flame_v2_dl_green11[];
extern const Gfx flame_v2_dl_green12[];
extern const Gfx flame_v2_dl_green13[];
extern const Gfx flame_v2_dl_green14[];
extern const Gfx flame_v2_dl_green15[];
extern const Gfx flame_v2_dl_green16[];

extern const Gfx flame_v2_dl_revert[];

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

        [ LAYER_TRANSPARENT_RED_FLAMES_FIRST + 0  ] = { flame_v2_dl_red01, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_RED_FLAMES_FIRST + 1  ] = { flame_v2_dl_red02, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_RED_FLAMES_FIRST + 2  ] = { flame_v2_dl_red03, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_RED_FLAMES_FIRST + 3  ] = { flame_v2_dl_red04, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_RED_FLAMES_FIRST + 4  ] = { flame_v2_dl_red05, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_RED_FLAMES_FIRST + 5  ] = { flame_v2_dl_red06, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_RED_FLAMES_FIRST + 6  ] = { flame_v2_dl_red07, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_RED_FLAMES_FIRST + 7  ] = { flame_v2_dl_red08, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_RED_FLAMES_FIRST + 8  ] = { flame_v2_dl_red09, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_RED_FLAMES_FIRST + 9  ] = { flame_v2_dl_red10, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_RED_FLAMES_FIRST + 10 ] = { flame_v2_dl_red11, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_RED_FLAMES_FIRST + 11 ] = { flame_v2_dl_red12, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_RED_FLAMES_FIRST + 12 ] = { flame_v2_dl_red13, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_RED_FLAMES_FIRST + 13 ] = { flame_v2_dl_red14, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_RED_FLAMES_FIRST + 14 ] = { flame_v2_dl_red15, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_RED_FLAMES_FIRST + 15 ] = { flame_v2_dl_red16, flame_v2_dl_revert },

        [ LAYER_TRANSPARENT_BLUE_FLAMES_FIRST + 0  ] = { flame_v2_dl_blue01, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_BLUE_FLAMES_FIRST + 1  ] = { flame_v2_dl_blue02, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_BLUE_FLAMES_FIRST + 2  ] = { flame_v2_dl_blue03, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_BLUE_FLAMES_FIRST + 3  ] = { flame_v2_dl_blue04, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_BLUE_FLAMES_FIRST + 4  ] = { flame_v2_dl_blue05, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_BLUE_FLAMES_FIRST + 5  ] = { flame_v2_dl_blue06, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_BLUE_FLAMES_FIRST + 6  ] = { flame_v2_dl_blue07, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_BLUE_FLAMES_FIRST + 7  ] = { flame_v2_dl_blue08, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_BLUE_FLAMES_FIRST + 8  ] = { flame_v2_dl_blue09, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_BLUE_FLAMES_FIRST + 9  ] = { flame_v2_dl_blue10, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_BLUE_FLAMES_FIRST + 10 ] = { flame_v2_dl_blue11, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_BLUE_FLAMES_FIRST + 11 ] = { flame_v2_dl_blue12, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_BLUE_FLAMES_FIRST + 12 ] = { flame_v2_dl_blue13, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_BLUE_FLAMES_FIRST + 13 ] = { flame_v2_dl_blue14, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_BLUE_FLAMES_FIRST + 14 ] = { flame_v2_dl_blue15, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_BLUE_FLAMES_FIRST + 15 ] = { flame_v2_dl_blue16, flame_v2_dl_revert },

        [ LAYER_TRANSPARENT_GREEN_FLAMES_FIRST + 0  ] = { flame_v2_dl_green01, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_GREEN_FLAMES_FIRST + 1  ] = { flame_v2_dl_green02, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_GREEN_FLAMES_FIRST + 2  ] = { flame_v2_dl_green03, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_GREEN_FLAMES_FIRST + 3  ] = { flame_v2_dl_green04, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_GREEN_FLAMES_FIRST + 4  ] = { flame_v2_dl_green05, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_GREEN_FLAMES_FIRST + 5  ] = { flame_v2_dl_green06, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_GREEN_FLAMES_FIRST + 6  ] = { flame_v2_dl_green07, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_GREEN_FLAMES_FIRST + 7  ] = { flame_v2_dl_green08, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_GREEN_FLAMES_FIRST + 8  ] = { flame_v2_dl_green09, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_GREEN_FLAMES_FIRST + 9  ] = { flame_v2_dl_green10, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_GREEN_FLAMES_FIRST + 10 ] = { flame_v2_dl_green11, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_GREEN_FLAMES_FIRST + 11 ] = { flame_v2_dl_green12, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_GREEN_FLAMES_FIRST + 12 ] = { flame_v2_dl_green13, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_GREEN_FLAMES_FIRST + 13 ] = { flame_v2_dl_green14, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_GREEN_FLAMES_FIRST + 14 ] = { flame_v2_dl_green15, flame_v2_dl_revert },
        [ LAYER_TRANSPARENT_GREEN_FLAMES_FIRST + 15 ] = { flame_v2_dl_green16, flame_v2_dl_revert },
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
